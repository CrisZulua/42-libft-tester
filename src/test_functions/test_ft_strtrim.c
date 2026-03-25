#include "libft_tester.h"

typedef struct s_test
{
	char *s;
	char *set;
	char *res_expected;
} t_test;

int test_ft_strtrim(void)
{
	t_test tests[] = {
		{"###Hello World!###", "#", "Hello World!"},
		{"###Hello World!###", "#!", "Hello World"},
		{"###Hello World!###", "#Hello!", " World"},
		{"@@@Hel@lo @ Wo@@rld!@@@", "@", "Hel@lo @ Wo@@rld!"},
		{"Hello World!\t\t\t", "\t", "Hello World!"},
		{"11234421Hello World!11432", "1234", "Hello World!"},
		{"##   # #   Hello World# # # #", " #", "Hello World"},
		{"Hello World", "/", "Hello World"},
		{"Hello World", "", "Hello World"},
		{"", "", ""},
	};

	int num_tests = sizeof(tests) / sizeof(t_test);
	int passed = 0;
	char *res_ft;

	for (int i = 0; i < num_tests; i++)
	{
		res_ft = ft_strtrim(tests[i].s, tests[i].set);

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
