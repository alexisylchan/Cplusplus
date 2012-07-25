#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cstdlib>
#include <algorithm>

int main (int argc, char* argv[])
{
	std::string input_str;
	std::getline(std::cin, input_str);
	std::istringstream input_stream(input_str);
	std::vector<std::string> string_to_sort;
	std::vector<int> int_to_sort;
	std::vector<bool> is_integer;

	while (input_stream)
	{
		std::string str_token;
		int int_token = 0;
		input_stream >> str_token;		
		if (((int_token = atoi(str_token.c_str()))!= 0)|| str_token == "0")// if the token is actually an integer
		{
			int_to_sort.push_back(int_token);
			is_integer.push_back(true);
		}
		else
		{
			string_to_sort.push_back(str_token);
			is_integer.push_back(false);
		}
		if (input_stream.eof())
		{
			break;
		}
	}
	std::sort(string_to_sort.begin(),string_to_sort.end());
	std::sort(int_to_sort.begin(), int_to_sort.end());

	
	std::vector<bool>::iterator bool_it = is_integer.begin(); 
	do {
		if (*bool_it)
		{
			std::cout<<int_to_sort.front();
			int_to_sort.erase(int_to_sort.begin());
		}
		else
		{
			std::cout<<string_to_sort.front();
			string_to_sort.erase(string_to_sort.begin());
		}
		 ++bool_it;
		 if (bool_it != is_integer.end())
		 {
			 std::cout<<" ";
		 }
	}while (bool_it != is_integer.end());
	
}