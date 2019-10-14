// A Dynamic Programming solution for Rod cutting problem 
#include<stdio.h> 
#include<limits.h>
#include<string>
#include<iostream>

using namespace std;

// A utility function to get the maximum of two integers 
int max(int a, int b) { return (a > b)? a : b;} 

/* Returns the best obtainable price for a rod of length n and 
price[] as prices of different pieces */
int cutRod(int price[], int n) { 
    int val[n+1]; 
    string cuts[n+1];
    val[0] = 0; 
    cuts[0] = "0";
    int i, j, aux;
    string cut = "";

// Build the table val[] in bottom up manner and return the last entry 
// from the table 
    for (i = 1; i<=n; i++) { 
    	int max_val = INT_MIN;   // INT_MIN para inicializarlo en el menor valor posible
    	for (j = 0; j < i; j++) {
    	    aux = max_val;
    	    max_val = max(max_val, price[j] + val[i-j-1]); 
            
    	    if (max_val == price[j] + val[i-j-1]) {
    	        string str1 = to_string(price[j]);
                string str2 = to_string(val[i-j-1]);
    	        cut = str1 + " + " + str2;
    	    } else {
    	        string str3 = to_string(aux);
    	        cut = str3;   
    	    }
    	}
    	cout << cut << endl;
    	cuts[i] = cut;
    	val[i] = max_val; 
    } 
    return val[n]; 
} 

/* Driver program to test above functions */
int main() { 
	int arr[] = {1, 5, 8, 9, 10, 17, 17, 20}; 
	int size = sizeof(arr)/sizeof(arr[0]); 
	printf("Maximum Obtainable Value is %dn", cutRod(arr, size)); 
	getchar(); 
	return 0; 
} 
