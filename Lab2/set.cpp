#include <iostream>
#include "set.h"


    Set::Set() {
        m_count = 0;
        m_max_el = 5;
        m_array = new int [m_max_el] {};
}

    Set::Set(int max_el): m_max_el(max_el) {
        m_count = 0;
        m_array = new int [m_max_el] {};
    }

    void Set::deep_copy (const Set& set) {
        delete [] m_array;
        m_count = set.m_count;
        m_max_el = set.m_max_el;
        if (set.m_array) {
            m_array = new int[m_max_el];
            for (int i = 0; i < m_count; i++) {
                m_array[i] = set.m_array[i];
            }
        }
        else {
            m_array = nullptr;
        }
    }

    Set::Set (const Set& set) {
        m_array = nullptr;
        deep_copy(set);
    }

    Set& Set::operator= (const Set& set) {
        if (this == &set)
            return *this;

        deep_copy(set);

        return * this;
    }

    Set::~Set()
    {
        delete [] m_array;
    }

    bool Set::find_el(int element) {
        for (int i = 0; i < m_count; i++){
            if (m_array[i] == element)
                return true;
        }
        return false;
    }

    void Set::add_el (int element) {
        if (m_max_el > m_count) {
            if (!find_el(element)) {
                m_array[m_count] = element;
                m_count++;
            }
        } else {
            std::cout << "В множестве нет места.\n";
        }
    }

    void Set::remove_el (int element) {
    if (m_count > 0) {
        bool el_exists = false;
        for (int i = 0; i < m_count; i++)
                if (m_array[i] == element) {
                    for (int j = i; j < m_count; j++) {
                        m_array[j] = m_array[j + 1];
                        el_exists = true;
                    }
                    m_count--;
                }
            } else
                std::cout << "В множестве нет элементов.\n";
    }

    void Set::remove_last_el () {
    if (m_count > 0)
        m_count--;
    else
        std::cout << "В множестве нет элементов.\n";
    }

    Set Set::set_union (Set& set) {
        Set s_union (m_count + set.m_count);
        for (int i = 0; i < m_count; i++)
            s_union.add_el(m_array[i]);
        for (int i = 0; i < set.m_count; i++)
            s_union.add_el(set.m_array[i]);

        return s_union;
    }

    Set Set::intersection (Set& set) {
        Set inter_set (m_max_el);
        for (int i = 0; i < m_count; i++)
            if (set.find_el(m_array[i]))
                inter_set.add_el(m_array[i]);

        return inter_set;
    }

    Set operator-= (Set& set1, Set& set2) {
        for (int i = 0; i < set1.m_count; i++)
            set1.remove_el(set2.m_array[i]);

        return set1;
    }

    Set operator+= (Set& set1, Set& set2) {
        if (set1.m_count + set2.m_count < set1.m_max_el)
            for (int i = 0; i < set2.m_count; i++)
                set1.add_el(set2.m_array[i]);

        else {
            Set set_temp (set1.set_union(set2));
            set1 = set_temp;
        }

        return set1;
    }

    void Set::print () {
        if (m_count > 0) {
            for (int i = 0; i < m_count; i++) {
                std::cout << m_array[i] << " ";
            }
            std::cout << '\n';
        } else {
            std::cout << "нет элементов.\n";
        }
    }

