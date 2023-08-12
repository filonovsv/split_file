#define _CRT_SECURE_NO_WARNINGS
#define GB (sizeof(char) * 1024 * 1024 * 1024)
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
int main() {

	FILE* fin = fopen("C:\\Users\\filon\\tata_z\\tata_z_db\\mmusculus\\data\\mus_musculus.gvf", "r");
	if (fin == NULL) {
		printf("fin == NULL");
		return -1;
	}


	char* buffer = (char*)malloc(GB);
	if (buffer == NULL) {
		printf("buffer == NULL");
		return -1;
	}
	int i = 1;
	while (true) {
		char fout_name[1024];
		sprintf(fout_name, "C:\\Users\\filon\\tata_z\\tata_z_db\\mmusculus\\data\\%d.txt", i);
		FILE* fout = fopen(fout_name, "w");
		if (fout == NULL) {
			printf("fout == NULL");
			return -1;
		}

		int read_count = 0;
		read_count = fread(buffer, sizeof(char), GB, fin);
		fwrite(buffer, sizeof(char), read_count, fout);
		if (read_count != GB) {
			break;
		} else {
			fgets(buffer, GB, fin);
			fprintf(fout, buffer);
		}
		i++;
	}
	return 0;
}