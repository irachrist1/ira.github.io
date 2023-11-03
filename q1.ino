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
