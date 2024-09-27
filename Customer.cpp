#include "Customer.h"
#include <iostream>

/// Gets available kiosk from laundromat and calls GetLaundryService() on it.
/// Prints a message if kiosk is not available.
void Customer::doLaundry() {
    std::optional<Kiosk> k = l.getKiosk();

    if (k){
        std::cout << "Kiosk found!" << std::endl;
        k->GetLaundryService();
    } else {
        std::cout << "Kiosk not found, come back tomorrow!";
    }
}