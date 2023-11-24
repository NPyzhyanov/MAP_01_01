#include <thread>
#include <chrono>

#include "consts.h"
#include "globals.h"
#include "events.h"
#include "print_event.h"
#include "responding_function.h"

void responding_function()
{
    do
    {
        std::this_thread::sleep_for(consts::time_delay);
    }
    while(clients_counter == 0);
    
    int client = 0;
    
    while(clients_counter != 0)
    {
        client++;
        auto serving_start = std::chrono::steady_clock::now();
        print_event(clients_counter, client, serving_start, events::client_called);
        
        std::this_thread::sleep_for(consts::response_period);
        
        clients_counter--;
        
        auto serving_finish = std::chrono::steady_clock::now();
        print_event(clients_counter, client, serving_finish, events::client_served);
    }
}
