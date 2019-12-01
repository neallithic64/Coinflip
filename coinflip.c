#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
	if (argc == 2) {
		int coinCtr = atoi(argv[1]);
		time_t t; srand((unsigned) time(&t));
		int Hctr = 0, Tctr = 0, next = rand()%2, last, longest = 0;
		
		for (int i = 0; i < coinCtr; i++) {
			last = next;
			if (last) {
				printf("T ");
				Tctr++;
			} else {
				printf("H ");
				Hctr++;
			}
			next = rand()%2;
			if (next == last)
				longest++;
		}
		
		printf("\n\tCoin Flip Statistics:\n");
		printf("Heads: %d, Percentage: %.2lf%%\nTails: %d, Percentage: %.2lf%%\n", Hctr, (double) Hctr/coinCtr*100, Tctr, (double) Tctr/coinCtr*100);
		printf("Longest chain (buggy): %d\n", longest);
	} else {
		printf("wrong parameter count\n");
	}
	return 0;
}
