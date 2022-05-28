#include <iostream>
#include "global.h"
#include <bitset>
#include <string>
#include <iostream>

// Мини-игра противостояние игрока и монстра(рандомного?) игрок и монстр атакуют по очереди, у каждого есть определённые характеристики 

std::string userName()
{
	std::cout << "\n";
	for (int i = 0; i <= 59; ++i)
	{
		std::cout << "*";
		std::cout << " ";
	}
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "Excellent! Now let's choose a name for your character: ";
	std::cin.ignore(32767, '\n'); // удаляем символ новой строки из входного потока данных
	std::string nameUser;
	std::getline(std::cin, nameUser);
	return nameUser;
	
}
enum class Profession
{
	MAGE,
	WARIRROR,
	PATHFINDER,
	BERSERK,
	ASSASIAN
};

struct UserData
{
	Profession type;
	std::string userName;
	int health_point_heroes;

	
};

Profession getProfessiongTypeString(std::string userChhooseProfession)
{
	if (userChhooseProfession == "Mage")
		return Profession::MAGE;
	if (userChhooseProfession == "Warirror")
		return Profession::WARIRROR;
	if (userChhooseProfession == "Pathfinder" )
		return Profession::PATHFINDER;
	if (userChhooseProfession == "Berserk")
		return Profession::BERSERK;
	if (userChhooseProfession == "Assasian")
		return Profession::ASSASIAN;
		
	
}
std::string receiptProfession(UserData ud)
{
	if (ud.type == Profession::MAGE)
		return "Mage";
	if (ud.type == Profession::WARIRROR)
		return "Warirror";
	if (ud.type == Profession::PATHFINDER)
		return "Pathfinder";
	if (ud.type == Profession::BERSERK)
		return "Berserk";
	if (ud.type == Profession::ASSASIAN)
		return "Assasian";
	else
		return "Unknown";
	

	
}

void printResultUser(UserData user)
{
	std::cout << "This " << receiptProfession(user) << " your name " << user.userName << " and his hero have point health " << user.health_point_heroes << "!!! :)" << std::endl;
}

enum class Monsters  // К каждому монстру присвоим значения стукртуры(Но можно ли присвоить это же значения используя 2 структуры?)
{
	OGRE,
	GOBLIN,
	SKELETON,
	ORC,
	TROLL
};

struct MonstersData // хп и имя монстров 
{
	Monsters type;
	std::string name;
	int healthPoint;
};

std::string getMonsterTypeString(MonstersData monster)
{
	if (monster.type == Monsters::OGRE)
		return "Ogre";
	if (monster.type == Monsters::GOBLIN)
		return "Goblin";
	if (monster.type == Monsters::SKELETON)
		return "Skeleton";
	if (monster.type == Monsters::ORC)
		return "Orc";
	if (monster.type == Monsters::TROLL)
		return "Troll";

	return "Unknown";
}

void printResult(MonstersData monster) // Вывод монстров и их характеристик в консоль
{
	std::cout << getMonsterTypeString(monster) << " is named " << monster.name << " and has " << monster.healthPoint << " health " << std::endl;
}


int main()
{	
	

	for (int i = 0; i <= 18; ++i)
	{
		std::cout << "*";
		std::cout << " ";
	}
	std::cout << "Hello!, There are five classes in this game "; 
	for (int i = 0; i <= 18; ++i)
	{
		std::cout << "*";
		std::cout << " ";
	}
	std::cout << "\n 1 - Mage\n 2 - Warirror\n 3 - Pathfinder\n 4 - Berserk\n 5 - Assasian\nChoose any of them : ";
	std::string userChhooseProfession; std::cin >> userChhooseProfession;
	std::string nameUser = userName();

	
	
	
	UserData mage{ Profession::MAGE, nameUser , 100 };
	UserData warirror{ Profession::WARIRROR, nameUser, 175 };
	UserData pathfinder{ Profession::PATHFINDER, nameUser , 150 };
	UserData berserk{ Profession::BERSERK, nameUser , 200 };
	UserData assasian{ Profession::ASSASIAN, nameUser , 125 };
	if (getProfessiongTypeString(userChhooseProfession) == Profession::MAGE)
		printResultUser(mage);
	if (getProfessiongTypeString(userChhooseProfession) == Profession::WARIRROR)
		printResultUser(warirror);
	if (getProfessiongTypeString(userChhooseProfession) == Profession::PATHFINDER)
		printResultUser(pathfinder);
	if (getProfessiongTypeString(userChhooseProfession) == Profession::BERSERK)
		printResultUser(berserk);
	if (getProfessiongTypeString(userChhooseProfession) == Profession::ASSASIAN)
		printResultUser(assasian);

	std::cout << "\n";
	for (int i = 0; i <= 59; ++i)
	{
		std::cout << "*";
		std::cout << " ";
	}
	std::cout << "\n";
	std::cout << "\n";

	for (int i = 0; i <= 18; ++i)
	{
		std::cout << "*";
		std::cout << " ";
	}

	std::cout << "You will have to confront these monsters: ";

	for (int i = 0; i <= 19; ++i)
	{
		std::cout << "*";
		std::cout << " ";
	}
	std::cout << '\n';
	std::cout << '\n';

	MonstersData ogre = { Monsters::OGRE, "Beat", 150 };
	MonstersData goblin = {Monsters::GOBLIN, "Ace", 100};
	MonstersData skeleton = { Monsters::SKELETON, "Jike", 125 };
	MonstersData orc = { Monsters::ORC, "Guldan", 150 };
	MonstersData troll = { Monsters::TROLL, "Rage", 160 };
	
	printResult(ogre);
	printResult(goblin);
	printResult(skeleton);
	printResult(orc);
	printResult(troll);

	
	return 0;

}
