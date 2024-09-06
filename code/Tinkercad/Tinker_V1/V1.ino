#define rele1 3
#define rele2 2
#define rele3 1
#define rele4 0
#define rele5 14

const int ledVetor1 = 15, ledVetor2 = 16, ledVetor3 = 17, ledVetor4 = 18, ledVetor5 = 19;

const int bt1D = 8, bt2D = 7, bt3D = 6, bt4D = 5, bt5D = 4;
const int bt1E = 13, bt2E = 12, bt3E = 11, bt4E = 10, bt5E = 9;

int vetorVarDireita[5] = {bt1D, bt2D, bt3D, bt4D, bt5D};
int vetorVarEsquerda[5] = {bt1E, bt2E, bt3E, bt4E, bt5E};


bool sbt1d = false, sbt2D = false, sbt3D = false, sbt4D = false, sbt5D = false;
bool sbt1E = false, sbt2E = false, sbt3E = false, sbt4E = false, sbt5E = false;

bool vetorDireita[5] = {sbt1d, sbt2D, sbt3D, sbt4D, sbt5D};
bool vetorEsquerda[5] = {sbt1E, sbt2E, sbt3E, sbt4E, sbt5E};


bool guardaSbt1D = false, guardaSbt2D = false, guardaSbt3D = false, guardaSbt4D = false, guardaSbt5D = false;
bool guardaSbt1E = false, guardaSbt2E = false, guardaSbt3E = false, guardaSbt4E = false, guardaSbt5E = false;

bool vetorEstadosDireita[5] = {guardaSbt1D, guardaSbt2D, guardaSbt3D, guardaSbt4D, guardaSbt5D};
bool vetorEstadosEsquerda[5] = {guardaSbt1E, guardaSbt2E, guardaSbt3E, guardaSbt4E, guardaSbt5E};

bool tempoDeDigitacao = false;
unsigned long previousMillis = 0;

bool capsLock = false;
bool shift = false;

void setup() {

  Serial.begin(9600);
  Serial.println("Teclas apertadas:");

  pinMode(bt1D, INPUT);
  pinMode(bt2D, INPUT);
  pinMode(bt3D, INPUT);
  pinMode(bt4D, INPUT);
  pinMode(bt5D, INPUT);
  pinMode(bt1E, INPUT);
  pinMode(bt2E, INPUT);
  pinMode(bt3E, INPUT);
  pinMode(bt4E, INPUT);
  pinMode(bt5E, INPUT);
  pinMode(rele1, OUTPUT);
  pinMode(rele2, OUTPUT);
  pinMode(rele3, OUTPUT);
  pinMode(rele4, OUTPUT);
  pinMode(rele5, OUTPUT);
  pinMode(ledVetor1, OUTPUT);
  pinMode(ledVetor2, OUTPUT);
  pinMode(ledVetor3, OUTPUT);
  pinMode(ledVetor5, OUTPUT);
  pinMode(ledVetor5, OUTPUT);
}

void loop() {
  for (int d = 0; d < 5; d++) {
    vetorDireita[d] = digitalRead(vetorVarDireita[d]);
    if (vetorDireita[d] == HIGH) {
      if (d == 0) {
        guardaSbt1D = true;
      }
      if (d == 1) {
        guardaSbt2D = true;
      }
      if (d == 2) {
        guardaSbt3D = true;
      }
      if (d == 3) {
        guardaSbt4D = true;
      }
      if (d == 4) {
        guardaSbt5D = true;
      }
      tempoDeDigitacao = true;
    }
  }

  for (int e = 0; e < 5; e++) {
    vetorEsquerda[e] = digitalRead(vetorVarEsquerda[e]);
    if (vetorEsquerda[e] == HIGH) {
      if (e == 0) {
        guardaSbt1E = true;
      }
      if (e == 1) {
        guardaSbt2E = true;
      }
      if (e == 2) {
        guardaSbt3E = true;
      }
      if (e == 3) {
        guardaSbt4E = true;
      }
      if (e == 4) {
        guardaSbt5E = true;
      }
      tempoDeDigitacao = true;
    }
  }

  if (tempoDeDigitacao) {
    unsigned long currentMillis = millis();
    unsigned long tempoEspera = 500;

    while (millis() - currentMillis < tempoEspera)
    {
      previousMillis = currentMillis;

      for (int d = 0; d < 5; d++) {
        vetorDireita[d] = digitalRead(vetorVarDireita[d]);
        if (vetorDireita[d] == HIGH) {
          if (d == 0) {
            guardaSbt1D = true;
          }
          if (d == 1) {
            guardaSbt2D = true;
          }
          if (d == 2) {
            guardaSbt3D = true;
          }
          if (d == 3) {
            guardaSbt4D = true;
          }
          if (d == 4) {
            guardaSbt5D = true;
          }
        }
      }

      for (int e = 0; e < 5; e++) {
        vetorEsquerda[e] = digitalRead(vetorVarEsquerda[e]);
        if (vetorEsquerda[e] == HIGH) {
          if (e == 0) {
            guardaSbt1E = true;
          }
          if (e == 1) {
            guardaSbt2E = true;
          }
          if (e == 2) {
            guardaSbt3E = true;
          }
          if (e == 3) {
            guardaSbt4E = true;
          }
          if (e == 4) {
            guardaSbt5E = true;
          }
        }
      }
    }
    escreve();
    tempoDeDigitacao = false;
    reseta();
  }
}

void escreve() {
    if(capsLock == true || shift == true){
        if (guardaSbt1D == true && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("A");
            digitalWrite(ledVetor1, HIGH);
            delay(500);
            digitalWrite(ledVetor1, LOW);
            shift = false;
        }

        if (guardaSbt1D == false && guardaSbt2D == true && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("B");
            digitalWrite(ledVetor2, HIGH);
            delay(500);
            digitalWrite(ledVetor2, LOW);
            shift = false;
        }

        if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == true && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("C");
            digitalWrite(ledVetor3, HIGH);
            delay(500);
            digitalWrite(ledVetor3, LOW);
            shift = false;
        }

        if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == true && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("D");
            digitalWrite(ledVetor4, HIGH);
            delay(500);
            digitalWrite(ledVetor4, LOW);
            shift = false;
        }

        if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == true && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("E");
            digitalWrite(ledVetor5, HIGH);
            delay(500);
            digitalWrite(ledVetor5, LOW);
        }

        if (guardaSbt1D == true && guardaSbt2D == true && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("F");
            digitalWrite(3, HIGH);
            digitalWrite(ledVetor1, HIGH);
            delay(500);
            digitalWrite(3, LOW);
            digitalWrite(ledVetor1, LOW);
            shift = false;
        }

        if (guardaSbt1D == true && guardaSbt2D == false && guardaSbt3D == true && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("G");
            digitalWrite(rele1, HIGH);
            digitalWrite(ledVetor2, HIGH);
            delay(500);
            digitalWrite(rele1, LOW);
            digitalWrite(ledVetor2, LOW);
            shift = false;
        }

        if (guardaSbt1D == true && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == true && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("H");
            digitalWrite(rele1, HIGH);
            digitalWrite(ledVetor3, HIGH);
            delay(500);
            digitalWrite(rele1, LOW);
            digitalWrite(ledVetor3, LOW);
            shift = false;
        }

        if (guardaSbt1D == true && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == true && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("I");
            digitalWrite(rele1, HIGH);
            digitalWrite(ledVetor4, HIGH);
            delay(500);
            digitalWrite(rele1, LOW);
            digitalWrite(ledVetor4, LOW);
            shift = false;
        }

        if (guardaSbt1D == false && guardaSbt2D == true && guardaSbt3D == true && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("J");
            digitalWrite(rele1, HIGH);
            digitalWrite(ledVetor5, HIGH);
            delay(500);
            digitalWrite(rele1, LOW);
            digitalWrite(ledVetor5, LOW);
            shift = false;
        }

        if (guardaSbt1D == false && guardaSbt2D == true && guardaSbt3D == false && guardaSbt4D == true && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("K");
            digitalWrite(rele2, HIGH);
            digitalWrite(ledVetor1, HIGH);
            delay(500);
            digitalWrite(rele2, LOW);
            digitalWrite(ledVetor1, LOW);
            shift = false;
        }

        if (guardaSbt1D == false && guardaSbt2D == true && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == true && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("L");
            digitalWrite(rele2, HIGH);
            digitalWrite(ledVetor2, HIGH);
            delay(500);
            digitalWrite(rele2, LOW);
            digitalWrite(ledVetor2, LOW);
            shift = false;
        }

        if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == true && guardaSbt4D == true && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("M");
            digitalWrite(rele2, HIGH);
            digitalWrite(ledVetor3, HIGH);
            delay(500);
            digitalWrite(rele2, LOW);
            digitalWrite(ledVetor3, LOW);
            shift = false;
        }

        if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == true && guardaSbt4D == false && guardaSbt5D == true && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("N");
            digitalWrite(rele2, HIGH);
            digitalWrite(ledVetor4, HIGH);
            delay(500);
            digitalWrite(rele2, LOW);
            digitalWrite(ledVetor4, LOW);
            shift = false;
        }

        if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == true && guardaSbt5D == true && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("O");
            digitalWrite(rele2, HIGH);
            digitalWrite(ledVetor5, HIGH);
            delay(500);
            digitalWrite(rele2, LOW);
            digitalWrite(ledVetor5, LOW);
            shift = false;
        }

        if (guardaSbt1D == true && guardaSbt2D == true && guardaSbt3D == true && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("P");
            digitalWrite(rele3, HIGH);
            digitalWrite(ledVetor1, HIGH);
            delay(500);
            digitalWrite(rele3, LOW);
            digitalWrite(ledVetor1, LOW);
            shift = false;
        }

        if (guardaSbt1D == true && guardaSbt2D == true && guardaSbt3D == false && guardaSbt4D == true && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("Q");
            digitalWrite(rele3, HIGH);
            digitalWrite(ledVetor2, HIGH);
            delay(500);
            digitalWrite(rele3, LOW);
            digitalWrite(ledVetor2, LOW);
            shift = false;
        }

        if (guardaSbt1D == true && guardaSbt2D == true && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == true && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("R");
            digitalWrite(rele3, HIGH);
            digitalWrite(ledVetor3, HIGH);
            delay(500);
            digitalWrite(rele3, LOW);
            digitalWrite(ledVetor3, LOW);
            shift = false;
        }

        if (guardaSbt1D == true && guardaSbt2D == false && guardaSbt3D == true && guardaSbt4D == true && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("S");
            digitalWrite(rele3, HIGH);
            digitalWrite(ledVetor4, HIGH);
            delay(500);
            digitalWrite(rele3, LOW);
            digitalWrite(ledVetor4, LOW);
            shift = false;
        }

        if (guardaSbt1D == true && guardaSbt2D == false && guardaSbt3D == true && guardaSbt4D == false && guardaSbt5D == true && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("T");
            digitalWrite(rele3, HIGH);
            digitalWrite(ledVetor5, HIGH);
            delay(500);
            digitalWrite(rele3, LOW);
            digitalWrite(ledVetor5, LOW);
            shift = false;
        }

        if (guardaSbt1D == true && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == true && guardaSbt5D == true && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("U");
            digitalWrite(rele4, HIGH);
            digitalWrite(ledVetor1, HIGH);
            delay(500);
            digitalWrite(rele4, LOW);
            digitalWrite(ledVetor1, LOW);
            shift = false;
        }

        if (guardaSbt1D == true && guardaSbt2D == true && guardaSbt3D == true && guardaSbt4D == true && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("V");
            digitalWrite(rele4, HIGH);
            digitalWrite(ledVetor2, HIGH);
            delay(500);
            digitalWrite(rele4, LOW);
            digitalWrite(ledVetor2, LOW);
            shift = false;
        }

        if (guardaSbt1D == true && guardaSbt2D == false && guardaSbt3D == true && guardaSbt4D == true && guardaSbt5D == true && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("W");
            digitalWrite(rele4, HIGH);
            digitalWrite(ledVetor3, HIGH);
            delay(500);
            digitalWrite(rele4, LOW);
            digitalWrite(ledVetor3, LOW);
            shift = false;
        }

        if (guardaSbt1D == true && guardaSbt2D == true && guardaSbt3D == false && guardaSbt4D == true && guardaSbt5D == true && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("X");
            digitalWrite(rele4, HIGH);
            digitalWrite(ledVetor4, HIGH);
            delay(500);
            digitalWrite(rele4, LOW);
            digitalWrite(ledVetor4, LOW);
            shift = false;
        }

        if (guardaSbt1D == true && guardaSbt2D == true && guardaSbt3D == true && guardaSbt4D == false && guardaSbt5D == true && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("Y");
            digitalWrite(rele4, HIGH);
            digitalWrite(ledVetor5, HIGH);
            delay(500);
            digitalWrite(rele4, LOW);
            digitalWrite(ledVetor5, LOW);
            shift = false;
        }

        if (guardaSbt1D == false && guardaSbt2D == true && guardaSbt3D == true && guardaSbt4D == true && guardaSbt5D == true && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("Z");
            digitalWrite(rele5, HIGH);
            digitalWrite(ledVetor1, HIGH);
            delay(500);
            digitalWrite(rele5, LOW);
            digitalWrite(ledVetor1, LOW);
            shift = false;
        }
    }else{
        if (guardaSbt1D == true && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("a");
            digitalWrite(ledVetor1, HIGH);
            delay(500);
            digitalWrite(ledVetor1, LOW);
        }

        if (guardaSbt1D == false && guardaSbt2D == true && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("b");
            digitalWrite(ledVetor2, HIGH);
            delay(500);
            digitalWrite(ledVetor2, LOW);
        }

        if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == true && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("c");
            digitalWrite(ledVetor3, HIGH);
            delay(500);
            digitalWrite(ledVetor3, LOW);
        }

        if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == true && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("d");
            digitalWrite(ledVetor4, HIGH);
            delay(500);
            digitalWrite(ledVetor4, LOW);
        }

        if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == true && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("e");
            digitalWrite(ledVetor5, HIGH);
            delay(500);
            digitalWrite(ledVetor5, LOW);
        }

        if (guardaSbt1D == true && guardaSbt2D == true && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("f");
            digitalWrite(3, HIGH);
            digitalWrite(ledVetor1, HIGH);
            delay(500);
            digitalWrite(3, LOW);
            digitalWrite(ledVetor1, LOW);
        }

        if (guardaSbt1D == true && guardaSbt2D == false && guardaSbt3D == true && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("g");
            digitalWrite(rele1, HIGH);
            digitalWrite(ledVetor2, HIGH);
            delay(500);
            digitalWrite(rele1, LOW);
            digitalWrite(ledVetor2, LOW);
        }

        if (guardaSbt1D == true && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == true && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("h");
            digitalWrite(rele1, HIGH);
            digitalWrite(ledVetor3, HIGH);
            delay(500);
            digitalWrite(rele1, LOW);
            digitalWrite(ledVetor3, LOW);
        }

        if (guardaSbt1D == true && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == true && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("i");
            digitalWrite(rele1, HIGH);
            digitalWrite(ledVetor4, HIGH);
            delay(500);
            digitalWrite(rele1, LOW);
            digitalWrite(ledVetor4, LOW);
        }

        if (guardaSbt1D == false && guardaSbt2D == true && guardaSbt3D == true && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("j");
            digitalWrite(rele1, HIGH);
            digitalWrite(ledVetor5, HIGH);
            delay(500);
            digitalWrite(rele1, LOW);
            digitalWrite(ledVetor5, LOW);
        }

        if (guardaSbt1D == false && guardaSbt2D == true && guardaSbt3D == false && guardaSbt4D == true && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("k");
            digitalWrite(rele2, HIGH);
            digitalWrite(ledVetor1, HIGH);
            delay(500);
            digitalWrite(rele2, LOW);
            digitalWrite(ledVetor1, LOW);
        }

        if (guardaSbt1D == false && guardaSbt2D == true && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == true && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("l");
            digitalWrite(rele2, HIGH);
            digitalWrite(ledVetor2, HIGH);
            delay(500);
            digitalWrite(rele2, LOW);
            digitalWrite(ledVetor2, LOW);
        }

        if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == true && guardaSbt4D == true && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("m");
            digitalWrite(rele2, HIGH);
            digitalWrite(ledVetor3, HIGH);
            delay(500);
            digitalWrite(rele2, LOW);
            digitalWrite(ledVetor3, LOW);
        }

        if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == true && guardaSbt4D == false && guardaSbt5D == true && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("n");
            digitalWrite(rele2, HIGH);
            digitalWrite(ledVetor4, HIGH);
            delay(500);
            digitalWrite(rele2, LOW);
            digitalWrite(ledVetor4, LOW);
        }

        if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == true && guardaSbt5D == true && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("o");
            digitalWrite(rele2, HIGH);
            digitalWrite(ledVetor5, HIGH);
            delay(500);
            digitalWrite(rele2, LOW);
            digitalWrite(ledVetor5, LOW);
        }

        if (guardaSbt1D == true && guardaSbt2D == true && guardaSbt3D == true && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("p");
            digitalWrite(rele3, HIGH);
            digitalWrite(ledVetor1, HIGH);
            delay(500);
            digitalWrite(rele3, LOW);
            digitalWrite(ledVetor1, LOW);
        }

        if (guardaSbt1D == true && guardaSbt2D == true && guardaSbt3D == false && guardaSbt4D == true && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("q");
            digitalWrite(rele3, HIGH);
            digitalWrite(ledVetor2, HIGH);
            delay(500);
            digitalWrite(rele3, LOW);
            digitalWrite(ledVetor2, LOW);
        }

        if (guardaSbt1D == true && guardaSbt2D == true && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == true && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("r");
            digitalWrite(rele3, HIGH);
            digitalWrite(ledVetor3, HIGH);
            delay(500);
            digitalWrite(rele3, LOW);
            digitalWrite(ledVetor3, LOW);
        }

        if (guardaSbt1D == true && guardaSbt2D == false && guardaSbt3D == true && guardaSbt4D == true && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("s");
            digitalWrite(rele3, HIGH);
            digitalWrite(ledVetor4, HIGH);
            delay(500);
            digitalWrite(rele3, LOW);
            digitalWrite(ledVetor4, LOW);
        }

        if (guardaSbt1D == true && guardaSbt2D == false && guardaSbt3D == true && guardaSbt4D == false && guardaSbt5D == true && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("t");
            digitalWrite(rele3, HIGH);
            digitalWrite(ledVetor5, HIGH);
            delay(500);
            digitalWrite(rele3, LOW);
            digitalWrite(ledVetor5, LOW);
        }

        if (guardaSbt1D == true && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == true && guardaSbt5D == true && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("u");
            digitalWrite(rele4, HIGH);
            digitalWrite(ledVetor1, HIGH);
            delay(500);
            digitalWrite(rele4, LOW);
            digitalWrite(ledVetor1, LOW);
        }

        if (guardaSbt1D == true && guardaSbt2D == true && guardaSbt3D == true && guardaSbt4D == true && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("v");
            digitalWrite(rele4, HIGH);
            digitalWrite(ledVetor2, HIGH);
            delay(500);
            digitalWrite(rele4, LOW);
            digitalWrite(ledVetor2, LOW);
        }

        if (guardaSbt1D == true && guardaSbt2D == false && guardaSbt3D == true && guardaSbt4D == true && guardaSbt5D == true && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("w");
            digitalWrite(rele4, HIGH);
            digitalWrite(ledVetor3, HIGH);
            delay(500);
            digitalWrite(rele4, LOW);
            digitalWrite(ledVetor3, LOW);
        }

        if (guardaSbt1D == true && guardaSbt2D == true && guardaSbt3D == false && guardaSbt4D == true && guardaSbt5D == true && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("x");
            digitalWrite(rele4, HIGH);
            digitalWrite(ledVetor4, HIGH);
            delay(500);
            digitalWrite(rele4, LOW);
            digitalWrite(ledVetor4, LOW);
        }

        if (guardaSbt1D == true && guardaSbt2D == true && guardaSbt3D == true && guardaSbt4D == false && guardaSbt5D == true && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("y");
            digitalWrite(rele4, HIGH);
            digitalWrite(ledVetor5, HIGH);
            delay(500);
            digitalWrite(rele4, LOW);
            digitalWrite(ledVetor5, LOW);
        }

        if (guardaSbt1D == false && guardaSbt2D == true && guardaSbt3D == true && guardaSbt4D == true && guardaSbt5D == true && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
            Serial.print("z");
            digitalWrite(rele5, HIGH);
            digitalWrite(ledVetor1, HIGH);
            delay(500);
            digitalWrite(rele5, LOW);
            digitalWrite(ledVetor1, LOW);
        }
    }

    //Números
  if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == true && guardaSbt2E == true && guardaSbt3E == true && guardaSbt4E == true && guardaSbt5E == true) {
    Serial.print("0");
    digitalWrite(rele5, HIGH);
    digitalWrite(ledVetor2, HIGH);
    delay(500);
    digitalWrite(rele5, LOW);
    digitalWrite(ledVetor2, LOW);
  }

  if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == true && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
    Serial.print("1");
    digitalWrite(rele5, HIGH);
    digitalWrite(ledVetor3, HIGH);
    delay(500);
    digitalWrite(rele5, LOW);
    digitalWrite(ledVetor3, LOW);
  }

  if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == true && guardaSbt3E == true && guardaSbt4E == false && guardaSbt5E == false) {
    Serial.print("2");
    digitalWrite(rele5, HIGH);
    digitalWrite(ledVetor4, HIGH);
    delay(500);
    digitalWrite(rele5, LOW);
    digitalWrite(ledVetor4, LOW);
  }
  if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == true && guardaSbt4E == false && guardaSbt5E == false) {
    Serial.print("3");
    digitalWrite(rele5, HIGH);
    digitalWrite(ledVetor5, HIGH);
    delay(500);
    digitalWrite(rele5, LOW);
    digitalWrite(ledVetor5, LOW);
  }
  if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == true && guardaSbt5E == false) {
    Serial.print("4");
  }
  if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == true) {
    Serial.print("5");
  }
  if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == true && guardaSbt2E == true && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
    Serial.print("6");
  }
  if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == true && guardaSbt2E == false && guardaSbt3E == true && guardaSbt4E == false && guardaSbt5E == false) {
    Serial.print("7");
  }
  if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == true && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == true && guardaSbt5E == false) {
    Serial.print("8");
  }
  if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == true && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == true) {
    Serial.print("9");
  }

  //Sinal
  	//Espaço
    if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == false) {
        Serial.print(" ");
    }

    //Ponto Final
    if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == true && guardaSbt3E == true && guardaSbt4E == false && guardaSbt5E == false) {
        Serial.print(".");
    }

    //Virgula
    if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == true && guardaSbt3E == false && guardaSbt4E == true && guardaSbt5E == false) {
        Serial.print(",");
    }

    //Ponto e Virgula
    if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == true && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == true) {
        Serial.print(";");
    }

    //Dois Pontos
    if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == true && guardaSbt4E == true && guardaSbt5E == false) {
        Serial.print(":");
    }

    //Exclamação
    if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == true && guardaSbt4E == false && guardaSbt5E == true) {
        Serial.print("!");
    }

    //Interrogação
    if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == true && guardaSbt5E == true) {
        Serial.print("?");
    }

    //Aspas Duplas
    if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == true && guardaSbt2E == true && guardaSbt3E == true && guardaSbt4E == false && guardaSbt5E == false) {
        Serial.print('"');
    }

    //Arroba
    if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == true && guardaSbt2E == true && guardaSbt3E == false && guardaSbt4E == true && guardaSbt5E == false) {
        Serial.print("@");
    }

    //Hashtag
    if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == true && guardaSbt2E == true && guardaSbt3E == false && guardaSbt4E == false && guardaSbt5E == true) {
        Serial.print("#");
    }

    //Por cento
    if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == true && guardaSbt2E == false && guardaSbt3E == true && guardaSbt4E == true && guardaSbt5E == false) {
        Serial.print("%");
    }

    //Asterisco
    if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == true && guardaSbt2E == false && guardaSbt3E == true && guardaSbt4E == false && guardaSbt5E == true) {
        Serial.print("*");
    }

    //Colchete 1
    if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == true && guardaSbt2E == false && guardaSbt3E == false && guardaSbt4E == true && guardaSbt5E == true) {
        Serial.print("(");
    }

    //Colchete 2
    if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == true && guardaSbt3E == true && guardaSbt4E == true && guardaSbt5E == false) {
        Serial.print(")");
    }
    
    //Travessão
    if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == true && guardaSbt3E == true && guardaSbt4E == false && guardaSbt5E == true) {
        Serial.print("-");
    }

    //Underline
    if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == true && guardaSbt3E == false && guardaSbt4E == true && guardaSbt5E == true) {
        Serial.print("_");
    }

    //Igual
    if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == false && guardaSbt3E == true && guardaSbt4E == true && guardaSbt5E == true) {
        Serial.print("=");
    }

    //Soma
    if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == true && guardaSbt2E == true && guardaSbt3E == true && guardaSbt4E == true && guardaSbt5E == false) {
        Serial.print("+");
    }

    //Barra
    if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == true && guardaSbt2E == false && guardaSbt3E == true && guardaSbt4E == true && guardaSbt5E == true) {
        Serial.print("/");
    }


  //Comando
  	//Caps  Lock
    if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == true && guardaSbt2E == true && guardaSbt3E == true && guardaSbt4E == false && guardaSbt5E == true) {
        capsLock = !capsLock;
    }

    //Shift
    if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == true && guardaSbt2E == true && guardaSbt3E == false && guardaSbt4E == true && guardaSbt5E == true) {
        shift = true;
    }
  	
    //Bacspace
    //if (guardaSbt1D == false && guardaSbt2D == false && guardaSbt3D == false && guardaSbt4D == false && guardaSbt5D == false && guardaSbt1E == false && guardaSbt2E == true && guardaSbt3E == true && guardaSbt4E == true && guardaSbt5E == true) {
        
    //}
}

void reseta() {
    guardaSbt1D = false;
    guardaSbt2D = false;
    guardaSbt3D = false;
    guardaSbt4D = false;
    guardaSbt5D = false;
    guardaSbt1E = false;
    guardaSbt2E = false;
    guardaSbt3E = false;
    guardaSbt4E = false;
    guardaSbt5E = false;
}