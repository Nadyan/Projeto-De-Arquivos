#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	char titulo[30];
	char editora[30];
	int anoPublicacao;
	char isbn[30];
} Livro;

typedef struct {
	int id;
	char nome[30];
	char fone[30];
	int endereco; //??
	int cidade; //??
	int estado; //??
} Leitor;

typedef struct {
	int id;
	char nome[30];
	char sobrenome[30];
} Autor;

typedef struct {
	int autorID;
	int livroID;
	int sequencia;
} AutoDoLivro;

//DECLARAÇÃO DAS FUNÇÕES
int menuEntidade();
void menuOperacao(int entidade);
int adicionarEntidade(int entidade);
int removerEntidade(int entidade);
int lerEntidade(int entidade);
int atualizarEntidade(int entidade);

int main()
{
   int escolha;
   do{
    escolha = menuEntidade();
   }while(escolha != 0);
    return 0;
}

int menuEntidade(){
    int entidade;
    do{
        printf("escolha a entidade com a qual deseja trabalhar:\n");
        printf("1-Livro\n");
        printf("2-Leitor\n");
        printf("3-Autor\n");
        printf("4-Autor Do Livro\n");
        printf("0-Sair do programa\n");
        scanf("%d",&entidade);
        system("cls");
        if(entidade != 0)
            menuOperacao(entidade);
    }while(entidade != 0);
    return entidade;
}

void menuOperacao(int entidade){
    int operacao;
    do{
        printf("escolha a operacao desejada:\n");
        printf("1-Adicionar\n");
        printf("2-Atualizar\n");
        printf("3-Ler\n");
        printf("4-Deletar\n");
        printf("0-Voltar ao meu anterior\n");
        scanf("%d",&operacao);
        system("cls");
        switch(operacao){
            case 1:
                if(adicionarEntidade(entidade)==0){
                    printf("operacao realizada com sucesso!\n");
                }else{
                    printf("operacao falhou!\n");
                }
                break;
            case 2:
                if(atualizarEntidade(entidade)==0){
                    printf("operacao realizada com sucesso!\n");
                }else{
                    printf("operacao falhou!\n");
                }
                break;
            case 3:
                if(lerEntidade(entidade)==0){
                    printf("operacao realizada com sucesso!\n");
                }else{
                    printf("operacao falhou!\n");
                }
                break;
            case 4:
                if(removerEntidade(entidade)==0){
                    printf("operacao realizada com sucesso!\n");
                }else{
                    printf("operacao falhou!\n");
                }
                break;
        }
    }while(operacao != 0);
}

int adicionarEntidade(int entidade){

    return 0;
}

int removerEntidade(int entidade){

    return 0;
}

int lerEntidade(int entidade){

    return 0;
}

int atualizarEntidade(int entidade){

    return 0;
}


