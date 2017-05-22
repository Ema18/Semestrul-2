//
// Created by Ema on 4/23/2017.
//

#pragma once

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