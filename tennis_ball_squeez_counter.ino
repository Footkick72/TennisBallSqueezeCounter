float connectionState = 0;
int presses = 0;
int stableTime = 0;
int runs = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(4, INPUT);
  digitalWrite(2, HIGH);
  Serial.print("GO!");
  Serial.print("\n");
}

void loop() {
  // put your main code here, to run repeatedly:
  int v = digitalRead(4);
  if (v != connectionState) {
    stableTime++;
    if (stableTime > 1000) {
      connectionState = v;
      stableTime = 0;
      if (v == LOW) {
        presses++;
      }
    }
  }
  else {
    stableTime = 0;
  }
  if (millis() / 10000 > runs) {
    runs++;
    Serial.print(presses);
    Serial.print(" - ");
    Serial.print(runs);
    Serial.print("\n");
    presses = 0;
  }
}
