#include <math.h>
static const uint8_t n[] = {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15};
static const uint8_t FF=5;
static const uint8_t FM=3;
static const uint8_t FB=A4;
static const uint8_t IF=4;
static const uint8_t IM=A0;
static const uint8_t IB=A3;
static const uint8_t GT=A1;
static const uint8_t GM=A5;
static const uint8_t GB=A8;
static const uint8_t HT=6;
static const uint8_t HM=2;
static const uint8_t HB=A2;
static const uint8_t TLB=7;
static const uint8_t TLJ=A11;
static const uint8_t LX=A14;
static const uint8_t LY=A15;
static const uint8_t TRB=A9;
static const uint8_t TRJ=A10;
static const uint8_t RX=A12;
static const uint8_t RY=A13;
int A,B,C,D,E,F,G,H,I,a,b,c,d,e,f,g,h,i,q;
int m=0;
int k=15;
int w=2;
unsigned long lir;
unsigned long lhr;
unsigned long lsr;
unsigned long lpr;
unsigned long lfr;
double hd;
double hr;
int s;
int t;                                                    
String X="A";
void send()
{
  Serial.print(X+a+"X"+"B"+b+"X"+"C"+c+"X"+"D"+d+"X"+"E"+e+"X"+"F"+f+"X"+"G"+g+"X"+"H"+h+"X"+"I"+i+"XQZ\n");
  if(w!=1)
  {
    digitalWrite(32,HIGH);
    digitalWrite(34,HIGH);
    digitalWrite(36,LOW);
    digitalWrite(38,LOW);
    w=1;
  }
}
void sendx()
{
  Serial.print("Z\n");
  if(w!=0)
  {
    digitalWrite(32,LOW);
    digitalWrite(34,HIGH);
    digitalWrite(36,HIGH);
    digitalWrite(38,LOW);
    w=0;
  }
}
void setup() {
Serial.begin(57600);
for(int r=0;r<=11;r++)
{
  pinMode(n[r],INPUT_PULLUP);
}
for(int r=2;r<=7;r++)
{
  pinMode(r,INPUT_PULLUP);
}
E=511;
F=511;
G=250;
H=511;
I=511;
pinMode(32,OUTPUT);
pinMode(34,OUTPUT);
pinMode(36,OUTPUT);
pinMode(38,OUTPUT);
digitalWrite(34,HIGH);
digitalWrite(32,LOW);
digitalWrite(36,LOW);
digitalWrite(38,LOW);
pinMode(9,OUTPUT);
digitalWrite(9,LOW);
pinMode(8,INPUT_PULLUP);
}
void loop() {
  A=analogRead(LY);
  delay(m);
  A=analogRead(LY)-512;
  B=analogRead(LX);
  delay(m);
  B=analogRead(LX)-531;
  C=analogRead(RY);
  delay(m);
  C=analogRead(RY)-508;
  D=analogRead(RX);
  delay(m);
  D=-analogRead(RX)+508;
  if(A<50 & A>-50) A=0;
  if(B<50 & B>-50) B=0;
  if(C<50 & C>-50) C=0;
  if(D<50 & D>-50) D=0;
  hd=-4068*atan2(C,D)/71;
  hd+=720;
  hd=int(hd)%360;
  hr=71*hd/4068;
  s=sqrt(pow(C,2)+pow(D,2));
  a=s*(-sin(hr)-cos(hr))+B;
  b=s*(-sin(hr)+cos(hr))+B;
  c=s*(sin(hr)+cos(hr))+B;
  d=s*(sin(hr)-cos(hr))+B;
  a=map(a,-512,511,80,100);
  b=map(b,-512,511,80,100);
  c=map(c,-512,511,80,100);
  d=map(d,-512,511,80,100);
  E-=A/50;
  if(lsr<millis()-700) F-=15*(digitalRead(FF)-digitalRead(FB));
  if(lsr<millis()-700) if(lfr<millis()-700) G+=25*(digitalRead(GT)-digitalRead(GB));
  if(lhr<millis()-700) if(lpr<millis()-700) H+=40*(digitalRead(HT)-digitalRead(HB));
  if(lir<millis()-700) if(lpr<millis()-700) I+=15*(digitalRead(IF)-digitalRead(IB));
  if (lpr<millis()-700) if(digitalRead(IF)+digitalRead(IB)==0)
  {
     I=511;
     lir=millis();
  }
  if (lpr<millis()-700) if(digitalRead(HT)+digitalRead(HB)==0)//DOUBLE H
  {
     E=540;
     F=878;
     G=498;
     H=348;
     I=601;
     lhr=millis();
  }
  if(digitalRead(FB)+digitalRead(GT)+digitalRead(GB)==0)//F BACK + DOUBLE G
  {
     E=596;
     F=207;
     G=867;
     H=0;
     I=511;
     lsr=millis();
  }
  if(digitalRead(HT)+digitalRead(HB)+digitalRead(IF)+digitalRead(IB)==0)//FULL RIGHT SIDE
  {
     E=511;
     F=359;
     G=573;
     H=1023;
     I=491;
     lpr=millis();
  }
  if(lsr<millis()-700) if(digitalRead(GT)+digitalRead(GB)==0)//BUCKET FLIP
  {
     E=map(88,17,163,0,1023);
     F=map(88,23,157,0,1023);
     G=map(55,15,165,0,1023);
     H=map(108,15,165,0,1023);
     I=map(91,15,165,0,1023);
     lfr=millis();
  }
  E=constrain(E,0,1023);
  F=constrain(F,0,1023);
  G=constrain(G,0,1023);
  H=constrain(H,0,1023);
  I=constrain(I,0,1023);
  e=map(E,0,1023,17,163);
  f=map(F,0,1023,23,158);
  g=map(G,0,1023,15,165);
  h=map(H,0,1023,15,165);
  i=map(I,0,1023,15,165);
  if(digitalRead(8)==0) send();
  if(digitalRead(8)==1) sendx();
  delay(20);
}

