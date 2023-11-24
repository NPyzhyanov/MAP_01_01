#include <iostream>
#include <chrono>

#include "globals.h"
#include "events.h"
#include "print_event.h"

void print_event(int clients_amount, int client_number, std::chrono::time_point<std::chrono::steady_clock> time, events event)
{
    auto event_time = std::chrono::duration_cast<std::chrono::milliseconds>(time - start);
    std::cout << event_time.count() << "ms\t";
    
    std::cout << "Client #" << client_number;
    switch (event)
    {
    case events::client_arrived:
        std::cout << " arrived.";
        break;
    case events::client_called:
        std::cout << " is called.";
        break;
        
    case events::client_served:
        std::cout << " is served.";
        break;
    }
    
    std::cout << "\tThere are " << clients_amount << " unserved clients." << std::endl;
}
