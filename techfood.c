aqui
//3 funcao de Atualizar
void atualizarProdutos(produto produtos[],int count){
	char nomes;
	int x, codigos, novoEstoques, diferencaEstoques;
	double novoPreco, diferencaPreco;
	system("cls");
	do{
		printf(">>>> EDI��O DE PRODUTOS <<<<\n");
		printf("Digite o c�digo do produto que voc� deseja editar: ");
		scanf("%d",&codigos);
	}while(codigos < 1 || codigos > count);
	int index = codigos - 1;
		printf(">>>> PRODUTO QUE SER� EDITADO <<<<\n");
		printf("\nPrecos: %lf",produtos[index].precos);
		printf("\nEstoque: %d",produtos[index].estoques);
		printf("\nCodigo: %d",produtos[index].codigos);
		printf("\nNome: %s",produtos[index].nomes);
			printf("\nDigite a nova quantidade do produto: ");
			scanf("%d",&novoEstoques);
			if(novoEstoques>=0){
				produtos[index].estoques = novoEstoques;
			}else{
				printf("\nValores negativos n�o s�o permitidos!\n");
				return;
			}
			printf("\nDigite o novo pre�o do produto: ");
			scanf("%lf",&novoPreco);
			if(novoPreco>=0){
				produtos[index].precos = novoPreco;
			}else{
				printf("\nValores negativos n�o s�o permitidos!\n");
				return;
			}
			printf("Produto atualizado com sucesso!!");
			system("pause");
	}	
