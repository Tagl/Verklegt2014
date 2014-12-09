#pragma once

#include <string>
#include <fstream>
#include "Date.h"

enum wasMade {YES, NO, UNSPECIFIED};

std::istream& operator>>(std::istream& in, wasMade& m);
std::ostream& operator<<(std::ostream& out, wasMade& m);

class Computer
{
public:
    int id;
    std::string name, computerType;
    wasMade _wasMade;
    int yearBuilt;
    std::string description;

    Computer(const Computer& value);
    Computer(const std::string name = "Anonymous", const std::string computerType = "", const wasMade _wasMade = UNSPECIFIED, const int yearBuilt = 0, const std::string desc = "");

    const std::string getName();
    void setName(const std::string value);

    const std::string getComputerType();
    void setComputerType(const std::string value);

    const wasMade getWasMade();
    void setwasMade(const wasMade value);

    const int getYearBuilt();
    void setyearBuilt(const int value);

    const std::string getDescription();
    void setDescription(const std::string value);

    friend std::ostream& operator<<(std::ostream& out, Computer p);
    friend std::istream& operator>>(std::istream& out, Computer& p);
};
