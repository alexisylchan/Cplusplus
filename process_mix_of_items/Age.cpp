#include "Age.h"

Age::Age(unsigned int ay): ageYears(ay){};

void Age::print (ostream& ostr) const {
	ostr << "Age " << this->ageYears << "\n";
}