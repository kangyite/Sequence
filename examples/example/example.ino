#include <Arduino.h>
#include <Sequence.h>

// Define the sequence class using Sequence<N> where N is the number of timer
Sequence<3> a;
Sequence<1> b;
enum a_state{
    state_hello, state_world, state_micro
};

void a_loop();
void b_loop();

void setup(){
    Serial.begin(115200);
}

void loop(){
    a_loop();
    b_loop();
}


void a_loop(){
    // .state default value is 0
    switch (a.state)
    {
        case state_hello:
            if(a.timeout()){
                Serial.println("Hello");
                a.set_timer(500);
                a.state = state_world;
            }
            break;
        case state_world:
            if(a.timeout()){
                Serial.println("World!");
                a.set_timer(500);
                a.state = state_micro;
            }
            break;
        case state_micro:
            // using a's 2nd timer by setting index 
            if(a.timeout(1)){
                a.set_timer(500*1000,1,MICROS);
                Serial.println("500000 microseconds");
            }
        break;
        default:
            break;
    }
}

void b_loop(){
    switch (b.state)
    {
    case 0:
        if(b.timeout()){
            b.set_timer(1000);
            Serial.println("Second passed!");
        }
        break;
    
    default:
        break;
    }
}