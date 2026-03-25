#include "libft_tester.h"

typedef struct s_test
{
	char *s;
	char c;
	char **res_expected;
	size_t res_expected_size;
} t_test;

static void free_split(char **strs)
{
	for (size_t i = 0; strs[i]; i++)
	{
		free(strs[i]);
	}
	free(strs);
}

static int wordscmp(char **res, char **exp, size_t exp_size, int test)
{
	size_t res_size = 1;

	for (size_t i = 0; res[i]; i++)
	{
		res_size++;
	}

	if (res_size != exp_size)
	{
		printf("\t❌   FAILED TEST %-2d ❌\tWords Expected : %-3lu , Words Gotten : %-3lu\n", test, exp_size, res_size);
		return (0);
	}

	for (size_t i = 0; i < (exp_size - 1); i++)
	{
		if (strcmp(res[i], exp[i]))
		{
			printf("\t❌   FAILED TEST %-2d ❌\tExpected : %-15s , Got : %-15s\n", test, exp[i], res[i]);
			return (0);
		}
	}
	return (1);
}

int test_ft_split(void)
{
	t_test tests[] = {
		{"Hello World!", ' ', (char *[]){"Hello", "World!", NULL}, 3},
		{"He llo Wor ld!", ' ', (char *[]){"He", "llo", "Wor", "ld!", NULL}, 5},
		{"Hello-World!", '-', (char *[]){"Hello", "World!", NULL}, 3},
		{" Hello World! ", ' ', (char *[]){"Hello", "World!", NULL}, 3},
		{"abcdebfgh", 'b', (char *[]){"a", "cde", "fgh", NULL}, 4},
		{"       ", ' ', (char *[]){NULL}, 1},
		{"aaaa", 'a', (char *[]){NULL}, 1},
		{"aabaa", 'a', (char *[]){"b", NULL}, 2},
	};

	int num_tests = sizeof(tests) / sizeof(t_test);
	int passed = 0;
	char **res_ft;

	for (int i = 0; i < num_tests; i++)
	{

		res_ft = ft_split(tests[i].s, tests[i].c);

		if (!res_ft)
		{
			if (!tests[i].res_expected)
				passed++;
			else
				printf("\t❌   FAILED TEST %-2d ❌\tExpected : %-15p , Got : %-15s\n", i, tests[i].res_expected, "NULL");
		}
		else
		{
			if (!tests[i].res_expected)
				printf("\t❌   FAILED TEST %-2d ❌\tExpected : %-15s , Got : %-15p\n", i, "NULL", res_ft);
			else if (wordscmp(res_ft, tests[i].res_expected, tests[i].res_expected_size, i))
				passed++;
			free_split(res_ft);
		}
	}

	return (passed == num_tests);
}
