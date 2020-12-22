#include<iostream>
using namespace std; 
  
// Returns modulo inverse of 'a' with respect to 'm' using extended Euclid Algorithm.
int inverse(int a, int m)
{ 
    int m0 = m, temp, quotient; 
    int x0 = 0, x1 = 1; 
  
    if (m == 1)
       return 0;
  
    // Apply extended Euclid Algorithm 
    while (a > 1)
    { 
        // q is quotient 
        quotient = a / m; 
  
        temp = m;
  
        // m is remainder now, process same as euclid's algorithm 
        m = a % m;
        a = temp;
  
        temp = x0;
  
        x0 = x1 - quotient * x0;
  
        x1 = temp;
    }
  
    // Make x1 positive 
    if (x1 < 0) 
       x1 += m0; 
  
    return x1;
} 

// k is size of number[] and remainder[].  
// Returns the smallest number x such that: 
// x % number[i] = remainder[i] for all i in 0...k-1 
// Assumption: Numbers in num[] are pairwise coprime 
// (gcd for every pair is 1)

int findMinX(int number[], int remainder[], int size) 
{ 
    // Compute product of all numbers 
    int product = 1;

    for (int i = 0; i < size; i++) 
        product *= number[i]; 
  
    // Initialize result 
    int result = 0; 
  
    // Apply above formula 
    for(int i = 0; i < size; i++) 
    { 
        int pp = product / number[i]; 
        result += remainder[i] * inverse(pp, number[i]) * pp;
        cout<<"\nx for ("<<number[i]<<", "<<remainder[i]<<") = "<<result;
    }
  
    return result % product;
} 

int main(void)
{ 
    
    int size;
    int numbers[100] = {0};
    int remainders[100] = {0};

    cout<<"\nEnter the number of co-prime pairs (<100) : ";
    cin>>size;
    
    for(int i=0;i<size;i++)
    {
        cout<<"\n\nNumber "<<i+1<<"\t: ";
        cin>>numbers[i];

        cout<<"\nRemainder "<<i+1<<"\t: ";
        cin>>remainders[i];
    }

    cout << "\n\nx = " <<findMinX(numbers, remainders, size); 
    return 0;
}