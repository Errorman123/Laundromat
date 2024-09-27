#include <pthread.h>
#include <optional>
#include <iostream>
#include <stdexcept>

/// ObjPool constructor that takes a vector of objects.
/// \tparam T type of objects in pool
/// \param objects vector of objects
template <class T>
ObjPool<T>::ObjPool(std::vector<T> objects) {
    this->objects = objects;
    initMutex();
}

/// Initializes the mutex lock.
/// \tparam T type of objects in pool
template <class T>
void ObjPool<T>::initMutex(){
    int initResult = pthread_mutex_init(&p_mutex, NULL);
    if (initResult != 0){
        std::cout << "\np_mutex init has failed!" << std::endl;
        throw std::runtime_error("ObjPool() cannot initialize p_mutex, errno: " + initResult);
    }
}

/// Removes an object from the pool and returns it.
/// \tparam T type of object in pool
/// \return Object from pool
template <class T>
std::optional<T> ObjPool<T>::getObject(){
    std::optional<T> result;

    /// Locks access to the pool
    int lockResult = pthread_mutex_lock(&p_mutex);
    if ( lockResult == 0) {
        if (!objects.empty()){
            result = objects.back();
            objects.pop_back();
        } else {
            result = std::nullopt;
        }
    } else {
        //TODO:Exception check on failed lock
        std::cout << "Locking error obtaining object! Error number: " << lockResult << std::endl;
        result = std::nullopt;
    }
    int unlockResult = pthread_mutex_unlock(&p_mutex);
    return result;
}

/// Returns object in param to pool.
/// \tparam T type of object to return to pool
/// \param object object to be returned to pool.
/// \return true on success, false on failure.
template <class T>
bool ObjPool<T>::returnObjToPool(T object){
    bool result;
    int lockResult = pthread_mutex_lock(&p_mutex);
    if (lockResult == 0) {
        objects.push_back(object);
        result = true;
    } else {
        //TODO:Exception check on failed lock
        std::cout << "Locking error returning object! Error number: " << lockResult << std::endl;
        result = false;
    }
    int unlockResult = pthread_mutex_unlock(&p_mutex);
    return result;
}

