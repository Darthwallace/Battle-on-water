#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <new>
#include <time.h>

using namespace std;

void menuInicial();

using namespace std;

void limpaTela(){
	system("CLS");
}


void iniciaTabuleiro(char tabuleiro[10][10], char mascara[10][10]){
	
	
	int linha,coluna;
	//popula o tabuleiro com agua
	for(linha = 0; linha < 10; linha++){
	  for(coluna = 0; coluna < 10;coluna++){
	  	  tabuleiro[linha][coluna] = 'A';
	  	  mascara[linha][coluna] = '*';
	  }
	}
	
	
}

void exibeMapa(){
	
	int i;
	for(i = 0; i < 10; i++){
		if(i == 0){
		  cout << "     ";	
		}
		  cout << i << " ";
	}
	cout << "\n";
	for(i = 0; i < 10; i++){
		if(i == 0){
		  cout << "     ";	
		}
		  cout << "| ";
	}
	cout << "\n";


	
}

void exibeTabuleiro(char tabuleiro[10][10],char mascara[10][10],bool mostraMascara){
	
	char red[] = { 0x1b, '[', '1', ';', '3', '5', 'm', 0 };
	char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
    char normal[] = { 0x1b, '[', '1', ';', '3', '9', 'm', 0 };
	
		
		
	int linha,coluna;
	
	for(linha = 0; linha < 10; linha++){
		cout << linha << " - ";
	  for(coluna = 0; coluna < 10;coluna++){
	  	  
		  switch(mascara[linha][coluna]){
		  	 case 'A':
		  	 	cout << blue << " " << mascara[linha][coluna] << normal;
		  	 	break;
		  	 case 'B':
		  	 	cout << green << " " << mascara[linha][coluna] << normal;
			   	break;
		  	 default:
		  	 	cout << " " << mascara[linha][coluna];
			    break;	
		  	
		  }  
	  	  if(mascara[linha][coluna] == 'A'){
	  	  	        
			}else{
				    
			}
	  	
	  }
	      cout << "\n";
	}
	
	if(mostraMascara == true){
		for(linha = 0; linha < 10; linha++){
	  for(coluna = 0; coluna < 10;coluna++){
	  	  cout << " " << tabuleiro[linha][coluna];
	  }
	      cout << "\n";
	    }
		
	}
	
	
	
}

void posicionaBarcos(char tabuleiro[10][10]){
	
	//coloca 10 barcos no ta
	int i;
	
	int quantidade = 10,quantidadePosicionada = 0;
	
	//verifica se ja posicionou todos os barcos
	while(quantidadePosicionada < quantidade){
		
		int linhaBarco = rand() % 10;    //gera numero aleatorio de 0 a 9
		int colunaBarco = rand() % 10;   //gera numero aleatorio de 0 a 9
		
		if(tabuleiro[linhaBarco][colunaBarco] == 'A'){
				
			tabuleiro[linhaBarco][colunaBarco] = 'B';
			
			quantidadePosicionada++;
			
			//aumenta o contador de barcos
		}
			
	}
	
}


void verificaTiro(char tabuleiro[10][10], int linhaJogada, int colunaJogada, int *pontos, string *mensagem){
	
     
	
	//verifica quantos pontos adicionar
	switch(tabuleiro[linhaJogada][colunaJogada]){
	    case 'B':
	       *pontos = *pontos + 10;
	       *mensagem = "\n    Acertou o barco! (10 pts)";
	        break;
	    case 'A':
	    	*mensagem= "\n   Tiro na agua! ";
		     break;
	}
	/*for(linhaJogada = 0;linhaJogada < tentativas(); linhaJogada++){
		for(colunaJogada = 0; linhaJogada < tentativas(); colunaJogada++){
			
			//Ao encontrar a letra
			if(tabuleiro[linhaJogada][colunaJogada] == (linhaJogada) &&(colunaJogada)){
				
				*mensagem = "Deixa de ser lesado!\n";
				
				//Indica uma variavel booleana
				jaFoi = true;
			}
		}*/
	
}

void jogo(string nomeDoJogador){
	
	char normal[] = { 0x1b, '[', '1', ';', '3', '9', 'm', 0 };
	char marinho[] = { 0x1b, '[', '1', ';', '3', '6', 'm', 0 };
	char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
	char red[] = { 0x1b, '[', '1', ';', '3', '1', 'm', 0 };
    char yellow[] = { 0x1b, '[', '1', ';', '3', '3', 'm', 0 };
    char blue[] = { 0x1b, '[', '1', ';', '3', '0', 'm', 0 };
    
	///variaveis reais
	char tabuleiro[10][10],mascara[10][10];               //Tabuleiro do jogo
	int linha,coluna;                                     //Auxiliares da navega��o
	int linhaJogada,colunaJogada;                         //posi��o exibe pelo jogador
	int estadoDeJogo = 1;                                 //1 = jogo iniciado ; jogo encerramdo
	int pontos = 0;                                       //pontua��o do jogador
	int opcao;                                            //op�oes de fim de jogo
	int tentativas = 0, maximoDeTentativas = 20;
	string mensagem ="\nBoa sorte Almirante";              //Mensagem de feedback para jogador
	bool jaFoi = false;
	
    iniciaTabuleiro(tabuleiro,mascara);
    
    //posiciona barcos aleatoriamente
    posicionaBarcos(tabuleiro);
    
    while(tentativas < maximoDeTentativas){
    
	limpaTela();
	//exibe o mapa de indica��es
	exibeMapa();
		
	exibeTabuleiro(tabuleiro,mascara , false);
	
	cout << mensagem;
	cout << "\n\nTentativas restantes: " << maximoDeTentativas - tentativas;
	cout << "\nPontos:" << pontos;
		
		
	//verifica��o de dados
	linhaJogada = -1;
	colunaJogada = -1;
	
	while(    (linhaJogada < 0 || colunaJogada < 0)  || (linhaJogada > 9 || colunaJogada > 9) ){
	cout << "\n"<< nomeDoJogador <<"\nDigite a posicao da linha:";
    cin >> linhaJogada;
	cout << "\n" << "\nDigite a posicao da coluna:";
    cin >> colunaJogada;
	}	
		
	
	
	//Verifica o que aconteceu
	verificaTiro(tabuleiro,linhaJogada,colunaJogada,&pontos, &mensagem);
	
	//revela o que esta no tabuleiro
	mascara[linhaJogada][colunaJogada] = tabuleiro[linhaJogada][colunaJogada];
	
	tentativas++;
	

	}
	
	
	
	cout << marinho << "\n   Voce eh a vergonha da profission , deseja se aventurar novamente?\n" << normal;
	cout << green << "\n   1 - BIRLLL!! Agora eu quebro esses barcos na porrada!\n" << normal;
	cout << yellow << "\n   2 - Voltar para o deck principal\n" << normal;
	cout << red << "\n   3 - Pode ter ganhado a batalha mas nao a guerra. Ate outro dia!\n\n" << normal;
	cout << blue <<"Opcao: " << normal;
	cin >> opcao;
	
	switch(opcao){
		case 1:
			jogo(nomeDoJogador);
			break;
		case 2:
			menuInicial();
		   break;
		case 3:
			cout << marinho << "\n    ------------------\n" << normal;
			cout << marinho << "    |Ate uma proxima!|" << normal;
			cout << marinho << "\n    ------------------\n\n";
		   break;   	
	}
	
	
}



void menuInicial(){
	//opcao escolhida pelo o usu�rio
    int opcao = 0;
    char red[] = { 0x1b, '[', '1', ';', '3', '1', 'm', 0 };
    char yellow[] = { 0x1b, '[', '1', ';', '3', '3', 'm', 0 };
    char marinho[] = { 0x1b, '[', '1', ';', '3', '6', 'm', 0 };
	char blue[] = { 0x1b, '[', '1', ';', '3', '0', 'm', 0 };
    char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
    char normal[] = { 0x1b, '[', '1', ';', '3', '9', 'm', 0 };
    
    string nomeDoJogador;
 	
 while(opcao < 1 || opcao > 3){
 	limpaTela();
 	cout << marinho << "          -----------------\n" << normal;
    cout << marinho <<"          |BATTLE ON WATER|\n" << normal;
	cout << marinho <<"          -----------------\n" << normal;
	cout << green << "\n 1 - jogar\n" << normal;
	cout << green << " ---------\n" << normal;	
    cout << yellow << "\n 2 - sobre\n" << normal;
    cout << yellow <<" ---------\n" << normal;
	cout << red <<"\n 3 - sair\n" << normal;
	cout << red <<" --------\n" << normal;
	cout << blue <<"\nEscolha uma opcao e tecle ENTER\n" << normal;
	cout << blue <<"Opcao: " << normal;
	cin >> opcao;
	//faz com
	switch(opcao){
		case 1:
			cout<< "\nQual o seu nome?\n";
			cin >> nomeDoJogador;
			jogo(nomeDoJogador);
		    //cout << "jogo iniciado\n";	
			break;
		
		case 2:
			limpaTela();
			cout << green << "\n                    INFORMACOES DO JOGO:\n\n" << normal;
			cout << green << "      -----------------------------------------------------\n" << normal;
			cout << green << "      |Aluno universitario de Sistemas e Midias Digitais. |\n" << normal;
			cout << green << "      |Desenvolvedor: Wallace Leite, since 2020.          |" << normal;
			cout << green << "\n      |Desenvolvido na linguagem C e C++.                 |" << normal;
			cout << green << "\n      |Estagiario da empresa CALANGO COMPUTERS.           |" << normal;
			cout << green << "\n      -----------------------------------------------------\n" << normal;
			cout << yellow << "\n\n   1 -> Voltar ao deck principal\n" << normal;
			cout << yellow << "   -----------------------------\n" << normal;
	        cout << red << "\n   2 -> Sair do jogo\n" << normal;
	        cout << red << "   -----------------\n\n" << normal;
	        cout << blue << "Opcao: " << normal;
			cin >> opcao;
            
            if(opcao == 2){
            cout << marinho << "\n       ------------------\n" << normal;
			cout << marinho << "       |Ate uma proxima!|" << normal;
			cout << marinho << "\n       ------------------\n\n";
			}else{
				menuInicial();
			}
			 
	        break;
	
		case 3:
			cout << marinho << "\n    ------------------\n" << normal;
			cout << marinho << "    |Ate uma proxima!|" << normal;
			cout << marinho << "\n    ------------------\n\n";
			break;		
	}
	        
	}
	
}

int main(){
	
	srand( (unsigned)time(NULL));
	
    menuInicial();
	 
	system("PAUSE");

	return 0;
}
