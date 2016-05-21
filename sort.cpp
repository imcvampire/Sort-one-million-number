#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

#define n 1000000 // Consumes 4MB
#define m 500000  // Consumes 2MB
#define p 100000

int main()
{
	// freopen("input", "r", stdin);
	
	int v[m];
	
	// Read first 500000 number
	for	 (int i = 0; i < m; ++i)
	{
		cin >> v[i];
	}
	
	sort(v, v + m);
	
	// Write first 500000 number to file
	fstream fstemp ("temp", fstream::out);
	
	for (int i = 0; i < m; ++i)
	{
		fstemp << v[i] << endl;
	}
	
	fstemp.close();
	
	// Read 500000 others number
	for (int i = 0; i < m; ++i)
	{
		cin >> v[i];
	}
	
	sort(v, v + m);
	
		
	// 2-way merge
	fstream fs ("temp", fstream::in);

	int temp[p];

<<<<<<< HEAD
	// First 250000 number in temp file
	for (int i = 0; i < p; ++i)
	{
		fs >> temp[i];
	}		
	
	int i = 0, // index in temp
		j = 0; // index in v
	bool flag = true;
		
	while (i < p && j < m)
	{
		if (temp[i] > v[j])
		{
			cout << v[j] << endl;
			++j;
		}
		else 
		{
			cout << temp[i] << endl;
			++i;
		}
		
		// Check j are in range
		if (j == m)
		{
			// Print others number in temp array
			for (int k = j; k < p; ++k)
			{
				cout << temp[i] << endl;
			}
			
			//Print others number in temp file
			for (int k = 0; k < p; ++k)
			{
				fs >> temp[k]; 
			}
			
			for (int k = 0; k < p; ++k)
			{
				cout << temp[k] << endl;
			}
			
			flag = false;
		}
	}
	
	// Next 250000 number in temp file
	if (flag)
	{
		for (int k = 0; k < p; ++k)
		{
			fs >> temp[k]; 
		}
		
		i = 0;
		
		while (i < p && j < m)
		{
			if (temp[i] > v[j])
			{
				cout << v[j] << endl;
				++j;
			}
			else 
			{
				cout << temp[i] << endl;
				++i;
			}
			
			// Check i and j in range
			if (i == p)
			{
				for (int k = j; k < m; ++k)
				{
					cout << v[k] << endl;
				}
			}
			
			if (j == m)
			{
				for (int k = i; k < p; ++k)
				{
					cout << temp[k] << endl;
				}
			}
		}
	}
	
	fs.close();
	
	return 0;
}