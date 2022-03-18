char t;

  const int buzPin2 = 8;
 const int Led1 = 4;
 const int Led2 = 5;
  const int Led3 = A3;
 const int Led4 = A5;
 char ButtonValue ;

 
 
void setup() {
pinMode(13,OUTPUT);   //left motors forward
pinMode(12,OUTPUT);   //left motors reverse
pinMode(11,OUTPUT);   //right motors forward
pinMode(10,OUTPUT);   //right motors reverse
pinMode(Led1,OUTPUT);   //Led1
pinMode(Led2,OUTPUT);   //Led2
pinMode(Led3,OUTPUT);   //Led3
pinMode(Led4,OUTPUT);   //Led4


pinMode(buzPin2,OUTPUT);   //Buzzer 
Serial.begin(9600);
 
}
 
void loop() {

//ButtonValue = digitalRead(t);
  
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //move forward(all motors rotate in forward direction)
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
}
 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
}
 
else if(t == 'L'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(13,HIGH);
}
 
else if(t == 'R'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(11,HIGH);
}


if(t == 'w')
{
   digitalWrite(Led1,HIGH);
  digitalWrite(Led2,HIGH);
     digitalWrite(Led3,HIGH);
  digitalWrite(Led4,HIGH);
   
  }
else if(t == 'W'){
    digitalWrite(Led1,LOW);
  digitalWrite(Led2,LOW);
   digitalWrite(Led3,LOW);
  digitalWrite(Led4,LOW);
  }

 
else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}

else if(t == 'V'){      //SOUND (beep Buzzer
  tone(buzPin2,6000,1000);
  delay(2000);
  digitalWrite(buzPin2,LOW);

}

delay(100);
}
