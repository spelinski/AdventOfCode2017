#include "acutest.h"
#include "../GridBuilder/GridBuilder.h"
#include "../PathFinder/PathFinder.h"

void test_steps_from_one_to_one(void)
{
	std::deque<std::deque<int>> myGrid = createFirstGrid();
	myGrid = createNextGrid(myGrid);
	myGrid = createNextGrid(myGrid);
	int numSteps = findDistance(myGrid, 1);
	TEST_CHECK(numSteps == 0);
}

void test_steps_from_twelve_to_one(void)
{
	std::deque<std::deque<int>> myGrid = createFirstGrid();
	myGrid = createNextGrid(myGrid);
	myGrid = createNextGrid(myGrid);
	int numSteps = findDistance(myGrid, 12);
	TEST_CHECK(numSteps == 3);
}

void test_steps_from_twentyThree_to_one(void)
{
	std::deque<std::deque<int>> myGrid = createFirstGrid();
	myGrid = createNextGrid(myGrid);
	myGrid = createNextGrid(myGrid);
	int numSteps = findDistance(myGrid, 23);
	TEST_CHECK(numSteps == 2);
}

void test_steps_from_1024_to_one(void)
{
	std::deque<std::deque<int>> myGrid = createFirstGrid();
	int currentMaxRow = 0;
	int currentMaxColumn = 0;
	while(myGrid.at(currentMaxRow).at(currentMaxColumn) < 1024)
	{
		currentMaxRow+= 2;
		currentMaxColumn+= 2;
		myGrid = createNextGrid(myGrid);
	}
	int numSteps = findDistance(myGrid, 1024);
	TEST_CHECK(numSteps == 31);
}

TEST_LIST = {{"steps_one", test_steps_from_one_to_one},{"steps_twelve", test_steps_from_twelve_to_one},{"steps_23",test_steps_from_twentyThree_to_one},
			{"steps_1024", test_steps_from_1024_to_one},{0}};