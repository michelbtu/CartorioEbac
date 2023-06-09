#include <stdio.h>   // Bibioteca de comunica��o com o usuario
#include <stdlib.h>  // Biblioteca de aloca��o de mem�ria
#include <locale.h>  // Biblioteca de aloca��es de texto por regi�o
#include <string.h>  // Bibloteca respons�vel por cuidar das string

int registro()// Fun��o respons�lvel por cadastrar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	// Inicio da cria��o de vari�vel/ string
	 char arquivo[40];
	 char cpf[40];
	 char nome[40];
	 char sobrenome[40];
	 char cargo[40];
	 // Final da cria��o de vari�vel/ string
	 
	 
	 
	 printf("Voc� escolheu o resgistro de nomes!\n\n\n"); // Coletando informa��es do usu�rio
	 printf("Por favor digite o CPF a ser cadastrado: "); // %s refere-se a string
     scanf("%s",cpf);
     
     strcpy(arquivo, cpf); // Respons�vel por copiar os valores das string
     
     FILE *file; // Cria o arquivo
     file = fopen(arquivo, "w"); // Abre o arquivo e escreve (w)
     fprintf(file, "CPF: ");
     fprintf(file, cpf); // Salva o valor da vari�vel
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
	
	
	printf("Voc� escolheu consultar nomes!\n\n\n");
	printf("Por favor digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // Abre o arquivo e l� (r)
	
	if(file == NULL)
	{
		printf("Cadastro n�o localizado, por favor informar CPF valido!\n");
	}
	
	while(fgets(conteudo, 200, file)!=NULL)
	{
		printf("Essas s�o as informa��es do usu�rio solicitado: ");
		printf("%s", conteudo);
		
	}
	
	system("pause");
}
	
   

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Voc� escolheu o deletar nomes!\n\n\n");
	printf("Por favor digite o CPF a ser deletado ");
	scanf("%s", cpf);
	
	remove(cpf);
		printf("O usu�rio solicitado foi deletado com sucesso! \n");
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio solicitado n�o se encontra no sistema! \n");
		system("pause");
	}
	
	
    
}
int main()
{ 
   int opcao=0; // Defini�ao de vari�veis
   
   int laco=1; // Implata��o do la�o de repeti��o
   
   for(laco=1;laco=1;)// La�o de repeti��o
   {
        system("cls");// Comando para limpar a tela
   
        setlocale(LC_ALL, "Portuguese");  // Defini��o de idioma
   
        printf("### Cart�rio da EBAC ###\n\n");// Inicio do menu
	    printf("Escolha uma op��o desejada no menu:\n\n");
        printf("\t 1 - Registrar nomes\n\n");
        printf("\t 2 - Consutar nomes\n\n");
        printf("\t 3 - Deletar nomes\n\n");
        printf("\t 4 - Sair do sistema\n\n");
        printf("Op��o: ");// Fim do menu
    
        scanf("%d", &opcao);// Armazenando escolha do usu�rio.
    
        system("cls");
    
        switch(opcao)// Inicio da sele��o do menu
        {
    	    case 1: 
    		registro();// Inicio da sele��o de fun��es
    		break;
    		
    	    case 2:
    		consulta();	// Inicio da sele��o de fun��es
    		break;
    		
    	    case 3:
    		deletar();// Inicio da sele��o de fun��es
    		break;
    		
    		case 4:
    		printf("Obrigado por ultilizar o sistema!\n");
    		return 0;
   			break;	
    		
    		
    	    default: // Se nenhum dos cases anteriores seja atendido
    		printf("Essa op��o n�o est� disponivel!\n");
    		system("pause");
    		break;
    		
	    }// Fim da sele��o
    }
}

