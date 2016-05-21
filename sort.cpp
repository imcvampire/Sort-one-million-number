#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

#define n 1000000 // Consumes 4MB
#define m 500000  // Consumes 2MB
#define p 250000

int main()
{
	int v[m];
	
	// Read first 500000 number
	for	 (int i = 0; i < m; ++i)
	{
		cin >> v[i];
	}
	
	sort(v[0], v[m - 1]);
	
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
	
	sort(v[0], v[m - 1]);
	
	fstream fsresult ("output.txt", fstream::out);
	fstream fstemp ("temp", fstream::in);
	
	// 2-way merge
	int temp[p];
	
	int i;
	for (i = 0; i < p; ++i)
	{
		fs >> temp[i];
	}
		
	
	return 0;
}