#include "ExpressionManager.h"
#include <string>
#include <stack>
#include <iostream>
#include <cctype>
#include <sstream>
#include <cstring>
#include <cstdlib>

using namespace std;

//check if expression is balanced--done!
bool ExpressionManager::isBalanced(string expression)
{
	stack<char> balanced;
	int expressionLength;
	expressionLength=strlen(expression.c_str());
	for (int i=0; i<expressionLength; i++)
	{

		if (expression[i]=='('||expression[i]=='{'||expression[i]=='[')
		{
			balanced.push(expression[i]);
		}
		if (expression[i]==')')
		{
			if (balanced.empty()||balanced.top()!='(')
				return false;
			else balanced.pop();
		
		}
		if (expression[i]=='}')
		{
			if (balanced.empty()||balanced.top()!='{')
				return false;
			else balanced.pop();
		}
		if (expression[i]==']')
		{
			if (balanced.empty()||balanced.top()!='[')
				return false;
			else balanced.pop();
		}
	}
if (balanced.empty())
return true;
else
return false;
}


//turn postfix into infix

string ExpressionManager::postfixToInfix(string postfixExpression)
{
stack<string> values;
string value1="";
string value2="";

int expressionLength;
expressionLength=strlen(postfixExpression.c_str());
for (int i=0; i<expressionLength;i++)
{
	string valuefinal="";
	if (isdigit(postfixExpression[i])){
				while(isdigit(postfixExpression[i])){
					valuefinal+=postfixExpression[i];
					i++;
					}
					values.push(valuefinal);
					}
	if (postfixExpression[i]=='+'||postfixExpression[i]=='-'||postfixExpression[i]=='/'||postfixExpression[i]=='*'||postfixExpression[i]=='%'){
			if (!values.empty()){
				value2=values.top();
				values.pop();
				} else return "invalid";
			if (!values.empty()){
				value1=values.top();
				values.pop();
				} else return "invalid";
			valuefinal="( "+ value1;
			valuefinal+=" ";
			valuefinal+=postfixExpression[i];
			valuefinal+=" ";
			valuefinal+=value2;
			valuefinal+=" )";
			values.push(valuefinal);
}
}
if (values.empty())
return "invalid";
string test=values.top();
values.pop();
if (values.empty())
return test;
else 
return "invalid";
}


//turn infix to Postfix
string ExpressionManager::infixToPostfix(string infixExpression)
{

if(!isBalanced(infixExpression))
return "invalid";
string postfixExpression="";
string postfixExpressionfinal;
stack<char> postfix;
int expressionLength;
expressionLength=strlen(infixExpression.c_str());

	for (int i=0; i<expressionLength; i++)
	{
		
		
		//move ints to the expression string
		if (isdigit(infixExpression[i])){
				while(isdigit(infixExpression[i])){
					postfixExpression+=infixExpression[i];
					i++;
					}
					postfixExpression+=" ";
			}
			if (isalpha(infixExpression[i])||(ispunct(infixExpression[i])&&(infixExpression[i]!='+'&&infixExpression[i]!='-'&&infixExpression[i]!='*'&&infixExpression[i]!='/'&&infixExpression[i]!='%'&&infixExpression[i]!='['&&infixExpression[i]!=']'&&infixExpression[i]!='{'&&infixExpression[i]!='}'&&infixExpression[i]!='('&&infixExpression[i]!=')')))
	return "invalid";
		if ((infixExpression[i]=='*'||infixExpression[i]=='-'||infixExpression[i]=='+'||infixExpression[i]=='/'||infixExpression[i]=='%')&&((postfixExpression==""||infixExpression[i-2]=='('||infixExpression[i-2]=='['||infixExpression[i-2]=='{'||infixExpression[i-2]=='+'||infixExpression[i-2]=='-'||infixExpression[i-2]=='*'||infixExpression[i-2]=='/'||infixExpression[i-2]=='%')||(infixExpression[i+2]==')'||infixExpression[i+2]==']'||infixExpression[i+2]=='}'||infixExpression[i+2]=='+'||infixExpression[i+2]=='-'||infixExpression[i+2]=='*'||infixExpression[i+2]=='/'||infixExpression[i+2]=='%'))||infixExpression[i]=='.')
		return "invalid";


//if its some form of punctuation

			if (infixExpression[i]=='('||infixExpression[i]=='{'||infixExpression=="[")
				postfix.push(infixExpression[i]);
			if (infixExpression[i]=='+'||infixExpression[i]=='-'){
				if (postfix.empty()||postfix.top()=='('||postfix.top()=='['||postfix.top()=='{')
					{
						postfix.push(infixExpression[i]);
					}
				else if (!postfix.empty())
				{
					while (!postfix.empty()&&(postfix.top()=='+'||postfix.top()=='-'||postfix.top()=='/'||postfix.top()=='*'||postfix.top()=='%')){
					postfixExpression+=postfix.top();
					postfixExpression+=" ";
					postfix.pop();
					
				}
				postfix.push(infixExpression[i]);
				}
			} else if (infixExpression[i]=='*'||infixExpression[i]=='/'||infixExpression[i]=='%') {
					if (postfix.empty()||postfix.top()=='+'||postfix.top()=='-'||postfix.top()=='{'||postfix.top()=='('||postfix.top()=='['){
						postfix.push(infixExpression[i]);
						} else if (!postfix.empty()&&(postfix.top()=='*'||postfix.top()=='/'||postfix.top()=='%'))
					{
						postfixExpression+=postfix.top();
						postfix.pop();
						postfix.push(infixExpression[i]);
						postfixExpression+=" ";
						
					}
				} else if (infixExpression[i]=='}'||infixExpression[i]==')'||infixExpression[i]==']'){
					while (postfix.top()!='('&&postfix.top()!='{'&&postfix.top()!='[') {
						postfixExpression+=postfix.top();
						postfixExpression+=" ";
						postfix.pop();
						
					}
						postfix.pop();
				}
				
		

	//just in the for loop	
	} //end for loop
		
	if (postfix.empty()==1)
			{
			
			
			return postfixExpression;
			} else {
				postfixExpression+=postfix.top();
				postfix.pop();
				
				
					while (postfix.empty()!=1){
							postfixExpression+=" ";
							postfixExpression+=postfix.top();
							postfix.pop();	
						
						}
				
				}
return postfixExpression;
}

//evaluate expression!

string ExpressionManager::postfixEvaluate(string postfixExpression)
{

int valuefinal;
int value1;
int value2;
stack<int> values;
int expressionLength;
expressionLength=strlen(postfixExpression.c_str());


	for (int i=0; i<expressionLength; i++)
	{
	
		if (isdigit(postfixExpression[i])){
				string value="";
				while(!isspace(postfixExpression[i])){
					
					value+=postfixExpression[i];
					i++;
					}
					values.push(atoi(value.c_str()));
			}
			if (postfixExpression[i]=='('||postfixExpression[i]=='{'||postfixExpression=="["||postfixExpression[i]==')'||postfixExpression[i]=='}'||postfixExpression=="]")
	return "invalid";
			
		if (postfixExpression[i]=='+'||postfixExpression[i]=='-'||postfixExpression[i]=='/'||postfixExpression[i]=='*'||postfixExpression[i]=='%'){
			if (!values.empty()){
				value2=values.top();
				values.pop();
				} else return "invalid";
			if (!values.empty()){
				value1=values.top();
				values.pop();
				} else return "invalid";
			
			if (postfixExpression[i]=='+'){
				valuefinal=value1+value2;
			}else if (postfixExpression[i]=='-'){
				valuefinal=value1-value2;
				
			}else if (postfixExpression[i]=='/'){
				if (value2==0){
				return "invalid";}
				valuefinal=value1/value2;
				
			}else if (postfixExpression[i]=='*'){
				valuefinal=value1*value2;
				
			}else if (postfixExpression[i]=='%'){
				if (value2==0){
				return "invalid";}
				valuefinal=value1%value2;
				
			}else return "invalid";
			values.push(valuefinal);
			

	}


}
if (values.empty()){
return "invalid";
} else {
stringstream ss;//create a stringstream
ss << values.top();//add number to the stream
   
return ss.str();
}
}



