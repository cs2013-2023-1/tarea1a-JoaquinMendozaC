// =============================================================================
// Tarea 1a: Matrices Dinamicas, Constructores y Sobrecarga de Operadores
// =============================================================================
// 1. Utilizar unicamente los archivos de cabecera y codigo fuente provistos. Es
//    decir: main.cpp, foo.h y foo.cpp.
// 2. No se permite el uso de librerias adicionales.

#include "foo.h"

// Puede validar su codigo con la siguiente funcion main
int main(){
    Matriz2D m1;
    Matriz2D m2(3);
    Matriz2D m3(5,2);

    cout<<m1;
    cout<<"\n";
    cout<<m3;
    cout<<"\n";

    Matriz2D m4 = t(m3);
    cout<<m4;
}
