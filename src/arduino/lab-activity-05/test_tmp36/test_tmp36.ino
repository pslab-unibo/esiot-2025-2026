// #include <LiquidCrystal_I2C.h> 

// LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,20,4); 

void setup() {
  // lcd.init();
  // lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(A0);

  float value_in_Volt = ((float) value)* 0.00488;   //  5 Volt / 1024 range = 0.00488
 
  // TMP36 characteristics: V = Temp * 0.01 + 0.5

  float value_in_C = (value_in_Volt - 0.5) / 0.01;  // for TMP36 T(C°) = Volt - 0.5)

  Serial.println(value_in_C);
  
  /*
  lcd.setCursor(2, 1); // Set the cursor on the third column and first row.
  lcd.print(String("Value in C: ") + value_in_C);
  */
  delay(1000);
}
