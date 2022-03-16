#include "stdio.h"
#include "windows.h"
#include "conio.h"

char aa[9][12]={{"*#*********"},{"***###*###*"},{"###**#****#"},{"*#**###**#*"},{"***********"},{"#####*##*##"},{"**#*****#*E"},{"***#*###**#"},{"*#*********"}};

void ans_aa()
{
	for(int i=0;i<9;i++)
	{
		puts(aa[i]);
	}
}
void bb(int x,int y)
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	printf("curX=%d,curY=%d\n",x,y);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);

}

int curX,curY;
int main()
{
	while(1)
	{
		system("cls");
		ans_aa();
		bb(curX,curY);

		char j=getch();
		if(j=='w')
		{
			if((curY-1)>=0 && (aa[curY-1][curX]=='*' || aa[curY-1][curX]=='E'))
				curY--;
		}
		else if(j=='s')
		{
			if((curY+1)<9 && (aa[curY+1][curX]=='*' || aa[curY+1][curX]=='E'))
				curY++;
		}
		else if(j=='a')
		{
			if((curY-1)>=0 && (aa[curY][curX-1]=='*' || aa[curY][curX-1]=='E'))
				curX--;
		}
		else if(j=='d')
		{
			if((curY+1)<11 && (aa[curY][curX+1]=='*' || aa[curY][curX+1]=='E'))
				curX++;
		}
		if(aa[curY][curX]=='E')
			break;
	}
	return 0;
}