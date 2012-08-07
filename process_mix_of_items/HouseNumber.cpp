#include "HouseNumber.h"

HouseNumber::HouseNumber(unsigned long hn):houseNumber(hn){};
	
void HouseNumber::print (ostream& ostr) const{
	ostr << "House number " << this->houseNumber << "\n";
}