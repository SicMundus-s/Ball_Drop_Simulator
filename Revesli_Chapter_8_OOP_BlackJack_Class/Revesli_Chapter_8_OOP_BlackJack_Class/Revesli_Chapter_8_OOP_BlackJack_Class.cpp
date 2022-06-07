#include <iostream>
#include <string>
#include <array>
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для функции time()
#include <cassert> // для assert()



class Card
{
public:
    enum BlackjackResult
    {
        BLACKJACK_PLAYER_WIN,
        BLACKJACK_DEALER_WIN,
        BLACKJACK_DRAW
    };

    enum CardSuit
    {
        SUIT_TREFU,
        SUIT_BYBNI,
        SUIT_CHERVI,
        SUIT_PIKI,
        SUIT_MAX
    };

    enum CardRank
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

private:
    CardRank m_rank;
    CardSuit m_suit;
public:
    Card(CardRank rank = RANK_MAX, CardSuit suit = SUIT_MAX) : m_rank(rank), m_suit(suit) {};



    void printCard() const
    {
        switch (m_rank)
        {
        case RANK_2:		std::cout << '2'; break;
        case RANK_3:		std::cout << '3'; break;
        case RANK_4:		std::cout << '4'; break;
        case RANK_5:		std::cout << '5'; break;
        case RANK_6:		std::cout << '6'; break;
        case RANK_7:		std::cout << '7'; break;
        case RANK_8:		std::cout << '8'; break;
        case RANK_9:		std::cout << '9'; break;
        case RANK_10:		std::cout << 'T'; break;
        case RANK_VALET:	std::cout << 'J'; break;
        case RANK_QUEEN:	std::cout << 'Q'; break;
        case RANK_KING:		std::cout << 'K'; break;
        case RANK_TYZ:		std::cout << 'A'; break;
        }

        switch (m_suit)
        {
        case SUIT_TREFU:		std::cout << 'T'; break;
        case SUIT_BYBNI:	    std::cout << 'B'; break;
        case SUIT_CHERVI:	    std::cout << 'C'; break;
        case SUIT_PIKI:	        std::cout << 'P'; break;
        }
    }

    int getCardValue() const
    {
        switch (m_rank)
        {
        case RANK_2:		return 2;
        case RANK_3:		return 3;
        case RANK_4:		return 4;
        case RANK_5:		return 5;
        case RANK_6:		return 6;
        case RANK_7:		return 7;
        case RANK_8:		return 8;
        case RANK_9:		return 9;
        case RANK_10:		return 10;
        case RANK_VALET:	return 10;
        case RANK_QUEEN:	return 10;
        case RANK_KING:		return 10;
        case RANK_TYZ:		return 11;
        }

        return 0;
    }
};

class Deck
{
private:
    std::array<Card, 52> m_deck;

    static int randomCard(int min, int max)
    {
        return static_cast<int>((rand() % (max - min + 1)) + min);

    }

    static void swapCard(Card& a, Card& b)
    {
        Card temp = a;
        a = b;
        b = temp;
    }

    int m_cardIndex = 0;
public:
    Deck()
    {
        int card = 0;
        for (int suit = 0; suit < Card::SUIT_MAX; ++suit)
            for (int rank = 0; rank < Card::RANK_MAX; ++rank)
            {
                m_deck[card] = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
                ++card;
            }
    }

    void printDeck() const
    {
        for (const auto& card : m_deck)
        {
            card.printCard();
            std::cout << ' ';
        }

        std::cout << '\n';
    }


    void shuffleDeck()
    {
        // Перебираем каждую карту в колоде
        for (int index = 0; index < 52; ++index)
        {
            // Выбираем любую случайную карту
            int swapIndex = randomCard(0, 51);
            // Меняем местами с нашей текущей картой
            swapCard(m_deck[index], m_deck[swapIndex]);
        }
        m_cardIndex = 0;
    }

    const Card& dealCard()
    {
        assert(m_cardIndex < 52);
        return m_deck[m_cardIndex++];
    }
};

char getplayerChoice()
{
    std::cout << "Enter ('h') to draw another card or ('s') to hold on : ";
    char choise;
    do
    {
        std::cin >> choise;
    } while (choise != 'h' && choise != 's');
    return choise;
}

Card::BlackjackResult playBlacjJack(Deck& deck)
{
    int player = 0;
    int diler = 0;
    int card = deck.dealCard().getCardValue();
    player += card;
    player += card;

    std::cout << "Your score: " << player << '\n';
    char choise;

    do
    {

        if (player > 21)
            return Card::BLACKJACK_DEALER_WIN;


        choise = getplayerChoice();
        if (choise == 'h')
        {
            player += card;
            std::cout << "Your score: " << player << '\n';
        }
        else if (choise == 's')
            break;

    } while (true);

    do
    {

        diler += card;
        std::cout << "The dealer now has: " << diler << '\n';
        if (diler > 21)
            return Card::BLACKJACK_PLAYER_WIN;


    } while (diler < 17);



    if (player > diler)
        return Card::BLACKJACK_PLAYER_WIN;
    else if (player < diler)
        return Card::BLACKJACK_DEALER_WIN;
    else if (player == diler)
        return Card::BLACKJACK_DRAW;
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


    srand(static_cast<unsigned int>(time(0))); // используем системные часы в качестве стартового значения
    rand(); // пользователям Visual Studio: делаем сброс первого случайного числа

    Deck deck;
    // deck.printDeck(); // Базовая колода
    deck.shuffleDeck();
    // deck.printDeck(); // перемешанная колода

    int resultGameBlackJack = playBlacjJack(deck);

    if (resultGameBlackJack == Card::BLACKJACK_PLAYER_WIN)
        std::cout << "You WIN!!!";
    else if (resultGameBlackJack == Card::BLACKJACK_DEALER_WIN)
        std::cout << "You lose(((";
    else if (resultGameBlackJack == Card::BLACKJACK_DRAW)
        std::cout << "Draw! What a surprise!";



    return 0;


}