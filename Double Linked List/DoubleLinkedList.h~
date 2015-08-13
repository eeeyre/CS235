/* Eric Eyre
 * CS 235 Section 003
 * CS 235 Fall 2013 Midterm
 * 
 * 
 */


#pragma once
#include "DoubleLinkedListInterface.h"
#include <ctime>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;


template <class T>
	class DoubleLinkedList : public DoubleLinkedListInterface<T>
{
	private:
		struct Node
		{
			T node_data;
			Node* next;
			Node* prev;
		
			Node(T& data_item, Node* next_ptr = NULL, Node* prev_ptr = NULL) : 
				node_data(data_item), next(next_ptr), prev(prev_ptr) {}
				
		};
		Node* head=NULL;
		Node* tail=NULL;
	public:
		
//----------------------------------------------------------------------------------------------------------------------------------------------------
		/* Add head item */
		void addFront(T data)
		{
			if (head==NULL)
			{
				head=new Node(data, head, NULL);
				tail=head;
			} else {
			Node* new_head=new Node(data, head, NULL);
			head->prev=new_head;
			head=new_head;
			}
			
			
		}
		/* End Add Head Item */
//----------------------------------------------------------------------------------------------------------------------------------------------------		
		/*Add Tail Item */
		void addRear(T data)
		{
			Node* newTail= new Node(data,NULL,tail);
			tail->next=newTail;
			tail=newTail;
			if (head==NULL)
				head=tail;
			
		}
		/*End Add Tail Item */
//----------------------------------------------------------------------------------------------------------------------------------------------------		
		/*Add Item at index*/
		bool addAt(T data, int index)
		{
			
			Node* node_ptr=head;
			//Get the number of Nodes
			if (index<0)
				return false;
			else if (index==0)
			{
				addFront(data);
				return true;
			}
			else {
				for (int i=1;i<=index;i++)
				{
					
					node_ptr=node_ptr->next;
									
					
					if (i==index)
						{
							if (node_ptr==NULL) {
								addRear(data);
							}
							else
							{
								
								Node* insertNode=new Node(data, node_ptr, node_ptr->prev);
								node_ptr->prev->next=insertNode;
								node_ptr->prev=insertNode;
								
								
							} 
							return true;
						}
					
					if (node_ptr==NULL)
						return false;
					
				}
			     }	
		return false;	
			
		}
		/*End Add Item at Index */
//----------------------------------------------------------------------------------------------------------------------------------------------------		
		/*remove item from index*/
		bool remove(int index)
		{
			
			if (index<0)
				return false;
			int numNodes=0;
			Node* node_ptr=head;
			for (int i=0; i<=index; i++)
			{
				if (node_ptr==NULL)
					return false;
				if (numNodes==index)
				{
					if (node_ptr->next==NULL&&node_ptr->prev==NULL)
					{
						delete node_ptr;
						tail=NULL;
						head=NULL;
						return true;
					}
					else if (node_ptr->next==NULL)
					{
						node_ptr->prev->next=NULL;
						tail=node_ptr->prev;
						delete node_ptr;
						return true;
					}
					else if (node_ptr->prev==NULL)
					{
						node_ptr->next->prev=NULL;
						head=node_ptr->next;
						delete node_ptr;
						return true;		
					}
					else 
					{
						node_ptr->prev->next=node_ptr->next;
						node_ptr->next->prev=node_ptr->prev;
						delete node_ptr;
						return true;
					}
				}
				node_ptr=node_ptr->next;
				numNodes++;
			}
		}
		/*End Remove item from index*/
//----------------------------------------------------------------------------------------------------------------------------------------------------		
		/*return item at index*/
		T at(int index)
		{
			Node* node_ptr=head;
			for (int i=0;i<=index;i++)
				{
				if (i==index)
					return node_ptr->node_data;
				node_ptr=node_ptr->next;
				
				}
		}
		/*end return item at index*/
//----------------------------------------------------------------------------------------------------------------------------------------------------		
		/*does list contain data?*/
		bool contains(T data)
		{
			Node* node_ptr=head;
			while (node_ptr!=NULL)
			{
				if (node_ptr->node_data==data)
				return true;
				node_ptr=node_ptr->next;
			}
			return false;
		}
		/* End Item contained */
//----------------------------------------------------------------------------------------------------------------------------------------------------		
		/*List Size*/
		int size()
		{
			Node* node_ptr=head;
			int numNodes=0;
			while(node_ptr!=NULL)
			{
				numNodes++;
				node_ptr=node_ptr->next;
			}
			return numNodes;
		}
		/*end List Size*/
//----------------------------------------------------------------------------------------------------------------------------------------------------		
		/*Swap two items*/
		bool swap(int index1, int index2)
		{
			int numNodes=0;
			
			if (index1<0||index2<0)
				return false;
			Node* swap1=NULL;
			Node* swap2=NULL;
			T swapval1;
			T swapval2;
			Node* node_ptr=head;
			while(node_ptr!=NULL)
			{
				if (numNodes==index1)
				{
					swap1=node_ptr;
					swapval1=swap1->node_data;
					
				}
				if (numNodes==index2)
				{
					swap2=node_ptr;
					swapval2=swap2->node_data;
					
				}
				numNodes++;
				node_ptr=node_ptr->next;
				
			}
			
			if (swap1==NULL||swap2==NULL)
				return false;
			swap1->node_data=swapval2;
			swap2->node_data=swapval1;
			if (swap1->next==NULL)
				tail=swap1;
			if (swap1->prev==NULL)
				head=swap1;
			if (swap2->next==NULL)
				tail=swap2;
			if (swap2->prev==NULL)
				head=swap2;
			return true;
			
		}
		/*end Swap*/
//----------------------------------------------------------------------------------------------------------------------------------------------------		
		/*Shuffle Items*/
		void shuffle()
		{
			if (size()==0)
				return;
			int item_select=rand() % size();
			T data=at(item_select);
			remove(item_select);
			shuffle();
			addFront(data);
			
		}
		/*end Shuffel*/
//----------------------------------------------------------------------------------------------------------------------------------------------------		
		/*is palindrome*/
		bool isPalindrome()
		{
			Node* node_ptr=head;
			Node* node_ptr_tail=tail;
			while (node_ptr!=NULL)
			{
				if (node_ptr->node_data==node_ptr_tail->node_data)
				{
				node_ptr=node_ptr->next;
				node_ptr_tail=node_ptr_tail->prev;
				} else return false;
			}
			return true;
		}
		/*end is palindrome*/
//----------------------------------------------------------------------------------------------------------------------------------------------------		
		/*return reverse index*/
		T getKthFromRear(int k)
		{
			
			int numNodes=0;
			Node* node_ptr=tail;
			for (int i=0;i<=k;i++)
				{
				 if (i==k)
				 	return node_ptr->node_data;
				 node_ptr=node_ptr->prev;
				
				}
		}
		/*end return reverse index*/
//----------------------------------------------------------------------------------------------------------------------------------------------------		
		/*remove Duplicates*/
		void removeDuplicates()
		{
			int index=0;
			Node* node_ptr=head;
			while (node_ptr!=NULL)
			{
				int index_mid=index;
				Node* node_ptr_mid=node_ptr;
				while(node_ptr_mid!=NULL)
				{
					node_ptr_mid=node_ptr_mid->next;
					index_mid++;
					if (node_ptr_mid==NULL)
						break;
					if (node_ptr->node_data==node_ptr_mid->node_data)
						remove(index_mid);
					
					
				}
				node_ptr=node_ptr->next;
				index++;
				
			}
		}
		/*end remove Duplicates*/
//----------------------------------------------------------------------------------------------------------------------------------------------------		
		/*reverse list*/
		void reverse()
		{
			int numNodes=0;
			Node* node_ptr=head;
			head=tail;
			tail=node_ptr;
			while (node_ptr!=NULL)
			{
				Node* node_int=node_ptr->next;
				node_ptr->next=node_ptr->prev;
				node_ptr->prev=node_int;
				node_ptr=node_ptr->prev;
			}

		}
		/*end reverse list*/
//----------------------------------------------------------------------------------------------------------------------------------------------------		
		/*count number of nodes*/
		int count(T data)
		{
			int numCount=0;
			Node* node_ptr=head;
			while(node_ptr!=NULL)
			{
				if (data==node_ptr->node_data)
					numCount++;
				node_ptr=node_ptr->next;
			}
			return numCount;
		}
		/*end count*/
		
//----------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------		
//----------------------------------------------------------------------------------------------------------------------------------------------------		
//----------------------------------------------------------------------------------------------------------------------------------------------------		

		//EXTRA CREDIT
		void sort(){}
		
		
		
		int JosephusSafe(int m, int n){return -1;}

};
