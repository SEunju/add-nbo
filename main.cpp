#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t my_ntohl(uint32_t a) {
	uint32_t a1 = (a & 0xFF000000) >> 24;
	uint32_t a2 = (a & 0x00FF0000) >> 8;
	uint32_t a3 = (a & 0x0000FF00) << 8;
	uint32_t a4 = (a & 0x000000FF) << 24;
	return a4 | a3 | a2 | a1;
}

int main(int argc, char **argv) {
	FILE *fp1, *fp2;
	uint32_t num1, num2;

	fp1 = fopen(argv[1], "rb");
	fread(&num1, sizeof(uint32_t), 1, fp1);
	fclose(fp1);

	fp2 = fopen(argv[2], "rb");
	fread(&num2, sizeof(uint32_t), 1, fp2);
	fclose(fp2);

	//printf("%x \n %x \n", num1, num2);
       	//num1 = e8030000, num2 = f4010000
	
	uint32_t a = my_ntohl(num1); //0x03e8
	uint32_t b = my_ntohl(num2); //0x01f4
	uint32_t c = a + b;
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", a, a, b, b, c, c); 
		

}
