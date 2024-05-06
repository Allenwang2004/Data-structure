//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

void TourinMemo(int x0, int y0, int n)
{
    // ?建一?二????表示棋?
    int board[8][8] = {0};

    // ?建?????表示?士可能移?的八?方向
    int moveX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int moveY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    // ?起始位置???已??
    board[x0][y0] = 1;

    // ?建???量?表示?士?前位置的坐?
    int currentX = x0;
    int currentY = y0;

    // ?建一??量?表示下一步要??的位置的索引
    int nextMove = 0;

    // ?建一?字符串?量?存?棋?的字符串表示
    AnsiString boardStr;

    // 遍?所有可能的位置
    for (int step = 2; step <= n * n; step++)
    {
        // 在每一步之后，??前棋?的情?添加到 boardStr 中
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

        // ?找下一步的最佳移?位置
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

        // ?下一步的位置???已??
        board[nextX][nextY] = step;

        // 更新?前位置
		currentX = nextX;
        currentY = nextY;
    }

    // ?最?的棋?情?添加到 boardStr 中
    boardStr += "Step " + IntToStr(n * n) + ":\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            boardStr += IntToStr(board[i][j]) + "\t";
        }
        boardStr += "\n";
    }

    // 在 Memo 控件中?示?果
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
	TourinMemo(x0,y0,n);
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



