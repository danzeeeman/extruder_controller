// Define stepper motor connections and steps per revolution:
#define stepPin 2
#define dirPin 3
//#define stepsPerRevolution 20000
int stepSpeed = 50;
int incomingByte = 0;

bool motorON;
void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.begin(9600);
  digitalWrite(dirPin, LOW);
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);
//  read serial
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    // Set the spinning direction OUT:
    if(incomingByte == 'c'){
      digitalWrite(dirPin, HIGH);
    }else if(incomingByte == 'w'){
      // Set the spinning direction IN:
       digitalWrite(dirPin, LOW);
    }else if(incomingByte == 'o'){
       // Turn the Motor On
      motorON = true;
    }else if(incomingByte == 'f'){
        // Turn the Motor Off
      motorON = false;
    }else if(incomingByte == '0'){
      stepSpeed = 7;
    }else if(incomingByte == '1'){
      stepSpeed = 15;
    }else if(incomingByte == '2'){
      stepSpeed = 30;
    }else if(incomingByte == '3'){
      stepSpeed = 60;
    }else if(incomingByte == '4'){
      stepSpeed = 120;
    }else if(incomingByte == '5'){
      stepSpeed = 240;
    }else if(incomingByte == '6'){
      stepSpeed = 480;
    }else if(incomingByte == '7'){
      stepSpeed = 960;
    }else if(incomingByte == '8'){
      stepSpeed = 1000;
    }else if(incomingByte == '9'){
      stepSpeed = 2000;
    }
  }
  if(motorON == true){
      //Step Motors
      digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(stepSpeed);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(stepSpeed);
   }
}
