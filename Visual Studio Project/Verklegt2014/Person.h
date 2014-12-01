#pragma once

#include <string>
#include <fstream>
#include "Date.h"


enum Gender { UNSPECIFIED, MALE, FEMALE };

class Person
{
private:
	std::string firstname, surname;
	Gender gender;
	Date dob, dod; // Date of Birth, Date of Death
	std::string description;
public:
	Person(const Person& value);
	Person(const std::string firstname = "Anonymous", const std::string surname = "", const Gender gender = Gender::UNSPECIFIED, const Date dob = Date(), const Date dod = Date(), const std::string desc = "");
	
	std::string getFirstName();
	void setFirstName(const std::string value);
	
	std::string getSurname();
	void setSurname(const std::string value);

	Gender getGender();
	void setGender(const Gender value);

	Date getDoB();
	void setDoB(const Date value);

	Date getDoD();
	void setDoD(const Date value);
	
	std::string getDescription();
	void setDescription(const std::string value);

	friend std::istream& operator>>(std::istream& in, Gender& g);
	friend std::ostream& operator<<(std::ostream& out, Gender g);
};