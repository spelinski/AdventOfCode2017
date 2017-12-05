#include <iostream>
#include <deque>
#include "GridBuilder/GridBuilder.h"
#include "PathFinder/PathFinder.h"
int main(){
	std::deque<std::deque<int>> myGrid = createFirstGrid();
	int currentMaxRow = 0;
	int currentMaxColumn = 0;
	while(myGrid.at(currentMaxRow).at(currentMaxColumn) < 325489)
	{
		currentMaxRow+= 2;
		currentMaxColumn+= 2;
		myGrid = createNextGrid(myGrid);
	}
	int numSteps = findDistance(myGrid, 325489);
	std::cout << std::endl << "First Challenge: " << numSteps << std::endl;


	std::deque<std::deque<int>> mySumGrid = createFirstGrid();
	int result = createNextSumGrid(mySumGrid,325489);
	while(result == -1)
	{
		result = createNextSumGrid(mySumGrid,325489);
	}

	std::cout << std::endl << "Second Challenge: " << result << std::endl;




	return 0;
}