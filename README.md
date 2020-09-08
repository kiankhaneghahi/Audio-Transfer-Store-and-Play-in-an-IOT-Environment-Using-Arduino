# Audio Transfer, Store and Play in an IOT Environment Using Arduino
We use an Arduino Due board and Arduino ESP8266 board to implement a system that:
1)   Uses UART protocol to receive 10 seconds of an 8-KHz, 8-bit depth sampled audio data. 
(Telephone line quality)
2)   Makes a web server and waits for clients over Wi-Fi, then displays a simple HTML page.
3)   Plays audio over DAC for  headphones. (You may need a simple amplifier IC.)
4)   Stored music won't be wiped after system reset. (Use Flash memory or other storages to store 
data)

The ESP8266 board is programmed as the generator for our IOT server and the interface is written in HTML. This board communicates with the arduino due board over a dual serial connection using encoded strings. Also, the first thing that the ESP board should do is that it should connect to a local wifi network with given username and password and then it should set up a local server for the GUI and wait for local clients to interact with the interface and then act based on the command.

For more information read the Project PDF and the codes.
