
#ifndef PR_LAB6_MYALGORITMS_H
#define PR_LAB6_MYALGORITMS_H

namespace my_algoritms {

    template<class Input, class Predicate>
    bool all_of(Input first, Input last, Predicate p) {
        while (first != last) {
            if (!p(*first++)) return false;
        }
        return true;
    }

    template<class Input, class Predicate>
    bool is_partitioned(Input first, Input last, Predicate p) {
        while (first != last)
            if (!p(*first++))
                break;
        while (first != last)
            if (p(*first++))
                return false;
        return true;
    }

    template<class Input, class Predicate>
    Input find_backward(Input first, Input last, Predicate p) {
        while (last != first) {
            if (p(*last--)) {
                return last;
            }
        }
        return first - 1;
    }
}

#endif //PR_LAB6_MYALGORITMS_H
