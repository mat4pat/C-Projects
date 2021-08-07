#include <stdio.h>

struct Student {
int id;
int Maths;
int Science;
struct Student *next; 
}p[5];

static int count=0;
int userInput;

void insertEntry();
void deleteEntry();
void displayList();


int main() {
	printf("This is a \"sample linked list\" with student entries.\n");
	printf("You may create the maximum amount of student entries(5),\nyou can only display them if they are linked by a linked list!\n");
	
	while (1) {
		
		printf("\n     MENU: \n\n");
		printf("1. Insert Entry \n");
		printf("2. Delete Entry \n");
		printf("3. Display List \n");
		printf("4. Exit\n");
		printf("Pick your choice: ");	
		scanf("%d", &userInput);
		printf("\n"); // New line for aesthetics
		/* Checks which option we have chosen with an addition of conditions */
		if (userInput==1 && count <5) {	
			insertEntry();
		}
		else if (userInput==1 && count>=5) {
			printf("All entry slots have been taken already!\n");
		}
		
		else if (userInput==2 && count>=1) {
			deleteEntry();
		}
		else if (userInput==2 && count<1) {
			printf("No entries to delete!\n");
		}
	
		else if (userInput==3 && count >=1 && p[0].id==NULL) {
			printf("There are existing entries, however, entry number one isn't linked to any entries!\n");
		}
		else if (userInput==3 && count >=1) {
			displayList();
		}
		else if (userInput==3 && count <1) {
			printf("No entries to display!\n");
		}
		
		else if (userInput==4) {
			break;
		}
		
		else {
			printf("This is an invalid option!\n");
		}
	} // Ending bracket of while(1)	
} // Ending bracket of int main()

void insertEntry() {

	for (int i=0; i<5; i++) {
		if (p[i].id==NULL) {
			p[i-1].next=&p[i]; /* Links previous entry to the current entry being created */
			count++;
			printf("Insert ID of student no.%d: ",i+1);
			scanf("%d", &p[i].id);
			
			for (int i2=0; i2<5; i2++) {
				while (p[i].id==p[i2].id && i!=i2 || p[i].id<=0) {
					if (p[i].id<=0) {
						printf("ID can only be 0 and above!\n");
					}
					else if (p[i].id==p[i2].id) {
						printf("This ID has already been chosen!\n");
					}
					printf("Insert another ID for student no.%d: ",i+1);
					scanf("%d", &p[i].id);
					i2=0; 
					/* i2 is set to 0, in order to infinitly loop until finally there are no student ID duplicates */
				}
			}
			printf("Insert mathematics grade of student no.%d: ",i+1);
			scanf("%d", &p[i].Maths);
			while (p[i].Maths<0 || p[i].Maths>100) {
				printf("This mark cannot exist!\n");
				printf("Insert mathematics grade of student no.%d: ", i+1);
				scanf("%d", &p[i].Maths);
			}
			printf("Insert science grade of student no.%d: ",i+1);
			scanf("%d", &p[i].Science);
			while (p[i].Science<0 || p[i].Science>100) {
				printf("This mark cannot exist!\n");
				printf("Insert science grade of student no.%d: ", i+1);
				scanf("%d", &p[i].Science);
			}
			break;
		}
	}
} // Ending bracket of insertEntry()

void deleteEntry() {
	int notExist=0;
	printf("Enter the ID of the student: ");
	scanf("%d", &userInput);
	
	for (int i=0; i<5; i++) {
		while (userInput<=0) {
			printf("\nPlease choose an ID that is only 0 and above: ");
			scanf("%d", &userInput);
		}
		if (p[i].id!=userInput) {
			notExist++;
			if (notExist==5) {
			printf("\nID number \"%d\" hasn't been found!\n\n", userInput);
			}
		}
		else if (p[i].id==userInput){
			count--;
			p[i].id=NULL;
			p[i-1].next=NULL;
			/*	It is unnecessary to put the grades to NULL(0),
				because they will not be visible after deletion */
			printf("\nStudent no.%d's entry has been deleted!\n\n", i+1);
			break;
		} 
	}
} // ending bracket of deleteEntry()

void displayList() {
	/* displayList will only be called if the first student entry was created and if there was atleast one entry */
	printf("Student 1: \nID:%d \nMaths:%d \nScience:%d\n\n",p[0].id, p[0].Maths, p[0].Science);
	
	for (int i=0; i<4; i++) {
		if (p[i].next!=NULL) { /* While the current student entry is linked to the forward entry */
			printf("Student %d: \nID:%d \nMaths:%d \nScience:%d\n\n",i+2, p[i].next->id, p[i].next->Maths, p[i].next->Science);
		}
		else {
			break;
		}
	}	
} // Ending bracket of displayList()
