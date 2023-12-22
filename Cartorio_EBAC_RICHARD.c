#include <stdio.h> // Biblioteca de comunic�o com o usu�rio
#include <stdlib.h> // Biblioteca de alocac�o de espa�o em mem�ria
#include <locale.h> // Biblioteca de alocac�o de texto por regi�o
#include <string.h> // Biblioteca respons�vel por cuidar das strings



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
	 printf("Cadastro n�o encontrado!\n\n");		
	}
	while(fgets(conteudo, 200,file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	system("cls");
}

int deletar ()
{
	char cpf [40];
	
	printf("Digite o CPF do usu�rio para deletar: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o encontrado no sistema!\n");	
	}
	system("pause");
	system("cls");
}


int main ()

{
	int opcao=0;// Definindo vari�veis

	int laco=1;

	for(laco=1;laco=1;)

	{
		setlocale (LC_ALL,"portuguese");// Definindo a lingua

		printf("### Cart�rio da EBAC ####\n\n");
		printf("Escolha a op��o desejada no menu\n\n");// Inicio do menu
		printf("\t1 - Registrar cadastro \n");
		printf("\t2 - Consultar cadastro \n");
		printf("\t3 - Deletar cadastro \n\n\n");
		printf("Op��o: ");//Final do menu

		scanf("%d", &opcao);// Armazenando a escolha do usu�rio

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
				printf("Op��o n�o disponivel!!\n\n");
				system("pause");
				break;

		}
		
	}
}

