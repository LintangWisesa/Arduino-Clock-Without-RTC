#include <LiquidCrystal.h>
#include "LCDKeypad.h"

#define DAYS 0
#define HOURS 1
#define MINUTES 2
#define SECONDS 3
LCDKeypad lcd;

unsigned int days = 0;
unsigned int hours = 0;
unsigned int minutes = 0;
unsigned int seconds = 0;
unsigned int setting = 0;

void setup() { 
  lcd.begin(16,2);
  lcd.setCursor(4, 0);
  lcd.print("JamDUINO");
  lcd.setCursor(0, 1); 
  lcd.print("tanpa modul RTC");
  delay(3500);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Lintang Wisesa");
  lcd.setCursor(1,1);
  lcd.print("simpLINnovation");
  delay(3500);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print(" Setting: Hari  "); // "Hari" means "Day"
}

void loop() {
  incTime();
  printTime();
  buttonListen();
}

void buttonListen() {
  for (int i = 0; i < 5; i++) {
    int button = lcd.button();
    switch (button) {

    case KEYPAD_RIGHT:
      setting++;
      break;

    case KEYPAD_LEFT:
      setting--;
      break;

    case KEYPAD_UP:
      switch (setting) {
      case DAYS:
        days++;
        if (days == 7) days = 0;
        if (days == 0)
        lcd.setCursor(0,1);
        lcd.print("SENIN ");  // "Senin" means "Monday"
        if (days == 1)
        lcd.setCursor(0,1);
        lcd.print("SELASA");  // "Selasa" means "Tuesday"
        if (days == 2)
        lcd.setCursor(0,1);
        lcd.print("RABU  ");  // "Rabu" means "Wednesday"
        if (days == 3)
        lcd.setCursor(0,1);
        lcd.print("KAMIS ");  // "Kamis" means "Thursday"
        if (days == 4)
        lcd.setCursor(0,1);
        lcd.print("JUMAT ");  // "Jumat" means "Friday"
        if (days == 5)
        lcd.setCursor(0,1);
        lcd.print("SABTU ");  // "Sabtu" means "Saturday"
        if (days == 6)
        lcd.setCursor(0,1);
        lcd.print("AHAD  ");  // "Ahad" means "Sunday"
        break;
      case HOURS:
        hours++;
        break;
      case MINUTES:
        minutes++;
        break;
      case SECONDS:
        seconds++;
      }     
      break;

    case KEYPAD_DOWN:
      switch (setting) {
      case DAYS:
        days--;
        if (days == -1) days = 6;
        if (days == 0)
        lcd.setCursor(0,1);
        lcd.print("SENIN ");
        if (days == 1)
        lcd.setCursor(0,1);
        lcd.print("SELASA");
        if (days == 2)
        lcd.setCursor(0,1);
        lcd.print("RABU  ");
        if (days == 3)
        lcd.setCursor(0,1);
        lcd.print("KAMIS ");
        if (days == 4)
        lcd.setCursor(0,1);
        lcd.print("JUMAT ");
        if (days == 5)
        lcd.setCursor(0,1);
        lcd.print("SABTU ");
        if (days == 6)
        lcd.setCursor(0,1);
        lcd.print("AHAD  ");
        break;
      case HOURS:
        hours--;
        if (hours == -1) hours = 23;
        break;
      case MINUTES:
        minutes--;
        if (minutes == -1) minutes = 59;
        break;
      case SECONDS:
        seconds--;
        if (seconds == -1) seconds = 59;
      }
    }

    setting %= 4;
    printSetting();
    
    days %= 7;
    hours %= 24;
    minutes %= 60;
    seconds %= 60;
    printTime();

    while(millis() % 200 != 0);
  }
}


void printSetting() {
  lcd.setCursor(0,0);

  switch (setting) {
  case DAYS:
    lcd.print("JamDUINO   Hari~");  // "Hari" means "Day"
    break;  
  case HOURS:
    lcd.print("JamDUINO    Jam~");  // "Jam" means "Hour"
    break;
  case MINUTES:
    lcd.print("JamDUINO  Menit~");  // "Menit" means "Minute"
    break;
  case SECONDS:
    lcd.print("JamDUINO  Detik~");  // "Detik" means "Second"
  }
}

void incTime() {
 
  seconds++;

  if (seconds == 60) {
    
    seconds = 0;

    minutes++;

    if (minutes == 60) {
      
      minutes = 0;

      hours++;

      if (hours == 24) {
        hours = 0;

        days++;
        if (days == 7) days = 0;
        if (days == 0)
        lcd.setCursor(0,1);
        lcd.print("SENIN ");
        if (days == 1)
        lcd.setCursor(0,1);
        lcd.print("SELASA");
        if (days == 2)
        lcd.setCursor(0,1);
        lcd.print("RABU  ");
        if (days == 3)
        lcd.setCursor(0,1);
        lcd.print("KAMIS ");
        if (days == 4)
        lcd.setCursor(0,1);
        lcd.print("JUMAT ");
        if (days == 5)
        lcd.setCursor(0,1);
        lcd.print("SABTU ");
        if (days == 6)
        lcd.setCursor(0,1);
        lcd.print("AHAD  ");
      }
    }
  }
}

void printTime() {
  lcd.setCursor(6,1);
  char time[17];
  sprintf(time, "  %02i:%02i:%02i", hours, minutes, seconds);
  lcd.print(time);
}
