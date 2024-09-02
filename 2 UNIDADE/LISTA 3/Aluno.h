typedef struct aluno Aluno;

Aluno * criarAluno(int matricula, char nome[], float media);

void salvarAlunoEmArquivo(char * nome, Aluno * aluno);

void exibirAlunos(char * nome);