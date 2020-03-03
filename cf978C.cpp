#include<bits/stdc++.h>
using namespace std;

int BS(vector<long long int> & v1, int l, int h,  long long int target)
{
	
	while(l <= h)
	{
		int m = l + (h-l)/2;
		
		//cout << m << " "<< v1[m] << "  " << target << "\n";
		if(v1[m] == target)
		{
			//cout << "HI  ";
			return m;
		}
		else if(v1[m] > target)
		{
			//cout << "HELLO  ";
			h = m-1;
		}
		else{
			//cout << "BYE  ";
			l = m+1;
		}
	}
	//cout << l << "\n";
	return l;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<long long int> v1(n+1);
	v1[0] = 0;
	for(int i=1; i<=n; i++)
	{
		cin >> v1[i];
	}
	vector<long long int> v2(m);
	for(int i=0; i<m; i++)
	{
		cin >> v2[i];
	}
	long long int cs = 0;
	// calculated cumulated sum for n size array
	
	for(int i=0; i<=n; i++)
	{
		cs += v1[i];
		v1[i] = cs;
	}
	//cout << v1[2] << "\n";
	for(int i=0; i<m; i++)
	{
		int x = BS(v1, 1, n, v2[i]);
		cout << x << " " << v2[i] - v1[x-1] << "\n";
	}
	
	return 0;
}