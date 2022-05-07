// https://github.com/vallesmartin
// Constants
const int HOUR_SEC = 3600;      // Seconds in hour
const long HOUR_MILI = 3600000; // Ms in hour
const byte PIN_RELAY = 2;       // Board Pin number for relay
const byte PIN_STEPBUTTON = 3;  // Board Pin number for

// Variables
int HOUR_DAYLIGHT = 20;   // Hours of daylight
int HOUR_NIGHT = 4;       // Hours of darkness
int HOUR_STEP = 4;        // Minimun step of hours


int stepButtonValue;
int stepLightValue;


void setup() {
  pinMode(PIN_RELAY, OUTPUT);
  pinMode(PIN_STEPBUTTON, INPUT);
}

void loop() {
  ini();
  /********* Time turned on *********/
  activateRelay(PIN_RELAY);

  for(int i=0; i < HOUR_DAYLIGHT / HOUR_STEP; i++){
    stepLightValue += 1;
    customHoursDelay(HOUR_STEP);
  }
  /********* Time turned off *********/
  deactivateRelay(PIN_RELAY);
  for(int i=0; i < HOUR_NIGHT / HOUR_STEP; i++){
      customHoursDelay(HOUR_STEP);
  }
}

void ini(){
  stepButtonValue = 0;
  stepLightValue = 0;
  resolveLights();
}

void resolveLights(){
  
}

void activateRelay(byte r){
  digitalWrite(r, HIGH);
}

void deactivateRelay(byte r){
  digitalWrite(r, LOW);
}

void customHoursDelay(int hours){
  for(int i=0; i<hours*HOUR_SEC; i++){
    delay(1000);
    stepButtonValue = digitalRead(PIN_STEPBUTTON);
    if(stepButtonValue == HIGH){
      skipStep();
      break;
    }
  }
}

void skipStep(){
    
}
