#ifndef WORLD_AFTER_CORE_ARRAY_H
#define WORLD_AFTER_CORE_ARRAY_H

#include "primitive.h"

template<typename T, size_t size>
class waArray
{

public:

    T data[size];

    waArray() = default;
    waArray(const T* array, size_t arraySize);
    waArray(const waArray& copy);
    waArray(waArray&& move);

public:

    


};

#endif /* WORLD_AFTER_CORE_ARRAY_H */