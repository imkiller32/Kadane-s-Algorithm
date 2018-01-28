#include<bits/stdc++.h>
#define inf 100
using namespace std;
int maxup=0,maxdown=0,maxleft,maxright;
int Kadane(int a[],int n)
{
	int max_current,max_global;
	max_current=max_global=a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]>max_current+a[i])
			maxup=i;
		else if(max_global<max_current+a[i])
			maxdown=i;
		max_current=max(a[i],max_current+a[i]);
		if(max_current>max_global)
			max_global=max_current;
	}
	return max_global;
}
int main()
{
	int n,a[inf][inf],b[inf],i,max=0,max_up,max_down,max_left,max_right,j,left,right,temp;
	cout<<"Enter n: ";
	cin>>n;
	cout<<"Enter "<<n*n<<" integers : ";
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	cin>>a[i][j];
	for(left=0;left<n;left++)
	{
		for(i=0;i<n;i++)
		b[i]=0;
		for(right=left;right<n;right++)
		{
			for(j=0;j<n;j++)
			b[j]=b[j]+a[j][right];
			temp=Kadane(b,n);
			if(max<temp)
			{
				max=temp;
				max_left=left;
				max_right=right;
				max_up=maxup;
				max_down=maxdown;
			}
		}
	}
	cout<<"Maximum subarray sum = "<<max<<endl;
	//cout<<max_up<<endl<<max_down<<endl<<max_left<<endl<<max_right;
	for(i=max_up;i<=max_down;i++)
	{
		for(left=max_left;left<=max_right;left++)
		{
			cout<<a[i][left]<<" ";
		}
		cout<<endl;
	}
}
