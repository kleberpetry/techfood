aqui

#include <stdio.h>
#include <string.h>

#define produtosMax 100
#define nomeMax 50

// Estrutura para representar um produto consumido na cantina
typedef struct {
    char nome[nomeMax];
    float preco;
    int quantidade_vendida;
} ProdutoCantina;

// Função para buscar e exibir informações de um produto pelo nome
void buscarProduto(ProdutoCantina produtos[], int numProdutos, const char nomeBusca[]) {
    int i;
    for (i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].nome, nomeBusca) == 0) {
            printf("Produto encontrado na cantina:\n");
            printf("Nome: %s\n", produtos[i].nome);
            printf("Preço: R$ %.2f\n", produtos[i].preco);
            printf("Quantidade vendida: %d\n", produtos[i].quantidade_vendida);
            return; // Retorna após encontrar o produto
        }
    }
    printf("Produto com o nome '%s' não encontrado na cantina.\n", nomeBusca);
}

int main() {
    // Lista de produtos na cantina
    ProdutoCantina listaProdutos[produtosMax] = {
        {"Salgado", 5.50, 120},
        {"Refrigerante", 3.00, 180},
        {"Café", 2.50, 90},
        {"Bolo", 7.00, 60},
        {"Pipoca", 4.00, 150},
        {"Água", 2.50, 150},
        {"Gelatina", 3.00, 120},
        {"Sanduíche", 5.00, 180},
        {"Salada de Frutas", 7.00, 150},
        {"Chocolate", 4.50, 130},
        {"Paçoca", 2.50, 110},
        {"Iogurte", 4.00, 80},
        {"Energético", 6.00, 95}
    };

    int numProdutos = 13; // Número atual de produtos na lista da cantina

    // Solicita ao usuário o nome do produto que deseja buscar
    char nomePesquisa[nomeMax];
    printf("Digite o nome do produto que deseja buscar na cantina: ");
    fgets(nomePesquisa, sizeof(nomePesquisa), stdin);
    nomePesquisa[strcspn(nomePesquisa, "\n")] = '\0'; // Remove o \n do final de fgets

    // Chama a função para buscar e exibir informações do produto
    buscarProduto(listaProdutos, numProdutos, nomePesquisa);

    return 0;
}


