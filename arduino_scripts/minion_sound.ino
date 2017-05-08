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

// const initializations
const int NUMBER_OF_PHRASES = 22;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String minion_phrases[22] = {
  "Apple"
  , "Ba Di Da"
  , "Bahaha"
  , "Banana"
  , "Bat Bat"
  , "Boss!!"
  , "Doo"
  , "Fight Fight"
  , "Go to Sleep...."
  , "Hehehe"
  , "Hello"
  , "Hmhm"
  , "Hohoho"
  , "Kung Fu"
  , "Look at You"
  , "Poka Banana"
  , "Restless"
  , "Uno"
  , "Water"
  , "What"
  , "Whistling"
  , "Yup La Lo Doo"
};

void doStartupSeq() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Delay for good measure
  delay(1000);
  // Print a message to the LCD.
  String welcome_message = "Starting Minion Sound Phrases...";
  lcd.print(welcome_message);
  // scroll 16 positions (display length + string length) to the left
  // to move it back to center:
  for (int positionCounter = 0; positionCounter < welcome_message.length() + 16; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }

  lcd.clear();
  lcd.setCursor(0,1);

  delay(1000);
}

void setup() {
  doStartupSeq();
}


void loop(void) {
  for (int i=0;i<NUMBER_OF_PHRASES;i++) {
    lcd.clear();
    lcd.setCursor(16,0);
    lcd.print(minion_phrases[i]);
    for (int posnCounter = 0; posnCounter < minion_phrases[i].length() + 16; posnCounter++) {
      // scroll one position left:
      lcd.scrollDisplayLeft();
      // wait a bit:
      delay(150);
    }
    delay(1000);
  }
}
