#ifndef LIBFT_TESTER_H
#define LIBFT_TESTER_H

// libft.h Header Path
#define LIBFT_PATH "../../libft/libft.h"

#include LIBFT_PATH
#include <stdio.h>
#include <string.h>

// Type for pointer to function
typedef int (*fttest)(void);

// Struct that holds test functions
typedef struct s_ftlist
{
	char *name;
	fttest fct;
} t_ftlist;

extern const t_ftlist funct_list[];

int run_tests(char *ft_name);

#endif
