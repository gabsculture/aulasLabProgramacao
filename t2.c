//l1-t2 gabriela vitoria da rosa soares
#include <stdbool.h>
#include "terminal.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void desenha_tabuleiro(int tamanho, char tabuleiro[], int linha_destaque, int coluna_destaque) {
    int cor_fundo_clara[] = {220, 220, 220};
    int cor_fundo_escura[] = {100, 100, 100};
    int cor_destaque[] = {0, 255, 0};

    for (int linha = 1; linha <= tamanho; linha++) {
        for (int coluna = 1; coluna <= tamanho; coluna++) {
            int *cor_atual;
            if (linha == linha_destaque && coluna == coluna_destaque) {
                cor_atual = cor_destaque;
            } else if ((linha + coluna) % 2 == 0) {
                cor_atual = cor_fundo_clara;
            } else {
                cor_atual = cor_fundo_escura;
            }

            t_cor_fundo(cor_atual[0], cor_atual[1], cor_atual[2]);
            printf(" %c", tabuleiro[(linha - 1) * tamanho + (coluna - 1)]);
        }
        printf("\n");
    }
    t_cor_normal();
    t_atualiza();
}


bool processa_entrada(char tabuleiro[], int tamanho, int *linha_cursor, int *coluna_cursor, int *contadorRainhas,
                      bool *validando) {
    int nlin, ncol;
    t_tamanho(&nlin, &ncol);
    if (t_tem_tecla()) {
        char tecla = t_tecla();

        switch (tecla) {
            case 'w':
                if (*linha_cursor > 1) (*linha_cursor)--;
                break;
            case 's':
                if (*linha_cursor < nlin - 1) (*linha_cursor)++;
                break;
            case 'a':
                if (*coluna_cursor > 1) (*coluna_cursor)--;
                break;
            case 'd':
                if (*coluna_cursor < ncol - 1) (*coluna_cursor)++;
                break;
            case ' ':
            case '\n': {
                int index = ((*linha_cursor - 1) * tamanho) + (*coluna_cursor - 1);
                if (tabuleiro[index] == '.') {
                    tabuleiro[index] = 'x';
                    t_atualiza();
                } else if (tabuleiro[index] == 'x') {

                    tabuleiro[index] = '.';
                    t_atualiza();
                }
                *contadorRainhas = 0;
                for (int i = 0; i < tamanho * tamanho; i++) {
                    if (tabuleiro[i] == 'x') {
                        (*contadorRainhas)++;
                    }

                }
                if (*contadorRainhas == tamanho) {
                    *validando = true;
                }
                break;
            case 'x':
                return true;
            }
        }

        return false;
    }
}

bool verificaLinhas(int tamanhoTabuleiro, int numero, char tabuleiro[]) {
    int numeroRainhas;
    for (int i = 0; i < tamanhoTabuleiro; i += numero) {
        numeroRainhas = 0;
        for (int j = i; j < i + numero && j < tamanhoTabuleiro; j++) {
            if (tabuleiro[j] == 'x') {
                numeroRainhas++;
            }
        }
        if (numeroRainhas > 1) {
            return false;
        }
    }
    return true;
}

bool verificaColunas(int tamanhoTabuleiro, int numero, char tabuleiro[]) {
    int numeroRainhas;
    for (int coluna = 0; coluna < numero; coluna++) {
        numeroRainhas = 0;
        for (int j = coluna; j < tamanhoTabuleiro; j += numero) {
            if (tabuleiro[j] == 'x') {
                numeroRainhas++;
            }
        }
        if (numeroRainhas > 1) {
            return false;
        }
    }
    return true;
}

bool verificaDiagonal(int tamanhoTabuleiro, int numero, char tabuleiro[]) {
    int numeroRainhas;

    for (int i = 0; i < tamanhoTabuleiro; i++) {
        numeroRainhas = 0;
        for (int posicaoInicial = i; posicaoInicial < tamanhoTabuleiro; posicaoInicial += numero + 1) {
            if (posicaoInicial < tamanhoTabuleiro && tabuleiro[posicaoInicial] == 'x') {
                numeroRainhas++;
            }
        }
        if (numeroRainhas > 1) {
            return false;
        }
    }

    for (int j = 0; j < tamanhoTabuleiro; j++) {
        numeroRainhas = 0;
        for (int posicaoInicial = j; posicaoInicial < tamanhoTabuleiro; posicaoInicial += numero - 1) {
            if (posicaoInicial < tamanhoTabuleiro && tabuleiro[posicaoInicial] == 'x') {
                numeroRainhas++;
            }
        }
        if (numeroRainhas > 1) {
            return false;
        }
    }

    return true;
}

bool verificaTabuleiro(int numero, int tamanhoTabuleiro, char tabuleiro[]) {
    return verificaLinhas(tamanhoTabuleiro, numero, tabuleiro) &&
           verificaColunas(tamanhoTabuleiro, numero, tabuleiro) &&
           verificaDiagonal(tamanhoTabuleiro, numero, tabuleiro);
}

bool verificaQuantidadeRainhas(int numero, char tabuleiro[]) {
    int contadorRainhas = 0;
    for (int i = 0; i < numero * numero; i++) {
        if (tabuleiro[i] == 'x') {
            contadorRainhas++;
        }
    }
    if (contadorRainhas < numero) {
        return false;
    }
    return true;
}

int recebeNumeroRainhas() {
    int numeroRainhas;
    printf("Insira o número de rainhas (maior que 0):\n ");
    scanf("%d", &numeroRainhas);
    return numeroRainhas;
}

char *inicializaTabuleiro(int tamanhoTabuleiro) {
    char *tabuleiro = (char *) malloc(tamanhoTabuleiro * sizeof(char));

    if (tabuleiro == NULL) {
        printf("Erro: Não foi possível alocar memória para o tabuleiro.\n");
        return NULL;
    }

    for (int i = 0; i < tamanhoTabuleiro; i++) {
        tabuleiro[i] = '.';
    }

    return tabuleiro;
}

int main() {
    bool fim = false;
    int nlin, ncol;
    int linha_destaque, coluna_destaque;
    int linha_cursor = 1, coluna_cursor = 1;
    double ultima_mexida;


    linha_destaque = 2 + rand() % (nlin - 4);
    coluna_destaque = 2 + rand() % (ncol - 4);


    int numeroRainhas = recebeNumeroRainhas();
    int tamanhoTabuleiro = numeroRainhas * numeroRainhas;
    char *tabuleiro = inicializaTabuleiro(tamanhoTabuleiro);
    int contadorRainhas = 0;
    bool validando = false;

    t_inicializa();

    t_tamanho(&nlin, &ncol);
    ultima_mexida = t_relogio();

    if (tabuleiro == NULL) {
        t_finaliza();
        return 1;
    }

    desenha_tabuleiro(numeroRainhas, tabuleiro, linha_cursor, coluna_cursor);

    while (!fim) {
        fim = processa_entrada(tabuleiro, numeroRainhas, &linha_cursor, &coluna_cursor, &contadorRainhas, &validando);

        if (t_relogio() - ultima_mexida >= 8.2) {
            linha_destaque = 2 + rand() % (nlin - 4);
            coluna_destaque = 2 + rand() % (ncol - 4);
            ultima_mexida = t_relogio(); // Atualiza o tempo da última mudança
        }

        if (validando) {
            if (contadorRainhas == numeroRainhas) {
                if (verificaTabuleiro(numeroRainhas, tamanhoTabuleiro, tabuleiro)) {
                    printf("\nParabéns! Você completou o desafio!\n");
                }
            } else {
                printf("\nTabuleiro inválido!\n");
            }
            break;
        }
    }

    if (!validando) {
        printf("\nPrograma encerrado pelo usuário.\n");
    }
    t_finaliza();

    free(tabuleiro);

    return 0;
}
