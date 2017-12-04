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
	std::cout << std::endl << numSteps << std::endl;
	return 0;
}