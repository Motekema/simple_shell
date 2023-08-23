#include "Our_Shell.h"
#include <stdio.h>
#include <stdlib.h>

char *get_input()
{
    char *input = malloc(MAX_INPUT_SIZE);
    if (!input)
    {
        perror("Memory allocation fail");
        exit(EXIT_FAILURE);
    }
    printf(":) ");
    if (!fgets(input, MAX_INPUT_SIZE, stdin))
    {
        if (feof(stdin))
	{
            printf("\nExiting the shell...\n");
            free(input);
            exit(EXIT_SUCCESS);
        }
        perror("Input error");
        free(input);
        exit(EXIT_FAILURE);
    }
    return (input);
}

