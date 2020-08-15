#include <iostream>
#include <list>
#include <string>

class HashTable
{
private:
	static const int hashGroups = 26;
	std::list<std::pair<int, std::string>> table[hashGroups];

public:
	bool isEmpty() const;

	int hashFunction(int key);

	void insertItem(int key, std::string value);

	void removeItem(int key);

	std::string searchTable(int key);

	void printTable();
};

bool HashTable::isEmpty() const
{
	int sum{};

	// for (int i{}; i < hashGroups; i++)
	for (const auto & i : table)
	{
		sum += i.size();
	}
	if (!sum)
	{
		return true;
	}
	return false;
}

int HashTable::hashFunction(int key)
{
	return key % hashGroups;
}

void HashTable::insertItem(int key, std::string value)
{
	int hashValue = hashFunction(key);
	auto &cell = table[hashValue];
	auto beginIter = begin(cell);
	bool keyExists = false;
	for (; beginIter != end(cell); beginIter++)
	{
		if (beginIter->first == key)
		{
			keyExists = true;
			beginIter->second = value;
			std::cout << "[WARNING] Key exists. Value replaced" << std::endl;
			break;
		}
	}
	if (!keyExists)
	{
		cell.emplace_back(key, value);
	}
}

void HashTable::removeItem(int key)
{
	int hashValue = hashFunction(key);
	auto &cell = table[hashValue];
	auto beginIter = begin(cell);
	bool keyExists = false;
	for (; beginIter != end(cell); beginIter++)
	{
		if (beginIter->first == key)
		{
			auto tmpKVP = beginIter;
			keyExists = true;
			beginIter = cell.erase(beginIter); // returns iterator to next index
			std::cout << "[INFO] Key Value Pair: {" << tmpKVP->first << ", " << tmpKVP->second << "} Removed."
			          << std::endl;
			break;
		}
	}
	if (!keyExists)
	{
		std::cout << "[WARNING] Key not found, pair not removed." << std::endl;
	}
}

void HashTable::printTable()
{
	// for (const auto & i : table)
	for (int i{}; i < hashGroups; i++)
	{
		// if (i.cend()) continue;   //  if iterator goes through list once, stop looking
		if (table[i].empty()) continue;   //  if table index is empty, move to next position in table (!double check on this)

		// auto beginIter = i.begin();
		auto beginIter = table[i].begin();

		// for (auto j: table)
		for (; beginIter != table[i].end(); beginIter++)
		{
			std::cout << "[INFO] Key: " << beginIter->first << " Value: " << beginIter->second << std::endl;
		}
	}
}













