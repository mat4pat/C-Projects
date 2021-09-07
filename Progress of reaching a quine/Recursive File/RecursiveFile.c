#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

enum STATE_OF_SECOND_FILE {
	CLOSED, // Didn't recurse yet
	OPENED_BEFORE // Recruse now
};

int main() {
	
	FILE * file = fopen("State.txt", "r");
	int state;
	fscanf(file,"%d",&state);
	fclose(file);
	
	file = fopen("State.txt","w");
	
	if (state==OPENED_BEFORE) {
		
		state=CLOSED;
		fprintf(file, "%d", state);
		
		printf("This file has been reopened :)\n");
		printf("Press any key to closed this file");
		getch();
		
	}
	else if (state==CLOSED) {
		
		state=OPENED_BEFORE;
		fprintf(file, "%d", state);
	    system("start C:\\Users\\<your PC's name>\\Desktop\\Test\\RecursiveFile.exe");
	    //                        ^^^^^^^^^^^^^^ don't forget to specify the exact path to this soruce code file. 
	}
	fclose(file);
	
}
