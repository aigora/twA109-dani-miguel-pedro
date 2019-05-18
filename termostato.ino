#include <LiquidCrystal.h> // includes the LiquidCrystal Library 
#include "DHT.h"

#define DHTTYPE DHT11   
const int DHTPin = 7;     // what digital pin we're connected to
DHT dht(DHTPin, DHTTYPE);



//configuracion al crear el objeto lcd
//1º parametro = RS
//2º parametro = E
//3º parametro = D4
//4º parametro = D5
//5º parametro = D6
//6º parametro = D7

LiquidCrystal lcd(8, 9, 10, 11, 12, 13); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7) 

const int pinTermostato=A0;
const int pinLedTermostato=A1;


int termostato=0;

void setup() { 
  Serial.begin(9600);

  pinMode(pinTermostato, INPUT);
  pinMode(pinLedTermostato, OUTPUT);

  dht.begin();
  
  lcd.begin(16,2);

  lcd.print("INICIANDO");
  lcd.setCursor(0,1);
  lcd.print("SISTEMA"); 

  digitalWrite(pinLedTermostato, HIGH);
  delay(5000); 
  digitalWrite(pinLedTermostato, LOW);

  lcd.clear(); 
}


void loop() { 
  //CAPTURAMOS ESTADO DEL TERMOSTATO
  int valorTermostato=analogRead(pinTermostato);
  valorTermostato=map(valorTermostato, 10, 1000, 10, 30);

  lcd.clear(); 

  if(valorTermostato!=termostato){
    lcd.setCursor(0,0);
    lcd.print("TERMOSTATO:");
    lcd.setCursor(0,1);
    lcd.print(valorTermostato); 
    termostato=valorTermostato;
    delay(1000);
  }else{
    //CAPTURAMOS LA TEMPERATURA Y LA HUMEDAD
    int h = dht.readHumidity();
    int t = dht.readTemperature();
    
    if (isnan(h) || isnan(t)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }
    
    //IMPRIMIMOS POR EL SERIAL
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" *C ");
    Serial.println("");
  
  
    //IMPRIMIR EN LA LCD
    lcd.setCursor(0,0);
    lcd.print("TEMP: "+String(t)+"C");
    lcd.setCursor(0,1);
    lcd.print("HUM.: "+String(h)+"%"); 


    //VERIFICAR TEMPERATURA CON RESPECTO A TERMOSTATO
    if(t<=termostato){
      digitalWrite(pinLedTermostato, HIGH);
    }else{
      digitalWrite(pinLedTermostato, LOW);
    }
    
    delay(500);
  }
}
