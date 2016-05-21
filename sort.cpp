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
	// fstream output ("output", fstream::out);
	
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

	
	
	fs.close();
	// output.close();
	
	return 0;
}