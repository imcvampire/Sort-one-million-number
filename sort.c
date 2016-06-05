#include <stdio.h>
#include <stdlib.h>

#define m 500000  // Consumes 2MB
#define p 333333  // Consumes 4/3 MB
#define o 333334

void swap(int *a, int *b)
{
	int n = *b;
	*b = *a;
	*a = n;
}

void quicksort(int a[], int left, int right)
{
	int i = left, j = right;
	int pivot = a[(left + right) / 2];
	do
	{
		while (a[i] < pivot && i < right) i++;
		while (a[j] > pivot && j > left) j--;
		if (i <= j)
    	{
      		swap(&a[i], &a[j]);
      		i++; 
      		j--;
    	}
  	} while (i <= j);
   
  	if (left < j) quicksort(a, left, j);
  	if (i < right) quicksort(a, i, right);
}

int midpoint(int imin, int imax) 
{
	return (imin + imax) / 2;
}

int main()
{
	int *a = NULL;
	a = (int *) malloc(p * sizeof(int));
	
	// Take first 333333 number
	int i;
	
	for (i = 0; i < p; ++i)
	{
		scanf("%d", &a[i]);	
	}
	
	quicksort(a, 0, p);
	
	FILE *f1 = fopen("temp1", "w");
	
	for (i = 0; i < p; ++i)
	{
		fprintf(f1, "%d\n", a[i]);
	}
	
	fclose(f1);
	
	// Take next 333333 number
	for (i = 0; i < p; ++i)
	{
		scanf("%d", &a[i]);	
	}
	
	quicksort(a, 0, p);
	
	FILE *f2 = fopen("temp2", "w");
	
	for (i = 0; i < p; ++i)
	{
		fprintf(f2, "%d\n", a[i]);
	}
	
	fclose(f2);
	
	// Sort last 333334 number
	free(a);
	a = (int *) malloc(o * sizeof(int));
	
	for (i = 0; i < o; ++i)
	{
		scanf("%d", &a[i]);	
	}
	
	quicksort(a, 0, o);
	
	// 2-way merge 2 temp file
	f1 = fopen("temp1", "r");
	f2 = fopen("temp2", "r");
	
	FILE *f = fopen("temp", "w");
	
	int i1 = 0,	// index in f1
		i2 = 0;	// index in f2
	int check = 0;
	
	int i_f1, i_f2;
	
	fscanf(f1, "%d", &i_f1);
	fscanf(f2, "%d", &i_f2);
	
	while (i1 < p && i2 < p)
	{
		if (i_f1 > i_f2)
		{
			fprintf(f, "%d\n", i_f2);
			fscanf(f2, "%d", &i_f2);
			++i2;
		}
		else
		{
			fprintf(f, "%d\n", i_f1);
			fscanf(f1, "%d", &i_f1);
			++i1;
		}
		
		if (i1 == p)
		{
			check = 1;
		}
		if (i2 == p)
		{
			check = 2;
		}
	}
	
	if (check == 1)
	{
		for (; i2 < p; ++i2)
		{
			fprintf(f, "%d", &i_f2);
			fscanf(f2, "%d", &i_f2);
		}
	}
	
	if (check == 2)
	{
		for (; i1 < p; ++i1)
		{
			fprintf(f, "%d", &i_f1);
			fscanf(f1, "%d", &i_f1);
		}
	}
	
	return 0;
}