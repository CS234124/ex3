//
// Created by User on 21/05/2022.
//

#include "HealthPoints.h"

const int NO_HEALTH_POINTS = 0;

HealthPoints::HealthPoints(const int maxHealthPoints) :
        m_maxHealthPoints(maxHealthPoints), m_healthPoints(maxHealthPoints) {
    if (maxHealthPoints <= NO_HEALTH_POINTS) {
        throw InvalidArgument();
    }
}

HealthPoints &HealthPoints::operator=(const HealthPoints &other) {
    if (this != &other) {
        m_maxHealthPoints = other.m_maxHealthPoints;
        m_healthPoints = other.m_healthPoints;
    }
    return *this;
}

HealthPoints &HealthPoints::operator-=(const int &subtrahend) {
    *this += -subtrahend;
    return *this;
}

HealthPoints HealthPoints::operator-(const int &subtrahend) const {
    HealthPoints resultHealthPoints = *this;
    resultHealthPoints -= subtrahend;
    return resultHealthPoints;
}

HealthPoints &HealthPoints::operator+=(const int &addend) {
    m_healthPoints += addend;
    if (m_healthPoints < 0) {
        m_healthPoints = 0;
    }
    if (m_healthPoints > m_maxHealthPoints) {
        m_healthPoints = m_maxHealthPoints;
    }
    return *this;
}

HealthPoints HealthPoints::operator+(const int addend) const {
    HealthPoints resultHealthPoints = *this;
    resultHealthPoints += addend;
    return resultHealthPoints;
}

bool HealthPoints::operator==(const HealthPoints &other) const {
    return m_healthPoints == other.m_healthPoints;
}

bool HealthPoints::operator!=(const HealthPoints &other) const {
    return m_healthPoints != other.m_healthPoints;
}

bool HealthPoints::operator>(const HealthPoints &other) const {
    return m_healthPoints > other.m_healthPoints;
}

bool HealthPoints::operator>=(const HealthPoints &other) const {
    return m_healthPoints >= other.m_healthPoints;
}

bool HealthPoints::operator<(const HealthPoints &other) const {
    return m_healthPoints < other.m_healthPoints;
}

bool HealthPoints::operator<=(const HealthPoints &other) const {
    return m_healthPoints <= other.m_healthPoints;
}

HealthPoints operator+(int addend, const HealthPoints &healthPoints) {
    return healthPoints + addend;
}

bool operator==(const int &comparedNum, const HealthPoints &comparedHealthPoints) {
    return comparedHealthPoints == comparedNum;
}

bool operator!=(const int &comparedNum, const HealthPoints &comparedHealthPoints) {
    return comparedHealthPoints != comparedNum;
}

bool operator>(const int &comparedNum, const HealthPoints &comparedHealthPoints) {
    return comparedHealthPoints < comparedNum;
}

bool operator>=(const int &comparedNum, const HealthPoints &comparedHealthPoints) {
    return comparedHealthPoints <= comparedNum;
}

bool operator<(const int &comparedNum, const HealthPoints &comparedHealthPoints) {
    return comparedHealthPoints > comparedNum;
}

bool operator<=(const int &comparedNum, const HealthPoints &comparedHealthPoints) {
    return comparedHealthPoints >= comparedNum;
}


std::ostream &operator<<(std::ostream &os, const HealthPoints &healthPoints) {
    os << healthPoints.m_healthPoints << "(" << healthPoints.m_maxHealthPoints << ")";
    return os;
}
