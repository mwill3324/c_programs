//Marcus Williams
// HW4
//CSE 240



#include <stdio.h>   
#include <string.h>
#include <ctype.h>
#pragma warning(disable: 4996)
#define max 100
	typedef enum { diploma, bachelor, master, doctor} education;

	struct person {				       // a node to hold personal details
		char name[30];
		char email[30];
		int phone;
		education degree;
	};
	
	struct person directory[max];	 
	struct person temp[1];	// an array of structures, 100 entries
	int tail = 0;					      // global variable
	void flush();		      // forward declaration of functions
	void branching(char c);
	int insertion();
	int print_person(int i);
	int print_all();
	int search_person();
	int delete_person();
	char blob;


	const char* deg[] = {"diploma","bachelor","master","doctor"};
	int main() {  // print a menu for selection
		char ch = 'i';
		

		


		ungetc('\n', stdin); // inject the newline character into input buffer

		do {
			printf("Enter your selection\n");
			printf("\ti: insert a new entry\n");
			printf("\td: delete an entry\n");
			printf("\ts: search an entry\n");
			printf("\tp: print all entries\n");
			printf("\tq: quit \n"); 

			flush();	// flush the input buffer. To be discussed later
			ch = tolower(getchar());
			branching(ch);
		} while (ch != 113);

		return 0;
	}

	void flush() {	// flush the input buffer. To be discussed later
		int c;
		do {
			c = getchar();
		} while (c != '\n' && c != EOF);
	}


	void branching(char c) {    // branch to different tasks
		switch (c) {
		case 'i':
			insertion();
			break;
		case 's':
			search_person();
			break;
		case 'd':
			delete_person();
			break;
		case 'p':
			print_all();
			break;
		case 'q':
			break;
		default:
			printf("Invalid input\n");
		}
	}

	int insertion() {    // insert a new entry at the end
		int j = 0;
		int a = 0;
		if (tail == max) {
			printf("There are no more places to insert.\n");
			return -1;
		}
		else {

			printf("Enter name, phone, email, degree:\n");




			scanf("%s", directory[tail].name);
			// &directory[tail].name is an array. No "&" is needed
			scanf("%d", &directory[tail].phone, sizeof(directory[tail].phone));
			scanf("%s", directory[tail].email);
			scanf("%s", &blob); // holder word for degree

			for (int w = 0; w < 3; w++){

				if (blob == *deg[w]){ // compare degrees
					directory[tail].degree = w; // if degree is equal, it initializes here.
					
					
					if (tail != 0){ // we dont need to sort the array if there is going to be only 1 input.

						for (int a = 0; a < tail; a++){ // runs the sort all the way through until the last inputed element

							if (strcmp(directory[a].name, directory[a + 1].name) > 0){ // checks to make sure the name before the next name is in the right spot
								temp[0] = directory[a]; // temp to hold name that is in wrong place
								directory[a] = directory[a + 1]; // replacing first name with correct position next name
								directory[a + 1] = temp[0]; // replacing the name in the next position with the temp, then should check it for correct position with the next name in line. 
								a++; // next position
							}
						}
					}

				}
			}

			



		}
		//	scanf("%d");
		tail++;
		printf("The number of entries = %d\n", tail);
		return 0;



		a = 0;//<<<<<
		// RESTART THE abc order compare from the beggining of list:) 
	
		}
	

	int print_person(int i) {
		// print all information one person in the directory
		printf("\n\nname = %s\n", directory[i].name);
		printf("email = %s\n", directory[i].email);
		printf("phone = %d\n", directory[i].phone);
		printf("degree = %s\n", deg[directory[i].degree]);

			return 0;

	}
	int print_all() {
		// print all information each person in the contactbook
		int i;

		if (tail == 0) {
			printf("No entries found.");
		}
		else {
			for (i = 0; i < tail; i++) {
				print_person(i);
			}
		}

		return 0;
	}
	int search_person() {      // print phone and email via name
		char NamSer[30];
		int  L;
		char *p = NamSer;
		printf("Please enter the name to be searched for:\n");

		scanf("%s", NamSer);     // is an array, no & needed
		L = 0;
		
		
		while (L<tail){ 
			// comparing the name with the searchvvv while iterating through all of the names!!!!!!
			if (strcmp(p, ((directory + L)->name)) == 0) {
				print_person(L);
				return L; // returns name
			}
			L++;
		}
		printf("The name does not exist.\n");
		return -1;
	}
	int delete_person() {
		int i, k;
		k = search_person();
		if (k == -1) {
			printf("The name does not exist.\n"); return -1;
		}
		else {
			for (i = k; i<tail; i++) {
				strcpy(directory[i].name, directory[i + 1].name);
				directory[i].phone = directory[i + 1].phone;
				strcpy(directory[i].email, directory[i + 1].email);
				printf("The index deleted is: %d\n", k);
			}
			tail--;
			return k;
		}
	}
