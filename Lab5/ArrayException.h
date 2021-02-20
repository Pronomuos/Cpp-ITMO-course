#pragma once
#include <iostream>

#ifndef PR_LAB5_ARRAYEXCEPTION_H
#define PR_LAB5_ARRAYEXCEPTION_H


class ArrayException: public std::exception {
private:
    std::string m_error;

public:
    ArrayException(std::string);

    const char* what() const noexcept override;
};



#endif //PR_LAB5_ARRAYEXCEPTION_H
