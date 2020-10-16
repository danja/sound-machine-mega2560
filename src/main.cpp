#include <Arduino.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

// set the LCD number of columns and rows
int lcdColumns = 20;
int lcdRows = 4;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[COLS][ROWS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};
byte rowPins[ROWS] = {34, 35, 36, 37}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {30, 31, 32, 33}; //connect to the column pinouts of the keypad

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup()
{
  Serial.begin(9600);
  // initialize LCD
  lcd.init();
  // turn on LCD backlight
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello, World!");
  lcd.setCursor(0, 1);
  lcd.print("Hello, World!");
  lcd.setCursor(0, 2);
  lcd.print("Hello, World!");
  lcd.setCursor(0, 3);
  lcd.print("Hello, World!");
  lcd.setCursor(0, 0);
}

int count = 0;

void loop()
{
  char customKey = customKeypad.getKey();

  if (customKey)
  {
    if (count++ > 19)
    {
      count = 0;
      lcd.setCursor(0, 0);
    }
    lcd.clear();
    lcd.print(customKey);
    // Serial.println(customKey);
  }
}
