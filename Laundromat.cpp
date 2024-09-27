#include <iostream>

#include "Laundromat.h"
#include "Washer.h"
#include "Dryer.h"
#include "Kiosk.h"
#include "ObjPool.h"

/// Default constructor.
/// Initializes washers, dryers, and kiosk object pools.
Laundromat::Laundromat() {
    std::vector<Washer> w(NUM_WASHERS);
    std::vector<Dryer> d(NUM_DRYERS);
    std::vector<Kiosk> k;
    for (int i = 0; i < NUM_KIOSKS; i++){
        k.push_back(*(new Kiosk(this)));
    }

    washers = ObjPool<Washer>(w);
    dryers = ObjPool<Dryer>(d);
    kiosks = ObjPool<Kiosk>(k);

}

/// Returns first available Washer.
/// \return Washer
std::optional<Washer> Laundromat::getWasher() {
    return washers.getObject();
}

/// Returns Washer to Washer pool
/// \param w Washer
/// \return true on success, false on failure
bool Laundromat::returnWasherToPool(Washer w){
    return washers.returnObjToPool(w);
}

/// Returns first available dryer
/// \return Dryer
std::optional<Dryer> Laundromat::getDryer() {
    return dryers.getObject();
}

/// Returns Dryer to Dryer pool
/// \param d Dryer
/// \return true on success, false on failure
bool Laundromat::returnDryerToPool(Dryer d){
    return dryers.returnObjToPool(d);
}

/// Returns first available Kiosk
/// \return Kiosk
std::optional<Kiosk> Laundromat::getKiosk() {
    return kiosks.getObject();
}

/// Returns Kiosk to Kiosk pool
/// \param k Kiosk
/// \return true on success, false on failure
bool Laundromat::returnKioskToPool(Kiosk k) {
    return kiosks.returnObjToPool(k);
}