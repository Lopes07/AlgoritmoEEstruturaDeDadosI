/*12. Considere um cadastro de produtos de um estoque, com as seguintes informac¸oes para ˜
cada produto:
• Codigo de identificac¸ ´ ao do produto: representado por um valor inteiro ˜
• Nome do produto: com ate 50 caracteres ´
• Quantidade dispon´ıvel no estoque: representado por um numero inteiro ´
• Prec¸o de venda: representado por um valor real
(a) Defina uma estrutura, denominada produto, que tenha os campos apropriados para
guardar as informac¸oes de um produto ˜
(b) Crie um conjunto de N produtos (N e um valor fornecido pelo usu ´ ario) e pec¸a ao ´
usuario para entrar com as informac¸ ´ oes de cada produto ˜
(c) Encontre o produto com o maior prec¸o de venda
(d) Encontre o produto com a maior quantidade dispon´ıvel no estoque*/

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int identificacao;
    char nome[50];
    int qtd;
    double preco;
} Produto;


int main(){
    int nProdutos, maiorQtd;
    char *nomeMaiorQtd, *nomeMaiorPreco;
    double maiorPreco;
    Produto *cadastro;

    nomeMaiorQtd = (char *)malloc(50 * sizeof(char));
    nomeMaiorPreco = (char *)malloc(50 * sizeof(char));


    printf("Declare a quantidade de produtos: \n");
    scanf("%i",&nProdutos);

    cadastro = (Produto *)malloc(nProdutos * sizeof(Produto));

    for(int i = 0; i < nProdutos; i++){
        
        printf("Declare o numero de identificacao para o %i produto: \n", i + 1);
        scanf("%i", &cadastro[i].identificacao);

        printf("Declare o nome do %i produto: \n", i + 1);
        scanf("%s", &cadastro[i].nome);


        printf("Declare a quantidade disponivel em estoque do produto %i: \n", i + 1);
        scanf("%i", &cadastro[i].qtd);
 

        printf("Declare o preco do produto %i: \n", i + 1);
        scanf("%lf", &cadastro[i].preco);
    }

    maiorQtd = cadastro[0].qtd;
    maiorPreco = cadastro[0].preco;

    for(int i = 0; i < nProdutos; i++){
        if (cadastro[i].preco > maiorPreco){
            maiorPreco = cadastro[i].preco;
            nomeMaiorPreco = &cadastro[i].nome;
        }
        if (cadastro[i].qtd > maiorQtd){
            maiorQtd = cadastro[i].qtd;
            nomeMaiorQtd = &cadastro[i].nome;
        }
    }

    printf("\nProduto com maior quantidade em estoque: %s\n", nomeMaiorQtd);
    printf("Produto com maior preco: %s\n", nomeMaiorPreco);

    free(cadastro);
    free(nomeMaiorQtd);
    free(nomeMaiorPreco);    

    return 0;
}