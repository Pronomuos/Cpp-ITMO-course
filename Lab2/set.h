#pragma once

#ifndef PR_LAB2_SET_H
#define PR_LAB2_SET_H


class Set {
private:
    int *m_array;
    int m_max_el;
    int m_count ;

public:
    Set();
    Set(int);
    void deep_copy (const Set&);
    Set (const Set&);
    Set& operator= (const Set&);
    ~Set();
    bool find_el(int);
    void add_el (int);
    void remove_el (int);
    void remove_last_el ();
    Set set_union (Set&);
    Set intersection (Set&);
    friend Set operator-= (Set&, Set&);
    friend Set operator+= (Set&, Set&);
    void print ();
};


#endif //PR_LAB2_SET_H
