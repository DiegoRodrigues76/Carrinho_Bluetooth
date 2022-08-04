#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2, 3);

//aplicativo do controle remoto Bluetooth RC Car (desenvolvido por Andi.Co)

char comando;
int X1 = 4;
int X2 = 5;
int X3 = 6;
int X4 = 7;

void setup() {
  bluetooth.begin(9600);
  pinMode(X1, OUTPUT);
  pinMode(X2, OUTPUT);
  pinMode(X3, OUTPUT);
  pinMode(X4, OUTPUT);
}
void loop() {
  while(bluetooth.available()){
    comando = bluetooth.read();
    if (comando == 'F'){
      frente();
    }
    else if (comando == 'B'){
      tras();
    }
    else if (comando == 'L'){
      esquerda();
    }
    else if (comando == 'R'){
      direita();
    }
    else {
      parado();
    }
  }
}

void frente(){
  digitalWrite(X1, HIGH);
  digitalWrite(X2, LOW);
  digitalWrite(X3, HIGH);
  digitalWrite(X4, LOW);
}

void tras(){
  digitalWrite(X1, LOW);
  digitalWrite(X2, HIGH);
  digitalWrite(X3, LOW);
  digitalWrite(X4, HIGH);
}

void esquerda(){
  digitalWrite(X1, LOW);
  digitalWrite(X2, HIGH);
  digitalWrite(X3, HIGH);
  digitalWrite(X4, LOW);
}

void direita(){
  digitalWrite(X1, HIGH);
  digitalWrite(X2, LOW);
  digitalWrite(X3, LOW);
  digitalWrite(X4, HIGH);
}

void parado(){
  digitalWrite(X1, HIGH);
  digitalWrite(X2, HIGH);
  digitalWrite(X3, HIGH);
  digitalWrite(X4, HIGH);
}
