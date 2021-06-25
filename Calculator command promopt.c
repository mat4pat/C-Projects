#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <bits/stdc++.h>

static char *sNum1;
static char *sNum2;
static char UserInput[101];
static char mathAction[1];
static int Index;

void CheckInput();


int main() // command prompt & calculator
{	
	CheckInput();
}

void CheckInput()
{
	printf("Calc>");
	scanf("%s", UserInput);
	while (strcmp(UserInput, "exit") != 0 ) {	
		for(Index=0; Index<=101; Index++) {
			if(UserInput[Index] != 0||1||2||3||4||5||6||7||8||9) {
				
				switch(UserInput[Index]) {
					case '+':
						mathAction[0]=UserInput[Index];
						break;
					case '-':
						mathAction[0]=UserInput[Index];
						break;
					case '*':
						mathAction[0]=UserInput[Index];
						break;
					case '/':
						mathAction[0]=UserInput[Index];
						break;	
				}
			}
			
			else {
			}
	}
	printf("Calc>");
	sNum1 = strtok(UserInput,mathAction);
	sNum2 = strtok(NULL,"");
  
				switch (mathAction[0]) {
			case '+':
				printf("%f\n",atof(sNum1)+atof(sNum2));
				break;
			case '-':
				printf("%f\n", atof(sNum1)-atof(sNum2));
				break;
			case '*':
				printf("%f\n", atof(sNum1)*atof(sNum2));
				break;
			case '/':
				printf("%f\n", atof(sNum1)/atof(sNum2));
				break;
			}
			
		printf("Calc>");
		scanf("%s", UserInput);
	}	
	printf("calc>EXITING...\n");
}
