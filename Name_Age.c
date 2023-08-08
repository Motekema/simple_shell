#include <stdio.h>
#include <string.h>

/**
 * main - Entry point of the program
 *
 * Description:
 * This program prompts the user to enter their name and age, then displays
 * the entered values. It uses the fgets function to read input and removes
 * the newline character to ensure correct formatting.
 *
 * Return: 0 (Success)
 */

int main(void)
{
char name[100];
char age[10];

printf("What's your name: ");
fgets(name, sizeof(name), stdin);
name[strcspn(name, "\n")] = '\0';

printf("What's your age: ");
fgets(age, sizeof(age), stdin);
age[strcspn(age, "\n")] = '\0';

printf("Name: %s, Age: %s\n", name, age);

return (0);
}
