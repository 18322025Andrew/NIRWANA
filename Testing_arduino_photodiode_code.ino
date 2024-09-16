const int ledPin = 4;        // Pin for the LED
const int photoPin = A1;     // Pin for the photodiode
const float maxAnalogValue = 1023; // Maximum value returned by analogRead()

float maxValue = 0; // calibrate value
float meanValue = 0;
int count = 0;

void setup() {
  pinMode(ledPin, OUTPUT);   // Set LED pin as output
  Serial.begin(9600);        // Begin serial communication for debugging
}

void loop() {
  digitalWrite(ledPin, HIGH);
  float sensorValue = (analogRead(photoPin)*5)/maxAnalogValue; // Read the value from the photodiode
  if(sensorValue >= maxValue){
    maxValue = sensorValue;
  }
  float intensityPercentage = (sensorValue / maxValue) * 100; // Calculate light intensity as a percentage
  
  // Print the sensor value and intensity percentage to the Serial Monitor
  // Send only numerical data to the Serial Plotter
  Serial.print(sensorValue, 5);   // Raw sensor value
    // Voltage reading
  Serial.print(",");           // Separator for the plotter
  Serial.println(intensityPercentage, 5); // Light intensity percentage

  meanValue += sensorValue;
  count ++;
  Serial.print("Mean Value :");
  Serial.println(meanValue/count);
  delay(10);  // Small delay for better stability
}
