#ifndef LAUNDROMAT_CUSTOMER_H
#define LAUNDROMAT_CUSTOMER_H

#include "Laundromat.h"

/// Customer class does laundry.
class Customer {
public:
    /// Constructs a customer object with a laundromat param.
    /// \param l laundromat
    Customer( Laundromat l) {this->l = l;}

    /// Gets available kiosk from laundromat and calls GetLaundryService() on it.
    void doLaundry();

private:
    /// Instance of laundromat class.
    Laundromat l;
};


#endif //LAUNDROMAT_CUSTOMER_H
