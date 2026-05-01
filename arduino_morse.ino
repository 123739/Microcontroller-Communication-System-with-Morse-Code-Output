const int txPin = 2;

void setup() {
  pinMode(txPin, OUTPUT);
  digitalWrite(txPin, LOW);
  Serial.begin(9600);
}

void sendByte(char c) {

  // start pulse
  digitalWrite(txPin, HIGH);
  delay(100);
  digitalWrite(txPin, LOW);
  delay(100);

  // send bits with FIXED timing
  for (int i = 7; i >= 0; i--) {
    int bit = bitRead(c, i);
    digitalWrite(txPin, bit);

    delay(150); // 🔥 IMPORTANT: increase stability
  }

  digitalWrite(txPin, LOW);
  delay(300);
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();

    if (c == '\n' || c == '\r') return;

    c = toupper(c);

    Serial.print("Sent: ");
    Serial.println(c);

    sendByte(c);
  }
}