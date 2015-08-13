#pragma once
#include <iostream>
#include <string>
#include "QSInterface.h"
#include "QS.h"
using namespace std;


void QS::sortAll(int data[], int size)
{
	if (size==1)
	{
		return;
	}
	sort(data, size, 0, size-1);

}
/*----------------------------------------------------------------------------------------------
End Sort ALL
----------------------------------------------------------------------------------------------*/
void QS::sort(int data[], int size, int left, int right)
{
	if (left<0||right<0||left>=size||right>=size||left>right||data==NULL||size==1)
	{
		return;
	}

	int newright=partition(data,size,left,right);

	sort(data,newright-left-1,left,newright);
	sort(data, right-newright+1, newright,right);

}
/*----------------------------------------------------------------------------------------------
End Sort
----------------------------------------------------------------------------------------------*/

void QS::medianOfThree(int data[], int size, int left, int right)
{
	if (left<0||right<0||left>=size||right>=size||left>right||data==NULL||right-left<2)
	{
		return;
	}
	if (data[left]>data[right])
	{
		swap(data,size,left,right);
	}
	int middle=(left+right)/2;

	if (data[left]>data[middle])
	{
		swap(data,size,left,middle);
	}
	if (data[middle]>data[right])
	{
		swap(data,size,right,middle);
	}

}
/*----------------------------------------------------------------------------------------------
End MEDIAN OF THREE
----------------------------------------------------------------------------------------------*/

int QS::partition(int data[], int size, int left, int right)
{
	if (left<0||right<0||left>=size||right>=size||left>right||data==NULL)
	{
		return -1;
	}
	
	medianOfThree(data, size, left, right);
	int middle=(left+right)/2;
		int pivot=data[middle];
	int j=right;

	for (int i=left; i<j; i++)
	{
		if (data[i]>=data[middle])
		{
			while (data[j]>data[middle])
			{
				j--;
			}
			swap(data, size, data[i], data[j]);
			if (j==middle)
			{
				middle=i;
			}
			else if (i==middle)
			{
				middle=j;
			}
		}
		else if (data[j]<=data[middle])
		{
			while (data[i]<data[middle])
			{
				i++;
			}
			swap(data,size,data[i],data[j]);
			if (j==middle)
			{
				middle=i;
			}
			else if (i==middle)
			{
				middle=j;
			}
		}
	}
	cout<<"middle="<<middle<<endl;
for (int i=0;i<size;i++)
{
	cout<<i<<" | "<<data[i]<<endl;
}
	return middle;


}
/*----------------------------------------------------------------------------------------------
End Sort ALL
----------------------------------------------------------------------------------------------*/

void QS::swap(int data[], int size, int i, int j)
{
	if (j<0||i<0||i>=size||j>=size||data==NULL||size==1||i==j||data[i]==data[j])
	{
		return;
	}
	data[i]=data[i]^data[j];
	data[j]=data[i]^data[j];
	data[i]=data[i]^data[j];
}