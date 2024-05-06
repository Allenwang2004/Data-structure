//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MagicSquare.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#define SWAP(x,y) {int t; t = x; x = y; y = t;}
int flag1,flag2;
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
int N = StrToInt(Edit1->Text);
	int matrix[N][N];
	for (int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			matrix[i][j]==0;
	int key =1;
	if(flag1==1 and flag2==1)
	{
		int i =0;
		int j = (N-1) / 2;
        matrix[i][j]=1;
		for(key = 2; key <= N*N; key++)
		{
			if((key % N) == 1)
				i++;      //�I�쩳���ɭ�
			else
			{
				i--;
				j--;       //���ʪ���V
			}

			if(i == -1)
				i = N-1;
			if(j == -1 )
				j = N-1;

			matrix[i][j] = key;
		}
	}
	else if(flag1==1 and flag2==2)
	{
        int i =0;
		int j = (N-1) / 2;
        matrix[i][j]=1;
		for(key = 2; key <= N*N; key++)
		{
			if((key % N) == 1)
				i++;
			else {
				i--;
				j++;     //���ʤ�V
			}

			if(i == -1)  //���쩳
				i = N-1;
			if(j == N)    //��}
				j = 0;
			matrix[i][j] = key;
		}
	}
	else if(flag1==1 and flag2==3)
	{
		int i =0;
		int j = (N-1) / 2;
        matrix[i][j]=1;
		for(key = 2; key <= N*N; key++)
		{
			if((key % N)== 1)
				i--;
			else
			{
				j--;
				i++;
			}

			if(j == -1)
				j = N-1;
			if(i == N)
				i = 0;
            if(i == -1)
                i = N-1;
			matrix[i][j] = key;
		}
	}
	else if(flag1==1 and flag2==4)
	{
	int i = 0;
		int j = (N-1) / 2;
        matrix[i][j]=1;
		for(key = 2; key <= N*N; key++)
		{
			if((key % N) == 1)
				i--;
			else
			{
				j++;
				i++;
			}

			if(i == N)
				i = 0;
			if(j == N)
				j = 0;
            if(i==-1)
                i=N-1;
			matrix[i][j] = key;
		}
	}
	else if(flag1==2 and flag2==1)
	{
		int i = (N-1) / 2;
		int j = N-1;
        matrix[i][j]=1;
		for(key = 2; key <= N*N; key++)
		{
			if((key % N) == 1)
				i++;
			else
			{
				i--;
				j--;
			}

			if(i == -1)
				i = N-1;
			if(j == -1 )
				j = N-1;
            if( i== N)
                i = 0;

			matrix[i][j] = key;
		}
	}
	else if(flag1==2 and flag2==2)
	{
		int i = (N-1) / 2;
		int j = N-1;
        matrix[i][j]=1;
		for(key = 2; key <= N*N; key++)
		{
			if((key % N) == 1)
				i++;
			else {
				i--;
				j++;
			}

			if(i == -1)   //���쩳
				i = N-1;
			if(j == N)    //��}
				j = 0;
            if(i == N)
                i = 0;

			matrix[i][j] = key;
		}
	}
	else if(flag1==2 and flag2==3)
	{
		int i = (N-1) / 2;
		int j = N-1;
        matrix[i][j]=1;
		for(key = 2; key <= N*N; key++)
		{
			if((key % N) == 1)
				i--;
			else
			{
				j--;
				i++;
			}

			if(j == -1)
				j = N-1;
			if(i == N)
				i = 0;
            if(i==-1)
                i = N-1;

			matrix[i][j] = key;
		}
	}
	else if(flag1==2 and flag2==4)
	{
		int i = (N-1) / 2;
		int j = N-1;
        matrix[i][j]=1;
		for(key = 2; key <= N*N; key++)
		{
			if((key % N) == 1)
				i--;
			else
			{
				j++;
				i++;
			}

			if(i == N)
				i = 0;
			if(j == N)
				j = 0;
            if(i==-1)
                i = N-1;
			matrix[i][j] = key;
		}
	}
	else if(flag1==3 and flag2==1)
	{
		int i = N-1;
		int j = (N-1) / 2;
        matrix[i][j]=1;
		for(key = 2; key <= N*N; key++)
		{
			if((key % N) == 1)
				i++;
			else
			{
				i--;
				j--;
			}

			if(i == -1)
				i = N-1;
			if(j == -1 )
				j = N-1;
            if(i==N)
                i=0;

			matrix[i][j] = key;
		}
	}
	else if(flag1==3 and flag2==2)
	{
		int i = N-1;
		int j = (N-1) / 2;
        matrix[i][j]=1;
		for(key = 2; key <= N*N; key++)
		{
			if((key % N) == 1)
				i++;
			else {
				i--;
				j++;
			}

			if(i == -1)   //���쩳
				i = N-1;
			if(j == N)    //��}
				j = 0;
            if(i==N)
                i=0;

			matrix[i][j] = key;
		}
	}
	else if(flag1==3 and flag2==3)
	{
		int i = N-1;
		int j = (N-1) / 2;
        matrix[i][j]=1;
		for(key = 2; key <= N*N; key++)
		{
			if((key % N) == 1)
				i--;
			else
			{
				j--;
				i++;
			}

			if(j == -1)
				j = N-1;
			if(i == N)
				i = 0;

			matrix[i][j] = key;
		}
	}
	else if(flag1==3 and flag2==4)
	{
		int i = N-1;
		int j = (N-1) / 2;
        matrix[i][j]=1;
		for(key = 2; key <= N*N; key++)
		{
			if((key % N) == 1)
				i--;
			else
			{
				j++;
				i++;
			}

			if(i == N)
				i = 0;
			if(j==N)
				j = 0;

			matrix[i][j] = key;
		}
	}
	else if(flag1==4 and flag2==1)
	{
		int i = (N-1) / 2 ;
		int j = 0;
        matrix[i][j]=1;
		for(key = 2; key <= N*N; key++)
		{
			if((key % N) == 1)
				i++;
			else
			{
				i--;
				j--;
			}

			if(i == -1)
				i = N-1;
			if(j == -1 )
				j = N-1;
            if(i==N)
                i=0;
			matrix[i][j] = key;
		}
	}
	else if(flag1==4 and flag2==2)
	{
		int i = (N-1) / 2;
		int j = 0;
        matrix[i][j]=1;
		for(key = 2; key <= N*N; key++)
		{
			if((key % N) == 1)
				i++;
			else {
				i--;
				j++;
			}

			if(i == -1)   //���쩳
				i = N-1;
			if(j ==N)    //��}
				j = 0;
            if(i==N)
                i=0;
			matrix[i][j] = key;
		}
	}
	else if(flag1==4 and flag2==3)
	{
		int i = (N-1) / 2;
		int j = 0;
        matrix[i][j]=1;
		for(key = 2; key <= N*N; key++)
		{
			if((key % N) == 1)
				i--;
			else
			{
				j--;
				i++;
			}

			if(j == -1)
				j = N-1;
			if(i ==N)
				i = 0;
            if(i==-1)
                i=N-1;
			matrix[i][j] = key;
		}
	}
	else if(flag1==4 and flag2==4)
	{
		int i = (N-1) / 2;
		int j = 0;
        matrix[i][j]=1;
		for(key = 2; key <= N*N; key++)
		{
			if((key % N) == 1)
				i--;
			else
			{
				j++;
				i++;
			}

			if(i == N)
				i = 0;
			if(j == N)
				j = 0;
            if(i==-1)
                i=N-1;
			matrix[i][j] = key;
		}
	}
	int m, n ,k;
	String row,space;
	int len = IntToStr(N*N).Length()+2;
	for(m = 0; m < N; m++)
	{
		row="";
		for(n = 0; n < N; n++)
		{
			space = len-IntToStr(matrix[m][n]).Length();
			for(k=0;k<space;k++)
				row+="";
			row+=IntToStr(matrix[m][n]);
		}
		Form1->Memo1->Lines->Add(row);

	}
	for(m=0; m<N;m++)
	{
		row="";
		for(n=0; n<N; n++)
		{
			space = len-IntToStr(matrix[m][n]).Length();
			for(k=0;k<space;k++)
				row+="  ";
			row+=IntToStr(matrix[m][n]);
		}
		Form1->Memo2->Lines->Add(row);

	}
	int sum=0;
	for(m=0; m<N;m++)    //�˴�
	{
		row="";
		for(n=0; n<N; n++)
		{
			space = len-IntToStr(matrix[m][n]).Length();
			sum=sum+matrix[m][n];
			for(k=0;k<space;k++)
				row+="  ";
			row+=IntToStr(matrix[m][n]);

		}
		row+="   --";
		row+=IntToStr(sum);
		Form1->Memo3->Lines->Add(row);
		sum=0;
	}
	row="";
	for(n=0; n<N; n++)
	{
		for(m=0; m<N; m++)
		{
			sum=sum+matrix[m][n];
		}
		space = len-IntToStr(sum).Length();
			for(k=0;k<space-1;k++)
				row+="  ";
		row+=" |";
		row+=IntToStr(sum);
		sum=0;
	}
	Form1->Memo3->Lines->Add(row);

	StringGrid1->RowCount = N;
	StringGrid1->ColCount = N;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			StringGrid1->Cells[j][i] = IntToStr(matrix[i][j]);
		}
	}
}
//---------------------------------------------------------------------------




void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
	flag1=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton3Click(TObject *Sender)
{
	flag1=4;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
	flag1=3;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton4Click(TObject *Sender)
{
	flag1=2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton5Click(TObject *Sender)
{
	flag2=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton7Click(TObject *Sender)
{
    flag2=2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton6Click(TObject *Sender)
{
    flag2=3;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton8Click(TObject *Sender)
{
    flag2=4;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{
int N = StrToInt(Edit2->Text);
int matrix2[N][N];
int p=1;
for (int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			matrix2[i][j]=p;
			p++;
		}

int array[1000];
int t=0;
for (int i=0;i<N;i++)
{
		for(int j=0;j<N;j++)
		{
			if(((i%4==0 or i%4==3)and(j%4==0 or j%4==3)) or ((i%4==1 or i%4==2)and(j%4==1 or j%4==2)))
				{
					array[t]=matrix2[i][j];
					t++;
				}
		}
}
t=0;
for (int i=N-1;i>-1;i--)
{
		for(int j=N-1;j>-1;j--)
		{
			if(((i%4==0 or i%4==3)and(j%4==0 or j%4==3)) or ((i%4==1 or i%4==2)and(j%4==1 or j%4==2)))
				{
					matrix2[i][j]=array[t];
					t++;
				}
		}
}
int m, n ,k;
	String row,space;
	int len = IntToStr(N*N).Length()+2;
	for(m = 0; m < N; m++)
	{
		row="";
		for(n = 0; n < N; n++)
		{
			space = len-IntToStr(matrix2[m][n]).Length();
			for(k=0;k<space;k++)
				row+="";
			row+=IntToStr(matrix2[m][n]);
		}
		Form1->Memo5->Lines->Add(row);

	}
	for(m=0; m<N;m++)
	{
		row="";
		for(n=0; n<N; n++)
		{
			space = len-IntToStr(matrix2[m][n]).Length();
			for(k=0;k<space;k++)
				row+="  ";
			row+=IntToStr(matrix2[m][n]);
		}
		Form1->Memo6->Lines->Add(row);

	}
	int sum=0;
	for(m=0; m<N;m++)    //�˴�
	{
		row="";
		for(n=0; n<N; n++)
		{
			space = len-IntToStr(matrix2[m][n]).Length();
			sum=sum+matrix2[m][n];
			for(k=0;k<space;k++)
				row+="  ";
			row+=IntToStr(matrix2[m][n]);

		}
		row+="   --";
		row+=IntToStr(sum);
		Form1->Memo7->Lines->Add(row);
		sum=0;
	}
	row="";
	for(n=0; n<N; n++)
	{
		for(m=0; m<N; m++)
		{
			sum=sum+matrix2[m][n];
		}
		space = len-IntToStr(sum).Length();
			for(k=0;k<space-1;k++)
				row+="  ";
		row+=" |";
		row+=IntToStr(sum);
		sum=0;
	}
	Form1->Memo7->Lines->Add(row);

	StringGrid2->RowCount = N;
	StringGrid2->ColCount = N;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			StringGrid2->Cells[j][i] = IntToStr(matrix2[i][j]);
		}
	}
}
//---------------------------------------------------------------------------




