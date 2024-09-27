#include <iostream>
#include <Windows.h>

#include "Dryer.h"

/// Default constructor
Dryer::Dryer() {}

/// Executes drying job.
void Dryer::dry() {
    std::cout << "Starting to dry!" << std::endl;
    Sleep(DRY_TIME);
    std::cout << "Finished drying!" << std::endl;
}