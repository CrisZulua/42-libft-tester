#include "libft_tester.h"

typedef struct s_test
{
	char *path;
	char c;
} t_test;

int test_ft_putchar_fd(void)
{
	t_test tests[] = {
		{"./test1.txt", 'a'},
		{"./test1", '\t'},
		{"./test1.txt", '\n'},
		{"./test2", '1'},
		{"./test1.txt", '\x02'},
	};

	int num_tests = sizeof(tests) / sizeof(t_test);
	int passed = 0;
	char buf[1];

	for (int i = 0; i < num_tests; i++)
	{
		int fd = open(tests[i].path, O_RDWR | O_CREAT, 00700);
		ft_putchar_fd(tests[i].c, fd);
		close(fd);

		fd = open(tests[i].path, O_RDWR);
		read(fd, buf, 1);
		close(fd);

		if (buf[0] == tests[i].c)
			passed++;
		else
			printf("\t❌   FAILED TEST %-2d ❌\tExpected : %-2c , Got : %-2c\n", i, tests[i].c, buf[0]);
		rm_created_file(tests[i].path);
	}

	return (passed == num_tests);
}
