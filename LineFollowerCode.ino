// Motor A
const int ENA = 11; // PWM pin for Motor A
const int IN1 = 10;  // IN1 pin for Motor A
const int IN2 = 9;  // IN2 pin for Motor A
#define s 100 //base speed
#define t 130//turning speed


// Motor B
const int ENB = 6; // PWM pin for Motor B
const int IN3 = 8;  // IN3 pin for Motor B
const int IN4 = 7;  // IN4 pin for Motor B

// IR Sensors
const int IRSensorLeft = 2;   // Left IR sensor
const int IRSensorRight = 3;  // Right IR sensor

void setup() {
  // Set motor pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Set sensor pins as inputs
  pinMode(IRSensorLeft, INPUT);
  pinMode(IRSensorRight, INPUT);

  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  bool leftSensor = digitalRead(IRSensorLeft);
  bool rightSensor = digitalRead(IRSensorRight);
  
  // Print sensor values
  Serial.print("Left Sensor: ");
  Serial.print(leftSensor);
  Serial.print(" | Right Sensor: ");
  Serial.println(rightSensor);

  // Forward movement
  if (leftSensor == LOW && rightSensor == LOW) {
    moveForward();
  }
  // Turn right
  else if (leftSensor == LOW && rightSensor == HIGH) {
    turnRight();
  }
  // Turn left
  else if (leftSensor == HIGH && rightSensor == LOW) {
    turnLeft();
  }
  // Stop
  else {
    stopMotors();
  }

  delay(100); // Add a short delay to make the print readable
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, s); // Adjust speed here

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, s); // Adjust speed here
}

void turnRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, t); // Adjust speed here

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, t); // Adjust speed here
}

void turnLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, t); // Adjust speed here

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, t); // Adjust speed here
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0); // Stop motor

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0); // Stop motor
}
