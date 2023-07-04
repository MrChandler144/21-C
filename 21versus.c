// makes 21. you vs a friend

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
		while (validq==0)
		{
			printf("Player %d, how many moves would you like to make? ", (player+1)%2+1);
			scanf("%d", &numMoves);
			if ((numMoves<4) && (numMoves > 0))
			{
				validq=1;
			}
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
	printf("player %d won. Good work!", (player+1)%2+1);
	// printf("and that's a win for player %d! Good work whoever that is", ((player+1)%2)+1);
	
	
	return 0;
}