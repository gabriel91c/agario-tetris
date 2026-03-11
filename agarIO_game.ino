#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 oled(128, 64, &SPI, 4, 6, 12);

int playerX = 63, playerY = 31;
int playerSize = 2;
int upBtn = A0, rightBtn = A1, leftBtn = A2, downBtn = A3, okBtn = 8, selectBtn = 7;
int foodX, foodY;
int enemyX = 10, enemyY = 10, enemySize = 10;
int dx, dy, distance;
int dx2, dy2, distance2;
unsigned long previousMillis = 0, enemySpeed = 30;

void setup() {
  oled.begin(SSD1306_SWITCHCAPVCC);
  oled.clearDisplay();
  delay(100);
  oled.display();
  pinMode(upBtn, INPUT);
  pinMode(rightBtn, INPUT);
  pinMode(leftBtn, INPUT);
  pinMode(downBtn, INPUT);
  pinMode(okBtn, INPUT);
  pinMode(selectBtn, INPUT);
  randomSeed(analogRead(A4));
  foodX = random(5, 125);
  foodY = random(5, 60);
}

void loop() {
  oled.clearDisplay();
  oled.fillCircle(playerX, playerY, playerSize, WHITE);
  oled.drawRect(0, 0, 128, 64, WHITE);
  oled.fillCircle(foodX, foodY, 1, WHITE);
  oled.fillCircle(enemyX, enemyY, enemySize, WHITE);
  oled.display();
  if(digitalRead(upBtn) == LOW) playerY--;
  if(digitalRead(downBtn) == LOW) playerY++;
  if(digitalRead(rightBtn) == LOW) playerX++;
  if(digitalRead(leftBtn) == LOW) playerX--;
  if(digitalRead(okBtn) == LOW) playerSize = 2;
  if(playerX < 0) playerX = 0;
  if(playerX > 128) playerX = 128;
  if(playerY < 0) playerY = 0;
  if(playerY > 64) playerY = 64;
  dx = playerX - foodX;
  dy = playerY - foodY;
  distance = sqrt(dx * dx + dy * dy);
  if(distance < playerSize) {
    foodX = random(5, 125);
    foodY = random(5, 60);
    playerSize++;
  }
  dx2 = playerX - enemyX;
  dy2 = playerY - enemyY;
  distance2 = sqrt(dx2 * dx2 + dy2 * dy2);
  oled.setTextSize(2);
  oled.setCursor(10, 20);
  oled.setTextColor(WHITE);
  if(playerSize > enemySize && distance2 < playerSize - enemySize) {
    playerX = 63, playerY = 31, playerSize = 2;
    enemyX = 10, enemyY = 10;
    oled.clearDisplay();
    oled.print("You win!");
    oled.display();
    delay(5000);
  }
  if(playerSize < enemySize && distance2 < enemySize - playerSize && playerSize > 2) {
    playerX = 63, playerY = 31, playerSize = 2;
    enemyX = 10, enemyY = 10;
    oled.clearDisplay();
    oled.print("Game Over");
    oled.display();
    delay(5000);
  }
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= enemySpeed) {
    previousMillis = currentMillis;
    if(enemyX < playerX) enemyX++;
    if(enemyX > playerX) enemyX--;
    if(enemyY < playerY) enemyY++;
    if(enemyY > playerY) enemyY--;
  } 
}
