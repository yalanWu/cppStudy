#include <vector>
#include <list>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <iostream>
#include <array>
#include <ctime>

#define  ASIZE 1000000

int compareLongs(const void* a, const void* b)
{
	return (*(long*)a - *(long*)b);
}

int comparestrings(const void* a, const void* b)
{
	if (*(long*)a > *(long*)b)
	{
		return 1;
	}
	else if (*(long*)a < *(long*)b)
	{
		return -1;
	}
	else
		return 0;
}

long get_a_target_long()
{
	long target;
	while (1)
	{
		std::cout << "target (0~" << RAND_MAX << ")" << std::endl;
		std::cin >> target;
		if (target >= 0 && target <= RAND_MAX)
		{
			break;
		}
	}
	
	return target;
}

std::string get_a_target_string()
{
	long target;
	char buf[10];
	memset(buf, 0, 10);
	while (1)
	{
		std::cout << "target (0~" << RAND_MAX << ")" << std::endl;
		std::cin >> target;
		if (target >= 0 && target <= RAND_MAX)
		{
			snprintf(buf, 10, "%ld", target);
			break;
		}
	}

	return std::string(buf);
}

void test_array(long value)
{
	std::cout << "\ntest array....\n";
	std::array<long, ASIZE> c;
	clock_t timeStart = clock();
	for (size_t i = 0; i < ASIZE; i++)
	{
		c[i] = rand();
	}

	std::cout << "cost milli-seconds:" << (clock() - timeStart)  << std::endl;
	std::cout << "array.size " << c.size() << std::endl;
	std::cout << "array.max_size" << c.max_size() << std::endl;
	std::cout << "array.front " << c.front() << std::endl;// 获得第一个 并不从数组中删除 size并不改变
	std::cout << "array.back " << c.back() << std::endl;
	std::cout << "array.data " << c.data() << std::endl;

	timeStart = clock();
	//排序 便于二分法查找
	qsort(c.data(), ASIZE, sizeof(long), compareLongs);
	std::cout << "qsort cost milli-seconds:" << (clock() - timeStart) << std::endl;
	//查找
	timeStart = clock();
	long* pItem = (long*)bsearch(&value, (c.data()), ASIZE, sizeof(long), compareLongs);
	std::cout << "bsearch cost milli-seconds:" << (clock() - timeStart) << std::endl;

	if (pItem != NULL)
	{
		std::cout << "found : " << *pItem << std::endl;
	}
	else
	{
		std::cout << "not found!" << std::endl;
	}
}

int get_a_target_container()
{
	int container;
	std::cout << "Sequence Containers, 底层数组实现，空间连续：\n";
	std::cout << "	1 Array\n";
	std::cout << "	2 Vector\n";
	std::cout << "	3 Deque\n";
	std::cout << "	4 List\n";
	std::cout << "	5 Forward-List\n";
	std::cout << "	6 Stack\n";
	std::cout << "	7 Queue\n";

	std::cout << "Associative Containers, 底层红黑树实现，查找效率较高:\n";
	std::cout << "	11 Set\n";
	std::cout << "	12 MultiSet\n";
	std::cout << "	13 Map\n";
	std::cout << "	14 MultiMap\n";

	std::cout << "Unordered Containers, 底层hashTable实现，key连续数组，vlaue为链表\n";
	std::cout << "	21 unordered_Set\n";
	std::cout << "	22 unordered_Map\n";
	std::cout << "	23 unordered_MultiSet\n";
	std::cout << "	24 unordered_MultiMap\n";

	std::cout << "Please select the number which container you will test:" << std::endl;
	std::cin >> container;
	return container;
}

int main(int argc, char* agrc[])
{
	int ctype = get_a_target_container();
	long svalue = get_a_target_long();
	switch (ctype)
	{
	case 1:
		test_array(svalue);
		break;
	default:
		break;
	}
	return 0;
}