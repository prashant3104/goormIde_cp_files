// Q: Given an array find the max consecutive diff in the sorted form of the array
/* Bucketing Example */

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
	
	int _min = INT_MAX;
	int _max = INT_MIN;
	
	for(int i=0; i<n; i++)
	{
		_min = min(_min, v[i]);
		_max = max(_max, v[i]);
	}
	//cout << _max << " " << _min;
	int min_val_of_max_gap;
	int t = (_max - _min)%(n-1);
	if(t == 0)
		min_val_of_max_gap = (_max - _min)/(n-1);
	else
		min_val_of_max_gap = (_max - _min)/(n-1) + 1;
	
	//cout << min_val_of_max_gap;
	vector<int> min_arr(n, INT_MAX);
	vector<int> max_arr(n, INT_MIN);
	
	for(int i=0; i<n; i++)
	{
		int bkt = (v[i] - _min)/min_val_of_max_gap;
		min_arr[bkt] = min(v[i], min_arr[bkt]);
		max_arr[bkt] = max(v[i], min_arr[bkt]);		
	}
	for(int i=0; i<n; i++)
	{
		cout << min_arr[i] << " " << max_arr[i] << "\n";
	}
	int max_diff = INT_MIN;
	for(int i=0; i<n-1;)
	{
		if(max_arr[i] != INT_MIN)
		{
			for(int j=i+1; j<n; j++)
			{
				if(min_arr[j] != INT_MAX)
				{
					max_diff = max(max_diff, min_arr[j] - max_arr[i]);
					i = j;
					break;
					
				}
				else if(j = n-1)
					i = j; // when last element of min_arr is INT_MAX then to avoid infinite loop
			}
		}
		else 
			i++;
		
	}
	
	cout << max_diff << " ";
	
	return 0;
}