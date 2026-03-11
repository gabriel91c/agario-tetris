🎮 Arduino OLED Mini Game – Grow & Escape

This project is a simple arcade-style game developed for Arduino Leonardo using an SSD1306 OLED display (128x64).

The player controls a small circle that collects food to grow bigger while avoiding or defeating an enemy depending on the size difference.

📦 Hardware Requirements

Arduino Leonardo

SSD1306 OLED Display (128x64 SPI)

5 Push Buttons

Jumper wires

Breadboard (optional)

🔌 Pin Connections
Component	Arduino Pin
OLED CS	4
OLED DC	6
OLED RESET	12
Move UP	A0
Move RIGHT	A1
Move LEFT	A2
Move DOWN	A3
OK Button	8
SELECT Button	7
📚 Required Libraries

Install the following libraries using Arduino Library Manager:

Adafruit GFX

Adafruit SSD1306

Steps:

Arduino IDE → Sketch → Include Library → Manage Libraries

Search and install the libraries.

🎮 Game Controls
Button	Action
A0	Move Up
A3	Move Down
A1	Move Right
A2	Move Left
Button 8	Reset player size
🧠 Game Logic

The game includes three main elements:

👤 Player

The player is represented by a circle that can move around the screen.

oled.fillCircle(playerX, playerY, playerSize, WHITE);

The player's size increases when food is collected.

🍎 Food

Food appears randomly on the screen.

foodX = random(5, 125);
foodY = random(5, 60);

When the player touches the food:

the food relocates to a random position

the player grows bigger

👾 Enemy

The enemy constantly moves toward the player.

if(enemyX < playerX) enemyX++;
if(enemyY < playerY) enemyY++;

Its movement speed is controlled using millis() timing.

🏆 Win Condition

If the player becomes larger than the enemy and touches it:

You win!

The game resets after a few seconds.

💀 Lose Condition

If the enemy is larger than the player and catches the player:

Game Over

The game resets after 5 seconds.

⚙️ Game Features

Player movement using 4 buttons

Random food generation

Growing mechanic

Enemy AI that chases the player

Win / Lose screens

Real-time OLED graphics

▶️ How to Run

Connect the hardware components according to the pin table.

Install the required libraries.

Open the project in Arduino IDE.

Select:

Board → Arduino Leonardo

Upload the code.

The game will start automatically.
