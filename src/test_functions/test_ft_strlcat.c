#include "libft_tester.h"


typedef struct s_test
{
	char *src;
	char *dst_init;
	size_t size;
	size_t expected_ret;
	char *expected_dst;
} t_test;

int test_ft_strlcat(void)
{
	t_test tests[] = {
		{"world", "hello ", 15, 11, "hello world"},
		{"world", "hello ", 8, 11, "hello w"},
		{"world", "hello ", 3, 11, "hello "},
		{"world", "hello ", 0, 5, "hello "},
		{"", "hello", 10, 5, "hello"},
		{"world", "", 10, 5, "world"},
		{"", "", 5, 0, ""},
		{"!", "hi", 4, 3, "hi!"},
		{"42", "piscine", 10, 9, "piscine42"},
		{"very long", "short ", 10, 15, "short ver"},
		{"rocks", "c ", 4, 7, "c r"},
		{"finish", "test", 20, 10, "testfinish"}};

	int num_tests = sizeof(tests) / sizeof(t_test);
	int passed = 0;
	int cmp;
	char buff_ft[50];
	char buff_sys[50];

	for (int i = 0; i < num_tests; i++)
	{
		memset(buff_ft, 0, sizeof(buff_ft));
		strcpy(buff_ft, tests[i].dst_init);

		memset(buff_sys, 0, sizeof(buff_sys));
		strcpy(buff_sys, tests[i].dst_init);

		size_t res_ft = ft_strlcat(buff_ft, tests[i].src, tests[i].size);
		size_t res_sys = strlcat(buff_sys, tests[i].src, tests[i].size);
		cmp = strcmp(buff_sys, buff_ft);

		if (res_ft == res_sys && !cmp)
			passed++;
		else if (cmp)
			printf("\t❌   FAILED TEST %-2d ❌\tExpected : %-15s , Got : %-15s\n", i, buff_sys, buff_ft);
		else
			printf("\t❌   FAILED TEST %-2d ❌\tExpected : %-15lu , Got : %-15lu\n", i, res_sys, res_ft);
	}
	return (passed == num_tests);
}
