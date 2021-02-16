#include "config.h"
#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

#define LED_PIN 2

AdafruitIO_Feed *servos = io.feed("servos");

//int i = 0;
//int data = 0;

void setup() {
//  servo1.attach(4);
//  servo2.attach(5);
//  servo3.attach(2);
//  servo4.attach(16);
//
//  pinMode(4,OUTPUT);
//  pinMode(5,OUTPUT);
  pinMode(LED_PIN,OUTPUT);
//  pinMode(16,OUTPUT);

    // start the serial connection
    Serial.begin(115200);

    // wait for serial monitor to open
    while(! Serial);

    // connect to io.adafruit.com
    Serial.print("Connecting to Adafruit IO");
    io.connect();

    //change to your feed name you created in Adafruit IO
    servos->onMessage(handleMessage); //New!

    // wait for a connection
    while(io.status() < AIO_CONNECTED) {
      Serial.print(".");
      delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

  //change to your feed name you created in Adafruit IO
  servos->get(); //New!
}

void loop() {
    io.run();
    
  //if the incoming data equals 1, then spin the Servo Motors randomly between 20-50.
//    if (data=1) {
//      servo1.write(random(10,50));             
//      servo2.write(random(10,50));    
//      servo3.write(random(10,50));
//      servo4.write(random(10,50));        
//      delay(10);
//    }
//
//  //if the incoming data equals 0, then stop the Servo Motors or reverse the Motors
//    if (data=0) {
//      servo1.write(0);             
//      servo2.write(0);    
//      servo3.write(0);
//      servo4.write(0);        
//      delay(10);
//    }
}

void handleMessage(AdafruitIO_Data *servos) { // New!

  Serial.print("received <- ");

//change to your feed name you created in Adafruit IO
  if(servos->toPinLevel() == HIGH) // New!
    Serial.println("HIGH");
  else
    Serial.println("LOW");

//change to your feed name you created in Adafruit IO
  digitalWrite(LED_PIN, servos->toPinLevel()); // New!
}
