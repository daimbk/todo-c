#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcs.h"

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Use '<todo help>' to see all commands");
		exit(1);
	}

	if (strcmp(argv[1], "add") == 0) {
		if (argc < 3) {
			printf("Not enough arguments!");
			printf("Usage: todo add <task>");
			exit(1);
		}

		int mem = 0;
		char *task = (char *)malloc(mem);

		for (int i = 2; i < argc; i++) {
			task = (char *)realloc(task, (mem + strlen(argv[i])));
			strcat(task, argv[i]);
			strcat(task, " ");
		}

		printf("Added: %s\n", task);
		add(task);
		free(task);

		exit(0);
	}

	if (strcmp(argv[1], "delete") == 0) {
		if (argc < 3 && argc != 3) {
			printf("Not enough arguments!");
			printf("Usage: todo delete <task number>");
			exit(1);
		}

		delete (atoi(argv[2]));
		exit(0);
	}

	if (strcmp(argv[1], "list") == 0) {
		if (argc != 2) {
			printf("Incorrect arguments!");
			printf("Usage: todo list");
			exit(1);
		}

		list();
		exit(0);
	}

	return 0;
}
