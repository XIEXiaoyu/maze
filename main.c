#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#include "maze.h"

int r, c, nrows, ncols;

int main(void)
{	
	int starting_row;
	int starting_col;

	int current_row;
	int current_col;

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
				starting_row = i;
				starting_col = j;
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

	move(starting_row, starting_col);

	// handle input
	int success = 0;
	while(success == 0)
	{
		getyx(wnd, current_row, current_col);
		char stroke = getch();
		char des;
		
		if(stroke == 'j')
		{	
			des = mvinch(current_row - 1, current_col) & A_CHARTEXT;
			if(current_row != 0 && des != 'X')
			{
				if(des == '$')
				{
					success = 1;
				}
				move(current_row - 1, current_col);
			}
			else
			{
				move(current_row, current_col);
			}
		}
		if(stroke == 'k')
		{
			des = mvinch(current_row + 1, current_col) & A_CHARTEXT;
			if(current_row < rows &&  des != 'X')
			{
				if(des == '$')
				{
					success = 1;
				}				
				move(current_row + 1, current_col);
			}
			else
			{
				move(current_row, current_col);
			}
		}
		if(stroke ==  'l')
		{
			des = mvinch(current_row, current_col - 1) & A_CHARTEXT;
			if(current_col != 0 &&  des != 'X')
			{
				if(des == '$')
				{
					success = 1;
				}
				move(current_row, current_col - 1);
			}
			else
			{
				move(current_row, current_col);
			}
		}
		if(stroke == 'm')
		{
			des = mvinch(current_row, current_col + 1) & A_CHARTEXT;

			if(current_col < cols &&  des != 'X')
			{
				if(des == '$')
				{
					success = 1;
				}
				move(current_row, current_col + 1);
			}
			else
			{
				move(current_row, current_col);
			}
		}
	}

	// while(1){
	// 	ch = getch();

	// 	if( ch == 'q' )
	// 	{
	// 		break;
	// 	}
	// }
	
	// stop
	endwin();
}