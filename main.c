#include <stdio.h>
#include <stdlib.h>

#include "maze.h"

int main(void)
{
	int ch;
	FILE *fp;
	char fname[50];

	printf("Enter the name of the maze input file: ");
	scanf("%s", fname);
	fp = fopen(fname, "r");
	if(fp == NULL)
	{
		printf("failed to open the file. Bye.\n");
		exit(1);
	}
	while((ch = getc(fp)) != EOF)
	{
		if(ch == '\n')
		{
			putchar(ch);
		}
		else if(ch == 1)
		{
			putchar('X');
		}
		else if(ch == 2)
		{
			putchar('@');
		}
		else if(ch == 0)
		{
			putchar('.');
		}
		else if(ch == 3)
		{
			putchar('$');
		}
		else
		{
			putchar(ch);
		}
	}
	putchar('\n');
	fclose(fp);

	return 0;
}