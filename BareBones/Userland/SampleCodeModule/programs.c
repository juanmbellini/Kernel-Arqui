#include "music.h"
#include "time.h"
#include "stdio.h"
#include "string.h"

static void welcomeMessage(char * programName, char * initialMessage) {

	printf("Bienvenido a %s\n\n%s", programName, initialMessage);
}

static void printByeByeMessage() {
	printf("Hasta luego\n");
}

static tMusicNote marioMusic[] = { 
	{3619, 120}, {3619, 237}, {0, 79}, {3619, 237}, {0, 79}, {4560, 158}, {3619, 316},  {3043, 632}, {6087, 632},
	{4560, 474}, {6087, 474}, {7239, 474}, {5423, 316}, {4831, 316}, {5119, 158},  {5423, 316}, {6087, 158},	
	{3619, 316}, {3043, 158}, {2711, 316}, {3416, 158}, {3043, 316}, {3619, 316},  {4560, 158}, {4063, 158}, {4831, 474},
	{4560, 474}, {6087, 474}, {7239, 474}, {5423, 316}, {4831, 316}, {5119, 158},  {5423, 316}, {6087, 158},
	{3619, 316}, {3043, 158}, {2711, 316}, {3416, 158}, {3043, 316}, {3619, 316},  {4560, 158}, {4063, 158}, {4831, 474},
	{0 , 316},
	{3043, 120}, {3224, 158}, {3416, 158}, {3834, 316}, {3619, 316},
	{5746 , 158}, {5423, 158}, {4560, 316}, {5423, 158}, {4560, 158}, {4063, 632},
	{0 , 316},
	{3043, 120}, {3224, 158}, {3416, 158}, {3834, 316}, {3619, 316},
	{2280, 316}, {2280, 158}, {2280, 632},
	{0 , 316},
	{3043, 120}, {3224, 158}, {3416, 158}, {3834, 316}, {3619, 316},
	{5746 , 158}, {5423, 158}, {4560, 316}, {5423, 158}, {4560, 158}, {4063, 632},
	{0 , 316},
	{3834, 316}, {4063, 474}, {4560, 1264},
	{0 , 316},
	{3043, 120}, {3224, 158}, {3416, 158}, {3834, 316}, {3619, 316},
	{5746 , 158}, {5423, 158}, {4560, 316}, {5423, 158}, {4560, 158}, {4063, 632},
	{0 , 316},
	{3043, 120}, {3224, 158}, {3416, 158}, {3834, 316}, {3619, 316},
	{2280, 316}, {2280, 158}, {2280, 632},
	{0 , 316},
	{3043, 120}, {3224, 158}, {3416, 158}, {3834, 316}, {3619, 316},
	{5746 , 158}, {5423, 158}, {4560, 316}, {5423, 158}, {4560, 158}, {4063, 632},
	{0 , 316},
	{3834, 316}, {4063, 474}, {4560, 1264},

	{4560, 158}, {4560, 316}, {4560, 316}, {4560, 158}, {4063, 316}, {3619, 158},  {4560, 316}, {5423, 158}, {6087, 632},
	{4560, 158}, {4560, 316}, {4560, 316}, {4560, 158}, {4063, 316}, {3619, 316},  {0, 948},
	{4560, 79}, {4560, 316}, {4560, 316}, {4560, 158}, {4063, 316}, {3619, 158},  {4560, 316}, {5423, 158}, {6087, 632},
	{3619, 158}, {3619, 237}, {0, 79}, {3619, 237}, {0, 79}, {4560, 158}, {3619, 316},  {3043, 632}, {6087, 632},
	
	{4560, 474}, {6087, 474}, {7239, 474}, {5423, 316}, {4831, 316}, {5119, 158},  {5423, 316}, {6087, 158},	
	{3619, 316}, {3043, 158}, {2711, 316}, {3416, 158}, {3043, 316}, {3619, 316},  {4560, 158}, {4063, 158}, {4831, 474},
	{4560, 474}, {6087, 474}, {7239, 474}, {5423, 316}, {4831, 316}, {5119, 158},  {5423, 316}, {6087, 158},
	{3619, 316}, {3043, 158}, {2711, 316}, {3416, 158}, {3043, 316}, {3619, 316},  {4560, 158}, {4063, 158}, {4831, 474},

	{3619, 158}, {4560, 316}, {6087, 474}, {5746, 316}, {5423, 158}, {3416, 316},  {3416, 158}, {5423, 632},
	{4831, 158}, {2711, 316}, {2711, 158}, {2711, 316}, {3043, 158}, {3416, 316},  {3619, 158}, {4560, 316}, {5423, 158}, {6087, 632},
	{3619, 158}, {4560, 316}, {6087, 474}, {5746, 316}, {5423, 158}, {3416, 316},  {3416, 158}, {5423, 632},
	{4831, 158}, {3416, 316}, {3416, 158}, {3416, 316}, {3619, 158}, {4063, 316},  {4560, 1264},
	{3619, 158}, {4560, 316}, {6087, 474}, {5746, 316}, {5423, 158}, {3416, 316},  {3416, 158}, {5423, 632},
	{4831, 158}, {2711, 316}, {2711, 158}, {2711, 316}, {3043, 158}, {3416, 316},  {3619, 158}, {4560, 316}, {5423, 158}, {6087, 632},
	{3619, 158}, {4560, 316}, {6087, 474}, {5746, 316}, {5423, 158}, {3416, 316},  {3416, 158}, {5423, 632},
	{4831, 158}, {3416, 316}, {3416, 158}, {3416, 316}, {3619, 158}, {4063, 316},  {4560, 1264},

	{4560, 158}, {4560, 316}, {4560, 316}, {4560, 158}, {4063, 316}, {3619, 158},  {4560, 316}, {5423, 158}, {6087, 632},
	{4560, 158}, {4560, 316}, {4560, 316}, {4560, 158}, {4063, 316}, {3619, 316},  {0, 948},
	{4560, 79}, {4560, 316}, {4560, 316}, {4560, 158}, {4063, 316}, {3619, 158},  {4560, 316}, {5423, 158}, {6087, 632},
	{3619, 158}, {3619, 237}, {0, 79}, {3619, 237}, {0, 79}, {4560, 158}, {3619, 316},  {3043, 632}, {6087, 632},

	{3619, 158}, {4560, 316}, {6087, 474}, {5746, 316}, {5423, 158}, {3416, 316},  {3416, 158}, {5423, 632},
	{4831, 158}, {2711, 316}, {2711, 158}, {2711, 316}, {3043, 158}, {3416, 316},  {3619, 158}, {4560, 316}, {5423, 158}, {6087, 632},
	{3619, 158}, {4560, 316}, {6087, 474}, {5746, 316}, {5423, 158}, {3416, 316},  {3416, 158}, {5423, 632},
	{4831, 158}, {3416, 316}, {3416, 158}, {3416, 316}, {3619, 158}, {4063, 316},  {4560, 1264},
{0,0} };

static tMusicNote tetrisMusic[256] ={ {0, 220},	
	{3619, 188}, {4831, 188}, {4560, 188}, {4063, 375}, {4560, 188}, {4831, 188}, {5423, 375},
	{5423, 188}, {4560, 188}, {3619, 375}, {4063, 188}, {4560, 188}, {4831, 375},
	{4831, 188}, {4560, 188}, {4063, 375}, {3619, 375}, {4560, 375}, {5423, 375}, {5423, 938},
	{4063, 188}, {4063, 188}, {3416, 188}, {2711, 375}, {3043, 188}, {3419, 188}, {3619, 563},
	{4560, 188}, {3619, 375}, {4063, 188}, {4560, 188}, {4831, 375},
	{4831, 188}, {4560, 188}, {4063, 375}, {3619, 375}, {4560, 375}, {5423, 375}, {5423, 750},

	{3619, 375}, {4831, 188}, {4560, 188}, {4063, 375}, {4560, 188}, {4831, 188}, {5423, 375},
	{5423, 188}, {4560, 188}, {3619, 375}, {4063, 188}, {4560, 188}, {4831, 375},
	{4831, 188}, {4560, 188}, {4063, 375}, {3619, 375}, {4560, 375}, {5423, 375}, {5423, 938},
	{4063, 188}, {4063, 188}, {3416, 188}, {2711, 375}, {3043, 188}, {3419, 188}, {3619, 563},
	{4560, 188}, {3619, 375}, {4063, 188}, {4560, 188}, {4831, 375},
	{4831, 188}, {4560, 188}, {4063, 375}, {3619, 375}, {4560, 375}, {5423, 375}, {5423, 750},
{0, 0} };

static tMusicNote birthdayMusic[256] = { {0, 220},
	{6087, 272}, {6087, 136}, {5423, 545}, {6087, 954}, {4560, 545}, {4831, 1498},
	{6087, 408}, {6087, 136}, {5423, 545}, {6087, 954}, {4063, 545}, {4560, 1498},
	{6087, 408}, {6087, 136}, {3043, 545}, {3619, 954}, {4560, 545}, {4831, 545 }, {5423, 1090},
	{3416, 408}, {3416, 136}, {3619, 545}, {4560, 954}, {4063, 545}, {4560, 1498},
	
	{6087, 408}, {6087, 136}, {5423, 545}, {6087, 954}, {4560, 545}, {4831, 1498},
	{6087, 408}, {6087, 136}, {5423, 545}, {6087, 954}, {4063, 545}, {4560, 1498},
	{6087, 408}, {6087, 136}, {3043, 545}, {3619, 954}, {4560, 545}, {4831, 545 }, {5423, 1090},
	{3416, 408}, {3416, 136}, {3619, 545}, {4560, 954}, {4063, 545}, {4560, 1498},

{0,0} };


void showHelp(void){
	clearShell();
	printf("Lista de comandos: \n\n");
	printf("help         : Muestra el manual de usuario\n");
	printf("piano        : Inicia un \"piano\" basico\n");
	printf("beep         : Hace sonar el speaker brevemente\n");
	printf("echo         : Escribe un mensaje en pantalla con eco\n");
//    printf("stopwatch    : Inicia un cronometro basico. No disponible en las PCs del ITBA\n");
	printf("musicplayer  : Reproductor de musica\n");
	printf("exit         : Apaga la PC\n"); 
	printf("\n");
	return;
}

void beep(void){
	clearShell();
	tMusicNote beep = {5423, 375};
	automaticPlay(beep);
	return;
}


void piano(void) {
	clearShell();
	welcomeMessage("piano","Puede tocar con el teclado utilizando las teclas alfabeticas.\nPara salir presione ESC o Q\n");
	pianoPlay();
	printByeByeMessage();

}

void echo(void) {
	
	int i = 0;
	char string [1024];
	tMusicNote beepNoise = {5423, 375};
	clearShell();	
	welcomeMessage("echo","Ingrese texto: ");	
	readLine(string, 1024);
	while (i++ < 4) {
		printf("%s\n", string);	
		automaticPlay(beepNoise);
		sleep(625);
	}
	printByeByeMessage();
}


void stopWatch() {
	clearShell();
	welcomeMessage("stop watch","Presione E para empezar. Para deternlo, presione cualquier tecla.\nPara salir presione Q\n");
	int counter = 0;
	char option;
	tMusicNote beepNoise = {2415, 56};
	do {
		printf("Ingrese una opcion: ");
		option = getchar();
		while (getchar() != '\n'); /* cleans buffer */
		if (option == 'e' || option == 'E') {
			printf("\n\n\n");
			do {
				printf("%d\t", counter);
				sleep(944);
				automaticPlay(beepNoise);
				counter++;
				int flag = (int)askIfThereWasInput(); 
				if (flag) {
					printf("\nEl cronometro fue detenido. Ingrese que desea hacer (E para continuar, R para resetear, o Q para salir): ");
					do {
						
						option = getchar();
						while (getchar() != '\n'); /* cleans buffer */
					
						if (option == 'r' || option == 'R') {
							counter = 0;	
							printf("El cronometro fue reseteado. Presione enter para volver a empezar\n");
							while (getchar() != '\n');
							printf("\n\n\n");
						
						} else if (option == 'E' || option == 'e') {
							printf("\nContinua...\n");
						} else if (option != 'q' && option != 'q') {
							printf("Opcion invalida. Intente nuevamente\nIngrese una opcion:");
						}
					} while ( !(option == 'E' || option == 'e' || option == 'r' || option == 'R' || option == 'q' || option == 'Q'));
				}
			} while (option != 'q' && option != 'Q');
		} else if (option != 'q' && option != 'Q') {
			printf("Opcion inválida. Intente nuevamente\n");
		}
	} while ( option != 'q' && option != 'Q');
	printByeByeMessage();
}


void playMusic(void) {
	
	char option;
	char * options ="1- Super Mario Bros. Theme\n2- Tetris Theme\n3- Happy-Birthday\n";
	tMusicNote * songs[3] = {marioMusic, tetrisMusic, birthdayMusic};
	char * songNames[3] = {"Super Mario Bros. Theme", "Tetris Theme" ,"Happy Birthday"};
	char * songName;
	clearShell();
	tMusicNote * song;	
	welcomeMessage("play music","Para salir presione Q\n");	
	do {
		
		int i = 0, interrupt = 0, run = 1;
		do {
			printf("\nSeleccione una de las siguientes opciones:\n%s\nOpcion: ", options);
			option = getchar();
			while (getchar() != '\n'); /* Cleans buffer */
			if (option > '0' && option < '4') {
				int i = ((int)option - '0') - 1;
				song = songs[i];
				songName = songNames[i];
			} else if (option =='q' || option == 'Q') {
				run = 0;
			}
		} while ( option != '\n' && option != 'C' && option != 'c' && option > '0' && option <= 3 );
		if (run) {
			printf("Reproduciendo '%s'\nPresione cualquier tecla para detener\n", songName);
		}
		while ( ((uint64_t)song[i].note + song[i].duration) && !interrupt && run){

			automaticPlay(song[i++]);
			interrupt = (int)askIfThereWasInput();
			if (interrupt) {
				char c;
				do {
					printf("Pausa\nQue desea hacer?\nPresione C para continuar, S para cambiar de cancion o Q para salir: ");
					c = getchar();
					while (getchar() != '\n'); /* Cleans buffer */
					if (c == 'c' || c == 'C') {
						interrupt = 0;
					} else if (c == 'q' || c == 'Q') {
						run = 0;
						option = 'q';
					} else if (c != 's' || c != 'S') {
						printf("Opcion invalida. Intente nuevamente");
					}
				} while ( c != '\n' && c != 'C' && c != 'c' && c != 'q' && c != 'Q' && c != 's' && c != 's');
			}
			
					
		}


	} while (option != 'Q' && option != 'q');
	printByeByeMessage();
}








