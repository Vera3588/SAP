byte Display[]={63,6,91,79,102,109,125,7, 127, 103};
int temp = 0;
int temp1 = 0;
byte exepcion[]={92,121};
void setup() {
  DDRA = 0B01111111;
  DDRC = 0B01111111;
  DDRL = 0B01111111;
  DDRK = 0B00000000;
  
}

void loop() {
  temp = PINK;
  int centena = temp/100;
  temp1 = temp%100;
  int decena = temp1/10;
  int unidades = temp1%10;

  PORTA = Display[centena];
  PORTC = Display[decena];
  PORTL = Display[unidades];

  if(PINK == 15){
    PORTC = exepcion[1];
    PORTL = exepcion[0];
    delay(1000);
  }

  
  
}
