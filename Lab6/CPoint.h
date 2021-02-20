
#ifndef PR_LAB6_CPOINT_H
#define PR_LAB6_CPOINT_H


class CPoint {
public:
    CPoint (int, int);
    friend bool operator> (const CPoint&, int);
    int get_x();
    int get_y();
private:
    int m_x;
    int m_y;
};


#endif //PR_LAB6_CPOINT_H
