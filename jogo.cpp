/* 
	Jogo da Forca em C++
	Autor: Matheus Henrique da Silva dos Santos
*/


/* Bibliotecas */
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

/* Declaração de Funções */
void menu();
void game();
int drawing(int life);
void rules();

/* Função Principal */

int main(){
	
	int select;
	SetConsoleTitle("JOGO DA FORCA");
	
	while(true){
				
		menu();
		
		cin >> select;
		
		if(select == 1){
			game();
		}
		
		if(select == 2){
			rules();
		}
		
		if(select == 3){
			break;
		}

	
}
	
	
	return 0;
}


/* Escrita das funções */

void menu(){
	system("color 0B");
	
	cout << "\t\t\t\t\t\tJOGO "; Sleep(500);
	cout << "DA ";   Sleep(500);
	cout << "FORCA"; Sleep(500);
	
	cout << endl << endl;
	
	cout << "\t\t\t\t\t\t1 - INICIAR" << endl;
	cout << "\t\t\t\t\t\t2 - REGRAS" << endl;
	cout << "\t\t\t\t\t\t3 - SAIR" << endl << endl;
	cout << "OPCAO -> ";
}

void game(){	// Lógica do jogo
	
	system("cls");
	
	char executionerPlayer[30], guessingPlayer[30], executionerWord[30], executionerWordHidden[30], letter;
	string guessingWords;
	int auxLife, life = 0;
	
	for(int i =0; i<30;i++){
		executionerWord[i] = NULL;
		executionerWordHidden[i] = NULL;
	}
	
	cout << "Digite o nome do executor -> ";
	fflush(stdin);
	gets(executionerPlayer);
	
	cout << endl << "Digite o nome do advinhador -> ";
	gets(guessingPlayer);
	
	system("cls");
	
	cout << "(CARRASCO) " << executionerPlayer << " digite uma frase ou palavra -> ";
	fflush(stdin);
	gets(executionerWord);
	
	for(int i = 0; executionerWord[i] != '\0'; i++){
		if(executionerWord[i] == ' '){
			executionerWordHidden[i] = ' ';
		}
		else{
			executionerWordHidden[i] = '_';
		}
	}
	
	system("cls");
	
	while(true){
		auxLife = 0;
		cout << "LETRAS -> " << guessingWords << endl;
		
		drawing(life);
		
		if(life == 5){
			cout << "VOCE PERDEU O JOGO!" << endl << endl;
			cout << "A PALAVRA ERA -> " << executionerWord << endl;
			Sleep(5000);
			system("cls");
			break;
		}
		
		cout << "\t\t\t\t\t\t\t\t" << executionerWordHidden << endl;
		cout << "Letra -> ";
		cin >> letter;
		
		guessingWords += letter; 
		
		
		for(int i = 0; executionerWord[i] != '\0'; i++){
			if(executionerWord[i] == letter){
				executionerWordHidden[i] = letter;
			
				auxLife++;
			}
		}
		
		if(auxLife == 0){
			life++;
		}
		
		
		if(!strcmp(executionerWordHidden,executionerWord)){
			cout << "PARABENS, " << guessingPlayer << " !! Voce advinhou a palavra!!!" << endl << endl;
			cout << "PALAVRA -> " << executionerWord << endl;
			Sleep(5000);
			system("cls");
			break;
		}
		
	}
}

int drawing(int life){
	if(life == 0){
				
		cout << "     ----------    "  << endl;
		cout << "    |        __|__ "  << endl;
		cout << "    |              "  << endl;
		cout << "    |              "  << endl;
		cout << "    |              "  << endl;
		cout << "    |              "  << endl;
		cout << "    |              "  << endl;
		cout << " ___|___           "  << endl;
		cout << endl;
	}else{
		if(life == 1){
			
			cout << "     ----------    "  << endl;
			cout << "    |        __|__ "  << endl;
			cout << "    |          0    " << endl;
			cout << "    |              "  << endl;
			cout << "    |              "  << endl;
			cout << "    |              "  << endl;
			cout << "    |              "  << endl;
			cout << " ___|___           "  << endl;
			cout << endl;
			
		}
	else{
			if (life == 2){
				
				cout << "     ----------    "  << endl;
				cout << "    |        __|__ "  << endl;
				cout << "    |          0   "  << endl;
				cout << "    |         /|   "  << endl;
				cout << "    |              "  << endl;
				cout << "    |              "  << endl;
				cout << "    |              "  << endl;
				cout << " ___|___           "  << endl;
				cout << endl;	
				
			}else{
				if(life == 3){
					
					cout << "     ----------    "  << endl;
					cout << "    |        __|__ "  << endl;
					cout << "    |          0   "  << endl;
					cout << "    |         /|\\ "  << endl;
					cout << "    |              "  << endl;
					cout << "    |              "  << endl;
					cout << "    |              "  << endl;
					cout << " ___|___           "  << endl;
					cout << endl;
					
				}else{
					if(life == 4){
						
						cout << "     ----------    "  << endl;
						cout << "    |        __|__ "  << endl;
						cout << "    |          0   "  << endl;
						cout << "    |         /|\\ "  << endl;
						cout << "    |          |   "  << endl;
						cout << "    |         /    "  << endl;
						cout << "    |              "  << endl;
						cout << " ___|___           "  << endl;
						cout << endl;
						
					}else{
						if(life == 5){
							   
							cout << "     ----------    "  << endl;
							cout << "    |        __|__ "  << endl;
							cout << "    |          0   "  << endl;
							cout << "    |         /|\\ "  << endl;
							cout << "    |          |   "  << endl;
							cout << "    |         / \\ "  << endl;
							cout << "    |              "  << endl;
							cout << " ___|___           "  << endl;
							cout << endl;
							cout << "QUE PENA VC PERDEU O JOGO !!!" << endl << endl;
							   	
						}
					}
				}
			}
		}
	}
}

void rules(){
	
	cout << "REGRA NUMERO 1 -> A PALAVRA DEVE CONTER SOMENTE LETRAS" << endl;
	cout << "REGRA NUMERO 2 -> NUMERO DE VIDAS = 5" << endl;
	cout << "REGRA NUMERO 3 -> LETRAS ERRADAS REPETIDAS SERAO CONSIDERADAS COMO ERROS" << endl;
	
	Sleep(5000);
	system("cls");
}
	
	




