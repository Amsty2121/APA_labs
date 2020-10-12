#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

long double fib1(int n)
{
    if(n<2)
        return n;
    else
        return (fib1(n-1)+fib1(n-2));
}

int main()
{
    int val[]={10, 30, 50, 100, 1000, 10000};

    float start,finish;

    for(int i=0;i<6;i++)
    {
        start=clock();
        cout<<"Pentru valoarea a "<<val[i]<<"-lea numar: "<<endl;
        cout<<"Metoda recursiva :"<<fib1(val[i])<<endl<<endl;
        finish=clock();

        float t=(finish-start)/CLOCKS_PER_SEC;
        cout<<"runtime = "<<setprecision(10)<<t/1000.0<<" ms"<<endl<<endl;
    }

    return 1;
}
