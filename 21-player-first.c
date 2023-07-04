// makes 21. you vs the AI, you start

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>


int main(void)
{
	int number=0;
	int player=1;
	int numMoves=0;
	int newNumber;
	int validq;
	
	// now we run a turn
	while (number<21)
	{
		validq=0;
		if (player%2 == 1)
		{
			// player 1 (you)
			while (validq==0)
			{
				printf("how many moves would you like to make? ");
				scanf("%d", &numMoves);
				if ((numMoves<4) && (numMoves > 0))
				{
					validq=1;
				}
			}
		} else {
			// player 2 (cpu)
			// because we haven't updated numMoves, we have access to the player's last guess
			numMoves=4-numMoves;
			printf("the computer is playing %d\n", numMoves);
			//numMoves=2;
		}
		
		newNumber=number+numMoves;		
		if (newNumber >=21)
		{
			newNumber=21;
		}
		// print out the numbers
		while (number <newNumber)
		{
			number++;
			printf("%d\n", number);
		}
		//printf("\n");
		
		player++;
	}
	
	// at this point 21 has been hit
	if (player%2 == 1)
	{
		// player 1 (you)
		printf("you... weren't meant to see this. something's gone wrong here");
	} else {
		// player 2 (cpu)
		printf("And the computer won! lol noob the AI takeover starts now");
	}
	//printf("and that's a win for player %d! Good work whoever that is", ((player+1)%2)+1);
	
	
	return 0;
}