/**************************************************************************
 This is an example for our Monochrome OLEDs based on SSD1306 drivers

 Pick one up today in the adafruit shop!
 ------> http://www.adafruit.com/category/63_98

 This example is for a 128x32 pixel display using I2C to communicate
 3 pins are required to interface (two I2C and one reset).

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source
 hardware by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries,
 with contributions from the open source community.
 BSD license, check license.txt for more information
 All text above, and the splash screen below must be
 included in any redistribution.
 **************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <icons.cpp>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library.
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET -1       // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void testdrawtriangle(void)
{
  display.clearDisplay();

  for (int16_t i = 0; i < max(display.width(), display.height()); i += 10)
  {
    display.drawTriangle(
        display.width() / 2, display.height() / 2 - i,
        display.width() / 2 - i, display.height() / 2 + i,
        display.width() / 2 + i, display.height() / 2 + i, SSD1306_WHITE);
    display.display();
    delay(20);
  }
}

void testfilltriangle(void)
{
  display.clearDisplay();

  for (int16_t i = max(display.width(), display.height()); i > 0; i -= 10)
  {
    // The INVERSE color is used so triangles alternate white/black
    display.fillTriangle(
        display.width() / 2, display.height() / 2 - i,
        display.width() / 2 - i, display.height() / 2 + i,
        display.width() / 2 + i, display.height() / 2 + i, SSD1306_INVERSE);
    display.display();
    delay(20);
  }
  delay(500);
}

void slowClear(void)
{
  for (int16_t i = 0; i < max(display.width(), display.height()) + 10; i += 10)
  {
    // The INVERSE color is used so triangles alternate white/black
    display.fillTriangle(
        display.width() / 2, display.height() / 2 - i,
        display.width() / 2 - i, display.height() / 2 + i,
        display.width() / 2 + i, display.height() / 2 + i, SSD1306_BLACK);
    display.display();
    delay(50);
  }
  delay(300);
}

void testdrawchar(char message[])
{

  display.setTextSize(3);              // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 5);             // Start at top-left corner
  display.cp437(true);                 // Use full 256 char 'Code Page 437' font

  // Not all the characters will fit on the display. This is normal.
  // Library will draw what it can and the rest will be clipped.
  for (uint8_t i = 0; i < strlen(message); i++)
  {
    display.write(message[i]);
    display.display();
    delay(100);
  }

  delay(2000);

  display.setTextColor(SSD1306_BLACK);
  display.setCursor(0, 5);
  for (uint8_t i = 0; i < strlen(message); i++)
  {
    display.write(message[i]);
    display.display();
    delay(100);
  }
}

void drawClimateMode(void)
{
  uint8_t test = millis() / 2000;
  switch (test)
  {
  case 1:
    display.drawBitmap(0, 0, climateFeet, LOGO_WIDTH, LOGO_HEIGHT, 1);
    break;
  case 2:
    display.drawBitmap(0, 0, climateFace, LOGO_WIDTH, LOGO_HEIGHT, 1);
    break;
  case 3:
    display.drawBitmap(0, 0, climateFeetFace, LOGO_WIDTH, LOGO_HEIGHT, 1);
    break;
  case 4:
    display.drawBitmap(0, 0, climateFeetDefrost, LOGO_WIDTH, LOGO_HEIGHT, 1);
    break;
  case 5:
    display.drawBitmap(0, 0, climateDefrost, LOGO_WIDTH, LOGO_HEIGHT, 1);
    break;
  default:
    break;
  }
}

void renderTemp(bool animate, uint8_t start, uint8_t size, float percent)
{
  display.drawLine(start, 0, start + size, 0, SSD1306_WHITE);
  if (animate)
  {
    display.display();
    delay(200);
  }
  display.drawLine(start + size, 0, start + size, 31, SSD1306_WHITE);
  if (animate)
  {
    display.display();
    delay(200);
  }
  display.drawLine(start + size, 31, start, 31, SSD1306_WHITE);
  if (animate)
  {
    display.display();
    delay(200);
  }
  display.drawLine(start, 32, start, 0, SSD1306_WHITE);
  if (animate)
  {
    display.display();
    delay(200);
  }
  display.drawLine(start + (size / 2), 0, start + (size / 2), 2, SSD1306_WHITE);
  if (animate)
  {
    display.display();
    delay(200);
  }
  display.drawLine(start + (size / 2), 31, start + (size / 2), 29, SSD1306_WHITE);
  if (animate)
  {
    display.display();
    delay(200);
  }

  percent *= 0.84;
  uint8_t target = (uint8_t)(size * percent + 0.5);
  if (animate)
  {
    uint8_t current = 0;
    for (uint8_t i = 0; i < 64; i++)
    {
      uint8_t speed = (target - current) / 4;
      if (speed == 0)
      {
        speed = 1;
      }
      current = current + speed;
      display.fillRect(start + 5, 8, current, 16, SSD1306_WHITE);
      display.display();
    }
  }

  display.fillRect(start + 5, 8, target, 16, SSD1306_WHITE);
}

void acIndicator()
{
  display.setTextSize(3);
  display.setCursor(92, 5);
  display.setTextColor(SSD1306_WHITE);
  display.print(F("AC"));
}

const bool left = false;
void setup()
{
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    for (;;)
      ; // Don't proceed, loop forever
  }

  display.clearDisplay();

  testdrawtriangle(); // Draw triangles (outlines)

  testfilltriangle(); // Draw triangles (filled)

  slowClear();

  if (left)
  {
    testdrawchar("WELCOME"); // Draw characters of the default font
    renderTemp(true, 0, 88, 1);
    acIndicator();
    display.display();
  }
  else
  {
    testdrawchar("ETHAN"); // Draw characters of the default font
    renderTemp(true, 39, 88, 1);
    drawClimateMode();
    display.display();
  }
}

uint8_t postion = 0;
void leftRenderLoop()
{
  postion++;
  renderTemp(false, 0, 88, postion / 255.0);
  if (postion < 128)
  {
    acIndicator();
  }
}

void rightRenderLoop()
{
  renderTemp(false, 39, 88, 1);
  drawClimateMode();
  display.display();
}

void loop()
{

  display.clearDisplay();
  if (left)
  {
    leftRenderLoop();
  }
  else
  {
    rightRenderLoop();
  }
  display.display();
}
