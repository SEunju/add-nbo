#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "my_ntohl.h"

int main(int argc, char **argv) {
	FILE *fp1, *fp2;
	uint32_t num1, num2;

	fp1 = fopen(argv[1], "rb");
	fread(&num1, sizeof(uint32_t), 1, fp1);
	fclose(fp1);

	fp2 = fopen(argv[2], "rb");
	fread(&num2, sizeof(uint32_t), 1, fp2);
	fclose(fp2);

	uint32_t a = my_ntohl(num1); //0x03e8
	uint32_t b = my_ntohl(num2); //0x01f4
	uint32_t c = a + b;
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", a, a, b, b, c, c); 
}
