const int sensorPin = A5;
const int led = 2;

const int samples = 20;

// Calibration Data
const float quarterSubmerged = 361.3; // THESE VALUES WILL BE DIFFERENT FOR YOU. CHANGE THEM TO YOUR CALIBRATION DATA.
const float halfSubmerged = 383.0;
const float threeQuartersSubmerged = 392.0;
const float fullySubmerged = 398.7;

float getWaterLevel() {
  long total = 0;

  for (int i = 0; i < samples; i++) {
    total += analogRead(sensorPin);
    delay(10);
  }

  return (float)total / samples;
}

float getPercentage(float adc) {

  if (adc < quarterSubmerged) {  // if you want to measure percentages below 25%, you must calibrate the sensor more with readings at 10% height, etc.
    return 0;  // Below calibrated range
  }

  if (adc < halfSubmerged) {
    return 25 + (adc - quarterSubmerged) / (halfSubmerged - quarterSubmerged) * 25;
  }

  if (adc < threeQuartersSubmerged) {
    return 50 + (adc - halfSubmerged) / (threeQuartersSubmerged - halfSubmerged) * 25;
  }

  if (adc < fullySubmerged) {
    return 75 + (adc - threeQuartersSubmerged) / (fullySubmerged - threeQuartersSubmerged) * 25;
  }

  return 100;
}

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(sensorPin, INPUT);
}

void loop() {
  float adc = getWaterLevel();
  float percentage = getPercentage(adc);

  Serial.print("ADC: ");
  Serial.print(adc, 1);

  Serial.print(" | Estimated immersion: ");
  Serial.print(percentage, 1);
  Serial.println("%");

  if (percentage > 0) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }

  delay(500);
}
