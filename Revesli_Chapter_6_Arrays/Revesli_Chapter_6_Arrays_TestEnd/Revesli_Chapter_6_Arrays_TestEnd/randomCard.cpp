/*#include <cstdlib> // ��� ������� rand() � srand()
#include <ctime> // ��� ������� time()

int randomCard(int min, int max)
{
	srand(static_cast<unsigned int>(time(0)));
	rand();
	return static_cast<int>((rand() % (max - min + 1)) + min);

}
*/