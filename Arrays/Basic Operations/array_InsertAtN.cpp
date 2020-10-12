#include<iostream>
using namespace std;


int* insert(int n, int arr[], int x, int at) 
{ 
    int i; 
    n++; //increasing size only by 1
  
    // shift elements forward 
    for (i = n; i >= at; i--) 
        arr[i] = arr[i - 1]; 
  
    // insert x at position
    if(at>n){ //covered an edge case
        cout<<"Array length is "<<n-1<<". Please give a valid position.";
        return 0;
    }else{
        arr[at - 1] = x; 
        return arr; 
    }


} 

int main()
{
	int n,x,at;
	cin>>n;
    int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
    cin>>x>>at; //number to be inserted
    int *p = insert(n, arr, x, at); //checking if user gives invalid position
    if(p==0){
        cout<<"";
    }else{
        //printing updated array
            for (int i = 0; i < n + 1; i++) 
                cout << arr[i] << " "; 
            cout << endl;
    }
  
    return 0; 
}