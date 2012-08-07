#ifndef __Data_h
#define __Data_h

#include <iostream>

using std::ostream;

class Data {
public:
	friend ostream& operator <<(ostream& ostr, const Data& other);
protected:
	virtual void print(ostream& ostr) const = 0;
};

inline ostream& operator <<(ostream& ostr, const Data& other) {
	other.print(ostr);
	return ostr;
}
#endif