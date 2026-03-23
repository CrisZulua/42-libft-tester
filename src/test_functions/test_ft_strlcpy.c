#include "libft_tester.h"

typedef struct s_test
{
	char *src;
	size_t dest_size;
	size_t expected_len;
	char *expected_dest;
} t_test;

int test_ft_strlcpy(void)
{
	t_test tests[] = {
		{"Hello", 10, 5, "Hello"},
		{"World", 3, 5, "Wo"},
		{"42", 0, 2, ""},
		{"42", 1, 2, ""},
		{"", 5, 0, ""},
		{"A", 2, 1, "A"},
		{"Longer", 7, 6, "Longer"},
		{"Way too long", 5, 12, "Way "},
		{"\t\n", 5, 2, "\t\n"},
		{"    ", 20, 4, "    "},
		{"12345", 5, 5, "1234"},
		{"hi\0hidden", 9, 2, "hi"},
		{"Zero", 1, 4, ""},
		{"Overflow", 4, 8, "Ove"},
		{"Final", 10, 5, "Final"}};

	int num_tests = sizeof(tests) / sizeof(tests[0]);
	int passed = 0;
	int cmp;
	char *buff = (char *)calloc(50, 1);

	for (int i = 0; i < num_tests; i++)
	{
		size_t res_ft = ft_strlcpy(buff, tests[i].src, tests[i].dest_size);
		cmp = strcmp(buff, tests[i].expected_dest);

		if (res_ft == tests[i].expected_len && !cmp)
			passed++;
		else if (cmp)
			printf("\t❌ FAIL TEST %-3d ❌\tExpected : %-15s , Got : %-15s\n", i, tests[i].expected_dest, buff);
		else
			printf("\t❌ FAIL TEST %-3d ❌\tExpected : %-15lu , Got : %-15lu\n", i, tests[i].expected_len, res_ft);
	}
	free(buff);
	return (passed);
}
