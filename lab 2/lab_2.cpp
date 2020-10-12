#include <iostream>
#include <cmath>

using namespace std;

int prim_basic(int, int*);
int prim_sqrt(int, int*);
int prim_Erastosthenes(int, int*);

int main()
{
    int n;
    cout << "Da numarul limita  n -> ";
    cin >> n;
    int number = 0;
    int iter = 0;

    /*cout << endl << "Prin metoda bazica";
    for(int i = 2; i <= n; i++)
    {
        if(prim_basic(i, &iter) == 1)
        {
            number += 1;
            cout << endl << "Numarul -> " << i << " este prim";
        }
    }
    cout << endl << "Sunt -> " << number << " numere prime in limita pina la numarul -> " << n;
    cout << endl << "Numarul de iteratii " << iter;
    cout << endl;
    number = 0;
    iter = 0;

    cout << endl << "Prin metoda bazica-optimizata";
    for(int i = 2; i <= n; i++)
    {
        if(prim_sqrt(i, &iter) == 1)
        {
            number += 1;
            cout << endl << "Numarul -> " << i << " este prim";
        }
    }
    cout << endl << "Sunt -> " << number <<" numere prime in limita pina la numarul -> " << n;
    cout << endl << "Numarul de iteratii " << iter;
    cout << endl;*/
    number = 0;
    iter = 0;

   // cout << endl << " Prin metoda lui Erastosthenes";
    number = prim_Erastosthenes(n, &iter);
    cout << endl << "Sunt -> " << number <<" numere prime in limita pina la numarul -> " << n;
    cout << endl << "Numarul de iteratii " << iter;

    return 0;
}

int prim_sqrt(int i, int *iter)
{
    int j = 2;
    int n2 = sqrt(i);
    int aux = 0;
    while(j <= n2 && aux == 0)
    {
        *iter = *iter + 1;
        if(i % j == 0)
            aux = 1;
        j++;
    }

    if(aux == 0)
        return 1;
    else
        return 0;
}

int prim_basic(int i, int *iter)
{
    int aux = 0;
    int j = 2;
    while(aux == 0 && j < i )
    {
        *iter = *iter + 1;
        if(i % j == 0)
            aux = 1;
        j++;
    }

    if(aux == 0)
        return 1;
    else
        return 0;
}

int prim_Erastosthenes(int n, int *iter)
{
    int *prim=new int[n+1];
    for(int i = 0; i < n + 1; i++)
        prim[i] = 1;
    int total = 0;

    for (int i=2; i*i<=n; i++)
    {
        if (prim[i] == 1)
        {
            for (int j=i*i; j<=n; j += i)
            {
                if(prim[j] == 1)
                    prim[j] = 0;

                *iter = *iter + 1;
            }
        }
    }

    for(int i = 2; i < n + 1 ; i++)
        if(prim[i] > 0)
        {
            //cout << endl << "Numarul -> " << i << " este prim";
            total++;
        }

    return total;
}
