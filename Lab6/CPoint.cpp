#pragma once
#include "CPoint.h"

    CPoint::CPoint (int x, int y) : m_x (x), m_y (y) {}

    int CPoint::get_x() {
        return m_x;
    }

    int CPoint::get_y() {
        return m_y;
    }

    bool operator> (const CPoint& point, int num) {
        return point.m_x > num && point.m_y > num;
}