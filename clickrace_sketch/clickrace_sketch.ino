#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

#define IO_USERNAME  "Xplosivebum"
#define IO_KEY       "aio_xDpW81DDXBE1IMn1V21IWg9nxVye"
AdafruitIO_Feed *testData = io.feed("testData");

int i = 0;

void setup() {
  servo1.attach(4);
  servo2.attach(5);
  servo3.attach(2);
  servo4.attach(16);

    // start the serial connection
    Serial.begin(115200);

    // wait for serial monitor to open
    while(! Serial);

    // connect to io.adafruit.com
    Serial.print("Connecting to Adafruit IO");
    io.connect();

    //change to your feed name you created in Adafruit IO
    testData->onMessage(handleMessage); //New!

    // wait for a connection
    while(io.status() < AIO_CONNECTED) {
      Serial.print(".");
      delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

  //change to your feed name you created in Adafruit IO
  testData->get(); //New!
}

void loop() {
    io.run();
    
  for (int i = 0; i < 180; i++) {
    servo1.write(i);             
    servo2.write(i);    
    servo3.write(i);
    servo4.write(i);        
    delay(10);                     
  }
  for (i = 180; i > 0; i--) {
    servo1.write(i);               
    servo2.write(i);    
    servo3.write(i);
    servo4.write(i);         
    delay(10);                     
  }

    // save the current state to the 'digital' feed on adafruit io
    Serial.print("sending testData -> ");
    Serial.println(current);

    //place your specific feed name
    testData->save(current);

    // store last testData state
    last = current;
}

    void handleMessage(AdafruitIO_Data *testData) {
      Serial.print("received <- ");

        if(testData->toPinLevel() == HIGH)
          Serial.println("HIGH");
        else
          Serial.println("LOW");
          
        digitalWrite(LED_PIN, testData->toPinLevel()); // New!
}
