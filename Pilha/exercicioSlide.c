    void listar(Pilha *pilha){

        printf("\n###Alunos###\n");

        while (!(Empty(pilha))){
            Aluno aluno;
            POP(pilha, &aluno);

            printf("\nNome: %s\tRA: %i\n", aluno->nome, aluno->ra);
        }
        
    }