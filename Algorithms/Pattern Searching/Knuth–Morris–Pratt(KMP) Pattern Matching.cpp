/*
	Video Tutorials on KMP : 
			https://www.youtube.com/watch?v=sMARZCTPyNI(Bangla)
			https://www.youtube.com/watch?v=GTJr8OvyEVQ
			https://www.youtube.com/watch?v=KG44VoDtsAA
*/

#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
const int N = 1e6 + 2;
int lps[N]; //longest prefix suffix 
char s[N],p[N];
void kmpPreprocess(char *s)
{
	int len = strlen(s);
	lps[0] = 0;
	for(int i = 1, j = 0; i<len;)
	{
		if(s[i] != s[j])
		{
			if(j != 0)
				j = lps[j-1];
			else
			{
				lps[i] = 0;
				i++;
			}
		}
		else
		{
			lps[i] = j+1;
			j++,i++;
		}
	}
}
int kmp(char *text, char *pattern)
{
	kmpPreprocess(pattern);
	int j = 0,cnt = 0;
	int ps =  strlen(pattern);
	int sz = strlen(text);
	for(int i = 0; i<sz;)
	{	
		if(text[i] == pattern[j]) i++,j++;
		
		else
		{
			if(j != 0)
				j = lps[j-1];
			else
				i++;
		}
		if(j==ps)
		{
			cnt++;
		}
		//cout<<"cholche\n";
		
	}
	return cnt;
}
int main()
{
//	fast
	scanf("%s %s",s,p);
	int ans = kmp(s, p);
	printf("'%s' is found %d times in '%s'",p,ans,s);
    return 0;
}

