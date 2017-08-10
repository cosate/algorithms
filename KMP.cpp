#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int kmp(string, string);

int main()
{

	string s = "abaccababcabababcabbcabcbabbcbbabbcbacbbbbabcbacb";
	string pattern = "acc";
	cout << kmp(s, pattern) << endl;
	return 0;
}

int kmp(string s, string pattern)
{
	int len = pattern.length();
	int * rec = new int[len];
	rec[0] = 0;
	for (int i = 1; i < len; i++)
	{
		int l = rec[i - 1];
		while (l != 0 && pattern[l] != pattern[i])
		{
			l = rec[l - 1];
		}
		if (pattern[l] == pattern[i])
			rec[i] = l + 1;
		else
			rec[i] = 0;
	}

	int index = 0;
	int j = 0;
	while (index <= s.length() && j < len)
	{
		if (s[index] == pattern[j])
		{
			index++;
			j++;
		}
		else
		{
			if (j == 0)
				index++;
			else
				j = rec[j - 1];
		}
	}
	if (j == len)
		return index - len;
	else
		return -1;
}
