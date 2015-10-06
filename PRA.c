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
