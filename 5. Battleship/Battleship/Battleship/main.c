#define _CRT_SECURE_NO_WARNINGS

#include "battleship.h"

int main (void)
{

	Stats players[2] = {{0, 0, 0, 0.0}, {0, 0, 0, 0.0}};

	Cell playerOneGameBoard[ROWS][COLS];      
	Cell playerTwoGameBoard[ROWS][COLS];  

	Coordinate target;          
	Coordinate targetTemp;     
	Coordinate targetOrigin;      
	Coordinate targetAI;      

	WaterCraft ship[NUM_OF_SHIPS] = {{'c', 5, "Carrier"}, 
	                                 {'b', 4, "Battleship"}, 
	                                 {'r', 3, "Cruiser"}, 
	                                 {'s', 3, "Submarine"}, 
	                                 {'d', 2, "Destroyer"}};

	Boolean    huntMode       = TRUE;                
	Boolean    targetMode     = FALSE;                  
	Boolean    flipper        = TRUE;	                 
	Boolean    cardinals[4]   = {TRUE, TRUE, TRUE, TRUE}; 
	Boolean    hasAShipSunked = FALSE;              


	short sunkShip[2][NUM_OF_SHIPS] = {{5, 4, 3, 3, 2},    
	                                   {5, 4, 3, 3, 2}};

	short player  = 0;	       
	short shot    = 0;       
	int   option  = 0;         
	int   north   = 0,        
		  south   = 0,      
		  east    = 0,         
		  west    = 0;       
	int   i       = 0,             
		  counter = 1;       

	char  shipSymbol = '\0';    
	
	FILE *outStream = NULL;  


	outStream = fopen (LOG_FILE_NAME, "w");

	srand ((unsigned int) time (NULL));


	welcomeScreen ();
	getchar();
	system ("cls");


	initializeGameBoard (playerOneGameBoard);
	initializeGameBoard (playerTwoGameBoard);


	printf ("> Please select from the following menu:\n");
	printf ("> [1] Manually\n");
	printf ("> [2] Randomly\n");
	printf ("> Enter Option: ");
	scanf ("%d", &option);
	
	switch (option) {
		case 1: manuallyPlaceShipsOnGameBoard (playerOneGameBoard, ship);
	            break;
		case 2: randomlyPlaceShipsOnGameBoard (playerOneGameBoard, ship);
				break;
	}


	randomlyPlaceShipsOnGameBoard (playerTwoGameBoard, ship);
	printf ("> Player 2 (Computer's) board has been generated.\n");


	player = getRandomNumber (0, 1);
	printf ("> Player %d has been randomly selected to go first.\n", player + 1);
	getchar();
	system ("cls");


	while (TRUE) {


		fprintf (outStream, "Player %d's turn.\n", player + 1);


		switch (player) {

			case PLAYER_ONE: 

				printf ("> Player 2's Board:\n");
				printGameBoard (playerTwoGameBoard, FALSE);
				printf ("> PLAYER 1'S TURN\n");

	
				do {
					target = getTarget (); 
					shot = checkShot (playerTwoGameBoard, target);
					
	
					if (shot == -1) 
						printf ("> Try inputting another target!\n");

				} while (shot == -1);


				shipSymbol = playerTwoGameBoard[target.row][target.column].symbol;
				break;

			case PLAYER_TWO: 

		
				printf ("> Player 1's Board:\n");
				printGameBoard (playerOneGameBoard, TRUE);
				printf ("> COMPUTER'S TURN\n");

		
				if (hasAShipSunked) {
					hasAShipSunked = FALSE;
					targetMode = FALSE;
					huntMode = TRUE;
				}
				
		
				if (targetMode) {
				
					target = targetAI;

					do {
						if (cardinals[NORTH]) {   
							target.row = north;
						} else if (cardinals[SOUTH]) { 
							target.row = south;
						} else if (cardinals[WEST]) { 
							target.column = west;
						} else if (cardinals[EAST]) { 
							target.column = east;
						} else if (!cardinals[NORTH] && !cardinals[SOUTH] && 
						           !cardinals[WEST]  && !cardinals[EAST]  && 
								   !hasAShipSunked) {
					
							
						
							target = targetOrigin;
							targetTemp = target;

					
							north = target.row - counter;
							targetTemp.row = north;

						
							if (checkShot (playerOneGameBoard, targetTemp) != -1 && north >= 0) {
								cardinals[NORTH] = TRUE;
							}

							targetTemp = target;
							south = target.row + counter;
							targetTemp.row = south;

				
							if (checkShot (playerOneGameBoard, targetTemp) != -1 && south <= 9) {
								cardinals[SOUTH] = TRUE;
							}

							targetTemp = target;
							west = target.column - counter;
							targetTemp.column = west;

					
							if (checkShot (playerOneGameBoard, targetTemp) != -1 && west >= 0) {
								cardinals[WEST] = TRUE;
							}

							targetTemp = target;
							east = target.column + counter;
							targetTemp.column = east;

				
							if (checkShot (playerOneGameBoard, targetTemp) != -1 && east <= 9) {
								cardinals[EAST] = TRUE;
							}

				
							counter++;

						} else  {
				
							targetMode = FALSE;
							huntMode = TRUE;
							break;
						}
						
			
						shot = checkShot (playerOneGameBoard, target);

					} while (shot == -1 && targetMode == TRUE);

			
					if (shot == 1 && huntMode == FALSE) {
						for (i = 0; i < 4; i++) {
							if (flipper == FALSE)
								cardinals[i] = FALSE;

							if (cardinals[i] == flipper) 
								flipper = FALSE;
						}
					} else {
						for (i = 0; i < 4; i++) {
							if (flipper == TRUE && cardinals[i] != FALSE) {
								cardinals[i] = FALSE;
								break;
							}
						}
					}

			
					flipper = TRUE;
				}

		
				if (huntMode) {	

			
					counter = 1;
					flipper = TRUE;
					for (i = 0; i < 4; i++)
						cardinals[i] = TRUE;

		
					do {
						target.row = getRandomNumber (0, 9);
						target.column = getRandomNumber (0, 9);

			
						shot = checkShot (playerOneGameBoard, target);
					} while (shot == -1);

		
					if (shot == 1) targetOrigin = target;
				}

		
				if (shot == 1) {

		
					if (!cardinals[NORTH] && !cardinals[SOUTH] && 
						!cardinals[WEST]  && !cardinals[EAST]  && 
						!hasAShipSunked) { target = targetOrigin; }

		
					huntMode = FALSE;
					targetMode = TRUE;
					targetAI = target;

		
					if (cardinals[NORTH] == TRUE) {  /* NORTH */
						north = (targetAI.row - 1);
						checkBoundsOfCardinal (cardinals, north, NORTH);
						targetTemp = target;
						targetTemp.row = north;
						if (checkShot (playerOneGameBoard, targetTemp) == -1)
							cardinals[NORTH] = FALSE;
					}
					
					if (cardinals[SOUTH] == TRUE) {  /* SOUTH */
						south = targetAI.row + 1;
						checkBoundsOfCardinal (cardinals, south, SOUTH);
						targetTemp = target;
						targetTemp.row = south;
						if (checkShot (playerOneGameBoard, targetTemp) == -1)
							cardinals[SOUTH] = FALSE;
					}

					if (cardinals[WEST] == TRUE) {   /* WEST */
						west  = targetAI.column - 1;
						checkBoundsOfCardinal (cardinals, west, WEST);
						targetTemp = target;
						targetTemp.column = west;
						if (checkShot (playerOneGameBoard, targetTemp) == -1)
							cardinals[WEST] = FALSE;
					}

					if (cardinals[EAST] == TRUE) {   /* EAST */
						east  = targetAI.column + 1;
						checkBoundsOfCardinal (cardinals, east, EAST);
						targetTemp = target;
						targetTemp.column = east;
						if (checkShot (playerOneGameBoard, targetTemp) == -1)
							cardinals[EAST] = FALSE;
					}
				}


				shipSymbol = playerOneGameBoard[target.row][target.column].symbol;
				break;
		}

		if (shot == 1) { 
			printf ("> %d, %d is a hit!\n", target.row, target.column);

	
			fprintf (outStream, "%d, %d is a hit!\n", target.row, target.column);

	
			players[player].numHits++;

		
			if (player == 1)  
				hasAShipSunked = checkSunkShip (sunkShip, !player, shipSymbol, outStream);
			else
				checkSunkShip (sunkShip, !player, shipSymbol, outStream);

		} else {     
			printf ("> %d, %d is a miss!\n", target.row, target.column);

		
			fprintf (outStream, "%d, %d is a miss!\n", target.row, target.column);
			players[player].numMisses++;
		}
		
		if (player == 0) 
			updateGameBoard (playerTwoGameBoard, target);
		else              
			updateGameBoard (playerOneGameBoard, target);

	
		if (isWinner (players, player)) {
			printf ("\n> Player %d wins!\n", player + 1);

	
			fprintf (outStream, "\n>>>>> Player %d wins! <<<<<\n", player + 1);
			break;
		}

		getchar();

	
		player = !player;	

		system ("cls");
	}


	players[0].totalShots = players[0].numHits + players[0].numMisses;
	players[0].hitMissRatio = ((double) players[0].numHits/(double) players[0].numMisses) * 100;
	players[1].totalShots = players[1].numHits + players[1].numMisses;
	players[1].hitMissRatio = ((double) players[1].numHits/(double) players[1].numMisses) * 100;
	fprintf (outStream, "+===================================================\n");
	fprintf (outStream, "|                    PLAYER STATS                   \n");
	fprintf (outStream, "+---------------------------------------------------\n");
	fprintf (outStream, "| PLAYER 1 : %d hits                                \n", players[0].numHits);
	fprintf (outStream, "|            %d misses                              \n", players[0].numMisses);
	fprintf (outStream, "|            %d total shots                         \n", players[0].totalShots);
	fprintf (outStream, "|            %.2lf%% hit/miss ratio                 \n", players[0].hitMissRatio);
	fprintf (outStream, "| PLAYER 2 : %d hits                                \n", players[1].numHits);
	fprintf (outStream, "|            %d misses                              \n", players[1].numMisses);
	fprintf (outStream, "|            %d total shots                         \n", players[1].totalShots);
	fprintf (outStream, "|            %.2lf%% hit/miss ratio                 \n", players[1].hitMissRatio);
	fprintf (outStream, "+===================================================");

	fclose (outStream);
	return 0;
}