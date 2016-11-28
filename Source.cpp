#include "Set.h"

int main()
{
	Set a(10);
	std::cin >> a;
	std::cout << a<<std::endl;
	a.FilterSort();
	a.add(4);
	std::cout << a;
	getchar();
	getchar();
}