#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++)
	{
		int x;
		cin >> x;
		v[i] = x;
	}
	long long int res = 1; // IMPORTANT step to avoid overflow
	int x,y;
	x = INT_MIN;
	y = INT_MIN;
	
	for(int i=0; i<n; i++)
	{
		if(v[i] == 1)
		{
			x = y;
			y = i;
			if(x != INT_MIN && y != INT_MIN)
			{
				res *= (y-x);
			}
		}
	}
	
	if(x == INT_MIN && y == INT_MIN)
	{
		res = 0;
	}
	cout << res;
	
	return 0;
}