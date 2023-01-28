#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <fstream>
using namespace std;

class Node
{
public:
	char letter;
	Node* next;
	Node* prev;
	Node() { next = prev = nullptr; letter = ' '; };
	Node(char c) { next = prev = nullptr; letter = c; };
};

void gotoxy(int x, int y)
{
	COORD kursor;
	kursor.X = x;
	kursor.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), kursor);
}

void main()
{
	int x, y;
	Node* start;
	Node* end;
	Node* curr;
	char c;
	Node* rows[10];
	int rowNumber = 0;

	for (int i = 0; i < 10; i++)
	{
		rows[i] = nullptr;
	}

	/*while (1)
	{
		c = _getch();
		cout << int(c) << endl;
	}*/

	start = end = curr = nullptr;
	x = y = 0;
	while ((c = _getch()) != 27)
	{
		if ((int)c == 0)
		{
			c = _getch();
			if ((int)c == 60)
			{
				ofstream outfile("c:\\temp\\output.txt");
				for (int i = 0; i < 10; i++)
				{
					if (rows[i] != nullptr)
					{
						Node* T;
						T = rows[i];
						while (T != nullptr)
						{
							outfile << T->letter;
							T = T->next;
						}
						outfile << endl;
					}
				}
				outfile.close();

			}
			if ((int)c == 61)
			{
				ifstream infile("c:\\temp\\input.txt");
				for (int i = 0; i < 10; i++)
				{
					/*while (!infile.eof())
					{
						c = infile.get();
						if (c = '\n')
						{
							newline();
						}
						else
						{
							inserttolinklist();
						}
					}*/
				}
				infile.close();
			}
		}
		else if ((int)c == 8) //backspace
		{
			end = end->prev;
			delete(end->next);
			end->next = nullptr;
			x--;
		}
		else if ((int)c == 13)
		{
			rowNumber++;
			start = end = curr = rows[rowNumber];
		}
		else if (start == nullptr)
		{
			Node* p = new Node(c);
			start = p;
			end = p;
			curr = p;
			rows[rowNumber] = start;
			start->prev = rows[rowNumber];
			x++;
		}
		else if (curr == end)
		{
			Node* p = new Node(c);
			end->next = p;
			p->prev = end;
			end = p;
			curr = end;
			x++;
		}
		else if ((int)c == -32)
		{
			c = _getch();
			if ((int)c == 75) // left
			{
				curr = curr->prev;
				x--;
			}
			if ((int)c == 77) // right
			{
				curr = curr->next;
				x++;
			}
		}
		//else if (curr->next != nullptr && curr->prev != nullptr) //insert in the middle
		//{
		//	Node* p = new Node(c);
		//	p->next = curr->next;
		//	curr->next->prev = p;
		//	p->prev = curr;
		//	curr->next = p;
		//	curr = p;
		//	x++;
		//}
		//if (curr == start) // insert at the start (having issues)
		//{
		//	Node* p = new Node(c);
		//	start->next = p;
		//	p->prev = start;
		//	start = p;
		//	curr = start;
		//	x++;
		//}
		system("cls");
		for (int i = 0; i < 10; i++)
		{
			if (rows[i] != nullptr)
			{
				Node* T;
				T = rows[i];
				while (T != nullptr)
				{
					cout << T->letter;
					T = T->next;
				}
				cout << endl;
			}
		}
		gotoxy(x, y);
	}
}