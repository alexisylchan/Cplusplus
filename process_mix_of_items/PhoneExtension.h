#include "Data.h"

class PhoneExtension : public Data {
	unsigned int areaCode;
	unsigned long sevenDigitNumber;
public:
	PhoneExtension(unsigned int ac, unsigned long sdn);
	~PhoneExtension();
protected:
	virtual void print (ostream& ostr) const;	
};

