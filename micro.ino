int D1andU1 = 0;

int D2andU2 = 0;

int D3andU3 = 0;

int PushButton_floor1 = 0;

int PushPutton_floor2 = 0;

int PushButton_floor3 = 0;

int LimitSensor_floor1 = 0;

int LimitSensor_floor2 = 0;

int LimitSensor_floor3 = 0;

int LedFloor1 = 0;

int LedFloor2 = 0;

int LedFloor3 = 0;

void setup()
{
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(6, INPUT);
  pinMode(11, INPUT);
  pinMode(3, INPUT);
  pinMode(7, INPUT);
  pinMode(13, INPUT);
  pinMode(5, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(12, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10,INPUT);
}

void loop()
{
  D1andU1 = digitalRead(8);
  D2andU2 = digitalRead(9);
  D3andU3 = digitalRead(10);
  PushButton_floor1 = digitalRead(6);
  PushPutton_floor2 = digitalRead(11);
  PushButton_floor3 = digitalRead(3);
  LimitSensor_floor1 = digitalRead(7);
  LimitSensor_floor2 = digitalRead(13);
  LimitSensor_floor3 = digitalRead(5);
  LedFloor1 = digitalRead(A0);
  LedFloor2 = digitalRead(A1);
  LedFloor3 = digitalRead(A2);

  //if the user push up or down from first floor
  if (D1andU1 == HIGH) {
    LedsSystem();
    if (LimitSensor_floor1 == HIGH) {
      digitalWrite(12, LOW);
    }
  }
   //if the user push up or down from second floor
  else if (D2andU2 == HIGH) {
    LedsSystem();
    if (LimitSensor_floor2 == HIGH) {
      digitalWrite(12, LOW);
    }
  }
   //if the user push up or down from third floor
  else if (D3andU3 == HIGH) {
    LedsSystem();
    if (LimitSensor_floor3 == HIGH) {
      digitalWrite(12, LOW);
    }
  }
  digitalWrite(12, HIGH);

    //if the user push the first floor button
   //the elevator always go down because it is the first door
  if (PushButton_floor1 == HIGH) {
    LedsSystem();
    if (LimitSensor_floor1 == HIGH) {
      digitalWrite(12, LOW);
    }
  }
    //if the user push the third floor button
   //the elevator always go up because it is the last door
  else if (PushButton_floor3 == HIGH) {
    LedsSystem();
    if (LimitSensor_floor3 == HIGH) {
      digitalWrite(12, LOW);
    }
  }
    //if the user push the second floor button
  else if (PushPutton_floor2 == HIGH) {
    //when the user in third flooe the elevator goes down
    if (LimitSensor_floor3 == HIGH)
    {
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
    LedsSystem();
    if (LimitSensor_floor2 == HIGH) {
      digitalWrite(12, LOW);
    }
  }
  //whrn the user in first floor the elevator goes up
  else {
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);
    LedsSystem();
    if (LimitSensor_floor2 == HIGH) {
      digitalWrite(12, LOW);
    }
  }
  }
  digitalWrite(12, HIGH);
}

//function to make one of leds ON in specific floor to know the current floor 
void LedsSystem()
{
  if (LimitSensor_floor1 == HIGH) {
    digitalWrite(A0, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(A0, LOW);
  }
  if (LimitSensor_floor2 == HIGH) {
    digitalWrite(A1, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(A1, LOW);
  }
  if (LimitSensor_floor3 == HIGH) {
    digitalWrite(A2, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(A2, LOW);
  }
}
