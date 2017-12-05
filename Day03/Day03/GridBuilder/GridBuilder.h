#ifndef GRID_BUILD_H
#define GRID_BUILD_H
#include <deque>
#include <math.h>
#include <iostream>
#include <tuple>
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

	return previousGrid;
}

bool checkIndexesAgainstSize(std::deque<std::deque<int>> grid, int row, int column)
{
	return ((row >= 0) && (column >= 0) && (row < grid.size()) && (column < grid[row].size()));
}

int sumAllTouching(std::deque<std::deque<int>> grid, int insertionRow, int insertionColumn)
{
	int sum = 0;
	//Check to the right
	if(checkIndexesAgainstSize(grid, insertionRow, insertionColumn+1)) {
		sum += grid.at(insertionRow).at(insertionColumn+1);
	}
	//check the top right
	if(checkIndexesAgainstSize(grid, insertionRow-1, insertionColumn+1)) {
		sum += grid.at(insertionRow-1).at(insertionColumn+1);
	}

	//check the top middle
	if(checkIndexesAgainstSize(grid, insertionRow-1, insertionColumn)) {
		sum += grid.at(insertionRow-1).at(insertionColumn);
	}

	//check the top left
	if(checkIndexesAgainstSize(grid, insertionRow-1, insertionColumn-1)) {
		sum += grid.at(insertionRow-1).at(insertionColumn-1);
	}

	//Check to the left
	if(checkIndexesAgainstSize(grid, insertionRow, insertionColumn-1)) {
		sum += grid.at(insertionRow).at(insertionColumn-1);
	}

	//check to the bottom left
	if(checkIndexesAgainstSize(grid, insertionRow+1, insertionColumn-1)) {
		sum += grid.at(insertionRow+1).at(insertionColumn-1);
	}

	//check the bottom middle
	if(checkIndexesAgainstSize(grid, insertionRow+1, insertionColumn)) {
		sum += grid.at(insertionRow+1).at(insertionColumn);
	}

	//check the bottom right
	if(checkIndexesAgainstSize(grid, insertionRow+1, insertionColumn+1)) {
		sum += grid.at(insertionRow+1).at(insertionColumn+1);
	}
	return sum;
}

std::deque<std::deque<int>> padGridWithZeroes(std::deque<std::deque<int>> previousGrid)
{
	size_t beginSize = previousGrid.at(0).size()-1;
	int oneLocation = beginSize/2;
	int currentDesiredRow = beginSize;

	while (currentDesiredRow >= 0)
	{
		previousGrid[currentDesiredRow].push_back(0);
		currentDesiredRow--;
	}

	int currentDesiredColumn = beginSize + 2;
	previousGrid.push_front({});
	while (currentDesiredColumn >= 0)
	{
		previousGrid[0].push_front(0);
		currentDesiredColumn--;
	}

	previousGrid.push_back({});
	currentDesiredRow = beginSize + 2;
	int currentRow = 1;
	while (currentRow <= currentDesiredRow)
	{
		previousGrid[currentRow].push_front(0);
		currentRow++;
	}


	int currentColumn = 1;
	currentDesiredColumn = beginSize + 2;
	while (currentColumn <= currentDesiredColumn)
	{
		previousGrid[currentDesiredRow].push_back(0);
		currentColumn++;
	}

	return previousGrid;
}

int createNextSumGrid(std::deque<std::deque<int>> &previousGrid, int target)
{
	size_t beginSize = previousGrid.at(0).size();
	int oneLocation = beginSize/2;
	int currentDesiredRow = beginSize;

	previousGrid = padGridWithZeroes(previousGrid);

	while (currentDesiredRow > 0)
	{
		int newNumber = sumAllTouching(previousGrid, currentDesiredRow, previousGrid[currentDesiredRow].size()-1);
		if (newNumber > target)
		{
			return newNumber;
		}
		previousGrid[currentDesiredRow][previousGrid[currentDesiredRow].size()-1]= newNumber;
		currentDesiredRow--;
	}

	int currentDesiredColumn = beginSize + 1;
	while (currentDesiredColumn >= 0)
	{
		int newNumber = sumAllTouching(previousGrid, 0, currentDesiredColumn);
		if (newNumber > target)
		{
			return newNumber;
		}
		previousGrid[0][currentDesiredColumn] = newNumber;
		currentDesiredColumn--;
	}

	currentDesiredRow = beginSize + 1;
	int currentRow = 1;
	while (currentRow <= currentDesiredRow)
	{
		int newNumber = sumAllTouching(previousGrid, currentRow, 0);
		if (newNumber > target)
		{
			return newNumber;
		}
		previousGrid[currentRow][0] = newNumber;
		currentRow++;
	}


	int currentColumn = 1;
	currentDesiredColumn = beginSize + 1;
	while (currentColumn <= currentDesiredColumn)
	{
		int newNumber = sumAllTouching(previousGrid, currentDesiredRow, currentColumn);
		if (newNumber > target)
		{
			return newNumber;
		}
		previousGrid[currentDesiredRow][currentColumn] = newNumber;
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

	return -1;
}
#endif
