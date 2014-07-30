void setup()
{
	pinMode(3,OUTPUT);	//กำหนดให้ขาหมายเลข 2 ทำหน้าที่เป็น OUTPUT
	pinMode(4,OUTPUT);	//กำหนดให้ขาหมายเลข 4 ทำหน้าที่เป็น OUTPUT
        pinMode(5,OUTPUT);	//กำหนดให้ขาหมายเลข 5 ทำหน้าที่เป็น OUTPUT
        pinMode(6,OUTPUT);	//กำหนดให้ขาหมายเลข 6 ทำหน้าที่เป็น OUTPUT
     
        Serial.begin(9600);      //กำหนดความเร็วในการส่งข้อมูล
}
void motor_forward(unsigned char Left_duty,unsigned char Right_duty)	//ฟังก์ชั่นสำหรับสั่งงานให้มอเตอร์หมุนไปข้างหน้า ปรับความเร็วได้ 0-255
{                                                                       //Left_duty คือความเร็วล้อซ้าย
	analogWrite(5,Left_duty);                                       //Right_duty คือวคามเร็วล้อขวา
	digitalWrite(3,LOW);

        analogWrite(6,Right_duty);
	digitalWrite(4,LOW);
}
void motor_backward(unsigned char Left_duty,unsigned char Right_duty)	//ฟังก์ชั่นสำหรับสั่งงานให้มอเตอร์หมุนถอยหลัง ปรับความเร็วได้ 0-255
{                                                                       //Left_duty คือความเร็วล้อซ้าย
	analogWrite(5,255-Left_duty);                                   //Right_duty คือวคามเร็วล้อขวา
	digitalWrite(3,HIGH);

        analogWrite(6,255-Right_duty);
	digitalWrite(4,HIGH);
}
void setspeed(unsigned char Left_duty,unsigned char Right_duty)
{
        if(Left_duty>0)
        {
          analogWrite(5,Left_duty);                                       //Right_duty คือวคามเร็วล้อขวา
          digitalWrite(3,LOW);
        }else
        {
          analogWrite(5,255-(Left_duty*(-1)));                                   //Right_duty คือวคามเร็วล้อขวา
	  digitalWrite(3,HIGH);
        }
        if(Right_duty>0)
        {
          analogWrite(6,Right_duty);
          digitalWrite(4,LOW);
        }
        else
        {
          analogWrite(6,255-(Right_duty*(-1)));
	  digitalWrite(4,HIGH);
        }
}

void loop()
{	
        int SS1 = analogRead(4);         // อ่านค่า Sensor1 โดยมีค่าอยู่ในช่วง 0- 1024
        int SS2 = analogRead(5);         // อ่านค่า Sensor2 โดยมีค่าอยู่ในช่วง 0- 1024
        int SS3 = analogRead(6);         // อ่านค่า Sensor3 โดยมีค่าอยู่ในช่วง 0- 1024
       
        if(SS1 < 800){                   //กำหนดเงื่อนไขว่า ถ้า SS1 มีค่ามากกว่า 800 จะทำงานใน{...}
          motor_forward(0,128);          //สั่งให้มอเตอร์ซ้ายหยุดและมอเตอร์ขวาหมุนไปข้างหน้าด้วยความเร็ว 50%
        }
        else if(SS3 < 800){              //กำหนดเงื่อนไขว่า ถ้า SS2 มีค่ามากกว่า 800 จะทำงานใน{...}
          motor_forward(128,0);          //สั่งให้มอเตอร์ขวาหยุดและมอเตอร์ซ้ายหมุนไปข้างหน้าด้วยความเร็ว 50%
        }
        else{
	  motor_forward(127,127);	//สั่งให้มอเตอร์หมุนไปข้างหน้าด้วยความเร็ว 50%
        }    
        Serial.print(SS1);              //อ่านค่าเซนเซอร์ SS1 ผ่านทาง Serial Monitor
        Serial.print("\t");             //คำสั่งเว้นวรรค 1 แทบ
        Serial.print(SS2);              //อ่านค่าเซนเซอร์ SS2 ผ่านทาง Serial Monitor
        Serial.print("\t");
        Serial.print(SS3);              //อ่านค่าเซนเซอร์ SS3 ผ่านทาง Serial Monitor
        Serial.print("\n");
	
}				//หลังจากจบบรรทัดนี้โปรแกรมจะขึ้นไปทำบรรทัดแรกของ void loop ใหม่

