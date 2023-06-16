/*
 ============================================================================
 Name        : ass3(3).c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arr[50][50],b[50][50];
	int x,y;
	printf("enter rows and columns of the matrix ");
	fflush(stdin);fflush(stdout);
	scanf("%d%d",&x,&y);
	for(int r=0;r<x;r++)
	{
		for(int c=0;c<y;c++)
		{
			printf("enter element a%d%d",r+1,c+1);
			fflush(stdin);fflush(stdout);
		    scanf("%d",&arr[r][c]);
		}
	}
	printf("entered matrix\n ");
	for(int r=0;r<x;r++)
		{
			for(int c=0;c<y;c++)
			{
	printf("%d\t",arr[r][c]);
			if(c==y-1)
	printf(" \n");
			}
		}

	for(int r=0;r<x;r++)
		{
			for(int c=0;c<y;c++)
			{
				b[c][r]=arr[r][c];
			}
		}

	printf("transpose of  matrix\n ");
		for(int r=0;r<y;r++)
			{
				for(int c=0;c<x;c++)
				{
		printf("%d  ",b[r][c]);
				if(c==x-1)
		printf(" \n");
				}
			}

	return EXIT_SUCCESS;
}
