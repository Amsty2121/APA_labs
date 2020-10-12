#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

long double fib2(int n)
{
    long double i=1,j=0;

    for(int k=1;k<=n;k++)
    {
        j=i+j;
        i=j-i;
    }

    return j;
}

int main()
{
    int val[]={10, 30, 50, 100, 1000, 10000};

    float start,finish;

    for(int i=0;i<6;i++)
    {
        start=clock();
        cout<<"Pentru valoarea a "<<val[i]<<"-lea numar: "<<endl;
        cout<<"Metoda recursiva :"<<fib2(val[i])<<endl<<endl;
        finish=clock();

        float t=(finish-start)/CLOCKS_PER_SEC;
        cout<<"runtime = "<<setprecision(10)<<t/1000.0<<" ms"<<endl<<endl;
    }

    return 1;
}
