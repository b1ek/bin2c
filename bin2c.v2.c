#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "v2.h"

int main(int argc, char** argv) {
	if (argc < 1)
		return 0;

	int i;
	int ssz = 0;
	for (i=1; i<argc; i++) {
		ssz += strlen(argv[i]);
		if (argc > i+1)
			ssz++;
	}
	char *cmds;
	cmds = malloc(ssz);
	cmds[0] = '\0';

	for (i=1; i<argc; i++) {
		strcat(cmds, argv[i]);
		if (argc > i+1)
			strcat(cmds, " ");
	}
	FILE *f = fopen(cmds, "rb");
	fseek(f, 0, SEEK_END);
	
	
	size_t sz = ftell(f);
	rewind(f);
	if (sz == 0) {
		printf("{}");
		return 0;
	}
	
	if (ferror(f)) {
		printf("Error while opening file!\n");
	}
	char *bin = malloc((sz) * sizeof(char));
	fread(bin, sz, 1, f);
	fclose(f);
	printf("char %s[%d]=\"", cmds, sz);
	for (int i = 0; i <= sz-2; i++) {
		if (bin[i] == 0) {
			printf("\\0");
		} else {
			printf("\\x%x", bin[i] & 0xff);
		}
	}
	printf("\\x%x", bin[sz-1] & 0xff);
	printf("\";");
	free(cmds);
	free(bin);
	return 0;
}