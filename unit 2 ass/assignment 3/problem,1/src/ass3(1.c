//Name        : ass3(1).c


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arr[2][2], arr2[2][2],arr3[2][2];

	printf("enter elemnts of the first matrix \n");
	for (int r=0;r<2;r++)
	{
		for(int c=0;c<2;c++)
		{
			printf("enter a%d%d:",r+1,c+1);
			fflush(stdin);fflush(stdout);
			scanf("%d",&arr[r][c]);
		}
	}
	printf("enter elemnts of the second matrix \n");
		for (int r=0;r<2;r++)
		{
			for(int c=0;c<2;c++)
			{
				printf("enter b%d%d:",r+1,c+1);
				fflush(stdin);fflush(stdout);
				scanf("%d",&arr2[r][c]);
			}
		}
		for(int r=0;r<2;r++)
		{
			for(int c=0;c>2;c++)
			{
				arr3[r][c]=arr[r][c]+arr2[r][c];
			}
		}

		printf("\n sum of matrix:");
		fflush(stdout);
		for(int r=0;r<2;r++)
				{
					for(int c=0;c>2;c++)
					{
					 printf("%d\t",arr3[r][c]);

//							 if(c==1)
//								 printf("\n");
					}
				}

	return EXIT_SUCCESS;
}
