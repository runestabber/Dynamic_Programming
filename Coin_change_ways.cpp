#include <iostream>
using namespace std;
#include <vector>
int main()
{
	cout<<"Enter the number of Coins"<<endl;
	int num;
	cin>>num;
	vector<int> coins(num,0);
	for(int i=0;i<num;i++)
	cin>>coins[i];
	cout<<"Enter the Amount"<<endl;
	int amt;
	cin>>amt;
	vector<int> result(amt+1,0);
	result[0]=1;
	
	for(int i=0;i<num;i++)
	{
		for(int j=coins[i];j<=amt;j++)		
		result[j]+=result[j-coins[i]];
		// Bottom-up building of result, first loop takes each coin 
		// and calculates the possible ways second loop fills value for
		// each amount.
		
	}
	
	
	cout<<"The ways to pay "<<amt<<" are "<<result[amt]<<" ";
	
}
