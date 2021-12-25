
# Interrupts

## Limitation of Polling

- Performance can suffer in complicated embedded systems which require input from many sources.
- If the main loop has many things to perform, short blips of input can be missed.
- Multi-tasking is difficult.

## Advantage of Interrupt

- Main loop is free of polling.
- The CPU can sleep (to conserve power).

## Drawbacks of Interrupt

- Added complexity to make the CPU stop its work, save the context, jump to the ISR and then restore the context and resume its previous work.
- CPU can be interrupted **any** time. Software needs to be written with this behavior in mind.

## Pin_Change_Interrupt

This project uses the interrupt feature for PORT B of the Arduino.
The LED will change its state whenever there is a change of logic from PORTB 4.
Since a push button is used, a delay is needed to avoid the CPU reading multiple toggling of logic level.

<img scr = "CircuitDiagram.png" height = "400" width = "400">

Youtube Link: 
