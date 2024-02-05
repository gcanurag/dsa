#include <iostream>
using namespace std;

int fib(int n)
{
    int a, b,count;
    a = b=count = 1;
   if(n==0 || n==1)
   {
      return n;
   }else{
       return fib(n - 1) + fib(n - 2);
   }
}

int main()
{
    int n, i=0;
    cout << "Enter the number of terms";
    cin >> n;
    while ( i < n)
    {
        cout << " " << fib(i);
        i++;
    }
    return 0;
}