#include<bits/stdc++.h>
using namespace std;
void func(string s,int l,int r,char d,vector<char> &a)
{
	if(l>r)
		return;
	int i,pos=l;
	char mini=s[pos];
	for(i=l+1;i<=r;i++)
	{
		if(s[i]<mini)
		{
			pos=i;
			mini=s[i];
		}
	}
	if(mini>=d)
		return;
	a.push_back(mini);
	func(s,pos+1,r,d,a);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		char d;
		cin>>s>>d;
		vector<char> a;
		func(s,0,s.size()-1,d,a);
		int rem = s.size()-a.size(),i;
		for(i=0;i<a.size();i++)
			cout<<a[i];
		for(i=0;i<rem;i++)
			cout<<d;
		cout<<endl;
	}
	return 0;
}
