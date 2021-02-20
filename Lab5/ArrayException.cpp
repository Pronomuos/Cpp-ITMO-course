#include "ArrayException.h"


    ArrayException::ArrayException(std::string error)
            : m_error(error) {}

    const char* ArrayException::what() const noexcept {

        return m_error.c_str();
    }
