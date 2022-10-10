#include <cassert>
#include "Lab6.h"

int main()
{
	std::vector<int> v = { 1,3,3,3,4,2,5,6,1,3,8,5,2,46,2,3,5,2 };

	lab6::Min(v);

	lab6::Max(v);

	return 0;
}