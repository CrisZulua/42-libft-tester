#include "libft_tester.h"

int test_ft_isdigit(void)
{
	char tests[] = {
		'\x02',
		'a',
		'Z',
		'7',
		'+',
		'\0',
		'\t',
		'\n',
		56};

	int num_tests = sizeof(tests);
	int passed = 0;
	int res_sys;
	int res_ft;

	for (int i = 0; i < num_tests; i++)
	{
		res_sys = isdigit(tests[i]);
		res_ft = ft_isdigit(tests[i]);

		if ((res_sys > 0 && res_ft > 0) || (!res_ft && !res_sys))
			passed++;
		else
			printf("\t❌   FAILED TEST %-2d ❌\tExpected : %-3d , Got : %-3d\n", i, res_sys, res_ft);
	}

	return (passed == num_tests);
}
