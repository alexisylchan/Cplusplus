#include <iostream>
#include <vector>
#include <string>
#include <tr1/memory>
#include "PhoneExtension.h"
#include "HouseNumber.h"
#include "Age.h"

using std::ostream;
using std::vector;
using std::tr1::shared_ptr;
 

void showData(vector<shared_ptr<Data> >& data_vec)
{
    std::cout << "\n";
    for ( unsigned int i=0; i < data_vec.size(); ++i ) {
		std::cout << "Element index number " << i << " is a " << *data_vec[i].get();
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
	
	vector<shared_ptr<Data> > data_vec;
	data_vec.push_back(shared_ptr<Data>(new PhoneExtension(313, 4567892)));
	data_vec.push_back(shared_ptr<Data>(new PhoneExtension(800, 3334455)));
	data_vec.push_back(shared_ptr<Data>(new Age(39)));
	data_vec.push_back(shared_ptr<Data>(new HouseNumber(44842)));
	data_vec.push_back(shared_ptr<Data>(new Age(21)));
	showData(data_vec);
	holdCommandWindow();
}
