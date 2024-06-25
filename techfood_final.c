#include<stdio.h>
#include<string.h>
#include<locale.h>


typedef struct{
 double precos;
 int estoques;
 int codigos;
 char nomes[30];
 int vendas;	
	
} produto;

int count = 0;

//1- funcao de cadastro
void cadastrarProdutos(produto produtos[]){
	system("cls");
	printf(">>> CADASTRAR PRODUTO <<<\n");
	
	produtos[count].codigos=count+1;
	
	printf("\nDigite o nome do produto: ");
	fflush(stdin);
	gets(produtos[count].nomes);
	printf("Digite a quantidade de produtos: ");
	scanf("%d",&produtos[count].estoques);
	produtos[count].estoques=produtos[count].estoques;
	fflush(stdin);
	printf("Digite o valor do produto: ");
	scanf("%lf",&produtos[count].precos);
	produtos[count].vendas = 0; 
	
	printf("\nProduto cadastrado com sucesso!\n\n");
	system("pause");
}

//2 funcao de listar
void listarProdutos(produto produtos[]){
	int x;
	
	system("cls");
	printf(">>> LISTAR PRODUTOS <<<\n");
	
	for(x=0;x<count;x++){
		printf("\nNome: %s",produtos[x].nomes);
		printf("\nCodigo: %d",produtos[x].codigos);
		printf("\nPrecos: %.2lf",produtos[x].precos);
		printf("\nEstoque: %d",produtos[x].estoques);	
		printf("\nVendido: %d\n\n",produtos[x].vendas);	
	}
	
	system("pause");
}
//3 funcao de Atualizar
void atualizarProdutos(produto produtos[]){
	char nomes;
	int x, codigos, novoEstoques, diferencaEstoques;
	double novoPreco, diferencaPreco;
	
	system("cls");
	printf(">>> ATUALIZAR PRODUTO <<<\n");
	
	do{
		printf("\nDigite o código do produto que você deseja editar: ");
		scanf("%d",&codigos);
	} while(codigos < 1 || codigos > count);
	
	int index = codigos - 1;
	
	printf("\nNome: %s",produtos[index].nomes);
	printf("\nCódigo: %d",produtos[index].codigos);
	printf("\nValor: %.2lf",produtos[index].precos);
	printf("\nEstoque: %d",produtos[index].estoques);
		
	printf("\n\nDigite a nova quantidade do produto: ");
	scanf("%d",&novoEstoques);
	
	if(novoEstoques>=0){
		produtos[index].estoques = novoEstoques;
	}else{
		printf("\nValores negativos não são permitidos!\n\n");
		system("pause");
		return;
	}
	
	printf("Digite o novo preço do produto: ");
	scanf("%lf",&novoPreco);
	
	if(novoPreco>=0){
		produtos[index].precos = novoPreco;
	}else{
		printf("\nValores negativos não são permitidos!\n\n");
		system("pause");
		return;
	}
	printf("\n\nProduto atualizado com sucesso!!\n\n");
	system("pause");
}

// 4 - Buscar Produto
void buscarproduto(produto produtos[]) {
    int i;
    char nomeBusca[50];
    
    system("cls");
	printf(">>> BUSCAR PRODUTO <<<\n");
    
    printf("\nDigite o nome do produto: ");
    fflush(stdin);
    gets(nomeBusca);
    for (i = 0; i < count; i++) {
        if (strcmp(produtos[i].nomes, nomeBusca) == 0) {
            printf("\nProduto encontrado na cantina:");
            printf("\nNome: %s", produtos[i].nomes);
            printf("\nPreço: R$ %.2f", produtos[i].precos);
            printf("\nQuantidade vendida: %d\n\n", produtos[i].vendas);
        }
    }
    
    printf("\nProduto com o nome '%s' não encontrado na cantina.\n\n", nomeBusca);
    system("pause");
}

// 5 - Vender produto
void venderprodutos(produto produtos[]) {
	system("cls");
	printf(">>> VENDER PRODUTO <<<\n\n");
	
	char produto[30];
	int quantidade, i;
	
	printf("Nome do produto: ");
	fflush(stdin);
	gets(produto);
	for(i = 0; i < count; i++) {
		if(strcmp(produto, produtos[i].nomes) == 0) {	//Verifica se o produto existe (se foi cadastrado)
			do {
				system("cls");
				printf(">>> VENDER PRODUTO <<<\n\n");
				printf("Nome do produto: %s\n", produto);
			
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
			printf("\nProduto não cadastrado.\n\n");
			break;
		}
	}
	
	printf("\nVenda concluída!\n\n");
	system("pause");
}

// 6 - Função para listar as vendas de produtos
void listarvendas(produto produtos[]) {
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

void menu(){
	system("cls");
	printf(">>> TechFood <<<\n\n");
	printf("Escolha uma opção: ");
	printf("\n 1 - Cadastrar Produto");
	printf("\n 2 - Listar Produtos");
	printf("\n 3 - Atualizar Produto");
	printf("\n 4 - Buscar Produto");
	printf("\n 5 - Vender Produto");
	printf("\n 6 - Listar Vendas");
	printf("\n 0 - Sair");
	printf("\nOpção: ");	
}
// bloco principal
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int opcao;
	produto produtos[100];
	
	do{
		menu();
		scanf("%d",&opcao);
		switch(opcao){
			case 0:
				printf("\nSaindo da aplicação!\n\n");
				system("pause");
				break;
			case 1:
				cadastrarProdutos(produtos);
				count++;
				break;
			case 2:
				listarProdutos(produtos);
				break;
			case 3:
				atualizarProdutos(produtos);
				break;
			case 4:
				buscarproduto(produtos);
				break;
			case 5:
				venderprodutos(produtos);
				break;
			case 6:
				listarProdutos(produtos);
				break;
			default:
				printf("\nOpção inválida!\n");
				system("pause");
				break;
		}
	} while(1);
	
	return 0;
}
