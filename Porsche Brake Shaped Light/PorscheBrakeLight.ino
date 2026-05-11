#include <Wire.h>
#include <WiFi.h>
#include <WebServer.h>
#include <Adafruit_VCNL4040.h>

const char* ssid = "Wifi";
const char* password = "Password";

WebServer server(80);

const int mosfetPin = 27;

Adafruit_VCNL4040 vcnl4040 = Adafruit_VCNL4040();

bool mosfetState = false;
bool sensorFound = false;

const uint16_t proximityThreshold = 1500;
bool handWasDetected = false;

const unsigned long toggleCooldown = 700;
unsigned long lastToggleTime = 0;

void setMosfet(bool state) {
  mosfetState = state;

  if (mosfetState == true) {
    digitalWrite(mosfetPin, HIGH);
  } else {
    digitalWrite(mosfetPin, LOW);
  }
}

void toggleMosfet() {
  setMosfet(!mosfetState);

  if (mosfetState == true) {
    Serial.println("MOSFET toggled ON by hand wave");
  } else {
    Serial.println("MOSFET toggled OFF by hand wave");
  }
}

void checkHandWave() {
  if (sensorFound == false) {
    return;
  }

  uint16_t proximity = vcnl4040.getProximity();

  Serial.print("Proximity: ");
  Serial.println(proximity);

  unsigned long currentTime = millis();

  if (proximity > proximityThreshold && handWasDetected == false) {
    if (currentTime - lastToggleTime > toggleCooldown) {
      toggleMosfet();
      lastToggleTime = currentTime;
    }

    handWasDetected = true;
  }

  if (proximity < proximityThreshold * 0.6) {
    handWasDetected = false;
  }
}

void handleRoot() {
  String html = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>ESP32 MOSFET Control</title>

  <style>
    body {
      font-family: Arial, sans-serif;
      text-align: center;
      background-color: #f2f2f2;
      margin-top: 60px;
    }

    .card {
      background-color: white;
      width: 360px;
      margin: auto;
      padding: 30px;
      border-radius: 15px;
      box-shadow: 0 0 15px rgba(0,0,0,0.15);
    }

    h1 {
      font-size: 26px;
    }

    button {
      font-size: 22px;
      padding: 15px 35px;
      margin: 12px;
      border-radius: 10px;
      border: none;
      cursor: pointer;
    }

    .on {
      background-color: #4CAF50;
      color: white;
    }

    .off {
      background-color: #f44336;
      color: white;
    }

    #status {
      font-size: 22px;
      font-weight: bold;
      margin-top: 25px;
    }

    #prox {
      font-size: 18px;
      margin-top: 15px;
      color: #444;
    }

    #sensor {
      font-size: 18px;
      margin-top: 10px;
      color: #444;
    }
  </style>
</head>

<body>
  <div class="card">
    <h1>ESP32 MOSFET Control</h1>

    <button class="on" onclick="turnOn()">Turn ON</button>
    <button class="off" onclick="turnOff()">Turn OFF</button>

    <p id="status">Status: Loading...</p>
    <p id="sensor">Sensor: Loading...</p>
    <p id="prox">Proximity: Loading...</p>
  </div>

  <script>
    function turnOn() {
      fetch("/on")
        .then(response => response.text())
        .then(data => {
          updateStatus();
        });
    }

    function turnOff() {
      fetch("/off")
        .then(response => response.text())
        .then(data => {
          updateStatus();
        });
    }

    function updateStatus() {
      fetch("/status")
        .then(response => response.text())
        .then(data => {
          document.getElementById("status").innerHTML = "Status: " + data;
        });
    }

    function updateSensor() {
      fetch("/sensor")
        .then(response => response.text())
        .then(data => {
          document.getElementById("sensor").innerHTML = "Sensor: " + data;
        });
    }

    function updateProximity() {
      fetch("/proximity")
        .then(response => response.text())
        .then(data => {
          document.getElementById("prox").innerHTML = "Proximity: " + data;
        });
    }

    function updatePage() {
      updateStatus();
      updateSensor();
      updateProximity();
    }

    setInterval(updatePage, 500);
    updatePage();
  </script>
</body>
</html>
)rawliteral";

  server.send(200, "text/html", html);
}

void handleOn() {
  setMosfet(true);
  server.send(200, "text/plain", "ON");
}

void handleOff() {
  setMosfet(false);
  server.send(200, "text/plain", "OFF");
}

void handleStatus() {
  if (mosfetState == true) {
    server.send(200, "text/plain", "ON");
  } else {
    server.send(200, "text/plain", "OFF");
  }
}

void handleSensor() {
  if (sensorFound == true) {
    server.send(200, "text/plain", "VCNL4040 found");
  } else {
    server.send(200, "text/plain", "VCNL4040 not found");
  }
}

void handleProximity() {
  if (sensorFound == false) {
    server.send(200, "text/plain", "Sensor not found");
    return;
  }

  uint16_t proximity = vcnl4040.getProximity();
  server.send(200, "text/plain", String(proximity));
}

void setup() {
  Serial.begin(115200);

  pinMode(mosfetPin, OUTPUT);
  setMosfet(false);

  Wire.begin(21, 22);

  Serial.println();
  Serial.println("Starting VCNL4040...");

  if (!vcnl4040.begin()) {
    Serial.println("Could not find VCNL4040 sensor. Website will still start.");
    sensorFound = false;
  } else {
    Serial.println("VCNL4040 found.");
    sensorFound = true;

    vcnl4040.setProximityLEDCurrent(VCNL4040_LED_CURRENT_200MA);
    vcnl4040.setProximityLEDDutyCycle(VCNL4040_LED_DUTY_1_40);
    vcnl4040.setProximityIntegrationTime(VCNL4040_PROXIMITY_INTEGRATION_TIME_8T);
  }

  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Connected to WiFi!");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);
  server.on("/status", handleStatus);
  server.on("/sensor", handleSensor);
  server.on("/proximity", handleProximity);

  server.begin();

  Serial.println("Web server started.");
}

void loop() {
  server.handleClient();
  checkHandWave();
  delay(50);
}