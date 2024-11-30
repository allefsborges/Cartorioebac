#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��es de espa�o e mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar da string


int registrar() //fun��o respons�vel por cadastrar os usu�rios
{
	
	printf("\tVoc� escolheu a op��o -Registrar nomes-\n\n"); //Apresenta��o da escolha feita pelo usu�rio
	
	// inicio da cria��o de vari�veis / string
	char arquivo[200];
	char cpf [200];
	char nome [200];
	char sobrenome [200];
	char cargo [200];
	//final da cria��o de vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando a informa��o do usu�rio
	scanf("%s" , cpf); //%s refere-se a string / armazenamento da informa��o
	
	strcpy(arquivo, cpf); //respons�vel por criar valores da string
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo , "w"); //cria o arquivo / o "w" significa writer
	fprintf(file, "CPF: "); //salva o valor da vari�vel 
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo , "a"); //abre o arquivo / o "a" siginifica atualizar
	fprintf(file, cpf); // armazena o arquivo
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo , "a"); //atualiza o arquivo
	fprintf(file, "/ Nome: "); //salva o valor do vari�vel
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando a informa��o do usu�rio
	scanf("%s", nome); //%s refere-se a string / armazenamento da informa��o
	
	file = fopen(arquivo , "a"); //atualiza o arquivo
	fprintf(file, nome); //salva o valor do vari�vel
	fclose(file); //fecha o arquivo
	
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
	
	system("pause"); //pausa o sistema
	
}

int consultar()
{
	printf("\tVoc� escolheu a op��o -Consultar nomes-\n\n"); //Apresenta��o da escolha feita pelo usu�rio
	
	// inicio da cria��o de vari�veis / string
	char cpf [40];
	char conteudo [40];
	//final da cria��o de vari�veis
	
	printf("Digite o CPF a ser consultado: "); //Coletando informa��es
	scanf("%s", cpf);
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //abre o arquivo / "r" significa read
	
	if(file == NULL) //apresentar� determinado condi��o quando o resultado for nulo
	{
		printf("CPF inv�lido. Tente novamente. ");
		printf("\n\n");
		system("pause");
	}
	
	while(fgets(conteudo, 100, file) != NULL) //apresentar� determinado valor quando o resultado for diferente de nulo
	{
		printf("Essas s�o as informa��es do usu�rio: "); //mostra as informa��es do CPF digitado
		printf("%s", conteudo);
		printf("\n\n");
		
		system("pause");
	}	
}

int deletar()
{
	printf("\tVoc� escolheu a op��o -Deletar nomes-!\n\n"); //Apresenta��o da escolha feita pelo usu�rio
	
	//inicio cria��o da variavel
	char cpf[40];
	//final da cria��o da vari�vel
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	printf("\n");
	
	FILE *file = fopen(cpf, "r"); //abre o arquivo e l�
    if (file == NULL) //se p resultado for nulo...
	{
		printf("\tO usu�rio n�o pode ser identificado no sistema!\n\n"); //... apresenta isso
		system("pause");
		system("cls"); //apaga o que tinha na tela
		return; 
	}
	fclose(file); //fecha o arquivo
	
	int opcao=0; //Definido vari�veis 
	
	printf("Tem certeza que deseja deletar?\n\n");
	printf("\t1 - Sim\n");
	printf("\t2 - N�o\n\n");
	printf("Escolha uma op��o: ");
	scanf("%d", &opcao); //Armazenar a escolha do usu�rio
	printf("\n");	

			switch(opcao) 
			{
				case 1:
				remove(cpf);
				printf("Usu�rio Removido\n\n");
				system("pause");
				system("cls");
				break;
				
				case 2:
				printf("Tente novamente!\n\n");
				system("pause");
				system("cls");
				deletar(); //retorna para int(deletar)
				break;
			}
	main(); //retorna para o menu
}


int main () //menu
{	
	setlocale(LC_ALL, "Portuguese");
	
	int opcao=0; //Definido vari�veis 
	int loop=1;
	char senhadigitada[10];
	int comparacao;
	
	printf("\tCART�RIO DA EBAC\n\n");
	printf("Login de administrador\n\nDigite sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
		for(loop=1;loop=1;) // retorna para o menu quando tiver finalizado
		{	
	
			system("cls"); //limpa a tela
			
			setlocale(LC_ALL, "Portuguese"); //idioma selecionado
		
			printf("\tCART�RIO DA EBAC\n\n");
			printf("\tSeja bem-vindo! \nPor favor selecione uma das op��es a seguir \n\n"	);
			printf("\t1 - Registrar nomes \n");
			printf("\t2 - Consultar nomes \n");
			printf("\t3 - Deletar nomes \n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Escolha uma op��o: ");
			
			scanf("%d" , &opcao); //Armazenar a escolha do usu�rio
		
			system("cls"); //Limpar a tela a partir da escolha do usu�rio
		
			switch(opcao) //inicio da sele��o de menu
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
				return 0; //retorna o valor 0 e fecha o sistema 
				break;
			
				default:
				printf("\tOp��o inv�lida. Tente novamente!\n\n");
				system("pause");
				break;
			}
		}	
  	}
  	
  	else
  	{
  		printf("Senha incorreta!");
	}
}

