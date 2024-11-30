#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocações de espaço e memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar da string


int registrar() //função responsável por cadastrar os usuários
{
	
	printf("\tVocê escolheu a opção -Registrar nomes-\n\n"); //Apresentação da escolha feita pelo usuário
	
	// inicio da criação de variáveis / string
	char arquivo[200];
	char cpf [200];
	char nome [200];
	char sobrenome [200];
	char cargo [200];
	//final da criação de variáveis
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando a informação do usuário
	scanf("%s" , cpf); //%s refere-se a string / armazenamento da informação
	
	strcpy(arquivo, cpf); //responsável por criar valores da string
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo , "w"); //cria o arquivo / o "w" significa writer
	fprintf(file, "CPF: "); //salva o valor da variável 
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo , "a"); //abre o arquivo / o "a" siginifica atualizar
	fprintf(file, cpf); // armazena o arquivo
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo , "a"); //atualiza o arquivo
	fprintf(file, "/ Nome: "); //salva o valor do variável
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando a informação do usuário
	scanf("%s", nome); //%s refere-se a string / armazenamento da informação
	
	file = fopen(arquivo , "a"); //atualiza o arquivo
	fprintf(file, nome); //salva o valor do variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, " ");
	fclose(file);
	
	printf("Digite o último sobrenome a ser cadastrado: "); 
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
	printf("\tVocê escolheu a opção -Consultar nomes-\n\n"); //Apresentação da escolha feita pelo usuário
	
	// inicio da criação de variáveis / string
	char cpf [40];
	char conteudo [40];
	//final da criação de variáveis
	
	printf("Digite o CPF a ser consultado: "); //Coletando informações
	scanf("%s", cpf);
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //abre o arquivo / "r" significa read
	
	if(file == NULL) //apresentará determinado condição quando o resultado for nulo
	{
		printf("CPF inválido. Tente novamente. ");
		printf("\n\n");
		system("pause");
	}
	
	while(fgets(conteudo, 100, file) != NULL) //apresentará determinado valor quando o resultado for diferente de nulo
	{
		printf("Essas são as informações do usuário: "); //mostra as informações do CPF digitado
		printf("%s", conteudo);
		printf("\n\n");
		
		system("pause");
	}	
}

int deletar()
{
	printf("\tVocê escolheu a opção -Deletar nomes-!\n\n"); //Apresentação da escolha feita pelo usuário
	
	//inicio criação da variavel
	char cpf[40];
	//final da criação da variável
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	printf("\n");
	
	FILE *file = fopen(cpf, "r"); //abre o arquivo e lê
    if (file == NULL) //se p resultado for nulo...
	{
		printf("\tO usuário não pode ser identificado no sistema!\n\n"); //... apresenta isso
		system("pause");
		system("cls"); //apaga o que tinha na tela
		return; 
	}
	fclose(file); //fecha o arquivo
	
	int opcao=0; //Definido variáveis 
	
	printf("Tem certeza que deseja deletar?\n\n");
	printf("\t1 - Sim\n");
	printf("\t2 - Não\n\n");
	printf("Escolha uma opção: ");
	scanf("%d", &opcao); //Armazenar a escolha do usuário
	printf("\n");	

			switch(opcao) 
			{
				case 1:
				remove(cpf);
				printf("Usuário Removido\n\n");
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
	
	int opcao=0; //Definido variáveis 
	int loop=1;
	char senhadigitada[10];
	int comparacao;
	
	printf("\tCARTÓRIO DA EBAC\n\n");
	printf("Login de administrador\n\nDigite sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
		for(loop=1;loop=1;) // retorna para o menu quando tiver finalizado
		{	
	
			system("cls"); //limpa a tela
			
			setlocale(LC_ALL, "Portuguese"); //idioma selecionado
		
			printf("\tCARTÓRIO DA EBAC\n\n");
			printf("\tSeja bem-vindo! \nPor favor selecione uma das opções a seguir \n\n"	);
			printf("\t1 - Registrar nomes \n");
			printf("\t2 - Consultar nomes \n");
			printf("\t3 - Deletar nomes \n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Escolha uma opção: ");
			
			scanf("%d" , &opcao); //Armazenar a escolha do usuário
		
			system("cls"); //Limpar a tela a partir da escolha do usuário
		
			switch(opcao) //inicio da seleção de menu
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
				printf("\tOpção inválida. Tente novamente!\n\n");
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

