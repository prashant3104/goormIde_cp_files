#include<bits/stdc++.h>
using namespace std;

int BS(vector<int> & v, int l, int h, int target)
{
	while(l <= h)
	{
		int m = l + (h-l)/2;
		if(v[m] == target)
		{
			if(m == v.size()-1)
			{
				return m+1;
			}
			else if(v[m] == v[m+1])
			{
				l = m+1;
			}
			else
				return m+1;
		}
		else if(v[m] > target)
			h = m-1;
		else
			l = m+1;
	}
	return h+1;
}

int main()
{
	int n,m;
	cin >> n >> m;
	vector<int> v1(n);
	vector<int> v2(m);
	
	for(int i=0; i<n; i++)
	{
		cin >> v1[i];
	}
	
	for(int i=0; i<m; i++)
	{
		cin >> v2[i];
	}
	
	sort(v1.begin(), v1.end());
	
	for(int i=0; i<m; i++)
	{
		cout << BS(v1, 0, n-1, v2[i]) << " ";
	}
	
	return 0;
}