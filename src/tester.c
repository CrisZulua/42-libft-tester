#include "libft_tester.h"

int main(int argc, char **argv)
{
	int passed_test = 0;

	// Check if there is no arguments
	if (argc < 2)
	{
		printf("Bad execution: usage <function|all>\n");
		return (1);
	}

	// Check if all tests are to be runned. If not run only the test
	// for the functions specified in arguments
	printf(BLUE "---------------------TESTING--------------------------\n\n" RST);
	if (!strcmp(argv[1], "all"))
	{
		for (int i = 0; funct_list[i].name != NULL; i++)
		{
			printf(BLUE "⚡ Executing '%s' test:\n" RST, funct_list[i].name);
			if (funct_list[i].fct())
			{
				printf(GREEN ITALIC "\t🟢 TEST SUCCESSFUL\n" RST);
				passed_test++;
			}
			else
				printf(RED ITALIC "\t🔴 TEST FAILED\n" RST);
		}
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			printf(BLUE "⚡ Executing '%s' test:\n" RST, argv[i]);
			if (run_test(argv[i]))
			{
				printf(GREEN ITALIC "\t🟢 TEST SUCCESSFUL\n" RST);
				passed_test++;
			}
			else
				printf(RED ITALIC "\t🔴 TEST FAILED\n" RST);
		}
	}

	printf(BLUE "\n---------------------RESULTS--------------------------\n");
	printf("Total tests passed: %d/%d.\n" RST, passed_test, strcmp(argv[1], "all") ? argc - 1 : 0);
	return (0);
}
