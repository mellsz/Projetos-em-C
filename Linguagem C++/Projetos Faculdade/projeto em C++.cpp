/*____________ Cabeçalho_______________ 
-Projeto: Identificador de Tipos de Triangulo

-Descrição: O programa recebe tres valores do usuario e informa qual o tipo
do triângulo formado, ele informa se é um triangulo equilátero, isósceles,
escaleno, triangulo-retangulo ou se não forma um triangulo.

Autor: Mell Dias Vieira
_____________________________________
*/

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    double a, b, c;

    cout << "Identificador de Tipos de Triangulo" << endl;

    //Leitura dos dados informado pelo usuario

    cout << "Informe os tres lados do triangulo:" << endl;
    cout << "Lado A: ";
    cin >> a;
    cout << "Lado B: ";
    cin >> b;
    cout << "Lado C: ";
    cin >> c;

    //Validação: todos os lados precisam ser positivos

    if (a <= 0 || b <= 0 || c <= 0) {
        cout << "ERRO: Os lados devem ser valores positivos!" << endl;
        return 1;
    }

    //Desigualde Triangular: Para formar um triangulo valido,
    // a soma de quaisquer dois lados deve ser maior que o terceiro lado

    if ((a + b <= c) || (a + c <= b) || (b + c <= a)) {
        cout << "RESULTADO: Os valores informados NAO formam um triangulo." << endl;
        cout << "Motivo: a soma de dois lados deve ser maior que o terceiro." << endl;
 
    } else {
        cout << "RESULTADO: Os valores formam um triangulo!" << endl;
        cout << endl;
    }

    //Classificação pelo comprimento dos lados

    if (a == b && b == c) {
            // Todos os lados iguais
            cout << "Triangulo EQUILATERO (todos os lados sao iguais)" << endl;
        } else if (a == b || b == c || a == c) {
            // Exatamente dois lados iguais
            cout << "Triangulo ISOSCELES (dois lados sao iguais)" << endl;
        } else {
            // Todos os lados diferentes
            cout << "Triangulo ESCALENO (todos os lados sao diferentes)" << endl;
        }

    //Classificação usando o Teorema de Pitagoras

    double lados[3] = {a, b, c};
        sort(lados, lados + 3);
 
        double x = lados[0], y = lados[1], z = lados[2];
        double diff = fabs((x * x + y * y) - (z * z));
 
        cout << endl;
        cout << "  >> Classificacao pelos angulos:" << endl;
 
        if (diff < 1e-9) {
            cout << "Triangulo RETANGULO (satisfaz a^2 + b^2 = c^2)" << endl;
        } else if ((x * x + y * y) > (z * z)) {
            cout << "Triangulo ACUTANGULO (todos os angulos menores que 90 graus)" << endl;
        } else {
            cout << "Triangulo OBTUSANGULO (possui um angulo maior que 90 graus)" << endl;
        }
    }
  return 0;
}
