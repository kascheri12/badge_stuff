/*
Test LCD Character Program

Used to test for properly functioning LCD displays.

This scetch has multiple modes for testing. See PRINT_MODE value below.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)


 Originally created 05 May 2017
 by Kenny Ascheri

 */

// include the library code:
#include <LiquidCrystal.h>

// Constant values declared here
const int NUMBER_OF_CHARS = 190;
// 0 = iterate through all characters before moving to next position
// 1 = iterate through all positions before moving to next character
const int PRINT_MODE = 1;


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

byte all_pixels[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

// HD44780 LCD Character Set found here: https://web.stanford.edu/class/ee281/handouts/lcd_tutorial.pdf
byte charSet[NUMBER_OF_CHARS] = {
            B00100001,B00100000,B00100011,B00100100,B00100101,B00100110,B00100111,B00101000,B00101001,B00101010,B00101011,B00101100,B00101101,B00101110,B00101111,
  B00110000,B00110001,B00110010,B00110011,B00110100,B00110101,B00110110,B00110111,B00111000,B00111001,B00111010,B00111011,B00111100,B00111101,B00111110,B00111111,
  B01000000,B01000001,B01000010,B01000011,B01000100,B01000101,B01000110,B01000111,B01001000,B01001001,B01001010,B01001011,B01001100,B01001101,B01001110,B01001111,
  B01010000,B01010001,B01010010,B01010011,B01010100,B01010101,B01010110,B01010111,B01011000,B01011001,B01011010,B01011011,B01011100,B01011101,B01011110,B01011111,
  B01100000,B01100001,B01100010,B01100011,B01100100,B01100101,B01100110,B01100111,B01101000,B01101001,B01101010,B01101011,B01101100,B01101101,B01101110,B01101111,
  B01110000,B01110001,B01110010,B01110011,B01110100,B01110101,B01110110,B01110111,B01111000,B01111001,B01111010,B01111011,B01111100,B01111101,B01111110,B01111111,
            B10100001,B10100010,B10100011,B10100100,B10100101,B10100110,B10100111,B10101000,B10101001,B10101010,B10101011,B10101100,B10101101,B10101110,B10101111,
  B10110000,B10110001,B10110010,B10110011,B10110100,B10110101,B10110110,B10110111,B10111000,B10111001,B10111010,B10111011,B10111100,B10111101,B10111110,B10111111,
  B11000000,B11000001,B11000010,B11000011,B11000100,B11000101,B11000110,B11000111,B11001000,B11001001,B11001010,B11001011,B11001100,B11001101,B11001110,B11001111,
  B11010000,B11010001,B11010010,B11010011,B11010100,B11010101,B11010110,B11010111,B11011000,B11011001,B11011010,B11011011,B11011100,B11011101,B11011110,B11011111,
  B11100000,B11100001,B11100010,B11100011,B11100100,B11100101,B11100110,B11100111,B11101000,B11101001,B11101010,B11101011,B11101100,B11101101,B11101110,B11101111,
  B11110000,B11110001,B11110010,B11110011,B11110100,B11110101,B11110110,B11110111,B11111000,B11111001,B11111010,B11111011,B11111100,B11111101,B11111110,B11111111
};

void showSmiley() {
  lcd.clear();
  lcd.createChar(0,smiley);
  lcd.write(byte(0));
}

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Delay for good measure
  delay(1000);
  // Print a message to the LCD.
  String welcome_message = "Welcome to Kenny's Testing Program...";
  lcd.setCursor(3,0);
  lcd.print(welcome_message);
  // scroll 16 positions (display length + string length) to the left
  // to move it back to center:
  for (int positionCounter = 0; positionCounter < welcome_message.length(); positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }

  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Starting test");

  delay(1000);
}

void loop() {
  // test all pixels
  doAllPixelsTest();

  // check the print_mode value
  if (PRINT_MODE == 0) {
    for (int i = 0; i < 2; i++) {
      for (int j=0;j<16;j++) {
        for (int z=0;z<NUMBER_OF_CHARS;z++) {
          lcd.clear();
          lcd.setCursor(j,i);
          lcd.write(charSet[z]);
          delay(100);
        }
      }
    }
  } else if (PRINT_MODE == 1) {
    for (int l=0;l<NUMBER_OF_CHARS;l++) {
      for (int i = 0; i < 2; i++) {
        for (int j=0;j<16;j++) {
          lcd.clear();
          lcd.setCursor(j,i);
          lcd.write(charSet[l]);
          delay(100);
        }
      }
    }
  }
}

void doAllPixelsTest() {
  // crete custom character
  lcd.createChar(0,all_pixels);
  // check all pixels first
  for (int i=0;i<2;i++) {
    for (int j=0;j<16;j++) {
      lcd.setCursor(j,i);
      lcd.write(byte(0));
    }
  }
  delay(2000);
  for (int i=3;i>0;i--) {
    lcd.setCursor(7,1);
    lcd.print("0");
    lcd.print(i);
    delay(1000);
  }
  lcd.clear();
}
