#include<iostream>
using namespace std;

int deleteX(int arr[], int n, int x) 
{ 
   // Search x
   int i; 
   for (i=0; i<n; i++) 
      if (arr[i] == x) 
         break; 
  
   // If x found 
   if (i < n) 
   { 
     // reduce size and move all elements on space ahead 
     n = n - 1; 
     for (int j=i; j<n; j++) 
        arr[j] = arr[j+1]; 
    return n; 
   }else{
       cout<<"Cannot find "<<x<<endl;
       return 0;
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
    cin>>x;
    n = deleteX(arr, n, x); 
    if(n==0){ //if the number to be deleted is not found
        cout<<"";
    }else{
        for (int i=0; i<n; i++) 
            cout << arr[i] << " "; 
    }
  
    return 0; 
}