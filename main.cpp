#include <iostream>
#include "Punto.h"

using namespace std;

int main()
{
    Punto P[] = {{65, 34}, {15, 80}, {56, 32}, {97, 12}, {43, 11}, {43, 34}};
    int n = sizeof(P) / sizeof(P[0]);
    cout<<"Dados los puntos: {65, 34}, {15, 80}, {56, 32}, {97, 12}, {43, 11}, {43, 34}"<<endl;
    cout<<"Calcular cual es la menor distancia que existe entre ellos"<<endl;
    cout<<"La menor distacia entre los puntos es: "<< parMasCercano(P, n);
    cout<<endl;

    return 0;
}
