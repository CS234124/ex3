//
// Created by Itamar on 21/05/2022.
//

#ifndef MTM_EX3_HEALTHPOINTS_H
#define MTM_EX3_HEALTHPOINTS_H

#include <iostream>

const int DEFAULT_MAX_HEALTH_POINTS = 100;

class HealthPoints {
private:
    ///Maximum Health Points allowed
    int m_maxHealthPoints;
    ///Current Health Points
    int m_healthPoints;
public:
    HealthPoints(int maxHealthPoints = DEFAULT_MAX_HEALTH_POINTS);

    /// Assignment operator for HP. Copies both the current and the max HPs.
    /// \param other HP object to copy
    /// \return this HP object
    HealthPoints &operator=(const HealthPoints &other);

    HealthPoints(const HealthPoints &other) = default;

    ~HealthPoints() = default;

    /// Minus assignment operator to subtract HP from the current object.
    /// Minimum HP possible is 0
    /// \param subtrahend number of HP to subtract.
    /// \return This HP object, after subtraction.
    HealthPoints &operator-=(const int &subtrahend);

    /// Minus operator to subtract HP from the current object (not modifying this object).
    /// Minimum HP possible is 0
    /// \param subtrahend number of HP to subtract.
    /// \return New HP object, after subtraction.
    HealthPoints operator-(const int &subtrahend) const;

    /// Plus assignment operator to add HP to the current object.
    /// Maximum HP possible is m_maxHP
    /// \param addend number of HP to add.
    /// \return This HP object, after addition.
    HealthPoints &operator+=(const int &addend);

    /// Plus operator to add HP to the current object (not modifying this object).
    /// Maximum HP possible is m_maxHP
    /// \param addend number of HP to add.
    /// \return New HP object, after addition.
    HealthPoints operator+(int addend) const;

    /// Equals operator between HP objects or HP object and int.
    /// Compares the current HPs of the objects.
    /// \param other HP object to compare to
    /// \return True if current health points of the objects are equal, False otherwise.
    bool operator==(const HealthPoints &other) const;

    /// Not Equals operator between HP objects or HP object and int.
    /// Compares the current HPs of the objects.
    /// \param other HP object to compare to
    /// \return True if current health points of the objects are different, False otherwise.
    bool operator!=(const HealthPoints &other) const;

    /// "Larger Than" operator between HP objects or HP object and int.
    /// Compares the current HPs of the objects.
    /// \param other HP object to compare to
    /// \return True if this object's current HP is larger than the other's, False otherwise.
    bool operator>(const HealthPoints &other) const;

    /// "Larger Than or Equals" operator between HP objects or HP object and int.
    /// Compares the current HPs of the objects.
    /// \param other HP object to compare to
    /// \return True if this object's current HP is larger than or equals the other's, False otherwise.
    bool operator>=(const HealthPoints &other) const;

    /// "Less Than" operator between HP objects or HP object and int.
    /// Compares the current HPs of the objects.
    /// \param other HP object to compare to
    /// \return True if this object's current HP is less than the other's, False otherwise.
    bool operator<(const HealthPoints &other) const;

    /// "Less Than or Equals" operator between HP objects or HP object and int.
    /// Compares the current HPs of the objects.
    /// \param other HP object to compare to
    /// \return True if this object's current HP is less than or equals the other's, False otherwise.
    bool operator<=(const HealthPoints &other) const;

    /// Concat/Print operator for HP. Prints as "<currentHP> (<maxHP>)"
    /// \param os ostream to concat to.
    /// \param healthPoints HP object to concat.
    /// \return ostream after concatenation.
    friend std::ostream &operator<<(std::ostream &os, const HealthPoints &healthPoints);

    ///Exception class for invalid arguments for the max HP
    class InvalidArgument {
    };
};

///Plus operator to add Health Points to given HP object using LHS int (not modifying this object).
HealthPoints operator+(int addend, const HealthPoints &healthPoints);

///Equals operator between HP object and int using LHS int.
bool operator==(const int &comparedNum, const HealthPoints &comparedHealthPoints);

/// Not Equals operator between HP object and int using LHS int.
bool operator!=(const int &comparedNum, const HealthPoints &comparedHealthPoints);

/// "Larger Than" operator between HP object and int using LHS int.
bool operator>(const int &comparedNum, const HealthPoints &comparedHealthPoints);

/// "Larger Than or Equals" operator between HP object and int using LHS int.
bool operator>=(const int &comparedNum, const HealthPoints &comparedHealthPoints);

/// "Less Than" operator between HP object and int using LHS int.
bool operator<(const int &comparedNum, const HealthPoints &comparedHealthPoints);

/// "Less Than or Equals" operator between HP object and int using LHS int.
bool operator<=(const int &comparedNum, const HealthPoints &comparedHealthPoints);

#endif //MTM_EX3_HEALTHPOINTS_H
