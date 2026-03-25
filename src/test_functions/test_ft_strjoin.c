#include "libft_tester.h"

typedef struct s_test
{
	char *s1;
	char *s2;
	char *res_expected;
} t_test;

int test_ft_strjoin(void)
{
	t_test tests[] = {
		{"Hello", "World!", "HelloWorld!"},
		{"Hello", "", "Hello"},
		{"", "World!", "World!"},
		{"", "", ""},
		{"+", "-", "+-"},
		{"\t\r\f\n", "-", "\t\r\f\n-"},
		{"1", "\x02\x03\x04\x05", "1\x02\x03\x04\x05"},
	};

	int num_tests = sizeof(tests) / sizeof(t_test);
	int passed = 0;
	char *res_ft;

	for (int i = 0; i < num_tests; i++)
	{
		res_ft = ft_strjoin(tests[i].s1, tests[i].s2);

		if (!res_ft)
		{
			if (!tests[i].res_expected)
				passed++;
			else
				printf("\t❌   FAILED TEST %-2d ❌\tExpected : %-15s , Got : %-15s\n", i, tests[i].res_expected, "NULL");
		}
		else
		{
			if (!tests[i].res_expected)
				printf("\t❌   FAILED TEST %-2d ❌\tExpected : %-15s , Got : %-15s\n", i, "NULL", res_ft);
			else if (strcmp(res_ft, tests[i].res_expected))
				printf("\t❌   FAILED TEST %-2d ❌\tExpected : %-15s , Got : %-15s\n", i, tests[i].res_expected, res_ft);
			else
				passed++;
			free(res_ft);
		}
	}

	return (passed == num_tests);
}
