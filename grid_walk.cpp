#include <boost/unordered_map.hpp>
#include <boost/shared_ptr.hpp>
#include <iterator>
#include <iostream>
#include <cstdlib>

class GridSpace;
typedef boost::shared_ptr<GridSpace> GridSpace_S;
class GridSpace
{
	int x;
	int y;
	bool visited;
	GridSpace():x(0),y(0),visited(false){};
	GridSpace(int xval, int yval):x(xval),y(yval),visited(false){};	
	GridSpace(int xval, int yval, bool visitedval):x(xval),y(yval),visited(visitedval){};	
public:
	static GridSpace_S create(int x, int y, bool visited){return GridSpace_S(new GridSpace(x,y,visited));};
	bool operator==(const GridSpace &other) const
	{
		return (this->x == other.x) && (this->y == other.y);
	}
	friend std::size_t hash_value(GridSpace const& other)
    {
        std::size_t seed = 0;
        boost::hash_combine(seed, other.x);
        boost::hash_combine(seed, other.y);

        return seed;
    }
	
};

class Grid
{	 
	boost::unordered_map<GridSpace_S, int> grid_map;
public: 
	Grid(){};
	int traverse_grid();
	int sum_of_digit(int num);
	/*int sum_of_digit(int num,bool is_x);
	int sum_of_digits(int x, int y);*/
	int recurse_traverse_grid(int x, int y, int direction); 

}; 
int Grid::sum_of_digit(int num)
{
		
		int digitsum = 0; 
		int modval = 10;
		int divval = 0;
		int val = 0;
		int absnum = abs(num);
				
		while ((divval = absnum / modval) > 0)
		{
			digitsum += absnum % modval;
			absnum = absnum / modval; 
		}
		digitsum += absnum; 
		return digitsum; 
} 
 

int Grid::recurse_traverse_grid(int x, int y, int direction)
{
	if (grid_map.find(GridSpace::create(x,y,false)) != grid_map.end())
		return 0; 

	int sum_x_y = sum_of_digit(x) + sum_of_digit(y);   
	if ( sum_x_y > 19) return 0;	

	grid_map.insert(std::make_pair<GridSpace_S,int>(GridSpace::create(x,y,true),sum_x_y));
	int sum1, sum2, sum3, sum4, sum_x_y_k, sum_x_y_l;
	sum1 = sum2 = sum3 = sum4 = sum_x_y_k = sum_x_y_l = 0;
	for (int l = 0; ; l++)
	{ 
		for (int k = 0; ; k++)
		{ 

			sum_x_y_k = sum_of_digit(k + 1) + sum_of_digit(l);   
			sum_x_y_l = sum_of_digit(k) + sum_of_digit(l+1);   
			if ((sum_x_y_k > 19) && ( sum_x_y_l > 19)) break;
			if (( sum_x_y_k <= 19) && grid_map.find(GridSpace::create(k + 1,l,false)) != grid_map.end())
			{ 
				grid_map.insert(std::make_pair<GridSpace_S,int>(GridSpace::create(k + 1,l,true),sum_x_y_k));
				sum2 += 2; 
			} 
			if ((sum_x_y_l <= 19)&& grid_map.find(GridSpace::create(k,l+1,false)) != grid_map.end())
			{ 
				grid_map.insert(std::make_pair<GridSpace_S,int>(GridSpace::create(k,l+1,true),sum_x_y_l));
				sum2 += 2; 
			}	
		}
	}
	/*sum1 = recurse_traverse_grid(x+1,y,0);
	sum2 = recurse_traverse_grid(x-1,y,0);
	sum3 = recurse_traverse_grid(x,y+1,0);
	sum4 = recurse_traverse_grid(x,y-1,0);*/
	return 1 + sum1 + sum2 + sum3 + sum4;
	 
}
int Grid::traverse_grid()
{
	return recurse_traverse_grid(0,0,-1); 
}

int main()
{
	Grid g = Grid();
	std::cout<<g.traverse_grid()<<std::endl; 
	char bla;
	std::cin>> bla;
    return 0;
}