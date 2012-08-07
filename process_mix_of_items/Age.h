#include "Data.h"

class Age : public Data {
	unsigned int ageYears;
public:
	Age(unsigned int ay); 
protected:
	virtual void print (ostream& ostr) const;
};