#include <Servo.h>
int A = 89;
int B = 92;
int C = 88;
int D = 88;
int E, F, G, H, I, a, b, c, d, e, f, g, h, i;
int q=0;
int r=0;
int n=0;
int o=2;
char z;
int l;
char m;
int td;
int cd;
unsigned long t;
Servo sa, sb, sc, sd, se, sf, sg, sh, si,sj,sk,sl,sm,sn;
String S = "";
String X = "a";

void move()
{
  a = A;
  b = B;
  c = C;
  d = D;
  e = E;
  f = F;
  g = G;
  h = H;
  i = I;
  t=millis();
  a=constrain(a,0,180);
  b=constrain(b,0,180);
  c=constrain(c,0,180);
  d=constrain(d,0,180);
  Serial.println("^-^");
  if(q==1)
  {
  sa.write(a);
  sb.write(b);
  sc.write(c);
  sd.write(d);
  se.write(e);
  sf.write(f);
  sg.write(g);
  sh.write(h);
  si.write(i);
  Serial.print(X+a+"B"+b+"C"+c+"D"+d+"E"+e + "F" + f + "G" + g + "H" + h + "I" + i + "\n");
  }
  else
  {
  delay(5);
  }
q=0;
}
void setup() {
  Serial.begin(57600);
  pinMode(31,INPUT_PULLUP);
  pinMode(30,OUTPUT);
  pinMode(32,OUTPUT);
  pinMode(34,OUTPUT);
  pinMode(36,OUTPUT);
  digitalWrite(32,HIGH);
  digitalWrite(30,LOW);
  digitalWrite(34,LOW);
  digitalWrite(36,HIGH);
  pinMode(A8,OUTPUT);
  pinMode(A9,OUTPUT);
  pinMode(A10,OUTPUT);
  pinMode(A11,OUTPUT);
  pinMode(A12,OUTPUT);
  pinMode(A13,OUTPUT);
  pinMode(A14,OUTPUT);
}
void loop() {
  delayMicroseconds(50);
  if (Serial.available() > 0)
  {
    z = Serial.read();
    if (z == *"X")
    {
      m = 0;
    }
    else if (z == *"A") 
    {
      m = 1;
      l = 1;
      S = "";
    }
    else if (z == *"B")
    {
      m = 1;
      l = 2;
      S = "";
    }
    else if (z == *"C")
    {
      m = 1;
      l = 3;
      S = "";
    }
    else if (z == *"D")
    {
      m = 1;
      l = 4;
      S = "";
    }
    else if (z == *"E")
    {
      m = 1;
      l = 5;
      S = "";
    }
    else if (z == *"F")
    {
      m = 1;
      l = 6;
      S = "";
    }
    else if (z == *"G")
    {
      m = 1;
      l = 7;
      S = "";
    }
    else if (z == *"H")
    {
      m = 1;
      l = 8;
      S = "";
    }
    else if (z == *"I")
    {
      m = 1;
      l = 9;
      S = "";
    }
    else if (z == *"Z")
    {
      if(digitalRead(31)==LOW && o!=1)
  {
  sa.attach(14);
  sb.attach(15);
  sc.attach(16);
  sd.attach(17);
  se.attach(18);
  sf.attach(19);
  sg.attach(20);
  sh.attach(A8);
  si.attach(A10);
  //sj.attach(A10);
  //sk.attach(A11);
  //sl.attach(A12);
  //sm.attach(A13);
  //sn.attach(A14);
  
  o=1;
  digitalWrite(30,HIGH);
  digitalWrite(34,LOW);
  digitalWrite(36,LOW);
  }
  if(digitalRead(31)==HIGH && o!=0)
  {    
  sa.detach();
  sb.detach();
  sc.detach();
  sd.detach();
  se.detach();
  sf.detach();
  sg.detach();
  sh.detach();
  si.detach();
  o=0;
  digitalWrite(30,LOW);
  digitalWrite(34,HIGH);
  digitalWrite(36,LOW);
  }
      move();
      S = "";
      m = 3;
    }
    else if (z == *"Q")
    {
      q=1;
      m=3;
    }
    else if (z == *"^")
    {
      r=1;
      m=3;
    }
    else if (z == *"\n")
    {
      m = 4;
    }
    else
    {
      m = 2;
    }

    if (m == 2)
    {
      S = S + z;
    }
    if (m == 1)
    {
      S = "";
    }
    if (m == 0)
    {
      if (l == 1)
      {
        A = S.toInt();
      }
      else if (l == 2)
      {
        B = S.toInt();
      }
      else if (l == 3)
      {
        C = S.toInt();
      }
      else if (l == 4)
      {
        D = S.toInt();
      }
      else if (l == 5)
      {
        E = S.toInt();
      }
      else if (l == 6)
      {
        F = S.toInt();
      }
      else if (l == 7)
      {
        G = S.toInt();
      }
      else if (l == 8)
      {
        H = S.toInt();
      }
      else if (l == 9)
      {
        I = S.toInt();
      }
      S = "";
    }
  }
}
