const int greenLED = 2;
const int redLED = 3;
const int buzzer = 12;
const int vibrationSensor = A0;

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(vibrationSensor, INPUT);

  startGame();
}

void loop() {
  int sensorValue = digitalRead(vibrationSensor);

  if (sensorValue == HIGH) { // Vibration detected
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, HIGH);
    //wait for 3 seconds
    delay(3000);
    //turn off the buzzer
    //we turn off the buzzer and wait for 5 seconds before restarting the game. 
    //We wait because the buzzer itself create vibration which is detected by the vibration sensor.  
    digitalWrite(buzzer, LOW);
    //wait for five seconds before restarting the game
    delay(5000);
    startGame(); // Restart the game
  }
}

void startGame() {
  digitalWrite(greenLED, HIGH); // Turn on green LED to indicate game start
  digitalWrite(redLED, LOW);
}
