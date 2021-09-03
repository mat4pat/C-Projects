#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
 *	GOALS: 
 *	1. Figure out if implmeneting enums cleans the code - enums for the mathOperator.
 *	2. I want to make sure I can sure another '-' after the any mathOperator.
 *  Example: 5+-5 = 0, but currently this throws out an error, but this is temporary.
 */

char UserInput[102];
static int index;
FILE * fTimeInfo; 

double mathFunction();
void helpFunction();
void timeFunction();
void timeListFunction();

int main() // command prompt & calculator
{	
	while (1) {
		
		printf("CMD>");
		gets(UserInput);
		
		if (strcmp(UserInput, "exit") == 0 ) {
			printf("CMD>EXITING...\n");
			exit(0);
		}
		
		else if (strcmp(UserInput, "help") == 0 ) {
			helpFunction();
		}
		
		else if (strcmp(UserInput,"time") == 0 ) {
			timeFunction();
		}
		
		else if (strcmp(UserInput,"time list") == 0 ) {
			timeListFunction();
		}
		
		else if (strcmp(UserInput,"math help") == 0 ) {
			printf("CMD>Operations avaliable: addition(+), subtraction(-), multiplication(*) and division(/)\n");
			printf("Format: number [operator] number, example: 5*5, 40/2, -1+1 etc. \n");
		}
		
		else if ( ((UserInput[0] >= '0') && (UserInput[0] <= '9')) || (UserInput[0] == '-') ) {
			printf("CMD>%.3f\n",mathFunction());
		}
		
		else {
			printf("CMD>Invalid command please try \"help\" \n");
		}
	}	// bracket of while()
} // bracket of int main()

double mathFunction() {	

	for(index=0; index<=101; index++) {
		if ( (UserInput[index]>=':' && UserInput[index]<='~') || (UserInput[index]>=' ' && UserInput[index]<=')') || UserInput[index]==',' ) {
			// This condition checks if there are any illegal characters: 'a', 'P', '(', etc.
			printf("CMD>Invalid command please try \"help\"!\n");
			main();
		}
	}
	
	char mathOperator[2] = {'o'}; //The letter is not of any actual significance - used to keep track if a math operator will be found in following for loop.
	int countOfMathOperators=0;
	
	for(index=0; index<=101; index++) {
		if( ((UserInput[index]>= '*' && UserInput[index]<='/') && (UserInput[index]!= '.' && UserInput[index]!= ',')) && index!=0 ) {
			mathOperator[0]=UserInput[index];
			countOfMathOperators++;
		}
	}
	
	if ( mathOperator[0]=='o' || countOfMathOperators>1) { 
		printf("CMD>None or too many mathametical operators try \"math help\" \n");
		main();
	}
	
	// If the code here is executed, it means mathOperator has changed. Since main wasn't executed.
	char *sNum1 = strtok(UserInput,mathOperator);
	char *sNum2 = strtok(NULL,"");

		/*     To deal with the issue of sometimes the first number not being detected as negative.
		Example: input: -1-1, output: 1-1=0, expected output: -1-1=-2.
		I check if the first number has a '-' character at the beginning, and then I just manually
		do the mathametical operation.
		This is rather unfortuante because it is inefficient but I don't have choice.		*/
	switch (mathOperator[0]) {
		case '+':
			if (UserInput[0]=='-') {
				return -fabs(atof(sNum1))+atof(sNum2);
			}
			return fabs(atof(sNum1))+atof(sNum2);
		case '-':
			if (UserInput[0]=='-') {
				return -fabs(atof(sNum1))-atof(sNum2);
			}
			return fabs(atof(sNum1))-atof(sNum2);
		case '*':
			if (UserInput[0]=='-') {
				return -fabs(atof(sNum1))*atof(sNum2);
			}
			return fabs(atof(sNum1))*atof(sNum2);
		case '/':
			if (UserInput[0]=='-') {
				return -fabs(atof(sNum1))/atof(sNum2);
			}
			return fabs(atof(sNum1))/atof(sNum2);
	}
	return 0;
}

void timeFunction() { 
	time_t currentTime;
	time(&currentTime);
	printf("CMD>%s",ctime(&currentTime));
	//write history of execution of this command in Time.txt
	fTimeInfo = fopen("Problem7/Time.txt", "a");
	fprintf(fTimeInfo,ctime(&currentTime));
	fclose(fTimeInfo);
	
}

void timeListFunction() {
	char timeListChar;
	fTimeInfo = fopen("Problem7/Time.txt","r");
	
	while (timeListChar != EOF) {
		timeListChar = fgetc(fTimeInfo);
		printf("%c",timeListChar);
	}
	
	printf("\nInformation is individual to each computer.\n");
	fclose(fTimeInfo);
}

void helpFunction() {
	printf("CMD>\n\"help\" \n\"time\" or \"time list\" \n\"exit\" \n\"math help\" ");
	printf("\n\nLast updated on 3rd of September 2021 \nCreated by mat4pat, GitHub: https://github.com/mat4pat \n\n");
}
