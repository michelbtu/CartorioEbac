#include <stdio.h>   // Bibioteca de comunicação com o usuario
#include <stdlib.h>  // Biblioteca de alocação de memória
#include <locale.h>  // Biblioteca de alocações de texto por região
#include <string.h>  // Bibloteca responsável por cuidar das string

int registro()// Função responsálvel por cadastrar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	// Inicio da criação de variável/ string
	 char arquivo[40];
	 char cpf[40];
	 char nome[40];
	 char sobrenome[40];
	 char cargo[40];
	 // Final da criação de variável/ string
	 
	 
	 
	 printf("Você escolheu o resgistro de nomes!\n\n\n"); // Coletando informações do usuário
	 printf("Por favor digite o CPF a ser cadastrado: "); // %s refere-se a string
     scanf("%s",cpf);
     
     strcpy(arquivo, cpf); // Responsável por copiar os valores das string
     
     FILE *file; // Cria o arquivo
     file = fopen(arquivo, "w"); // Abre o arquivo e escreve (w)
     fprintf(file, "CPF: ");
     fprintf(file, cpf); // Salva o valor da variável
     fclose(file); // Fecha o arquivo
     
     file = fopen(arquivo, "a"); // Abre o arquivo e salva novos valores (a)
     fprintf(file, "\nNome: ");
     fclose(file);
     
      printf("Por favor digite o nome a ser cadastrado: ");
     scanf("%s", nome);
     
     file = fopen(arquivo, "a");
     fprintf(file, nome);
     fclose(file);
     
     file = fopen(arquivo, "a"); 
     fprintf(file, "\nSobrenome: ");
     fclose(file);
     
     printf("Por favor digite o sobrenome a ser cadastrado: ");
     scanf("%s", sobrenome);
     
     file = fopen(arquivo, "a");
     fprintf(file, sobrenome);
     fclose(file);
     
     file = fopen(arquivo, "a"); 
     fprintf(file, "\nCargo: ");
     fclose(file);
     
     
     printf("Por favor digite o cargo a ser cadastrado: ");
     scanf("%s", cargo);
     
     file = fopen(arquivo, "a");
     fprintf(file, cargo);
     fclose(file);

        
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	
	printf("Você escolheu consultar nomes!\n\n\n");
	printf("Por favor digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // Abre o arquivo e lê (r)
	
	if(file == NULL)
	{
		printf("Cadastro não localizado, por favor informar CPF valido!\n");
	}
	
	while(fgets(conteudo, 200, file)!=NULL)
	{
		printf("Essas são as informações do usuário solicitado: ");
		printf("%s", conteudo);
		
	}
	
	system("pause");
}
	
   

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Você escolheu o deletar nomes!\n\n\n");
	printf("Por favor digite o CPF a ser deletado ");
	scanf("%s", cpf);
	
	remove(cpf);
		printf("O usuário solicitado foi deletado com sucesso! \n");
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário solicitado não se encontra no sistema! \n");
		system("pause");
	}
	
	
    
}
int main()
{ 
   int opcao=0; // Definiçao de variáveis
   
   int laco=1; // Implatação do laço de repetição
   
   for(laco=1;laco=1;)// Laço de repetição
   {
        system("cls");// Comando para limpar a tela
   
        setlocale(LC_ALL, "Portuguese");  // Definição de idioma
   
        printf("### Cartório da EBAC ###\n\n");// Inicio do menu
	    printf("Escolha uma opção desejada no menu:\n\n");
        printf("\t 1 - Registrar nomes\n\n");
        printf("\t 2 - Consutar nomes\n\n");
        printf("\t 3 - Deletar nomes\n\n");
        printf("\t 4 - Sair do sistema\n\n");
        printf("Opção: ");// Fim do menu
    
        scanf("%d", &opcao);// Armazenando escolha do usuário.
    
        system("cls");
    
        switch(opcao)// Inicio da seleção do menu
        {
    	    case 1: 
    		registro();// Inicio da seleção de funções
    		break;
    		
    	    case 2:
    		consulta();	// Inicio da seleção de funções
    		break;
    		
    	    case 3:
    		deletar();// Inicio da seleção de funções
    		break;
    		
    		case 4:
    		printf("Obrigado por ultilizar o sistema!\n");
    		return 0;
   			break;	
    		
    		
    	    default: // Se nenhum dos cases anteriores seja atendido
    		printf("Essa opção não está disponivel!\n");
    		system("pause");
    		break;
    		
	    }// Fim da seleção
    }
}

