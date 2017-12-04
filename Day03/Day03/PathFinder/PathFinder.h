#ifndef PATH_FINDER_H
#define PATH_FINDER_H
#include <deque>
#include <math.h>

int findDistance(std::deque<std::deque<int>> grid, int targetData)
{
	size_t beginSize = grid.at(0).size()-1;
	int oneRow = beginSize/2;
	int oneColumn = oneRow;
	for (int i = 0; i < grid.size(); i++)
	{
		for(int j = 0; j < grid[0].size(); j++)
		{
			if(grid.at(i).at(j) == targetData)
			{
				return (abs(i-oneRow) + abs(j-oneColumn));
			}
		}
	}
	return 0;
}
#endif
