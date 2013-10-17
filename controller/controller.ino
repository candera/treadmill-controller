/*
  Treadmill controller
 */

// Pin 13 is connected to an LED on the Leonardo
int led = 13;
int bStop = 4;
int bFaster = 6;
int bSlower = 8;
int targetSpeed = 0;   // How fast we're trying to go
int actualSpeed = 0;   // How fast we're going right now
boolean bFasterDown = false;
boolean bSlowerDown = false;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(bStop, INPUT_PULLUP);
  pinMode(bFaster, INPUT_PULLUP);
  pinMode(bSlower, INPUT_PULLUP);
}

// the loop routine runs over and over again forever:
void loop() {
  if (digitalRead(bStop) == LOW) {
    targetSpeed = 0;
  } 

  if (!bFasterDown && (digitalRead(bFaster) == LOW)) {
    targetSpeed += 1;
    bFasterDown = true;
  }
  else {
    bFasterDown = false;
  }

  if (!bSlowerDown && (digitalRead(bSlower) == LOW)) {
    targetSpeed -= 1;
    bSlowerDown = true;
  }
  else {
    bSlowerDown = false;
  }

  if (actualSpeed != targetSpeed) {
    int delta = targetSpeed - actualSpeed;
    int limited = constrain(delta, -1, 1);
    actualSpeed += limited;
    analogWrite(led, actualSpeed);
  }
  
  delay(100);
}
