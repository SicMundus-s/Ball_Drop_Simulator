// Revesli_Chapter_8_OOP_TestEnd.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <string>
#include "Date.h"
#include <iostream>
#include <cmath>



class Monster
{
public:
	enum MonsterType
	{
		Dragon,
		Ogre,
		Goblin,
		Orc,
		Skeleton,
		Troll,
		Vampire,
		Zombie,
		MAX_MONSTER_TYPES

	};

private:
	MonsterType m_monsterType;
	std::string m_monsterName;
	int m_monsterHealth;

public:
	Monster(MonsterType monsterType, std::string monserName, int monsterHealth)
		: m_monsterType(monsterType), m_monsterName(monserName), m_monsterHealth(monsterHealth) {}

	std::string getTypeString()
	{
		switch (m_monsterType)
		{
		case Dragon: return "Dragon";
		case Ogre: return "Ogre";
		case Goblin: return "Goblin";
		case Orc: return "Orc";
		case Skeleton: return "Skeleton";
		case Troll: return "Troll";
		case Vampire: return "Vampire";
		case Zombie: return "Zombie";
		}

		return "Error";
		
	}

	void print()
	{
		std::cout << m_monsterName << " is the " << getTypeString() << " that has " << m_monsterHealth << " health point" << '\n';
	}
};


static class MonsterGeneration
{
private:
	
public:
	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); // используем static, так как это значение нужно вычислить единожды
		// Равномерно распределяем вычисление значения из нашего диапазона
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

	static Monster generateMonster()
	{
		static std::string monster_names[6] = { "a", "b", "c", "v", "d", "f" };
		Monster::MonsterType type = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1));
		return Monster(type, monster_names[getRandomNumber(0,5)], getRandomNumber(10, 100));
	}
};

int main()
{
	srand(static_cast<unsigned int>(time(0))); // используем системные часы в качестве стартового значения
	rand(); 

	Monster m = MonsterGeneration::generateMonster();
	m.print();
	Monster a = MonsterGeneration::generateMonster();
	Monster b = MonsterGeneration::generateMonster();
	a.print();
	b.print();
}