#include "HouseNumber.h"

HouseNumber::HouseNumber(unsigned long hn):houseNumber(hn){}
HouseNumber::~HouseNumber(){}	
void HouseNumber::print (ostream& ostr) const{
	ostr << "House number " << this->houseNumber << "\n";
}