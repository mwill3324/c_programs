
#include <stdlib.h>  // include srand function
#include <stdio.h>
#include <time.h>
#define Size 15
#pragma warning(disable : 4996)
//Marcus Williams
/*cse240*/
main() {
	int a[Size];
	int i;
	double b1[Size], b2[Size];
	srand((unsigned)time(NULL));  // Use current time as seed


	// creat a clock with double start and end
	clock_t strt, fin;
	double cpu_time_used; /*timeis a double*/
	fin = clock();
	strt = clock();
	cpu_time_used = ((double)(fin - strt)) / CLOCKS_PER_SEC;
	/**/
	printf("The runtime = %f \n", cpu_time_used);


	for (i = 0; i < Size; i++)
	{
		a[i] = rand() % 100;
		// initialize the array using random number between 0 and 99
		b1[i] = a[i] / 5;
		printf("a[%d] = %d\n", i, a[i]);
		printf("b1[%d] = %f\n", i, b1[i]);
		b2[i] = a[i];
		b2[i] = b2[i] / 5;
		printf("b2[%d] = %f\n", i, b2[i]);
	}
	// apply (end) timestamp
	//compute the time elapsed and display time in seconds
}