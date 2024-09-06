const int bt1D = 8, bt2D = 7, bt3D = 6, bt4D = 5, bt5D = 4;
const int bt1E = 13, bt2E = 12, bt3E = 11, bt4E = 10, bt5E = 9;

int vetorVarDireita[5] = {bt1D, bt2D, bt3D, bt4D, bt5D};
int vetorVarEsquerda[5] = {bt1E, bt2E, bt3E, bt4E, bt5E};

int vetorRespDireita[5] = {13, 12, 11, 10, 9};

bool sbt1d = 0, sbt2D = 0, sbt3D = 0, sbt4D = 0, sbt5D = 0;
bool sbt1E = 0, sbt2E = 0, sbt3E = 0, sbt4E = 0, sbt5E = 0;

bool vetorDireita[5] = {sbt1d, sbt2D, sbt3D, sbt4D, sbt5D};
bool vetorEsquerda[5] = {sbt1E, sbt2E, sbt3E, sbt4E, sbt5E};


int guardaSbt1D = 0, guardaSbt2D = 0, guardaSbt3D = 0, guardaSbt4D = 0, guardaSbt5D = 0;
int guardaSbt1E = 0, guardaSbt2E = 0, guardaSbt3E = 0, guardaSbt4E = 0, guardaSbt5E = 0;

bool direita = 0;
bool tempoDeDigitacao = 0;
unsigned long previousMillis = 0;

bool backspace = false;
bool capslock = false;
bool shift = false;
bool ctrl = false;
bool esc = false;
bool tab = false;

void setup() {
  Serial.begin(115200);
  Serial.println("Teclas apertadas:");

  for(int i; i > 5; i++){
    pinMode(vetorVarDireita[i], INPUT);
    pinMode(vetorVarEsquerda[i], INPUT);
    pinMode(vetorRespDireita[i], OUTPUT);
  };
}

void loop() {
  verificaDireita ();
  verificaEsquerda ();

  if (tempoDeDigitacao) {
    unsigned long currentMillis = millis();
    unsigned long tempoEspera = 1000;

    while (millis() - currentMillis < tempoEspera)
    {
      previousMillis = currentMillis;

      direita == 1 ? verificaDireita () : verificaEsquerda();
    }

    int resultDireita = guardaSbt1D + guardaSbt2D + guardaSbt3D + guardaSbt4D + guardaSbt5D;
    int resultEsquerda = guardaSbt1E + guardaSbt2E + guardaSbt3E + guardaSbt4E + guardaSbt5E;

    char *escreveDireita[] = {"a", "b", "f", "c", "g", "j", "p", "d", "h", "k",
                              "q", "m", "s", "v", "z", "e", "i", "l", "r", "n",    
                              "t", "w", "ç", "o", "u", "x", "", "y", "", "",    
                              " "};

	  char *escreveEsquerda[] = {"1", "2", "6", "3", "7", ".", "\"", "4", "8", ",",
                              "@", ":", "%", ")", "+", "5", "9", ";", "#", "!",
                              "*", "-", "ESC", "?", "(", "_", "", "=", "/", "",    
                              "0"};

    char *maiusculas[] = {"A", "B", "F", "C", "G", "J", "P", "D", "H", "K",
                          "Q", "M", "S", "V", "Z", "E", "I", "L", "R", "N",    
                          "T", "W", "Ç", "O", "U", "X", "", "Y", "", "",    
                          " "};

    if(capslock == true || shift == true){
      direita == 1 ? Serial.write(maiusculas[(resultDireita - 1)]) : Serial.write(escreveEsquerda[(resultEsquerda - 1)]);
      shift = false;
    }else{
      direita == 1 ? Serial.write(escreveDireita[(resultDireita - 1)]) : Serial.write(escreveEsquerda[(resultEsquerda - 1)]);

      if(guardaSbt1D){digitalWrite(13, HIGH);}
      if(guardaSbt2D){digitalWrite(12, HIGH);}
      if(guardaSbt3D){digitalWrite(11, HIGH);}
      if(guardaSbt4D){digitalWrite(10, HIGH);}
      if(guardaSbt5D){digitalWrite(9, HIGH);}

      delay(300);
    }

    // 30 = BACKSCAPE, 29 = CAPSLOCK, 27 = SHIFT --> Direita
    // 30 = CTRL, 23 = ESC, 27 = TAB --> Esquerda
    switch(resultDireita){
      case 27:  // Shift
        shift = !shift;
      break;
    
      case 29:  // CapsLock 
        capslock = !capslock;
      break;

      /*case 30:  // Backspace
        backspace = !backspace;
      break;*/
    }
    
    switch(resultEsquerda){
      /*case 23:  // Esc
        esc = !esc;
      break;

      case 27:  // Tab
        tab = !tab;
      break;

      case 30:  // Ctrl
        ctrl = !ctrl;
      break;*/
    }

    direita = 0;
    tempoDeDigitacao = 0;
    reseta();
  }
}

void verificaDireita (){
  for (int d = 0; d < 5; d++) {
    vetorDireita[d] = digitalRead(vetorVarDireita[d]);
    if (vetorDireita[d] == HIGH) {
      switch(d){
        case 0: guardaSbt1D = 1;
          break;
        case 1: guardaSbt2D = 2;
         break;
        case 2: guardaSbt3D = 4;
         break;
        case 3: guardaSbt4D = 8;
          break;
        case 4: guardaSbt5D = 16;
          break;
      }

      tempoDeDigitacao = 1;
      direita = 1;
    }
  }
}

void verificaEsquerda () {
  for (int e = 0; e < 5; e++) {
    vetorEsquerda[e] = digitalRead(vetorVarEsquerda[e]);
    if (vetorEsquerda[e] == HIGH) {
      switch(e){
        case 0: guardaSbt1E = 1;
         break;
        case 1: guardaSbt2E = 2;
         break;
        case 2: guardaSbt3E = 4;
         break;
        case 3: guardaSbt4E = 8;
         break;
        case 4: guardaSbt5E = 16;
         break;
      }

      tempoDeDigitacao = 1;
    }
  }
}

void reseta() {
    guardaSbt1D = guardaSbt2D = guardaSbt3D = guardaSbt4D = guardaSbt5D = 0;
    guardaSbt1E = guardaSbt2E = guardaSbt3E = guardaSbt4E = guardaSbt5E = 0;

    for(int i = 13; i >= 9; i--){
      digitalWrite(i, LOW);
    };
}