#pragma once

#include <string>
#include <fstream>
#include "Date.h"

enum WasMade {YES, NO, MAYBE};

std::istream& operator>>(std::istream& in, WasMade& m);
std::ostream& operator<<(std::ostream& out, WasMade& m);

class Computer
{
public:
    int id;
    std::string name, computerType;
    WasMade wasMade;
    int yearBuilt;
    std::string description;

    Computer(const Computer& value);
    Computer(const std::string name = "Anonymous", const std::string computerType = "", const WasMade wasMade = MAYBE, const int yearBuilt = 0, const std::string desc = "");

    const std::string getName();
    void setName(const std::string value);

    const std::string getComputerType();
    void setComputerType(const std::string value);

    const WasMade getWasMade();
    void setWasMade(const WasMade value);

    const int getYearBuilt();
    void setYearBuilt(const int value);

    const std::string getDescription();
    void setDescription(const std::string value);

    friend std::ostream& operator<<(std::ostream& out, Computer p);
    friend std::istream& operator>>(std::istream& out, Computer& p);
};
