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
}

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

//Ej 4
// Implementar una función que dado un contenedor y un elemento del tipo guardado en el mismo, modifique el
//contenedor recibido por parámetro eliminando todas las apariciones del elemento parámetro. La función tendrá la
//siguiente aridad:

template<class Contenedor>
void filtrar(Contenedor &c, const typename Contenedor::value_type& elem){
    typename Contenedor::iterator iterator = c.begin();
    while(iterator != c.end()){
        if (*iterator == elem){
            iterator = c.erase(iterator);
        } else {
            ++iterator;
        }
    }
}

//Ej 5
//Implementar una función que decida si los elementos —dispuestos en el orden en el que los devuelve el iterador—
//están ordenados de manera estrictamente creciente.
template<class Contenedor>
bool ordenado(Contenedor &c){
    typename Contenedor::const_iterator iterator = c.begin();
    typename Contenedor::value_type este_valor = *iterator;
    ++iterator;
    while (iterator != c.end()){
        if (este_valor >= *iterator){
            return false;
        }
        este_valor = *iterator;
        ++iterator;
    }
    return true;
}

//Ej 6
// Implementar una operación que dado un contenedor y un elemento devuelva una tupla con dos nuevos contenedores
//del mismo tipo que el recibido por parámetro. El primer contenedor deberá tener todos los elementos menores al
//elemento. El segundo deberá tener los elementos mayores o iguales. La aridad será la siguiente:
template<class Contenedor>
std::pair<Contenedor, Contenedor> split(const Contenedor & c, const typename Contenedor::value_type& elem){

    std::pair<Contenedor, Contenedor> result;

    typename Contenedor::iterator it_menores = result.first.begin();
    typename Contenedor::iterator it_mayores = result.second.begin();

    typename Contenedor::const_iterator iterator = c.begin();

    while(iterator != c.end()){
        if (*iterator < elem){
            it_menores = result.first.insert(it_menores, *iterator);
            ++it_menores;
        } else {
            it_mayores = result.second.insert(it_mayores, *iterator);
            ++it_mayores;
        }
        ++iterator;
    }
    return result;
}

//Ej 7
// Implementar una función que dados tres contenedores del mismo tipo, agregue los elementos de los primeros dos
//al final del tercero. Se asume como precondición que los elementos de c1 y c2 se encuentran ordenados de manera
//creciente (no necesariamente estricta). Los elementos se deben agregar a res de manera creciente (no estricta).

template <class Contenedor>
void merge(const Contenedor& c1, const Contenedor & c2, Contenedor & res){
    typename Contenedor::const_iterator iterator1 = c1.begin();
    typename Contenedor::const_iterator iterator2 = c2.begin();
    typename Contenedor::iterator iterator_res = res.begin();

    while (iterator1 != c1.end() || iterator2 != c2.end()){
        if (iterator2 == c2.end()){
            iterator_res = res.insert(iterator_res, *iterator1);
            ++iterator1;
        } else if (iterator1 == c1.end()){
            iterator_res = res.insert(iterator_res, *iterator2);
            ++iterator2;
        }
        if(*iterator1 < *iterator2){
            iterator_res = res.insert(iterator_res, *iterator1);
            ++iterator1;
        } else {
            iterator_res = res.insert(iterator_res, *iterator2);
            ++iterator2;
        }
        //++iterator_res;
    }
}


#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
