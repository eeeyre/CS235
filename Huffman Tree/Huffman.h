#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "HuffmanInterface.h"
using namespace std;

/*
	WARNING: Do not modify any part of this document, including its name
*/
	class Huffman : public HuffmanInterface
	{
	private:
		struct Node
		{
			char node_data;
			int frequency;
			Node* left;
			Node* right;

			Node(char letter, int frequency_in, Node* left_ptr = NULL, Node* right_ptr = NULL) : 
			node_data(letter), left(left_ptr), right(right_ptr), frequency(frequency_in) {}

		};
		Node* rootnode=NULL;
		
		vector<string> encoding;
		void encodelist(Node* node_ptr,string code="")
		{
			string newcode;
			if (node_ptr->left!=NULL)
			{
				newcode="0";
				encodelist(node_ptr->left,code+newcode);
			}
			if (node_ptr->right!=NULL)
			{
				newcode="1";
				encodelist(node_ptr->right,code+newcode);
			}
			if (node_ptr->node_data!=(char)007)
			{
				stringstream t;
				string q;
				t << node_ptr->node_data;
				t >> q;
				q+=" "+code;
				encoding.push_back(q);
				//cout<<"found "<<node_ptr->node_data<<endl;	
			}
		}

	public:
		Huffman(){}
		virtual ~Huffman(){}

	/**
	 * This method is called to generate your tree.  The return type is void because this method simply creates the tree.  The other methods
	 * will be used to encode or decode the message.
	 * 
	 * @param message The message that should be used to create the tree
	 */
	 void createTree(string message);



	/**
	 * This method is called to encode a message into 1s and 0s using the tree created by the createTree method.
	 * 
	 * @param toEncode The message to be encoded
	 * 
	 * @return The encoded message, or an empty string if the text could not be encoded
	 */
	 string encodeMessage(string toEncode);



	/**
	 * This method is called to decode a message consisting of 1s and 0s back into characters using the tree that was created by the createTree method.
	 * 
	 * @param toDecode The encoded message (1s and 0s) that should be decoded
	 * 
	 * @return The decoded message, or an empty string if the text could not be decoded
	 */
	 string decodeMessage(string toDecode);

	/**
	 * This method is called to return a vector that contains all of the current encodings 
	 * in the tree that was created by the createTree method.
	 * 
	 * @return A vector containing strings.  Each string should be of the format: "char encoding"
	 * I.E.
	 * If your tree holds: a-01, b-001, c-10
	 * Your vector would look like this (without quotes):
	 *"a 01"
	 *"b 001"
	 *"c 10"
	 */	
	 vector<string> getEncodings();
	};
