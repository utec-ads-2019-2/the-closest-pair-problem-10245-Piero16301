#include <bits/stdc++.h>

using namespace std;

double calcularDistancia(double x1, double y1, double x2, double y2) {

    double resultado;
    resultado = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
    return resultado;

}

map <string, double> obtenerDistanciaMaxima(vector <double> puntosX, vector <double> puntosY) {

    map <string, double> resultado;
    
    double distanciaMinima = 10000.0;
    int size = puntosX.size();
    
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j){
            double distanciaTemporal = calcularDistancia(puntosX[i], puntosY[i], puntosX[j], puntosY[j]);
            distanciaMinima = (distanciaTemporal < distanciaMinima && distanciaTemporal != 0) ? distanciaTemporal : distanciaMinima;
        }
    }

    if (distanciaMinima < 10000 && distanciaMinima > 0){
        resultado["NUMERO"] = distanciaMinima;
    } else{
        resultado["INFINITY"] = distanciaMinima;
    }
    return resultado;

}

int main() {

    int bloques;
    while(scanf("%d", &bloques) == 1) {
        if (bloques != 0) {
            vector <double> puntosX;
            vector <double> puntosY;
            double x, y;

            for (int i = 0; i < bloques; ++i) {
                cin >> x >> y;
                puntosX.push_back(x);
                puntosY.push_back(y);
            }

            map <string, double> resultado = obtenerDistanciaMaxima(puntosX, puntosY);

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
