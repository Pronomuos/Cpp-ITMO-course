#pragma once
#include "ArrayException.h"

#ifndef PR_LAB5_STATICARRAY_H
#define PR_LAB5_STATICARRAY_H

template <class T, int size>
class StaticArray
{
private:
    T m_array[size] {};

public:
    T& operator[](const int index)
    {
        if (index < 0 || index >= size)
            throw ArrayException("Invalid index");

        return m_array[index];
    }
};

#endif //PR_LAB5_STATICARRAY_H
