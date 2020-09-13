#include "../include/person.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

person::person(const std::string& name, int birthDay, int weight)
{
    namePerson=name;
    birthDayPerson=birthDay;
    weightPerson=weight;
	agePerson=2020-birthDay;
}
void person::showPerson(){
	cout<<namePerson;
	cout<<", "<<birthDayPerson;
	cout<<", "<<weightPerson;
}
 

