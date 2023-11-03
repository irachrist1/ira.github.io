//turn on and off LED  


int ledPins[] = {2, 3, 4, 5, 6};

void setup() {
  
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPins[i], HIGH); 
    delay(500); 
    digitalWrite(ledPins[i], LOW); 
    delay(500); 
  }
}








//Q2 two push

const int button1Pin = 2;
const int button2Pin = 3;
const int ledPin = 13;


int delayTime = 1000;  
int button1State = HIGH;
int button2State = HIGH;
int lastButton1State = HIGH;
int lastButton2State = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  
  int reading1 = digitalRead(button1Pin);
  int reading2 = digitalRead(button2Pin);

  if (reading1 != lastButton1State) {
    lastDebounceTime = millis();
  }
  if (reading2 != lastButton2State) {
    lastDebounceTime = millis();
  }

  if (millis() - lastDebounceTime > debounceDelay) {
    if (reading1 != button1State) {
      button1State = reading1;
      if (button1State == LOW) {
        
        delayTime += 100;
      }
    }
    if (reading2 != button2State) {
      button2State = reading2;
      if (button2State == LOW) {
        
        if (delayTime > 100) {
          delayTime -= 100;
        }
      }
    }
  }

  lastButton1State = reading1;
  lastButton2State = reading2;

  
  digitalWrite(ledPin, HIGH);
  delay(delayTime);
  digitalWrite(ledPin, LOW);
  delay(delayTime);
}






//Q3 1,2


void setup() {
  Serial.begin(9600); 
}

void loop() {
  String myString = "Hello, this is a test string!";
  Serial.println(myString); 
  delay(1000); 
}


void setup() {
  Serial.begin(9600); 
}

void loop() {
  String userInput;

  if (Serial.available() > 0) {
    userInput = Serial.readString();
    Serial.print("You entered: ");
    Serial.println(userInput);
  }
}
