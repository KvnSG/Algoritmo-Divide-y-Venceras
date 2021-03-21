#ifndef PUNTO_H_INCLUDED
#define PUNTO_H_INCLUDED
#include <bits/stdc++.h>

using namespace std;

class Punto
{
	public:
	int x, y;
};

// Funcion para ordenar la matriz de puntos según coordenada X
int compararX(Punto p1, Punto p2) {
    return (p1.x < p2.x);
}

// Funcion para ordenar la matriz de puntos según coordenada Y
int compararY(Punto p1, Punto p2) {
    return (p1.y < p2.y);
}

//Funcion para encontrar la distancia entre los 2 puntos
float distancia(Punto p1, Punto p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

//Funcion que devuelve la menor distancia entre dos puntos en P [] de tamaño n (un conjunto)
float minimaDistacia(Punto pts[], int n) {
    float min = 9999;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (distancia(pts[i], pts[j]) < min)
                min = distancia(pts[i], pts[j]);
    return min;
}

//Funcion para encontrar el minimo de dos valores flotantes
float min(float a, float b) {
    return (a < b)? a : b;
}


// Una función de utilidad para encontrar la distancia entre los puntos más cercanos
//Todos los puntos en strip [] se ordenan según la coordenada y.
//Todos tienen una parte superior limitado a la distancia mínima como d.
float distanciaPuntos(Punto strip[], int size, float d) {
    float min = d;
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (distancia(strip[i],strip[j]) < min)
                min = distancia(strip[i], strip[j]);
    return min;
}

// Una función recursiva para encontrar el distancia más pequeña.
float puntoCercano(Punto xOrdenado[], Punto yOrdenado[], int n){
    if (n <= 3)
        return minimaDistacia(xOrdenado, n);
    int mid = n/2;

    Punto punto_medio = xOrdenado[mid];
    Punto yIzquierda[mid+1];     //Puntos de Y ordenados en el lado izquierdo
    Punto yDerecha[n-mid-1];  // Puntos de Y ordenados en el lado derecho
    int inicio_izquierda = 0, inicio_derecha = 0;

    for (int i = 0; i < n; i++) {       //Separamos los puntos ordenados de Y
        if (yOrdenado[i].x <= punto_medio.x)
            yIzquierda[inicio_izquierda++] = yOrdenado[i];
        else
            yDerecha[inicio_derecha++] = yOrdenado[i];
    }

    float leftDist = puntoCercano(xOrdenado, yIzquierda, mid);
    float rightDist = puntoCercano(yOrdenado + mid, yDerecha, n-mid);
    float dist = min(leftDist, rightDist);

    Punto strip[n];      //Contiene los puntos mas cercanos a la mitad la la mattriz
    int j = 0;

    for (int i = 0; i < n; i++)
        if (abs(yOrdenado[i].x - punto_medio.x) < dist) {
            strip[j] = yOrdenado[i];
            j++;
        }
    return min(dist, distanciaPuntos(strip, j, dist));    //encuentra el valor minimo usando la distancia y el punto mas cercano
}

float parMasCercano(Punto pts[], int n) {    //encuentra la distancia del par mad cercano en un conjunto de puntos
    Punto xOrdenado[n];
    Punto yOrdenado[n];

    for (int i = 0; i < n; i++) {
        xOrdenado[i] = pts[i];
        yOrdenado[i] = pts[i];
    }

    sort(xOrdenado, xOrdenado+n, compararX);
    sort(yOrdenado, yOrdenado+n, compararY);
    return puntoCercano(xOrdenado, yOrdenado, n);
}


#endif // PUNTO_H_INCLUDED
