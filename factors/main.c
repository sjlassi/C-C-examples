#include <stdio.h>
#include <stdlib.h>

#define FACTORS_TABLE 		5
int  number_of_factors	=	0, table_size=0, n=0, i=0;
int *table=NULL, *current=NULL;


int main()
{
	//initialize the table for holding factors
	table = (int*)malloc(FACTORS_TABLE*sizeof(int));
	current = table;
	table_size = FACTORS_TABLE;

START:
	printf("Enter a number\n");
	scanf("%d", &n);
	if(n<=0)
	{
		printf("Please enter a positive non null number\n");
		goto START;
	}

	for(i=1; i<=n; i++)
	{
		if (0 == (n%i))
		{

			if (number_of_factors == table_size) // we need more rooms for factors
			{
				table = (int*)realloc(table,(table_size+FACTORS_TABLE)*sizeof(int));
				table_size += FACTORS_TABLE;
			}
			*(current++)=i;
			number_of_factors++;
		}
	}
	printf("%d has %d factors, which are: \n", n, number_of_factors);
	for(i=0; i<number_of_factors; i++)
		printf("\t%d\n", table[i]);

	return 0;
}
