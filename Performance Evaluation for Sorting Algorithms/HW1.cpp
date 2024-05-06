//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include <vector>
#include <algorithm>
#include "HW1.h"
#include <time.h>
#include <stack>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#define SWAP(x,y,t) (t=x,x=y,y=t)
int data[100000];
int original_data[100000];
int Leftdata[100000];   //用在Merge Sort
int Rightdata[100000];
int sum1[1000];   //這邊是用在最後輸出圖表結果的地方
int sum2[1000];
int sum3[1000];
int sum4[1000];
int sum5[1000];
int sum6[1000];
int sum7[1000];
int sum8[1000];
int sum9[1000];
int n;
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
void SelectionSort(int data[], int n)
{
	int i,j,temp,min;
		for(i=0;i<n;i++)
		{
			min=i;
			for(j=i+1;j<n;j++)
			{
				if(data[j]<data[min])
				{
					min = j;
				}
			}
			temp = data[i];
			data[i]=data[min];
            data[min]=temp;
        }

}

void BubbleSort(int data[],int n)
{
	int i,j,temp;
		for (i=n-1;i>=0;i--)
		{
			for(j=1;j<i+1;j++)
			{
				if(data[j-1]>data[j])
					SWAP(data[j-1],data[j],temp);
			}
		}
}

void InsertionSort(int data[],int n)
{
	int target,j;
	for(int i=1;i<n;i++)
    {
        target = data[i];
        j=i;
        while((data[j-1]>target) and (j>0))  //每次只看一個
        {
            data[j]=data[j-1];  //比較大就往後
            j--;
		}
        data[j]=target;
    }
}

void RadixSort(int data[], int n)
{
	int maxElement = data[0];
	for (int i = 1; i < n; i++)
	{
		if (data[i] > maxElement)
			maxElement = data[i];
	}
	for (int exp = 1; maxElement / exp > 0; exp *= 10)
	{
		int count[10] = {0};
		int output[n];
		for (int i = 0; i < n; i++)
			count[(data[i] / exp) % 10]++;
		for (int i = 1; i < 10; i++)
			count[i] += count[i - 1];
		for (int i = n - 1; i >= 0; i--)
		{
			output[count[(data[i] / exp) % 10] - 1] = data[i];
			count[(data[i] / exp) % 10]--;
        }
		for (int i = 0; i < n; i++)
			data[i] = output[i];
        for (int i = 0; i < n; i++)
            output[i] = 0;
    }
}

void heapify(int data[], int n, int rootIndex)
{
    int temp;
	int largest = rootIndex;
    int leftChild = 2 * rootIndex + 1;
    int rightChild = 2 * rootIndex + 2;
	if (leftChild < n && data[leftChild] > data[largest])
        largest = leftChild;
    if (rightChild < n && data[rightChild] > data[largest])
        largest = rightChild;
    if (largest != rootIndex)
    {
        SWAP(data[rootIndex],data[largest],temp);
        heapify(data, n, largest);
    }
}
void Heapsort(int data[], int n)
{
	int temp;
	for (int i = n / 2 - 1; i >= 0; i--)
        heapify(data, n, i);
    for (int i = n - 1; i > 0; i--)
    {
		SWAP(data[0],data[i],temp);
        heapify(data, i, 0);
    }
}

void Merge(int data[], int front, int mid, int end)
{
	for(int i=front;i<=mid;i++)
	{
		Leftdata[i]=data[i];
		Rightdata[i]=data[i+mid];
	}
	Leftdata[mid+1]=1000000;
	Rightdata[mid+1]=1000000;
	int left=0;
	int right=0;
	for (int i = front; i <= end; i++)
	{
		if (Leftdata[left] <= Rightdata[right] )  //比較左右兩邊 放入小的
		{
			data[i] = Leftdata[i];
			left++;
		}
		else
		{
			data[i] = Rightdata[i];
			right++;
		}
    }
}

void MergeSort(int data[], int front, int end)
{
	if (front < end)
	{
		int mid = (front+end)/2;
		MergeSort(data, front, mid);
		MergeSort(data, mid+1, end);
		Merge(data, front, mid, end);
	}
}

int Partition(int data[], int front, int end)
{
	int pivot = data[end];
	int temp;
	int i = front -1;
	for (int j = front; j < end; j++)
	{
		if (data[j] < pivot)
		{
			i++;
			SWAP(data[i],data[j],temp);
		}
	}
	i++;
	SWAP(data[i],data[end],temp);
	return i;
}

void merge(int data[], int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    int* leftArr = new int[leftSize];
    int* rightArr = new int[rightSize];
    for (int i = 0; i < leftSize; i++)
        leftArr[i] = data[left + i];
    for (int i = 0; i < rightSize; i++)
        rightArr[i] = data[mid + 1 + i];
    int i = 0;
    int j = 0;
    int k = left;
    while (i < leftSize && j < rightSize)
	{
        if (leftArr[i] <= rightArr[j])
        {
            data[k] = leftArr[i];
            i++;
        }
        else
        {
            data[k] = rightArr[j];
            j++;
        }
        k++;
    }
	while (i < leftSize)
    {
        data[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < rightSize)
    {
        data[k] = rightArr[j];
        j++;
        k++;
    }
    delete[] leftArr;
	delete[] rightArr;
}
void MergesortNON(int data[], int n)
{
    int currSize;
    int leftStart;
    for (currSize = 1; currSize <= n - 1; currSize = 2 * currSize)
    {
        for (leftStart = 0; leftStart < n - 1; leftStart += 2 * currSize)
        {
            int mid = std::min(leftStart + currSize - 1, n - 1);
            int rightEnd = std::min(leftStart + 2 * currSize - 1, n - 1);
            merge(data, leftStart, mid, rightEnd);
		}
    }
}


void QuickSort(int data[], int front, int end)
{
	if (front < end)
	{
        int pivot = Partition(data, front, end);
		QuickSort(data, front, pivot - 1);
		QuickSort(data, pivot + 1, end);
    }
}

int partition(int data[], int low, int high)
{
    int pivot = data[high];
	int temp;
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (data[j] <= pivot)
        {
            i++;
            SWAP(data[i],data[j],temp);
		}
    }
    SWAP(data[i+1],data[high],temp);
    return (i + 1);
}

void QuicksortNON(int data[], int low, int high)
{
    std::stack<int> stack;
    stack.push(low);
    stack.push(high);
    while (!stack.empty())
    {
		high = stack.top();
        stack.pop();
        low = stack.top();
        stack.pop();
        int pivotIndex = partition(data, low, high);
        if (pivotIndex - 1 > low)
        {
            stack.push(low);
            stack.push(pivotIndex - 1);
        }
        if (pivotIndex + 1 < high)
        {
            stack.push(pivotIndex + 1);
			stack.push(high);
        }
    }
}

void printdata(int data[],int n,int flag)
{
	int i;
		if(flag==1)
		{
			for(i=0;i<n;i++)
			{
				Form1->Memo1->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
			}
		}
		else if(flag==2)
		{
			for(i=0;i<n;i++)
			{
				Form1->Memo2->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
			}
		}
		else if(flag==3)
		{
			for(i=0;i<n;i++)
			{
				Form1->Memo3->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
			}
		}
		else if(flag==5)
		{
			for(i=0;i<n;i++)
			{
				Form1->Memo5->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
			}
		}
		else if(flag==6)
		{
			for(i=0;i<n;i++)
			{
				Form1->Memo6->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
			}
		}
		else if(flag==4)
		{
			for(i=0;i<n;i++)
			{
				Form1->Memo4->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
			}
		}
		else if(flag==10)
		{
			for(i=0;i<n;i++)
			{
				Form1->Memo10->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
			}
		}
		else if(flag==7)
		{
			for(i=0;i<n;i++)
			{
				Form1->Memo7->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
			}
		}
		else if(flag==8)
		{
			for(i=0;i<n;i++)
			{
				Form1->Memo8->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
			}
		}
		else if(flag==9)
		{
			for(i=0;i<n;i++)
			{
				Form1->Memo9->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
			}
		}
}

void Checkdata(int data[],int n,int flag)
{
	int i;
	for(i=0;i<n-1;i++)
	{
		if(data[i]>data[i+1])
		{
			break;
        }
    }
	if(i==n-1)
	{
		if(flag==2)
			Form1->Memo2->Lines->Add("Correctly Sorted.");
		else if(flag==3)
			Form1->Memo3->Lines->Add("Correctly Sorted.");
		else if(flag==5)
			Form1->Memo5->Lines->Add("Correctly Sorted.");
		else if(flag==4)
			Form1->Memo4->Lines->Add("Correctly Sorted.");
		else if(flag==10)
			Form1->Memo10->Lines->Add("Correctly Sorted.");
		else if(flag==7)
			Form1->Memo7->Lines->Add("Correctly Sorted.");
		else if(flag==8)
			Form1->Memo8->Lines->Add("Correctly Sorted.");
		else if(flag==9)
			Form1->Memo9->Lines->Add("Correctly Sorted.");
		else
			Form1->Memo6->Lines->Add("Correctly Sorted.");
	}
	else
    {
		if(flag==2)
			Form1->Memo2->Lines->Add("Not Sorted.");
		else if(flag==3)
			Form1->Memo3->Lines->Add("Not Sorted.");
		else if(flag==5)
			Form1->Memo5->Lines->Add("Not Sorted.");
		else if(flag==4)
			Form1->Memo4->Lines->Add("Not Sorted.");
		else if(flag==10)
			Form1->Memo10->Lines->Add("Not Sorted.");
		else if(flag==7)
			Form1->Memo7->Lines->Add("Not Sorted.");
		else if(flag==8)
			Form1->Memo8->Lines->Add("Not Sorted.");
		else if(flag==9)
			Form1->Memo9->Lines->Add("Not Sorted.");
		else
			Form1->Memo6->Lines->Add("Not Sorted.");
	}

}

void RandData(int original_data[],int n ,int range)
{
	for(int i=0;i<n;i++)
	{
		original_data[i] = rand()% range+1;
	}
}

void PlusData(int original_data[],int n ,int range,int step)    //這個是用在新增data在原陣列的後面
{
	for(int i=n+1;i<n+step;i++)
	{
		original_data[i] = rand()% range+1;
	}
}

void getData(int data[],int original_data[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		data[i]= original_data[i];
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int repeation = StrToInt(Edit4->Text);
	int sum=0;
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
	int range =StrToInt(Edit2->Text);
		srand(time(NULL));
        clock_t t_begin,t_end;
		t_begin = clock();
		RandData(original_data,n,range);
		t_end = clock();
		if(CheckBox1->Checked)
			printdata(original_data,n,1);
		sum=sum+(t_end-t_begin);
	for(int i=0;i<repeation;i++)
	{
			srand(time(NULL));
		clock_t t_begin,t_end;
			t_begin = clock();
			PlusData(original_data,n,range,step);//這個是用在新增data在原陣列的後面
			t_end = clock();
			if(CheckBox1->Checked)
				printdata(original_data,n,1);
		n= n+step;
		sum=sum+(t_end-t_begin);
	}
	Form1->Memo1->Lines->Add("CPU time(sec.) = "+FloatToStr((float)(sum)/CLOCKS_PER_SEC));

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{   int repeation =StrToInt(Edit4->Text);               //selection sort
	for(int i=0;i<1000;i++)
	{
		sum1[i]=0;
	}
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
	for(int i=0;i<=repeation;i++)  //這邊是小於等於 因為前面沒有跑過一次
	{
	clock_t t_begin,t_end;
		t_begin = clock();
		getData(data,original_data,n);
		SelectionSort(data,n);
		t_end = clock();
		if(CheckBox1->Checked)
			printdata(data,n,2);
		if(CheckBox2->Checked)
			Checkdata(data,n,2);
		sum1[i+1] =  sum1[i]+(t_end-t_begin);
		n=n+step;
	}
	for(int i=1;i<=repeation+1;i++)      //這邊則是要再加一次
	{
	  Form1->Memo2->Lines->Add("CPU time(sec.) = "+FloatToStr((float)(sum1[i])/CLOCKS_PER_SEC));
	}
	//這樣就可以一次得到所有數據
}
//--------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{   int repeation =StrToInt(Edit4->Text);              //bubble
	for(int i=0;i<1000;i++)
	{
		sum2[i]=0;
	}
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
	for(int i=0;i<=repeation;i++)  //這邊是小於等於 因為前面沒有跑過一次
	{
	clock_t t_begin,t_end;
		t_begin = clock();
		getData(data,original_data,n);
		BubbleSort(data,n);
		t_end = clock();
		if(CheckBox1->Checked)
			printdata(data,n,3);
		if(CheckBox2->Checked)
			Checkdata(data,n,3);
		sum2[i+1] =  sum2[i]+(t_end-t_begin);
		n=n+step;
	}
	for(int i=1;i<=repeation+1;i++)      //這邊則是要再加一次
	{
	  Form1->Memo3->Lines->Add("CPU time(sec.) = "+FloatToStr((float)(sum2[i])/CLOCKS_PER_SEC));
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{ int repeation =StrToInt(Edit4->Text);                   //Insertion
	for(int i=0;i<1000;i++)
	{
		sum5[i]=0;
	}
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
	for(int i=0;i<=repeation;i++)  //這邊是小於等於 因為前面沒有跑過一次
	{
	clock_t t_begin,t_end;
		t_begin = clock();
		getData(data,original_data,n);
		InsertionSort(data,n);
		t_end = clock();
		if(CheckBox1->Checked)
			printdata(data,n,4);
		if(CheckBox2->Checked)
			Checkdata(data,n,4);
		sum5[i+1] =  sum5[i]+(t_end-t_begin);
		n=n+step;
	}
	for(int i=1;i<=repeation+1;i++)      //這邊則是要再加一次
	{
	  Form1->Memo4->Lines->Add("CPU time(sec.) = "+FloatToStr((float)(sum5[i])/CLOCKS_PER_SEC));
	}
	//這樣就可以一次得到所有數據
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{   int repeation =StrToInt(Edit4->Text);                //merge re
	for(int i=0;i<1000;i++)
	{
		sum3[i]=0;
	}
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
	for(int i=0;i<=repeation;i++)  //這邊是小於等於 因為前面沒有跑過一次
	{
	clock_t t_begin,t_end;
		t_begin = clock();
		getData(data,original_data,n);
		MergeSort(data,0,n-1);
		t_end = clock();
		if(CheckBox1->Checked)
			printdata(data,n,5);
		if(CheckBox2->Checked)
			Checkdata(data,n,5);
		sum3[i+1] =  sum3[i]+(t_end-t_begin);
		n=n+step;
	}
	for(int i=1;i<=repeation+1;i++)      //這邊則是要再加一次
	{
	  Form1->Memo5->Lines->Add("CPU time(sec.) = "+FloatToStr((float)(sum3[i])/CLOCKS_PER_SEC));
	}

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button6Click(TObject *Sender)
{
	int repeation =StrToInt(Edit4->Text);                //Quick re
	for(int i=0;i<1000;i++)
	{
		sum4[i]=0;
	}
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
	for(int i=0;i<=repeation;i++)  //這邊是小於等於 因為前面沒有跑過一次
	{
	clock_t t_begin,t_end;
		t_begin = clock();
		getData(data,original_data,n);
		QuickSort(data,0,n-1);
		t_end = clock();
		if(CheckBox1->Checked)
			printdata(data,n,6);
		if(CheckBox2->Checked)
			Checkdata(data,n,6);
		sum4[i+1] =  sum4[i]+(t_end-t_begin);
		n=n+step;
	}
	for(int i=1;i<=repeation+1;i++)      //這邊則是要再加一次
	{
	  Form1->Memo6->Lines->Add("CPU time(sec.) = "+FloatToStr((float)(sum4[i])/CLOCKS_PER_SEC));
	}

}
//---------------------------------------------------------------------------

//底下是各個圖表

void __fastcall TForm1::Button7Click(TObject *Sender)
{
		Chart1->RemoveAllSeries();
	Chart1->Title->Text->Clear();
	Chart1->Title->Text->Add("Compare of CPU time");
	Chart1->BottomAxis->Title->Caption = "Data";
	Chart1->LeftAxis->Title->Caption = "CPU Time";
	for (int i=1;i<=9;i++)
	{
		TLineSeries *Series=new TLineSeries(Chart1);
		Series->ParentChart=Chart1;
		Chart1->AddSeries(Series);
	}
	int repeation =StrToInt(Edit4->Text);
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
	for (int i=1; i<=repeation+1; i++)
	{
		Chart1->Series[0]->Title = "Selection Sort";
		Chart1->Series[1]->Title = "Bubble Sort";
		Chart1->Series[2]->Title = "Merge Sort Recursive";
		Chart1->Series[3]->Title = "Quick Sort Recursive";
		Chart1->Series[4]->Title = "Insertion Sort";
		Chart1->Series[5]->Title = "Radix Sort";
		Chart1->Series[6]->Title = "Heap Sort";
		Chart1->Series[7]->Title = "Merge Sort NONRecursive";
		Chart1->Series[8]->Title = "Quick Sort NONRecursive";
				Chart1->Series[0]->Add( sum1[i] , n+step*(i-1) , clBlue );
		Chart1->Series[1]->Add( sum2[i] , n+step*(i-1) , clYellow );
		Chart1->Series[2]->Add( sum3[i] , n+step*(i-1) , clRed );
		Chart1->Series[3]->Add( sum4[i] , n+step*(i-1) , clGreen );
		Chart1->Series[4]->Add( sum5[i] , n+step*(i-1) , clOlive );
		Chart1->Series[5]->Add( sum6[i] , n+step*(i-1) , clPurple );
		Chart1->Series[6]->Add( sum7[i] , n+step*(i-1) , clGray );
		Chart1->Series[7]->Add( sum8[i] , n+step*(i-1) , clLime );
		Chart1->Series[8]->Add( sum9[i] , n+step*(i-1) , clAqua );
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button8Click(TObject *Sender)
{
	Chart1->RemoveAllSeries();    //清除所有圖表
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button12Click(TObject *Sender)
{
    	int repeation =StrToInt(Edit4->Text);                //radix
	for(int i=0;i<1000;i++)
	{
		sum6[i]=0;
	}
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
	for(int i=0;i<=repeation;i++)  //這邊是小於等於 因為前面沒有跑過一次
	{
	clock_t t_begin,t_end;
		t_begin = clock();
		getData(data,original_data,n);
		RadixSort(data,n);
		t_end = clock();
		if(CheckBox1->Checked)
			printdata(data,n,10);
		if(CheckBox2->Checked)
			Checkdata(data,n,10);
		sum6[i+1] =  sum6[i]+(t_end-t_begin);
		n=n+step;
	}
	for(int i=1;i<=repeation+1;i++)      //這邊則是要再加一次
	{
	  Form1->Memo10->Lines->Add("CPU time(sec.) = "+FloatToStr((float)(sum6[i])/CLOCKS_PER_SEC));
	}
	//這樣就可以一次得到所有數據
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
int repeation =StrToInt(Edit4->Text);               //heap
	for(int i=0;i<1000;i++)
	{
		sum7[i]=0;
	}
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
	for(int i=0;i<=repeation;i++)  //這邊是小於等於 因為前面沒有跑過一次
	{
	clock_t t_begin,t_end;
		t_begin = clock();
		getData(data,original_data,n);
		Heapsort(data,n);
		t_end = clock();
		if(CheckBox1->Checked)
			printdata(data,n,7);
		if(CheckBox2->Checked)
			Checkdata(data,n,7);
		sum7[i+1] =  sum7[i]+(t_end-t_begin);
		n=n+step;
	}
	for(int i=1;i<=repeation+1;i++)      //這邊則是要再加一次
	{
	  Form1->Memo7->Lines->Add("CPU time(sec.) = "+FloatToStr((float)(sum7[i])/CLOCKS_PER_SEC));
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
	int repeation =StrToInt(Edit4->Text);               //merge NON
	for(int i=0;i<1000;i++)
	{
		sum8[i]=0;
	}
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
	for(int i=0;i<=repeation;i++)  //這邊是小於等於 因為前面沒有跑過一次
	{
	clock_t t_begin,t_end;
		t_begin = clock();
		getData(data,original_data,n);
		MergesortNON(data,n);
		t_end = clock();
		if(CheckBox1->Checked)
			printdata(data,n,8);
		if(CheckBox2->Checked)
			Checkdata(data,n,8);
		sum8[i+1] =  sum8[i]+(t_end-t_begin);
		n=n+step;
	}
	for(int i=1;i<=repeation+1;i++)      //這邊則是要再加一次
	{
	  Form1->Memo8->Lines->Add("CPU time(sec.) = "+FloatToStr((float)(sum8[i])/CLOCKS_PER_SEC));
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
    int repeation =StrToInt(Edit4->Text);               //merge NON
	for(int i=0;i<1000;i++)
	{
		sum9[i]=0;
	}
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
	for(int i=0;i<=repeation;i++)  //這邊是小於等於 因為前面沒有跑過一次
	{
	clock_t t_begin,t_end;
		t_begin = clock();
		getData(data,original_data,n);
		QuicksortNON(data,0,n-1);
		t_end = clock();
		if(CheckBox1->Checked)
			printdata(data,n,9);
		if(CheckBox2->Checked)
			Checkdata(data,n,9);
		sum9[i+1] =  sum9[i]+(t_end-t_begin);
		n=n+step;
	}
	for(int i=1;i<=repeation+1;i++)      //這邊則是要再加一次
	{
	  Form1->Memo9->Lines->Add("CPU time(sec.) = "+FloatToStr((float)(sum9[i])/CLOCKS_PER_SEC));
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
	Chart1->RemoveAllSeries();
	Chart1->Title->Text->Clear();
	Chart1->Title->Text->Add("Compare of CPU time");
	Chart1->BottomAxis->Title->Caption = "Data";
	Chart1->LeftAxis->Title->Caption = "CPU Time";
	for (int i=1;i<=9;i++)
	{
		TBarSeries *Series=new TBarSeries(Chart1);
		Series->ParentChart=Chart1;
		Chart1->AddSeries(Series);
	}
	int repeation =StrToInt(Edit4->Text);
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
	for (int i=1; i<=repeation+1; i++)
	{
		Chart1->Series[0]->Title = "Selection Sort";
		Chart1->Series[1]->Title = "Bubble Sort";
		Chart1->Series[2]->Title = "Merge Sort Recursive";
		Chart1->Series[3]->Title = "Quick Sort Recursive";
		Chart1->Series[4]->Title = "Insertion Sort";
		Chart1->Series[5]->Title = "Radix Sort";
		Chart1->Series[6]->Title = "Heap Sort";
		Chart1->Series[7]->Title = "Merge Sort NONRecursive";
		Chart1->Series[8]->Title = "Quick Sort NONRecursive";
		Chart1->Series[0]->Add( sum1[i] , n+step*(i-1) , clBlue );
		Chart1->Series[1]->Add( sum2[i] , n+step*(i-1) , clYellow );
		Chart1->Series[2]->Add( sum3[i] , n+step*(i-1) , clRed );
		Chart1->Series[3]->Add( sum4[i] , n+step*(i-1) , clGreen );
		Chart1->Series[4]->Add( sum5[i] , n+step*(i-1) , clOlive );
		Chart1->Series[5]->Add( sum6[i] , n+step*(i-1) , clPurple );
		Chart1->Series[6]->Add( sum7[i] , n+step*(i-1) , clGray );
		Chart1->Series[7]->Add( sum8[i] , n+step*(i-1) , clLime );
		Chart1->Series[8]->Add( sum9[i] , n+step*(i-1) , clAqua );
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
    Chart1->RemoveAllSeries();
	Chart1->Title->Text->Clear();
	Chart1->Title->Text->Add("Compare of CPU time");
	Chart1->BottomAxis->Title->Caption = "Data";
	Chart1->LeftAxis->Title->Caption = "CPU Time";
	for (int i=1;i<=9;i++)
	{
		TLineSeries *Series=new TLineSeries(Chart1);
		Series->ParentChart=Chart1;
		Chart1->AddSeries(Series);
	}
	int repeation =StrToInt(Edit4->Text);
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
	for (int i=1; i<=repeation+1; i++)
	{
		Chart1->Series[0]->Title = "Selection Sort";
		Chart1->Series[1]->Title = "Bubble Sort";
		Chart1->Series[2]->Title = "Merge Sort Recursive";
		Chart1->Series[3]->Title = "Quick Sort Recursive";
		Chart1->Series[4]->Title = "Insertion Sort";
		Chart1->Series[5]->Title = "Radix Sort";
		Chart1->Series[6]->Title = "Heap Sort";
		Chart1->Series[7]->Title = "Merge Sort NONRecursive";
		Chart1->Series[8]->Title = "Quick Sort NONRecursive";
		Chart1->Series[0]->Add( sum1[i] , n+step*(i-1) , clBlue );
		Chart1->Series[1]->Add( sum2[i] , n+step*(i-1) , clYellow );
		Chart1->Series[2]->Add( sum3[i] , n+step*(i-1) , clRed );
		Chart1->Series[3]->Add( sum4[i] , n+step*(i-1) , clGreen );
		Chart1->Series[4]->Add( sum5[i] , n+step*(i-1) , clOlive );
		Chart1->Series[5]->Add( sum6[i] , n+step*(i-1) , clPurple );
		Chart1->Series[6]->Add( sum7[i] , n+step*(i-1) , clGray );
		Chart1->Series[7]->Add( sum8[i] , n+step*(i-1) , clLime );
		Chart1->Series[8]->Add( sum9[i] , n+step*(i-1) , clAqua );
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton3Click(TObject *Sender)
{
    Chart1->RemoveAllSeries();
	Chart1->Title->Text->Clear();
	Chart1->Title->Text->Add("Compare of CPU time");
	Chart1->BottomAxis->Title->Caption = "Data";
	Chart1->LeftAxis->Title->Caption = "CPU Time";
	for (int i=1;i<=9;i++)
	{
		TAreaSeries *Series=new TAreaSeries(Chart1);
		Series->ParentChart=Chart1;
		Chart1->AddSeries(Series);
	}
	int repeation =StrToInt(Edit4->Text);
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
	for (int i=1; i<=repeation+1; i++)
	{
		Chart1->Series[0]->Title = "Selection Sort";
		Chart1->Series[1]->Title = "Bubble Sort";
		Chart1->Series[2]->Title = "Merge Sort Recursive";
		Chart1->Series[3]->Title = "Quick Sort Recursive";
		Chart1->Series[4]->Title = "Insertion Sort";
		Chart1->Series[5]->Title = "Radix Sort";
		Chart1->Series[6]->Title = "Heap Sort";
		Chart1->Series[7]->Title = "Merge Sort NONRecursive";
		Chart1->Series[8]->Title = "Quick Sort NONRecursive";
		Chart1->Series[0]->Add( sum1[i] , n+step*(i-1) , clBlue );
		Chart1->Series[1]->Add( sum2[i] , n+step*(i-1) , clYellow );
		Chart1->Series[2]->Add( sum3[i] , n+step*(i-1) , clRed );
		Chart1->Series[3]->Add( sum4[i] , n+step*(i-1) , clGreen );
		Chart1->Series[4]->Add( sum5[i] , n+step*(i-1) , clOlive );
		Chart1->Series[5]->Add( sum6[i] , n+step*(i-1) , clPurple );
		Chart1->Series[6]->Add( sum7[i] , n+step*(i-1) , clGray );
		Chart1->Series[7]->Add( sum8[i] , n+step*(i-1) , clLime );
		Chart1->Series[8]->Add( sum9[i] , n+step*(i-1) , clAqua );
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton4Click(TObject *Sender)
{
Chart1->RemoveAllSeries();
	Chart1->Title->Text->Clear();
	Chart1->Title->Text->Add("Compare of CPU time");
	Chart1->BottomAxis->Title->Caption = "Data";
	Chart1->LeftAxis->Title->Caption = "CPU Time";
	for (int i=1;i<=9;i++)
	{
		TPointSeries *Series=new TPointSeries(Chart1);
		Series->ParentChart=Chart1;
		Chart1->AddSeries(Series);
	}
	int repeation =StrToInt(Edit4->Text);
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
	for (int i=1; i<=repeation+1; i++)
	{
		Chart1->Series[0]->Title = "Selection Sort";
		Chart1->Series[1]->Title = "Bubble Sort";
		Chart1->Series[2]->Title = "Merge Sort Recursive";
		Chart1->Series[3]->Title = "Quick Sort Recursive";
		Chart1->Series[4]->Title = "Insertion Sort";
		Chart1->Series[5]->Title = "Radix Sort";
		Chart1->Series[6]->Title = "Heap Sort";
		Chart1->Series[7]->Title = "Merge Sort NONRecursive";
		Chart1->Series[8]->Title = "Quick Sort NONRecursive";
		Chart1->Series[0]->Add( sum1[i] , n+step*(i-1) , clBlue );
		Chart1->Series[1]->Add( sum2[i] , n+step*(i-1) , clYellow );
		Chart1->Series[2]->Add( sum3[i] , n+step*(i-1) , clRed );
		Chart1->Series[3]->Add( sum4[i] , n+step*(i-1) , clGreen );
		Chart1->Series[4]->Add( sum5[i] , n+step*(i-1) , clOlive );
		Chart1->Series[5]->Add( sum6[i] , n+step*(i-1) , clPurple );
		Chart1->Series[6]->Add( sum7[i] , n+step*(i-1) , clGray );
		Chart1->Series[7]->Add( sum8[i] , n+step*(i-1) , clLime );
		Chart1->Series[8]->Add( sum9[i] , n+step*(i-1) , clAqua );
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton5Click(TObject *Sender)
{
Chart1->RemoveAllSeries();
	Chart1->Title->Text->Clear();
	Chart1->Title->Text->Add("Compare of CPU time");
	Chart1->BottomAxis->Title->Caption = "Data";
	Chart1->LeftAxis->Title->Caption = "CPU Time";
	for (int i=1;i<=9;i++)
	{
		TPieSeries *Series=new TPieSeries(Chart1);
		Series->ParentChart=Chart1;
		Chart1->AddSeries(Series);
	}
	int repeation =StrToInt(Edit4->Text);
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
	for (int i=1; i<=repeation+1; i++)
	{
		Chart1->Series[0]->Title = "Selection Sort";
		Chart1->Series[1]->Title = "Bubble Sort";
		Chart1->Series[2]->Title = "Merge Sort Recursive";
		Chart1->Series[3]->Title = "Quick Sort Recursive";
		Chart1->Series[4]->Title = "Insertion Sort";
		Chart1->Series[5]->Title = "Radix Sort";
		Chart1->Series[6]->Title = "Heap Sort";
		Chart1->Series[7]->Title = "Merge Sort NONRecursive";
		Chart1->Series[8]->Title = "Quick Sort NONRecursive";
		Chart1->Series[0]->Add( sum1[i] , n+step*(i-1) , clBlue );
		Chart1->Series[1]->Add( sum2[i] , n+step*(i-1) , clYellow );
		Chart1->Series[2]->Add( sum3[i] , n+step*(i-1) , clRed );
		Chart1->Series[3]->Add( sum4[i] , n+step*(i-1) , clGreen );
		Chart1->Series[4]->Add( sum5[i] , n+step*(i-1) , clOlive );
		Chart1->Series[5]->Add( sum6[i] , n+step*(i-1) , clPurple );
		Chart1->Series[6]->Add( sum7[i] , n+step*(i-1) , clGray );
		Chart1->Series[7]->Add( sum8[i] , n+step*(i-1) , clLime );
		Chart1->Series[8]->Add( sum9[i] , n+step*(i-1) , clAqua );
	}



}
//---------------------------------------------------------------------------

