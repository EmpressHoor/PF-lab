#include<iostream>
#include<conio.h>


using namespace std;
void turn1(int score)
{
	char array2[10][10];
	int a, b;
	a = score / 10;
	b = score % 10;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)                     //Nested Loops for filling 2D matrix with 0 int
		{
			array2[i][j] = '0';
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << "\t\t\t\t";
		for (int j = 0; j < 10; j++)                    //Nested Loops for printing your matrix
		{
			if (array2[i][j] == array2[a][b])
			{
				array2[a][b] = '*';
				cout << array2[a][b] << ' ';
			}
			else
				cout << array2[i][j] << " ";
		}
		cout << endl;
	}
}
void turn2(int score)
{
	char array2[10][10];
	int a, b;
	a = score / 10;
	b = score % 10;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)                     //Nested Loops for filling 2D matrix with 0 int
		{
			array2[i][j] = '0';
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << "\t\t\t\t";
		for (int j = 0; j < 10; j++)                    //Nested Loops for printing your matrix
		{
			if (array2[i][j] == array2[a][b])
			{
				array2[a][b] = '+';
				cout << array2[a][b] << ' ';
			}
			else
				cout << array2[i][j] << " ";
		}
		cout << endl;
	}
}
void line(int n, char ch)
{
	int i = 0;
	while (i < n)
	{
		cout << ch;
		i++;
	}
}
void dice(int& score)
{
	int dice;
	dice = rand() % 6 + 1;
	cout << "\nYou got " << dice << " Point !! ";
	score = score + dice;
	if (score > 100)
	{
		cout << "you cannot make a move\n";
		score = score - dice;
	}
	cout << "Now you are at position " << score << endl;
}
void gamescore(string P1, string P2, int S1, int S2)
{
	cout << "\n";
	line(50, '~');
	cout << "\n\t\tGAME STATUS\n";
	line(50, '~');
	cout << "\n\t" << P1 << " is at position " << S1 << endl;
	cout << "\t" << P2 << " is at position " << S2 << endl;
	line(50, '_');
	cout << endl;
}
void table(char array2[10][10])
{
	line(120, '=');
	line(120, '=');
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "\t\t\t\t";
		for (int j = 0; j < 10; j++)                    //Nested Loops for printing your matrix
		{
			cout << array2[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	char array1[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)                     //Nested Loops for filling 2D matrix with 0 int
		{
			array1[i][j] = '0';
		}
	}
	int	position;
	int n = 100, b, S1 = 0, S2 = 0, c = 0;
	string P1, P2;
	line(120, '=');
	line(120, '=');
	cout << "\n\n\t\t\t\t\tWELCOME TO SNAKE AND LADDER GAME\t\t\t\t\t\n\n";
	line(120, '=');
	line(120, '=');
	cout << "\n\t\t\t\t\t\tTAP (1) TO START\n";
	cout << "\n\t\t\t\t\t\tTAP (2) TO RESTART\n";
	cin >> b;
	system("cls");
	if (b == 1)
	{
		cout << "\n\n\t\t\t\t\t\t\tLET'S START\n";
		cout << "Enter the name of your players\n";
		cout << "Player 1:\n";
		cin >> P1;
		cout << "Player 2:\n";
		cin >> P2;
		cout << "Score of first player " << P1 << " is: " << S1 << endl;
		cout << "Score of second player " << P2 << " is: " << S2 << endl;
		cout << endl;
		table(array1);
		c = 0;
		b = 10;
		position = (rand() % 10) * 5;
		while (S1 <= 100 && S2 <= 100)
		{
			line(120, '*');
			cout << "\n\t\t\t\t\t" << P1 << " YOUR TURN\n";
			cout << "  \t\t\t\tPRESS ANY KEY TO ROLL THE DICE\n";
			line(120, '*');
			_getch();
			dice(S1);
			turn1(S1);
			if (S1 < position + 1)
			{
				S1 = S1 - position;
				cout << "\nALAS!!! YOU FOUND A SNAKE. NOW YOUR CURRENT POSITION IS: " << S1 << endl;
			}
			else if (S1 > position)
			{
				S1 = S1 + position;
				cout << "\nGREAT YOU GOT A LADDER. NOW YOUR CURRENT POSITION IS: " << S1 << endl;
			}
			line(120, '*');
			cout << "\n\t\t\t\t\t" << P2 << " YOUR TURN\n";
			cout << "   \t\t\t\t\tPRESS ANY KEY TO ROLL THE DICE\n";
			line(120, '*');
			_getch();
			dice(S2);
			turn2(S2);
			if (S2 < position + 1)
			{
				S2 = S2 - position;
				cout << "\nALAS!!! YOU FOUND A SNAKE. NOW YOUR CURRENT POSITION IS: " << S2 << endl;
			}
			else if (S2 > position)
			{
				S2 = S2 + position;
				cout << "\nGREAT YOU GOT A LADDER. NOW YOUR CURRENT POSITION IS: " << S2 << endl;
			}
			c = c + 2;
			if (S1 == 100 || S2 == 100)
			{
				break;
			}
			n++;
			_getch();
			system("cls");
		}
		cout << "YOUR CURRENT GAMESCORE IS: ";
		gamescore(P1, P2, S1, S2);
		cout << "\n\n\n";
		if (P1 > P2)
			cout << " CONGRATULATIONS!!! " << P1 << " YOU ARE THE WINNER OF THE GAME\n\n";
		else
			cout << " CONGRATULATIONS!!! " << P2 << " YOU ARE THE WINNER OF THE GAME\n\n";
		line(50, '_');
		cout << endl;
	}
	if (b == 2)
	{
		cout << "\n\n\t\t\t\t\t\t\tLET'S START\n";
		cout << "Enter the name of your players\n";
		cout << "Player 1:\n";
		cin >> P1;
		cout << "Player 2:\n";
		cin >> P2;
		cout << "Score of first player " << P1 << " is: " << S1 << endl;
		cout << "Score of second player " << P2 << " is: " << S2 << endl;
		cout << endl;
		table(array1);
		c = 0;
		b = 10;
		position = (rand() % 10) * 5;
		while (S1 <= 100 && S2 <= 100)
		{
			line(120, '*');
			cout << "\n\t\t\t\t\t" << P1 << " YOUR TURN\n";
			cout << "  \t\t\t\tPRESS ANY KEY TO ROLL THE DICE\n";
			line(120, '*');
			_getch();
			dice(S1);
			turn1(S1);
			if (S1 < position + 1)
			{
				S1 = S1 - position;
				cout << "\nALAS!!! YOU FOUND A SNAKE. NOW YOUR CURRENT POSITION IS: " << S1 << endl;
			}
			else if (S1 > position)
			{
				S1 = S1 + position;
				cout << "\nGREAT YOU GOT A LADDER. NOW YOUR CURRENT POSITION IS: " << S1 << endl;
			}
			line(120, '*');
			cout << "\n\t\t\t\t\t" << P2 << " YOUR TURN\n";
			cout << "   \t\t\t\t\tPRESS ANY KEY TO ROLL THE DICE\n";
			line(120, '*');
			_getch();
			dice(S2);
			turn2(S2);
			if (S2 < position + 1)
			{
				S2 = S2 - position;
				cout << "\nALAS!!! YOU FOUND A SNAKE. NOW YOUR CURRENT POSITION IS: " << S2 << endl;
			}
			else if (S2 > position)
			{
				S2 = S2 + position;
				cout << "\nGREAT YOU GOT A LADDER. NOW YOUR CURRENT POSITION IS: " << S2 << endl;
			}
			c = c + 2;
			if (S1 == 100 || S2 == 100)
			{
				break;
			}
			n++;
			_getch();
			system("cls");
		}
		cout << "YOUR CURRENT GAMESCORE IS: ";
		gamescore(P1, P2, S1, S2);
		cout << "\n\n\n";
		if (P1 > P2)
			cout << " CONGRATULATIONS!!! " << P1 << " YOU ARE THE WINNER OF THE GAME\n\n";
		else
			cout << " CONGRATULATIONS!!! " << P2 << " YOU ARE THE WINNER OF THE GAME\n\n";
		line(50, '_');
		cout << endl;
	}
	system("pause");
	return 0;
}
