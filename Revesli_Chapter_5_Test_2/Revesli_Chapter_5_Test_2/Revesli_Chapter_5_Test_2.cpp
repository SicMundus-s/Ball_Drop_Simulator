#include <iostream>
#include <cstdlib>

int Generating_a_random_number(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Равномерно распределяем рандомное число в нашем диапазоне
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

bool playAgain()
{
    char nowPlayAgain;
    do
    {
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> nowPlayAgain;
    } while (nowPlayAgain != 'y' && nowPlayAgain != 'n');

    return (nowPlayAgain == 'y');
}

void Game(int randomNumber)
{
    
    do 
    {


        int guess = 0;
        std::cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.\n";
        for (int attempt = 1; attempt <= 7; attempt++)
        {
            std::cout << "Guess #" << attempt << ": ";
            std::cin >> guess;

            if (attempt >= 7)
                std::cout << "Sorry, you lose. The correct number was: " << randomNumber;
            else if (guess > randomNumber)
                std::cout << "Your guess is too high.\n";
            else if (guess < randomNumber)
                std::cout << "Your guess is too low.\n";
            else if (guess == randomNumber)
            {
                std::cout << "Correct! You Win!";
                break;
            }


        }

             
    } while (playAgain());

    
}

int main()
{
    srand(static_cast<unsigned int>(time(0))); 
    rand();
    int randomNumber = Generating_a_random_number(1, 100); // Получаем псевдорандомное число от 1 до 100
    Game(randomNumber); // Передаём псевдорандомное число в функцию game

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
