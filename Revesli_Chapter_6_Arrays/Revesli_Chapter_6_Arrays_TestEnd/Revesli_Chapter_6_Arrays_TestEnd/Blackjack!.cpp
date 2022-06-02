#include <iostream>
#include <string>
#include <array>
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для функции time()

int randomCard(int min, int max)
{
    return static_cast<int>((rand() % (max - min + 1)) + min);

}


enum BlackjackResult
{
    BLACKJACK_PLAYER_WIN,
    BLACKJACK_DEALER_WIN,
    BLACKJACK_DRAW
};

enum CardSuit
{
    SUIT_TREFU,
    SUIT_BYBNU,
    SUIT_CHERVU,
    SUIT_PIKI,
    SUIT_MAX
};

enum CardWorth
{
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_9,
    RANK_10,
    RANK_VALET,
    RANK_QUEEN,
    RANK_KING,
    RANK_TYZ,
    RANK_MAX
};

struct Card
{
    CardSuit suit;
    CardWorth wotrh;
};

void printCard(const Card &card)
{
    switch (card.suit)
    {
    case SUIT_TREFU:
        std::cout << "T";
        break;
    case SUIT_BYBNU: 
        std::cout << "B";
        break;
    case SUIT_CHERVU:
        std::cout << "C";
        break;
    case SUIT_PIKI:
        std::cout << "P";
        break;
    case SUIT_MAX:
        std::cout << "Suit max: " << SUIT_MAX;
        break;
    default: break;
    }

    switch (card.wotrh)
    {
    case RANK_2:
        std::cout << "2";
        break;
    case RANK_3:
        std::cout << "3";
        break;
    case RANK_4:
        std::cout << "4";
        break;
    case RANK_5:
        std::cout << "5";
        break;
    case RANK_6:
        std::cout << "6";
        break;
    case RANK_7:
        std::cout << "7";
        break;
    case RANK_8:
        std::cout << "8";
        break;
    case RANK_9:
        std::cout << "9";
        break;
    case RANK_10:
        std::cout << "10";
        break;
    case RANK_VALET:
        std::cout << "V";
        break;
    case RANK_QUEEN:
        std::cout << "Q";
        break;
    case RANK_KING:
        std::cout << "K";
        break;
    case RANK_TYZ:
        std::cout << "T";
        break;
    case RANK_MAX:
        std::cout << "Rank Max: " << RANK_MAX;
        break;
    default: break;
    }
}

int getCardValue(const Card &card)
{
    switch (card.wotrh)
    {
    case::RANK_2:               return 2; 
    case::RANK_3:               return 3; 
    case::RANK_4:               return 4; 
    case::RANK_5:               return 5; 
    case::RANK_6:               return 6;
    case::RANK_7:               return 7; 
    case::RANK_8:               return 8; 
    case::RANK_9:               return 9; 
    case::RANK_10:              return 10; 
    case::RANK_VALET:           return 10; 
    case::RANK_QUEEN:           return 10; 
    case::RANK_KING:            return 10;
    case::RANK_TYZ:             return 11; 
    default: break;
    }
    return 0;
}

void swapCard(Card& a, Card& b)
{
    Card temp = a;
    a = b;
    b = temp;
}


void shuffleDeck(std::array<Card, 52>& deck)
{
    for (int count = 0; count < 52; ++count)
    {
        swapCard(deck[count], deck[randomCard(0, 51)]);
    }
}

void printDeck(const std::array<Card, 52> &deck)
{
    for (const auto& card : deck)
    {
        printCard(card);
        std::cout << ' ';
    }
    std::cout << '\n';
}

BlackjackResult playBlacjJack(std::array<Card, 52>& deck)
{
    int player = 0;
    int diler = 0;
    const Card *CardPtr = &deck[0];

    player += getCardValue(*CardPtr++);
    player += getCardValue(*CardPtr++);

    std::cout << "Your score: " << player << '\n';
    std::string choise;

    do
    {
        
        if (player > 21)
            return BLACKJACK_DEALER_WIN;

        std::cout << "Enter 'h' to draw another card or 's' to hold on : ";
        std::cin >> choise;
        if(choise == "h")
        {
            player += getCardValue(*CardPtr++);
            std::cout << "Your score: " << player << '\n';
        }
        else if (choise == "s")
            break;

    } while (true);

    do
    {
        
        diler += getCardValue(*CardPtr++);
        std::cout << "The dealer now has: " << diler << '\n';
        if (diler > 21)
            return BLACKJACK_PLAYER_WIN;
        
            
    } while (diler < 17);

    

    if (player > diler)
        return BLACKJACK_PLAYER_WIN;
    else if (player < diler)
        return BLACKJACK_DEALER_WIN;
    else if (player == diler)
        return BLACKJACK_DRAW;
}

int main()
{
    for (int iii = 0; iii < 71; ++iii) // opening. Features and rules of the game
    {
        std::cout << "*";
        std::cout << " ";
    }
    std::cout << "\nHello!, this is homemade Blackjack, it's quite easy to play, you just need a couple of clicks :)\n" << "The rules of our version of Blackjack are as follows : \n";
    std::cout << "All cards have a certain value, from 2 to 11. The game features a dealer and a player.\n";
    std::cout << "Each participant takes cards, the player (you :) takes 2 cards and then has the opportunity to either get cards or hold on,\n";
    std::cout << "your goal is to score as many points as possible, but when you reach 21 or more you will lose.\n";
    std::cout << "The dealer takes cards up to 17 points and then stops, if he has more than 21, then the dealer also loses. The one with the most points wins\n";
    std::cout << '\n';
    for (int iii = 0; iii < 71; ++iii)
    {
        std::cout << "*";
        std::cout << " ";
    }
    std::cout << '\n'; // End here
        
    srand(static_cast<unsigned int>(time(0)));
    rand();
    std::array<Card, 52> deck;
    int card = 0; // Для заполнения массива с помощью suitIndex и RankIndex нужен *двумернный массива*
        for (int suitIndex = 0; suitIndex < SUIT_MAX; ++suitIndex)
            for (int rankIndex = 0; rankIndex < RANK_MAX; ++rankIndex)
            {
                deck[card].suit = static_cast<CardSuit>(suitIndex);
                deck[card].wotrh = static_cast<CardWorth>(rankIndex);
                ++card;
            }
            
        
    
    //printDeck(deck);

    shuffleDeck(deck);

    //printDeck(deck);

    if (playBlacjJack(deck) == BLACKJACK_PLAYER_WIN)
        std::cout << "You WIN!!!";
    else if (BLACKJACK_DEALER_WIN)
        std::cout << "You lose(((";
    else
        std::cout << "Draw! What a surprise!";

    

    return 0;
}
