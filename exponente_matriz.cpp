#include "exponente_matriz.hpp"
#include "ClaseTiempo.cpp"

std::vector<std::vector<double>> multiplicarMatrices(const vector < vector < double > > &m1, const vector < vector < double > > &m2, int n)
{

    std::vector < std::vector < double > > producto(n, std::vector<double>(n));

	for(unsigned int i = 0; i < m1.size(); i++) //Recorre filas de la primera matriz
	{
		for(unsigned int j = 0; j < m2[0].size(); j++) //Recorre columnas de la segunda matriz
		{
			producto[i][j] = 0.0;
			for(unsigned int k = 0; k < m1[0].size(); k++) //Recorre los elementos a multiplicar (numero de columnas de la primera matriz)
				producto[i][j] = producto [i][j] + m1[i][k]*m2[k][j];
		}
	}
    return producto;
}

double t_potencia_matriz_v1(std::vector<std::vector<double>> matriz, int n, std::vector<std::vector<double>> &result, int exp){
    
    Clock time;
    result = matriz;
    double tmedio = 0;

    time.start();
    for(int i = 0; i < exp-1; i++){
        result = multiplicarMatrices(matriz, result, n);
    }
    if(time.isStarted()){
        time.stop();
        tmedio = tmedio + time.elapsed();
    }
    return tmedio;
}