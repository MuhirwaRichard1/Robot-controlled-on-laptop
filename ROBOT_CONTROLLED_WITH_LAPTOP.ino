char val;// variable to receive data from serial port
/*char val1
char val2
char val3
char val4*/

int en1=6;
int en2=11;

//motorA
int motA1 = 7;
int motA2 =8;

//motorB
int motB1= 9;
int motB2=10;
void setup() {
Serial.begin(9600);

pinMode(en1 , OUTPUT);
pinMode(en2 , OUTPUT);
pinMode(motA1 , OUTPUT);
pinMode(motA2 , OUTPUT);
pinMode(motB1 , OUTPUT);
pinMode(motB2 , OUTPUT);


}

void loop() {
  if (Serial.available()){ // if data to read is available
    val= Serial.read();  // read it and store it in 'val'
    }
 if (val == 'w') { // if 'w' was received motor go forward
  digitalWrite(motA1, HIGH);
  digitalWrite(motA2, LOW);
  analogWrite(en1, 255);
  digitalWrite(motB1, HIGH);
  digitalWrite(motB2, LOW);
  analogWrite(en2, 255);  
  }
  else if(val == 'z'){ // if 'z' was received robot go backward
  digitalWrite(motA1, LOW);
  digitalWrite(motA2, HIGH);
  analogWrite(en1, 255);
  digitalWrite(motB1, LOW);
  digitalWrite(motB2, HIGH);
  analogWrite(en2, 255);
  }

  else if(val == 'a'){ // if 'a' received robot go left

    digitalWrite(motA1, HIGH);
  digitalWrite(motA2, LOW);
  analogWrite(en1, 255);
  digitalWrite(motB1, HIGH);
  digitalWrite(motB2, LOW);
  analogWrite(en2, 60);
  }
  else if(val == 'd'){ // if 'd' received robot go right
  digitalWrite(motA1, HIGH);
  digitalWrite(motA2, LOW);
  analogWrite(en1, 70);
  digitalWrite(motB1,HIGH );
  digitalWrite(motB2, LOW);
  analogWrite(en2, 255);
  }
  
  else if(val == 's'){ // if 's' received robot stop
    digitalWrite(motA1, LOW);
  digitalWrite(motA2, LOW);
  analogWrite(en1, 0);
  digitalWrite(motB1, LOW);
  digitalWrite(motB2, LOW);
  analogWrite(en2, 0);
  }
  delay(100);
}
