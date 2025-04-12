#include <stdio.h>

// Define o tamanho fixo do tabuleiro (10x10)
#define TAMANHO_TABULEIRO 10
// Define o tamanho fixo de cada navio (3 posições)
#define TAMANHO_NAVIO 3
// Define os valores de cada elemento no tabuleiro
#define AGUA 0
#define NAVIO 3

// Função responsável por preencher o tabuleiro com "água" (valor 0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Inicializando tabuleiro...\n");
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = AGUA;
        }
    }
    printf("Tabuleiro inicializado!\n\n");
}

// Função que verifica se o navio pode ser posicionado sem sair dos limites e sem sobrepor outro navio
int podePosicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int orientacao) {
    printf("Validando posição para navio %s em (%c, %d)...\n",
           (orientacao == 0) ? "Horizontal" : "Vertical",
           'A' + linha, coluna + 1);

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + (orientacao == 1 ? i : 0);  // Se for vertical, soma linha
        int c = coluna + (orientacao == 0 ? i : 0); // Se for horizontal, soma coluna

        // Validação: navio não pode ultrapassar o limite do tabuleiro
        if (l >= TAMANHO_TABULEIRO || c >= TAMANHO_TABULEIRO) {
            printf("Falha: Navio sairia dos limites do tabuleiro!\n");
            return 0; // Posição inválida
        }
        // Validação: navio não pode sobrepor outro navio já existente
        if (tabuleiro[l][c] == NAVIO) {
            printf("Falha: Sobreposição detectada na posição (%c, %d)!\n", 'A' + l, c + 1);
            return 0; // Posição inválida
        }
    }
    printf("Posição válida.\n");
    return 1; // Posição válida
}

// Função que posiciona o navio no tabuleiro, alterando as posições de AGUA para NAVIO
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int orientacao) {
    printf("Posicionando navio %s em (%c, %d)...\n",
           (orientacao == 0) ? "Horizontal" : "Vertical",
           'A' + linha, coluna + 1);

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + (orientacao == 1 ? i : 0);
        int c = coluna + (orientacao == 0 ? i : 0);
        tabuleiro[l][c] = NAVIO; // Marca no tabuleiro o valor que representa um navio
        printf("Posicionado parte do navio em (%c, %d).\n", 'A' + l, c + 1);
    }
    printf("Navio posicionado com sucesso!\n\n");
}

// Função para imprimir o tabuleiro formatado, com índices A-J (linhas) e 1-10 (colunas)
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n    ");
    // Cabeçalho das colunas com letras (A a J)
    for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
        printf(" %c ", 'A' + coluna);
    }
    printf("\n");

    // Loop para imprimir cada linha com número de 1 a 10
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        printf("%2d  ", linha + 1); // Mostra o índice da linha (1-10)
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%2d ", tabuleiro[linha][coluna]); // Exibe o conteúdo da célula
        }
        printf("\n");
    }
}

// Função principal do programa
int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Etapa 1: Inicializa o tabuleiro preenchendo com água
    inicializarTabuleiro(tabuleiro);

    // Coordenadas fixas para os navios
    int navioHorizontalLinha = 2, navioHorizontalColuna = 4;  // Navio Horizontal começando em C5
    int navioVerticalLinha = 5, navioVerticalColuna = 7;      // Navio Vertical começando em F8

    // Etapa 2: Validação e posicionamento do navio horizontal
    if (podePosicionarNavio(tabuleiro, navioHorizontalLinha, navioHorizontalColuna, 0)) {
        posicionarNavio(tabuleiro, navioHorizontalLinha, navioHorizontalColuna, 0);
    } else {
        printf("Erro: Não foi possível posicionar o navio horizontal!\n");
        return 1;
    }

    // Etapa 3: Validação e posicionamento do navio vertical
    if (podePosicionarNavio(tabuleiro, navioVerticalLinha, navioVerticalColuna, 1)) {
        posicionarNavio(tabuleiro, navioVerticalLinha, navioVerticalColuna, 1);
    } else {
        printf("Erro: Não foi possível posicionar o navio vertical!\n");
        return 1;
    }

    // Etapa 4: Exibir o tabuleiro final com os navios posicionados
    exibirTabuleiro(tabuleiro);

    return 0;
}
