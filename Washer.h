#ifndef LAUNDROMAT_WASHER_H
#define LAUNDROMAT_WASHER_H

#include "pthread.h"

/// Class represents Washer.
/// Only one thread at a time can access the Washer because the method
/// getObject<Washer>() of the Washer pool is protected by a mutex lock
/// and when a Washer is given to the user it is removed from the pool.
class Washer {
public:
    /// Default constructor
    Washer();

    /// Executes washing job.
    void wash();

    /// Time to wash in milliseconds
    static const int WASH_TIME = 5000;
};

#endif //LAUNDROMAT_WASHER_H