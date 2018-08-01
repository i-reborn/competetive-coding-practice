#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	stack <char> st;
	cin>>s;
	int len=s.length();
	int i=0;
	for(i=0;i<len;i++)
	{
		if (s[i]=='('||s[i]=='{'||s[i]=='[')
		{
			st.push(s[i]);
		}
		if (s[i]==')')
		{
			if(st.top()=='(')
			{
				st.pop();
			}
			else
			{
				break;
			}
		}
		if (s[i]==']')
		{
			if(st.top()=='[')
			{
				st.pop();
			}
			else
			{
				break;
			}
		}
		if (s[i]=='}')
		{
			if(st.top()=='{')
			{
				st.pop();
			}
			else
			{
				break;
			}
		}
	}
	if(i==len && st.empty()==1)
	{
		cout<<"Balanced";
	}
	else
	{
		cout<<"Unbalanced";
	}
	
	return 0;
}
