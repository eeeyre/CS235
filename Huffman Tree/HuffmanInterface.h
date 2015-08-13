#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
	WARNING: Do not modify any part of this document, including its name
*/
class HuffmanInterface
{
	public:
		HuffmanInterface(){}
		virtual ~HuffmanInterface(){}

	/**
	 * This method is called to generate your tree.  The return type is void because this method simply creates the tree.  The other methods
	 * will be used to encode or decode the message.
	 * 
	 * @param message The message that should be used to create the tree
	 */
	virtual void createTree(string message) = 0;
	
	
	
	/**
	 * This method is called to encode a message into 1s and 0s using the tree created by the createTree method.
	 * 
	 * @param toEncode The message to be encoded
	 * 
	 * @return The encoded message, or an empty string if the text could not be encoded
	 */
	virtual string encodeMessage(string toEncode) = 0;
	
	
	
	/**
	 * This method is called to decode a message consisting of 1s and 0s back into characters using the tree that was created by the createTree method.
	 * 
	 * @param toDecode The encoded message (1s and 0s) that should be decoded
	 * 
	 * @return The decoded message, or an empty string if the text could not be decoded
	 */
	virtual string decodeMessage(string toDecode) = 0;

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
	virtual vector<string> getEncodings() = 0;
};
