#include <iostream>
using namespace std;
#include <string>

int main()
{
	string str1,str2;
	cout<<"Enter the first string"<<endl;
	cin>>str1;
	cout<<"Enter the second string"<<endl;
	cin>>str2;
	int len1=str1.length();
	int len2=str2.length();
	int arr[len1+1][len2+1];
	for(int i=0;i<=len1;i++)
	{
		for(int j=0;j<=len2;j++)
		arr[i][j]=0;
	}
	
	//Finding the length of Largest Common Sub-sequence by bottom-up approach.
	for(int i=0;i<=len1;i++)
	{
		for(int j=0;j<=len2;j++)
		{
			if(i==0||j==0)
			arr[i][j]=0;
			else if(str1[i-1]==str2[j-1]) 
			{
				arr[i][j]=arr[i-1][j-1]+1;
			}
			else
			{
				int x=arr[i-1][j];
				int y=arr[i][j-1];
				arr[i][j]=(x>y?x:y);
			}
		}
	}
	

	int s=arr[len1][len2];
	string res(s,0);
	//Finding actual subsequence by traversing through matrix.
	for(int i=len1;i>0;)
	{
		for(int j=len2;j>0;)
		{	
			if(str1[i-1]==str2[j-1])
			{
			
			res[--s]=str1[i-1];
			i--,j--;
			}
			else
			{
				int x=arr[i-1][j];
				int y=arr[i][j-1];
				if(x>y)
				--i;
				else
				--j;
				
			}
		}
	}
	
	cout<<"The longest common subsequence is "<<res<<endl;
	cout<<"The Length is "<<arr[len1][len2];
}
