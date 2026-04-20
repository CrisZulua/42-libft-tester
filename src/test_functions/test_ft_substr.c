#include "libft_tester.h"

typedef struct s_test
{
	char *s;
	unsigned int start;
	size_t len;
	char *res_expected;
} t_test;

int test_ft_substr(void)
{
	t_test tests[] = {
		{"Hello World!", 0, 12, "Hello World!"},
		{"Hello World!", 0, 1, "H"},
		{"Hello World!", 11, 1, "!"},
		{"Hello World!", 0, 0, ""},
		{"Hello World!", 6, 5, "World"},
		{"Hello World!", 3, 5, "lo Wo"},
		{"Hello World!", 6, 50, "World!"},
		{"Hello World!", 6, SIZE_MAX, "World!"},
		{"\tabc\r", 0, 5, "\tabc\r"},
		{"\x02\x03", 1, 5, "\x03"},
	};

	int num_tests = sizeof(tests) / sizeof(t_test);
	int passed = 0;
	char *res_ft;

	for (int i = 0; i < num_tests; i++)
	{
		res_ft = ft_substr(tests[i].s, tests[i].start, tests[i].len);

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
