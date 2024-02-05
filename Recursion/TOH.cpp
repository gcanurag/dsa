#include<iostream>
using namespace std;


void TOH(int n, string source, string auxillary, string destination)
{
    if(n==1){
        cout << "Moved from " << source << " to " << destination<<endl;
    }else{
        TOH(n - 1, source, destination, auxillary);
        TOH(1, source, auxillary, destination);
        TOH(n - 1, auxillary, source, destination);
    }
}

int main()
{
    TOH(3, "A", "B", "C");
    return 0;
}