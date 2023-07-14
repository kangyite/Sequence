# Sequence - A Non RTOS State Machine


## Getting Started

###To declare a LinkedList object
```c++
Sequence<1> stateMachine //to create a Sequence class with 1 timer.

Sequence<N> stateMachine //to create a Sequence class with N timers.
```

### State
note: default state is 0
```c++
#include <Sequence.h>
//No timer needed for this example
Sequence<0> stateMachine;

enum states{
  state_hello, state_world
};

void setup(){
  Serial.begin(115200);
}

void loop(){
  seq();
}

void seq(){
  switch(stateMachine.state){
    case state_hello:
      Serial.print("Hello ");
      stateMachine.state = state_world;
    break;

    case state_world:
      Serial.println("World!");
      stateMachine.state = state_hello;
    break;

    default:
    break;
  }
}

```

### Timer
```c++
#include <Sequence.h>

Sequence<1> stateMachine;

enum states{
  state_hello, state_world
};

void setup(){
  Serial.begin(115200);
}
void loop(){
  seq();
}

void seq(){
  switch(stateMachine.state){
    case state_hello:
      if(stateMachine.timeout()){
        stateMachine.set_timer(500); // Set timer of 500 milliseconds
        Serial.print("Hello ");
        stateMachine.state = state_world;
      } 
    break;

    case state_world:
      if(stateMachine.timeout()){ 
        stateMachine.set_timer(500); // Set timer of 500 milliseconds
        Serial.println("World!");
        stateMachine.state = state_hello;
      } 
    break;

    default:
    break;
  }
}
```

### Multiple Timers
```c++
//Initialize 3 timers to stateMachine
Sequence<3> stateMachine;

stateMachine.set_timer(500); // Set 500ms to timer 0, indexed to timer 0 if the 2nd argument isn't given.
stateMachine.set_timer(500,0); // Set 500ms to timer 0
stateMachine.set_timer(500,1); // Set 500ms to timer 0
stateMachine.set_timer(500,2); // Set 500ms to timer 0

stateMachine.timeout(); // Check timeout for timer 0, indexed to timer 0 if the 2nd argument isn't given.
stateMachine.timeout(0); // Check timeout for timer 0
stateMachine.timeout(1); // Check timeout for timer 1
stateMachine.timeout(2); // Check timeout for timer 2
```

### Microseconds
```c++
Sequence<1> stateMachine;

stateMachine.set_timer(500,0,MICROS); // Need to specify the index of timer even it's the 0th timer

```
