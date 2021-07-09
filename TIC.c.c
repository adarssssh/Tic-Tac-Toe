#include<stdio.h>
#include<stdlib.h>
#include<time.h>
char s[10]={'0','1','2','3','4','5','6','7','8','9'};
char comp[10]={'C','O','M','P','U','T','E','R'},p1[10],p2[10];
int move=0,i,mode;
int checkwin();
int computer();
void board();
int main()
{
	srand(time(0));
	int player=(rand()%2)+1,i,c,choice;
	char mark;
	printf("1.Player vs AI\n2.Player vs Player\nEnter Your choice:");
	scanf("%d",&mode);
	switch(mode)
	{
		case 1:
		printf("Enter your name\n");
		scanf("%s",&p2);
		do
		{
			board();
			player=(player%2)?1:2;
			if(player==2)
			{
				printf("%s, enter a pos: ", p2);
				scanf("%d", &choice);
			}
			else
				choice=computer();
			mark=(player==1)?'X':'O';
			if(choice==1&&s[1]=='1')
			{
				s[1]=mark;
				move++;
			}
			else if(choice==2&&s[2]=='2')
			{
				s[2]=mark;
				move++;
			}
			else if(choice==3&&s[3]=='3')
			{
				s[3]=mark;
				move++;
			}
			else if(choice==4&&s[4]=='4')
			{
				s[4]=mark;
				move++;
			}
			else if(choice==5&&s[5]=='5')
			{
				s[5]=mark;
				move++;
			}
			else if(choice==6&&s[6]=='6')
			{
				s[6]=mark;
				move++;
			}
			else if(choice==7&&s[7]=='7')
			{
				s[7]=mark;
				move++;
			}
			else if(choice==8&&s[8]=='8')
			{
				s[8]=mark;
				move++;
			}
			else if(choice==9&&s[9]=='9')
			{
				s[9]=mark;
				move++;
			}
			else
			{
				printf("Invalid move ");
				player--;
			}
			i=checkwin();
			player++;
		}while(i==- 1);
		board();
		if(i==1)
		{
			--player;
			if(player==1)
				printf("Player %s win \n",comp);
			else
				printf("Player %s win \n",p2);
		}
		else
			printf("Game draw\n");
		return 0;
		case 2:
		printf("Enter the name of both the player\n");
		scanf("%s%s",p1,p2);
		do
		{
			board();
			player=(player%2)?1:2;
			if(player==1)
				printf("Player %s,Move: ",p1);
			else
				printf("Player %s,Move: ",p2);
			scanf("%d", &choice);
			mark=(player==1)?'X':'O';
			if(choice==1&&s[1]=='1')
				s[1]=mark;
			else if(choice==2&&s[2]=='2')
				s[2]=mark;
			else if(choice==3&&s[3]=='3')
				s[3]=mark;
			else if(choice==4&&s[4]=='4')
				s[4]=mark;
			else if(choice==5&&s[5]=='5')
				s[5]=mark;
			else if(choice==6&&s[6]=='6')
				s[6]=mark;
			else if(choice==7&&s[7]=='7')
				s[7]=mark;
			else if(choice==8&&s[8]=='8')
				s[8]=mark;
			else if(choice==9&&s[9]=='9')
				s[9]=mark;
			else
			{
				printf("Invalid move ");
				player--;
			}
			i = checkwin();
			player++;
		}while(i==-1);
		board();
		if (i==1)
		{
			if(player==2)
				printf("%s win \n",p1);
			else
				printf("%s win \n",p2);
		}
		else
			printf("Game draw\n");
		return 0;
		default:printf("Invalid Choice\n");
	}
	return 0;
}

//Winning Conditions//

int checkwin()
{
	if (s[1]==s[2]&&s[2]==s[3]) return 1;
	else if (s[4]==s[5]&&s[5]==s[6])return 1;
	else if (s[7]==s[8]&&s[8]==s[9])return 1;
	else if (s[1]==s[4]&&s[4]==s[7])return 1;
	else if (s[2]==s[5]&&s[5]==s[8])return 1;
	else if (s[3]==s[6]&&s[6]==s[9])return 1;
	else if (s[1]==s[5]&&s[5]==s[9])return 1;
	else if (s[3]==s[5]&&s[5]==s[7])return 1;
	else if (s[1]!='1'&&s[2]!='2'&&s[3]!='3'&&s[4]!='4'&&s[5]!='5'&&s[6]!='6'&&s[7]!='7'&&s[8]!='8'&&s[9]!='9')
		return 0;
	else
		return -1;
}
void board()
{
	if(mode==1)
	{
	printf("Computer=X - %s=O\n\n\n",p2);
	}
	else
	printf("%s=X - %s=O\n\n\n",p1,p2);
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c \n",s[1],s[2],s[3]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c \n",s[4],s[5],s[6]);
	printf("_____|_____|_____\n");
	printf("     |     | \n");
	printf("  %c  |  %c  |  %c \n",s[7],s[8],s[9]);
	printf("     |     | \n\n");
}
int computer()
{
	int r,flag=0;
	//Initail move for AI//
	if(s[5]!='X' && s[5] != 'O')
	{
		flag++;
		return 5;
	}

	if(s[1]==s[2]&&s[2]=='X'&&s[3]=='3')
	{
		flag++;
		return 3;
	}
	if(s[1]==s[3]&&s[3]=='X'&&s[2]=='2')
	{
		flag++;
		return 2;
	}
	if(s[2]==s[3]&&s[2]=='X'&&s[1]=='1')
	{
		flag++;
		return 1;
	}
	if(s[4]==s[5]&&s[5]=='X'&&s[6]=='6')
	{
		flag++;
		return 6;
	}
	if(s[5]==s[6]&&s[6]=='X'&&s[4]=='4')
	{
		flag++;
		return 4;
	}
	if(s[6]==s[4]&&s[6]=='X'&&s[5]=='5')
	{
		flag++;
		return 5;
	}
	if(s[7]==s[8]&&s[8]=='X'&&s[9]=='9')
	{
		flag++;
		return 9;
	}
	if(s[8]==s[9]&&s[8]=='X'&&s[7]=='7')
	{
		flag++;
		return 7;
	}
	if(s[9]==s[7]&&s[7]=='X'&&s[8]=='8')
	{
		flag++;
		return 8;
	}
	if(s[1]==s[4]&&s[4]=='X'&&s[7]=='7')
	{
		flag++;
		return 7;
	}
	if(s[4]==s[7]&&s[4]=='X'&&s[1]=='1')
	{
		flag++;
		return 1;
	}
	if(s[7]==s[1]&&s[1]=='X'&&s[4]=='4')
	{
		flag++;
		return 4;
	}
	if(s[2]==s[5]&&s[2]=='X'&&s[8]=='8')
	{
		flag++;
		return 8;
	}
	if(s[5]==s[8]&&s[8]=='X'&&s[2]=='2')
	{
		flag++;
		return 2;
	}
	if(s[8]==s[2]&&s[2]=='X'&&s[5]=='5')
	{
		flag++;
		return 5;
	}
	if(s[3]==s[5]&&s[5]=='X'&&s[7]=='7')
	{
		flag++;
		return 7;
	}
	if(s[5]==s[7]&&s[7]=='X'&&s[3]=='3')
	{
		flag++;
		return 3;
	}
	if(s[7]==s[3]&&s[3]=='X'&&s[5]=='5')
	{
		flag++;
		return 5;
	}
	if(s[3]==s[6]&&s[3]=='X'&&s[9]=='9')
	{
		flag++;
		return 9;
	}
	if(s[6]==s[9]&&s[9]=='X'&&s[3]=='3')
	{
		flag++;
		return 3;
	}
	if(s[9]==s[3]&&s[9]=='X'&&s[6]=='6')
	{
		flag++;
		return 6;
	}
	if(s[1]==s[5]&&s[5]=='X'&&s[9]=='9')
	{
		flag++;
		return 9;
	}
	if(s[5]==s[9]&&s[9]=='X'&&s[1]=='1')
	{
		flag++;
		return 1;
	}
	if(s[9]==s[1]&&s[9]=='X'&&s[5]=='5')
	{
		flag++;
		return 5;
	}
	if(s[1]==s[2]&&s[2]=='O'&&s[3]=='3')
	{
		flag++;
		return 3;
	}
	if(s[1]==s[3]&&s[3]=='O'&&s[2]=='2')
	{
		flag++;
		return 2;
	}
	if(s[2]==s[3]&&s[2]=='O'&&s[1]=='1')
	{
		flag++;
		return 1;
	}
	if(s[4]==s[5]&&s[5]=='O'&&s[6]=='6')
	{
		flag++;
		return 6;
	}
	if(s[5]==s[6]&&s[6]=='O'&&s[4]=='4')
	{
		flag++;
		return 4;
	}
	if(s[6]==s[4]&&s[6]=='O'&&s[5]=='5')
	{
		flag++;
		return 5;
	}
	if(s[7]==s[8]&&s[8]=='O'&&s[9]=='9')
	{
		flag++;
		return 9;
	}
	if(s[8]==s[9]&&s[8]=='O'&&s[7]=='7')
	{
		flag++;
		return 7;
	}
	if(s[9]==s[7]&&s[7]=='O'&&s[8]=='8')
	{
		flag++;
		return 8;
	}
	if(s[1]==s[4]&&s[4]=='O'&&s[7]=='7')
	{
		flag++;
		return 7;
	}
	if(s[4]==s[7]&&s[4]=='O'&&s[1]=='1')
	{
		flag++;
		return 1;
	}
	if(s[7]==s[1]&&s[1]=='O'&&s[4]=='4')
	{
		flag++;
		return 4;
	}
	if(s[2]==s[5]&&s[2]=='O'&&s[8]=='8')
	{
		flag++;
		return 8;
	}
	if(s[5]==s[8]&&s[8]=='O'&&s[2]=='2')
	{
		flag++;
		return 2;
	}
	if(s[8]==s[2]&&s[2]=='O'&&s[5]=='5')
	{
		flag++;
		return 5;
	}
	if(s[3]==s[5]&&s[5]=='O'&&s[7]=='7')
	{
		flag++;
		return 7;
	}
	if(s[5]==s[7]&&s[7]=='O'&&s[3]=='3')
	{
		flag++;
		return 3;
	}
	if(s[7]==s[3]&&s[3]=='O'&&s[5]=='5')
	{
		flag++;
		return 5;
	}
	if(s[3]==s[6]&&s[3]=='O'&&s[9]=='9')
	{
		flag++;
		return 9;
	}
	if(s[6]==s[9]&&s[9]=='O'&&s[3]=='3')
	{
		flag++;
		return 3;
	}
	if(s[9]==s[3]&&s[9]=='O'&&s[6]=='6')
	{
		flag++;
		return 6;
	}
	if(s[1]==s[5]&&s[5]=='O'&&s[9]=='9')
	{
		flag++;
		return 9;
	}
	if(s[5]==s[9]&&s[9]=='O'&&s[1]=='1')
	{
		flag++;
		return 1;
	}
	if(s[9]==s[1]&&s[9]=='O'&&s[5]=='5')
	{
		flag++;
		return 5;
	}

//Two special Condition which makes AI unbeatable//

		if(s[5]==s[9] && s[3]=='3')
	{
		flag++;
		return 3;
	}
    if(s[8]==s[1] && s[7]=='7')
	{
		flag++;
		return 7;
	}
	if(flag==0)
	{
		if(s[1]=='1')
			return 1;
		if(s[2]=='2')
			return 2;
		if(s[3]=='3')
			return 3;
		if(s[4]=='4')
			return 4;
		if(s[5]=='5')
			return 5;
		if(s[6]=='6')
			return 6;
		if(s[7]=='7')
			return 7;
		if(s[8]=='8')
			return 8;
		if(s[9]=='9')
			return 9;
	}
	return 0;
}
