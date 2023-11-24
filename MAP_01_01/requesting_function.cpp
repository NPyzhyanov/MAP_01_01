#include <thread>
#include <chrono>

#include "consts.h"
#include "globals.h"
#include "events.h"
#include "print_event.h"
#include "requesting_function.h"

void requesting_function()
{
    for (int client = 0; client < consts::max_client_number; client++)
    {
        clients_counter++;
        
        auto now = std::chrono::steady_clock::now();
        print_event(clients_counter, client + 1, now, events::client_arrived);
        
        std::this_thread::sleep_for(consts::requests_period);
    }
}
