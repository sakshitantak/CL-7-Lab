#include<iostream>
#include<math.h>
#include<string>

using namespace std;

// Find GCD
int GCD(int x, int y) {
   int t;
   while(1) {
      t = x % y;
      if(t == 0)
         return y;
      x = y;
      y = t;
   }
}


int main() {
   //Declare variables for 2 prime nos.
   double p1;
   double p2;
   
   //Input prime no 1
   cout<<"\n\nEnter prime 1 : ";
   cin>>p1;

   //Input prime no 2
   cout<<"\n\nEnter prime 2 : ";
   cin>>p2;

   //calculate n
   double n = p1 * p2;
   double track;

   //calculate phi
   double phi = (p1 - 1) * (p2 - 1);
   
   //Public key
   //e : for encrypt
   double e;
   cout<<"\n\nInput public key : ";
   cin>>e;
   
   //For checking that 1 < e < phi(n) and GCD(e, phi(n)) = 1; i.e., e and phi(n) are co-primes.
   while(e < phi) {
      track = GCD(e, phi);
      if(track == 1)
         break;
      else
         e++;
   }

   //private key
   //d stands for decrypt
   //choosing d such that it satisfies d*e = 1 mod phi
   double d1 = 1/e;
   double d = fmod(d1,phi);
   
   //Input message
   double message;
   cout<<"\n\nPlease enter your message : ";
   cin>>message;

   //Encrypt message
   double c = pow(message,e);
   double m = pow(c,d);
   c = fmod(c,n);
   m = fmod(m,n);
   

   cout<<"Original Message : "<<message;
   cout<<"\n"<<"p1 = "<<p1;
   cout<<"\n"<<"p2 = "<<p2;
   cout<<"\n"<<"n = p1.p2 = "<<n;
   cout<<"\n"<<"phi = "<<phi;
   cout<<"\n"<<"e = "<<e;
   cout<<"\n"<<"d = "<<1/d;
   cout<<"\n"<<"Encrypted Message : "<<c;
   cout<<"\n"<<"Decrypted Message : "<<m;

   return 0;
}