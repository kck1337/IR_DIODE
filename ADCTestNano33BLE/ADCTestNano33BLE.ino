int valueADC1 = 0;
int valueADC2 = 0;
int minValueADC = 4095;
int maxValueADC = 0;

void setup() {
  Serial.begin(9600);
}

int data1 = 0;
int data2 = 0;

void loop() {
  if (millis() >= 5000)  // starts after 5 seconds
  {
    analogReadResolution(12);
    valueADC1 = analogRead(A3);
    valueADC2 = analogRead(A4);
    if (valueADC1 > maxValueADC) maxValueADC = valueADC1;
    else 
    {
      if (valueADC1 < minValueADC) minValueADC = valueADC1;
    }

//    data = valueADC * 0.4 + (data * 0.6);

    data1 = valueADC1;
    data2 = valueADC2;
    float val1 = map(data1,0,4095,0,10000);
    float val2 = map(data2,0,4095,0,10000);
//    Serial.print((float)data*3.3/4095);
//    Serial.print(",");
    Serial.print(val1/10000);
    Serial.print("\t");
    Serial.println(val2/10000);  
//    Serial.print(",");
//    Serial.println(millis());
//    Serial.print("  ");
//    Serial.print((float)minValueADC*3.3/4095);
//    Serial.print("  ");
//    Serial.println((float)maxValueADC*3.3/4095);
  }
  delayMicroseconds(1);
}
