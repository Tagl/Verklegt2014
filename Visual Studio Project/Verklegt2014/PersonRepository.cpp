#include <algorithm>
#include <fstream>
#include "PersonRepository.h"

PersonRepository::PersonRepository()
{
	people = std::vector<Person>();
}

bool PersonRepository::load(const std::string file)
{
	std::ifstream in;
	in.open(file, std::ios_base::in);
	if(in.is_open())
	{
		people.clear();
		while(!in.eof())
		{
			Person p;
			in >> p;
			add(p);
		}
		in.close();
		return true;
	}
	else return false;
}

bool PersonRepository::save(const std::string file)
{
	std::ofstream out;
	out.open(file, std::ios_base::out);
	if(out.is_open())
	{
		for (size_t i = 0; i < people.size(); i++)
		{
			if(i!=0) out << std::endl;
			out << people.at(i);
		}
		out.close();
		return true;
	}
	else return false;
}

std::vector<Person> PersonRepository::search(const std::string sq)
{
	std::vector<Person> peepz = std::vector<Person>();
	for (size_t i = 0; i < people.size(); i++)
	{
		Person p = people.at(i);
		if(p.firstname.find(sq) != -1 || p.surname.find(sq) != -1 || p.description.find(sq) != -1)
		{
			peepz.push_back(p);
		}
	}

	return peepz;
}

std::vector<Person> PersonRepository::getPeople(const SortTypes st, const Order o, std::string sq)
{
	std::vector<Person> peepz; // the vector to return

	if(sq != "") peepz = search(sq); // if there is a search query then we search
	else peepz = std::vector<Person>(people); // otherwise get all the people
	
	switch (st)
	{
	case NOTHING:
		if(o==DESCENDING) std::reverse(peepz.begin(), peepz.end());
	case FIRSTNAME:
		if(o == ASCENDING)
			std::sort(peepz.begin(), peepz.end(), [](const Person& p, const Person& q){ return p.firstname < q.firstname; });
		else
			std::sort(peepz.begin(), peepz.end(), [](const Person& p, const Person& q){ return p.firstname > q.firstname; });
		break;
	case SURNAME:
		if(o == ASCENDING)
			std::sort(peepz.begin(), peepz.end(), [](const Person& p, const Person& q){ return p.surname < q.surname; });
		else
			std::sort(peepz.begin(), peepz.end(), [](const Person& p, const Person& q){ return p.surname > q.surname; });
		break;
	case GENDER:
		if(o == ASCENDING)
			std::sort(peepz.begin(), peepz.end(), [](const Person& p, const Person& q){ return p.gender < q.gender; });
		else
			std::sort(peepz.begin(), peepz.end(), [](const Person& p, const Person& q){ return p.gender > q.gender; });
		break;
	case DOB:
		if(o == ASCENDING)
			std::sort(peepz.begin(), peepz.end(), [](const Person& p, const Person& q){ return p.dob < q.dob; });
		else
			std::sort(peepz.begin(), peepz.end(), [](const Person& p, const Person& q){ return p.dob > q.dob; });
		break;
	case DOD:
		if(o == ASCENDING)
			std::sort(peepz.begin(), peepz.end(), [](const Person& p, const Person& q){ return p.dod < q.dod; });
		else
			std::sort(peepz.begin(), peepz.end(), [](const Person& p, const Person& q){ return p.dod > q.dod; });
		break;
	default:
		break;
	}

	return peepz;
}

void PersonRepository::add(Person p)
{
	people.push_back(p);
}

const std::string PersonRepository::sortNames[] = {"Nothing", "First name", "Surname", "Gender", "Date of birth", "Date of death"};

std::ostream& operator<<(std::ostream& out, SortTypes st)
{
	out << PersonRepository::sortNames[(int)st];
	return out;
}

std::ostream& operator<<(std::ostream& out, Order o)
{
	out << (o == ASCENDING ? "Ascending" : "Descending");
	return out;
}