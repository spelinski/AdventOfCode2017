#include "acutest.h"
#include "../GridBuilder/GridBuilder.cpp"

void test_initial_grid(void)
{
	std::deque<std::deque<int>> myGrid = createFirstGrid();
	TEST_CHECK(myGrid.at(0).at(0) == 1);
}

void test_second_grid(void)
{
	std::deque<std::deque<int>> myGrid = createFirstGrid();
	myGrid = createNextGrid(myGrid);
	TEST_CHECK(myGrid.at(1).at(1) == 1);
	TEST_CHECK(myGrid.at(2).at(2) == 9);
}

TEST_LIST = {{"initial", test_initial_grid},{"second", test_second_grid},{0}};
