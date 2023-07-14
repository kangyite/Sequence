#include <Sequence.h>

// Define the sequence class using Sequence<N> where N is the number of timer
// 1 timer is enough for most application
Sequence<1> led; 

#define LED_PIN 13

enum led_state{
    off_state, on_state //off_state = 0, on_state = 1
};

void setup(){
    pinMode(LED_PIN, OUTPUT);
}

void loop(){
    seq();
}

void seq(){
    // .state default value is 0
    switch (led.state)
    {
        case off_state:
            if(led.timeout()){
                digitalWrite(LED_PIN, LOW);
                led.set_timer(500);
                led.state = on_state;
            }
            break;

        case on_state:
            if(led.timeout()){
                digitalWrite(LED_PIN, HIGH);
                led.set_timer(500);
                led.state = off_state;
            }
            break;

        default:
            break;
    }
}
