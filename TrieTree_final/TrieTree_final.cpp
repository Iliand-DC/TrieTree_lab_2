#include <iostream>
#include "TrieTree.h"

int main() {
	//std::cout << toBinary(6) << '\n';
	int numberC, x;
	std::cout << "Enter count of numbers (n>0): ";
	std::cin >> numberC;/*
	std::cout << "Enter count of query (q>0): ";
	std::cin >> queryC;*/

	TrieNode* root = nullptr;
	int numbers;
	std::cout << "\nEnter your number (a1,a2,a3,...,an):";
	for (size_t i = 0; i < numberC; i++)
	{
		std::cin >> numbers;
		insert(root, toBinary(numbers));
	}

	//std::cout << "\nYou entered: ";
	//printTree(root);


	////std::cout << "\nEnter your query:";
	////for (size_t i = 0; i < queryC; i++)
	////{
		std::cout << "\nEnter x:";
		std::cin >> x;
		std::string res = "";
		std::string XOR = maxXOR(root, toBinary(x), res);
		std::cout << "\nFor " << x << " max XOR number in string is :" << getMaxXOR(root, XOR) << "\n";
		std::cout << "\nYour MaxXOR is : " << toDecimal(getMaxXOR(root, XOR)) << '\n';

	//}

	//std::cout << "Your tree is: "; printTree(root);


	std::cin.ignore().get();
	return 0;
}