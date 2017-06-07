//
// Created by Ema on 4/23/2017.
//

#include "../includes/Counter.h"
#include "../includes/Movie.h"

template class Counter<Movie>;

template<class T>
int Counter<T>::alive = 0;

template<class T>
int Counter<T>::total = 0;