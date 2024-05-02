const int trigPin1 = 6; // Front
const int echoPin1 = 7;
const int trigPin2 = 8; // Left
const int echoPin2 = 9;
const int trigPin3 = 12; // Right
const int echoPin3 = 13;
const int in1 = 2;
const int in2 = 3;
const int in3 = 5;
const int in4 = 4;
const int speedPin1 = 10; // PWM pin for motor speed control 1
const int speedPin2 = 11; // PWM pin for motor speed control 2
int A=110;
long long DIS = 6;
long long DISf = 25;

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(speedPin1, OUTPUT); // Set PWM pins as output
  pinMode(speedPin2, OUTPUT);

  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  long frontDist = measureDistance(trigPin1, echoPin1);
  long rightDist = measureDistance(trigPin2, echoPin2);
  long leftDist = measureDistance(trigPin3, echoPin3);

  Serial.print("Front distance: ");
  Serial.println(frontDist);
  Serial.print("Right distance: ");
  Serial.println(rightDist);
  Serial.print("Left distance: ");
  Serial.println(leftDist);

  forward();
  
  if (frontDist <= DISf || rightDist <= DIS || leftDist <= DIS) {
    reverse();
    if(frontDist <= DISf) {
      reverse();
    if (leftDist <= rightDist) {
      turn_right();
      delay(700);
    } 
    else if (rightDist <= leftDist) {
      turn_left();
      delay(700);
    }
    }
    else if (leftDist <= rightDist) {
      turn_right();
    } 
    else if (rightDist <= leftDist) {
      turn_left();
    }
  }
}

void forward() {
  analogWrite(speedPin1, A); // adjust speed as needed
  analogWrite(speedPin2, A); // adjust speed as needed
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turn_left() {
  analogWrite(speedPin1, A); // adjust speed as needed
  analogWrite(speedPin2, A); // adjust speed as needed
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}                                                                           

void turn_right() {
  analogWrite(speedPin1, A); // adjust speed as needed
  analogWrite(speedPin2, A); // adjust speed as needed
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void reverse() {
  analogWrite(speedPin1, A); // adjust speed as needed
  analogWrite(speedPin2, A); // adjust speed as needed
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

long measureDistance(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW);
  // delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  // delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;
  return distance;
}
