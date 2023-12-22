#include <stdio.h> // Biblioteca de comunicão com o usuário
#include <stdlib.h> // Biblioteca de alocacão de espaço em memória
#include <locale.h> // Biblioteca de alocacão de texto por região
#include <string.h> // Biblioteca responsável por cuidar das strings



int registrar ()
 {
 	setlocale (LC_ALL,"portuguese");// Definindo a lingua
 	
 	char arquivo[40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // Responsavel por copiar os valores das strings
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // Cria o arquivo
	fprintf(file,cpf); // Salva o valor da variavel
	fclose(file);  //Fecha o arquivo
	
	file = fopen(arquivo,"a"); 
	fprintf(file,",");
	fclose(file); 
	
	printf("Digite o Nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo,"a"); 
	fprintf(file,nome);
	fclose(file); 
	
	file = fopen(arquivo,"a"); 
	fprintf(file,",");
	fclose(file); 
	
	printf("Digite o Sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a"); 
	fprintf(file,sobrenome);
	fclose(file); 
	
	file = fopen(arquivo,"a"); 
	fprintf(file,",");
	fclose(file); 
	
	printf("Digite o Cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a"); 
	fprintf(file,cargo);
	fclose(file); 
	system("pause");
	system("cls");
	
}

int consultar ()
{
	setlocale (LC_ALL,"portuguese");// Definindo a lingua
	
	char cpf [40];
	char conteudo [200];
	
	printf("Digite o CPF para consultar: ");
	scanf("%s", cpf);
	 FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
	 printf("Cadastro não encontrado!\n\n");		
	}
	while(fgets(conteudo, 200,file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	system("cls");
}

int deletar ()
{
	char cpf [40];
	
	printf("Digite o CPF do usuário para deletar: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usuário não encontrado no sistema!\n");	
	}
	system("pause");
	system("cls");
}


int main ()

{
	int opcao=0;// Definindo variáveis

	int laco=1;

	for(laco=1;laco=1;)

	{
		setlocale (LC_ALL,"portuguese");// Definindo a lingua

		printf("### Cartório da EBAC ####\n\n");
		printf("Escolha a opção desejada no menu\n\n");// Inicio do menu
		printf("\t1 - Registrar cadastro \n");
		printf("\t2 - Consultar cadastro \n");
		printf("\t3 - Deletar cadastro \n\n\n");
		printf("Opção: ");//Final do menu

		scanf("%d", &opcao);// Armazenando a escolha do usuário

		system("cls");

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

			default:
				printf("Opção não disponivel!!\n\n");
				system("pause");
				break;

		}
		
	}
}

