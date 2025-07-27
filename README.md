# RF Based Data Encoder and Decoder

This project implements a secure wireless communication system using 433 MHz RF modules and the ATMEGA16A microcontroller. It encodes alphanumeric characters into sequences of "+" and "-" signals, encrypts them, and transmits the data over RF. The receiver decodes and decrypts the data, ensuring secure and private communication.

## Features

- RF-based wireless data transmission
- Encoding of alphanumeric data into symbolic format
- 8-bit password encryption for security
- Decoding and display of received data
- Developed using Embedded C, Proteus, and KiCad

## Technologies Used

- ATMEGA16A Microcontroller
- 433 MHz RF Transmitter and Receiver
- Embedded C (AVR-GCC)
- Proteus for simulation
- KiCad for circuit design

## Project Overview

### Encoding

Each character (0-9, A-Z) is encoded into a unique 6-symbol sequence using "+" for binary 1 and "-" for binary 0.

Example:
- A -> -+---+
- B -> -+++++
- 1 -> -++-+-

### Encryption

An 8-bit password is applied to the encoded data before transmission to ensure security. Only receivers with the correct key can decrypt and decode the message.

### Transmission and Reception

The transmitter sends encrypted data via a 433 MHz RF module. The receiver captures the RF signal, decrypts it, and decodes it back into the original character.

## How to Use

1. Compile the source code using AVR-GCC or Atmel Studio.
2. Upload the compiled code to the ATMEGA16A microcontroller using a USBasp programmer.
3. Connect the RF transmitter and receiver modules as per the schematic.
4. Power both the transmitter and receiver circuits.
5. Enter alphanumeric data at the transmitter side. The receiver will display the decoded data on the LCD.


## For Simulation testing

1. Download the proteus file
2. Open with protues
3. Start the simulation
4. Top button is "-" and bottom one is "+"
5. By reffering to the encoding file, you can enter the data
6. The microcontroller will decode and display on the LCD
   

## Hardware Requirements

- ATMEGA16A microcontroller
- 433 MHz RF transmitter and receiver
- LCD display
- Power supply (5V)
- Breadboard, jumper wires, and basic electronic components

## Software Requirements

- Atmel Studio or AVR-GCC
- Proteus for simulation
- KiCad for circuit design



## Future Improvements

- Extend transmission range
- Add error detection and correction
- Real-time communication support
- Integration with IoT systems
- Power efficiency optimization
- Security against jamming and interference

## Author

Ahasas Yadav  
B.Tech, Electronics and Communication Engineering  
Indian Institute of Information Technology, Una



