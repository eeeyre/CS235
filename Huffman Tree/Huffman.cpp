#include "Huffman.h"
#include <sstream>
#include <utility>
#include <iostream>


void Huffman::createTree(string message)
{
	if (message=="")
		return;
	vector<pair<int, char> > uniquechar;
	vector<Node*> nodevector;
	stringstream ss(message);
	char letter;
	bool found;
	while(ss>>noskipws>>letter)
	{
		found=false;
		//check if the letter is already in the priority vector
		for (int i=0; i<uniquechar.size();i++)
		{
			if (letter==uniquechar[i].second)
			{
				found=true;
				uniquechar[i].first++;

				break;
			}
		}
		//if you don't find it in the vector add it.
		if (found==false)
		{
			pair<int, char> inputvalue (1,letter);
			uniquechar.push_back(inputvalue);
		}

	}
	//order vector
	bool ordered=false;
	while (!ordered)
	{
		ordered=true;
		for (int i=1;i<uniquechar.size();i++)
		{
			if (uniquechar[i-1].first>uniquechar[i].first||(uniquechar[i-1].first==uniquechar[i].first&&uniquechar[i-1].second==(char)007))
			{
				ordered=false;
				pair<int,char> temp (uniquechar[i-1].first, uniquechar[i-1].second);
				uniquechar[i-1].first=uniquechar[i].first;
				uniquechar[i-1].second=uniquechar[i].second;
				uniquechar[i].first=temp.first;
				uniquechar[i].second=temp.second;
			}
		}
	}
	//*/
	//cout<<"freq\t|"<<"\tLetter\n";
	for (int i=0;i<uniquechar.size();i++)
	{
		nodevector.push_back(new Node(uniquechar[i].second, uniquechar[i].first));
	}
	//put into tree
	while(nodevector.size()>1)
	{
		////cout<<nodevector.size()<<endl;
		Node* new_node=new Node((char)007,nodevector[0]->frequency+nodevector[1]->frequency, nodevector[0], nodevector[1]);
		nodevector.push_back(new_node);
		nodevector[0]=nodevector[nodevector.size()-1];
		for (int i=2;i<nodevector.size();i++)
		{
			nodevector[i-1]=nodevector[i];
		}
		nodevector.pop_back();
		nodevector.pop_back();

		bool nodeordered=false;
		while (!nodeordered)
		{
			nodeordered=true;
			for (int i=1;i<nodevector.size();i++)
			{
				//////cout<<nodevector.size()<<endl;
				////cout<<"ifstatement1------>";
				if ((nodevector[i-1]->frequency>nodevector[i]->frequency||(nodevector[i-1]->frequency==nodevector[i]->frequency&&nodevector[i-1]->node_data==(char)007)))
				{////cout<<"start----->";
			nodeordered=true;
			Node* temp=nodevector[i-1];
			nodevector[i-1]=nodevector[i];
			nodevector[i]=temp;
					////cout<<"end------>";
				} ////cout<<"complete\n";
				
			}
		}

	}
	rootnode=nodevector[0];

}



string Huffman::encodeMessage(string toEncode)
{
	string encoded;
	stringstream ss(toEncode);
	char letter;
	getEncodings();
	if (encoding.size()==0)
	{
		return "";
	}
	while(ss>>noskipws>>letter)
	{
		for (int i=0; i<encoding.size(); i++)
		{
			stringstream qq(encoding[i]);
			char in;
			qq >> noskipws>>in;
			if (in==letter)
			{
				string code;
				qq >> skipws>>code;
				encoded+=code;
				break;
			}
			if (i==encoding.size()-1)
				return "";
		}
	}
	return encoded;
}



string Huffman::decodeMessage(string toDecode)
{
	string message;
	char temp;
	Node* node_ptr=rootnode;
	if (node_ptr==NULL)
		return "";
	bool updatenode=false;
	bool shifted=false;
	stringstream ss(toDecode);
	char in;
	while (ss >> in)
	{
		
		if (node_ptr->right==NULL)
		{
			return "";
		}
		else if (in=='1')
		{
			node_ptr=node_ptr->right;
			temp=node_ptr->node_data;
		}else
		{
			node_ptr=node_ptr->left;
			temp=node_ptr->node_data;
		}
		if (node_ptr->node_data!=(char)007)
		{
			temp=node_ptr->node_data;
			message+=node_ptr->node_data;
			node_ptr=rootnode;
		}
	}
	if (temp==(char)007)
	{
		return "";
	}
	////cout<<message<<endl;

	return message;
}


vector<string> Huffman::getEncodings()
{
	Node* node_ptr=rootnode;
	if (rootnode!=NULL)
		encodelist(node_ptr);
	return encoding;
}


