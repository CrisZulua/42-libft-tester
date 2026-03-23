#include "libft_tester.h"

// Here I have a field called res_expected. As I have no access to
// BSD functions
typedef struct s_test
{
	char *big;
	char *little;
	char *res_expected;
	size_t len;
} t_test;

int test_ft_strnstr()
{
	const t_test tests[] = {
		{"Hello World!", "World!", "World!", 12},
		{"Hello World!", "W", "World!", 7},
		{"Hello World!", "W", NULL, 4},
		{"Hello \0World!", "W", NULL, 4},
		{"Hello \0World!", "", "Hello ", 4},
		{"", "hello", NULL, 4},
		{"42", "42 piscine", NULL, 15}};

	int num_tests = sizeof(tests) / sizeof(tests[0]);
	int passed = 0;
	char *ptr = NULL;

	for (int i = 0; i < num_tests; i++)
	{
		ptr = ft_strnstr(tests[i].big, tests[i].little, tests[i].len);
		if (ptr)
		{
			if (!tests[i].res_expected)
				printf("\t❌ FAIL TEST %-3d ❌\tExpected : %-15s , Got : %-15s\n", i, "NULL", ptr);
			else if (strcmp(tests[i].res_expected, ptr))
				printf("\t❌ FAIL TEST %-3d ❌\tExpected : %-15s , Got : %-15s\n", i, tests[i].res_expected, ptr);
			else
				passed++;
		}
		else if (tests[i].res_expected)
			printf("\t❌ FAIL TEST %-3d ❌\tExpected : %-15s , Got : %-15s\n", i, tests[i].res_expected, "NULL");
		else
			passed++;
	}

	return (passed == num_tests);
}
