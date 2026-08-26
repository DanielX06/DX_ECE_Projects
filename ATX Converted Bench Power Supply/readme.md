# ATX bench power supply

A Corsair RM650x that used to run a gaming PC and now runs whatever is on my desk. Same silent Corsair fan, same rock-solid rails, except the 24-pin has been replaced with a row of banana jacks and the whole thing lives in a 3D printed enclosure made in SolidWorks.

Four outputs come out the front. Three of them are the ATX rails themselves, 3.3 V, 5 V and 12 V, tapped straight off the harness so they carry the supply's original regulation and protection. The fourth is the one I actually use most, an AliExpress buck-boost module fed from the 12 V rail and dialed anywhere between 0 and 36 V with a knob on the panel. Its display sits flush next to the knob, so setting a rail takes one hand and no guessing at a multimeter.
[Link to buck-boost converter](https://www.aliexpress.com/item/1005010632869190.html?spm=a2g0o.order_list.order_list_main.11.5d6b1802nnHKKg)

Turning it on is the fun part. ATX supplies do not have a power switch in any useful sense. They wait for PS_ON to be pulled to ground, so the toggle on the front panel does exactly that and nothing else. Next to it, an LED wired to PS_OK lights once the supply has come up and decided its rails are in spec. Flip the switch, wait for the LED, and you know the thing is actually regulating rather than just humming.

The enclosure wraps the original PSU shell and leaves the stock intake and exhaust clear, because Corsair already solved the airflow problem and I saw no reason to unsolve it. The front face is a separate model from the rest of the box, so when I inevitably want another output or a different jack layout I can re-print one panel instead of rebuilding a supply.
