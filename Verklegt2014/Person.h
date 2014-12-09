#pragma once

#include <string>
#include <fstream>
#include "Date.h"

enum Gender { UNSPECIFIED, MALE, FEMALE };

std::istream& operator>>(std::istream& in, Gender& g);
std::ostream& operator<<(std::ostream& out, Gender g);

class Person
{
public:
    int id;
	std::string firstname, surname;
	Gender gender;
	Date dob, dod; // Date of Birth, Date of Death
	std::string description;

	Person(const Person& value);
    Person(const std::string firstname = "Anonymous", const std::string surname = "", const Gender gender = UNSPECIFIED, const Date dob = Date(), const Date dod = Date(), const std::string desc = "");
	
	const std::string getFirstName();
	void setFirstName(const std::string value);
	
	const std::string getSurname();
	void setSurname(const std::string value);

	const Gender getGender();
	void setGender(const Gender value);

	const Date getDoB();
	void setDoB(const Date value);

	const Date getDoD();
	void setDoD(const Date value);
	
	const std::string getDescription();
	void setDescription(const std::string value);

	friend std::ostream& operator<<(std::ostream& out, Person p);
	friend std::istream& operator>>(std::istream& out, Person& p);
};
