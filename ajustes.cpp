#include <vector>
#include <iostream>
#include "ajustes.hpp"
#include "funciones_comunes.hpp"
#include "sistemaEcuaciones.hpp"

void ajustePolinomico4(std::vector <double> &n, std::vector <double> &tiemposReales, std::vector <double> &a){
    std::vector<std::vector<double>> A(5, std::vector<double>(5));
    std::vector<std::vector<double>> B(5, std::vector<double>(1));
    std::vector<std::vector<double>> X(5, std::vector<double>(1));

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            A[i][j] = sumatorio(n,tiemposReales,i+j,0);
            if(j == 0){
                B[i][j] = sumatorio(n,tiemposReales,i,1);
            }
        }
    }

    resolverSistemaEcuaciones(A,B,5,X);

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 1; j++){
            a.push_back(X[i][j]);
        }
    }

}

void calcularTEstimadoPolinomio4(const std::vector <double> &n, const std::vector <double> &a, std::vector <double> &tiemposEstimados){
    for(int i = 0; i < n.size(); i++){
        tiemposEstimados.push_back(a[0]+a[1]*n[i]+a[2]*pow(n[i],2)+a[3]*pow(n[i],3)+a[4]*pow(n[i],4));
    }
}
