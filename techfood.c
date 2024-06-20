#include <stdio.h>
#include <locale.h>
#include <string.h>

//Função para realizar a venda de produtos
venderprodutos(produto produtos[]) {

	system("cls");
	printf(">>> VENDER PRODUTO <<<\n\n");
	
	char produto[30];
	int quantidade, i;
	
	printf("Produto: ");
	fflush(stdin);
	gets(produto);
	for(i = 0; i < count; {
		if(strcmp(produto, produtos[i].nomes) == 0) {	//Verifica se o produto exite (se foi cadastrado)
			do {
				system("cls");
				printf(">>> VENDER PRODUTO <<<\n\n");
				printf("Produto: %s\n", produto);
			
				printf("Quantidade: ");
				scanf("%d", &quantidade);
				if(quantidade <= produtos[i].estoques){	//Verifica se a quantidade não é superior à disponível no estoque
					produtos[i].estoques -= quantidade;
					produtos[i].vendas += quantidade;
					break;
				} else {
					printf("\nQuantidade superior ao estoque.\n\n");
					system("pause");
				}
			} while(1);
		} else {
			printf("Produto não cadastrado.\n\n");
			break;
		}
	}
	
	printf("\nVenda concluída!\n\n");
	system("pause");
}

//Função para listar as vendas de produtos
listarvendas(produto produtos[]) {
	system("cls");
	printf(">>> LISTAR VENDAS <<<\n\n");
	
	int i;
	
	for(i = 0; i < count; i++) {
		if(produtos[i].vendas != 0){	//Verifica se o produto teve alguma venda, se sim, imprime os dados
			double valor = produtos[i].vendas * produtos[i].precos;
			
			printf("Nome: %s", produtos[i].nomes);
			printf("\nCódigo: %d", produtos[i].codigos);
			printf("\nPreço: R$ %.2lf", produtos[i].precos);
			printf("\nQuantidade vendida: %d", produtos[i].vendas);
			printf("\nQuantidade em estoque: %d", produtos[i].estoques);
			printf("\nValor total de venda: R$ %.2lf\n\n", valor);
		}
	}
	
	system("pause");
}
