#include "foo.h"

Matriz2D::Matriz2D(){
    // Constructor por defecto
    srand(time(0));

    filas = 3;
    columnas = 3;

    ptr = new float *[filas];

    for (int i = 0; i < 3; ++i) {
        ptr[i] = new float[columnas];
    }

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            ptr[i][j] = float (rand() & (99))/100;
        }
    }
}

Matriz2D::Matriz2D(int n){
    // Constructor con un parametro
    srand(time(0));

    filas = n;
    columnas = n;

    ptr = new float * [filas];

    for (int i = 0; i < n; ++i) {
        ptr[i] = new float[columnas];
    }

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            ptr[i][j] = float (rand() & (99))/100;
        }
    }
}

Matriz2D::Matriz2D(int n, int m){
    // Constructor con dos parametros
    srand(time(0));

    filas = n;
    columnas = m;

    ptr = new float * [filas];

    for (int i = 0; i < n; ++i) {
        ptr[i] = new float[columnas];
    }

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            ptr[i][j] = float (rand() & (99))/100;
        }
    }

}

Matriz2D::Matriz2D(const Matriz2D& m) :ptr(m.ptr){
    // Constructor de copia
    filas = m.filas;
    columnas = m.columnas;
}

Matriz2D::Matriz2D(Matriz2D&& m) :ptr(m.ptr){
    // Constructor de movimiento
    columnas = m.columnas;
    filas = m.filas;
    m.ptr = NULL;
}

Matriz2D t(Matriz2D& m){
    // Transpuesta de una matriz

    int f = m.columnas;
    int c = m.filas;

    Matriz2D obj(f,c);

    for (int i = 0; i < m.filas; ++i) {
        for (int j = 0; j < m.columnas; ++j) {
            obj.ptr[j][i] = m.ptr[i][j];
        }
    }
    return obj;
}

std::ostream& operator<<(std::ostream& os, const Matriz2D& m){
    // Sobrecarga del operador <<
    for (int i = 0; i < m.filas; ++i) {
        for (int j = 0; j < m.columnas; ++j) {
            cout.width(5);
            os<<m.ptr[i][j]<<" ";
        }
        os<<endl;
    }
}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador +
    int f, c;
    if (m1.filas == m2.filas && m1.columnas == m2.columnas){
        f = m1.filas;
        c = m1.columnas;
        Matriz2D obj(f,c);

        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) {
                obj.ptr[i][j] = m1.ptr[i][j] + m1.ptr[i][j];
            }
        }
        return obj;
    } else{
        cout<<"No fue posible sumar ambas matrices";
    }
}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador -

    int f, c;
    if (m1.filas == m2.filas && m1.columnas == m2.columnas){
        f = m1.filas;
        c = m1.columnas;
        Matriz2D obj(f,c);

        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) {
                obj.ptr[i][j] = m1.ptr[i][j] - m1.ptr[i][j];
            }
        }
        return obj;
    } else{
        cout<<"No fue posible restar ambas matrices";
    }

}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador *
    int f, c;
    if (m1.columnas == m2.filas){
        f = m2.filas;
        c = m1.columnas;

        Matriz2D obj(f,c);

        for (int i = 0; i < m1.filas; ++i) {
            for (int j = 0; j < m2.columnas; ++j) {
                for (int k = 0; k < m1.columnas; ++k) {
                    obj.ptr[i][j] = obj.ptr[i][j] + m1.ptr[i][j] * m2.ptr[i][j];
                }
            }
        }
        return obj;
    } else{
        cout<<"No fue posible multiplicar ambas matrices";
    }

}

Matriz2D operator+(const Matriz2D& m, float n){
    // Sobrecarga del operador +
    int f, c;
    f = m.filas;
    c = m.columnas;
    Matriz2D obj(f,c);

    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            obj.ptr[i][j] = obj.ptr[i][j] + n;
        }
    }

    return obj;
}

Matriz2D operator-(const Matriz2D& m, float n){
    // Sobrecarga del operador -
    int f, c;
    f = m.filas;
    c = m.columnas;
    Matriz2D obj(f,c);

    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            obj.ptr[i][j] = obj.ptr[i][j] - n;
        }
    }

    return obj;
}

Matriz2D operator*(const Matriz2D& m, float n){
    // Sobrecarga del operador *
    int f, c;
    f = m.filas;
    c = m.columnas;
    Matriz2D obj(f,c);

    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            obj.ptr[i][j] = obj.ptr[i][j] * n;
        }
    }

    return obj;
}

Matriz2D operator/(const Matriz2D& m, float n){
    // Sobrecarga del operador /
    int f, c;
    f = m.filas;
    c = m.columnas;
    Matriz2D obj(f,c);

    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            obj.ptr[i][j] = obj.ptr[i][j] / n;
        }
    }

    return obj;
}

float Matriz2D::get(int i, int j){
    return ptr[i][j];
}

int Matriz2D::getFilas(){
    return filas;
}

int Matriz2D::getColumnas(){
    return columnas;
}
