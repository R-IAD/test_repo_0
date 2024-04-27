/*****************************************************************************************************/

 /*
  Gearmotor Rotary Encoder Test
  motor-encoder-rpm.ino
  Read pulses from motor encoder to calculate speed
  Control speed with potentiometer
  Displays results on Serial Monitor
  Use Cytron MD10C PWM motor controller
  DroneBot Workshop 2019
  https://dronebotworkshop.com
*/

// Motor encoder output pulse per rotation (change as required)
#define ENC_COUNT_REV 374
 
// Encoder output to Arduino Interrupt pin
#define rENC_IN 2 
#define lENC_IN 3 
void updateEncoder1();
void updateEncoder2();
 
// MD10C PWM connected to pin 10
#define rRPWM 5
#define rLPWM 6
#define lRPWM 9
#define lLPWM 10
// MD10C DIR connected to pin 12
//#define DIR 12 
 
// Analog pin for potentiometer
int speedcontrol = 0;
 
// Pulse count from encoder
volatile long encoder1Value = 0;
volatile long encoder2Value = 0;
 
// One-second interval for measurements
int interval = 1000;
 
// Counters for milliseconds during interval
long previousMillis1 = 0;
long currentMillis1 = 0;
long previousMillis2 = 0;
long currentMillis2 = 0; 
// Variable for RPM measuerment
int Rrpm = 0;
int Lrpm = 0;

// Variable for PWM motor speed output
int RmotorPwm = 0;
int LmotorPwm = 0;

void setup()
{
  // Setup Serial Monitor
  Serial.begin(9600); 
  
  // Set encoder as input with internal pullup  
  pinMode(rENC_IN, INPUT_PULLUP); 
  pinMode(lENC_IN, INPUT_PULLUP); 

  // Set PWM and DIR connections as outputs
  pinMode(rRPWM, OUTPUT);
  pinMode(rLPWM, OUTPUT);
  pinMode(lRPWM, OUTPUT);
  pinMode(lLPWM, OUTPUT);

  
  // Attach interrupt for D3
  attachInterrupt(digitalPinToInterrupt(rENC_IN),updateEncoder1, RISING);
  
  // Setup initial values for timer
  previousMillis1 = millis();


    // Attach interrupt for D2
  attachInterrupt(digitalPinToInterrupt(lENC_IN),updateEncoder2, RISING);  
  // Setup initial values for timer
  previousMillis2 = millis();
}




 
void loop()
{
  
    // Control motor with potentiometer
    RmotorPwm = map(analogRead(speedcontrol), 0, 1023, 0, 255);
    LmotorPwm = map(analogRead(speedcontrol), 0, 1023, 0, 255); 

       
    // Write PWM to controller
    analogWrite(rRPWM, 255);
    analogWrite(rLPWM, 0);
    analogWrite(lRPWM, 255);
    analogWrite(lLPWM, 0);
 
  // Update Right RPM value every second
  currentMillis1 = millis();
  if (currentMillis1 - previousMillis1 > interval) {
    previousMillis1 = currentMillis1;
 
 
    // Calculate RPM
    Rrpm = (float)(encoder1Value * 60 / ENC_COUNT_REV);
 
    // Only update display when there is a reading
    if (RmotorPwm > 0 || Rrpm > 0) {
      Serial.print("Right PWM VALUE: ");
      Serial.print(RmotorPwm);
      Serial.print('\t');
      Serial.print(" Right PULSES: ");
      Serial.print(encoder1Value);
      Serial.print('\t');
      Serial.print(" Right SPEED: ");
      Serial.print(Rrpm);
      Serial.println(" Right RPM");
    }
    
    encoder1Value = 0;
  }


  // Update Left RPM value every second
  currentMillis2 = millis();
  if (currentMillis2 - previousMillis2 > interval) {
    previousMillis2 = currentMillis2;
 
 
    // Calculate RPM
    Lrpm = (float)(encoder2Value * 60 / ENC_COUNT_REV);
 
    // Only update display when there is a reading
    if (LmotorPwm > 0 || Lrpm > 0) {
      Serial.print("Left PWM VALUE: ");
      Serial.print(LmotorPwm);
      Serial.print('\t');
      Serial.print(" Left PULSES: ");
      Serial.print(encoder2Value);
      Serial.print('\t');
      Serial.print(" Left SPEED: ");
      Serial.print(Lrpm);
      Serial.println(" Left RPM");
    }
    
    encoder2Value = 0;
  }
}
 
void updateEncoder1()
{
  // Increment value for each pulse from encoder
  encoder1Value++;
}
void updateEncoder2()
{
  // Increment value for each pulse from encoder
  encoder2Value++;
}
