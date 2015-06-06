#include <stdio.h>
#include <stdlib.h>

// Allocates memory for string of given size
char *createCommand(size_t size) {
	return malloc(size);
}

// Allocates memory for pointers to n strings, set to NULL
char **createCommands(int n) {
	// calloc sets each pointer to NULL
	return calloc(n, sizeof(char *));
}

char *getCommand(size_t size) {
	// Printing prompt
	printf("> ");
	char *str = createCommand(size);
	if (str != NULL) {
		fgets(str, size, stdin);
	}
	return str;
}

char **getCommands(int n, size_t size) {
	char **strs = createCommands(n);
	for (int i = 0; i < n; i++) {
		if (strs != NULL) {
			strs[i] = getCommand(size);
		}
	}
	return strs;
}

void printCommands(char **commands, int n) {
	if (commands != NULL) {
		for (int i = 0; i < n; i++) {
			if (commands[i] != NULL) {
				printf("%s", commands[i]);
			} 
		}
	}
}

void freeCommands(char **commands, int n) {
	for (int i = 0; i < n; i++) {
		free(commands[i]);
	}
	free(commands);
}

int main(int argc, char **argv) {

	if (argc != 3) {
		printf("Usage: <num_commands> <command_size>\n");
		return 0;
	}

	int n = atoi(argv[1]);
	int size = atoi(argv[2]);

	if (n < 3 || size < 50) {
		printf("At least 3 commands, 50 characters each\n");
		return 0;
	}

	char **strs = getCommands(n, size);
	printf("\n");
	printCommands(strs, n);
	freeCommands(strs, n);

	return 0;
}
