#include <stdio.h>
#include <stdlib.h>

//CAMINHOS GLOBAIS
const char *caminhoIndices[4];
const char *caminhoRegistros[4];

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
}Leitor;

typedef struct {
	int id;
	char nome[30];
	char sobrenome[30];
}Autor;

typedef struct {
	int autorID;
	int livroID;
	int sequencia;
}AutorDoLivro;

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



void mostrarLivro(Livro *livro){
    printf("id%d\n",livro->id);
    printf("titulo:%s\n",livro->titulo);
    printf("ano:%d\n",livro->anoPublicacao);
    printf("editora:%s\n",livro->editora);
}

void mostrarAutor(Autor *autor){
    printf("id:%d\n",autor->id);
    printf("nome:%s\n",autor->nome);
    printf("sobrenome:%s\n",autor->sobrenome);
}

void mostrarLeitor(Leitor *leitor){
    printf("id:%d\n",leitor->id);
    printf("nome:%s\n",leitor->nome);
    printf("fone:%s\n",leitor->fone);
    printf("endereco:%d\n",leitor->endereco);
    printf("cidade:%d\n",leitor->cidade);
    printf("estado:%d\n",leitor->estado);
}

void mostrarAutorDoLivro(AutorDoLivro *autorLivro){
    printf("idAutor:%d\n",autorLivro->autorID);
    printf("idLivro:%d\n",autorLivro->livroID);
    printf("seq:%d\n",autorLivro->sequencia);
}
//DECLARAÇÃO DAS FUNÇÕES
int menuEntidade();
void menuOperacao(int entidade);
int adicionarEntidade(int entidade);
int removerEntidade(int entidade);
int lerEntidade(int entidade);
int atualizarEntidade(int entidade);
void mostrarLivro(Livro *livro);
void mostrarAutor(Autor *autor);
void mostrarLeitor(Leitor *leitor);
void mostrarAutorDoLivro(AutorDoLivro *autorLivro);
void salvarRegistro(int entidade,void *livro);
void heapsort(Indice vetor[], int n);
void inicializaArquivos();
int verificaArquivos(int quantidadeDesejada);
int tamanhoStructHeader(char *header);
int tamanhoChaveHeader(char *header);
void atualizaIndice(int entidade,int posicao,int id);
int idUnico(int entidade,int id);
int buscaID(int identidade,int id);
void mostrarEntidade(int entidade,void *registros,int tam);

int main()
{
   caminhoIndices[0] = "dados/indiceLivro.txt";
   caminhoIndices[1] = "dados/indiceLeitor.txt";
   caminhoIndices[2] = "dados/indiceAutor.txt";
   caminhoIndices[3] = "dados/indiceAutorLivro.txt";

   caminhoRegistros[0] = "dados/Livro.txt";
   caminhoRegistros[1] = "dados/Leitor.txt";
   caminhoRegistros[2] = "dados/Autor.txt";
   caminhoRegistros[3] = "dados/AutorLivro.txt";
   int escolha;
   if(verificaArquivos(4) != 4){
       inicializaArquivos(1,"0xDEADC0DE,header_size=173,entidade=livro,qtd_campos=5,campos=[id;titulo;editora;anopublicacao;isbn],tamanho=[4,30,30,4,20,], tipo=[int,varchar,varchar,int,varchar],chaves:1*");
       inicializaArquivos(2,"0xDEADC0DE,header_size=174,entidade=leitor,qtd_campos=6,campos=[id;nome;fone;endereco;cidade;estado],tamanho=[4,30,30,4,4,4,], tipo=[int,varchar,varchar,int,int,int],chaves:1*");
       inicializaArquivos(3,"0xDEADC0DE,header_size=137,entidade=autor,qtd_campos=3,campos=[id;nome;sobrenome],tamanho=[4,30,30,], tipo=[int,varchar,varchar],chaves:1*");
       inicializaArquivos(4,"0xDEADC0DE,header_size=134,entidade=autorLivro,qtd_campos=3,campos=[idlivro;idautor;seq],tamanho=[4,4,4,], tipo=[int,int,int],chaves:2*");
   }
   do{
    escolha = menuEntidade();
   }while(escolha != 0);
    return 0;
}

int verificaArquivos(int quantidadeDesejada){
    int i,arquivos=0;
    for(i=0;i<quantidadeDesejada;i++){
        FILE *f = fopen(caminhoRegistros[i],"r");
        if(f != NULL){
            arquivos++;
        }
        fclose(f);
    }
    return arquivos;
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
                    system("PAUSE");
                    system("cls");
                }else{
                    printf("operacao falhou!\n");
                    system("PAUSE");
                    system("cls");
                }
                break;
            case 2:
                if(atualizarEntidade(entidade)==0){
                    printf("operacao realizada com sucesso!\n");
                    system("PAUSE");
                    system("cls");
                }else{
                    printf("operacao falhou!\n");
                    system("PAUSE");
                    system("cls");
                }
                break;
            case 3:
                if(lerEntidade(entidade)==0){
                    printf("operacao realizada com sucesso!\n");
                    system("PAUSE");
                    system("cls");
                }else{
                    printf("operacao falhou!\n");
                    system("PAUSE");
                    system("cls");
                }
                break;
            case 4:
                if(removerEntidade(entidade)==0){
                    printf("operacao realizada com sucesso!\n");
                    system("PAUSE");
                    system("cls");
                }else{
                    printf("operacao falhou!\n");
                    system("PAUSE");
                    system("cls");
                }
                break;
        }
    }while(operacao != 0);
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
            scanf("%d",&leitor.cidade);
            printf("digite o estado do leitor:\n");
            scanf("%d",&leitor.estado);
            salvarRegistro(entidade,&leitor);
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
            salvarRegistro(entidade,&autor);
            break;

        case 4:
            printf("digite o id do autor do livro:\n");
            scanf("%d",&autorLivro.livroID);
            printf("digite o id do livro:\n");
            scanf("%d",&autorLivro.autorID);
            printf("digite a sequencia do autor do livro:\n");
            scanf("%d",&autorLivro.sequencia);
            salvarRegistro(entidade,&autorLivro);
            break;
    }
    return 0;
}

void inicializaArquivos(int entidade,char *header){
//INICIALIZA OS ARQUIVOS DE REGISTRO
    FILE *f = fopen(caminhoRegistros[entidade-1],"wb");
    if(f == NULL){
        printf("teste\n");
    }
    int tamanho=0;
    while(header[tamanho] != '*'){
        tamanho++;
    }
    fwrite(header,tamanho,1,f);
    printf("entidade:%d    tamanhoHeader:%d\n",entidade,tamanho);
    fclose(f);
    FILE *fi = fopen(caminhoIndices[entidade-1],"wb");
    fclose(fi);
}

int testeHexa(char hex[10]){
    if(strcmp("0xDEADC0DE",hex) == 0) //se srtcmp retornar 0, as strings sao iguais
    {
        return 1; //HEXADECIMAL CORRETO
    }else{
        return 0; //HEXADECIMAL ERRADO
    }
}

int tamanhoStructHeader(char *header){
    header = strstr(header,"tamanho");
    header = strstr(header,"[");
    char temp[4] = "";
    int tamanho =0;
    int i =1;
   // printf("tamanho:%d\n",tamanho);
    while( header[i] != ']'){

     //       printf("temp:%s  header[i]=%c\n",temp,header[i]);
        if(header[i] != ','){
            sprintf(temp,"%s%c",temp,header[i]);
        }else{
            tamanho += atoi(temp);
            strcpy(temp,"");
        }
        i++;
    }
   // printf("tamanho:%d\n",tamanho);
    return tamanho;
}

int tamanhoChaveHeader(char *header){
    header = strstr(header,"chaves");
    header = strstr(header,"=");
    char *temp;
    sprintf(temp,"%c",header[1]);
    return atoi(temp);
}

void salvarRegistro(int entidade,void *registro){
    char *caminho = caminhoRegistros[entidade-1];
    FILE *f = fopen(caminho,"rb");
    if(f == NULL){
        printf("erro ao abrir arquivo!\n");
        return;
    }
    int *id;

    char hex[11];
    fgets(hex,11,f);
    if(testeHexa(hex) == 1){
        fseek(f,23,SEEK_SET);
        char headerSize[4];
        fgets(headerSize,4,f);
        int headerSizeInt=atoi(headerSize);
        char header[headerSizeInt];
        fgets(header,headerSizeInt,f);
        int tamanhoStruct = tamanhoStructHeader(header);
        //int tamanhoChave = tamanhoChaveHeader(header);
        id=(int*)registro;
        if(idUnico(entidade,*id) == 0){
            printf("o id nao e unico!\n");
            return;
        }
        long tam;
        fseek (f,0,SEEK_END);
        tam=(ftell(f)-(long)headerSizeInt)/tamanhoStruct;
        int posicao;
        posicao=tam;
        fclose(f);
        FILE *f = fopen(caminho,"ab");
        fseek(f,0,SEEK_END);
        fwrite(registro,tamanhoStruct,1,f);
        fclose(f);
        atualizaIndice(entidade,posicao,*id);
    }else{
        fclose(f);
    }
}

void atualizaIndice(int entidade,int posicao,int id){
    char *caminho = caminhoIndices[entidade-1];
    FILE *f = fopen(caminho,"rb");
    int tam;
    printf("posicao:%d\nid:%d\n",posicao,id);
    fseek (f,0,SEEK_END);
	tam=(int)(ftell(f)/sizeof(Indice));
    Indice indices[tam+1];
    rewind(f);
    int i;
    if(tam>0){
       fread(indices,sizeof(Indice),tam,f);
    }
    Indice novo;
    novo.id=id;
    novo.posicao=posicao;
    indices[tam]=novo;
    heapsort(indices,tam+1);
    fclose(f);
    FILE *fw = fopen(caminho,"wb");
    fwrite(indices,sizeof(Indice),tam+1,fw);
    fclose(fw);
    /* for(i=0;i<tam+1;i++){
            printf("[%d]",indices[i].id);
     }
     printf("\n");*/
}

int idUnico(int entidade,int id){
    char *caminho = caminhoIndices[entidade-1];
    FILE *f = fopen(caminho,"rb");
    int tam,i;
    fseek (f,0,SEEK_END);
	tam=(int)(ftell(f)/sizeof(Indice));
	Indice indices[tam];
	rewind(f);
	if(tam>0){
       fread(indices,sizeof(Indice),tam,f);
    }
    fclose(f);
    int j=0;
    for(i=0;i<tam;i++){
        if(indices[i].id == id)
            return 0;
    }
    return 1;
}

int removerEntidade(int entidade){

    return 0;
}

int lerEntidade(int entidade){
    int id;
    printf("Informe o ID da entidade a ser lida ou 0 para mostrar todas:  \n");
    scanf("%d",&id);
    if(id==0){
        char *caminho = caminhoRegistros[entidade-1];
        FILE *f = fopen(caminho,"rb");
        if(f == NULL){
            printf("erro ao abrir arquivo!\n");
            return;
        }
        char hex[11];
        fgets(hex,11,f);
        if(testeHexa(hex) == 1){
            fseek(f,23,SEEK_SET);
            char headerSize[4];
            fgets(headerSize,4,f);
            int headerSizeInt=atoi(headerSize);
            char header[headerSizeInt];
            fgets(header,headerSizeInt,f);
            int tamanhoStruct = tamanhoStructHeader(header);
            long tam;
            fseek (f,0,SEEK_END);
            tam=(ftell(f)-(long)headerSizeInt)/tamanhoStruct;
            fseek (f,headerSizeInt,SEEK_SET);
            void **registros = (void**)malloc(tamanhoStruct*tam);
            int i;
            for(i=0;i<tam;i++){
                    fread(registros[i],tamanhoStruct,1,f);
            }

            for(i=0;i<tam;i++){
                    mostrarEntidade(entidade,registros[i],1);
            }
            fclose(f);
        }

    }else{
            int posicao = buscaID(entidade,id);
            char *caminho = caminhoRegistros[entidade-1];
            FILE *f = fopen(caminho,"rb");
            if(f == NULL){
                printf("erro ao abrir arquivo!\n");
                return;
            }
            char hex[11];
            fgets(hex,11,f);
            if(testeHexa(hex) == 1){
                fseek(f,23,SEEK_SET);
                char headerSize[4];
                fgets(headerSize,4,f);
                int headerSizeInt=atoi(headerSize);
                char header[headerSizeInt];
                fgets(header,headerSizeInt,f);
                int tamanhoStruct = tamanhoStructHeader(header);
                long tam;
                fseek (f,0,SEEK_END);
                tam=(ftell(f)-(long)headerSizeInt)/tamanhoStruct;
                fseek (f,headerSizeInt,SEEK_SET);
                fseek (f,posicao*tamanhoStruct,SEEK_CUR);
                void *registros = malloc(tamanhoStruct);
                fread(registros,tamanhoStruct,1,f);
                mostrarEntidade(entidade,registros,1);
                fclose(f);
        }
    }

    return 0;
}

void mostrarEntidade(int entidade,void *registros,int tam){
    //TODO TROCAR SWITCH POR VETOR GLOBAL DE FUNÇÕES(DESCOBRIR COMO)
    switch(entidade){
        case 1:
            mostrarLivro(registros);
            break;
        case 2:
            mostrarLeitor(registros);
            break;
        case 3:
            mostrarAutor(registros);
            break;
        case 4:
            mostrarAutorDoLivro(registros);
            break;
    }
}

int buscaID(int entidade,int id){
    char *caminho = caminhoIndices[entidade-1];
    FILE *f = fopen(caminho,"rb");
    int tam,i;
    fseek (f,0,SEEK_END);
	tam=(int)(ftell(f)/sizeof(Indice));
	Indice indices[tam];
	rewind(f);
	if(tam>0){
       fread(indices,sizeof(Indice),tam,f);
    }
    fclose(f);
    int j=0;
    for(i=0;i<tam;i++){
        if(indices[i].id == id)
            return indices[i].posicao;
    }
    return -1;
}

int atualizarEntidade(int entidade){
	Livro livro;
     	Leitor leitor;
     	AutorDoLivro autorLivro;
     	Autor autor;
    	switch(entidade){
		//usuario informa o ID a ser atualizado e entao informa os novos atributos,
		//o antigo registro é apagado e um novo é criado
		case 1:
		    printf("Informe o ID do livro a ser atualizado: \n");
		    scanf("%d", &livro.id);

		    printf("digite o novo titulo do livro:\n");
		    fflush(stdin);
		    gets(livro.titulo);
		    printf("digite o novo ano do livro:\n");
		    scanf("%d",&livro.anoPublicacao);
		    printf("digite a nova editora do livro:\n");
		    fflush(stdin);
		    gets(livro.editora);
		    printf("digite o novo isbn do livro:\n");
		    fflush(stdin);
		    gets(livro.isbn);

		    salvarRegistro(entidade,&livro);
		    break;

		case 2:
		    printf("Informe o ID do leitor a ser atualizado: \n");
		    scanf("%d",&leitor.id);

		    printf("digite o novo nome do leitor:\n");
		    fflush(stdin);
		    gets(leitor.nome);
		    printf("digite o novo telefone do leitor:\n");
		    fflush(stdin);
		    gets(leitor.fone);
		    printf("digite o novo endereco do leitor:\n");
		    scanf("%d",&leitor.endereco);
		    printf("digite a nova cidade do leitor:\n");
		    scanf("%d",leitor.cidade);
		    printf("digite o novo estado do leitor:\n");
		    scanf("%d",leitor.estado);

  		    salvarRegistro(entidade,&leitor); //??
		    break;

		case 3:
		    printf("Informe o ID do autor a ser atualizado:\n");
		    scanf("%d",&autor.id);

		    printf("digite o novo nome do autor:\n");
		    fflush(stdin);
		    gets(autor.nome);
		    printf("digite o novo sobrenome do autor:\n");
		    fflush(stdin);
		    gets(autor.sobrenome);

		    salvarRegistro(entidade,&autor); //??
		    break;

		case 4:
		    printf("Informe o ID do autor do livro a ser atualizado:\n");
		    scanf("%d",&autorLivro.autorID);

		    printf("digite o novo id do livro:\n");
		    fflush(stdin);
		    gets(autorLivro.livroID);
		    printf("digite a nova sequencia do autor do livro:\n");
		    scanf("%d",&autorLivro.sequencia);

		    salvarRegistro(entidade,&autorLivro); //??
		    break;
	    }
	    return 0;
}

void heapsort(Indice vetor[], int n){
	int pivot;
	int x, y;
	Indice aux;

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
			if((y+1 < n)&&(vetor[y+1].id>vetor[y].id)){
				y++;
			}
			if(vetor[y].id>aux.id){
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
































