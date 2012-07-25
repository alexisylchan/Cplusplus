#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

// Data Instance stores information about where the data id is first found
// and the list of other centers that contains it. The id itself is stored
// in the std::map data structure in main to allow O(log n) look up time. 
class DataInstance
{
	int first_from_center;
public:
	DataInstance(int from_v):first_from_center(from_v){from_centers.push_back(from_v);};	
	bool print_copy_instructions(int id, int num_centers);
	std::vector<int> from_centers;
};

bool DataInstance::print_copy_instructions(int id, int num_centers)
{
	std::vector<int>::iterator center_iterator;
	bool copy_instr_issued = false;
	for (int i = 1; i <= num_centers; ++i) // i starts from 1 because data center id starts from 1
	{
		bool data_in_center = false;
		for (center_iterator = from_centers.begin(); center_iterator != from_centers.end(); ++center_iterator)
		{
			if ((*center_iterator) == i)
				data_in_center = true;
			
		}
		if (!data_in_center)
		{
			std::cout<<id<<" "<<first_from_center<<" "<<i<<std::endl;
			copy_instr_issued = true;
		}
	}
	return copy_instr_issued;
}

int main(int argc, char* argv[])
{
	std::map<int,DataInstance*> data_instances;
	std::map<int,DataInstance*>::iterator data_iterator; 
	int num_data_centers = 0;
	bool copy_instr_issued_ever = false;

	std::string num_data_centers_str;
	std::getline(std::cin,num_data_centers_str);
	std::istringstream num_data_centers_stream(num_data_centers_str);
	num_data_centers_stream >> num_data_centers;
	
	for (int i = 1; i <= num_data_centers; ++i) // i starts from 1 because data center id starts from 1
	{	
		std::string data_id_line;
		std::getline(std::cin,data_id_line);
		std::istringstream data_id_stream(data_id_line);				
		
		while (data_id_stream)
		{
			int data_id = -1;
			data_id_stream >> data_id;
			if (data_id == -1) //empty line
				break;
			
			if ((data_iterator = data_instances.find(data_id)) == data_instances.end())
			{
				data_instances.insert(std::make_pair<int,DataInstance*>(data_id,new DataInstance(i)));
			}
			else
			{
				data_iterator->second->from_centers.push_back(i);
			}			
			
			if (data_id_stream.eof())
				break;
		}
	}

	for (data_iterator = data_instances.begin(); data_iterator != data_instances.end(); ++data_iterator)
	{
		copy_instr_issued_ever = data_iterator->second->print_copy_instructions(data_iterator->first,num_data_centers);		
	}
	for (data_iterator = data_instances.begin(); data_iterator != data_instances.end(); ++data_iterator)
	{
		delete data_iterator->second;
		data_instances.erase(data_iterator);
	}
	if (!copy_instr_issued_ever)
	{
		std::cout<<std::endl;
	}
	std::cout<<"Done"<<std::endl;

}
