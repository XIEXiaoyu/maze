#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#include "maze.h"

int r, c, nrows, ncols;

int main(void)
{	
	//
	char fname[50];
	printf("input file: ");
	scanf("%s", fname);

	WINDOW *wnd;
	wnd = initscr(); 
	cbreak(); 
	noecho(); 
	getmaxyx(wnd,nrows,ncols); 

	r = 0, c = 0;
	char ch;
	FILE *fp;
	fp = fopen(fname, "r");

	int rows, cols;
	char temp;

	rows = getc(fp)-'0';
	cols = getc(fp)-'0';
	temp = getc(fp);

	for(int i = 0; i < rows; i++)
	{
		move(r,c);

		for(int j = 0; j <= cols; j++)
		{
			char num = getc(fp);
			
			if(num == '\n')
			{
				ch = '\n';
			}
			else if(num == '2')
			{
				ch = '@';
			}
			else if(num == '0')
			{
				ch = '.';
			}
			else if(num == '1')
			{
				ch = 'X';
			}
			else 
			{
				ch = '$';
			}
			addch(ch);
			c++;
		}
		r++;
		c = 0;
	}
	fclose(fp);

	// handle input

	while(1){
		ch = getch();

		if( ch == 'q' )
		{
			break;
		}
	}

	// stop
	endwin();
}