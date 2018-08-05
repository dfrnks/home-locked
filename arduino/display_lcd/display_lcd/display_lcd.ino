// Programa : Teste LCD 16x2 com Keypad
// Autor : Arduino e Cia

#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setMessage(String message = "") {
  if (message) {
    lcd.clear();
    lcd.print (message);
    delay(1000);
  }
  lcd.clear();
  lcd.print("Hey ho, lets go!");
  lcd.setCursor(0, 1);
  lcd.print("Clique...");
}

void setup() {
  lcd.begin(16, 2);
  setMessage();
}

void loop() {
  int botao;
  //  lcd.clear();
  botao = analogRead (0);  //Leitura do valor da porta analógica A0
  lcd.setCursor(6, 1);
  //  lcd.print(botao);
  //  delay(300);
  if (botao < 100) { //Direita
    setMessage("Direita");
  } else if (botao < 200) { //Cima
    setMessage("Cima");
  } else if (botao < 400) { //Baixo
    setMessage("Baixo");
  } else if (botao < 600) { //Esquera
    setMessage("Esquerda");
  } else if (botao < 800) { //Select
    setMessage("Select");
  }
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(14, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);

}
