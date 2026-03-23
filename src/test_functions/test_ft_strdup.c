#include "libft_tester.h"

int test_ft_strdup(void)
{
	char *tests[] = {
		"Hello World!",
		"",
		"abc",
		"\0hidden",
		"\x01\x02\x03\x04",
		"    "};

	int num_tests = sizeof(tests) / sizeof(char *);
	int passed = 0;
	char *res_ft;
	char *res_sys;

	for (int i = 0; i < num_tests; i++)
	{
		res_sys = strdup(tests[i]);
		res_ft = ft_strdup(tests[i]);

		if (res_sys && res_ft)
		{
			if (!strcmp(res_ft, res_sys))
				passed++;
			else
				printf("\t❌   FAILED TEST %-2d ❌\tExpected : %-15s , Got : %-15s\n", i, res_sys, res_ft);
		}
		else
			printf("\t❌   FAILED TEST %-2d ❌\tExpected : %-15s , Got : %-15s\n", i, res_sys ? res_sys : "NULL", res_ft ? res_ft : "NULL");
		if (res_sys)
			free(res_sys);
		if (res_ft)
			free(res_ft);
	}

	return (passed == num_tests);
}
