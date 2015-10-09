#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
//CAMINHOS GLOBAIS
const char *caminhoIndices[4];
const char *caminhoRegistros[4];

=======
>>>>>>> e6e5a1d4ffd73b273de24f3a33eeb028d0fb16eb
typedef struct {
	int id;
	char titulo[30];
	char editora[30];
	int anoPublicacao;
	char isbn[30];
}Livro;

typedef struct {
	int id;
	char nome[30];
	char fone[30];
	int endereco;
	int cidade;
	int estado;
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
<<<<<<< HEAD
} AutorDoLivro;

typedef struct indice{
    int posicao;
    int id;
}Indice;

typedef struct indiceAutorLivro{
    int posicao;
    int autor;
    int livro;
    int sequence;
}IndiceAutorLivro;
=======
} AutoDoLivro;
>>>>>>> e6e5a1d4ffd73b273de24f3a33eeb028d0fb16eb

//DECLARAÇÃO DAS FUNÇÕES
int menuEntidade();
void menuOperacao(int entidade);
int adicionarEntidade(int entidade);
int removerEntidade(int entidade);
int lerEntidade(int entidade);
int atualizarEntidade(int entidade);
<<<<<<< HEAD
void mostrarLivro(Livro livro);
void salvarRegistro(int entidade,void *livro);

void heapsort(int vetor[], int n);


int main()
{

   caminhoIndices[0] = "dados/indiceLivro.txt";
   caminhoIndices[1] = "dados/indiceLeitor.txt";
   caminhoIndices[2] = "dados/indiceAutor.txt";
   caminhoIndices[3] = "dados/indiceAutorLivro.txt";


   caminhoRegistros[0] = "Livro.txt";
   caminhoRegistros[1] = "dados/Leitor.txt";
   caminhoRegistros[2] = "dados/Autor.txt";
   caminhoRegistros[3] = "dados/AutorLivro.txt";
=======

int main()
{
>>>>>>> e6e5a1d4ffd73b273de24f3a33eeb028d0fb16eb
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
<<<<<<< HEAD
                    system("PAUSE");
                    system("cls");
                }else{
                    printf("operacao falhou!\n");
                    system("PAUSE");
                    system("cls");
=======
                }else{
                    printf("operacao falhou!\n");
>>>>>>> e6e5a1d4ffd73b273de24f3a33eeb028d0fb16eb
                }
                break;
            case 2:
                if(atualizarEntidade(entidade)==0){
                    printf("operacao realizada com sucesso!\n");
<<<<<<< HEAD
                    system("PAUSE");
                    system("cls");
                }else{
                    printf("operacao falhou!\n");
                    system("PAUSE");
                    system("cls");
=======
                }else{
                    printf("operacao falhou!\n");
>>>>>>> e6e5a1d4ffd73b273de24f3a33eeb028d0fb16eb
                }
                break;
            case 3:
                if(lerEntidade(entidade)==0){
                    printf("operacao realizada com sucesso!\n");
<<<<<<< HEAD
                    system("PAUSE");
                    system("cls");
                }else{
                    printf("operacao falhou!\n");
                    system("PAUSE");
                    system("cls");
=======
                }else{
                    printf("operacao falhou!\n");
>>>>>>> e6e5a1d4ffd73b273de24f3a33eeb028d0fb16eb
                }
                break;
            case 4:
                if(removerEntidade(entidade)==0){
                    printf("operacao realizada com sucesso!\n");
<<<<<<< HEAD
                    system("PAUSE");
                    system("cls");
                }else{
                    printf("operacao falhou!\n");
                    system("PAUSE");
                    system("cls");
=======
                }else{
                    printf("operacao falhou!\n");
>>>>>>> e6e5a1d4ffd73b273de24f3a33eeb028d0fb16eb
                }
                break;
        }
    }while(operacao != 0);
}

<<<<<<< HEAD

void mostrarLivro(Livro livro){
    printf("titulo:%s\n",livro.titulo);
    printf("ano:%d\n",livro.anoPublicacao);
    printf("editora:%s\n",livro.editora);
}

int adicionarEntidade(int entidade){
     Livro livro;
     Leitor leitor;
     AutorDoLivro autorLivro;
     Autor autor;
    switch(entidade){
        case 1:
            printf("digite o id do livro:\n");
            scanf("%d",&livro.id);
            printf("digite o titulo do livro:\n");
            fflush(stdin);
            gets(livro.titulo);
            printf("digite o ano do livro:\n");
            scanf("%d",&livro.anoPublicacao);
            printf("digite a editora do livro:\n");
            fflush(stdin);
            gets(livro.editora);
            printf("digite o isbn do livro:\n");
            fflush(stdin);
            gets(livro.isbn);
            salvarRegistro(entidade,&livro);
            break;

        case 2:
            printf("digite o id do leitor:\n");
            scanf("%d",&leitor.id);
            printf("digite o nome do leitor:\n");
            fflush(stdin);
            gets(leitor.nome);
            printf("digite o telefone do leitor:\n");
            fflush(stdin);
            gets(leitor.fone);
            printf("digite o endereco do leitor:\n");
            scanf("%d",&leitor.endereco);
            printf("digite a cidade do leitor:\n");
            scanf("%d",leitor.cidade);
            printf("digite o estado do leitor:\n");
            scanf("%d",leitor.estado);
            break;

        case 3:
            printf("digite o id do autor:\n");
            scanf("%d",&autor.id);
            printf("digite o nome do autor:\n");
            fflush(stdin);
            gets(autor.nome);
            printf("digite o sobrenome do autor:\n");
            fflush(stdin);
            gets(autor.sobrenome);
            break;

        case 4:
            printf("digite o id do autor do livro:\n");
            scanf("%d",&autorLivro.autorID);
            printf("digite o id do livro:\n");
            fflush(stdin);
            gets(autorLivro.livroID);
            printf("digite a sequencia do autor do livro:\n");
            scanf("%d",&autorLivro.sequencia);
            break;
    }
=======
int adicionarEntidade(int entidade){
>>>>>>> e6e5a1d4ffd73b273de24f3a33eeb028d0fb16eb

    return 0;
}

<<<<<<< HEAD
int testeHexa(char hex[10]){
    int i = 0;
    strcmp("0xDEADC0DE",hex);
    str
}

void salvarRegistro(int entidade,void *registro){
    char *caminho = caminhoRegistros[entidade-1];
    Livro *livro = (Livro*) registro;
    FILE *f = fopen("Livro.txt","r");
    if(f == NULL){
        printf("erro ao abrir arquivo!\n");
        return;
    }
    char hex[11];
    fgets(hex,11,f);
    mostrarLivro(*livro);
    printf("%s\n",hex);
    fclose(f);
    if(testeHexa(hex) == 0){

    }
}

=======
>>>>>>> e6e5a1d4ffd73b273de24f3a33eeb028d0fb16eb
int removerEntidade(int entidade){

    return 0;
}

int lerEntidade(int entidade){

    return 0;
}

int atualizarEntidade(int entidade){

    return 0;
}

<<<<<<< HEAD
void heapsort(int vetor[], int n){
	int pivot;
	int x, y, aux;

	pivot = n/2;

	while(1){
		if(pivot > 0){
			pivot--;
			aux = vetor[pivot];
		}else{
            n--;
            if(n==0)
                return;
            aux = vetor[n];
            vetor[n]=vetor[0];
		}
		x = pivot;
		y = pivot*2+1;

		while(y<n){
			if((y+1 < n)&&(vetor[y+1]>vetor[y])){
				y++;
			}

			if(vetor[y]>aux){
				vetor[x]=vetor[y];
				x=y;
				y=x*2+1;
			}else{
				break;
			}
		}
		vetor[x]=aux;
	}
}































=======
>>>>>>> e6e5a1d4ffd73b273de24f3a33eeb028d0fb16eb

