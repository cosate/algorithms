#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void catlan(vector<vector<int>>& res, vector<int> tmp, stack<int>& in, stack<int>& stk)
{
	if(stk.empty())
	{
		while(!in.empty())
		{
			tmp.push_back(in.top());
			in.pop();
		}
		res.push_back(tmp);
	}
	else
	{
		int k = stk.top();
		in.push(k);
		stk.pop();
		catlan(res, tmp, in, stk);
		stk.push(k);
		in.pop();


		if(!in.empty())
		{
			int t = in.top();
			tmp.push_back(t);
			in.pop();
			catlan(res, tmp, in, stk);
		}
	}
}

int main()
{
	stack<int> stk;
	stk.push(5);
	stk.push(4);
	stk.push(3);
	stk.push(2);
	stk.push(1);


	vector<vector<int>> res;
	vector<int> tmp;
	stack<int> in;
	catlan(res, tmp, in, stk);
	for(int i = 0; i < res.size(); i++)
	{
		for(int j = 0; j < res[0].size(); j++)
			cout<<res[i][j]<<"    ";
		cout<<endl;
	}

	return 0;
}