#include "libft_tester.h"

int test_ft_atoi(void)
{
	char *tests[] = {
		"",
		"    1234",
		"  \t42",
		"  \t-42",
		"  \t---42",
		"  \0---42",
		"  \a42",
		" + 42",
		"42ab42",
		"2147483647",
		"-2147483648",
		"9999999999999"};

	int num_tests = sizeof(tests) / sizeof(char *);
	int passed = 0;
	int res_sys;
	int res_ft;

	for (int i = 0; i < num_tests; i++)
	{
		res_sys = atoi(tests[i]);
		res_ft = ft_atoi(tests[i]);

		if (res_sys == res_ft)
			passed++;
		else
			printf("\t❌   FAILED TEST %-2d ❌\tExpected : %-11d , Got : %-11d\n", i, res_sys, res_ft);
	}

	return (passed == num_tests);
}
