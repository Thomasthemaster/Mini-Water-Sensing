const int sensorPin = A5;
const int r = 6;
const int g = 5;
const int b = 3;

const int samples = 20;

// Calibration Data
const float quarterSubmerged = 390.3; // THESE VALUES WILL BE DIFFERENT FOR YOU. CHANGE THEM TO YOUR CALIBRATION DATA.
const float halfSubmerged = 409.0;
const float threeQuartersSubmerged = 418.0;
const float fullySubmerged = 427.7;

float getWaterLevel() {
  long total = 0;

  for (int i = 0; i < samples; i++) {
    total += analogRead(sensorPin);
    delay(10);
  }

  return (float)total / samples;
}

float getPercentage(float adc) {

  if (adc < quarterSubmerged) {
    digitalWrite(r, HIGH);
    digitalWrite(g, LOW);
    digitalWrite(b, LOW);
    return 0;  // Below calibrated range
  }

  if (adc < halfSubmerged) {
    digitalWrite(r, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(b, LOW);
    return 25 + (adc - quarterSubmerged) / (halfSubmerged - quarterSubmerged) * 25;
  }

  if (adc < threeQuartersSubmerged) {
    digitalWrite(r, LOW);
    digitalWrite(g, HIGH);
    digitalWrite(b, LOW);
    return 50 + (adc - halfSubmerged) / (threeQuartersSubmerged - halfSubmerged) * 25;
  }

  if (adc < fullySubmerged) {
    digitalWrite(r, LOW);
    digitalWrite(g, HIGH);
    digitalWrite(b, HIGH);
    return 75 + (adc - threeQuartersSubmerged) / (fullySubmerged - threeQuartersSubmerged) * 25;
  }
  digitalWrite(r, LOW);
  digitalWrite(g, LOW);
  digitalWrite(b, HIGH);
  return 100;
}

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop() {
  float adc = getWaterLevel();
  float percentage = getPercentage(adc);

  Serial.print("ADC: ");
  Serial.print(adc, 1);

  Serial.print(" | Estimated immersion: ");
  Serial.print(percentage, 1);
  Serial.println("%");

  delay(500);
}
