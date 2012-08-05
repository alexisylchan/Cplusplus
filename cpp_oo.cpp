#include <iostream>
#include <vector>
#include <string>

using std::ostream;
using std::vector;

// type : phone extension , age , house_number
// phone extension : id, area code , seven digit number
// age : id, years
// house number : id,  number

class Data {
public:
	friend ostream& operator <<(ostream& ostr, const Data& other);
protected:
	virtual void print(ostream& ostr) const{
	};
};
inline ostream& operator <<(ostream& ostr, const Data& other) {
	other.print(ostr);
	return ostr;
}
class PhoneExtension : public Data {
	unsigned int areaCode;
	unsigned long sevenDigitNumber;
public:
	PhoneExtension(unsigned int ac, unsigned long sdn):areaCode(ac),sevenDigitNumber(sdn){};
protected:
	virtual void print (ostream& ostr) const{
		ostr << "Phone extension (" << this->areaCode << ") " << this->sevenDigitNumber << "\n";
	}
	
};

class Age : public Data {
	unsigned int ageYears;
public:
	Age(unsigned int ay): ageYears(ay){};
protected:
	virtual void print (ostream& ostr) const{
		ostr << "Age " << this->ageYears << "\n";
	}
};

class HouseNumber : public Data {
	unsigned long houseNumber;
public:
	HouseNumber(unsigned long hn):houseNumber(hn){};
protected:	
	virtual void print (ostream& ostr) const{
		ostr << "House number " << this->houseNumber << "\n";
	}
}; 

void showData(vector<Data>& data_vec)
{
    std::cout << "\n";
    for ( int i=0; i < data_vec.size(); ++i ) {
        std::cout << "Element index number " << i << " is a " <<data_vec[i];
    }
}
 
int holdCommandWindow()
{
    std::string str;
    std::cout << "\nHit Enter To End Program ";
    std::getline(std::cin,str);
    return 0;
}

int main (int argc, char* argv[]) {
	
	vector<Data> data_vec;
	data_vec.push_back(PhoneExtension(313, 4567892));
	data_vec.push_back(PhoneExtension(800, 3334455));
	data_vec.push_back(Age(39));
	data_vec.push_back(Age(21));
	data_vec.push_back(HouseNumber(44842));
	showData(data_vec);
	holdCommandWindow();
}