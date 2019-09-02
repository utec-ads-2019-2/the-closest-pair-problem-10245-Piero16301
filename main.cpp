#include <bits/stdc++.h>

using namespace std;

map <string, double> obtenerDistancia(vector <int> puntosX, vector <int> puntosY) {

    map <string, double> resultado;
    
    double distanciaMaxima = 0;
    int size = puntosX.size() - 1, iteraciones = 0;
    vector <int> posiciones_1;
    vector <int> posiciones_2;
    while (size != 0) {
        iteraciones += size;
        posiciones_1.push_back(size);
        size--;
    }
    for (int i = posiciones_1.size()-1; i > 0; --i)
        posiciones_2.push_back(posiciones_1[i]);
    
    int pivote = posiciones_2.back();
    int numero = posiciones_2.back() - 1;
    int indice = 0;

    for (int j = 0; j < iteraciones; ++j) {
        cout << "pivote: " << pivote << endl;
        cout << "numero: " << numero << endl;
        cout << "indice: " << indice << endl << endl;
        if (numero < pivote && numero >= 0) {
            cout << puntosX[indice] << ' ';
            numero--;
        } else {
            posiciones_2.pop_back();
            indice++;
            j--;
        }
    }

    resultado["INFINITY"] = distanciaMaxima;
    return resultado;

}

int main() {

    int bloques;
    while(scanf("%d", &bloques) == 1) {
        if (bloques != 0) {
            vector <int> puntosX;
            vector <int> puntosY;
            int x, y;

            for (int i = 0; i < bloques; ++i) {
                cin >> x >> y;
                puntosX.push_back(x);
                puntosY.push_back(y);
            }

            map <string, double> resultado = obtenerDistancia(puntosX, puntosY);

            for (auto itr = resultado.begin(); itr != resultado.end(); itr++) {
                if (itr->first == "INFINITY")
                    cout << itr->first << endl;
                else
                    cout << itr->second << endl;
            }

        } else {
            return 0;
        }
    }
    
}