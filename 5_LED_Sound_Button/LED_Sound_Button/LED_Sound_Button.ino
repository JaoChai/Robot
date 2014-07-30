
int buttonState = 1;
void setup()             
{
  for(int i=2 ; i<=7 ; i++)
  {
    pinMode(i, OUTPUT);    //กำหนดให้ขาพอร์ตที่ 2 ถึง 7 เป็น OUTPUT
  }
  pinMode(10,INPUT);        //กำหนดให้ pin หมายเลข 10 เป็น INPUT (BUTTON)
}
void loop()
{
  digitalWrite(10,HIGH);  //กำหนดให้เป็น BUTTON เป็นแบบ PULL UP คือถ้ามีการกดปุ่มจะเป็น LOW หรือ 0 ถ้าไม่กดจะเป็น HIGH หรือ 1
  
  buttonState = digitalRead(10);
  if(buttonState == LOW){
   for(int i=2 ; i<=7 ; i++)
   {
      digitalWrite(i,HIGH);  //สั่งให้ขาพอร์ตที่ i มีสถานะเป็น HIGH
      tone(9,131+(20*i-2),100); //สั่งงานเสียงผ่าน pin หมายเลข 9 โดยให้เสียงดัง 1000 มิลลิวินาที
      delay(100);           //หน่วงเวลา 1000 มิลลิวินาที หรือ 1 วินาที
      digitalWrite(i,LOW);   //สั่งให้ขาพอร์ตที่ i มีสถานะเป็น LOW
      delay(100);           //หน่วงเวลา 1000 มิลลิวินาที หรือ 1 วินาที
   }
  }
  else
  {
    for(int i=7 ; i>=2 ; i--)
    {
      digitalWrite(i,HIGH);  //สั่งให้ขาพอร์ตที่ i มีสถานะเป็น HIGH
      tone(9,131+(20*i-2),100); //สั่งงานเสียงผ่าน pin หมายเลข 9 โดยให้เสียงดัง 1000 มิลลิวินาที
      delay(100);           //หน่วงเวลา 1000 มิลลิวินาที หรือ 1 วินาที
      digitalWrite(i,LOW);   //สั่งให้ขาพอร์ตที่ i มีสถานะเป็น LOW
      delay(100);           //หน่วงเวลา 1000 มิลลิวินาที หรือ 1 วินาที
   }
  }
}
