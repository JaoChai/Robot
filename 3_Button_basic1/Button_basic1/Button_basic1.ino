
int buttonState = 0;         // สถานะของปุ่มถ้ากดจะเป็น 1 หรือ HIGH ถ้าไม่กดจะเป็น 0 หรือ LOW

void setup() {
  pinMode(2, OUTPUT);   //กำหนดให้ pin 2 เป็น OUTPUT (LED)
  pinMode(3, INPUT);    //กำหนดให้ pin 3 เป็น INPUT  (Button)
}

void loop(){
  buttonState = digitalRead(3); //อ่านสถานะจาก Button มาเก็บไว้ในตัวแปร buttonState
  
  if (buttonState == HIGH) {     //ตรวจสอบว่ากดปุ่มหรือไม่ ถ้ากดทำใน {..}ถ้าไม่กดทำใน else{...}
    // turn LED on:    
    digitalWrite(2, HIGH);  //ไฟ LED ติด
  } 
  else {
    // turn LED off:
    digitalWrite(2, LOW);   //ไฟ LED ดับ
  }
}
