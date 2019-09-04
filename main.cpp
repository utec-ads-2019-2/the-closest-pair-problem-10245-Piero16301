#include <bits/stdc++.h>

using namespace std;

double calcularDistancia(vector <double> punto1, vector <double> punto2) {

    double resultado;
    resultado = sqrt(pow(punto1[0] - punto2[0], 2) + pow(punto1[1] - punto2[1], 2));
    return resultado;

}

bool ordenarAscendente(vector <double> &a, vector <double> &b) {

    return (a[0] < b[0]);

}

map <string, double> obtenerDistanciaMaxima(vector < vector<double> > puntos, int bloques) {

    map <string, double> resultado;
    
    double distanciaMinima = 10000;
    sort(puntos.begin(), puntos.end(), ordenarAscendente);

    for (int i = 0; i < bloques; ++i) {
        for (int j = i + 1; j < bloques; ++j){
            double distancia = puntos[j][0] - puntos[i][0];
            if (distancia >= distanciaMinima) break;
            distancia = calcularDistancia(puntos[i], puntos[j]);
            if (distancia < distanciaMinima) 
                distanciaMinima = distancia;
        }
    }

    if (distanciaMinima == 10000){
        resultado["INFINITY"] = distanciaMinima;
    } else{
        resultado["NUMERO"] = distanciaMinima;
    }
    return resultado;

}

int main() {

    int bloques;
    while(scanf("%d", &bloques) == 1) {
        if (bloques != 0) {
            vector < vector<double> > puntos;
            double x, y;

            for (int i = 0; i < bloques; ++i) {
                vector <double> punto;
                cin >> x >> y;
                punto.push_back(x);
                punto.push_back(y);
                puntos.push_back(punto);
            }

            map <string, double> resultado = obtenerDistanciaMaxima(puntos, bloques);

            for (auto itr = resultado.begin(); itr != resultado.end(); itr++) {
                if (itr->first == "INFINITY") {
                    cout << itr->first << endl;
                } else {
                    cout << fixed << setprecision(4);
                    cout << itr->second << endl;
                }
            }

        } else {
            return 0;
        }
    }
    
}
