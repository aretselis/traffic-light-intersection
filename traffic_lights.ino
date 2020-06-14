#include <Wire.h> 
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#define DELAY_ADRIANOUPOLEOS 15
#define DELAY_AIGAIOU 25

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7);

/*Pin declaration*/

int prasino_aigaiou = 11;
int portokali_aigaiou = 12;
int kokkino_aigaiou = 13;
int prasino_adrianoupoleos = 8;
int portokali_adrianoupoleos = 9;
int kokkino_adrianoupoleos = 10;
int kokkino_pezon_adrianoupoleos = 5;
int prasino_pezon_adrianoupoleos = 6;
int i=0,j=0;


void setup() {
  pinMode(prasino_aigaiou, OUTPUT);
  pinMode(portokali_aigaiou, OUTPUT);
  pinMode(kokkino_aigaiou, OUTPUT);
  pinMode(prasino_adrianoupoleos, OUTPUT);
  pinMode(portokali_adrianoupoleos, OUTPUT);
  pinMode(kokkino_adrianoupoleos, OUTPUT);
  pinMode(kokkino_pezon_adrianoupoleos, OUTPUT);
  pinMode(prasino_pezon_adrianoupoleos, OUTPUT);
  lcd.begin (20,4); // 16 x 2 LCD module
  lcd.setBacklightPin(3,POSITIVE); // BL, BL_POL
  lcd.setBacklight(HIGH);   
  digitalWrite(prasino_aigaiou, LOW);
  digitalWrite(portokali_aigaiou, LOW);
  digitalWrite(kokkino_aigaiou, HIGH );
  digitalWrite(prasino_adrianoupoleos, HIGH );
}


void loop() {
  j=DELAY_AIGAIOU-1;
  adrianoupoleos_sequence();
  aigaiou_sequence();
}

void aigaiou_sequence(){
  digitalWrite(kokkino_pezon_adrianoupoleos, LOW);
  digitalWrite(prasino_pezon_adrianoupoleos, HIGH );
  j=DELAY_ADRIANOUPOLEOS-4;
  for(i=0;i<DELAY_ADRIANOUPOLEOS-4;i++) {
    lcd.clear();
    lcd.setCursor(7,0);
    lcd.print("GREEN");
    lcd.setCursor(9,2);
    lcd.print(j);
    delay(1000);
    j=j-1;}
  digitalWrite(kokkino_pezon_adrianoupoleos, HIGH);
  digitalWrite(prasino_pezon_adrianoupoleos, LOW );
    j=DELAY_AIGAIOU+3;
    for(i;i<DELAY_ADRIANOUPOLEOS-2;i++) {
    lcd.clear();
    lcd.setCursor(8,0);
    lcd.print("RED");
    lcd.setCursor(9,2);
    lcd.print(j);
    delay(1000);
    j=j-1;}
  digitalWrite(prasino_aigaiou, LOW);
  digitalWrite(portokali_aigaiou, HIGH);
   for(i;i<DELAY_ADRIANOUPOLEOS;i++) {
    lcd.clear();
    lcd.setCursor(8,0);
    lcd.print("RED");
    lcd.setCursor(9,2);
    lcd.print(j);
    delay(1000);
    j=j-1;}
  digitalWrite(portokali_aigaiou, LOW);
  digitalWrite(kokkino_aigaiou, HIGH );
  digitalWrite(kokkino_adrianoupoleos, LOW );
  digitalWrite(prasino_adrianoupoleos, HIGH );
  }

  void adrianoupoleos_sequence(){
  digitalWrite(kokkino_pezon_adrianoupoleos, HIGH);
  digitalWrite(prasino_pezon_adrianoupoleos, LOW);
  for(i=0;i<DELAY_AIGAIOU-2;i++) {
    lcd.clear();
    lcd.setCursor(8,0);
    lcd.print("RED");
    lcd.setCursor(9,2);
    lcd.print(j);
    delay(1000);
    j=j-1;}
  digitalWrite(prasino_adrianoupoleos, LOW );
  digitalWrite(portokali_adrianoupoleos, HIGH );
   for(i;i<DELAY_AIGAIOU;i++) {
    lcd.clear();
    lcd.setCursor(8,0);
    lcd.print("RED");
    lcd.setCursor(9,2);
    lcd.print(j);
    delay(1000);
    j=j-1;}
  digitalWrite(portokali_adrianoupoleos, LOW );
  digitalWrite(kokkino_adrianoupoleos, HIGH );
  digitalWrite(kokkino_aigaiou, LOW );
  digitalWrite(prasino_aigaiou, HIGH);
  }