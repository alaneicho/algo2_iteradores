#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>

// Completar con las funciones del enunciado

//Ej 1
template<class Contenedor>
typename Contenedor::value_type minimo(const Contenedor& c){
    typename Contenedor::const_iterator iterator = c.begin();
    typename Contenedor::value_type minimo = *iterator;
    ++iterator;
    while (iterator != c.end()){
        if (*iterator < minimo){
            minimo = *iterator;
        }
        ++iterator;
    }
    return minimo;
}

//Ej 2

template<class Contenedor>
typename Contenedor::value_type promedio(const Contenedor& c){
    typename Contenedor::const_iterator iterator = c.begin();
    typename Contenedor::value_type suma = *iterator;
    int cantidad = 1;
    ++iterator;
    while (iterator != c.end()){
        suma = suma + *iterator;
        cantidad++;
        ++iterator;
    }
    return suma/cantidad;
}

//Ej 3
// Implementar las funciones análogas a los ejercicios 1 y 2 pero esta vez recibiendo iteradores:
template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator& desde, const Iterator& hasta){
    Iterator iterator = desde;
    typename Iterator::value_type minimo = *iterator;
    ++iterator;
    while (iterator != hasta){
        if (*iterator < minimo){
            minimo = *iterator;
        }
        ++iterator;
    }
    return minimo;
};


template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator& desde, const Iterator& hasta){

    Iterator iterator = desde;
    typename Iterator::value_type suma = *iterator;
    int cantidad = 1;
    ++iterator;
    while (iterator != hasta){
        suma = suma + *iterator;
        cantidad++;
        ++iterator;
    }
    return suma/cantidad;
}



#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
