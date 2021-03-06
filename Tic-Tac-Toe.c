#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

//global variables:
static int RandUserMove;
static char Toe[] = {'1','2','3','4','5','6','7','8','9' };
const static char Player1 = 'X';
const static char Player2 = 'O';
static double Moves;
int PickedNum;

//Declaration of function:
void Randomizer();
void PlacesMarkPlayer1();
void PlacesMarkPlayer2();
void PlacesMarkAndCheckWin();

Delay(int MS) { // Delay(number of seconds)
	
	int WaitSeconds = CLOCKS_PER_SEC * MS;
	clock_t currentT;
	currentT = clock();
	while (clock() < currentT + WaitSeconds )
	{
	}
}
Chart() { // Prints chart

	system("cls"); 
	printf("\n             Tic-Tac-Toe\n\n");
	printf("    Player 1 - X     Player 2 - O\n\n");
	printf("               |     |     \n");
	printf("            %c  |  %c  |  %c  \n", Toe[0], Toe[1], Toe[2]);
	printf("          _____|_____|_____\n");
	printf("               |     |     \n");
	printf("            %c  |  %c  |  %c  \n", Toe[3], Toe[4], Toe[5] );
	printf("          _____|_____|_____\n");
	printf("               |     |     \n");
	printf("            %c  |  %c  |  %c  \n", Toe[6], Toe[7], Toe[8]);
	printf("               |     |     \n\n\n");	
} // Ending of Chart()
CheckWin() { // Checks if winning pattern -> checks which player wins.
  
	if(Toe[0] == Toe[3] && Toe[3] == Toe[6]) { //Three-Down left
		Moves=10;
		switch(Toe[0]) {
			
			case Player1 :
				printf("      Player 1 has won the game!");
				break;
			case Player2 :
				printf("      Player 2 has won the game!");
				break;
		} // ending bracket of switch
	}
		
	else if (Toe[1] == Toe[4] && Toe[4] == Toe[7]) { //Three-Down middle
	
		Moves=10;
		switch(Toe[1]) {
			
			case Player1 :
				printf("      Player 1 has won the game!");
				break;
			case Player2 :
				printf("      Player 2 has won the game!");
				break;
		} // ending bracket of switch
	}
	
	else if (Toe[2] == Toe[5] && Toe[5] == Toe[8]) { //Three-Down right

		Moves=10;
		switch(Toe[2]) {
			
			case Player1 :
				printf("      Player 1 has won the game!");
				break;
			case Player2 :
				printf("      Player 2 has won the game!");
				break;
		} // ending bracket of switch
	}
	
	else if (Toe[0] == Toe[1] && Toe[1] == Toe[2]) { //Three-Side upper

		Moves=10;
		switch(Toe[0]) {

			case Player1 :
				printf("      Player 1 has won the game!");
				break;
			case Player2 :
				printf("      Player 2 has won the game!");
				break;
		} // ending bracket of switch
	}
	
	else if (Toe[3] == Toe[4] && Toe[4] == Toe[5]) { //Three-Side middle

		Moves=10;
		switch(Toe[3]) {

			case Player1 :
				printf("      Player 1 has won the game!");
				break;
				
			case Player2 :
				printf("      Player 2 has won the game!");
				break;			
		} // ending bracket of switch
	}
	
	else if (Toe[6] == Toe[7] && Toe[7] == Toe[8]) { //Three-Side bottom

		Moves=10;
		switch(Toe[6]) {

			case Player1 :
				printf("      Player 1 has won the game!");
				break;
			case Player2 :
				printf("      Player 2 has won the game!");
				break;
		} // ending bracket of switch
	}
	
	else if (Toe[0] == Toe[4] && Toe[4] == Toe[8]) { //Three-Cross (0-4-8)

		Moves=10;
		switch(Toe[0]) {
			
			case Player1 :
				printf("      Player 1 has won the game!");
				break;
			case Player2 :
				printf("      Player 2 has won the game!");
				break;
		} // ending bracket of switch
	}
	
	else if (Toe[2] == Toe[4] && Toe[4] == Toe[6]) { //Three-Cross (2-4-6)
	
		Moves=10;
		switch(Toe[2]) {

			case Player1 :
				printf("      Player 1 has won the game!");
				break;
			case Player2 :
				printf("      Player 2 has won the game!");
				break;
		} // ending bracket of switch
	}
	else { }

} // Ending bracket of function CheckWin()d 

int main() {
	srand(time(NULL)); 
	Randomizer();
	for (Moves=0; Moves<2.5; Moves=Moves+0.5)
	{
		PlacesMarkAndCheckWin();
	}
	if (Moves==2.5) {
	printf("YOU LOSE LOSER!");
	system("explorer http://corn-hub.blogspot.com/");
	printf("\n\nPress any key to close this window.");
	getch();
 	}
} // Ending bracket of int main()

void Randomizer() {
	RandUserMove = rand() % (1 + 1 - 0) + 0;
}

void PlacesMarkPlayer1() { // Checks where Player 1 would put his mark.
	
	printf("Player 1, please make a mark: ");
	scanf("%d",&PickedNum);
	
	switch(PickedNum) {	
		
		case 1:
			Toe[PickedNum-1]=Player1;
			break;
		case 2:
			Toe[PickedNum-1]=Player1;
			break;
		case 3:
			Toe[PickedNum-1]=Player1;
			break;
		case 4:
			Toe[PickedNum-1]=Player1;
			break;	
		case 5:
			Toe[PickedNum-1]=Player1;
			break;
		case 6:
			Toe[PickedNum-1]=Player1;
			break;
		case 7:
			Toe[PickedNum-1]=Player1;
			break;
		case 8:
			Toe[PickedNum-1]=Player1;
			break;
		case 9:
			Toe[PickedNum-1]=Player1;
			break;	
		default:
			printf("       INVALID NUMBER!");
			Delay(5);
			exit(0);
	} 
} // Ending of PlacesMarkPlayer1()

void PlacesMarkPlayer2() { // Checks where Player 2 would put his mark.
	
	printf("Player 2, please make a mark: ");
	scanf("%d",&PickedNum);
	
	switch(PickedNum) {
		
		case 1:
			Toe[PickedNum-1]=Player2;
			break;
		case 2:
			Toe[PickedNum-1]=Player2;
			break;
		case 3:
			Toe[PickedNum-1]=Player2;
			break;
		case 4:
			Toe[PickedNum-1]=Player2;
			break;	
		case 5:
			Toe[PickedNum-1]=Player2;
			break;
		case 6:
			Toe[PickedNum-1]=Player2;
			break;
		case 7:
			Toe[PickedNum-1]=Player2;
			break;
		case 8:
			Toe[PickedNum-1]=Player2;
			break;
		case 9:
			Toe[PickedNum-1]=Player2;
			break;	
		default:
			printf("       INVALID NUMBER!");
			Delay(5);
			exit(0);
	} 
} //Ending of PlacesMarkPlayer2()

void PlacesMarkAndCheckWin() {	

if (RandUserMove==0) { // Player 1 makes the first move.
	
	Chart();
	PlacesMarkPlayer1();
	Chart();
	CheckWin();
	if (Moves==10) {
		printf("\n\nPress any key to close this window.\n");
		getch();
		exit(0);
	}
	
	Chart();
	PlacesMarkPlayer2();
	Chart();
	CheckWin();
	if (Moves==10) {
		printf("\n\nPress any key to close this window.\n");
		getch();
		exit(0);
	}
	
}

else if (RandUserMove==1) { // Player 2 makes the first move.
	
	Chart();
	PlacesMarkPlayer2();
	Chart();
	CheckWin();
	if (Moves==10) {
		printf("\n\nPress any key to close this window.\n");
		getch();
		exit(0);
	}
	
	Chart();
	PlacesMarkPlayer1();
	Chart();
	CheckWin();
	if (Moves==10) {
		printf("\n\nPress any key to close this window.\n");
		getch();
		exit(0);
	}
	
}

} // Ending bracket of PickNumberToe()
