#include "funcs.h"

#include <stdio.h>
#include <stdlib.h>

void add(char *task)
{
	FILE *file = fopen("tasks.txt", "a");
	if (file == NULL) {
		printf("Error opening file!");
		exit(1);
	}

	fprintf(file, "%s\n", task);
	fclose(file);
}

void list()
{
	FILE *file = fopen("tasks.txt", "r");
	if (file == NULL) {
		printf("Error opening file!");
		exit(1);
	}

	printf("Tasks:\n");
	char buffer[100];
	while (fgets(buffer, 100, file) != NULL) {
		printf("%s", buffer);
	}

	fclose(file);
}
