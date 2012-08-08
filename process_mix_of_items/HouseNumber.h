#include "Data.h"

class HouseNumber : public Data {
	unsigned long houseNumber;
public:
	HouseNumber(unsigned long hn);
	~HouseNumber();
protected:	
	virtual void print (ostream& ostr) const;
};