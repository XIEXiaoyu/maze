#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#include "maze.h"

int r,c, // current row and column (upper-left is (0,0))
nrows, // number of rows in window
ncols; // number of columns in window

void draw(char dc)
{
	move(r,c); // curses call to move cursor to row r, column c
	delch(); insch(dc); // curses calls to replace character under cursor by dc
	refresh(); // curses call to update screen
	r++; // go to next row
	// check for need to shift right or wrap around
	if (r == nrows) {
		r = 0;
		c++;
		if (c == ncols) c = 0;
	}
}

int main(void)
{
	/*
	// int ch;
	// FILE *fp;
	// char fname[50];

	// printf("Enter the name of the maze input file: ");
	// scanf("%s", fname);
	// fp = fopen(fname, "r");
	// if(fp == NULL)
	// {
	// 	printf("failed to open the file. Bye.\n");
	// 	exit(1);
	// }
	// while((ch = getc(fp)) != EOF)
	// {
	// 	if(ch == '\n')
	// 	{
	// 		putchar(ch);
	// 	}
	// 	else if(ch == 1)
	// 	{
	// 		putchar('X');
	// 	}
	// 	else if(ch == 2)
	// 	{
	// 		putchar('@');
	// 	}
	// 	else if(ch == 0)
	// 	{
	// 		putchar('.');
	// 	}
	// 	else if(ch == 3)
	// 	{
	// 		putchar('$');
	// 	}
	// 	else
	// 	{
	// 		putchar(ch);
	// 	}
	// }
	// putchar('\n');
	// fclose(fp);
	*/

	int i; char d;
	WINDOW *wnd;
	wnd = initscr(); // curses call to initialize window
	cbreak(); // curses call to set no waiting for Enter key
	noecho(); // curses call to set no echoing
	getmaxyx(wnd,nrows,ncols); // curses call to find size of window
	// printf("nrows is: %d.\n", nrows);
	// printf("ncols is: %d.\n", ncols);
	clear(); // curses call to clear screen, send cursor to position (0,0)
	refresh(); // curses call to implement all changes since last refresh

	r = 0; c = 0;
	while (1) 
	{
		d = getch(); // curses call to input from keyboard
		if (d == 'q') break; // quit?
		draw(d); // draw the character
	}

	endwin(); // curses call to restore the original window and leave

	return 0;
}