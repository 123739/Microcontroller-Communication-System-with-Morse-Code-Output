const int rxPin = 4;

const int bluePin = 2;
const int greenPin = 5;
const int buzzerPin = 23;

// -------- MORSE TABLE --------
String getMorse(char c) {
  switch(c) {
    case 'A': return ".-";
    case 'B': return "-...";
    case 'C': return "-.-.";
    case 'D': return "-..";
    case 'E': return ".";
    case 'F': return "..-.";
    case 'G': return "--.";
    case 'H': return "....";
    case 'I': return "..";
    case 'J': return ".---";
    case 'K': return "-.-";
    case 'L': return ".-..";
    case 'M': return "--";
    case 'N': return "-.";
    case 'O': return "---";
    case 'P': return ".--.";
    case 'Q': return "--.-";
    case 'R': return ".-.";
    case 'S': return "...";
    case 'T': return "-";
    case 'U': return "..-";
    case 'V': return "...-";
    case 'W': return ".--";
    case 'X': return "-..-";
    case 'Y': return "-.--";
    case 'Z': return "--..";
    default: return "";
  }
}

// -------- OUTPUT FUNCTIONS --------
void dot() {
  digitalWrite(bluePin, HIGH);
  tone(buzzerPin, 800);
  delay(200);

  digitalWrite(bluePin, LOW);
  noTone(buzzerPin);
  delay(200);
}

void dash() {
  digitalWrite(greenPin, HIGH);
  tone(buzzerPin, 1200);
  delay(500);

  digitalWrite(greenPin, LOW);
  noTone(buzzerPin);
  delay(200);
}

// -------- RECEIVE BYTE (already working sync system) --------
char receiveByte() {

  while (digitalRead(rxPin) == LOW);  // wait for start

  delay(120); // align timing

  byte value = 0;

  for (int i = 7; i >= 0; i--) {
    delay(150); // mid-bit sampling
    int bit = digitalRead(rxPin);
    bitWrite(value, i, bit);
  }

  return (char)value;
}

// -------- SETUP --------
void setup() {
  pinMode(rxPin, INPUT);

  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(115200);
}

// -------- LOOP --------
void loop() {

  char c = receiveByte();

  Serial.print("Received: ");
  Serial.println(c);

  String morse = getMorse(c);

  // PLAY FULL MORSE SEQUENCE
  for (int i = 0; i < morse.length(); i++) {

    if (morse[i] == '.') {
      dot();
    }
    else if (morse[i] == '-') {
      dash();
    }
  }

  delay(800); // gap between letters
}