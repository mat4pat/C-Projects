#include <stdio.h>

int main() {
	FILE * file = fopen("SelfPrintingCode.c", "r");
  //                   ^^^^^^^^^^^^^^^^^^ - this file name needs to match the one of your source code, it could also be fileName.cpp etc.
	char text;
	
	do {
		text = fgetc(file);
		printf("%c",text);
	} while(text!=EOF);

	fclose(file);
}
