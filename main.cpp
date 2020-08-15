#include <iostream>
#include "hashTable.cpp"

int main()
{
	HashTable HT;

	HT.isEmpty() ? std::cout<<"Table is empty!"<<std::endl : std::cout<<"Table is NOT empty"<<std::endl;

	HT.insertItem(202,"andrew");
	HT.insertItem(104,"bob");
	HT.insertItem(407,"dylan");
	HT.insertItem(706,"cole");

	HT.printTable();

	HT.isEmpty() ? std::cout<<"Table is empty!"<<std::endl : std::cout<<"Table is NOT empty"<<std::endl;

	HT.removeItem(104);

	HT.printTable();

	std::cout << "--END--" << std::endl;
	return 0;
}
