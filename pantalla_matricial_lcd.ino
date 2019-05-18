#include <LiquidCrystal.h> // includes the LiquidCrystal Library 

//configuracion al crear el objeto lcd
//1º parametro = RS
//2º parametro = E
//3º parametro = D4
//4º parametro = D5
//5º parametro = D6
//6º parametro = D7

LiquidCrystal lcd(8, 9, 10, 11, 12, 13); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7) 
void setup() { 
  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display } 
  delay(5000); 
}
void loop() { 
  lcd.print("Hola Amor !!!"); // Prints "Arduino" on the LCD 
  delay(2000); // 3 seconds delay 
  lcd.setCursor(0,1); // Sets the location at which subsequent text written to the LCD will be displayed 
  lcd.print("Que tal estas ?"); 
  delay(2000); 
  lcd.clear(); // Clears the display 

  
  lcd.print("Yo aqui probando"); // Prints "Arduino" on the LCD 
  lcd.setCursor(0,1); // Sets the location at which subsequent text written to the LCD will be displayed 
  lcd.print("La pantallita"); 
  delay(2000); 
  lcd.clear(); // Clears the display 

  

  lcd.print("Te Quiero. "); 
  lcd.setCursor(0,1); // Sets the location at which subsequent text written to the LCD will be displayed   
  lcd.print("UN SALUDO !!!"); // Prints "Arduino" on the LCD 
  delay(3000); 
/*
  
  
  lcd.blink(); //Displays the blinking LCD cursor 
  delay(4000); 
  lcd.setCursor(7,1); 
  delay(3000); 
  lcd.noBlink(); // Turns off the blinking LCD cursor 
  lcd.cursor(); // Displays an underscore (line) at the position to which the next character will be written 
  */
  delay(4000); 
  lcd.noCursor(); // Hides the LCD cursor 
  lcd.clear(); // Clears the LCD screen 
}
