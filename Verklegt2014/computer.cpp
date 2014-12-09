#include "computer.h"

Computer::Computer(const Computer& value)
{
    this->id = value.id;
    this->name = value.name;
    this->computerType = value.computerType;
    this->_wasMade = value._wasMade;
    this->yearBuilt = value.yearBuilt;
    this->description = value.description;
}


Computer::Computer(const std::string name, const std::string computerType, const wasMade _wasMade, const int yearBuilt, const std::string desc)
{
    this->name = name;
    this->computerType = computerType;
    this->_wasMade = _wasMade;
    this->yearBuilt = yearBuilt;
    this->description = desc;
}

const std::string Computer::getName()
{
    return name;
}
void Computer::setName(const std::string value)
{
    name = value == "" ? "Anonymous" : value;
}

const std::string Computer::getComputerType()
{
    return computerType;
}
void Computer::setComputerType(const std::string value)
{
    computerType = value;
}

const wasMade Computer::getWasMade()
{
    return _wasMade;
}
void Computer::setwasMade(const wasMade value)
{
    _wasMade = value;
}

const int Computer::getYearBuilt()
{
    return yearBuilt;
}
void Computer::setyearBuilt(const int value)
{
    yearBuilt = value;
}

const std::string Computer::getDescription()
{
    return description;
}
void Computer::setDescription(const std::string value)
{
    description = value;
}

std::istream& operator>>(std::istream& in, wasMade& m)
{
    std::string s;
    in >> s;
    if(s == "Y" || s == "y" || s == "Yes") m = YES;
    else if(s=="N" || s == "n" || s == "No") m = NO;
    else m = UNSPECIFIED;

    return in;
}

std::ostream& operator<<(std::ostream& out, wasMade& m)
{
    if(m == YES) out << "Yes";
    else if(m == NO) out << "No";
    else out << "Unspecified";

    return out;
}

std::ostream& operator<<(std::ostream& out, Computer c)
{
    out << c.name << " " << c.computerType << " " << c._wasMade << " " << c.yearBuilt << " " << c.description;
    return out;
}

std::istream& operator>>(std::istream& in, Computer& c)
{
    in >> c.name >> c.computerType >> c._wasMade >> c.yearBuilt;
    std::getline(in,c.description);
    return in;
}
