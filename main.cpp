#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <netinet/in.h>

int main(int argc, char* argv[]){
	FILE* f1 = fopen(argv[1], "r");

	FILE* f2 = fopen(argv[2], "r");
	if(f1 == NULL || f2 == NULL)
		return -1;

	char a[4], b[4];
	fread(a, sizeof(a), 1, f1);
	fread(b, sizeof(b), 1, f2);
	fclose(f1);
	fclose(f2);
	uint32_t res1 = (int(a[0])&0xff) << 24 | (int(a[1])&0xff) << 16 | (int(a[2])&0xff) << 8 | (int(a[3])&0xff);
	uint32_t res2 = (int(b[0])&0xff) << 24 | (int(b[1])&0xff) << 16 | (int(b[2])&0xff) << 8 | (int(b[3])&0xff);
	printf("%x\n", res1);
	printf("%x\n", res2);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", res1, res1, res2, res2, res1+res2, res1+res2);
}