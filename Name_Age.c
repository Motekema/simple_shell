#include <stdio.h>
#include <string.h>

/**
* Remove newline character
* Input Name and Age 
* Results: print Name and Age
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
