# Swiper_module
An Arduino microcontroller interfacing with a Raspberry Pi to read a 'swiping' hand gesture.

***Hardware/software configuration***  
The Arduino is connected to two face down motion sensors placed 20 cm apart with a metal plate between them. The Raspberry Pi runs a background python script watching for the Arduino's signal through USB with an image viewer in the foreground.

***Workflow***  
An object is swiped from right to left beneath the two motion sensors  
The Arduino sends a "success" message to the Raspberry Pi through the serial port (USB)  
The signal is read by the python script watching '/dev/ttyUSB0' (the USB port connected to the Arduino)  
The Raspberry Pi emulates a "right key" keypress  
The image viewer moves to the next image in the current directory  
