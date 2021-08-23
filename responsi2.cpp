#include <iostream>
using namespace std;

int findMin(int *A, int n)
{
	int out;
    if(n!=0){
    	if(A[n]<=findMin(A, n-1)){
    		out = A[n];
    	}else{
    		out = findMin(A, n-1);
    	}
    }else{
    	out = A[n]; 
    }
    return out;
}

int findMax(int *A, int n)
{
   int out;
    if(n!=0){
    	if(A[n]>=findMax(A, n-1)){
    		out = A[n];
    	}else{
    		out = findMax(A, n-1);
    	}
    }else{
    	out = A[n]; 
    }
    return out;
}
 

int main()
{	
	int n;
	cout << "Input   : "; cin>>n;
	int A[n];
	for(int i=0;i<n;i++){
		cout << "Input data-" << i << " : "; cin >> A[i];
	}cout << endl;

    cout << "Min value is : " << findMin(A, n-1) << endl;
    cout << "Max value is : " << findMax(A, n-1);
    return 0;
}