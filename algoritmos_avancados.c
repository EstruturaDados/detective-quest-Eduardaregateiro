#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Desafio Detective Quest
// Tema 4 - Árvores e Tabela Hash
// Este código inicial serve como base para o desenvolvimento das estruturas de navegação, pistas e suspeitos.
// Use as instruções de cada região para desenvolver o sistema completo com árvore binária, árvore de busca e tabela hash.


// Struct que representa uma sala da mansão
typedef struct Sala {
    char nome[50];          // nome da sala
    struct Sala *esquerda;  // ponteiro para sala à esquerda
    struct Sala *direita;   // ponteiro para sala à direita
} Sala;

// Função criarSala()
// Cria dinamicamente uma sala com nome e retorna o ponteiro
Sala* criarSala(const char* nome) {
    Sala* nova = (Sala*) malloc(sizeof(Sala));
    if (nova == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

// Função conectarSalas()
// Conecta uma sala principal às suas salas filhas (esquerda e direita)
void conectarSalas(Sala* principal, Sala* esquerda, Sala* direita) {
    principal->esquerda = esquerda;
    principal->direita = direita;
}

// Função explorarSalas()
// Permite navegação interativa pela árvore binária
void explorarSalas(Sala* atual) {
    char escolha;

    while (atual != NULL) {
        printf("\nVocê está em: %s\n", atual->nome);

        // Se não há caminhos, é um nó-folha
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Fim da exploração! Você chegou a um cômodo sem saídas.\n");
            break;
        }

        printf("Escolha um caminho:\n");
        if (atual->esquerda != NULL) printf("e - Ir para %s\n", atual->esquerda->nome);
        if (atual->direita != NULL) printf("d - Ir para %s\n", atual->direita->nome);
        printf("s - Sair da exploração\n");
        printf("Opção: ");
        scanf(" %c", &escolha);

        if (escolha == 'e' && atual->esquerda != NULL) {
            atual = atual->esquerda;
        } else if (escolha == 'd' && atual->direita != NULL) {
            atual = atual->direita;
        } else if (escolha == 's') {
            printf("Exploração encerrada pelo jogador.\n");
            break;
        } else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }
}

// Função main()
// Monta o mapa da mansão e inicia a exploração
int main() {
    // Criando salas da mansão
    Sala* hall = criarSala("Hall de Entrada");
    Sala* biblioteca = criarSala("Biblioteca");
    Sala* cozinha = criarSala("Cozinha");
    Sala* sotao = criarSala("Sótão");
    Sala* jardim = criarSala("Jardim");

    // Montando a árvore binária (mapa da mansão)
    conectarSalas(hall, biblioteca, cozinha);
    conectarSalas(biblioteca, sotao, jardim);

    // Iniciando exploração
    printf("Bem-vindo ao Detective Quest!\n");
    explorarSalas(hall);

    // Liberação da memória (boa prática)
    free(hall);
    free(biblioteca);
    free(cozinha);
    free(sotao);
    free(jardim);

    // 🌱 Nível Novato: Mapa da Mansão com Árvore Binária
    //
    // - Crie uma struct Sala com nome, e dois ponteiros: esquerda e direita.
    // - Use funções como criarSala(), conectarSalas() e explorarSalas().
    // - A árvore pode ser fixa: Hall de Entrada, Biblioteca, Cozinha, Sótão etc.
    // - O jogador deve poder explorar indo à esquerda (e) ou à direita (d).
    // - Finalize a exploração com uma opção de saída (s).
    // - Exiba o nome da sala a cada movimento.
    // - Use recursão ou laços para caminhar pela árvore.
    // - Nenhuma inserção dinâmica é necessária neste nível.

    // 🔍 Nível Aventureiro: Armazenamento de Pistas com Árvore de Busca
    //
    // - Crie uma struct Pista com campo texto (string).
    // - Crie uma árvore binária de busca (BST) para inserir as pistas coletadas.
    // - Ao visitar salas específicas, adicione pistas automaticamente com inserirBST().
    // - Implemente uma função para exibir as pistas em ordem alfabética (emOrdem()).
    // - Utilize alocação dinâmica e comparação de strings (strcmp) para organizar.
    // - Não precisa remover ou balancear a árvore.
    // - Use funções para modularizar: inserirPista(), listarPistas().
    // - A árvore de pistas deve ser exibida quando o jogador quiser revisar evidências.

    // 🧠 Nível Mestre: Relacionamento de Pistas com Suspeitos via Hash
    //
    // - Crie uma struct Suspeito contendo nome e lista de pistas associadas.
    // - Crie uma tabela hash (ex: array de ponteiros para listas encadeadas).
    // - A chave pode ser o nome do suspeito ou derivada das pistas.
    // - Implemente uma função inserirHash(pista, suspeito) para registrar relações.
    // - Crie uma função para mostrar todos os suspeitos e suas respectivas pistas.
    // - Adicione um contador para saber qual suspeito foi mais citado.
    // - Exiba ao final o “suspeito mais provável” baseado nas pistas coletadas.
    // - Para hashing simples, pode usar soma dos valores ASCII do nome ou primeira letra.
    // - Em caso de colisão, use lista encadeada para tratar.
    // - Modularize com funções como inicializarHash(), buscarSuspeito(), listarAssociacoes().

    return 0;
}