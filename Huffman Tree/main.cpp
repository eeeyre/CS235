#include "HuffmanInterface.h"
#include "Huffman.h"

#include <iostream>

int main()
{
	Huffman* testing=new Huffman();
	Huffman* testing2=new Huffman();
	testing->createTree("m0");
	cout<<(char)007;
	testing->getEncodings();
	cout<<testing->encodeMessage("m")<<endl;
	cout<<"00010011101001101100001110000111101111100001110001010000010000001101110001\n";
	cout<<testing->decodeMessage("0");
	cout<<testing->encodeMessage("zzytrs")<<endl;
	cout<<testing->decodeMessage("1")<<endl;
	testing2->createTree("This is a big test, I have no idea if it will work in the end, but I'll try a bunch of different things  new line is first.   now we'll try characters:  !@#$%^&*();'[],./{}:<>?`~.  Spanish Characters:  íóúéáñ|°qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM");
	testing2->getEncodings();
	cout<<testing2->decodeMessage(testing2->encodeMessage("lETS SEE IF SOMETHING WORKS I have no idea, but I can hope, right?"))<<endl;

}