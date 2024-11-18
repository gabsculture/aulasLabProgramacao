#include <stdio.h>
#include <stdbool.h>
#include "terminal.h"
#include <time.h>

// Função para desenhar o tabuleiro
void desenha_tabuleiro(int tamanho, char tabuleiro[], int linha_destaque, int coluna_destaque, int estado) {
    // Cores de fundo alternadas
    int cor_fundo_clara[] = {220, 220, 220}; // Cinza claro
    int cor_fundo_escura[] = {100, 100, 100}; // Cinza escuro
    int cor_destaque[] = {0, 255, 0};        // Verde (posição em destaque)

    // Cores da borda do tabuleiro para representar o estado
    int cor_borda_ok[] = {0, 255, 0};        // Verde (tabuleiro válido)
    int cor_borda_alerta[] = {255, 255, 0};  // Amarelo (aviso)
    int cor_borda_erro[] = {255, 0, 0};      // Vermelho (tabuleiro inválido)

    // Escolhe a cor da borda com base no estado
    int *cor_borda;
    if (estado == 1) {
        cor_borda = cor_borda_ok;
    } else if (estado == 2) {
        cor_borda = cor_borda_alerta;
    } else {
        cor_borda = cor_borda_erro;
    }

    // Limpa o terminal antes de desenhar
    t_limpa();

    // Desenha a borda
    for (int i = 0; i < tamanho + 2; i++) {
        for (int j = 0; j < tamanho + 2; j++) {
            if (i == 0 || i == tamanho + 1 || j == 0 || j == tamanho + 1) {
                t_cor_fundo(cor_borda[0], cor_borda[1], cor_borda[2]);
            } else {
                t_cor_fundo(0, 0, 0); // Fundo preto para área dentro do tabuleiro
            }
            t_lincol(i, j * 2); // Espaçamento horizontal ajustado para visualização
            printf("  ");
        }
    }

    // Desenha as células do tabuleiro
    for (int linha = 1; linha <= tamanho; linha++) {
        for (int coluna = 1; coluna <= tamanho; coluna++) {
            // Determina a cor de fundo
            int *cor_atual;
            if (linha == linha_destaque && coluna == coluna_destaque) {
                cor_atual = cor_destaque; // Destaque para posição selecionada
            } else if ((linha + coluna) % 2 == 0) {
                cor_atual = cor_fundo_clara;
            } else {
                cor_atual = cor_fundo_escura;
            }

            // Define a cor de fundo
            t_cor_fundo(cor_atual[0], cor_atual[1], cor_atual[2]);

            // Move o cursor e imprime a célula
            t_lincol(linha, coluna * 2);
            printf(" %c", tabuleiro[(linha - 1) * tamanho + (coluna - 1)]);
        }
    }

    // Restaura a cor normal e atualiza o terminal
    t_cor_normal();
    t_atualiza();
}

bool processa_entrada(char tabuleiro[], int tamanho, int *linha_cursor, int *coluna_cursor) {
    if (!t_tem_tecla()) {
        return false; 
    }

    char tecla = t_tecla();

    ```c
    if (tecla == 'w' && *linha_cursor > 1) {
        (*linha_cursor)--;
    } else if (tecla == 's' && *linha_cursor < tamanho) {
        (*linha_cursor)++;
    } else if (tecla == 'a' && *coluna_cursor > 1) {
        (*coluna_cursor)--;
    } else if (tecla == 'd' && *coluna_cursor < tamanho) {
        (*coluna_cursor)++;
    } else if (tecla == '\n' || tecla == ' ') {
        int index = ((*linha_cursor - 1) * tamanho) + (*coluna_cursor - 1);
        if (tabuleiro[index] == 'x') {
            tabuleiro[index] = '.'; 
        } else {
            tabuleiro[index] = 'x'; 
        }
    } else if (tecla == 'x') {
        return true; 
    }

    return false; 
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

    // Verifica diagonais da esquerda para a direita
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

    // Verifica diagonais da direita para a esquerda
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

int recebeNumeroRainhas() {
    int numeroRainhas;
    do {
        printf("Insira o número de rainhas (maior que 0): ");
        scanf("%d", &numeroRainhas);
        if (numeroRainhas <= 0) {
            printf("Número de rainhas deve ser maior que 0.\n");
        }
    } while (numeroRainhas <= 0);
    return numeroRainhas;
}

void zeraTabuleiro(char tabuleiro[], int tamanho) {
    for (int i = 0; i < tamanho * tamanho; i++) {
        tabuleiro[i] = '.'; 
    }
}

int main() {
    t_inicializa();

    int numeroRainhas = recebeNumeroRainhas();
    int tamanhoTabuleiro = numeroRainhas * numeroRainhas;
    char tabuleiro[tamanhoTabuleiro];
    int linha_cursor = 1, coluna_cursor = 1; 
    int estado = 1; 
    bool sair = false;
    bool venceu = false;

    zeraTabuleiro(tabuleiro, numeroRainhas);

    clock_t inicio = clock();

    while (!sair) {
 desenha_tabuleiro(numeroRainhas, tabuleiro, linha_cursor, coluna_cursor, 0);
        sair = processa_entrada(tabuleiro, numeroRainhas, &linha_cursor, &coluna_cursor);
        if (verificaTabuleiro(numeroRainhas, tamanhoTabuleiro, tabuleiro)) {
            venceu = true;
            sair = true; 
        }
    }

    if (venceu) {
        clock_t fim = clock();
        double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("\nParabéns! Você completou o desafio em %.2f segundos.\n", tempo);
    } else {
        printf("\nPrograma encerrado pelo usuário.\n");
    }

    getchar();
    t_finaliza();
    return 0;
}
