
int sensorValue = 0;        // sensorValue เป็นตัวแปรประเภท int หรือจำนวนเต็ม ใช้เป็นค่า sensor
int outputValue = 0;        // outputValue เป็นตัวแปรประเภท int หรือจำนวนเต็ม ใช้เป็นค่าความถี่

void setup() {
  
  Serial.begin(9600); //กำหนดความเร็วในการรับส่งข้อมูล 9600 bit ต่อวินาที
}

void loop() {
  
  sensorValue = analogRead(3);                      //อ่านค่า sensor มาเก็บไว้ที่ sensorValue
  
  outputValue = map(sensorValue, 0, 1023, 0, 255);  //ปรับค่าที่ได้จาก sensor ที่มีช่วง 0 - 1024 ให้อยู่ในช่วง 0-255 แล้วเก็บไว้ในตัวแปร outputValue
  
  analogWrite(9, outputValue);                      //สั่งงานเสียงโดยใช้ความที่จาก outputValue

  
  Serial.print("sensor = " );                        //ส่งข้อมูล sensor = ผ่าน serial Port
  Serial.print(sensorValue);                         //ส่งข้อมูล sensorValue ผ่าน serial Port
  Serial.print("\t output = ");                      //ส่งข้อมูล output = ผ่าน serial Port
  Serial.println(outputValue);                       //ส่งข้อมูล outputValue ผ่าน serial Port
  
  delay(10);                                         //หน่วงเวลา 10 วินาที
}
