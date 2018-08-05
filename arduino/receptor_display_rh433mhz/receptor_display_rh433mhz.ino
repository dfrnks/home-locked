// Programa : Teste LCD 16x2 com Keypad
// Autor : Arduino e Cia

#include <LiquidCrystal.h>
#include <VirtualWire.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

//Para receber
byte message[VW_MAX_MESSAGE_LEN];    // Armazena as mensagens recebidas
byte msgLength = VW_MAX_MESSAGE_LEN; // Armazena o tamanho das mensagens

void setMessage(String message = "") {
  if (message) {
    lcd.clear();
    lcd.print (message);
    delay(2000);
  }
  lcd.clear();
  lcd.print("Hey ho, lets go!");
  lcd.setCursor(0, 1);
  lcd.print("Clique...");
}

void setup() {
  Serial.begin(9600);
  vw_set_rx_pin(2);// Porta de receber
  vw_set_tx_pin(3);
  vw_setup(2000);             // Bits por segundo
  vw_rx_start();    // Inicializa o receptor
  Serial.println("Esperando o sinal...");

  pinMode(LED_BUILTIN, OUTPUT);

  lcd.begin(16, 2);
  setMessage();
}

void loop() {
  uint8_t message[VW_MAX_MESSAGE_LEN];
  uint8_t msgLength = VW_MAX_MESSAGE_LEN;
  String message_str;

  memset(message, 0, VW_MAX_MESSAGE_LEN);
  if (vw_get_message(message, &msgLength)) // Non-blocking
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(50);
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(300);
    digitalWrite(LED_BUILTIN, LOW);

    Serial.print("Recebido: ");

    message_str = "";
    for (int i = 0; i < msgLength; i++)
    {
      Serial.write(message[i]);
     // message_str[i] = message[i];
    }
    Serial.println();

    message_str = (char*)message;
    setMessage(message_str);
  }

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
