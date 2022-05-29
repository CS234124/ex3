//
// Created by Itamar on 21/05/2022.
//

#ifndef MTM_EX3_HEALTHPOINTS_H
#define MTM_EX3_HEALTHPOINTS_H

#include <iostream>

const int DEFAULT_MAX_HEALTH_POINTS = 100;

class HealthPoints {
private:
    int m_maxHealthPoints;
    int m_healthPoints;
public:
    HealthPoints(int maxHealthPoints = DEFAULT_MAX_HEALTH_POINTS);

    HealthPoints &operator=(const HealthPoints &other);

    HealthPoints(const HealthPoints &other) = default;

    ~HealthPoints() = default;

    HealthPoints &operator-=(const int &subtrahend);

    HealthPoints operator-(const int &subtrahend) const;

    HealthPoints &operator+=(const int &addend);

    HealthPoints operator+(int addend) const;

    bool operator==(const HealthPoints &other) const;

    bool operator!=(const HealthPoints &other) const;

    bool operator>(const HealthPoints &other) const;

    bool operator>=(const HealthPoints &other) const;

    bool operator<(const HealthPoints &other) const;

    bool operator<=(const HealthPoints &other) const;

    friend std::ostream &operator<<(std::ostream &os, const HealthPoints &healthPoints);

    class InvalidArgument {
    };
};

HealthPoints operator+(int addend, const HealthPoints &healthPoints);

bool operator==(const int &comparedNum, const HealthPoints &comparedHealthPoints);

bool operator!=(const int &comparedNum, const HealthPoints &comparedHealthPoints);

bool operator>(const int &comparedNum, const HealthPoints &comparedHealthPoints);

bool operator>=(const int &comparedNum, const HealthPoints &comparedHealthPoints);

bool operator<(const int &comparedNum, const HealthPoints &comparedHealthPoints);

bool operator<=(const int &comparedNum, const HealthPoints &comparedHealthPoints);

#endif //MTM_EX3_HEALTHPOINTS_H
