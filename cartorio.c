#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h>


int registrar()
{
	
	printf("\tVoc� escolheu a op��o -Registrar nomes-\n\n");
	
	char arquivo[200];
	char cpf [200];
	char nome [200];
	char sobrenome [200];
	char cargo [200];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s" , cpf);
	
	strcpy(arquivo, cpf);
	
	FILE *file;
	file = fopen(arquivo , "w");
	fprintf(file, "CPF: ");
	fclose(file);
	
	file = fopen(arquivo , "a");
	fprintf(file, cpf);
	fclose(file);
	
	file = fopen(arquivo , "a");
	fprintf(file, "/ Aluno: ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo , "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " ");
	fclose(file);
	
	printf("Digite o �ltimo sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file, sobrenome);
	fclose(file);
		
	file = fopen(arquivo, "a");
	fprintf(file, "/ Cargo: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo , "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consultar()
{
	printf("\tVoc� escolheu a op��o -Consultar nomes-\n\n");
	
	char cpf [40];
	char conteudo [40];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("CPF inv�lido. Tente novamente. ");
		printf("\n\n");
		system("pause");
	}
	
	while(fgets(conteudo, 100, file) != NULL)
	{
		printf("Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		
		system("pause");
	}	
}

int deletar()
{
	printf("\tVoc� escolheu a op��o -Deletar nomes-!\n\n");
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	printf("\n");
	
	FILE *file = fopen(cpf, "r");
    if (file == NULL)
	{
		printf("\tO usu�rio n�o pode ser identificado no sistema!\n\n");
		system("pause");
		system("cls");
		return;
	}
	fclose(file); 
	
	int opcao=0;
	
	printf("Tem certeza que deseja deletar?\n\n");
	printf("\t1 - Sim\n");
	printf("\t2 - N�o\n\n");
	printf("Escolha uma op��o: ");
	scanf("%d", &opcao);
	printf("\n");	

			if(opcao==1)
			{
				remove(cpf);
				printf("Usu�rio Removido\n\n");
				system("pause");
				system("cls");
			}	
		
			if(opcao==2)
			{
				printf("Tente novamente!\n\n");
				system("pause");
				system("cls");
				deletar();
			}
	main();
}


int main ()
{	
	int opcao=0; //Definido vari�veis 
	int loop=1;
	
	for(loop=1;loop=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");
	
		printf("\tCART�RIO DA EBAC\n\n");
		printf("\tSeja bem-vindo! \nPor favor selecione uma das op��es a seguir \n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Escolha uma op��o: ");
		
		scanf("%d" , &opcao); //Armazenar a escolha do usu�rio
		
		system("cls"); //Limpar a tela a partir da escolha do usu�rio
		
		switch(opcao)
		{
			case 1:
			registrar();
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema");
			return 0;
			break;
			
			default:
			printf("\tOp��o inv�lida. Tente novamente!\n\n");
			system("pause");
			break;
		}
	}
	
}

