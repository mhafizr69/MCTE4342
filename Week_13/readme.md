
# Interfacing Circuits  

## Down-shifting logic levels

### Voltage divider

- Simple and effective  
- The resistance of the bottom resistor is twice of the top one.

<details>
![Voltage Divider](./VoltageDivider.png)
</details>
  
### Transistor-based techniques

- High-side switching  
- Choose base resistor size to ensure saturation mode (may not be 1K)  

![Transistor](./TransistorBased.png)


### Zener diode

- The voltage drop of the Zenerdiode is 3.3V.  

![Zener Diode](./ZenerDiode.png)

## Up-shifting logic levels

### Double-transistor techniques

- Two transistors (low-side switching)  
- Each transistor acts as an inverter  
- Choose base resistor size to ensure saturation mode (may not be 1K)  

![Double Transistor](./DoubleTransistor.png)

### Single transistor techniques

![Single Transistor](./SingleTransistor.png)
