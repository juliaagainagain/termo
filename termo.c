#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 5
#define MAX_TENTATIVAS 6

void analisar_tentativa(char tentativa[], char palavra_secreta[]) {
    int marcadas_palavra[5] = {0}; 
    int marcadas_tentativa[5] = {0};
    char resultado[6] = {0};

    //letras corretas no lugar certo
    for (int i = 0; i < TAM; i++) {
        if (tentativa[i] == palavra_secreta[i]) {
            resultado[i] = 'G';
            marcadas_palavra[i] = 1;
            marcadas_tentativa[i] = 1;
        }
    }

    //letras certas no lugar errado
    for (int i = 0; i < TAM; i++) {
        if (!marcadas_tentativa[i]) {
            for (int j = 0; j < TAM; j++) {
                if (!marcadas_palavra[j] && tentativa[i] == palavra_secreta[j]) {
                    resultado[i] = 'Y';
                    marcadas_palavra[j] = 1;
                    marcadas_tentativa[i] = 1;
                    break;
                }
            }
        }
    }

    //erradas
    for (int i = 0; i < TAM; i++) {
        if (!marcadas_tentativa[i]) {
            resultado[i] = 'B';
        }
    }
    
    for (int i = 0; i < TAM; i++) {
        if (resultado[i] == 'G') printf("[ V ]");
        else if (resultado[i] == 'Y') printf("[ - ]");
        else printf("[   ]");
    }
    printf("\n");
}

int main() {
    char palavra_secreta[TAM + 1] = "LIVRO";
    char tentativa[100];
    int tentativas = 0;
    int acertou = 0;

     printf("Bem-vindo ao Termo!\n");
     printf("\n CODIGOS: \n");
     printf(" [ - ] -> existe, esta no lugar errado\n [   ] -> nao existe \n [ V ] -> lugar certo \n \n");
    
    while (tentativas < MAX_TENTATIVAS && !acertou) {
        printf("Tentativa %d: ", tentativas + 1);
        scanf("%s", tentativa);

        if (strlen(tentativa) != TAM) {
            printf("A palavra deve ter exatamente 5 letras.\n");
            continue;
        }

        for (int i = 0; i < TAM; i++) {
            tentativa[i] = toupper(tentativa[i]);
        }

        analisar_tentativa(tentativa, palavra_secreta);
        tentativas++;

        if (strcmp(tentativa, palavra_secreta) == 0) {
            printf("Parabens! Voce acertou! =D\n");
            acertou = 1;
        }
    }

    if (!acertou) {
        printf("Fim de jogo! A palavra era: %s\n", palavra_secreta);
    }

    return 0;
}

