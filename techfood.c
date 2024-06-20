aqui
#include<stdio.h>
#include<string.h>
#include<locale.h>


typedef struct{
 double precos;
 int estoques;
 int codigos;
 char nomes[30];
 int vendas	
	
}produto;

//1- funcao de cadastro
cadastrarProdutos(produto produtos[],int count){
	system("cls");
	produtos[count].codigos=count+1;
	printf("\nDigite o nome do produto: ");
	fflushin(stdin);
	gets(produtos[count].nomes);
	printf("\nDigite a quantidade de produtos: ");
	scanf("%d",&produtos[count].estoques);
	produtos[count].estoques=produtos[count].estoques;
	fflushin(stdin);
	printf("\nDigite o valor do produto: ");
	scanf("%d",produtos[count].precos);
	
	
}

//2 funcao de listar
 listarProdutos(produto produtos[],int count){
	int x;
	for(x=0;x<count;x++){
		printf("\nPrecos: lf",produtos[x].precos);
		printf("\nEstoque: %d",produtos[x].estoques);
		printf("\nCodigo: %d",produtos[x].codigos);
		printf("\nNome: %s",produtos[x].nomes);
		printf("\nVendido: %d",produtos[x].vendas);
		
	}
	system("pause");
}
