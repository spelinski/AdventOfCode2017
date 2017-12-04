#include "acutest.h"
#include "../GridBuilder/GridBuilder.h"

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

void test_third_grid(void)
{
	std::deque<std::deque<int>> myGrid = createFirstGrid();
	myGrid = createNextGrid(myGrid);
	myGrid = createNextGrid(myGrid);
	TEST_CHECK(myGrid.at(2).at(2) == 1);
	TEST_CHECK(myGrid.at(3).at(3) == 9);
	TEST_CHECK(myGrid.at(4).at(4) == 25);
}

TEST_LIST = {{"initial", test_initial_grid},{"second", test_second_grid},{"third", test_third_grid},{0}};
