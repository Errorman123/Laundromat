#pragma once
#ifndef LAUNDROMAT_KIOSK_H
#define LAUNDROMAT_KIOSK_H

#include "Washer.h"
#include "Dryer.h"
#include <optional>
#include <vector>

/// Forward declaration of Laundromat class
class Laundromat;

/// Provides laundry service to a customer
/// that allows customer to receive washer or dryer.
class Kiosk {
public:

    /// Constructor with laundromat field
    /// \param l laundromat
    Kiosk(Laundromat *l);

    /// Asks user whether they want a washer or a dryer.
    /// Retrieves first available washer/dryer from the corresponding pool.
    /// Returns itself to its object pool.
    /// Starts washing/drying accordingly.
    /// Returns washer/dryer back to pool after the washing or drying is done.
    /// Only one thread at a time can access the Kiosk because the method
    /// getObject<Kiosk>() of the Kiosk pool is protected by a mutex lock
    /// and when a Kiosk is given to the user it is removed from the pool.
    void GetLaundryService();

    /// Returns first available Washer.
    /// \return Washer
    std::optional<Washer> getWasher();

    /// Returns first available Dryer.
    /// \return Dryer
    std::optional<Dryer> getDryer();

private:
    /// Pointer to an object of laundromat class
    Laundromat *l;
};


#endif //LAUNDROMAT_KIOSK_H
