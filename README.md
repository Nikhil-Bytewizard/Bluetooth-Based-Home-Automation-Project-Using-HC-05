# 🔌 Bluetooth-Based Home Automation using HC-05 and LPC2129

## 📘 Overview

This project implements a **Bluetooth-based home automation system** using the **LPC2129 ARM7 microcontroller**, **HC-05 Bluetooth module**, **UART communication**, and a **16x2 LCD display**. The system allows users to wirelessly control home appliances from a smartphone via Bluetooth.

✅ Developed using:
- **Keil uVision** (for embedded C coding and HEX generation)
- **Proteus** (for circuit simulation)

---

## 🧰 Features

- 🟢 Turn ON/OFF appliances wirelessly using Bluetooth
- 📟 View real-time appliance status on LCD
- 🔄 UART-based communication with HC-05
- ⌛ Delay logic for LCD timing and initialization
- 🧪 Fully simulated in Proteus with LPC2129 custom library

---

## ⚙️ Components Used

| Component         | Details                              |
|------------------|--------------------------------------|
| LPC2129 MCU      | ARM7TDMI-S based 32-bit microcontroller |
| HC-05 Bluetooth  | UART-based Bluetooth module          |
| 16x2 LCD         | For status display                   |
| Virtual Terminal | Bluetooth input simulation in Proteus |
| Power Supply     | 5V DC for Proteus simulation         |

---

## 🔌 Proteus Connections

| LPC2129 Pin | Connected To        | Description               |
|-------------|---------------------|---------------------------|
| P0.0 (TXD0) | HC-05 RXD           | UART transmit             |
| P0.1 (RXD0) | HC-05 TXD           | UART receive              |
| P0.8–P0.15  | LCD Data (D0–D7)    | LCD 8-bit data lines      |
| P0.16       | LCD RS              | Register Select           |
| P0.17       | LCD EN              | Enable                    |
| GND         | VSS/VSSA/VSSA_PLL  | All ground pins           |
| 5V          | VDD/VREF/V3/V3A    | Connect 5V power properly |

---

## 🧾 UART Command Mapping

| Bluetooth Command | Action            |
|-------------------|-------------------|
| `'A'`             | Turn ON Light     |
| `'a'`             | Turn OFF Light    |
| `'B'`             | Turn ON Fan       |
| `'b'`             | Turn OFF Fan      |

---

## 📟 Code Snippets

### UART Initialization (LPC2129)

```c
void uart_init() {
    PINSEL0 |= 0x00000005;   // Enable UART0 P0.0 (TXD) and P0.1 (RXD)
    U0LCR = 0x83;            // 8-bit data, 1 stop bit, enable DLAB
    U0DLM = 0;
    U0DLL = 97;              // For 9600 baud at 15MHz
    U0LCR = 0x03;            // Disable DLAB
}
