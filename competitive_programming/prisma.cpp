#include<iostream>
using namespace std;
int i;
int n = 10;
void function2()
{
    if(i < n)
        cout << i << endl;
}
void function1()
{
    n = 100;
    for (i = 0; i < n;i++)
    {
        function2();
    }
}
int main()
{
    function1();
    
}