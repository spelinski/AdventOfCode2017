#ifndef GRID_BUILD_H
#define GRID_BUILD_H
#include <deque>
#include <math.h>
#include <iostream>
std::deque<std::deque<int>> createFirstGrid()
{
	std::deque<std::deque<int>> starterGrid;
	starterGrid.push_front({1});
	return starterGrid;
}

std::deque<std::deque<int>> createNextGrid(std::deque<std::deque<int>> previousGrid)
{
	size_t beginSize = previousGrid.at(0).size()-1;
	int oneLocation = beginSize/2;
	int largestNumber = previousGrid.at(beginSize).at(beginSize)+1;
	int currentDesiredRow = beginSize;

	while (currentDesiredRow >= 0)
	{
		previousGrid[currentDesiredRow].push_back(largestNumber);
		largestNumber++;
		currentDesiredRow--;
	}

	int currentDesiredColumn = beginSize + 2;
	previousGrid.push_front({});
	while (currentDesiredColumn >= 0)
	{
		previousGrid[0].push_front(largestNumber);
		largestNumber++;
		currentDesiredColumn--;
	}

	previousGrid.push_back({});
	currentDesiredRow = beginSize + 2;
	int currentRow = 1;
	while (currentRow <= currentDesiredRow)
	{
		previousGrid[currentRow].push_front(largestNumber);
		largestNumber++;
		currentRow++;
	}


	int currentColumn = 1;
	currentDesiredColumn = beginSize + 2;
	while (currentColumn <= currentDesiredColumn)
	{
		previousGrid[currentDesiredRow].push_back(largestNumber);
		largestNumber++;
		currentColumn++;
	}

	/*std::cout << std::endl;
	for(int i=0; i < previousGrid.size(); i++)
	{
		for (int j=0; j < previousGrid[i].size(); j++)
		{
			std::cout << previousGrid[i][j] << " ";
		}
		std::cout << std::endl;
	}*/

	return previousGrid;
}
#endif
