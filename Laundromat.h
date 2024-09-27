#pragma once
#ifndef LAUNDROMAT_LAUNDROMAT_H
#define LAUNDROMAT_LAUNDROMAT_H

#include <pthread.h>
#include "Washer.h"
#include "Dryer.h"
#include "Kiosk.h"
#include "ObjPool.h"

#include <vector>

/// Creates pools of washers, dryers, and kiosks.
/// Provides methods to access them.
class Laundromat {
public:
    /// Default constructor.
    /// Initializes washers, dryers, and kiosk object pools.
    Laundromat();

    /// Returns first available Washer.
    /// \return Washer
    std::optional<Washer> getWasher();

    /// Returns Washer to Washer pool
    /// \param w Washer
    /// \return true on success, false on failure
    bool returnWasherToPool(Washer w);


    /// Returns first available dryer
    /// \return Dryer
    std::optional<Dryer> getDryer();

    /// Returns Dryer to Dryer pool
    /// \param d Dryer
    /// \return true on success, false on failure
    bool returnDryerToPool(Dryer d);


    /// Returns first available Kiosk
    /// \return Kiosk
    std::optional<Kiosk> getKiosk();

    /// Returns Kiosk to Kiosk pool
    /// \param k Kiosk
    /// \return true on success, false on failure
    bool returnKioskToPool(Kiosk k);

private:
    /// Object pool of washers
    ObjPool<Washer> washers;
    /// Object pool of dryers
    ObjPool<Dryer> dryers;
    /// Object pool of kiosks
    ObjPool<Kiosk> kiosks;

    /// Number of washers in pool
    static const int NUM_WASHERS = 20;
    /// Number of dryers in pool
    static const int NUM_DRYERS = 20;
    /// Number of kiosks in pool
    static const int NUM_KIOSKS = 2;
};

#endif //LAUNDROMAT_LAUNDROMAT_H