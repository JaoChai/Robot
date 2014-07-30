int incomingByte = 0;   // ตัวแปรประเภท int 
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


void loop()
{	
        
        if (Serial.available() > 0) {
              incomingByte = Serial.read();
              if(incomingByte == 'w'){                   //กำหนดเงื่อนไขว่า ถ้า incomingByte เก็บค่า w ไว้จะทำงานใน {...}
                  motor_forward(128,128);                //สั่งให้มอเตอร์ซ้ายและมอเตอร์ขวาหมุนไปข้างหน้าด้วยความเร็ว 50%
              }
              else if(incomingByte == 's'){              //กำหนดเงื่อนไขว่า ถ้า incomingByte เก็บค่า s ไว้จะทำงานใน {...}
                motor_backward(128,128);                  //สั่งให้มอเตอร์ขวาและมอเตอร์ซ้ายหมุนไปด้านหลังด้วยความเร็ว 50%
              }
              else  if(incomingByte == 'a'){             //กำหนดเงื่อนไขว่า ถ้า incomingByte เก็บค่า a ไว้จะทำงานใน {...}
      	        motor_forward(0,128);	                 //สั่งให้มอเตอร์ซ้ายหยุดและมอเตอร์ขวาหมุนไปด้านหลังด้วยความเร็ว 50%
              }    
               else  if(incomingByte == 'd'){            //กำหนดเงื่อนไขว่า ถ้า incomingByte เก็บค่า d ไว้จะทำงานใน {...}
      	        motor_forward(128,0);	                 //สั่งให้มอเตอร์ขวาหยุดและมอเตอร์ซ้ายหมุนไปด้านหลังด้วยความเร็ว 50%
              }   
        }
        
	
}				//หลังจากจบบรรทัดนี้โปรแกรมจะขึ้นไปทำบรรทัดแรกของ void loop ใหม่






