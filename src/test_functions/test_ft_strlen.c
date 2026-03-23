#include "libft_tester.h"

int test_ft_strlen()
{
	const char *tests[] = {
		"Hola",
		"",
		" ",
		"abc de",
		"1234567890",
		"!@#$%^&*()",
		"\t\n\v\f\r",
		"Lorem ipsum dolor sit amet, consectetur adipiscing elit.",
		"Line1\nLine2",
		"a",
		"   ",
		"\0hidden",
		"Prueba con\0nulo",
	};

	int num_tests = sizeof(tests) / sizeof(tests[0]);
	int passed = 0;

	for (int i = 0; i < num_tests; i++)
	{
		size_t res_sys = strlen(tests[i]);
		size_t res_ft = ft_strlen(tests[i]);

		if (res_sys == res_ft)
			passed++;
		else
			printf("\t❌   FAILED TEST %-2d ❌\tExpected : %-5lu , Got : %-5lu\n", i, res_sys, res_ft);
	}

	return (passed == num_tests);
}
