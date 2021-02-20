#pragma once

#ifndef PR_LAB3_INTQUEUE_H
#define PR_LAB3_INTQUEUE_H


class IntQueue {
private:
    int m_max;
    int m_array[100];
    int m_count;
public:
    IntQueue ();

    friend IntQueue& operator<< (IntQueue&, int);
    friend IntQueue& operator>> (IntQueue&, int&);
};


#endif //PR_LAB3_INTQUEUE_H
