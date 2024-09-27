#ifndef LAUNDROMAT_OBJPOOL_H
#define LAUNDROMAT_OBJPOOL_H

#include <pthread.h>
#include <vector>
#include <optional>
#include <string>

/// Template class that represents a pool of objects.
/// Methods of this class are protected by a mutex.
/// Only one thread at a time can access the methods of this class.
/// Objects are removed from the pool when they are requested by the method getObject().
/// The method getObject() removes objects from the pool
/// so that only one thread may access the object.
/// \tparam T type of object in the pool
template <class T>
class ObjPool {
public:
    /// Default constructor
    ObjPool(){}

    /// ObjPool constructor that takes a vector of objects.
    /// \tparam T type of objects in pool
    /// \param objects vector of objects
    ObjPool(std::vector<T> objects);

    /// Removes an object from the pool and returns it.
    /// \tparam T type of object in pool
    /// \return Object from pool
    std::optional<T> getObject();

    /// Returns object in param to pool.
    /// \tparam T type of object to return to pool
    /// \param object object to be returned to pool.
    /// \return true on success, false on failure.
    bool returnObjToPool(T object);

    /// Returns size of pool.
    /// \return size of pool.
    int getSize(){return objects.size();}
private:
    /// Initializes the mutex lock.
    /// \tparam T type of objects in pool
    void initMutex();

    /// Mutex lock for pool.
    pthread_mutex_t p_mutex;
    /// Pool of objects.
    std::vector<T> objects;
};

#include "ObjPool_impl.h"

#endif //LAUNDROMAT_OBJPOOL_H
