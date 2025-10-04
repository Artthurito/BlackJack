#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <windows.h>

// Fazer um BlackJack Jogável

// Função de Geração de cartas
// Função de Checagem de cartas, para não ter repetida
// Função de Soma das cartas para verificar o maior
// Função de Limite 21
// Função "Até 17" do Dealer

// Gerar 2 Cartas para o Dealer - 1 "Encoberta"
// Gerar 2 Cartas para o Jogador
// Hit - Stand
// Jogador vai pedindo cartas, até dizer pare ou estourar
// Vê quem fez o maior valor

struct cartas{
	int valor;
	char naipe;	
};

void criar_baralho(struct cartas baralho[]);
void embaralhar(struct cartas baralho[]);
int valor_jogo(struct cartas carta_mao);
int calcular_pontuacao(struct cartas mao[], int num_cartas);
void imprimir_carta(struct cartas uma_carta);

int main(){
	SetConsoleOutputCP(CP_UTF8);
	setlocale(LC_ALL, "");
	srand(time(NULL));
	
    int i, escolha=0, pontuacaoJogador=0, pontuacaoDealer=0, cartaAtual = 0, cartasJogador = 0, cartasDealer = 0;
	struct cartas carta[52];
	struct cartas maoJogador[11];
	struct cartas maoDealer[11];
	
	criar_baralho(carta);
	embaralhar(carta);
	
	for(i=0;i<2;i++){
		maoJogador[cartasJogador] = carta[cartaAtual];
		cartaAtual++;
		cartasJogador++;
		maoDealer[cartasDealer] = carta[cartaAtual];
		cartaAtual++;
		cartasDealer++;
	}
	do {
	    pontuacaoJogador = calcular_pontuacao(maoJogador, cartasJogador);
	    printf("\n----------------\n");
	    printf("Sua mao: ");
	    for (i=0; i < cartasJogador; i++) {
	        imprimir_carta(maoJogador[i]);
	    }
	    printf("  (Pontuacao: %d)\n", pontuacaoJogador);
	
	    printf("Mao do Dealer: ");
	    imprimir_carta(maoDealer[0]);
	    printf("\n");
	
	    if (pontuacaoJogador > 21) {
	        printf("Voce estourou!\n");
	        break;
	    }
	
	    printf("\nDigite 1 para Comprar (Hit)\nDigite 2 para Parar (Stand)\n");
	    scanf("%d", &escolha);
		fflush(stdin);
		
	    if (escolha == 1) {
	        maoJogador[cartasJogador] = carta[cartaAtual];
	        cartaAtual++;
	        cartasJogador++;
	    }
	} while (escolha == 1);
	printf("\n----------------\n");
	printf("Turno do Dealer:\n");

	pontuacaoDealer = calcular_pontuacao(maoDealer, cartasDealer);
	printf("Dealer revelando: ");
	for (i=0; i < cartasDealer; i++) {
	    imprimir_carta(maoDealer[i]);
	}
	printf("  (Pontuacao: %d)\n", pontuacaoDealer);
	
	while (pontuacaoDealer < 17) {
	    printf("\nDealer compra mais uma carta...\n");
	    system("pause");
	    printf("\n");
	    maoDealer[cartasDealer] = carta[cartaAtual];
	    cartaAtual++;
	    cartasDealer++;
	    pontuacaoDealer = calcular_pontuacao(maoDealer, cartasDealer);
	
	    printf("Nova mao do Dealer: ");
	    for (i=0; i < cartasDealer; i++) {
	        imprimir_carta(maoDealer[i]);
	    }
	    printf("  (Pontuacao: %d)\n", pontuacaoDealer);
	}
	printf("\n---------- FIM DE JOGO ----------\n");
	printf("Sua pontuacao final: %d\n", pontuacaoJogador);
	printf("Pontuacao final do Dealer: %d\n", pontuacaoDealer);
	printf("---------------------------------\n");
	if (pontuacaoJogador > 21) {
	    printf("Voce estourou! O Dealer vence.\n");
	} else if (pontuacaoDealer > 21) {
	    printf("O Dealer estourou! Voce vence!\n");
	}
	else if (pontuacaoJogador > pontuacaoDealer) {
	    printf("Parabens, Voce ganhou do Evil Dealer!\n");
	} else if (pontuacaoDealer > pontuacaoJogador) {
	    printf("O Evil Dealer tem a maior pontuacao, Voce Perde...\n");
	}
	else {
	    printf("Empate! (Push)\n");
	}
	return 0;
}
void criar_baralho(struct cartas baralho[]){
//    char espadas_char = '\u2660';
//    char copas_char   = '\u2665';
//    char ouros_char   = '\u2666';
//    char paus_char    = '\u2663';
	char espadas_char = 'E';
    char copas_char   = 'C';
    char ouros_char   = 'O';
    char paus_char    = 'P';
    int contador = 0;
    for (int i = 1; i <= 13; i++) {
        for (int j = 1; j <= 4; j++) {
			baralho[contador].valor = i;
            switch(j){
            	case 1:
            		baralho[contador].naipe = espadas_char;
            		break;
            	case 2:
            		baralho[contador].naipe = copas_char;
            		break;
            	case 3:
            		baralho[contador].naipe = ouros_char;
            		break;
            	case 4:
            		baralho[contador].naipe = paus_char;
            		break;
			}
            contador++;
        }
    }
}

void embaralhar(struct cartas baralho[]){
    int i;
    for (i = 51; i > 0; i--) {
        int j = rand() % (i + 1);
        struct cartas temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

int valor_jogo(struct cartas carta_mao){
	int valor=0;
   if (carta_mao.valor==1){
   		return 1;
   }
   if (carta_mao.valor>10){
   		return 10;
	}
		return carta_mao.valor;
}

int calcular_pontuacao(struct cartas mao[], int num_cartas){
	int pontuacao=0, i, asses=0;
	for(i=0;i<num_cartas;i++){
		pontuacao += valor_jogo(mao[i]);
		if (mao[i].valor == 1){
			asses++;
		}
	}
	if(asses>0 && pontuacao<=11){
		pontuacao += 10;
	}
	return pontuacao;
}

void imprimir_carta(struct cartas carta_mao) {
    switch(carta_mao.valor) {
        case 1:  printf("A"); break;
        case 11: printf("J"); break;
        case 12: printf("Q"); break;
        case 13: printf("K"); break;
        default: printf("%d", carta_mao.valor);
    }
    printf("%c ", carta_mao.naipe);
}
