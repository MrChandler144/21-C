// makes 21. you vs the AI, the AI starts

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>


int main(void)
{
	srand ( (unsigned int)time(NULL) );
	int randomNumber;
	int number=0;
	int player=0;
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
			
			// we need to make them play optimally
			// so if the current score is divisible by 1, play randomly i guess
			// but otherwise bring it up to a multiple of four
			
			if (number%4==0)
			{
				// no perfect winning strat here
				// with a 50% chance, play a 2 or 3
				// with a 50% chance, play a 1
				randomNumber=rand()%4;
				//printf("the random number is %d\n", randomNumber);
				if (randomNumber<2)
				{
					numMoves=1;
				} else if (randomNumber<3)
				{
					numMoves=2;
				} else {
					numMoves=3;
				}
				// and don't guess over twenty that's unprofessional
				if (number==20)
				{
					numMoves=1;
				}
			} else {
				// play a move so that it becomes a multiple of 4
				numMoves=4-(number%4);
			}
			
			printf("the number is %d\n", number);
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
		printf("you won! I guess you know the strat aha");
	} else {
		// player 2 (cpu)
		printf("And the computer won! lol noob the AI takeover starts now");
	}
	//printf("and that's a win for player %d! Good work whoever that is", ((player+1)%2)+1);
	
	
	return 0;
}