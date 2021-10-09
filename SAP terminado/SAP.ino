byte Display[] ={68};
int LDA = 22;
int ADD = 23;
int SUB = 24;
int MULT = 25;
int DIV = 26;
int POTENCIA = 27;
int PAR = 28;
int LUCAS = 29;
int CALL = 30;
int MOD = 31;
int INC = 32;
int DECSZ = 33;
int OUT = 34;
int HLT = 35;
int RETURN = 36;
int GOTO = 37;

int LI = 40;
int LM = 41;
int EI = 42;
int LA = 43;
int EA = 44;
int LB = 45;
int EU = 46;
int SUMAA = 47;
int RESTAA = 48;
int MULTA = 49;
int DIVIA = 50;
int LO = 51;
int ER = 52;
int EP = 53;

int p=0;
byte pc;
byte temp;


void setup() {
  DDRK = 0B11111111;
  DDRF = 0B00000000;
  pc = 0;
  pinMode(LDA, INPUT);
  pinMode(ADD, INPUT);
  pinMode(SUB, INPUT);
  pinMode(MULT, INPUT);
  pinMode(DIV, INPUT);
  pinMode(POTENCIA, INPUT);
  pinMode(PAR, INPUT);
  pinMode(LUCAS, INPUT);
  pinMode(CALL, INPUT);
  pinMode(MOD, INPUT);
  pinMode(INC, INPUT);
  pinMode(DECSZ, INPUT);
  pinMode(OUT, INPUT);
  pinMode(HLT, INPUT);
  pinMode(RETURN, INPUT);
  pinMode(GOTO, INPUT);
  
  pinMode(LI, OUTPUT);
  pinMode(LM, OUTPUT);
  pinMode(EI, OUTPUT);
  pinMode(LA, OUTPUT);
  pinMode(EA, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(EU, OUTPUT);
  pinMode(SUMAA, OUTPUT);
  pinMode(RESTAA, OUTPUT);
  pinMode(MULTA, OUTPUT);
  pinMode(DIVIA, OUTPUT);
  pinMode(LO, OUTPUT);
  pinMode(ER, OUTPUT);
  pinMode(EP, OUTPUT);  
  
  Serial.begin(9600);
}

void loop() {
  PORTK = pc;

  digitalWrite(EP,1);
  digitalWrite(LM,1);
  delay(1000);
  
  digitalWrite(LM,0);
  digitalWrite(EP,0);

  digitalWrite(ER,1);
  digitalWrite(LI,1);
  delay(1000);
   
  
  digitalWrite(LI,0);
  digitalWrite(ER,0);
 
  
  if(digitalRead(LDA)== 1){
    digitalWrite(EI,1);
    digitalWrite(LM,1);
    delay(1000);

    digitalWrite(LM,0);
    digitalWrite(EI,0);
    
    digitalWrite(ER,1);
    digitalWrite(LA,1);
    delay(1000);
    
    digitalWrite(LA,0);
    digitalWrite(ER,0);
    pc++;
  }
  
  if(digitalRead(ADD)== 1){
    
    digitalWrite(EI,1);
    digitalWrite(LM,1);
    delay(1000);

    digitalWrite(LM,0);
    digitalWrite(EI,0);
    
    digitalWrite(ER,1);
    digitalWrite(LB,1);
    delay(1000);
    
    digitalWrite(LB,0);
    digitalWrite(ER,0);

    digitalWrite(SUMAA,1);
    digitalWrite(EU,1);
    digitalWrite(LA,1);
    delay(1000);
   
    digitalWrite(LA,0);
    digitalWrite(EU,0);
    digitalWrite(SUMAA,0);
    
    pc++;
    
    }
  if(digitalRead(SUB)==1){
    
    digitalWrite(EI,1);
    digitalWrite(LM,1);
    delay(1000);

    digitalWrite(LM,0);
    digitalWrite(EI,0);
    
    digitalWrite(ER,1);
    digitalWrite(LB,1);
    delay(1000);
    
    digitalWrite(LB,0);
    digitalWrite(ER,0);

    digitalWrite(RESTAA,1);
    digitalWrite(EU,1);
    digitalWrite(LA,1);
    delay(1000);
   
    digitalWrite(LA,0);
    digitalWrite(EU,0);
    digitalWrite(RESTAA,0);
    
    pc++;
    }
  if(digitalRead(MULT)==1){
    digitalWrite(EI,1);
    digitalWrite(LM,1);
    delay(1000);

    digitalWrite(LM,0);
    digitalWrite(EI,0);
    
    digitalWrite(ER,1);
    digitalWrite(LB,1);
    delay(1000);
    
    digitalWrite(LB,0);
    digitalWrite(ER,0);

    digitalWrite(MULTA,1);
    digitalWrite(EU,1);
    digitalWrite(LA,1);
    delay(1000);
   
    digitalWrite(LA,0);
    digitalWrite(EU,0);
    digitalWrite(MULTA,0);
    
    pc++;
    
    }
  if(digitalRead(DIV)==1){
    digitalWrite(EI,1);
    digitalWrite(LM,1);
    delay(1000);

    digitalWrite(LM,0);
    digitalWrite(EI,0);
    
    digitalWrite(ER,1);
    digitalWrite(LB,1);
    int var = PINF;
    delay(1000);
    digitalWrite(LB,0);
    digitalWrite(ER,0);
    if(var == 0){
      PORTK = 15;
      digitalWrite(EP,1);
      digitalWrite(LA,1);
      delay(1000);
      digitalWrite(LA,0);
      digitalWrite(EP,0);
    }
    else if(var != 0){
    digitalWrite(DIVIA,1);
    digitalWrite(EU,1);
    digitalWrite(LA,1);
    delay(1000);
   
    digitalWrite(LA,0);
    digitalWrite(EU,0);
    digitalWrite(DIVIA,0);
    }
    
    pc++;
    }
  if(digitalRead(POTENCIA)==1){
      digitalWrite(EI,1);
      digitalWrite(LM,1);
      delay(1000);
      digitalWrite(EI,0);
      digitalWrite(LM,0);
      
      
      int y = 0;
      digitalWrite(ER,1);
      y = PINF;
      delay(1000);
      digitalWrite(ER,0);
    
      digitalWrite(EA,1);
      digitalWrite(LB,1);
      
      delay(1000);

      digitalWrite(EA,0);
      digitalWrite(LB,0);
      
      for(int i = 0; i < y; i++){
          digitalWrite(MULTA,1);
          digitalWrite(EU,1);
          digitalWrite(LA,1);
          delay(1000);
         
          digitalWrite(LA,0);
          digitalWrite(EU,0);
          digitalWrite(MULTA,0);
      }
      pc++;
    }
  if(digitalRead(PAR)==1){
      int algo = 2;
      PORTK = algo;
      digitalWrite(EP,1);
      digitalWrite(LB,1);
      
      delay(1000);
      digitalWrite(LB,0);
      digitalWrite(EP,0);
      
      digitalWrite(EA,1);
      modulo();
      
      delay(1000);
      digitalWrite(EA,0);
      if(p == 0){
         PORTK = 1;
         digitalWrite(EP,1);
         digitalWrite(LA,1);
         
         delay(1000);
         digitalWrite(LA,0);
         digitalWrite(EP,0);
        }
       else{
         PORTK = 0;
         digitalWrite(EP,1);
         digitalWrite(LA,1);
         
         delay(1000);
         digitalWrite(LA,0);
         digitalWrite(EP,0);
        }
        pc++;
      }
  if(digitalRead(LUCAS)== 1){
    int n1 = 2;
    int n2 = 1;
    int n3 = 0;
    int cont = 0;
    
    digitalWrite(EA,1);
    cont = PINF;
    delay(1000);
    digitalWrite(EA,0);
    if(cont == 1){
      PORTK = n1;
      digitalWrite(EP,1);
      digitalWrite(LA,1);
      delay(1000);
      digitalWrite(LA,0);
      digitalWrite(EP,0);
    }
    else if(cont == 2){
      PORTK = n2;
      digitalWrite(EP,1);
      digitalWrite(LA,1);
      delay(1000);
      digitalWrite(LA,0);
      digitalWrite(EP,0);
    }
    else if(cont > 2){
      for(int i = 2; i < cont;++i) {
        PORTK = n1;
        digitalWrite(EP,1);
        digitalWrite(LA,1);
        delay(1000);
        digitalWrite(LA,0);
        digitalWrite(EP,0);
        
        PORTK = n2;
        digitalWrite(EP,1);
        digitalWrite(LB,1);
        delay(1000);
        digitalWrite(LB,0);
        digitalWrite(EP,0);

        digitalWrite(SUMAA,1);
        digitalWrite(EU,1);
        digitalWrite(LA,1);
        delay(1000);
       
        digitalWrite(LA,0);
        digitalWrite(EU,0);
        digitalWrite(SUMAA,0);

        digitalWrite(EA,1);
        n3 = PINF;
        delay(1000);
        digitalWrite(EA,0);  
        n1 = n2;  
        n2 = n3;  
      } 
        PORTK = n3;
        digitalWrite(EP,1);
        digitalWrite(LA,1);
        delay(1000);
        digitalWrite(LA,0);
        digitalWrite(EP,0);
      }
      pc++;
    }
    
  if(digitalRead(CALL)== 1 ){
      temp = pc+1;
      digitalWrite(EI,1);
      pc = PINF;
      delay(1000);
      digitalWrite(EI,0);
      
    }
  if(digitalRead(MOD)==1){
    
    digitalWrite(EA,1);
    int primero = PINF;
    delay(1000);
    digitalWrite(EA,0);
    
    digitalWrite(EI,1);
    digitalWrite(LM,1);
    delay(1000);

    digitalWrite(LM,0);
    digitalWrite(EI,0);
    
    digitalWrite(ER,1);
    digitalWrite(LB,1);
    delay(1000);
    
    digitalWrite(LB,0);
    digitalWrite(ER,0);

    digitalWrite(DIVIA,1);
    digitalWrite(EU,1);
    digitalWrite(LA,1);
    delay(1000);
   
    digitalWrite(LA,0);
    digitalWrite(EU,0);
    digitalWrite(DIVIA,0);

    digitalWrite(MULTA,1);
    digitalWrite(EU,1);
    digitalWrite(LA,1);
    delay(1000);
   
    digitalWrite(LA,0);
    digitalWrite(EU,0);
    digitalWrite(MULTA,0);

    digitalWrite(EA,1);
    digitalWrite(LB,1);
    delay(1000);
    digitalWrite(LB,0);
    digitalWrite(EA,0);
    
    PORTK = primero;
    digitalWrite(EP,1);
    digitalWrite(LA,1);
    
    delay(1000);
    digitalWrite(LA,0);
    digitalWrite(EP,0);

    digitalWrite(RESTAA,1);
    digitalWrite(EU,1);
    digitalWrite(LA,1);
    delay(1000);
   
    digitalWrite(LA,0);
    digitalWrite(EU,0);
    digitalWrite(RESTAA,0);
     
    pc++;
    
    }
  if(digitalRead(INC)==1){
    int aux = 1;
    PORTK = aux;
    digitalWrite(EP,1);
    digitalWrite(LB,1);
    delay(1000);

    digitalWrite(LB,0);
    digitalWrite(EP,0);
    
    digitalWrite(SUMAA,1);
    digitalWrite(EU,1);
    digitalWrite(LA,1);
    delay(1000);
   
    digitalWrite(LA,0);
    digitalWrite(EU,0);
    digitalWrite(SUMAA,0);
    pc++;
    }
    
  if(digitalRead(DECSZ)==1){
      int aux = 1;
      PORTK = aux;
      digitalWrite(EP,1);
      digitalWrite(LB,1);
      delay(1000);
      
      digitalWrite(LB,0);
      digitalWrite(EP,0);
      
      digitalWrite(RESTAA,1);
      digitalWrite(EU,1);
      digitalWrite(LA,1);
      delay(1000);
     
      digitalWrite(LA,0);
      digitalWrite(EU,0);
      digitalWrite(RESTAA,0);
      pc++;
    }
  if(digitalRead(OUT)==1){
      digitalWrite(EA,1);
      digitalWrite(LO,1);
      delay(1000);
  
      digitalWrite(LO,0);
      digitalWrite(EA,0);
    }
  if(digitalRead(HLT)==1){
       
      while(1){
      }
    
    
  }
  if(digitalRead(RETURN)==1){
      pc = temp;
    }
  if(digitalRead(GOTO)==1){
     
      digitalWrite(EI,1);
      pc = PINF;
      delay(1000);
      digitalWrite(EI,0);

      digitalWrite(ER, 1);
      temp = pc;
      delay(1000);
      pc = PINF;
      delay(1000);
      digitalWrite(ER, 0);
    }
   
}

void modulo(){
    digitalWrite(EA,1);
    int primero = PINF;
    delay(1000);
    digitalWrite(EA,0);

    digitalWrite(DIVIA,1);
    digitalWrite(EU,1);
    digitalWrite(LA,1);
    delay(1000);
   
    digitalWrite(LA,0);
    digitalWrite(EU,0);
    digitalWrite(DIVIA,0);

    digitalWrite(MULTA,1);
    digitalWrite(EU,1);
    digitalWrite(LA,1);
    delay(1000);
   
    digitalWrite(LA,0);
    digitalWrite(EU,0);
    digitalWrite(MULTA,0);

    digitalWrite(EA,1);
    digitalWrite(LB,1);
    delay(1000);
    digitalWrite(LB,0);
    digitalWrite(EA,0);
    
    PORTK = primero;
    digitalWrite(EP,1);
    digitalWrite(LA,1);
    
    delay(1000);
    digitalWrite(LA,0);
    digitalWrite(EP,0);

    digitalWrite(RESTAA,1);
    digitalWrite(EU,1);
    digitalWrite(LA,1);
    p = PINF;
    delay(1000);
   
    digitalWrite(LA,0);
    digitalWrite(EU,0);
    digitalWrite(RESTAA,0);
  }
