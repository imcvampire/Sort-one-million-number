#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

#define n 1000000

int main()
{
	fstream fs1 ("input", fstream::in);
	vector<int> v1(n);
	
	for (int i = 0; i < n; ++i)
	{
		fs1 >> v1[i];
	}
	
	sort(v1.begin(), v1.end());
	
	fstream fs2 ("output", fstream::in);
	vector<int> v2(n);
	
	for (int i = 0; i < n; ++i)
	{
		fs2 >> v2[i];
	}
	
	for (int i = 0; i < n; ++i)
	{
		if (v1[i] != v2[i])
			cout << "Wrong in " << (i + 1) << endl;
	}
	
	return 0;
}