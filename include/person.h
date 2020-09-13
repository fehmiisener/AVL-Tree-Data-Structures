#ifndef person_H
#define person_H	


#include <string>
class person
{
private:
    std::string namePerson;
    int birthDayPerson;
    int weightPerson;
	
public:
	int agePerson;
    	person(const std::string& name, int birthDay, int weight);	
	void showPerson();
};

#endif