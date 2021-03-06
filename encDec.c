#include <stdio.h>
#include <stdlib.h>
#include <libio.h>

int main(int argc, char *argv[]){
	if(argc < 3){
		fprintf(stderr, "Usage: encDec -i <input file> -o <output file> -k <key file>");
		return 1;
	}
	FILE *in;
	FILE *out;
	FILE *key;
	in = fopen(argv[1], "r");
	out = fopen(argv[2], "w");
	key = fopen(argv[3], "r"); 
	if(in == NULL || out == NULL || key == NULL){
		fprintf(stderr, "One or more of your files are invalid");
		return 2;
	}
	char inTemp[1024];
	char keyTemp[2];
	fread(inTemp, 1024, 1, in);
	fread(inTemp, 2, 1, key);
	for(int i = 0; i<1024; i++){
		inTemp[i] = inTemp[i] ^ key[1];
	}
	fwrite(inTemp, 1, 1, out);
	fclose(in);
	fclose(key);
	fclode(out);
	return 0;
	
}
