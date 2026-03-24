#include "libft_tester.h"

int test_ft_toupper(void)
{
	int tests[] = {
		'\x02',
		'a',
		'Z',
		'7',
		'+',
		'\0',
		'\t',
		'\n',
		56};

	int num_tests = sizeof(tests) / sizeof(int);
	int passed = 0;
	int res_sys;
	int res_ft;

	for (int i = 0; i < num_tests; i++)
	{
		res_sys = toupper(tests[i]);
		res_ft = ft_toupper(tests[i]);

		if (res_ft == res_sys)
			passed++;
		else
			printf("\t❌   FAILED TEST %-2d ❌\tExpected : %-3d , Got : %-3d\n", i, res_sys, res_ft);
	}

	return (passed == num_tests);
}
