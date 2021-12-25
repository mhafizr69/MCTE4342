
# Power Management  

## Reducing power consumption  
- Hardware-based  
- Software-based  

### Hardware-based

#### Take the ATmega328p out of Arduino (Easiest of all)

<img src="StandAlone.png" width="100" height"100"> <img src="StandAloneCircuit.png" width="100" height"100">

Reason of Arduino having high power consumption:  
- Arduino uses a linear voltage regulator. Linear voltage regulators are known to be very inefficient (Around 70% efficiency)
- Arduino has onboard LEDs that consume power.
- Arduino has ATmega16u that handles USB-Serial conversion. It consumes power.  

### Use efficient voltage regulators (or run directly from batteries if possible)

### Lower the CPU clock speed and Lower the operating voltage
- Reducing the operating voltage without reducing clock speed appropriately could make the CPU behave erratically.
- Reduce both clock speed and operating voltage to lower current consumption.

<img src="ClockvVolt.png" width="100" height"100">

### Software-based

#### Turning off external devices while they are not being used

#### Setting unused GPIO pins as output



#### Turning off ADC




#### Turning off analog comparator




#### Sleeping




#### Turning off brown-out detector




#### Turning off timers
