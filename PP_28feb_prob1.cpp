#include<bits/stdc++.h>
using namespace std;

int main()
{
	int l = 1000000000;
	int r = 1000000000 + 500;
	int n = 100000;
	vector<int> only_primes;
	vector<int> primes(n+1, 1);
	for(int i=2; i*i<=n; i++)
	{
		if(primes[i] == 1)
		{
			for(int j=i; j*i<=n; j++)
			{
				primes[i*j] = 0;
			}
		}
	}
	
	for(int i=2; i<=n; i++)
	{
		if(primes[i] == 1)
		{
			only_primes.push_back(i);
		}
	}
	
	// for(int i=0; i<only_primes.size(); i++)
	// {
	// 	cout << only_primes[i] << " ";
	// }
	vector<int>result(r-l+1, 1);
	for(int i=0; i<only_primes.size(); i++)
	{
		for(int j=l/only_primes[i]; only_primes[i]*j<=r; j++)
		{
			if(only_primes[i]*j >= l)
			{
				result[only_primes[i]*j - l] = 0;
			}
		}
	}
	
	for(int i=0; i<result.size(); i++)
	{
		if(result[i] == 1)
		{
			cout<< i+l << " ";
		}
	}
	
	return 0;
}