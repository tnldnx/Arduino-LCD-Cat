
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte FRAME_COUNT = 8;

byte cat[8][2][8] = {
  {
    {B10000,B11000,B01111,B01111,B01111,B00111,B01010,B10001},
    {B00101,B00111,B11111,B11111,B11111,B11110,B01010,B10001}
  },
  {
    {B10000,B11000,B01111,B01111,B01111,B00111,B01010,B01001},
    {B00101,B00111,B11111,B11111,B11111,B11110,B01010,B01001}
  },
  {
    {B10000,B11111,B01111,B01111,B00111,B01010,B10001,B00000},
    {B00101,B11111,B11111,B11111,B11110,B01010,B10001,B00000}
  },
  {
    {B10000,B11000,B01111,B01111,B01111,B00111,B01010,B00110},
    {B00101,B00111,B11111,B11111,B11111,B11110,B01010,B00110}
  },
  {
    {B01000,B11000,B01111,B01111,B01111,B00111,B10001,B01010},
    {B00101,B00111,B11111,B11111,B11111,B11110,B10001,B01010}
  },
  {
    {B01000,B11000,B01111,B01111,B01111,B00111,B10010,B01010},
    {B00101,B00111,B11111,B11111,B11111,B11110,B10010,B01010}
  },
  {
    {B01000,B11111,B01111,B01111,B00111,B01010,B01001,B00000},
    {B00101,B11111,B11111,B11111,B11110,B01010,B01001,B00000}
  },
  {
    {B10000,B11000,B01111,B01111,B01111,B00111,B01001,B10010},
    {B00101,B00111,B11111,B11111,B11111,B11110,B01001,B10010}
  }
};

unsigned long previousMillis = 0;
const unsigned long interval = 160;

byte frame = 0;

void showCat(byte f) {
  lcd.createChar(0, cat[f][0]);
  lcd.createChar(1, cat[f][1]);
}

void setup() {
  lcd.init();
  lcd.backlight();

  showCat(0);

  lcd.setCursor(0, 0);
  lcd.write((byte)0);
  lcd.write((byte)1);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    frame = (frame + 1) % FRAME_COUNT;
    showCat(frame);
  }
}
