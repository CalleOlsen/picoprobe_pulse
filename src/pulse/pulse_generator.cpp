#include "pulse_generator.hpp"
#include <pico/stdlib.h>
#include <cstdint>

constexpr inline uint8_t PULSE_PIN = 15;

// decltype(auto) init_repeating_timer(auto&& timer)
// {
//     return [timer](int32_t timeout, auto callback) mutable {
//         return add_repeating_timer_ms(timeout, callback, nullptr, &timer);
//     };
// }

namespace  {

repeating_timer pulse_timer{};
bool current = true;


bool callback(struct repeating_timer* rt)
{
        current = !current;
        gpio_put(PULSE_PIN,current);
        return true;
}
}



void core1_entry()
{


    gpio_init(PULSE_PIN);
    gpio_set_dir(PULSE_PIN,true);
    gpio_put(PULSE_PIN,true);
    add_repeating_timer_ms(1, callback, nullptr, &pulse_timer);
    //add_repeating_timer( 1, )''
    while(1)
    {
        //sleep_ms(300);


    }
}
