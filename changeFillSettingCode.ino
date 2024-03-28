// change pin # when actually making this
int changeSettingButton = 1;
#include <LiquidCrystal.h>
// finish setting up lcd screen

int firstCheck = 0;
int secondCheck = 0;
int buttonState = 0;

// 1 is low
// 2 is medium
// 3 is large
int currentDispenseSetting = 1;

void setup() {
  pinMode(changeSettingButton, INPUT);
  lcd.begin();
  lcd.setCursor(0,0);
  // to be changed once touch sensor code integrated
  lcd.print("Cereal Level: ");
  lcd.setCursor(1,0);
  lcd.print("Fill Level: Low");
  buttonState = digitalRead(changeSettingButton);
}

void loop() {
  firstCheck = digitalRead(changeSettingButton);
  // may need to use non delay method but should work fine
  delay(10);
  secondCheck = digitalRead(changeSettingButton);

  handleChangeFillSettings(firstCheck, secondCheck);
}

void handleChangeFillSettings(int firstCheck, int secondCheck) {
  if (firstCheck == secondCheck) {
    if (firstCheck != buttonState) {
      if (currentDispenseSetting == 1) {
        currentDispenseSetting = 2;
        // may need to clear to eliminate characters that are past previous prints
        // also may need to scroll text
        lcd.setCursor(1,0);
        lcd.print("Fill Level: Medium");
      } else if (currentDispenseSetting == 2) {
        currentDispenseSetting = 3;
        lcd.setCursor(1,0);
        lcd.print("Fill Level: High");
      } else if (currentDispenseSetting == 3) {
         currentDispenseSetting = 1;
        lcd.setCursor(1,0);
        lcd.print("Fill Level: Low");
      }
    }
    buttonState = firstCheck;
  }
}
