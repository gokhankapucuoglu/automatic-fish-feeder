# Automatic Fish Feeder 🐟

This project is an automated fish feeding system designed to provide food for your aquarium inhabitants at specific intervals. It uses a 28BYJ-48 stepper motor for precise portion control.

## 🚀 Features
- **Precise Control:** Uses a stepper motor for accurate rotation.
- **Adjustable Intervals:** Easy to modify feeding frequency via code.
- **Low Power:** Optimized for long-term operation.

## 🛠 Hardware Components
- **Microcontroller:** Arduino (Uno/Nano or compatible)
- **Motor:** 28BYJ-48 Stepper Motor
- **Driver:** ULN2003 Stepper Motor Driver
- **Power:** 5V/9V DC Power Supply
- **Mechanical:** 3D Printed dispenser and enclosure

## 🔌 Wiring Diagram
| Component (ULN2003) | Arduino Pin |
|---------------------|-------------|
| IN1                 | 7           |
| IN2                 | 6           |
| IN3                 | 5           |
| IN4                 | 4           |
| VCC                 | 5V          |
| GND                 | GND         |

## 📝 Developer Note
The variable names and code structure are in **English** to follow global programming standards, while the comments are in **Turkish** to provide detailed explanations for local users. Feel free to translate the comments if needed!

## 🔗 Resources & Credits
- **3D Files:** The 3D printed parts for this project were sourced from [Thingiverse (by leventerzin)](https://www.thingiverse.com/thing:3093429).
- **Video Tutorial:** Detailed assembly guide by [Orhan Celep - Robotik Projeler](https://www.youtube.com/watch?v=It2zWWw2ThI).

## 📜 License
This project is licensed under the **MIT License**.
