/**
Course: CSE240
Instructor: Dr. Chen
Assignment Name: Homework 5 Solution
Solved by: MARCUS WILLIAMS 
**/
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable: 4996)
#define MAX 100
/******************** Question 3 ************************/
#define FILE_NAME "myDatabase.txt"
/********************************************************/

// Changed: deploma to diploma.
typedef enum { diploma = 0, bachelor, master, doctor } education;
typedef enum { FALSE = 0, TRUE = 1 } boolean;

// A struct to hold attributes of a person
struct person {	 // a node to hold personal details
	char name[30];
	char email[30];
	int phone;
	education degree;
	struct person *next;
} 

*head;

/******************* Global Variable Section *******************/
struct person directory[MAX];	// an array of structures, 100 entries	           
int tail = 0;					// global variable  

/******************* Foward Declaration Section *******************/
void branching(char c);
int delete_person();
void flush();
int insertion();
boolean loadFile(char* fileName);
int print_person(int i);
int print_all();
void saveFile(char* fileName);
char *sname;
void shift_data(char* name, char* email, int phone, education educationLevel);

//// adding
char temp[3];
struct person *search(char *sname);
void deletion(char *sname);





int main()
{
	// Print a menu for selection
	char ch = 'i';

	/******************** Question 3 ************************/
	if (!loadFile(FILE_NAME))
	{
		printf("The file \"myDatabase.txt\" could not be found or loaded.\n");
	}
	/********************************************************/

	ungetc('\n', stdin);			// Inject the newline character into input buffer

	do {
		printf("Enter your selection\n");
		printf("\ti: insert a new entry\n");
		printf("\td: delete an entry\n");
		printf("\ts: search an entry\n");
		printf("\tp: print all entries\n");
		printf("\tq: quit \n");
		flush();					// Flush the input buffer. To be discussed later
		ch = tolower(getchar());	// Convert any uppercase char to lowercase.
		branching(ch);
	} while (ch != 113);			// 113 is 'q' in ASCII

	/******************** Question 3 ************************/
	saveFile(FILE_NAME);
	/********************************************************/

	return 0;
};

// Branch to different tasks: insert a person, search for a person, delete a person
// print all added persons.
void branching(char c)
{
	switch (c) {
	case 'i':
		insertion();
		break;
	case 's':
		printf("Please enter the name to be searched for:\n");
		scanf("%s", &sname);
		search(&sname);
		break;
	case 'd':
		printf("Please enter the name to be deleted:\n");
		scanf("%s", &sname);
		deletion(&sname);
		break;
	case 'p':
		print_all();
		break;
	case 'q':
		break;
	default:
		printf("Invalid input\n");
	}
};
// Delete a person after finding that person via their name.

void deletion(char *sname)
{
	struct person *b, *t;
	

	if (head == 0)  return;		// nothing to delete

	b = search(sname);		// find the position
	if (b == 0) {	// free head	  // case 1
		t = head;
		head = head->next;
		free(t); // C garbage collection
		return;
	}
	if (b->next->next == 0)	{ // case 2
		t = b->next;
		b->next = 0;
		free(t);
		return;
	}
	else {
		t = b->next;
		b->next = t->next; // case 3
		free(t);
		return;
	}

};

// Flush the input buffer. To be discussed later
void flush() // Manually flush all characters in the stdin buffer
{
	int c;
	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
};

// Inserts the person lexigraphically. Note: A < a so all capital letters will be ordered first.
	
	  /////////////////
	 //  INSERTION  //
	/////////////////
int insertion()
{
	education educationLevel = 0;
	int i = 0, phone;
	struct person *p; 
	p = (struct person *) malloc(sizeof(struct person));
	if (p == 0) {
		printf("out of memory\n");  return -1;
	}// originaly entring the info for each name.
		printf("Enter name, phone, email: \n");
		scanf("%s", p->name);	// p->name is array 
		scanf("%d", &p->phone);
		scanf("%s", p->email);
		do {// to get the degree set
			printf("Enter the degree: select 0 for diploma, select 1 for bachelor, select 2 for master, or select 3 for doctor:\n");
			scanf("%d", &p->degree);
			educationLevel = p->degree;
			if (educationLevel < diploma || educationLevel > doctor)
			{
				printf("Please enter a value from 0 to 3.\n");
			}
		}
			while (educationLevel < diploma || educationLevel > doctor);
// add to tail
		tail++;
		printf("The number of entries = %d\n", tail);
		p->next = head;// move p on to the next "link"
		head = p;
		return 0;


};
/******************** Question 2 ************************/
// Returns true if the file was successfully loaded and false if the file was not.
boolean loadFile(char* fileName)
{
	// not needed...... 
};
/********************************************************/

// Print the name, e-mail, phone, and education level of one person in the directory
int print_person(int i)
{
	printf("\n\nname = %s\n", directory[i].name);
	printf("email = %s\n", directory[i].email);
	printf("phone = %d\n", directory[i].phone);
	switch (directory[i].degree)
	{
	case diploma:
		printf("degree = diploma\n");
		break;

	case bachelor:
		printf("degree = bachelor\n");
		break;

	case master:
		printf("degree = master\n");
		break;

	case doctor:
		printf("degree = doctor\n");
		break;

	default:
		printf("System Error: degree information corruption.\n");
		break;
	}
	return 0;
}

// Print the name, e-mail, phone, and education level of each person in the directory
int print_all()
{
	struct person *p=head;
	int i;

	//Case 1: The structure is empty
	if (tail == 0)
	{
		printf("No entries found.");
	}

	// Case 2: The structure has at least one item in it
	else{
		while (p != 0) {
			printf("\n\nname = %s\n", p-> name);
			printf("email = %s\n", p->email);
			printf("phone = %d\n", p->phone);
			switch (p->degree)
			{
			case diploma:
				printf("degree = diploma\n");
				break;

			case bachelor:
				printf("degree = bachelor\n");
				break;

			case master:
				printf("degree = master\n");
				break;

			case doctor:
				printf("degree = doctor\n");
				break;

			default:
				printf("System Error: degree information corruption.\n");
				break;
			}
			p = p->next;
		}
		printf("\n");
	}

	return 0;
};

/******************** Question 1 ************************/
// Returns a enum type of true if the file saved or false if the file did not save.
void saveFile(char* fileName)
{
	FILE* file;
	int i = 0;

	file = fopen(fileName, "wb");
	if (file == NULL)
	{
		printf("Could not open file to save data.\n");
		return;
	}
	else
	{
		fwrite(&tail, sizeof(tail), 1, file);
		for (i = 0; i < tail; i++)
		{
			fwrite(directory[i].name, sizeof(directory[i].name), 1, file);
			fwrite(directory[i].email, sizeof(directory[i].email), 1, file);
			fwrite(&directory[i].phone, sizeof(directory[i].phone), 1, file);
			fwrite(&directory[i].degree, sizeof(directory[i].degree), 1, file);
		}
		fclose(file);
		return;
	}
};
/********************************************************/

//Find a person by comparing names.

struct person *search(char *sname){
	struct person *p = head, *b = 0;
	int i = 0;
	while (i != tail){
		if (strcmp(sname, p->name) == 0) { // compare the input (sname), with p->name; 
			printf(sname);
			printf("phone = %d\n", p->phone);
			printf("email = %s\n", p->email);
			switch (p->degree)
			{
			case diploma:
				printf("degree = diploma\n");
				
				break;
			case bachelor:
				printf("degree = bachelor\n");
				break;

			case master:
				printf("degree = master\n");
				break;

			case doctor:
				printf("degree = doctor\n");
				break;

			default:
				printf("System Error: degree information corruption.\n");
				break;
				return b;
			}
			i = tail; // immediately end search when it is found;
		}
		else {
			b = p; p = p->next;
			printf("The name does not exist.\n");
		}
	}
	i = 0;// reset for next search/////////////////////////////
		return 0;
	
};

void shift_data(char* name, char* email, int phone, education educationLevel)
{
	int i = 0, j = 0;

	// Case 1: Empty List
	if (tail == 0)
	{
		strcpy(directory[tail].name, name);
		strcpy(directory[tail].email, email);
		directory[tail].phone = phone;
		directory[tail].degree = educationLevel;
		return;
	}

	while (i < tail)
	{
		// Case 2: Beginning or middle of list
		if (strcmp(name, directory[i].name) < 0)
		{
			j = tail;
			while (j > i)
			{
				strcpy(directory[j].name, directory[j - 1].name);
				strcpy(directory[j].email, directory[j - 1].email);
				directory[j].phone = directory[j - 1].phone;
				directory[j].degree = directory[j - 1].degree;
				j--;
			}
			strcpy(directory[i].name, name);
			strcpy(directory[i].email, email);
			directory[i].phone = phone;
			directory[i].degree = educationLevel;
			return;
		}
		i++;
	}

	// Case 3: End of list
	strcpy(directory[tail].name, name);
	strcpy(directory[tail].email, email);
	directory[tail].phone = phone;
	directory[tail].degree = educationLevel;
};