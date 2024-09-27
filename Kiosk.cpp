#include <iostream>

#include "Kiosk.h"
#include "Washer.h"
#include "Dryer.h"
#include "Laundromat.h"

/// Constructor with laundromat field
/// \param l laundromat
Kiosk::Kiosk(Laundromat *l) {
    this -> l = l;
}

/// Asks user whether they want a washer or a dryer.
/// Retrieves first available washer/dryer from the corresponding pool.
/// Returns itself to its object pool.
/// Starts washing/drying accordingly.
/// Returns washer/dryer back to pool after the washing or drying is done.
/// Only one thread at a time can access the kiosk because the method
/// getObject<Kiosk>() of the Kiosk pool is protected by a mutex lock
/// and when kiosk is given to the user it is removed from the pool.
void Kiosk::GetLaundryService(){
    int choice = -1;
    std::cout << "Will you be washing or drying today? \n(0) washing \n(1) drying \n" << std::endl;
    std::cin >> choice;

    while (choice != 0 && choice !=1 ){
        std::cout << "please input the number 0 or 1.\n";
        std::cin >> choice;
    }

    if (choice == 0) {
        std::optional<Washer> w = getWasher();
        if (w){
            std::cout << "Washer found!\n";
            l->returnKioskToPool(*this);
            w->wash();

            if(!l->returnWasherToPool(w.value())){
                std::cout << "Unable to return washer" << std::endl;
            }
        } else {
            std::cout << "Washer not found, come back another time";
        }

    } else {
        std::optional<Dryer> d = getDryer();
        if (d) {
            std::cout << "Dryer found!\n";
            l->returnKioskToPool(*this);
            d->dry();

            if(!l->returnDryerToPool(d.value()))
                std::cout << "Unable to return dryer" << std::endl;

        } else {
            std::cout << "Dryer not found, come back another time";
        }
    }
}

/// Returns first available Washer.
/// \return Washer
std::optional<Washer> Kiosk::getWasher() {
    return l->getWasher();
}

/// Returns first available Dryer.
/// \return Dryer
std::optional<Dryer> Kiosk::getDryer() {
    return l->getDryer();
}
