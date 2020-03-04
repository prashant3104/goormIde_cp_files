#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n = 500000;
	vector<int> count(n+1, 1);
	count[0]=0;
	count[1]=0;
	for(int i=2; i<=n/2; i++)
		{
			for(int j=2; i*j<=n; j++)
			{
				count[i*j] += i;
			}
		}
	
	int t;
	cin >> t;
	while(t--)
	{
		int x;
		cin >> x;
		cout << count[x] << "\n";		
		
	}
	return 0;
}