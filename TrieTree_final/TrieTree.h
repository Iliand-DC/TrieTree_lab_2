#pragma once
#include <string>

const int ALPHABET_SIZE = 2;

struct TrieNode {
	struct TrieNode* children[ALPHABET_SIZE];
	bool isEndOfWord;
};


struct TrieNode* createNode() {
	struct TrieNode* pNode = new TrieNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = nullptr;

	return pNode;
}

std::string toBinary(int key)
{
	int st = 1;
	while (key > std::pow(2, st+1))
		st++;
	std::string word(st+1,'0');
	int i = 0;
	int maxst = st;
	while (key > 0)
	{
		if (key >= std::pow(2, st))
		{
			word[maxst - st] = '1';
			key -= pow(2, st);
		}
		st--;
	}
	return word;
}

int toDecimal(std::string key)
{
	int res = 0;
	int base = 1;
	for (int i = key.length()-1; i >= 0; i--)
	{
		res += ((int)key[i] - '0') * base;
		base *= 2;
	}
	return res;
}

void insert(struct TrieNode*& root, std::string key) {
	TrieNode* pNode = root;

	if (pNode == nullptr) {
		pNode = createNode();
		root = pNode;
	}

	for (size_t i = 0; i < key.length(); i++)
	{
		int index = key[i] - '0';

		if (!pNode->children[index])
			pNode->children[index] = createNode();
		pNode = pNode->children[index];
	}

	pNode->isEndOfWord = true;
}




/*std::string maxXOR(struct TrieNode* root, std::string key) {
	std::string result = "";
	TrieNode* pNode = root;
	if (pNode != nullptr) {
		int i;
		for (int i = 0; i < key.length(); i++) {
			int index = key[i] - '0';

			if (pNode->children[0] != nullptr && pNode->children[1] != nullptr)
			{

			}

			pNode = pNode->children[index];
		}
		result = pNode->isEndOfWord;
	}
	return result;
}
*/

TrieNode* deleteElem(struct TrieNode* root, std::string key, int place = 0) {

	struct TrieNode* pNode = root;

	if (pNode != nullptr) {

		if (place < key.length()) {
			int index = key[place] - '0';
			if (pNode->children[index]) pNode = deleteElem(pNode->children[index], key, place + 1);
		}
		else {

			bool isEnd = true;
			for (size_t i = 0; i < ALPHABET_SIZE; i++)
			{
				if (pNode->children[i] != nullptr) isEnd = true;
			}

			if (isEnd) {
				delete pNode->children;
				pNode = nullptr;
			}
			else pNode->isEndOfWord = false;
		}
	}

	return pNode;
}

bool search(struct TrieNode* root, std::string key) {
	bool result = false;
	struct TrieNode* pNode = root;
	if (pNode != nullptr) {
		for (int i = 0; i < key.length(); i++) {
			int index = key[i] - '0';

			if (!pNode->children[index]) result = false;

			pNode = pNode->children[index];
		}
		result = pNode->isEndOfWord;
	}
	return result;
}

std::string getMaxXOR(TrieNode* root, std::string number)
{
	std::string result = "";
	TrieNode* pNode = root;
	for (int i = 0; i < number.length(); i++)
	{
		if (pNode != nullptr)
		{
			int index = number[i] - '0';

			if (pNode->children[0] != nullptr && pNode->children[1] != nullptr)
			{
				if (index == 0) result += '0';
				else if (index == 1) result += '1';
			}
			else if (pNode->children[0] == nullptr && pNode->children[1] != nullptr)
			{
				if (index == 0)
					index++;
				result += '1';
			}
			else if (pNode->children[0] != nullptr && pNode->children[1] == nullptr)
			{
				if (index == 1)
					index--;
				result += '0';
			}

			pNode = pNode->children[index];
		}
	}
	return result;
}

std::string maxXOR(TrieNode* root, std::string number, std::string result) {
	if (root != nullptr)
	{
		int index = 0;
		while (index < number.length())
		{
			for (size_t i = 0; i < ALPHABET_SIZE; i++)
			{
				if (i != (int)number[index]-'0')
				{
					if(i == 0)
						result += '0';
					else if (i == 1)
						result += '1';
				}
			}
			index++;
		}
	}
	return result;
}

void printTree(struct TrieNode* root)
{
	TrieNode* pNode = root;
	for (size_t i = 0; i < ALPHABET_SIZE; i++)
	{
		if (pNode->children[i] != nullptr) {
			std::cout << i;
			printTree(pNode->children[i]);
		}
	}
	std::cout << "\n";
}