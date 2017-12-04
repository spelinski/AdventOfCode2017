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
	std::cout << beginSize << std::endl;
	std::cout << oneLocation << std::endl;
	return previousGrid;

}