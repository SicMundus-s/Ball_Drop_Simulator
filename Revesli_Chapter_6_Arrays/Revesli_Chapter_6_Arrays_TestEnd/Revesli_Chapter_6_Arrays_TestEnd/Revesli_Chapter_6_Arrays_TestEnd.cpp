#include <vector>
#include <iostream>
#include <string>
#include <random>

int getRandomNumber2(int min, int max)
{
    return static_cast<int>((rand() % (max - min + 1)) + min);
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    rand();
    int*** array = new int** [15]; // выделяем массив из 15 указателей типа int — это наши строки
    for (int a = 0; a < 15; ++a)
    {
        array[a] = new int* [15]; // а это наши столбцы 
        for (int b = 0; b < 15; ++b)
        {
            array[a][b] = new int[15]; // это колличество двумерных массивов(таблиц)(трехмерный массив)

        }
 
    }
    for (int a = 0; a < 15; ++a)
    {
        for (int b = 0; b < 15; ++b)
        {
            for(int c = 0; c < 15; ++c)
            {
                array[a][b][c] = getRandomNumber2(1, 9);
                std::cout << array[a][b][c] << " ";
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}