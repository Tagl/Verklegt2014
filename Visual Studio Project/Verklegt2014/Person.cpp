#include "Person.h"

Person::Person(const Person& value)
{
	this->firstname = value.firstname;
	this->surname = value.surname;
	this->gender = value.gender;
	this->dob = value.dob;
	this->dod = value.dod;
	this->description = value.description;
}


Person::Person(const std::string firstname, const std::string surname, const Gender gender, const Date dob, const Date dod, const std::string desc)
{
	this->firstname = firstname;
	this->surname = surname;
	this->gender = gender;
	this->dob = dob;
	this->dod = dod;
	this->description = desc;
}
	
const std::string Person::getFirstName()
{
	return firstname;
}
void Person::setFirstName(const std::string value)
{
	firstname = value == "" ? "Anonymous" : value;
}

const std::string Person::getSurname()
{
	return surname;
}
void Person::setSurname(const std::string value)
{
	surname = value;
}

const Gender Person::getGender()
{
	return gender;
}
void Person::setGender(const Gender value)
{
	gender = value;
}

const Date Person::getDoB()
{
	return dob;
}
void Person::setDoB(const Date value)
{
	dob = value;
}

const Date Person::getDoD()
{
	return dod;
}
void Person::setDoD(const Date value)
{
	dod = value;
}
	
const std::string Person::getDescription()
{
	return description;
}
void Person::setDescription(const std::string value)
{
	description = value;
}

std::istream& operator>>(std::istream& in, Gender& g)
{
	std::string s;
	in >> s;
	if(s == "M" || s == "m" || s == "Male") g = MALE;
	else if(s=="F" || s == "f" || s == "Female") g = FEMALE;
	else g = UNSPECIFIED;

	return in;
}

std::ostream& operator<<(std::ostream& out, Gender g)
{
	if(g == MALE) out << "Male";
	else if(g == FEMALE) out << "Female";
	else out << "Unspecified";

	return out;
}

std::ostream& operator<<(std::ostream& out, Person p)
{
	out << p.firstname << " " << p.surname << " " << p.gender << " " << p.dob << " " << p.dod << " \"" << p.description << "\"";
	return out;
}

std::istream& operator>>(std::istream& in, Person& p)
{
	in >> p.firstname >> p.surname >> p.gender >> p.dob >> p.dod;
	std::getline(in,p.description);
	return in;
}