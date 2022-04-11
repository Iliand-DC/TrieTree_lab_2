#include "TrieTree.h"

void TrieTree::add(std::string word)
{
	TrieNode* h = root;
	for (int i = 0; i < word.size(); i++)
	{
		if (h->alph[int(word[i] - '0')] != nullptr)
		{
			h = h->alph[int(word[i] - '0')];
		}
		else
		{
			h->alph[int(word[i] - '0')] = new TrieNode;
		}

	}
	h->alph[2] = tail;
}

bool TrieTree::wordFind(std::string word)
{
	bool flag = true;
	TrieNode* h = root;
	int i = 0;
	while (flag && i < word.size())
	{
		if (h->alph[int(word[i] - '0')] == nullptr)
			flag = false;
		h = h->alph[int(word[i] - '0')];
		i++;
	}
	if (h->alph[2] == nullptr)
		flag = false;
	return flag;
}

void TrieTree::recurseRemove(TrieNode* root, std::string word, int curIndex)
{
	if (curIndex<word.size() && root->alph[int(word[curIndex] - '0')] != nullptr)
		recurseRemove(root->alph[int(word[curIndex] - '0')], word, ++curIndex);
	
}
void TrieTree::remove(std::string word)
{
	if (!wordFind(word))
	{
		std::cout << 'n';
	}
	else
	{
		TrieNode* p = root;
		TrieNode* plc_wth_chld = root;
		int ch;
		int i = 0;
		while (i < word.size() && p->alph[int(word[i] - '0')] != nullptr)
		{
			if (checkchilds(p) > 1)
			{
				plc_wth_chld = p;
				ch = i;
			}
			p = p->alph[int(word[i] - '0')];
			i++;
		}
		if (word.size() > i || p->alph[2] == nullptr)
		{
			std::cout << "No such word!";
		}
		else
		{
			clearTree(plc_wth_chld->alph[ch]);
		}
	}
}

int TrieTree::checkchilds(TrieNode* root)
{
	int cnt = 0;
	for (int i = 0; i < 3; i++)
	{
		if (root->alph[i] != nullptr)
			cnt++;
	}
	return cnt;
}

void TrieTree::clearTree(TrieNode* p)
{
	for (int i = 0; i < 3; i++)
	{
		if(p->alph[i]!=nullptr)
			clearTree(p->alph[i]);
	}
	p = nullptr;
}