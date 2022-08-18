int valueADC1 = 0;
int valueADC2 = 0;
int minValueADC1 = 4095;
int maxValueADC1 = 0;
int minValueADC2 = 4095;
int maxValueADC2 = 0;

const int wrist = A2;
const int forearm = A3;

void setup() {
  Serial.begin(9600);
}

int data1 = 0;
int data2 = 0;

void loop() {
  if (millis() >= 5000)  // starts after 5 seconds
  {
    analogReadResolution(12);
    valueADC1 = analogRead(wrist);
    valueADC2 = analogRead(forearm);
    if (valueADC1 > maxValueADC1) maxValueADC1 = valueADC1;
    else 
    {
      if (valueADC1 < minValueADC1) minValueADC1 = valueADC1;
    }
    if (valueADC2 > maxValueADC2) maxValueADC2 = valueADC2;
    else 
    {
      if (valueADC2 < minValueADC2) minValueADC2 = valueADC2;
    }

//    data = valueADC * 0.4 + (data * 0.6);

    data1 = valueADC1;
    data2 = valueADC2;
    float val1 = map(data1,minValueADC1,maxValueADC1,0,10000);
    float val2 = map(data2,minValueADC2,maxValueADC2,0,10000);
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
  delay(1);
}
