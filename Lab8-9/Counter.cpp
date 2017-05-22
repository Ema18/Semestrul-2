//
// Created by Ema on 4/23/2017.
//

#include "Counter.h"
#include "Movie.h"

template class Counter<Movie>;

template<class T>
int Counter<T>::alive = 0;

template<class T>
int Counter<T>::total = 0;