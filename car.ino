char t;
int motor1 = 2;
int motor2 = 3;
int motor3 = 6;
int motor4 = 5;
void setup() {
  pinMode(motor1, OUTPUT);  //left motors forward
  pinMode(motor2, OUTPUT);  //left motors backward
  pinMode(motor3, OUTPUT);  //right motors forward
  pinMode(motor4, OUTPUT);  //right motors backward
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);
  }
  if (t == 'F') {  //move forward
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }

  else if (t == 'B') {  //move backward
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }

  else if (t == 'L') {  //turn right
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  }

  else if (t == 'R') {  //turn left
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  }
  else if (t == 'S') {  //STOP
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
}
