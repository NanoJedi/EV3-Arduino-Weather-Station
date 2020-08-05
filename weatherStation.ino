#include <LiquidCrystal.h>
#include "DHT.h"
#define DHTPIN 8     // pin DHT is connected
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define DHTTYPE DHT11
boolean data[] = {false, false, false, false, false, false, false, false};
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  dht.begin();
  lcd.begin(16, 2);
  pinMode(7, OUTPUT);
  pinMode(1, OUTPUT);
  delay(2000);

  
}
void loop() {
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  t = t * 9 / 5 + 32;
  if (isnan(t) || isnan(h)) {
    lcd.setCursor(0, 0);
    lcd.print("Failed to read from DHT");
    //Serial.println("Failed to read from DHT");
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Humidity: ");
    lcd.print(h);
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(t);
    lcd.print("F");
    numInBinArray(h);
    transmitAll();
    numInBinArray(t);
    transmitAll();
    digitalWrite(1, HIGH);
    delay(10);
    digitalWrite(1, LOW);
    
    
    
    
    
  }
}
void transmitAll(){
  for(int i=0; i<8; i++){
    tx(data[i]);
    delay(200);
  }
}

  digitalWrite(7, HIGH);
  delay(200);
  if(dat){
    digitalWrite(7, LOW);
  } else {
    delay(200);
    digitalWrite(7, LOW);
  }
}

void numInBinArray(int dat){
void tx(boolean dat){
  for(int i=0; i<8; i++){
    data[i] = false;
  }
  if(dat >= 128){
    dat = dat - 128;
    data[0] = true;
    
  }
  if(dat >= 64){
    dat = dat - 64;
    data[1] = true;
    
  } 
  if(dat >= 32){
    dat = dat - 32;
    data[2] = true;
    
  } 
  if(dat >= 16){
    dat = dat - 16;
    data[3] = true;
    
  } 
  if(dat >= 8){
    dat = dat - 8;
    data[4] = true;
    
  } 
  if(dat >= 4){
    dat = dat - 4;
    data[5] = true;
    
  } 
  if(dat >= 2){
    dat = dat - 2;
    data[6] = true;
    
  }
  if(dat >= 1){
    dat = dat - 1;
    data[7] = true;
    
  }
}
