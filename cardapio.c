#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Capacidade de manipulação (adição, remoção, edição e visualização) de um cardápio de
comidas.*/ 

//Defeni tamanhos para os tamanhos do vetores
#define MAX 100 //Para o nome da comida
#define MAX_ARQ 50 //Para o nome do arquivo

//Crie uma struct para receber o codigo e a quantidade do mantimento que ira precisar para fazer a comida
struct Ingrediente
{
    int codigoMantimento;
    int quantidade;
};

//Função adcionar comida
void adicionarComida() {
    char nome[MAX];
    int codigo = 0;
    float preco = 0;
    //Uma lista de ingredientes do tipo Ingredientes
    struct Ingrediente lista [MAX];
    
    printf("\nAdicionar comida no cardapio");
    printf("\nDigite o nome: ");
    fflush(stdin);
    fgets(nome, MAX, stdin);

    printf("Digite o codigo: ");
    scanf("%d", &codigo);

    printf("Digite o preco: ");
    scanf("%f", &preco);

    int resposta = 0;
    int count = 0;
    printf("Deseja adicionar ingredientes? \n1-Sim\n2-Nao\n");
    scanf("%d", &resposta);

    while (resposta != 2) {
        //Um objeto do tipo ingrediente
        struct Ingrediente ing;
        printf("Informe o codigo: ");
        scanf("%d", &ing.codigoMantimento);

        printf("Informe a quantidade: ");
        scanf("%d", &ing.quantidade);

        //Vendo se existe o ingrediente no estoque
        FILE* pont_arquivo;
        char nome_arquivo[MAX_ARQ];
        snprintf(nome_arquivo, MAX_ARQ, "estoque-%d%s", ing.codigoMantimento, ".txt");
        if ((pont_arquivo = fopen(nome_arquivo, "r")) != NULL) {
            lista[count] = ing;
            count++;
            fclose(pont_arquivo);
        } else {
            printf("Nao e possivel fazer a comida por falta de ingrediente\n");
        }

        printf("Deseja adicionar outro ingredientes? \n1-Sim\n2-Nao\n");
        scanf("%d", &resposta);       
    }
    
    //Criando e adicionando a comida
    FILE* pont_arquivo;
    char nome_arquivo[MAX_ARQ];
    snprintf(nome_arquivo, MAX_ARQ, "cardapio-%d%s", codigo, ".txt");
    pont_arquivo = fopen(nome_arquivo, "w");
    fprintf(pont_arquivo, "%s%d\n%.2f", nome, codigo, preco);
    for(int i = 0; i < count; i++){
        fprintf(pont_arquivo, "\n%d,%d", lista[i].codigoMantimento, lista[i].quantidade);
    }
    fclose(pont_arquivo);

    printf("A comida foi adicionada no cardapio com sucesso!");
}

//Função visualizar comida
void visualizarComida() {
    int codigoVisualizar = 0;
    printf("Informe o codigo da comida para visualizar\n");
    scanf("%d", &codigoVisualizar);

    FILE* pont_arquivo;
    char nome_arquivo[MAX_ARQ];
    snprintf(nome_arquivo, MAX_ARQ, "cardapio-%d%s", codigoVisualizar, ".txt");
    if ((pont_arquivo = fopen(nome_arquivo, "r")) != NULL) {

        printf("\nVisulizando");
        char nome[MAX];
        char codigo[MAX];
        char preco[MAX];
        char linha[MAX] = "";
 
        fgets(nome, MAX, pont_arquivo);
        printf("\nNome: %s", nome);

        fgets(codigo, MAX, pont_arquivo);
        printf("Codigo: %s", codigo);

        fgets(preco, MAX, pont_arquivo);
        printf("Preco: %s", preco);

        fgets(linha, MAX, pont_arquivo);
        printf("Ingredientes:\n");
        char* split;
        while (strcmp(linha, "") != 0) {
            split = strtok(linha, ",");
            printf("Codigo: %s", split);
            split = strtok(NULL, ",");
            printf("\nQuantidade: %s", split);
            strcpy(linha, "");
            fgets(linha, MAX, pont_arquivo);
        }
        fclose(pont_arquivo);
    } else {
        printf("A comida nao existe!\n");
    }
}

//Função editar comida n ta completo
void editarComida() {
    char nomeNovo[MAX];
    char codigoAux[MAX];
    char precoNovoAux[MAX];
    //struct Ingrediente lista [MAX];
    int codigoNovo = 0;
    float precoNovo = 0;
    
    int codigoEditar = 0;
    int resposta = 0;
    printf("Informe o codigo da comida para editar\n");
    scanf("%d", &codigoEditar);

    FILE* pont_arquivo;
    char nome_arquivo[MAX_ARQ];
    snprintf(nome_arquivo, MAX_ARQ, "cardapio-%d%s", codigoEditar, ".txt");
    if ((pont_arquivo = fopen(nome_arquivo, "r")) != NULL) {

        //Pegando as variaveis
        fgets(nomeNovo, MAX, pont_arquivo);
        fgets(codigoAux, MAX, pont_arquivo);
        fgets(precoNovoAux, MAX, pont_arquivo);

        //Função que passa de string para outro tipo de variavel
        sscanf(precoNovoAux, "%f", &precoNovo);
        sscanf(codigoAux, "%d", &codigoNovo);

        while(resposta != 4) {
            printf("Escolha o que deseja editar\n1 - Nome\n2 - Preco\n3 - Ingredientes\n4 - Sair\n");
            scanf("%d", &resposta);

            switch(resposta) {
                case 1:
                    printf("Informe o novo nome: ");
                    fflush(stdin);
                    fgets(nomeNovo, MAX, stdin);
                break;

                case 2:
                    printf("Informe o novo preco: ");
                    scanf("%f", &precoNovo);
                break;

                case 3:
                break;
            }
        }   
        fclose(pont_arquivo);
        remove(nome_arquivo);

        FILE* pont_arquivo_novo;
        pont_arquivo_novo = fopen(nome_arquivo, "w");
        fprintf(pont_arquivo_novo, "%s%d\n%.2f\n", nomeNovo, codigoNovo, precoNovo);
        fclose(pont_arquivo_novo);
        
        printf("A comida foi atualizado com sucesso!\n");
    } else {
        printf("Comida nao existe!\n");
    }
}

//Função remover comida
void removerComida() {
    int codigoRemover = 0;
    printf("Informe o codigo da comida para deletar\n");
    scanf("%d", &codigoRemover);

    FILE* pont_arquivo;
    char nome_arquivo[MAX_ARQ];
    snprintf(nome_arquivo, MAX_ARQ, "cardapio-%d%s", codigoRemover, ".txt");
    if ((pont_arquivo = fopen (nome_arquivo, "w")) != NULL) {
        fclose(pont_arquivo);
        remove(nome_arquivo);
        printf("A comida foi removida do cardapio!\n");
    } else {
        printf("A comida nao existe!\n");
    }
}

float precoComida(int codigo) {
    char precoAux [MAX];
    float preco = 0;
    FILE* pont_arquivo;
    char nome_arquivo[MAX_ARQ];
    snprintf(nome_arquivo, MAX_ARQ, "cardapio-%d%s", codigo, ".txt");
    if ((pont_arquivo = fopen(nome_arquivo, "r")) != NULL) {
        fgets(precoAux, MAX, pont_arquivo);
        fgets(precoAux, MAX, pont_arquivo);
        fgets(precoAux, MAX, pont_arquivo);
        sscanf(precoAux, "%f", &preco);
        fclose(pont_arquivo);
    }
    return preco;
}

void main_cardapio() {  
    int escolha = 0;
    printf("### Cardapio ###");
    while(escolha != 5) {
        printf("\n\nEscolha umas das opcoes abaixo");
        printf("\n1 - Adicionar\n2 - Visualizar\n3 - Editar\n4 - Remover\n5 - Sair\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                adicionarComida();
            break;

            case 2:
                visualizarComida();
            break;

            case 3:
                editarComida();
            break;

            case 4:
                removerComida();
            break;
        }
    }
}