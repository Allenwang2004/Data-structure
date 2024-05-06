
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

void Findsolution(int x0, int y0, int n)
{
	int board[100][100] = {0};
	int moveX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	int moveY[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	int currentX = x0;
	int currentY = y0;
	int nextMove = 0;
	bool correct = true;
	int count = 0;

	for (int step = 1; step <= n * n; step++)
	{
		board[currentX][currentY] = step;
		int minMoveCount = 8;
		int nextX = -1, nextY = -1;
		bool past = false;
		for (int i = 0; i < 8; i++)
		{
			int newX = currentX + moveX[i];
			int newY = currentY + moveY[i];
			if (newX >= 0 && newX < n && newY >= 0 && newY < n && board[newX][newY] == 0)
			{
				if(past == false)
				{
					count++;
					past = true;
				}
				int moveCount = 0;
				for (int j = 0; j < 8; j++)
				{
					int testX = newX + moveX[j];
					int testY = newY + moveY[j];
					if (testX >= 0 && testX < n && testY >= 0 && testY < n && board[testX][testY] == 0)
					{
						moveCount++;
					}
				}
				if (moveCount < minMoveCount)
				{
					minMoveCount = moveCount;
					nextX = newX;
					nextY = newY;
				}
			}
		}

		currentX = nextX;
		currentY = nextY;

	}

	if( count != n*n-1)
	{
		correct = false;
	}

	AnsiString boardStr;
	if(correct)
	{
		boardStr += "There is solution!";
		boardStr += "\n";
	}
	else
	{
		boardStr += "There isn't solution!" ;
		boardStr += "\n";
	}

	Form2->Memo1->Lines->Text = boardStr;
}

void TourinMemo(int x0, int y0, int n)
{
	int board[12][12] = {0};
	int moveX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	int moveY[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	int currentX = x0;
	int currentY = y0;
	int nextMove = 0;
	bool correct = true;
	int count = 0;

	for (int step = 1; step <= n * n; step++)
	{
		board[currentX][currentY] = step;
		int minMoveCount = 8;
		int nextX = -1, nextY = -1;
		bool past = false;
		for (int i = 0; i < 8; i++)
		{
			int newX = currentX + moveX[i];
			int newY = currentY + moveY[i];
			if (newX >= 0 && newX < n && newY >= 0 && newY < n && board[newX][newY] == 0)
			{
				if(past == false)
				{
					count++;
					past = true;
				}
				int moveCount = 0;
				for (int j = 0; j < 8; j++)
				{
					int testX = newX + moveX[j];
					int testY = newY + moveY[j];
					if (testX >= 0 && testX < n && testY >= 0 && testY < n && board[testX][testY] == 0)
					{
						moveCount++;
					}
				}
				if (moveCount < minMoveCount)
				{
					minMoveCount = moveCount;
					nextX = newX;
					nextY = newY;
				}
			}
		}

		currentX = nextX;
		currentY = nextY;

	}

	if( count != n*n-1)
	{
		correct = false;
	}

	AnsiString boardStr;
	if(correct)
	{
		boardStr += "There is solution!";
		boardStr += "\n";
	}
	else
	{
		boardStr += "There isn't solution!" ;
		boardStr += "\n";
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			boardStr += IntToStr(board[i][j]) + "\t";
		}
		boardStr += "\n";
	}

	Form2->Memo1->Lines->Text = boardStr;
}


void TourinMemoS(int x0, int y0, int n)
{
	int board[12][12] = {0};

	int moveX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	int moveY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

	board[x0][y0] = 1;

	int currentX = x0;
	int currentY = y0;

	int nextMove = 0;

	AnsiString boardStr;

	for (int step = 2; step <= n * n; step++)
	{
		boardStr += "Step " + IntToStr(step - 1) + ":\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				boardStr += IntToStr(board[i][j]) + "\t";
			}
			boardStr += "\n";
		}
		boardStr += "\n";

        int minMoveCount = 8;
        int nextX = -1, nextY = -1;
        for (int i = 0; i < 8; i++)
        {
            int newX = currentX + moveX[i];
            int newY = currentY + moveY[i];
            if (newX >= 0 && newX < n && newY >= 0 && newY < n && board[newX][newY] == 0)
            {
                int moveCount = 0;
                for (int j = 0; j < 8; j++)
                {
                    int testX = newX + moveX[j];
                    int testY = newY + moveY[j];
                    if (testX >= 0 && testX < n && testY >= 0 && testY < n && board[testX][testY] == 0)
                    {
                        moveCount++;
                    }
                }
                if (moveCount < minMoveCount)
                {
                    minMoveCount = moveCount;
                    nextX = newX;
                    nextY = newY;
                }
            }
        }

		board[nextX][nextY] = step;
		currentX = nextX;
        currentY = nextY;
    }

	boardStr += "Step " + IntToStr(n * n) + ":\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
        {
            boardStr += IntToStr(board[i][j]) + "\t";
        }
        boardStr += "\n";
    }

	Form2->Memo1->Lines->Text = boardStr;
}


//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	int x0 = 0;
	int y0 = 0;
	int n = 0;
	if (CheckBox1->Checked)
	{
		x0 = StrToInt(Edit4->Text);
		y0 = StrToInt(Edit5->Text);
	}
	else
	{
		x0 = StrToInt(Edit2->Text);
		y0 = StrToInt(Edit3->Text);
	}
	n = StrToInt(Edit1->Text);
	TourinMemoS(x0,y0,n);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
	int n = StrToInt(Edit1->Text);
	srand(time(NULL));

	// 生成隨機的 X 和 Y 座標
	int x0 = rand() % (n);
	int y0 = rand() % (n);
	Edit4->Text = IntToStr(x0);
	Edit5->Text = IntToStr(y0);
}
//---------------------------------------------------------------------------



void __fastcall TForm2::Button3Click(TObject *Sender)
{
	int x0 = 0;
	int y0 = 0;
	int n = 0;
	if (CheckBox1->Checked)
	{
		x0 = StrToInt(Edit4->Text);
		y0 = StrToInt(Edit5->Text);
	}
	else
	{
		x0 = StrToInt(Edit2->Text);
		y0 = StrToInt(Edit3->Text);
	}
	n = StrToInt(Edit1->Text);
	TourinMemo(x0,y0,n);

}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button4Click(TObject *Sender)
{
	int x0 = 0;
	int y0 = 0;
	int n = 0;
	if (CheckBox1->Checked)
	{
		x0 = StrToInt(Edit4->Text);
		y0 = StrToInt(Edit5->Text);
	}
	else
	{
		x0 = StrToInt(Edit2->Text);
		y0 = StrToInt(Edit3->Text);
	}
	n = StrToInt(Edit1->Text);
	Findsolution(x0,y0,n);
}
//---------------------------------------------------------------------------

