#define S0 8
#define S1 7
#define S2 6
#define S3 5
#define OutputSensor 4
#include <LiquidCrystal_I2C.h>
#include <Servo.h> // menyertakan library servo ke dalam program 
Servo myservo;     // variable untuk menyimpan posisi data
int pos = 00;   
LiquidCrystal_I2C lcd(0x27,16,2);
int IRSensor = 3; // connect ir sensor to arduino pin 2
// int LED = 13; // conect Led to arduino pin 13
int saldo=0;
int seratus=100;
int limapuluh=50;
int duapuluh=20;
int sepuluh=10;
int lima=5;
int dua=2;
int satu=1;
int f_red = 0;
int f_green = 0;
int f_blue = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(13);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  lcd.init();
  lcd.backlight();

  pinMode(OutputSensor, INPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
}

void loop() {
  
  int irhalangan = digitalRead (IRSensor);
 if (irhalangan == 1){
   lcd.clear();
     lcd.setCursor(0, 0);
  Serial.println("Masukkan Uang");
  lcd.println("masukkan uang"); 
   
   
 }
 else{
   delay(4000);
   setting();
   pengecekanuang();
  Serial.print("saldo =");
  Serial.print(saldo);
  Serial.println(".000");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.println("saldo total");
  lcd.setCursor(0, 1);
  lcd.println("Rp.");
  lcd.setCursor(3, 1);
  lcd.println(saldo);
  lcd.setCursor(12, 1);
  lcd.print(".000");
  delay(1000);
  servo();
   delay(1000);
 }
  Serial.println("reset");
  delay(500);
}

void setting(){
    digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  f_red = pulseIn(OutputSensor, LOW);
  Serial.print("R = ");
  Serial.println(f_red);
  delay(1000);

  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  f_green = pulseIn(OutputSensor, LOW);
  Serial.print("G = ");
  Serial.println(f_green);
  delay(1000);

  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  f_blue = pulseIn(OutputSensor, LOW);
  Serial.print("B = ");
  Serial.println(f_blue);
  delay(1000);
}

void pengecekanuang(){
  if((f_red>=14 && f_red<=18)&&(f_green>=22 && f_green<=29)&&(f_blue>=16&&f_blue<=20)||(f_red>18 && f_red<22)&&(f_green>=30 && f_green<=34)&&(f_blue>=21&&f_blue<=25)){
    Serial.println("RP100.000");
    saldo+=seratus;
    lcd.clear();
    lcd.setCursor(0, 0);
  lcd.print("Terimakasih");
  lcd.setCursor(0, 1);
  lcd.print("Rp.100.000");
  delay(1000);
  } else   if((f_red>=14 && f_red<=20)&&(f_green>=17 && f_green<=19)&&(f_blue>=11&&f_blue<=13)||(f_red>=27 && f_red<=30)&&(f_green>=24 && f_green<=28)&&(f_blue>=14&&f_blue<=17)){
    Serial.println("Rp50.000");
    saldo += limapuluh;
        lcd.clear();
    lcd.setCursor(0, 0);
  lcd.print("Terimakasih");
  lcd.setCursor(0, 1);
  lcd.print("Rp.50.000");
  delay(1000);
    }
    else   if((f_red>=20 && f_red<=23)&&(f_green>=20 && f_green<=25)&&(f_blue>=19&&f_blue<=22)||(f_red>=27 && f_red<=30)&&(f_green>=27&& f_green<=31)&&(f_blue>=22&&f_blue<=26)){
    Serial.println("Rp20.000");
    saldo += duapuluh;
    lcd.setCursor(0, 0);
      lcd.clear();
    lcd.setCursor(0, 0);
  lcd.print("Terimakasih");
  lcd.setCursor(0, 1);
  lcd.print("Rp.20.000");
  delay(1000);
    }
    else   if((f_red>=18 && f_red<=20)&&(f_green>=21 && f_green<=23)&&(f_blue>=12&&f_blue<=15)||(f_red>=24 && f_red<=26)&&(f_green>=30 && f_green<=32)&&(f_blue>=18&&f_blue<=21)){
    Serial.println("Rp10.000"); 
    saldo += sepuluh;
        lcd.clear();
    lcd.setCursor(0, 0);
  lcd.print("Terimakasih");
  lcd.setCursor(0, 1);
  lcd.print("Rp.10.000");
  delay(1000);
    }
    else   if((f_red>=12 && f_red<=15)&&(f_green>=16 && f_green<=19)&&(f_blue>=13&&f_blue<=16)||(f_red>=14 && f_red<=17)&&(f_green>=20 && f_green<=23)&&(f_blue>=17&&f_blue<=20)){
    Serial.print("Rp5.000");
    saldo += lima;
    lcd.clear();
    lcd.setCursor(0, 0);
  lcd.print("Terimakasih");
  lcd.setCursor(0, 1);
  lcd.print("Rp.5.000");
  delay(1000);
  }
    else   if((f_red>=22 && f_red<=23)&&(f_green>=25 && f_green<=27)&&(f_blue>=19&&f_blue<=20)||(f_red>=13 && f_red<=15)&&(f_green>=14 && f_green<=16)&&(f_blue>=10&&f_blue<=12)){
    Serial.println("Rp2.000");
    saldo += dua;
        lcd.clear();
    lcd.setCursor(0, 0);
  lcd.print("Terimakasih");
  lcd.setCursor(0, 1);
  lcd.print("Rp.2.000");
  delay(1000);
    }
    else   if((f_red>=11 && f_red<=13)&&(f_green>=13 && f_green<=15)&&(f_blue>=11&&f_blue<=14)||(f_red>=21 && f_red<=23)&&(f_green>=25 && f_green<=28)&&(f_blue>=21&&f_blue<=23)){
    Serial.println("Rp1.000");
    saldo += satu;
        lcd.clear();
    lcd.setCursor(0, 0);
  lcd.print("Terimakasih");
  lcd.setCursor(0, 1);
  lcd.print("Rp.1.000");
  delay(1000);
    } else {
      Serial.println("Uang Tidak Terdeteksi");    
      lcd.clear();
    lcd.setCursor(0, 0);
  lcd.print("Uang Tidak");
  lcd.setCursor(0, 1);
  lcd.print("Terdeteksi");
  delay(1000);
    }

}
 void servo(){
    for(pos = 00; pos < 180; pos += 1)  //fungsi perulangan yang akan dijadikan PWM dengan kenaikan 1
 {
  myservo.write(pos); //prosedur penulisan data PWM ke motor servo
  delay(15); //waktu tunda 15 ms                 
 } 
 for(pos = 180; pos>=1; pos-=1)  //fungsi perulangan yang akan dijadikan PWM dengan penurunan 1
 {                              
  myservo.write(pos);                 
  delay(15);                        
 }
}