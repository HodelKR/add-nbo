#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <netinet/in.h>

int main(int argc, char* argv[]){
	FILE* f1 = fopen(argv[1], "r");

	FILE* f2 = fopen(argv[2], "r");
	if(f1 == NULL || f2 == NULL)
		return -1;

	unsigned char a[4], b[4];
	fread(a, sizeof(a), 1, f1);
	fread(b, sizeof(b), 1, f2);
	fclose(f1);
	fclose(f2);
	
	uint32_t res1 = a[0] << 24 | a[1] << 16 | a[2] << 8 | a[3];
	uint32_t res2 = b[0] << 24 | b[1] << 16 | b[2] << 8 | b[3];

	printf("%x\n", res1);
	printf("%x\n", res2);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", res1, res1, res2, res2, res1+res2, res1+res2);
}