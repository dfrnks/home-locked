/**
 * Projeto Arduino acendendo e apagando o led com botão.
 */

// Constantes, valores dos pinos
const int led = 8;
const int btn = 2;

int status_btn = 0;
int status_led = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT); 
}

void loop() {
  // Ler o status do btn
  status_btn = digitalRead(btn);

  if(status_btn == HIGH){
    status_led = digitalRead(led);
    if(status_led == HIGH){
      digitalWrite(led, LOW);
    }else{
      digitalWrite(led, HIGH);
    }
    delay(300);
 }
}
