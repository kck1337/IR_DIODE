int valueADC = 0;
int minValueADC = 4095;
int maxValueADC = 0;

void setup() {
  Serial.begin(9600);
}

int data = 0;

void loop() {
  if (millis() >= 5000)  // starts after 5 seconds
  {
    analogReadResolution(12);
    valueADC = analogRead(A3);
    if (valueADC > maxValueADC) maxValueADC = valueADC;
    else 
    {
      if (valueADC < minValueADC) minValueADC = valueADC;
    }

//    data = valueADC * 0.4 + (data * 0.6);

//    data = valueADC;
    float val = map(data,0,4095,0,10000);
//    Serial.print((float)data*3.3/4095);
//    Serial.print(",");
    Serial.println(val/10000);
//    Serial.print(",");
//    Serial.println(millis());
//    Serial.print("  ");
//    Serial.print((float)minValueADC*3.3/4095);
//    Serial.print("  ");
//    Serial.println((float)maxValueADC*3.3/4095);
  }
  delay(10);
}
