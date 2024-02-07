#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcs.h"

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Incorrect command.\nUse '<todo help>' to see all commands");
		exit(1);
	}

	if (strcmp(argv[1], "add") == 0) {
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
		delete (atoi(argv[2]));
	}

	if (strcmp(argv[1], "list") == 0) {
		list();
		exit(0);
	}

	return 0;
}
