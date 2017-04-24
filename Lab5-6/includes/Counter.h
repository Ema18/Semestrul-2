//
// Created by Ema on 4/23/2017.
//

#ifndef LAB5_COUNTER_H
#define LAB5_COUNTER_H

template <class T>
class Counter
{
private:
    static int total, alive;

public:
    /** Constructor to count the memory leaks */
    Counter()
    {
        total++;
        alive++;
    }

    /** Destructor */
    ~Counter() { alive--; }

    /** Gets the total leaks */
    static int getTotal() { return total; }

    /** Gets the number of alive leaks at the moment */
    static int getAlive() { return alive; }
};

#endif //LAB5_COUNTER_H
///d5c7235226
