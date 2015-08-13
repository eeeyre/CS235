#include "DoubleLinkedList.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	srand(time(NULL));
	DoubleLinkedList<int> integers;
	int test1=1;
	int test2=2;
	int test3=2;
	int test4=1;
	integers.addFront(test1);
	integers.addFront(test2);
	integers.addRear(test3);
	integers.addRear(test4);
	integers.addFront(5);
	integers.addAt(3,4);
	integers.addRear(17);
	cout<<integers.size()<<endl;
	cout<<integers.at(0)<<" "<<integers.at(1)<<" "<<integers.at(2)<<" "<<integers.at(3)<<" "<<integers.at(4)<<" "<<integers.at(5)<<" "<<integers.at(6)<<endl;
	integers.reverse();
	integers.reverse();
	integers.swap(0,1);
	integers.shuffle();
	cout<<integers.at(0)<<" "<<integers.at(1)<<" "<<integers.at(2)<<" "<<integers.at(3)<<" "<<integers.at(4)<<" "<<integers.at(5)<<" "<<integers.at(6)<<endl;
	integers.removeDuplicates();
	
	cout<<integers.at(0)<<" "<<integers.at(1)<<" "<<integers.at(2)<<" "<<integers.at(3)<<" "<<integers.at(4)<<endl;
	cout<<integers.size()<<endl;
	
	DoubleLinkedList<string> strings;
	strings.addFront("String3");
	strings.addFront("String2");
	strings.addRear("String6");
	strings.addRear("String7");
	cout<<strings.size()<<endl;
	strings.addAt("String5",2);
	strings.addAt("String4",2);
	strings.addFront("String1");
	strings.remove(5);
	cout<<strings.size()<<endl;
	strings.addAt("String6",5);
	strings.swap(2,6);
	strings.swap(0,4);
	cout<<strings.at(0)<<" "<<strings.at(1)<<" "<<strings.at(2)<<" "<<strings.at(3)<<" "<<strings.at(4)<<" "<<strings.at(5)<<" "<<strings.at(6)<<endl;
	strings.swap(0,4);
	strings.swap(2,6);
	cout<<strings.at(0)<<" "<<strings.at(1)<<strings.at(2)<<" "<<strings.at(3)<<strings.at(4)<<" "<<strings.at(5)<<strings.at(6)<<endl;
	strings.reverse();
	cout<<strings.at(0)<<" "<<strings.at(1)<<strings.at(2)<<" "<<strings.at(3)<<" "<<strings.at(4)<<" "<<strings.at(5)<<" "<<strings.at(6)<<endl;
	strings.reverse();
	cout<<strings.isPalindrome()<<endl;
	strings.addFront("String1");
	cout<<strings.contains("String1");
	strings.addFront("String2");
	strings.addFront("String3");
	strings.addFront("String4");
	strings.addFront("String5");
	strings.addFront("String6");
	strings.addFront("String7");
	cout<<strings.at(0)<<" "<<strings.at(1)<<strings.at(2)<<" "<<strings.at(3)<<" "<<strings.at(4)<<" "<<strings.at(5)<<strings.at(6)<<" "<<strings.at(7)<<" "<<strings.at(8)<<" "<<strings.at(9)<<" "<<strings.at(10)<<" "<<strings.at(11)<<" "<<strings.at(12)<<" "<<strings.at(13)<<endl;
	cout<<strings.isPalindrome()<<endl;
	strings.reverse();
	cout<<strings.count("String2")<<endl;
	cout<<strings.getKthFromRear(0)<<" "<<strings.getKthFromRear(1)<<" "<<strings.getKthFromRear(2)<<" "<<strings.getKthFromRear(7)<<" "<<endl;
	strings.shuffle();
	cout<<strings.at(0)<<" "<<strings.at(1)<<strings.at(2)<<" "<<strings.at(3)<<" "<<strings.at(4)<<" "<<strings.at(5)<<strings.at(6)<<" "<<strings.at(7)<<" "<<strings.at(8)<<" "<<strings.at(9)<<" "<<strings.at(10)<<" "<<strings.at(11)<<" "<<strings.at(12)<<" "<<strings.at(13)<<endl;
	strings.shuffle();
	cout<<strings.at(0)<<" "<<strings.at(1)<<strings.at(2)<<" "<<strings.at(3)<<" "<<strings.at(4)<<" "<<strings.at(5)<<strings.at(6)<<" "<<strings.at(7)<<" "<<strings.at(8)<<" "<<strings.at(9)<<" "<<strings.at(10)<<" "<<strings.at(11)<<" "<<strings.at(12)<<" "<<strings.at(13)<<endl;
	strings.removeDuplicates();
	strings.addAt("String234",-1);
	strings.remove(-1);
	strings.remove(183);
	strings.swap(-1,30);
	strings.swap(3,34);
	cout<<strings.contains("asdkjhf")<<endl;
	cout<<strings.at(0)<<" "<<strings.at(1)<<" "<<strings.at(2)<<" "<<strings.at(3)<<" "<<strings.at(4)<<" "<<strings.at(5)<<" "<<strings.at(6)<<endl;
}
