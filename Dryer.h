#ifndef LAUNDROMAT_DRYER_H
#define LAUNDROMAT_DRYER_H

#include "pthread.h"

/// Class represents Dryer.
/// Only one thread at a time can access the Washer because the method
/// getObject<Dryer>() of the Dryer pool is protected by a mutex lock
/// and when a Dryer is given to the user it is removed from the pool.
class Dryer{
public:
    /// Default constructor
    Dryer();

    /// Executes drying job.
    void dry();

    /// Time to dry in milliseconds
    static const int DRY_TIME = 5000;
};


#endif //LAUNDROMAT_DRYER_H