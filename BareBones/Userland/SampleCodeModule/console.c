#include "stdio.h"
#include "programs.h"
#include "string.h"



/*
 * Reads the command sent and interprets it 
 * Returns 0 if everything went OK, 1 if the command was invalid or -1 for shut down
 */
static int inputInterpreter(char * command) {

	int result = 0;	
	if (!strsize(command)) {		
		result = 0; /* No command, just return */
	}else if (strcmp(command,"help")){
		showHelp();
		result = 0;
	}else if(strcmp(command,"piano")){
		piano();
		result = 0;
	}else if(strcmp(command,"beep")){
		beep();
		result = 0;
	}
	/*else if(strcmp(command,"stopwatch")){
		stopWatch(); // No funciona en las PCs del ITBA 
        printf("No disponible\n");
		result = 0;
	}*/
	else if(strcmp(command,"musicplayer")){
		playMusic();
		result = 0;
	} else if(strcmp(command,"echo")){
		echo();
		result = 0;
	} else if(strcmp(command,"clear")){
		clearShell();
		result = 0;
	} else if (strcmp(command,"exit")) {
		result = 1;
	}else{
		result = -1;	
	}
	
	return result;
}



void startShell(void){

	char command[128];
	int run = 1;
	clearShell();
	
	while(run){
		int result;
		printf("$>");	
		readLine(command, 256);

		result = inputInterpreter(command);

		switch (result) {
			case 1:
				run = 0;
				break;
			case -1:
				printf("'%s': Comando invalido. Pruebe 'help'\n", command);
				break;
				
		}
		
	}
}



