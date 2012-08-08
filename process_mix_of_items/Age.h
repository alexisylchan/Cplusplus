#include "Data.h"

class Age : public Data {
	unsigned int ageYears;
public:
	Age(unsigned int ay); 
	~Age();
protected:
	virtual void print (ostream& ostr) const;
};