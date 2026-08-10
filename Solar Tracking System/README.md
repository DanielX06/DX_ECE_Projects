08/2026 - Present 

A dual-axis solar tracker with a custom ESP32-controlled buck converter charging stage and instrumented efficiency measurement. The system logs panel-side and battery-side power alongside environmental conditions so that tracking gain and conversion efficiency can be quantified from real field data rather than estimated.


Most hobby solar trackers demonstrate that a panel can follow the sun. Far fewer measure whether the tracking actually pays for itself, or how much energy the charging stage wastes on the way to the battery. This project instruments both ends of the power path so the answer is measured, not assumed.

The build targets Edmonton, Alberta (53.55°N), which makes the question non-trivial. High latitude means low winter sun angles, long summer days with wide azimuth sweep, and freezing temperatures that constrain lithium-ion charging.

## Hardware
