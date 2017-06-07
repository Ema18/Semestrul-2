#pragma once
#include <assert.h>
#include "controller.h"
#include "FileRepository.h"
#include <QtWidgets\qpushbutton.h>

class Test
{
public:

	static void test_count_hours()
	{
		FileRepository repo("data.txt");
		Controller contro{ repo };

		assert(contro.count_hours("sunny") == 2);
		assert(contro.count_hours("rainy") == 7);
		assert(contro.count_hours("cloudy") == 3);
		assert(contro.count_hours("foggy") == 3);

	}

	static void run_all_tests()
	{
		test_count_hours();
	}
};