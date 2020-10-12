#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;


long double fib3(int n)
{
    long double i = 1,j = 0,k=0,h=1,t;

    while(n > 0)
    {
        if(n%2==1)
        {
            t=j*h;
            j=i*h+j*k+t;
            i=i*k+t;
        }

        t=h*h;
        h=2*k*h+t;
        k = k * k + t;
        n=n/2;
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
        cout<<"Metoda recursiva :"<<fib3(val[i])<<endl<<endl;
        finish=clock();

        float t=(finish-start)/CLOCKS_PER_SEC;
        cout<<"runtime = "<<setprecision(10)<<t/1000.0<<" ms"<<endl<<endl;
    }

    return 1;
}


