#include<bits/stdc++.h>
using namespace std;

int sieve[1000001] = {0};
int prefix_arr[11][1000001] = {0};

int main()
{
	int n = 1000001;
	for(int i=2; i<=n; i++)
	{
		if(sieve[i] == 0)
		{
			sieve[i] = 1;
			for(int j=2; i*j<=1000000; j++)
			{
				sieve[i*j] ++;
			}
		}
	}
	
	
	
	for(int i=1; i<=10; i++)
	{
		int cnt = 0;
		for(int j=2; j<=1000000; j++)
		{
			if(sieve[j] == i)
			{
				cnt++;
				prefix_arr[i][j] = cnt;
			}
			else{
				prefix_arr[i][j] = prefix_arr[i][j-1];
			}
		}
	}
	
	
	int t;
	cin >> t;
	while(t--)
	{
		int a, b, x;
		cin >> a >> b >> x;
		if(x == 0 && a == 1)
			cout << 1 << "\n";
		else
			cout << prefix_arr[x][b] - prefix_arr[x][a-1] << "\n";
		
	}
	return 0;
}