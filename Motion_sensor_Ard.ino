/* Motion_sensor_Ard.ino
 * (Arduino sketch)
 * 
 * This program simulates a swipe gesture reader. It is configured to work only on swipes from right to left.
 * The second motion sensor (leftmost) will only activate once the first sensor reads activity. If the second sensor then reads activity a successful swipe gesture has been made
 * and a HIGH signal is sent to the ledPin and a message is sent through the serial port to the neighbooring Raspberry Pi.
 */

int calibrationTime = 30;
boolean lockPir1 = false;

int pirPin1 = 2;  //pin connected to output of PIR motion sensor #1
int pirPin2 = 4;  //pin connected to output of PIR motion sensor #2

int ledPin = 13;  //output led pin

void setup() {
  
  Serial.begin(9600);
  pinMode(pirPin1, INPUT);
  pinMode(pirPin2, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(pirPin1, LOW);
  digitalWrite(pirPin2, LOW);

  //calibration time
  Serial.print("calibrating sensor ");
  for(int i=0 ; i<calibrationTime ; i++){
    Serial.print(".");
    delay(1000);
  }
  Serial.println(" done");
  Serial.println("SENSOR ACTIVE");
  delay(50);
}


void loop() {
  
  if(digitalRead(pirPin1) == HIGH && lockPir1 == false){
    pinMode(pirPin2, INPUT);
    delay(400);
    if(digitalRead(pirPin2) == HIGH){
      digitalWrite(ledPin, HIGH);  //the led shows the sensors output state (motion)
      Serial.println("success");
      lockPir1 = true;
      delay(2200);
      pinMode(pirPin2, OUTPUT);
/*      
      if(lockLow){  //allow transition back to low before any further output
      lockLow = false;
      Serial.println("---");                //**For serial output if present
      Serial.print("flip detected at ");
      Serial.print(millis()/1000);
      Serial.println(" sec");
      delay(50);
      }
    takeLowTime = true;
*/
    } 
  }
/*  else if(digitalRead(pirPin2) == HIGH && lock == false){
    Serial.print(".");    //indicators
    delay(2700);
    Serial.print(".");
  }
*/
  if(lockPir1 == true && (digitalRead(pirPin1) == LOW || digitalRead(pirPin2) == LOW)){
    digitalWrite(ledPin, LOW);  //the led shows the sensor output state (no motion)
    lockPir1 = false;
    Serial.println("LED off");
  }
/*
     if(takeLowTime){
      lowIn = millis();   //save the time of the transition from high to low
      takeLowTime = false;  //only done at th start of the low phase
    }
    //if the sensor if low for more than the given pause, assume no more motion will happen
    if(!lockLow && millis() - lowIn > pause){
      //makes sure this block of code is only executed again after a new motion sequence
      lockLow = true;
      Serial.print("motion ended at ");
      Serial.print((millis() - pause)/1000);
      Serial.println(" sec");
      delay(50);
    }
*/
}
