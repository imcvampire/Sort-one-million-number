#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

#define n 1000000 // Consumes 4MB
#define m 500000  // Consumes 2MB

int main()
{	
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
		fstemp << v[i] << "\n";
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
	
	int i_temp;
	fs >> i_temp;
	
	int i = 0,	// index in v
		j = 0;	// index in temp
	int result = 0;
	
	while (i < m)
	{
		if (v[i] > i_temp)
		{
			cout << i_temp << endl;
			fs >> i_temp;
			++j;
		}
		else
		{
			cout << v[i] << endl;
			++i;
		}
		
		if (i == m) 
		{
			result = 1;
		}
		
		if (j == m)
		{
			result = -1;
			break;
		}
	}
	
	if (result == 1)
	{
		for (; j < m; ++j)
		{
			fs >> i_temp;
			cout << i_temp << endl;
		}
	} 
	else if (result == -1)
	{
		for (; i < m; ++i)
		{
			cout << v[i] << endl;
		}
	}
	
	fs.close();
	
	remove("temp");
	
	return 0;
	
}
