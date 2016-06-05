#include <stdio.h>

#define m 500000  // Consumes 2MB
#define p 333333  // Consumes 4/3 MB
#define o 333334

void swap(int *a, int *b)
{
	int n = *b;
	*b = *a;
	*a = n;
}

int leftchildnode(int n)
{
	return 2 * n + 1;
}

int rightchildnode(int n)
{
	return 2 * n + 2;
}

int parentnode(int n)
{
	return (n - 1) / 2;
}

void siftDown(int *a, int start, int count)
{
	int i = start;
	
	int imax = parentnode(count + 1);
	while (i > imax)
	{
		int currentnodeindex = i;
		int leftnodeindex = leftchildnode(i);
		int rightnodeindex = rightchildnode(i);
		
		if (leftnodeindex < count && a[leftnodeindex] > a[i])
		{
			i = leftnodeindex;
		}
		
		if (rightnodeindex < count && a[rightnodeindex] < a[i])
		{
			i = rightnodeindex;
		}
		
		if (i != currentnodeindex)
		{
			swap(&a[currentnodeindex], &a[i]);
		}
		else
			break;
	}
}

void heapify(int *a, int count)
{
	int i;
	
	for (i = parentnode(count - 1); i > -1; --i)
	{
		siftDown(a, i, count);
	}
}

void heapsort(int *a, int count)
{
	int end = count - 1;
	
	while (end > 0)
	{
		swap(&a[0], &a[end]);
		siftDown(a, 0, end);
		--end;
	}
}

int main()
{
	int a[6] = {6, 2, 4, 3, 5, 1};
	heapsort(a, 6);
	
	for (int i = 0; i < 6; ++i)
	{
		printf("%d\n", a[i]);
	}
	
	return 0;
}