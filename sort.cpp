#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

#define n 1000000
#define m 500000 

int main()
{
	vector<int> v(m);
	
	// Read first 500000 number
	for	 (int i = 0; i < m; ++i)
	{
		cin >> v[i];
	}
	
	sort(v.begin(), v.end());
	
	// Write first 500000 number to file
	fstream fstemp ("test.txt", fstream::out);
	
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
	
	sort(v.begin(), v.end());	
	 
	
	
	return 0;
}