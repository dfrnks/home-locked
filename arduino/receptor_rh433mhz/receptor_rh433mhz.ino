//Programa : Módulo RF Transmissor com Arduino Uno
//Autor : FILIPEFLOP - Arduino e Cia

#include <VirtualWire.h>

//Para receber
byte message[VW_MAX_MESSAGE_LEN];    // Armazena as mensagens recebidas
byte msgLength = VW_MAX_MESSAGE_LEN; // Armazena o tamanho das mensagens

String mensagem;

void setup()
{
  Serial.begin(9600);
  vw_set_rx_pin(5);// Porta de receber
  vw_setup(2000);             // Bits por segundo
  vw_rx_start();    // Inicializa o receptor
  Serial.println("Esperando o sinal...");

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  uint8_t message[VW_MAX_MESSAGE_LEN];
  uint8_t msgLength = VW_MAX_MESSAGE_LEN;

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
    
    for (int i = 0; i < msgLength; i++)
    {
      Serial.write(message[i]);
    }
    Serial.println();
  }
}
