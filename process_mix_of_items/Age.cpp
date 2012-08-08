#include "Age.h"


Age::Age(unsigned int ay): ageYears(ay){}
Age::~Age(){}
void Age::print (ostream& ostr) const {
	ostr << "Age " << this->ageYears << "\n";
}