#include <iostream>
#include <vector>
#include "funciones_comunes.hpp"
#include "exponente_matriz.hpp"
#include "ajustes.hpp"
#include "sistemaEcuaciones.hpp"



int main(){
    int exp, n_min, n_max, incre;
    double tiempo_aux, coef_det;
    std::vector<double> tiemposReales;
    std::vector<double> n_elementos;
    std::vector<double> tiemposEstimados;
    std::vector<double> coef_a;

    std::cout<<"Introduzca el exponente de la potencia que quieres calcular"<<std::endl;
    std::cin>>exp;
    std::cout<<"Introduzca el orden minimo de la matriz"<<std::endl;
    std::cin>>n_min;
    std::cout<<"Introduzca el orden maximo de la matriz"<<std::endl;
    std::cin>>n_max;
    std::cout<<"Introduzca el incremento del orden de la matriz de cada iteracion"<<std::endl;
    std::cin>>incre;


    for(int i = n_min; i <= n_max; i = i + incre){
        std::vector<std::vector<double>> matriz(i,std::vector<double>(i));
        std::vector<std::vector<double>> result(i,std::vector<double>(i));
        rellenarMatrizAleatorio(matriz, i);

        tiempo_aux = t_potencia_matriz_v1(matriz, i, result, exp);

        tiemposReales.push_back(tiempo_aux);
        n_elementos.push_back(i);
    }

    ajustePolinomico4(n_elementos, tiemposReales, coef_a);
    calcularTEstimadoPolinomio4(n_elementos,coef_a,tiemposEstimados);

    std::cout<<"|   n    ||   t_r   ||   t_e   |\n";

    for(int i = 0; i < n_elementos.size(); i++){
        std::cout<<std::fixed<<"| "<<n_elementos[i]<<"|| "<<tiemposReales[i]<<" || "<<tiemposEstimados[i]<<std::endl;
    }
        
    almacenarFichero(tiemposReales, n_elementos, tiemposEstimados);

    coef_det = calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);

    std::cout<<"El coeficiente de determinacion es "<<coef_det<<"\n";
    std::cout<<"La ecuacion de la curva es f(n) = "<<coef_a[0]<<" + "<<coef_a[1]<<"*n + "<<coef_a[2]<<"*n^2 + "<<coef_a[3]<<"*n^3 + "<<coef_a[4]<<"*n^4"<<endl;

    std::system("gnuplot crear_tabla_expo_v1.sh");

}