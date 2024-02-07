#include "funcs.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

void delete(int taskNum)
{
	FILE *file = fopen("tasks.txt", "r");
	if (file == NULL) {
		printf("Error opening file!");
		exit(1);
	}

	FILE *tempFile = fopen("temp.txt", "w");
	if (tempFile == NULL) {
		printf("Error opening temporary file!");
		exit(1);
	}

	char buffer[100];
	int lineNum = 1;
	while (fgets(buffer, 100, file) != NULL) {
		if (lineNum != taskNum) {
			fputs(buffer, tempFile);
		}
		lineNum++;
	}

	fclose(file);
	fclose(tempFile);

	remove("tasks.txt");
	rename("temp.txt", "tasks.txt");
}

void list()
{
	FILE *file = fopen("tasks.txt", "r");
	if (file == NULL) {
		printf("Error opening file!");
		exit(1);
	}

	printf("Tasks:\n");
	int index = 1;
	char buffer[100];
	while (fgets(buffer, 100, file) != NULL) {
		printf("%d. %s", index, buffer);
		index++;
	}

	fclose(file);
}

void help()
{
	printf("Commands:\n");
	printf("Adding a task: todo add <task>\n");
	printf("Deleting a task: todo delete <task number>\n");
	printf("Displaying tasks: todo list\n");
	printf("View commands: todo help\n");
}
