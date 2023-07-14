#ifndef SEQUENCE_H_
#define SEQUENCE_H_
#include <Arduino.h>

#define MILLIS 0
#define MICROS 1

template<uint8_t N> struct Sequence{
    private:
        uint8_t total_timer_num = N;
        uint32_t time_data[N];
        uint32_t time_set[N];
        bool timer_type[N];
    public:
        uint8_t state = 0;

        /**
         * Set timer
         *
         * @param temp_tim_set The time for the timer.
         * @param timer_index (optional) The index of timer (default is 0).
         * @param temp_time_type (optional) MILLIS or MICROS (default is MILLIS)
         * @return Boolean type status indicates the success of the operation.
         */
        bool set_timer(uint32_t temp_tim_set, uint8_t timer_index = 0, bool temp_timer_type = MILLIS){
            if(timer_index >= total_timer_num) return false;
            time_set[timer_index] = temp_tim_set;
            timer_type[timer_index] = temp_timer_type;
            if(temp_timer_type == MILLIS){
                time_data[timer_index] = millis();
            }
            else{
                time_data[timer_index] = micros();
            }
            return true;
        }

        /**
         * Check status of timer
         *
         * @param timer_index (optional) The index of timer (default is 0).
         * @return True if timeout, otherwise false
         */
        bool timeout(uint8_t timer_index = 0){
            if(timer_index >= total_timer_num) return false;
            if(timer_type[timer_index] == MILLIS){
                if ((millis() - time_data[timer_index]) >= time_set[timer_index]) return true;
            }
            else{
                if ((micros() - time_data[timer_index]) >= time_set[timer_index]) return true;
            }
            return false;
        }
        
};

#endif


