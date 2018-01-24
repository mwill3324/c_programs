//Marcus Williams
//Cse 240
// hw1q3

#include <stdio.h>
#pragma warning(disable : 4996) 
// Im not completley sure about this^^
// We were told it had to do with helping keep the console open or something.
	

termination(int n) {  //
		int Cnt = 0;//<<<this is the count obvi
		int a;
		if (n % 2 == 0) a = 1;
		else a =0;
		while (n!=1) { //what up, you know dat the while loop
			if (n % 2 == 0)
				n = n / 2;
			else n = 3 * n + 1;
		Cnt++;
		}
		printf("%d\n", a);
		printf("# of iterations: %d\n", Cnt);
	}
	int main(){
		int n;
		 printf("input an integer for n: ");
		scanf("%d", &n);
		termination(n);
		return 0;
	}