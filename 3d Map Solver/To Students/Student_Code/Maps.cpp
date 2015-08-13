#include "Maps.h"
#include <sstream>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;
void Maps::createMap(string input)
{
	string prefix="";
	string temp="";
	string prefix1="";
	string prefix2="";
	vector<string> suffix;
	string suffixvalue="";
	stringstream ssinput(input);
	ssinput >> prefix1;
	ssinput >> prefix2;
	ssinput >> suffixvalue;
	do {
			if (temp!="")
			suffixvalue=temp;
			suffix.push_back(suffixvalue);
			prefix=prefix1+" "+prefix2;
			bool repeat=false;
			for (int i=0; i<prefixes.size();i++) {
				if (prefixes[i]==prefix){
					suffixes[i].push_back(suffixvalue);
					repeat=true; } }
			if (!repeat) {
				prefixes.push_back(prefix);
				suffixes.push_back(suffix); }
			prefix1=prefix2;
			prefix2=suffixvalue;
			suffix.pop_back();
			cout<<prefix<<" | "<<suffixvalue<<endl;	
	} while (ssinput >> temp);
			suffixvalue="THE_END";
			suffix.push_back(suffixvalue);
			bool repeat=false;
			prefix = prefix1+" "+prefix2;
			for (int i=0; i<prefixes.size();i++) {
				if (prefixes[i]==prefix) {
					suffixes[i].push_back(suffixvalue);
					repeat=true; } }
			if (!repeat) {
				prefixes.push_back(prefix);
				suffixes.push_back(suffix); } cout<<prefix<<" | "<<suffixvalue<<endl<<endl;}
vector<string> Maps::getSuffixList(string prefix)
{
	vector<string> empty;
	for (int i=0;i<prefixes.size();i++) {
		if (prefixes[i]==prefix) {
			return suffixes[i]; } }
	return empty;
}
string Maps::generateText()
{
	string suffix="";
	string generatedText="";
	string prefix1="";
	string prefix2="";
	string prefix="";
	int i=0;
	if (prefixes.size()==0)
		return generatedText;
	generatedText+=prefixes[0];
		suffix=suffixes[0][(rand()%suffixes[0].size())];
	generatedText+=" "+suffix;
	while (suffix!="THE_END") {
		stringstream ssinput(prefixes[i]);
		ssinput >> prefix1;
		ssinput >> prefix2;
		prefix=prefix2+" "+suffix;
		for (int j=0;j<prefixes.size();j++) {
			if (prefixes[j]==prefix) 
				i=j; }	
		suffix=suffixes[i][(rand()%suffixes[i].size())];
		if (suffix!="THE_END")
			generatedText+=" "+suffix; }
		return generatedText;
}