
#include "IntQueue.h"


    IntQueue::IntQueue() {
    m_count = 0;
}

    IntQueue& operator<< (IntQueue& q, int num) {
        q.m_array[q.m_count] = num;
        q.m_count++;

        return q;
    }

    IntQueue& operator>> (IntQueue& q, int& num) {
        num = q.m_array[0];
        for (int i = 0; i < q.m_count; i++)
            q.m_array[i] = q.m_array[i+1];
        q.m_count--;

        return q;
    }
