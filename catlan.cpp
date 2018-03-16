#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void catlan(vector<vector<int>>& res, vector<int> tmp, vector<int>& in, stack<int>& stk)
{
	if (stk.empty())
	{
		for (int i = in.size() - 1; i >= 0; i--)
			tmp.push_back(in[i]);
		res.push_back(tmp);
	}
	else
	{
		int k = stk.top();
		in.push_back(k);
		stk.pop();
		catlan(res, tmp, in, stk);
		stk.push(k);
		in.pop_back();

		if (!in.empty())
		{
			int t = in.back();
			tmp.push_back(t);
			in.pop_back();
			catlan(res, tmp, in, stk);
			tmp.pop_back();
			in.push_back(t);
		}
	}
}

int main()
{
	stack<int> stk;
	stk.push(11);
	stk.push(10);
	stk.push(9);
	stk.push(8);
	stk.push(7);
	stk.push(6);
	stk.push(5);
	stk.push(4);
	stk.push(3);
	stk.push(2);
	stk.push(1);


	vector<vector<int>> res;
	vector<int> tmp;
	vector<int> in;
	catlan(res, tmp, in, stk);
	cout << res.size() << endl;
	/*for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[0].size(); j++)
			cout << res[i][j] << "    ";
		cout << endl;
	}*/

	return 0;
}