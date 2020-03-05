// Prime Factorization of a number

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n = 10000000;
	vector<int>spf(n+1,-1);
	for(int i=2; i*i<=n; i++)
	{
		if(spf[i] == -1)
		{
			for(int j=i; j*i<=n; j++)
			{
				spf[i*j] = i;
			}
		}
	}
	
	
	int t; // no of test cases
	cin >> t;
	while(t--)
	{
		int x; // number 
		cin >> x;
		vector<int>result;
		
		while(spf[x] != -1)
		{
			result.push_back(spf[x]);
			x /= spf[x];
		}
		if(x != 1)
			result.push_back(x);
		
		for(int i=0; i<result.size(); i++)
		{
			cout << result[i] << " ";
		}
	}
	return 0;
}