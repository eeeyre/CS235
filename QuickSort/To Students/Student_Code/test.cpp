#pragma once
#include <cstdlib>
#include "test.h"
#include "QS.h"
#include "QSInterface.h"
using namespace std;

bool QSTest::testSortAll(QSInterface* test)
{
	int Test1[13]={1,45,3,6,7,4,2,5,2,234,456,4567,5678};
	int Test2[13]={1,45,3,6,7,4,2,5,2,234,456,4567,5678};
	int Test3[1];
	Test3[0]=1;
	int Test4[2];
	Test4[0]=6;
	Test4[1]=3;
	int Test5[15];
	int Test6[15];
for (int i=0;i<15;i++)
{
	Test5[i]==Test6[i];
}	

QS* tester = new QS();
test->sortAll(Test1,13);
test->sortAll(Test1,13);
test->sortAll(Test2,13);
test->sortAll(Test2,13);
test->sortAll(Test3,1);
test->sortAll(Test4,2);	
test->sortAll(NULL,0);
if (Test1[0]!=Test2[0])
	return false;
	for (int i=1;i<13;i++)
		{
			if (Test1[i]!=Test2[i]||Test1[i-1]>Test1[i]||Test2[i-1]>Test2[i]||Test3[0]!=1||Test4[0]!=3||Test4[1]!=6)
			{
				return false;
			}
		}

	return true;
}
bool QSTest::testSort(QSInterface* test)
{
	int Test1[13]={1,45,3,6,7,4,2,5,2,234,456,4567,5678};
	int Test2[13]={1,45,3,6,7,4,2,5,2,234,456,4567,5678};

	int Test3[1];
	Test3[0]=1;
	int Test4[2];
	Test4[0]=6;
	Test4[1]=3;
	int Test5[0];
	int* Test6=Test5;


test->sort(Test1,13,2,12);
test->sort(Test2,13,2,12);
test->sort(Test3,1,3,4);
test->sort(Test4,2,0,1);
test->sort(Test5,0,0,0);
test->sort(Test1,13,75,25);
test->sort(Test1, 13,-35,1049);
test->sort(Test1,13,50,1049);	
	for (int i=3;i<13;i++)
		{
			if (Test1[i-1]>Test1[i]||Test2[i-1]>Test2[i]||Test3[0]!=1||Test4[0]!=3||Test4[1]!=6||*Test6!=*Test5)
			{
				return false;
			}
		}
		return true;
}
bool QSTest::testMedianOfThree(QSInterface* test)
{
	int Test1[]={1,45,3,6,7,4,7,5,56,234,456,4567,3};
	int Test2[]={1,45,3,6,7,4,7,5,56,234,456,4567,3};
	int TestSolution[]={1,45,3,6,7,4,3,5,56,234,456,4567,7};
	int Test3[1];
	Test3[0]=1;
	int Test4[2];
	Test4[0]=6;
	Test4[1]=3;
	int Test5[0];
	int* Test6=Test5;
	

QS* tester = new QS();
test->medianOfThree(Test1,13,0,12);
test->medianOfThree(Test2,13,0,12);
test->medianOfThree(Test1,13,5,34);
test->medianOfThree(Test1,13,5,2);
test->medianOfThree(Test1,13,-1,5);
int middle=12/2;
test->medianOfThree(Test3,1,3,4);
test->medianOfThree(Test4,2,0,1);	
	if (Test1[0]>Test1[middle]||Test1[middle]>Test1[12]||Test2[0]>Test2[middle]||Test2[middle]>Test2[12]||Test3[0]!=1||Test4[0]!=3||Test4[1]!=6||*Test5!=*Test6||Test1[0]!=1)
		return false;
	for (int i=0;i<13;i++)
{
	//cout<<Test1[i]<<" | ";
	if (Test1[i]!=TestSolution[i])
		return false;
}

return true;
}
bool QSTest::testPartition(QSInterface* test)
{
	int Test1[]={1,45,3,6,7,4,7,5,56,234,456,4567,3};
	int Test2[]={1,45,3,6,7,4,7,5,56,234,456,4567,3};
	int TestSolution[]={1,4,3,6,7,45,7,5,56,234,456,4567,3};
	int Test3[1];
	Test3[0]=1;
	int Test4[2];
	Test4[0]=6;
	Test4[1]=3;
	int Test5[0];
	int *Test7=Test5;
	int Test6[]={1,13,12,11,10,9,8,7,6,5,4,3,2,175,0,1,4,3,6,7,45,7,5,56,234,456,4567};
	int Test6Solution[]={56,13,12,11,10,9,8,7,6,5,4,3,2,1,0,1,4,3,6,7,45,7,5,175,234,456,4567};

int middle1=6;
int middle2=6;
test->partition(Test1,13,0,middle1);
//test->partition(Test2,13,0,middle2);
test->partition(Test4,2,0,1);
test->partition(Test3,1,0,0);
test->partition(Test6,27,0,26);

//null array
if (Test4[0]!=3||Test4[1]!=6||Test3[0]!=1||*Test7!=*Test5)
	{return false;
	}
//out of bounds
if (test->partition(NULL,0,0,0)!=-1||test->partition(Test6,15,-1,14)!=-1||test->partition(Test1,13,3,105)!=-1||test->partition(Test1,13,-13,5)!=-1||test->partition(Test1,13,4,1)!=-1||test->partition(Test6,15,3,3)!=-1)
	{return false;
	}
//not true
for (int i=0; i<13;i++)
{
	//cout<<Test1[i]<<" | ";
	if (Test1[i]!=TestSolution[i])
	{
		return false;
	}
	
}//cout<<endl;

for (int i=0;i<27;i++)
{//cout<<Test6[i]<<" | ";
	if (Test6[i]!=Test6Solution[i])
		{return false;
		}
}
if (!testMedianOfThree(test)||!testSwap(test))
{
	return false;
}
return true;
}
bool QSTest::testSwap(QSInterface* test)
{
int Test1[100];
	int Test2[100];


	for (int i=0;i<100;i++)
	{
		Test1[i]=rand()%1000+1;
		Test2[i]=Test1[i];

	}
	int Test3[1];
	Test3[0]=1;
	int Test4[2];
	Test4[0]=6;
	Test4[1]=3;
	int Test5[0];

QS* tester = new QS();
test->swap(Test1,100,25,75);
test->swap(Test1,100,1,80);
test->swap(Test1,100,1,104);
test->swap(Test3,1,0,0);
test->swap(Test4,2,0,1);	
test->swap(Test5,0,0,1);
	if (Test1[25]!=Test2[75]||Test1[75]!=Test2[25]||Test1[1]!=Test2[80]||Test1[80]!=Test2[1]||Test3[0]!=1||Test4[0]!=3||Test4[1]!=6)
		return false;

return true;
	

}