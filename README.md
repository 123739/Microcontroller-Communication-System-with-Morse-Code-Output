# Microcontroller Communication System with Morse Code Output

## Overview

This project demonstrates a working communication system between an Arduino and an ESP32 using a custom bit-level transmission protocol. The Arduino acts as the transmitter, sending encoded characters through a GPIO pin, while the ESP32 receives and reconstructs the data using synchronized sampling. The received characters are then converted into Morse code and represented using visual (LED) and auditory (buzzer) outputs.

This project explores the fundamentals of embedded systems communication, timing synchronization, and real-time signal processing without relying on built-in serial communication libraries.

---

## System Architecture

The system consists of two microcontrollers:

### 1. Arduino (Transmitter)

* Reads character input from Serial Monitor
* Converts each character into an 8-bit binary sequence
* Sends data bit-by-bit through a digital GPIO pin
* Includes a start pulse for synchronization

### 2. ESP32 (Receiver + Decoder)

* Detects start pulse for synchronization
* Reads incoming bits using timed sampling
* Reconstructs the original character from binary data
* Converts character into Morse code
* Outputs Morse code using LED and buzzer

---

## Features

* Custom bit-level communication protocol
* Start-pulse based synchronization mechanism
* Real-time character decoding on ESP32
* Morse code conversion system (A–Z supported)
* Visual output using LED (dot and dash representation)
* Audio output using buzzer (short and long beeps)

---

## Hardware Requirements

* Arduino Uno (or compatible board)
* ESP32 development board
* LED (common cathode RGB recommended)
* Buzzer
* Connecting jumper wires
* USB cables for both boards

---

## Pin Configuration

### Arduino (Transmitter)

* Digital Pin 2 → ESP32 GPIO 4
* GND → ESP32 GND

### ESP32 (Receiver)

* GPIO 4 → Data input from Arduino
* GPIO 2 → Blue LED (dot indicator)
* GPIO 5 → Green LED (dash indicator)
* GPIO 23 → Buzzer
* GND → Common ground

---

## Working Principle

1. User inputs a character via Arduino Serial Monitor
2. Arduino converts the character into binary form
3. A start pulse is sent to indicate transmission beginning
4. ESP32 detects the start pulse and begins sampling bits
5. Bits are reconstructed into the original character
6. Character is mapped to Morse code sequence
7. Morse code is displayed using LED and buzzer signals

---

## Morse Code Representation

* Dot (.) → Blue LED blink + short beep
* Dash (-) → Green LED blink + long beep

---

## Example Flow

Input:

```
A
```

Binary transmission:

```
01000001
```

Morse output:

```
.-
```

Physical output:

* Short blue blink + beep
* Long green blink + beep

---

## Key Concepts Used

* Bitwise data transmission
* GPIO-based communication protocol
* Signal synchronization techniques
* Character encoding and decoding
* Real-time embedded system processing

---

## Limitations

* Transmission speed is relatively slow due to manual timing control
* Sensitive to wire noise and unstable connections
* Limited to basic character set (A–Z)
* No error correction implemented

---

## Future Improvements

* Implement UART-like reliable protocol
* Add full sentence transmission support
* Introduce checksum-based error detection
* Optimize timing for faster communication
* Expand Morse support to numbers and symbols
* Replace manual timing with interrupt-based reception

---

## Conclusion

This project demonstrates how fundamental communication systems can be built from scratch using basic microcontrollers. It provides insight into how data is transmitted, synchronized, and interpreted at the hardware level, bridging the gap between digital logic and physical output systems.

## Author
Anwesha Rath
