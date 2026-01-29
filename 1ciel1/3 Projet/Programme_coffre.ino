#include <LiquidCrystal.h>

#include <Servo.h>

int posInitiale = 0;
int Lrouge = 7;
int Lverte = 6;
int buzzer = 8;

Servo servo;

#define NOTE_C4  262
#define NOTE_G3  196

int melody[] = {NOTE_C4, NOTE_G3};

int noteDurations[] = {4, 4};


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {

  lcd.begin(16, 2);
  Serial.begin(9600);
  servo.attach(9);
  servo.write(0);
  pinMode(Lrouge, OUTPUT);
  pinMode(Lverte, OUTPUT);
  digitalWrite(Lrouge, LOW);
  digitalWrite(Lverte, LOW);
  
  pinMode(buzzer, OUTPUT);
  }



void loop() {
    Serial.begin(9600);
  float val = analogRead(A0);
  val=val*1000.0;
  float valIntensite = map(val,0.0,1023.0,0.0,5.0);
  valIntensite = valIntensite/1000.0;
  
  if ((valIntensite>=3.1)&&(valIntensite<=3.5)){
    lcd.clear();
    lcd.print("Code correct ! ");
  
    servo.write(90);
    digitalWrite(Lrouge, LOW);
    digitalWrite(Lverte, HIGH);
  }
  else {
    lcd.clear();
    lcd.print("Code incorrect ! ");
    
    servo.write(0);
   
    
    for (int thisNote = 0; thisNote < 2; thisNote++) {
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(8, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(8);
        }
    
    
    
    digitalWrite(Lverte, LOW);
    digitalWrite(Lrouge, HIGH);
  }
  
  lcd.setCursor(0,1);
  lcd.print(valIntensite);
  delay(100);
}