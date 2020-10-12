#include<iostream>
using namespace std;

int main()
{
	int n,x;
	cin>>n;
    int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
    cin>>x;
    if(x>n || n==0){
        cout<<"Array length is smaller or 0";
        return 0;
    }else{
        cout << x <<"th Element is "<< arr[x-1]; 
    }

    return 0; 
}