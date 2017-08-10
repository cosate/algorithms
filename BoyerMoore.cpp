#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int bm(string, string);

int main()
{

	string s = "abaccababcabababcabbcabcbabbcbbabbcbacbbbbabcbacb";
	string pattern = "acc";
	cout << kmp(s, pattern) << endl;
	cout << bm(s, pattern) << endl;
	return 0;
}

int bm(string s, string pattern)
{
	int lens = s.length();
	int lenp = pattern.length();
	int badchar[256];
	for (int i = 0; i < 256; i++)
		badchar[i] = -1;
	for (int i = 0; i < lenp; i++)
		badchar[pattern[i]] = i;//记录字符最右位置

	int* suff = new int[lenp];
	suff[lenp - 1] = lenp;
	for (int i = lenp - 2; i >= 0; i--)
	{
		int j = 0;
		while (j <= i && pattern[i - j] == pattern[lenp - 1 - j])
			j++;
		suff[i] = j;
	}

	int* goodsuffix = new int[lenp];
	for (int i = 0; i < lenp; i++)
		goodsuffix[i] = lenp;
	for (int i = 0; i < lenp; i++)
	{
		if (suff[i] == i + 1)
		{
			for (int j = 0; j < lenp - 1 - i; j++)
			{
				goodsuffix[j] = lenp - 1 - i;
			}
		}
	}
	for (int i = 0; i < lenp; i++)
	{
		if(suff[i] != 0)
			goodsuffix[lenp - suff[i]] = lenp - i - 1;
	}

	int index = lenp - 1;
	int ptr = lenp - 1;
	while (index < lens && ptr >= 0)
	{
		if (s[index] == pattern[ptr])
		{
			index--;
			ptr--;
		}
		else
		{
			if (ptr == lenp - 1)
			{
				index = index + ptr - badchar[s[index]];
			}
			else
			{
				int bc = lenp - 1 - badchar[s[index]];
				int bs = goodsuffix[ptr + 1];
				int move = max(bc, bs);
				index = index + move;
				ptr = lenp - 1;
			}
		}
	}
	if (ptr == -1)
		return index + 1;
	else
		return -1;
}