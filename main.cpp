#include <iostream>
#include <pthread.h>
#include <vector>
#include <string.h>//strerror()

#include "Kiosk.h"
#include "Dryer.h"
#include "Washer.h"
#include "Laundromat.h"
#include "Customer.h"


void* runThread(void* arg);

/// Creates threads of customers.
/// Each thread runs the function that requests service from a laundromat.
/// The laundromat keeps pools of washers, dryers, and kiosks.
/// User can acquire a kiosk object from the laundromat service.
/// The user then acquires a washer or dryer via the kiosk
/// and calls the washer's wash() or dryer's dry() methods.
/// The pools of washers, dryers, or kiosks synchronize access to them.
/// Only one thread at a time can get access to the pool to
/// retrieve from and return objects to the pool.
/// When an object is retrieved by a thread it is removed from the pool
/// So no other threads may access that object, creating a race condition.
/// \return 0
int main(){
    static const int NUM_THREADS = 2;

    Laundromat l;

    pthread_t tid[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++){
        Customer* customer = new Customer(l);

        int error = pthread_create(&(tid[i]),
                                   NULL,
                                   &runThread, customer);
        if (error != 0)
            printf("\nThread can't be created :[%s]",
                   strerror(error));


    }

    for(int i = 0; i < NUM_THREADS; i++){
        pthread_join(tid[i], NULL);
    }

    std::cout << "program finished" << std::endl;

    return 0;
}

/// The run method of the thread.
/// Receives customer as a param and calls the doLaundry() method on it.
/// \param arg pointer to customer object
/// \return NULL to avoid warning
void* runThread(void* arg){
    Customer* customer = (Customer*) arg;

    customer->doLaundry();

    return NULL;
}
