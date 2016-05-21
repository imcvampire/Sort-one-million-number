#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define n 1000000

int main()
{
	// initialize random seed:
	srand (time(NULL));
	
	fstream fs ("input", fstream::out);
	
	for (int i = 0; i < n; ++i)
	{
		fs << rand() << endl;
	}
	
	fs.close();
	
	return 0;
}