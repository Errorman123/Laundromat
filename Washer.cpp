#include <iostream>
#include <Windows.h>

#include "Washer.h"

/// Default constructor
Washer::Washer(){}

/// Executes washing job.
void Washer::wash(){
    std::cout << "Starting to wash!" << std::endl;
    /// Puts a thread to sleep for WASH_TIME milliseconds.
    Sleep(WASH_TIME);
    std::cout << "Finished washing!" << std::endl;
}
