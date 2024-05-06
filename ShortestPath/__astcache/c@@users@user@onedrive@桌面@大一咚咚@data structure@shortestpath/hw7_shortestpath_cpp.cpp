﻿//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Hw7_ShortestPath_cpp.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
int **maze;
int n, range, max_range,infinite=10000000, u;
int *found, *D, *E;
int **SSAD;
int **A;
int **B;
int **C;


int minpath(int n)
{
	int min = infinite, ans;
	for (int i = 0; i < n; i++)
	{
		if(D[i] < min && found[i] == 0)
		{
			min = D[i];
			ans = i;
		}
	}
	return ans;
}

int min(int a, int b)
{
	if(a > b)
		return b;
	else
        return a;
}


//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int i,j;
	if(maze != NULL)
	{
		for (i = 0; i < n; i++)
			delete maze[i];
		delete maze;
	}

	n = StrToInt(Edit1->Text);
	range = StrToInt(Edit2->Text);
	max_range = StrToInt(Edit3->Text);

	maze = new int *[n];
	for(i = 0; i < n; i++)
		maze[i] = new int [n];

	if(CheckBox1->Checked)
	{
		for(i = 0; i < n; i++)
		{
			for(j = i+1; j < n; j++)
			{
				maze[i][j] = rand()%range + 1;
				if(maze[i][j] > max_range)
					maze[i][j] = infinite;
			}
			maze[i][i] = infinite;
		}
		for(i = 0; i < n; i++)
			for(j = i+1; j < n; j++)
				maze[j][i]=maze[i][j];
	}
	else
	{
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				maze[i][j] = rand()%range + 1;
				if(maze[i][j] > max_range)
					maze[i][j] = infinite;
			}
			maze[i][i] = infinite;
		}
	}

	StringGrid1->RowCount = n+1;
	StringGrid1->ColCount = n+1;
	StringGrid1->Cells[0][0] = "";
	for(i = 1; i < n+1; i++)
	 StringGrid1->Cells[i][0] = i-1;
	for(i = 1; i < n+1; i++)
	 StringGrid1->Cells[0][i] = i-1;
	for(i = 1; i < n+1; i++)
	{
		for (j = 1; j < n+1; j++)
		{
			StringGrid1->Cells[j][i] = maze[i-1][j-1];
			if(maze[i-1][j-1]==infinite)
				StringGrid1->Cells[j][i] = "∞";
		}
	}
	if (Button1->Click) PageControl1->ActivePage = TabSheet2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Memo1->Clear();
    int i, j, v , m, k, p=0, a, b, c, count, sd;
	u = StrToInt(Edit5->Text);

	if(D != NULL)
		delete D;
	if(E != NULL)
		delete E;
	if(found != NULL)
		delete found;
	if(SSAD != NULL)
	{
		for (i = 0; i < n; i++)
			delete SSAD[i];
		delete SSAD;
	}

	D = new int [n];
	found = new int [n];
	E = new int [n];
	SSAD = new int *[n];
	for(i = 0; i < n; i++)
		SSAD[i] = new int [n];

	for (j = 0; j < n; j++)
	{
		D[j] = maze[u][j];
		E[j] = u;
		found[j] = 0;
	}
	found[u] = 1;
	D[u] = 0;
	for (m = 0; m < n-1; m++)
	{
		for(i = 0; i < n; i++)
			SSAD[m][i] = D[i];
		k = minpath(n);
		found[k] = 1;
		for (v = 0; v < n; v++)
			if (!found[v] && D[k]+maze[k][v] < D[v])
			{
				D[v] = D[k] + maze[k][v];
				E[v] = k;
			}
		Memo1->Lines->Add("min = " + IntToStr(k));
	}
	for(i = 0; i < n; i++)
		SSAD[m][i] = D[i];
	String r = "";
	for (v = 0; v < n; v++)
	{
		count = 0;
		sd = 0;
		c = u;
		if(v != u)
		{
			r = "-->"+IntToStr(v);
			for (b = v, a = E[b]; a != u; b = a, a = E[b])
			{
				count ++;
				if (count <= 1)
					c = a;
				if (count > 1)
					r = IntToStr(a) + "--[" + IntToStr(maze[a][b] ) + "]-->" + r ;
				else
					r = IntToStr(a) + "--[" + IntToStr(maze[a][b] ) + "]" + r;
				sd += maze[a][b];
			}
			sd += maze[a][b];
			if(count >= 1)
                Memo1->Lines->Add("The shortest distance fron "+IntToStr(u)+" to "+IntToStr(v)
					+" is "+IntToStr(sd)+" with path "+IntToStr(u)+"--["+IntToStr(maze[u][b]) +
					"]-->" + r);
			else
				Memo1->Lines->Add("The shortest distance fron "+IntToStr(u)+" to "+IntToStr(v)
					+" is "+IntToStr(sd)+" with path "+IntToStr(u)+"--["+IntToStr(maze[u][b]) +
					"]" + r);
		}
		StringGrid2->Cells[n+1][v+1] = c;
	}
	Memo1->Lines->Add("-------------------------------");
	StringGrid2->RowCount = n+1;
	StringGrid2->ColCount = n+2;
	StringGrid2->Cells[0][0] = "";
	for(i = 1; i < n+1; i++)
	 StringGrid2->Cells[i][0] = i-1;
	for(i = 1; i < n+1; i++)
	 StringGrid2->Cells[0][i] = i-1;
	for(i = 1; i < n+1; i++)
	{
		for (j = 1; j < n+1; j++)
		{
			StringGrid2->Cells[i][j] = SSAD[i-1][j-1];
            if(SSAD[i-1][j-1]==infinite)
				StringGrid2->Cells[i][j] = "∞";
		}
	}
	StringGrid2->Cells[n+1][0] = "from";

	if (Button2->Click) PageControl1->ActivePage = TabSheet3;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    int i, j, k ,m, count;
	if(A != NULL)
	{
		for (i = 0; i < n; i++)
			delete A[i];
		delete A;
	}
	if(B != NULL)
	{
		for (i = 0; i < n; i++)
			delete B[i];
		delete B;
	}
	A = new int *[n];
	for(i = 0; i < n; i++)
		A[i] = new int [n];
	B = new int *[n];
	for(i = 0; i < n; i++)
		B[i] = new int [n];
	for (i = 0; i < n; i++)
		for (j=0; j < n; j++)
			A[i][j] = maze[i][j];
	for (i = 0; i < n; i++)
		for (j=0; j < n; j++)
			B[i][j] = j;
	for (k=0; k<n; k++)
	{
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
                m = A[i][j];
				A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
				if (A[i][j] != m)
					B[i][j] = k;
			}
		}
	}
	for(i=0;i<n;i++)
		A[i][i]=0;
	for(i=0;i<n;i++)
		B[i][i]=i;
	StringGrid3->RowCount = n+1;
	StringGrid3->ColCount = n+1;
	StringGrid3->Cells[0][0] = "";
	for(i = 1; i < n+1; i++)
	 StringGrid3->Cells[i][0] = i-1;
	for(i = 1; i < n+1; i++)
	 StringGrid3->Cells[0][i] = i-1;
	 for(i = 1; i < n+1; i++)
		for (j = 1; j < n+1; j++)
			StringGrid3->Cells[j][i] = A[i-1][j-1];
	StringGrid4->RowCount = n+1;
	StringGrid4->ColCount = n+1;
	StringGrid4->Cells[0][0] = "";
	for(i = 1; i < n+1; i++)
	 StringGrid4->Cells[i][0] = i-1;
	for(i = 1; i < n+1; i++)
	 StringGrid4->Cells[0][i] = i-1;
	for(i = 1; i < n+1; i++)
		for (j = 1; j < n+1; j++)
			StringGrid4->Cells[j][i] = B[i-1][j-1];
	if (Button3->Click) PageControl1->ActivePage = TabSheet4;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
    int i, j, k;
	if(C != NULL)
	{
		for (i = 0; i < n; i++)
			delete C[i];
		delete C;
	}
	C = new int *[n];
	for(i = 0; i < n; i++)
		C[i] = new int [n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			C[i][j] = maze[i][j];
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				C[i][j] = min(C[i][j], C[i][k]+C[k][j]);
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			if(C[i][j] == infinite)
				C[i][j] = 0  ;
			else
				C[i][j] = 1;
        }
	}
	StringGrid5->RowCount = n+1;
	StringGrid5->ColCount = n+1;
	StringGrid5->Cells[0][0] = "";
	for(i = 1; i < n+1; i++)
	 StringGrid5->Cells[i][0] = i-1;
	for(i = 1; i < n+1; i++)
	 StringGrid5->Cells[0][i] = i-1;
	for(i = 1; i < n+1; i++)
		for (j = 1; j < n+1; j++)
			StringGrid5->Cells[i][j] = C[i-1][j-1];
	if (Button4->Click) PageControl1->ActivePage = TabSheet6;
}
//---------------------------------------------------------------------------
