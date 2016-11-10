#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "myconio.h"
#include <dos.h>
#include <time.h>
#define F 8
#define C 8
#define N 157
#define L 0
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void presentacion(int a);
void cargar_matriz(int M[F][C]);
void imprimir_matriz(int M[F][C]);
void cargar_vector(int V[C]);
void imprimir_vector(int V[C]);
void mover_ficha1(int V[C], int M[F][C], char noum_jug1[20]);
void mover_ficha2(int V[C], int M[F][C], char noum_jug2[20]);
int comprobacion_1(int M[F][C], int *a_i, int *a_j,int *b_i, int *b_j,int *c_i, int *c_j,int *d_i, int *d_j, int *tipo, int *vertical, int *horizontal, int *diagonal);
int comprobacion_2(int M[F][C], int *a_i, int *a_j,int *b_i, int *b_j,int *c_i, int *c_j,int *d_i, int *d_j, int *tipo, int *vertical, int *horizontal, int *diagonal);
int dados(int *dado_1, int *dado_2);
void instrucciones(int R);
void creditos(int a);
int tres_horizontal1(int M[F][C]);
int tres_horizontal2(int M[F][C]);
int tres_vertical1(int M[F][C]);
int tres_vertical2(int M[F][C]);
int tres_diagonal1(int M[F][C]);
int tres_diagonal2(int M[F][C]);
int main(int argc, char *argv[])
{
	int M[F][C], V[C], ganar=0, turno, i, j, espacios, dado_1, dado_2, repetir_partidas,g1, g2, empate, jugadas_1, jugadas_2;
	int a_i, a_j,b_i, b_j,c_i, c_j,d_i, d_j, tipo, b;
	char noum_jug1[20],noum_jug2[20], opcion, v_nombre[10][20];
	int partidas, cont_empates,porcentaje_empates, vertical, horizontal, diagonal, cont_dados, v_partidas[20], H1, H2, V1, V2, D1, D2, R1,R2;

	do
	{
		system("cls");
		presentacion(1);
		
		textcolor(LIGHT_RED);
		
		textcolor(WHITE);
		printf("\n\n\n\n\t\t\t     [1]EMPEZAR JUEGO");
		printf("\n\n\t\t\t     [2]INSTRUCCIONES DEL JUEGO");
		printf("\n\n\t\t\t     [3]SALIR");
		opcion=getche();
		
		switch(opcion)
		{
			
					case '1':
					{
					
												system("cls");
												textcolor(LIGHT_WHITE);
												printf("\n\n\n\n\n\n\t\t\t     REGISTRO DE 4 EN LINEA\n\n\n\n");
												partidas=0;	
												cont_empates=0;
												cont_dados=0;
												repetir_partidas=0;
												dado_1=0;
												dado_2=0;
												g1=0;
												g2=0;
												empate=0;	
												printf("\t\t     NOMBRE\t\t    SORTEO PARA EMPEZAR\n\n");
												turno=dados(&dado_1, &dado_2);
												textcolor(LIGHT_RED);
												printf("\tJUGADOR 1:   ");	
												textcolor(GRAY);
												fflush(stdin);
												gets(noum_jug1);
												for(i=0;i<=dado_1;i++)
												{	
														textcolor(LIGHT_AQUA);
														gotoxy(53, 12);
														printf("  ");
														gotoxy(53, 12);
														printf("%d", i);
														Sleep(20);	
												}
											
												textcolor(LIGHT_GREEN);
												printf("\n\n\tJUGADOR 2:   ");
												textcolor(GRAY);
												fflush(stdin);
												gets(noum_jug2);
												for(i=0;i<=dado_2;i++)
												{	
														textcolor(LIGHT_AQUA);
														gotoxy(53, 14);
														printf("  ");
														gotoxy(53, 14);
														printf("%d", i);
														Sleep(20);	
												}	
												textcolor(WHITE);
												printf("\n\n\n\n\t\t\t\t\t     <-PRESIONA INTRO PARA COMENZAR->");
												getche();
												if(turno==1)
												{				
													strcpy(v_nombre[cont_dados], noum_jug1);		
				  									v_partidas[cont_dados]=partidas+1;
   
												}
												if(turno==2)
												{				
													v_partidas[cont_dados]=partidas+1;	
													strcpy(v_nombre[cont_dados], noum_jug2);
												}
												cont_dados=cont_dados+1;
								
								vertical=0;
								horizontal=0;
								diagonal=0;
										
								do
								{
											
											system("cls");
											textcolor(WHITE);
											printf("\t\t\t    VAMOS A JUGAR 4 EN LINEA\n\n\n\n");
											cargar_matriz(M);
											cargar_vector(V);
											imprimir_vector(V);
											imprimir_matriz(M);				
											espacios=0;
											jugadas_1=0;
											jugadas_2=0;
											b=0;
										
											do
											{
												
												
													if(turno==1)
													{
														textcolor(WHITE);
														gotoxy(2,23);printf("Espacios Ocupados: %d/64", espacios);
														textcolor(LIGHT_RED); 
														mover_ficha1(V, M, noum_jug1);                               
														ganar=comprobacion_1(M, &a_i, &a_j, &b_i, &b_j, &c_i, &c_j, &d_i, &d_j, &tipo, &vertical, &horizontal, &diagonal);	

														turno=2;
														jugadas_1++;
														espacios++;
														if(ganar==1)
														{
															turno=1;
															gotoxy(55,23);
															textcolor(WHITE);
															printf("HA GANADO %s!!!!!", noum_jug1);
															getche();	
															system("cls");
															textcolor(LIGHT_RED);
															printf("\n\t\t\tESTADISTICAS DEL JUGADOR:  %s", noum_jug1);
															textcolor(WHITE);
															printf("\n\n\n->JUGADAS REALIZADAS: %d", jugadas_1);
															if(tipo==1){printf("\n\n->FICHAS ALINEADAS DE FORMA HORIZONTAL");}
															if(tipo==2){printf("\n\n->FICHAS ALINEADAS DE FORMA VERTICAL");}
															if(tipo==3){printf("\n\n->FICHAS ALINEADAS DE FORMA DIAGONAL");}
															printf("\n\n->POSICIONES EN LAS CASILLAS: 1.-[%d][%d]", a_i,a_j);
															printf("\n\t\t\t      2.-[%d][%d]", b_i, b_j);
															printf("\n\t\t\t      3.-[%d][%d]", c_i, c_j);
															printf("\n\t\t\t      4.-[%d][%d]", d_i, d_j);
															g1++;
															getche();
															break;
														
														}
													}
													
																if(espacios==64)
																{
																	gotoxy(55,23);
																	textcolor(WHITE);
																	printf("EMPATE %c!!!!!",1 );
																	gotoxy(2,23);printf("Espacios Ocupados: %d/64", espacios);
																	getche();
																	system("cls");
																	printf("\n\t\t\tESTADISTICAS DEL EMPATE\n");
																	turno=dados(&dado_1, &dado_2);
																	if(turno==1)
																	{				
																		strcpy(v_nombre[cont_dados], noum_jug1);		
							  											v_partidas[cont_dados]=partidas + 2;
			   
																	}
																	if(turno==2)
																	{				
																		v_partidas[cont_dados]=partidas + 2;	
																		strcpy(v_nombre[cont_dados], noum_jug2);
																	}
																	H1=tres_horizontal1(M);
																	H2=tres_horizontal2(M);
																	V1=tres_vertical1(M);
																	V2=tres_vertical2(M);
																	D1=tres_diagonal1(M);
																	D2=tres_diagonal2(M);
							
			
																	printf("\n\n->NUMERO DE %s: %d", noum_jug1, jugadas_1);
																	R1=H1+V1+D1;
																	printf("\n\n\t\t-.VECES QUE HIZO TRES EN LINEA: %d\n", R1);
																	textcolor(GRAY);
																	printf("\n\t\t   -.Horizontal: %d", H1);
																	printf("\n\t\t   -.Vertical: %d", V1);
																	printf("\n\t\t   -.Diagonal: %d", D1);
																	textcolor(WHITE);
																	printf("\n\n->NUMERO DE %s: %d", noum_jug2, jugadas_2);
																	R2=H2+V2+D2;
																	printf("\n\n\t\t-.VECES QUE HIZO TRES EN LINEA: %d\n", R2);
																	textcolor(GRAY);
																	printf("\n\t\t   -.Horizontal: %d", H2);
																	printf("\n\t\t   -.Vertical: %d", V2);
																	printf("\n\t\t   -.Diagonal: %d", D2);
																	cont_dados=cont_dados+1; 
																	cont_empates++;
																	empate++;
																	getche();
																	break;
																	
																}	
													if(turno==2)
													{
														
														textcolor(WHITE);
														gotoxy(2,23);printf("Espacios Ocupados: %d/64", espacios);
														textcolor(LIGHT_GREEN);
														mover_ficha2(V, M, noum_jug2);
														ganar=comprobacion_2(M, &a_i, &a_j, &b_i, &b_j, &c_i, &c_j, &d_i, &d_j, &tipo, &vertical, &horizontal, &diagonal);	
														turno=1;
														jugadas_2++;
														espacios++;
														if(ganar==2)
														{
															turno=2;
															gotoxy(55,23);
															textcolor(WHITE);
															printf("HA GANADO %s!!!!!", noum_jug2);
															getche();	
															system("cls");
															textcolor(LIGHT_GREEN);
															printf("\n\t\t\tESTADISTICAS DEL JUGADOR:  %s", noum_jug2);
															textcolor(WHITE);
															printf("\n\n\n->JUGADAS REALIZADAS: %d", jugadas_2);
															if(tipo==1){printf("\n\n->FICHAS ALINEADAS DE FORMA HORIZONTAL");}
															if(tipo==2){printf("\n\n->FICHAS ALINEADAS DE FORMA VERTICAL");}
															if(tipo==3){printf("\n\n->FICHAS ALINEADAS DE FORMA DIAGONAL");}
															printf("\n\n->POSICIONES EN LAS CASILLAS: 1.-[%d][%d]", a_i,a_j);
															printf("\n\t\t\t      2.-[%d][%d]", b_i, b_j);
															printf("\n\t\t\t      3.-[%d][%d]", c_i, c_j);
															printf("\n\t\t\t      4.-[%d][%d]", d_i, d_j);
															g2++;
															getche();
															break;
													
														
														}
												
						
													}
															
													
																	if(espacios==64)
																	{
																		gotoxy(55,23);
																		textcolor(WHITE);
																		printf("EMPATE %c!!!!!",1 );
																		gotoxy(2,23);printf("Espacios Ocupados: %d/64", espacios);
																		getche();
																		system("cls");
																		printf("\n\t\t\tESTADISTICAS DEL EMPATE\n");
																		turno=dados(&dado_1, &dado_2);
																		if(turno==1)
																		{				
																			strcpy(v_nombre[cont_dados], noum_jug1);		
								  											v_partidas[cont_dados]=partidas + 2;
				   
																		}
																		if(turno==2)
																		{				
																			v_partidas[cont_dados]=partidas + 2;	
																			strcpy(v_nombre[cont_dados], noum_jug2);
																		}
																		H1=tres_horizontal1(M);
																		H2=tres_horizontal2(M);
																		V1=tres_vertical1(M);
																		V2=tres_vertical2(M);
																		D1=tres_diagonal1(M);
																		D2=tres_diagonal2(M);
					
																	
																		printf("\n\n->NUMERO DE %s: %d", noum_jug1, jugadas_1);
																		R1=H1+V1+D1;
																		printf("\n\n\t\t-.VECES QUE HIZO TRES EN LINEA: %d\n", R1);
																		textcolor(GRAY);
																		printf("\n\t\t   -.Horizontal: %d", H1);
																		printf("\n\t\t   -.Vertical: %d", V1);
																		printf("\n\t\t   -.Diagonal: %d", D1);
																		textcolor(WHITE);
																		printf("\n\n->NUMERO DE %s: %d", noum_jug2, jugadas_2);
																		R2=H2+V2+D2;
																		printf("\n\n\t\t-.VECES QUE HIZO TRES EN LINEA: %d\n", R2);
																		textcolor(GRAY);
																		printf("\n\t\t   -.Horizontal: %d", H2);
																		printf("\n\t\t   -.Vertical: %d", V2);
																		printf("\n\t\t   -.Diagonal: %d", D2);
																		cont_dados=cont_dados+1;                      
																		cont_empates++;
																		empate++;
																		getche();
																		break;
																		
																	}
													
												
													
											}while(1);	
								
									
									
										repetir_partidas++;
										if(empate==4)
										{
											repetir_partidas--;
											empate--;
											g1=2;
											g2=2;	
										}
										if(g1==2 && g2==2 || g1==2 && g2==2 && empate==1)
										{
											repetir_partidas--;
											cont_empates;
										}
										if(empate==2 && g1==1 && g2==1)
										{
											repetir_partidas--;
											empate--;
											g1=2;
											g2=2;
										}
										if(empate==1 && g1==2 || empate==1 && g2==2)
										{
											repetir_partidas=4;
										}
										
									
										partidas++;		
								}while(repetir_partidas<4 && g1!=3 && g2!=3);
						
								
									system("cls");
									textcolor(LIGHT_RED);
									printf("\n\t\t\t      ESTADISTICAS GENERALES\n");Sleep(350);
									textcolor(LIGHT_WHITE);
									printf("\n1.- PARTIDAS JUGADAS:  %d", partidas);Sleep(350);
									printf("\n\n2.- PARTIDAS GANADAS POR CADA JUGADOR:\n\n");Sleep(350);
									textcolor(GRAY);
									printf("\n\t\t\t-.%s: %d partidas", noum_jug1, g1);Sleep(350);
									printf("\n\t\t\t-.%s: %d partidas", noum_jug2, g2);Sleep(350);
									textcolor(LIGHT_WHITE);
									printf("\n\n\n3.- PARTIDAS EMPATADAS: %d\n", cont_empates);Sleep(350);
									printf("\n\n4.-GANADOR ABSOLUTO:\n");Sleep(350);
									textcolor(GRAY);
									if(g1==3 && empate==1 && partidas==4 || g1==3 && g2==1 && partidas==4 || partidas==3 && g1==3)
									{
										if(empate==1){printf("\n\t\t\t-. %s: 3 ganados, 1 empate ", noum_jug1);Sleep(350);}
										else if(g2==1){printf("\n\t\t\t-. %s: 3 ganados, 1 perdido", noum_jug1);Sleep(350);}
										else {printf("\n\t\t\t-. %s: 3 ganados / 3 partidas", noum_jug1);Sleep(350);}
									}
									else if(g2==3 && empate==1 && partidas==4 || g2==3 && g1==1 && partidas==4 || partidas==3 && g2==3)
									{
										if(empate==1){printf("\n\t\t\t-. %s: 3 ganados, 1 empate ", noum_jug2);Sleep(350);}
										else if(g1==1){printf("\n\t\t\t-. %s: 3 ganados, 1 perdido", noum_jug1);Sleep(350);}
										else{printf("\n\t\t\t-. %s: 3 ganados / 3 partidas", noum_jug2);Sleep(350);}
									}
									else
									{
										printf("\n\t\t\t-. NO HUBO GANADOR ABSOLUTO");Sleep(350);
									}
									textcolor(LIGHT_WHITE);
									porcentaje_empates=(cont_empates*100)/partidas;
									printf("\n\n\n5.-PORCENTAJE DE PARTIDAS EMPATADAS: %d porciento\n", porcentaje_empates);Sleep(350);
									printf("\n\n6.-FORMA DE LAS RECTAS GANADORAS:\n");Sleep(350);
									textcolor(GRAY);
									printf("\n\t\t\t-. HORIZONTALES: %d", horizontal);Sleep(350);
									printf("\n\t\t\t-. VERTICALES: %d", vertical);Sleep(350);
									printf("\n\t\t\t-. DIAGONALES: %d", diagonal);Sleep(350);
									textcolor(LIGHT_WHITE);
									printf("\n\n7.-VECES QUE SE LANZARON LOS DADOS %d:\n", cont_dados);Sleep(350);
									textcolor(GRAY);
									for(i=0; i<cont_dados;i++)
									{                                   
										printf("\n\t\t\t-. PARTIDA: %d , GANADOR DEL SORTEO: %s", v_partidas[i], v_nombre[i]);Sleep(350);
									}
									
									
									
									
						break;
					}
					case '2':
					{
						
						instrucciones(1);
						break;
					}
		};
	
		getche();
		system("cls");
	}while(opcion!='3');
	
	creditos(1);
	return 0;
}

void creditos(int a)
{
	int x,  y;
	system("cls");
	x=25;
	y=21;
	gotoxy(25, 21);
	printf("    CU4TROENLINEA V 1.0 %c", 169);
	gotoxy(25, 22);
	printf("CREADO POR BRAYAN B. MONTA%cEZ O.",165);
	gotoxy(25, 23);
	printf("      C.I.: V.-27.270.063");
	gotoxy(25, 26);
	printf("     PROYECTO  COMPUTACION");
	gotoxy(25, 27);
	printf("     PROF.: DESIREE CHACON");
	do
	{
				gotoxy(x, y);
				printf("                                ");
				gotoxy(x, y+1);
				printf("                                     ");
				gotoxy(x, y+2);
				printf("                                     ");
				gotoxy(x, y+5);
				printf("                                     ");
				gotoxy(x, y+6);
				printf("                                     ");
				y = y-1;
			gotoxy(x, y);
			printf("    CU4TROENLINEA V 1.0 %c", 169);
			gotoxy(x, y+1);
			printf("CREADO POR BRAYAN B. MONTA%cEZ O.",165);
			gotoxy(x, y+2);
			printf("      C.I.: V.-27.270.063");
			gotoxy(x, y+5);
			printf("     PROYECTO  COMPUTACION");
			gotoxy(x, y+6);
			printf("     PROF.: DESIREE CHACON");
			Sleep(100);
	}while(kbhit && y>5);
	getche();
	printf("\n\n\n\n\n\n\n\n");
}
//***********************************      INSTRUCCIONES    *************************************//
void instrucciones(int R)
{
	system("cls");
	textcolor(LIGHT_WHITE);
	printf("********************************************************************************");
	printf("*                                                                              *");
	printf("*                                 INSTRUCCIONES                                *");
	printf("*                                                                              *");
	printf("*                                                                              *");
	printf("*    Bienvenido a CU4TROENLINEA V 1.0                                          *");
	printf("*                                                                              *");
	printf("*                                                                              *");
	printf("*                                                                              *");
	printf("*    TECLAS DE MOVIMIENTO: Usa las teclas que se encuentran el la parte        *");
	printf("*                          inferior derecha del teclado para recorrer y        *");
	printf("*                          ubicar tu ficha en la mejor columna.                *");
	printf("*                                                                              *");
	printf("*                                                                              *");
	printf("*                             -->   Derecha                                    *");
	printf("*                             <--   Izquierda                                  *");
	printf("*                                                                              *");
	printf("*                                                                              *");
	printf("*    LANZAR FICHA: Para lanzar tu ficha por el tablero solo debes              *");
	printf("*                  oprimir la tecla INTRO del teclado.                         *");
	printf("*                                                                              *");
	printf("*                                                                              *");
	printf("*                             INTRO  Lanzar ficha                              *");
	printf("*                                                                              *");
	printf("*******************************************************************************");
	
}
//***********************************      CARGAR MATRIZ CON 0    *************************************//
void cargar_matriz(int M[F][C])
{
	int i,j;
	for(i=0;i<F;i++){
		for(j=0;j<C;j++){
			M[i][j]=0;
			
		}
	}
}
//***********************************        IMPRIMIR MATRIZ      *************************************//
void imprimir_matriz(int M[F][C])
{
	int i,j;
	printf("\n");
	for(i=0;i<F;i++)
	{
		printf("\n");
		printf("\t\t\t");
		for(j=0;j<C;j++)
		{
			printf("[%c] ", M[i][j]);
		}
		printf("\n");
	}
	
}
//***********************************      CARGAR VECTOR CON 0    *************************************//
void cargar_vector(int V[C])
{
	int i;
	
	for(i=0;i<C;i++)
	{
		V[i]=0;
	}
}
//***********************************        IMPRIMIR VECTOR      *************************************//
void imprimir_vector(int V[C])
{
	int i;
	
	printf("\n\t\t<--\t");
	for(i=0;i<C;i++)
	{	
		textcolor(LIGHT_PURPLE);
		printf("[%c] ",V[i]);
	}
	textcolor(WHITE);
	printf("    -->");
}
//**********************     MOVIMIENTO DEL JUGADOR 1 POR EL VECTOR Y MATRIZ  *************************//
void mover_ficha1(int V[8], int M[F][C],char noum_jug1[20])
{
	int x, y, aux=0, cy=0, salir=0,i,j,o,z;
	char tecla;	
	x=25;
	y=5; 

	  gotoxy(68, 5); printf("                 ");
	  gotoxy(68, 5);printf("%s", noum_jug1);
	  gotoxy(25, 5);
	  printf("%c",N);
   
do{

	if (!kbhit())
	{
        tecla=getch();
	}
	switch (tecla)
	{
            case 75:                             //IZQUIERDA
			{
                if ( x > 25 ) 
				{
                gotoxy ( x, y );
                printf ( "%c",0);
                x = x - 4;
                gotoxy ( x, y );
                printf ( "%c",N);
               	
            	}
				break;
            }       
            case 77:                              //DERECHA
			{
                if ( x < 53 ) 
				{
                gotoxy ( x, y );
                printf ( "%c",0 );
                x = x + 4;
                gotoxy ( x, y );
                printf ( "%c",N);
               
            	}
            	break;
            }

		   case 13:                                //INTRO=BAJAR
			{	
				if(x==25){aux=0;}
				if(x==29){aux=1;}
				if(x==33){aux=2;}
				if(x==37){aux=3;}
				if(x==41){aux=4;}
				if(x==45){aux=5;}
				if(x==49){aux=6;}
				if(x==53){aux=7;}
				cy=y+2;
			    for(i=0;i<F;i++)
			    {
			    
			    		if(M[i][aux]==0)
			    		{
			    			gotoxy ( x, y );
                			printf ( "%c",0 );
                			cy=y+2;
                			y=cy;
                			gotoxy ( x, y );
                			printf ("%c",N );
                			z=i;
                			o=aux;
							Sleep(60); 				   
			    		}
			    		else
			    		{
							salir=1;	
			    			break;
			    		}
			    		      		 
			    }
                   
            	M[z][o]=1;    //NUMERO 1 PARA QUE CUBRA EL ESPACIO Y LUEGO PODER USARLO COMO UNA ESPECIE DE BANDERA PARA J1
            	salir=1;
            	break;
            }        
	};
				
}while(salir==0);

}
//**********************     MOVIMIENTO DEL JUGADOR 2 POR EL VECTOR Y MATRIZ  *************************//
void mover_ficha2(int V[8], int M[F][C], char noum_jug2[20])
{
	int x, y, aux=0, cy=0, salir=0,i,j, z, o;
	char tecla;	
	x=25;
	y=5; 
	  gotoxy(68, 5); printf("                 ");
	  gotoxy(68, 5);printf("%s", noum_jug2);
	  gotoxy(25, 5);
	  printf("%c",N);
   
do{
	if (!kbhit())
	{
        tecla=getch();
	}
	switch (tecla)
	{
            case 75:                                     //IZQUIERDA
			{
                if ( x > 25 ) 
				{
                gotoxy ( x, y );
                printf ( "%c",0);
                x = x - 4;
                gotoxy ( x, y );
                printf ( "%c",N);
               	
            	}
				break;
            }       
            case 77:                                      //DERECHA
			{
                if ( x < 53 ) 
				{
                gotoxy ( x, y );
                printf ( "%c",0 );
                x = x + 4;
                gotoxy ( x, y );
                printf ( "%c",N);
               
            	}
            	break;
            }
           
           	
		   case 13:                                        //INTRO=BAJAR
			{	
				if(x==25){aux=0;}
				if(x==29){aux=1;}
				if(x==33){aux=2;}
				if(x==37){aux=3;}
				if(x==41){aux=4;}
				if(x==45){aux=5;}
				if(x==49){aux=6;}
				if(x==53){aux=7;}
				cy=y+2;
			    for(i=0;i<F;i++)
			    {
			    
			    		if(M[i][aux]==0)
			    		{
			    			gotoxy ( x, y );
                			printf ( "%c",0 );
                			cy=y+2;
                			y=cy;
                			gotoxy ( x, y );
                			printf ("%c",N );
                			z=i;
                			o=aux; 
							Sleep(60);				   
			    		}
			    		else
			    		{
							salir=1;	
			    			break;
			    		}
			    		       		 
			    }      
            
            	M[z][o]=2;	//NUMERO 2 PARA QUE CUBRA EL ESPACIO Y LUEGO PODER USARLO COMO UNA ESPECIE DE BANDERA PARA J2
            	salir=1;
            	break;
            }        
	};
			
}while(salir==0);
}
//************************************  COMPROBACION PARA JUGADOR 1 **********************************//
int comprobacion_1(int M[F][C], int *a_i, int *a_j,int *b_i, int *b_j,int *c_i, int *c_j,int *d_i, int *d_j, int *tipo, int *vertical, int *horizontal, int *diagonal)
{ 
   int i,j,bandera=0;
  													
   for(i=0;i<F;i++)
    {     		
    	for(j=0;j<C-3;j++)
     	{			
		      		if(M[i][j]==1 && M[i][j+1]==1 && M[i][j+2]==1 && M[i][j+3]==1)   //HORIZONTAL
		         	{
		         		*a_i=i;		*a_j=j;
		         		*b_i=i; 	*b_j=j+1; 
		         		*c_i=i; 	*c_j=j+2; 
		         		*d_i=i; 	*d_j=j+3; 
		         		*horizontal=*horizontal+1;
						 bandera=1;
		         		*tipo=1;
		         		break;
		         	}

    	}

     	if(bandera==1)
        {
        	return 1;
        	break;
        }

     }
     
    for(i=0;i<F-3;i++)
	{
		for(j=0;j<C-3;j++)
		{
					if(M[i][j]==1 && M[i+1][j+1]==1 && M[i+2][j+2]==1 && M[i+3][j+3]==1)  //DIAGONAL PRINCIPAL
		        	{
		        		*a_i=i;		*a_j=j;
		         		*b_i=i+1; 	*b_j=j+1; 
		         		*c_i=i+2; 	*c_j=j+2; 
		         		*d_i=i+3; 	*d_j=j+3; 	
		        		bandera=1;
		        		*diagonal=*diagonal+1;
		        		*tipo=3;
		        		break;
		       		}
		}
		if(bandera==1)
        {
        	return 1;
        	break;
        }
		
	}																 //VERTICAL 
	for(j=0;j<C;j++)
    {
    	bandera=0;
    	for(i=0;i<F-3;i++)
    	{
    		
    		if(M[i][j]==1 && M[i+1][j]==1 && M[i+2][j]==1 && M[i+3][j]==1)
         	{
         		*a_i=i;		*a_j=j;
		       	*b_i=i+1; 	*b_j=j; 
		       	*c_i=i+2; 	*c_j=j; 
		        *d_i=i+3; 	*d_j=j; 
		        *vertical=*vertical+1;
        	 	bandera=1;
        	 	*tipo=2;
         		break;
         	}
    	}
     		if(bandera==1)
        	{
        		return 1;
        		break;
        	}
     }

															//DIAGONAL INVERSA
	for(j=C-1;j>=0;j--)
	{
		for(i=F-4;i>=0;i--)
		{
		    bandera=0;
		     if(M[i][j]==1 && M[i+1][j-1]==1 && M[i+2][j-2]==1 && M[i+3][j-3]==1)
		        {
		        		*d_i=i;		*d_j=j;
		       			*c_i=i+1; 	*c_j=j-1; 
		       			*b_i=i+2; 	*b_j=j-2; 
		        		*a_i=i+3; 	*a_j=j-3; 
		        	bandera=1;
		        	*diagonal=*diagonal+1;
		        	*tipo=3;
		        	break;
		       }
	    }
		  		if(bandera==1)
		        {
		        	return 1;
		        	break;
		        }
  	}

}

//************************************  COMPROBACION PARA JUGADOR 2 ***********************************//
int comprobacion_2(int M[F][C], int *a_i, int *a_j,int *b_i, int *b_j,int *c_i, int *c_j,int *d_i, int *d_j, int *tipo, int *vertical, int *horizontal, int *diagonal)
{
   int i,j,bandera;
   bandera=0;																
   for(i=0;i<F;i++)
    {
     
    	for(j=0;j<C-3;j++)
     	{
     	
     			
		      		if(M[i][j]==2 && M[i][j+1]==2 && M[i][j+2]==2 && M[i][j+3]==2)    //HORIZONTAL
		         	{
		         		*a_i=i;		*a_j=j;
		         		*b_i=i; 	*b_j=j+1; 
		         		*c_i=i; 	*c_j=j+2; 
		         		*d_i=i; 	*d_j=j+3; 
		         		*tipo=1;
		         		*horizontal=*horizontal+1;
		         		bandera=1;
		         		break;
		         	}
    	}

     	if(bandera==1)
        {
        	return 2;
        	break;
        }

     }        
    for(i=0;i<F-3;i++)
	{
		for(j=0;j<C-3;j++)
		{
					if(M[i][j]==2 && M[i+1][j+1]==2 && M[i+2][j+2]==2 && M[i+3][j+3]==2)  //DIAGONAL PRINCIPAL
		        	{
		        		*a_i=i;		*a_j=j;
		         		*b_i=i+1; 	*b_j=j+1; 
		         		*c_i=i+2; 	*c_j=j+2; 
		         		*d_i=i+3; 	*d_j=j+3; 	
		        		bandera=1;
		        		*diagonal=*diagonal+1;
		        		*tipo=3;
		        		break;
		       		}
		}
		if(bandera==1)
        {
        	return 2;
        	break;
        }
		
	}	
     																	//VERTICAL   
	for(j=0;j<C;j++)
    {
    	bandera=0;
    	for(i=0;i<F-3;i++)
    	{
    		
    		if(M[i][j]==2 && M[i+1][j]==2 && M[i+2][j]==2 && M[i+3][j]==2)
         	{
         		*a_i=i;		*a_j=j;
		       	*b_i=i+1; 	*b_j=j; 
		       	*c_i=i+2; 	*c_j=j; 
		        *d_i=i+3; 	*d_j=j; 
		        *tipo=2;
		        *vertical=*vertical+1;
        	 	bandera=1;
         		break;
         	}
    	}
     		if(bandera==1)                               
        	{   
		  

        		return 2;
        		break;
        	}
     }

																		//DIAGONAL INVERSA	
	for(j=C-1;j>=0;j--)
	{
		for(i=F-4;i>=0;i--)
		{
		    bandera=0;
		     if(M[i][j]==2 && M[i+1][j-1]==2 && M[i+2][j-2]==2 && M[i+3][j-3]==2)
		        {
		        		*d_i=i;		*d_j=j;
		       			*c_i=i+1; 	*c_j=j-1; 
		       			*b_i=i+2; 	*b_j=j-2; 
		        		*a_i=i+3; 	*a_j=j-3;
					*tipo=3; 
					*diagonal=*diagonal+1;                            
		        	bandera=1;
		        	break;
		       }                  
	    }
		  		if(bandera==1)
		        {
		        
		        	return 2;
		        	break;
		        }
  	}
}
//************************************              SORTEO            ***********************************//
int dados(int *dado_1, int *dado_2)
{
	int A;
	srand(time(NULL));
	do
	{
		*dado_1=rand()%100;  
		*dado_2=rand()%100;  
		if(*dado_1>*dado_2){A=1;}                           
		if(*dado_2>*dado_1){A=2;}
		
	}while(*dado_1==*dado_2);
	
	return A;
}
int tres_horizontal1(int M[F][C])
{
	int i, j, cont=0;	
	for(i=0;i<F; i++)
	{
		for(j=0; j<C-2; j++)
		{
			if(M[i][j]==1 && M[i][j+1]==1 && M[i][j+2]==1)
			{
				cont++;
			}
		}
	}
	return cont;
}

int tres_horizontal2(int M[F][C])
{
	int i, j, cont=0;	
	for(i=0;i<F; i++)
	{
		for(j=0; j<C-2; j++)
		{
			if(M[i][j]==2 && M[i][j+1]==2 && M[i][j+2]==2)
			{
				cont++;
			}
		}
	}
	return cont;
}

int tres_vertical1(int M[F][C])
{
	int i, j, cont=0;
	
	for(j=0;j<C; j++)
	{
		for(i=0; i<F-2; i++)
		{
			if(M[i][j]==1 && M[i+1][j]==1 && M[i+2][j]==1)
			{
				cont++;
			}
		}
	}
	return cont;
}
int tres_vertical2(int M[F][C])
{
	int i, j, cont=0;
	for(j=0;j<C; j++)
	{
		for(i=0; i<F-2; i++)
		{
			if(M[i][j]==2 && M[i+1][j]==2 && M[i+2][j]==2)
			{
				cont++;
			}
		}
	}
	return cont;
}
int tres_diagonal1(int M[F][C])
{
	int i, j, r=0,a=0, b=0;	
	for(i=0;i<8-2; i++)
	{
		for(j=0; j<8-2; j++)
		{
			if(M[i][j]==1 && M[i+1][j+1]==1 && M[i+2][j+2]==1)
			{
				a++;
			}
		}
	}	
	for(j=C-1;j>=0;j--)
	{
		for(i=F-3;i>=0;i--)
		{
		    
		     if(M[i][j]==1 && M[i+1][j-1]==1 && M[i+2][j-2]==1)
		        {			
		        	b++;
		       }           
		       
	    }
	}
	
	r= a +b;
	return r;
}

int tres_diagonal2(int M[F][C])
{
	int i, j, r=0,a=0, b=0;
	
	for(i=0;i<8-2; i++)
	{
		for(j=0; j<8-2; j++)
		{
			if(M[i][j]==2 && M[i+1][j+1]==2 && M[i+2][j+2]==2)
			{
				a++;
			}
		}
	}
	for(j=C-1;j>=0;j--)
	{
		for(i=F-3;i>=0;i--)
		{
		    
		     if(M[i][j]==2 && M[i+1][j-1]==2 && M[i+2][j-2]==2)
		        {			
		        	b++;
		       }           
		       
	    }
	}	
	r= a + b;	
	return r;
}

void presentacion(int a)
{
	textcolor(RED);
	
	printf("\n\n\n           XXXXXX   XX    XX    XXXXX   XXXXXXXXXX  XXXXXX      XXX         ");
	printf("             XX        XX    XX   XX  XX       XX      XX   XX    XX   XX       ");
	printf("            XX        XX    XX  XX   XX       XX      XX   XX   XX     XX       ");
	printf("           XX        XX    XX  XXXXXXXXX     XX      XX XX     XX     XX        ");
    printf("          XX        XX    XX       XX       XX      XX  XX     XX   XX          ");
	printf("         XXXXXX    XXXXXXXX       XX       XX      XX    XX      XXX            ");
	printf("                                                                                ");
	printf("         XXXXXXX  XXXX    XX      XX       XXXXXX  XXXX    XX  XXXXXXX  XXXXXXX ");
	printf("        XX       XX XX   XX      XX         XX    XX XX   XX  XX       XX   XX  ");
	printf("       XXXXXX   XX  XX  XX      XX         XX    XX  XX  XX  XXXXXX   XXXXXXX   ");
	printf("      XX       XX   XX XX      XX         XX    XX   XX XX  XX       XX   XX    ");
    printf("     XXXXXXX  XX    XXXX      XXXXXXX  XXXXXX  XX    XXXX  XXXXXXX  XX   XX     ");
	 
}





