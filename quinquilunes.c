/*

 *** Changelog ***
 beta 3 - Función repartir para Windows y Linux
 beta 2.1.1 - corregidos 30 warnings de compilación.
 beta 2.1 - corregido segmentation fault de la muerte, un par de warnings y añadido generador de aleatoriedad real basada en hardware.
 beta 2.0.1 - corregidos 6 warnings de compilación y añadidos booleanos.
 beta 2 - Corregidos varios fallos, ordenar el codigo, intrucciones y menu.
 beta 1 - El juego es jugable.

*/

#include <stdio.h>
#include <time.h> // Para time()
#include <stdlib.h> // Para rand() y srand
#include <stdbool.h>

int main()
{

    int carta=1; //variable para repartir las 40 cartas
    int baraja [4] [10]; //Creamos array para la bajara
    int jugador1 [4] [10]; //Array mano 1
    int jugador2 [4] [10]; //array mano 2
    int fila=0;
    int columna=0; //variables para recorrer el array
    //int j1=0; //Carta jugada por jugador 1
    //int j2=0; //Carta jugada por jugador 2
    int turno=0; // Indica de quien es el turno, 0 para j1 y 1 para J2 (I miss bool)
    
    int empieza();
    int menu();
    int crearbaraja();
    int repartir();
    
    turno=empieza();
    crearbaraja (baraja, jugador1, jugador2, columna, fila, carta); //Funcion para crear baraja
    repartir(baraja, jugador1, jugador2, fila, columna); //Funcion para repartir las cartas
    
    menu(jugador1, jugador2, fila, columna, turno, baraja); //Llama al menu
    
    printf("\nCreado por RW Labs S.I. - licenced GPLv3");
    printf("\nruvelro - edkalrio - fegarur");
      getchar();//Pausa hasta pulsar enter
    getchar();//Pausa hasta pulsar enter. Se necesitan 2  

    return 0;
}

int menu(int jugador1 [4] [10], int jugador2 [4] [10], int fila, int columna, int turno, int baraja [4] [10]){
  
	int menu=0;
	
	int juego();
	int instrucciones();
	
	do{
		menu=0;

		printf("Bienvenido a Quinquiluñes beta 3\n\n");
	    printf("\n\n¿Que desea hacer?\n1 - Jugar\n2 - Jugar en modo Chuck Norris (proximamente)\n3 - Instrucciones. ¿como jugar?\n4 - Salir\n\nSeleccion: ");
		scanf("%d",&menu);
    
    switch (menu){
		
		case 1: 
			juego(jugador1, jugador2, fila, columna, turno, baraja); //Que empiece el juego
			break;
			
		case 2:
			printf("\nEstamos trabajando en dicho modo, pero aun no se encuentra disponible.");
				printf("\n\nPulsa una tecla para volver al menu");
				getchar();//Pausa hasta pulsar enter
				getchar();//Pausa hasta pulsar enter. Se necesitan 2
				//system("cls"); //Borrar pantalla en Windows
				system("clear"); //Borrar pantalla en Linux				
			break;
			
		case 3:
			instrucciones();
			printf("\n\nPulsa una tecla para volver al menu");
			getchar();//Pausa hasta pulsar enter
			getchar();//Pausa hasta pulsar enter. Se necesitan 2
			//system("cls"); //Borrar pantalla en Windows
			system("clear"); //Borrar pantalla en Linux	
			break;
			
		default: 
			break;
		
	}
	}while ((menu==2) || (menu==3));
	
return 0;
}

int instrucciones(){
	
	//system("cls"); //Borrar pantalla en Windows
	system("clear"); //Borrar pantalla en Linux
	
	printf("Bienvenido a Los Quinquiluñes. Este juego es nativo de Cobos de Cerrato, en la provincia de Palencia.\n\n");
	printf("En primer lugar, se reparten 4 cartas a cada jugador.\nEl jugador que empieza juega una carta y el rival tiene que jugar una carta del mismo palo que la jugada.\nEn caso de no tener carta dle mismo palo que la jugada, se tiene que robar del mazo hasta que toque una carta del mismo palo que la jugada, y jugar obligatoriamente dicha carta.\n\n");
	printf("El valor de las cartas viene dado por las siguientes normas:\n");
	printf("-Oros: Gana la carta de menor valor. Ej. 4 de oros vende a 7 de oros.\n");
	printf("-Copas: Gana la carta de menor valor. Ej. 5 de copas vence a 6 de copas.\n");
	printf("-Bastos: Gana la carta de mayor valor. Ej. 4 de bastos vence a 2 de bastos.\n");
	printf("-Espadas: Gana la carta de mayor valor. Ej. 3 de espadas vence a 1 de espadas.\n\n");
	printf("Gana el primer jugador que se quede sin cartas en la mano.");

return 0;    
}

int juego (int jugador1 [4] [10], int jugador2 [4] [10], int fila, int columna, int turno, int baraja [4] [10]){ 
    
	int cartaj1=0; //Si hay cartas, se sigue jugando
	int cartaj2=0; //Si hay cartas, se sigue jugando
	int baraja1=0; //Si hay cartas, se sigue jugando
	int j1=0; //Carta jugada por J1
	int j2=0; //Carta jugada por J2
	int cheto=0;
	
	int cartas();
	int seleccion();
	int cartajugadaj1();
	int cartajugadaj2();
	int cortajugadaj2();
	int n();
	int seleccion();
	int seleccionj2();
	int contraataquej2();
	int comparador();
	int robarj1();
	int antichetos();
	
//BUG aleatorio con los turnos... jodido jodido. //Revisar funcion mano, juego la mejor carta o alguna de juego de j2
//Seleccion J2 o contrataque j2 esta poniendo mas de una carta a cero //Posiblemente solucionado

	do{
		// Esta función mira que aun queden cartas en la baraja
		baraja1=0;
			for (fila=0; fila<4; fila++){
        for (columna=0; columna<10; columna++){
			if (baraja[fila][columna]!=0) {
			baraja1 = baraja1 +1;
			}
		}
	}
		// Esta función controla que aun hay cartas en la mano de jugador 1.
	cartaj1=0;
	for (fila=0; fila<4; fila++){
        for (columna=0; columna<10; columna++){
			if (jugador1[fila][columna]!=0) {
			cartaj1 = cartaj1 +1;
			}
		}
	}
	// Esta función controla que aun hay cartas en la mano de jugador 2.
	cartaj2=0;
	for (fila=0; fila<4; fila++){
        for (columna=0; columna<10; columna++){
			if (jugador2[fila][columna]!=0) {
			cartaj2 = cartaj2 +1;
			}
		}
	}
	//
	if ((cartaj1>0)&&(cartaj2>0)){
		if (turno==0){ //Juega J1
		cartas(jugador1,fila,columna);
		j1=seleccion (fila, columna, jugador1);
		cartajugadaj1(j1);
		j2=contraataquej2(baraja, jugador1, j1, fila, columna, jugador2, baraja);
		cartajugadaj2(j2);
		turno=comparador(j1, j2, turno);
		if (turno==0){
			printf("\nHas ganado la mano, te toca");
		} else if (turno==1) {
			printf("\nHas perdido la mano, turno de J2");
		}
		j1=0;
		j2=0;
		//break;
	} else if (turno==1){ //Juega J2
		j2=seleccionj2(fila, columna, jugador2);
		cartajugadaj2(j2);
		robarj1(baraja, jugador1, j2, fila, columna, jugador2);
		printf("\n¿Que carta desea jugar?");
		cartas(jugador1,fila,columna);
		j1=seleccion (fila, columna, jugador1);
		cartajugadaj1(j1);
		cheto=antichetos(j1, j2); //Para comprobar que no haces trampa... provisional
		if (cheto==1){
			printf("¿Ya estas haciendo trampas? GAME OVER");
			break;
		}
		turno=comparador(j1, j2, turno);
		if (turno==0){
			printf("\nHas ganado la mano, te toca");
		} else if (turno==1) {
			printf("\nHas perdido la mano, turno de J2");
		}
		j1=0;
		j2=0;
		//break;
	}
}

} while ((cartaj1 !=0)&&(cartaj2!=0)&&(baraja1!=0));

if (cartaj1==0){
	printf("\n\nTe has quedado sin cartas en la mano, ganas la partida");
} else if (cartaj2==0) {
	printf("\n\nJ2 se ha quedado sin cartas, pìerdes la partida");
} else if (baraja1==0) {
	printf("\n\nNo quedan cartas en la baraja, ¿Que deseas hacer?");
	//Te rindes o se rinde la maquina (hacer con case)
}

return 0;}

int empieza (){
	
	int turn=0;
	
srand(time(NULL)); //Numero aleatorio mediante reloj  
turn=(rand()%2);
	
	return turn; //Bonito juego de palabras
	
}

int crearbaraja (int baraja [4] [10], int jugador1 [4] [10], int jugador2 [4] [10], int fila, int columna, int carta) {
    
    //Creamos la baraja de 40 cartas
    for (fila=0; fila<4; fila++){
        for (columna=0; columna<10; columna++){
            baraja [fila] [columna] = carta;
            carta = carta +1;
        }
    }
    //Poner la mano del J1 a cero
    for (fila=0; fila<4; fila++){
        for (columna=0; columna<10; columna++){
            jugador1 [fila] [columna] = 0;
        }
    }
    //Poner la mano dle J2 a cero
     for (fila=0; fila<4; fila++){
        for (columna=0; columna<10; columna++){
            jugador2 [fila] [columna] = 0;
        }
    }
    
    return 0;
}

int mostrarbaraja (int baraja [4] [10], int fila, int columna/*, int carta*/){
        
	    //Mostramos la baraja
	    printf("\n");
	    for (fila=0; fila<4; fila++){
		   printf("\n");
        for (columna=0; columna<10; columna++){
            printf ("%d ", baraja [fila] [columna]);
        }
    }
    printf("\n");
    return 0;
}

//REPARTIR OPTIMO LINUX
/*
int repartir (int baraja [4] [10], int jugador1 [4] [10], int jugador2 [4] [10], int fila, int columna){
    int n=0;
    int rnd=0;

	FILE *f;

	f = fopen ("/dev/random", "r");
	fread (&rnd, 1, sizeof(int),f);
	fclose(f);
	
	srand (rnd);
    
    
    //Reparte 4 cartas a J1 y las quita de la baraja
    do{
		fila=(rand()%4);
		columna=(rand()%10);
		if (baraja [fila] [columna] > 0){
		jugador1[fila][columna]=baraja[fila][columna];
		baraja[fila][columna]=0;
		n=n+1;
		}
	}while (n<4);
		
	//Reparte 4 cartas a J2 y las quita de la baraja
    for (n=0; n<4; n++){
		fila=(rand()%4);
		columna=(rand()%10);
		if (baraja [fila] [columna] != 0){
		jugador2[fila][columna]=baraja[fila][columna];
		baraja[fila][columna]=0;
	} else n=n-1;
        }
		
		
//srand(time(NULL));
//n=(rand()%40)+1;
return 0;
}
*/

//Función repartir multiplataforma
int repartir (int baraja [4] [10], int jugador1 [4] [10], int jugador2 [4] [10], int fila, int columna){
    int n=0;
    srand(time(NULL)); //Numero aleatorio mediante reloj
    
    //Reparte 4 cartas a J1 y las quita de la baraja
    do{
		fila=(rand()%4);
		columna=(rand()%10);
		if (baraja [fila] [columna] > 0){
		jugador1[fila][columna]=baraja[fila][columna];
		baraja[fila][columna]=0;
		n=n+1;
		}
	}while (n<4);
		
	//Reparte 4 cartas a J2 y las quita de la baraja
    for (n=0; n<4; n++){
		fila=(rand()%4);
		columna=(rand()%10);
		if (baraja [fila] [columna] != 0){
		jugador2[fila][columna]=baraja[fila][columna];
		baraja[fila][columna]=0;
	} else n=n-1;
        }
		
		
//srand(time(NULL));
//n=(rand()%40)+1;
return 0;
}

int mostrarmano (int jugador1 [4] [10],int jugador2 [4] [10], int fila, int columna/*, int carta*/){
	    
	    //Mostramos la mano de J1
	for (fila=0; fila<4; fila++){
	        printf("\n");
        for (columna=0; columna<10; columna++){
            printf ("%d ", jugador1 [fila] [columna]);
        }
    }
    printf("\n");
    //Mostramos la mano de J2
    for (fila=0; fila<4; fila++){
	        printf("\n");
        for (columna=0; columna<10; columna++){
            printf ("%d ", jugador2 [fila] [columna]);
        }
    }
    return 0;
}

int cartas (int jugador1 [4] [10], int fila, int columna){
	
	printf ("\nEstas son sus cartas: ");
	
	//Mostramos la mano de J1
	    for (fila=0; fila<4; fila++){
		    for (columna=0; columna<10; columna++){
				if (jugador1 [fila] [columna] !=0){
					if ((jugador1 [fila] [columna] >0) && (jugador1 [fila] [columna] <11)){ //Son oros
					    printf ("%d oros, ", columna+1);
		            }
					if ((jugador1 [fila] [columna] >10) && (jugador1 [fila] [columna] <21)){ //Son copas
					    printf ("%d copas, ", columna+1);
				    }
					if ((jugador1 [fila] [columna] >20) && (jugador1 [fila] [columna] <31)){ //Son bastos
					    printf ("%d bastos, ", columna+1);
				    }
					if ((jugador1 [fila] [columna] >30) && (jugador1 [fila] [columna] <41)){ //Son espadas
					    printf ("%d espadas, ", columna+1);
		            }
		        }
            }
        }
return 0;	
}

int cartajugadaj1 (int j1){ 
	
				if (j1 !=0){
					if ((j1 >0) && (j1 <11)){ //Son oros
					    printf ("\nHas jugado con %d oros. ", j1);
		            } else
					if ((j1 >10) && (j1<21)){ //Son copas
					    printf ("\nHas jugado con %d copas. ", j1-10);
				    } else
					if ((j1 >20) && (j1 <31)){ //Son bastos
					    printf ("\nHas jugado con %d bastos. ", j1-20);
				    } else
					if ((j1 >30) && (j1 <41)){ //Son espadas
					    printf ("\nHas jugado con %d espadas. ", j1-30);
		            }
		        }
return 0;	
}

int cartajugadaj2 (int j2){ 
	
				if (j2 !=0){
					if ((j2 >0) && (j2 <11)){ //Son oros
					    printf ("\nJ2 ha jugado con %d oros. ", j2);
		            } else
					if ((j2 >10) && (j2<21)){ //Son copas
					    printf ("\nJ2 ha jugado con %d copas. ", j2-10);
				    } else
					if ((j2 >20) && (j2 <31)){ //Son bastos
					    printf ("\nJ2 ha jugado con %d bastos. ", j2-20);
				    } else
					if ((j2 >30) && (j2 <41)){ //Son espadas
					    printf ("\nJ2 ha jugado con %d espadas. ", j2-30);
		            }
		        }
return 0;	
}

int robar(int fila, int columna, int baraja [4] [10], int jugador1 [4] [10]){
	int n=0;
    srand(time(NULL)); //Numero aleatorio mediante reloj
    
    //Roba 1 carta
    do{
		fila=(rand()%4);
		columna=(rand()%10);
		if (baraja [fila] [columna] > 0){
    		jugador1[fila][columna]=baraja[fila][columna];
    		baraja[fila][columna]=0;
    		n=n+1;
		}
	}while (n==0);
	
return 0;
}

int robar2(int fila, int columna, int baraja [4] [10], int jugador2 [4] [10]){  //el j2 también tendrá derecho a robar, digo yo
    int n=0;
    srand(time(NULL)); //Numero aleatorio mediante reloj
    
    //Roba 1 carta
    do{
		fila=(rand()%4);
		columna=(rand()%10);
		if (baraja [fila] [columna] > 0){
    		jugador2[fila][columna]=baraja[fila][columna];
    		baraja[fila][columna]=0;
    		n=n+1;
		}
	}while (n==0);
	
return 0;
}

int seleccion(int fila, int columna, int jugador1 [4][10]){
    int n=0; //Numero de carta seleccionada
	int m=0;
	int j1=0;
	int numero=0; //Numero de cartas en mano

	printf("\n\n¿Que carta quieres jugar? (introducir número: 1, 2, 3, 4...): ");
	scanf("%d", &n);
	
	for (fila=0; fila<4; fila++){ //recorremos las filas del array de la mano
        for (columna=0; columna<10; columna++){ //recorremos las columnas del array de la mano
        if (jugador1[fila][columna]>0) {
			m=m+1;
			numero=numero+1;
            if ((jugador1[fila][columna]>0) && (m==n)){
				//si el valor es distinto de cero... (si es cero es que no hay una carta ahi...) && una variable para que se detenga cuando llegue a la carta que has seleccionado (1,2,3,4,etc)
                j1=jugador1[fila][columna]; //j1 es la carta jugada
                jugador1[fila][columna]=0;//Pone a 0 la carja jugada
                //m=m+1; //suma 1 a la variable para continuar con el bucle
			 }
			}
            
        }
    }
    
    if (n>numero){
		printf("\n\nNo hagas trampas\n");
		cartas(jugador1,fila,columna);
		seleccion(fila,columna,jugador1);
	}

	//printf("\nLa carta seleccionada es %d", j1);
	return j1; //retorna la carta jugada
}

int robarj1 (int baraja [4] [10], int jugador1 [4] [10], int j2, int fila, int columna/*, int jugador2[4][10]*/){ //Funcion para robar si no tienes el palo que juega la maquina
	
	int n4 = 0;
    int robo=0;
	
	if(j2>0 && j2<=10) {	
							                        //si te saca oros
	do{
		for (fila=0; fila<4; fila++){
			for (columna=0;columna<10;columna++){
				if (jugador1[fila][columna] !=0){
					if ((jugador1[fila][columna] >0) && (jugador1[fila][columna] <=10)){
							n4=1;												
				}
			}
		}
	 } 
		if (n4==0){
			robar(fila, columna, baraja, jugador1);
			robo=robo+1;
		} 
		}while (n4<1);
		
	
				
	 } else	if((j2>10) && (j2<=20)) {						                        //si te saca copas
	do{
		for (fila=0; fila<4; fila++){
			for (columna=0;columna<10;columna++){
				if (jugador1[fila][columna] !=0){
					if ((jugador1[fila][columna] >10) && (jugador1[fila][columna] <=20)){
							n4=1;												
				}
			}
		}
       } 
		if (n4==0){
			robar(fila, columna, baraja, jugador1);
			robo=robo+1;
		} 
		}while (n4<1);
		
	} else if(j2>20 && j2<=30) {	
							                        //si te saca espadas
	do{
		for (fila=0; fila<4; fila++){
			for (columna=0;columna<10;columna++){
				if (jugador1[fila][columna] !=0){
					if ((jugador1[fila][columna] >20) && (jugador1[fila][columna] <=30)){
							n4=1;												
				}
			}
		}
       } 
		if (n4==0){
			robar(fila, columna, baraja, jugador1);
			robo=robo+1;
		} 
		}while (n4<1);
	} else if(j2>30 && j2<=40) {						 
		                       //si te saca espadas
	do{
		for (fila=0; fila<4; fila++){
			for (columna=0;columna<10;columna++){
				if (jugador1[fila][columna] !=0){
					if ((jugador1[fila][columna] >30) && (jugador1[fila][columna] <=40)){
							n4=1;												
				}
			}
		}
       } 
		if (n4==0){
			robar(fila, columna, baraja, jugador1);
			robo=robo+1;
		} 
		}while (n4<1);
	}
    
    if (robo>0){
		printf("\nNo tienes cartas del palo jugado. Has robado %d cartas", robo);
	}

return(jugador1 [4] [10]); /*esto hay que revisarlo que me sale un warning en minix. El 10 esta mal puesto pero no se lo que hay que poner y solo se da cuenta clang*/
}

int contraataquej2 (int baraja [4] [10], int jugador1 [4] [10], int j1, int fila, int columna, int jugador2[4][10]){	//aquí estaba el segmentation fault
    
    //int n1; oros
	//int n2; copas
	//int n3; bastos
	//int n4; espadas
	
	int n4 = 0;
    int mejor=0;
    int robo=0;
	
	if(j1>0 && j1<=10) {						                        //si te saca oros
	do{
		for (fila=0; fila<4; fila++){
			for (columna=0;columna<10;columna++){
				if (jugador2[fila][columna] !=0){
					if ((jugador2[fila][columna] >0) && (jugador2[fila][columna] <=10) && (n4==0)){ //n4==0 es para que se quede con la primera carta que encuentre, es decir, con la mas baja.
							n4=jugador2[fila][columna];
					}
				}
			}
		}
        
		if (n4!=0){
			mejor = n4;
		} else robar2(fila, columna, baraja, jugador2);
			robo=robo+1;
		} while (n4<1);
	}
				
	 else	if(j1>10 && j1<=20) {						                        //si te saca copas
	do{
		for (fila=0; fila<4; fila++){
			for (columna=0;columna<10;columna++){
				if (jugador2[fila][columna] !=0){
					if ((jugador2[fila][columna] >10) && (jugador2[fila][columna] <=20) && (n4==0)){ 
							n4=jugador2[fila][columna];
					}
				}
			}
		}
        
		if (n4!=0){
			mejor = n4;
		} else robar2(fila, columna, baraja, jugador2);
		robo=robo+1;
		} while (n4<1);
		
	} if(j1>20 && j1<=30) {						                        //si te saca espadas
	do{
		for (fila=0; fila<4; fila++){
			for (columna=0;columna<10;columna++){
				if (jugador2[fila][columna] !=0){
					if ((jugador2[fila][columna] >20) && (jugador2[fila][columna] <=30)){
							n4=jugador2[fila][columna];
					}
				}
			}
		}
        
		if (n4!=0){
			mejor = n4;
		} else robar2(fila, columna, baraja, jugador2);
		robo=robo+1;
		} while (n4<1);
	} else if(j1>30 && j1<=40) {						                        //si te saca espadas
	do{
		for (fila=0; fila<4; fila++){
			for (columna=0;columna<10;columna++){
				if (jugador2[fila][columna] !=0){
					if ((jugador2[fila][columna] >30) && (jugador2[fila][columna] <=40)){
							n4=jugador2[fila][columna];				
					}
				}
			}
		}
        
		if (n4!=0){
			mejor = n4;
		} else robar2(fila, columna, baraja, jugador2);
		robo=robo+1;
		} while (n4<1);
	}
    
    if (robo>0){
		printf("\nJ2 ha robado %d cartas", robo);
	}
	
	//Con esta función pondremos a cero la carta jugada

for (fila=0; fila<4; fila++){
		for (columna=0;columna<10;columna++){
			if (mejor==jugador2[fila][columna]){
				jugador2[fila][columna]=0;
			}
		}
	}
	
    return mejor;
}

int seleccionj2 (int fila, int columna, int jugador2[4][10]){
	
	int n1=41; //oros
	int n2=41; //copas
	int n3=0; //bastos
	int n4=0; //espadas
	int t1=0;
	int t2=0;
	int t3=0;
	int t4=0;
	int menor;
	int mayor;
	//int mejores[2];
	//int mejoraleatorio;
    int mejor;
	
	for (fila=0; fila<4; fila++){
		for (columna=0;columna<10;columna++){
			if (jugador2[fila][columna] !=0){
				if ((jugador2[fila][columna] >0) && (jugador2[fila][columna] <=10)){
					if (jugador2[fila][columna]<n1){
						n1=jugador2[fila][columna];
					}
				}
					else if ((jugador2[fila][columna] >10) && (jugador2[fila][columna] <=20)){
					    if (jugador2[fila][columna]<n2){
						    n2=jugador2[fila][columna];
					    }
				    }
					else if ((jugador2[fila][columna] >20) && (jugador2[fila][columna] <=30)){
					    if (jugador2[fila][columna]>n3){
						    n3=jugador2[fila][columna];
					    }
				    }
					else if ((jugador2[fila][columna] >30) && (jugador2[fila][columna] <=40)){
					    if (jugador2[fila][columna]>n4){
						    n4=jugador2[fila][columna];
					    }
				    }
			}
		}
	}
	
	if (n1==41){
		n1=0;}
		
	if (n2==41){
		n2=0;}	
		
	
	//printf ("\nn1=%d",n1);
	//printf ("\nn2=%d",n2);
	//printf ("\nn3=%d",n3);
	//printf ("\nn4=%d",n4);

t1=n1;
t2=n2-10;
t3=n3-20;
t4=n4-30;

if ((t1<t2)&&(t1!=0)){
	menor = n1;
} else menor = n2;

if (menor == 0){  // Par evitar que si n2 == 0 menor sea 0.
	menor = n1;}

if ((t3>t4)&&(t3!=0)){
	mayor = n3;
} else mayor = n4;

//printf ("\nmenor=%d",menor);
//printf ("\nmayor=%d",mayor);

//Prueba

if(mayor>menor){
	mejor=mayor;
} else mejor=menor;

/*
mejores [0] = menor;
mejores [1] = mayor;

srand(time(NULL)); //Numero aleatorio mediante reloj
    
mejoraleatorio=(rand()%2);
		
mejor = mejores[mejoraleatorio];
*/
//Con esta función pondremos a cero la carta jugada

for (fila=0; fila<4; fila++){
		for (columna=0;columna<10;columna++){
			if (mejor==jugador2[fila][columna]){
				jugador2[fila][columna]=0;
			}
		}
	}


	return mejor;
}

int comparador (int j1, int j2, int turno) { //Compara las cartas para ver quien gana

		turno=1; //damos por hecho que gana la máquina, a no ser que...

					if ((j1 >0) && (j1 <11)){ //Son oros
					    if (j1<j2) {
							turno=0;
						}
		            } else
					if ((j1 >10) && (j1<21)){ //Son copas
					    if (j1<j2) {
							turno=0;
						}
				    } else
					if ((j1 >20) && (j1 <31)){ //Son bastos
					    if (j1>j2) {
							turno=0;
						}
				    } else
					if ((j1 >30) && (j1 <41)){ //Son espadas
					    if (j1>j2) {
							turno=0;
						}
		            }
		            
		   return turno;
}

int antichetos (int j1, int j2) {
	int cheto=0;
	
					if ((j2 >0) && (j2 <11)){ //Son oros
					    if ((j1 >0) && (j1 <11)) {
							cheto=0;
						} else {cheto=1;}
		            } else
					if ((j2 >10) && (j2<21)){ //Son copas
					    if ((j1 >10) && (j1 <21)) {
							cheto=0;
						} else {cheto=1;}
				    } else
					if ((j2 >20) && (j2 <31)){ //Son bastos
					   if ((j1 >20) && (j1 <31)) {
							cheto=0;
						} else {cheto=1;}
				    } else
					if ((j2 >30) && (j2 <41)){ //Son espadas
					    if ((j1 >30) && (j1 <41)) {
							cheto=0;
						} else {cheto=1;}
		            }
	
	return cheto;
}
