#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "my_ntohl.h"

int main(int argc, char **argv) {
	FILE *fp1, *fp2;
	uint32_t num1, num2;


	if ((fp1 = fopen(argv[1], "rb")) == NULL) {
	       printf("file open error\n");
	       return -1;
	}
	int read_size = fread(&num1, 1, 4, fp1);
	if (read_size != 4) {
		printf("file1 size smaller than 4 bytes");
		return -1;
	}
	/* my code
	fread(&num1, sizeof(uint32_t), 1, fp1);
	if (ftell(fp1) < 4) {
		printf("file1 size smaller than 4 bytes");
		return -1;
	}
	*/
	fclose(fp1);


	if ((fp2 = fopen(argv[2], "rb")) == NULL) {
		printf("file open error\n");
		return -1;
	}
	fread(&num2, sizeof(uint32_t), 1, fp2);
	if (ftell(fp2) < 4) {
		printf("file2 size samller than 4 bytes");
		return -1;
	}
	fclose(fp2);


	uint32_t a = my_ntohl(num1); //0x03e8
	uint32_t b = my_ntohl(num2); //0x01f4
	uint32_t c = a + b;
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", a, a, b, b, c, c); 
}
