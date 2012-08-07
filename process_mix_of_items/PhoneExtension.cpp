#include "PhoneExtension.h"

PhoneExtension::PhoneExtension(unsigned int ac, unsigned long sdn):areaCode(ac),sevenDigitNumber(sdn){};

void PhoneExtension::print (ostream& ostr) const {
	ostr << "Phone extension (" << this->areaCode << ") " << this->sevenDigitNumber << "\n";
}