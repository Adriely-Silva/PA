#include <stdio.h>
#include <stdlib.h>
#include "saldo.c"

//Defeni tamanhos para os vetores
#define MAX 100 //Para o nome do mantimento
#define MAX_ARQ 50 //Para o nome do arquivo

//Função cadastar mantimento
void cadastrarMantimento() {
    char nome[MAX];
    int codigo = 0;
    float preco = 0;
    int quantidade = 0;
    
    printf("\nAdicionar mantimentos no estoque");
    printf("\nDigite o nome: ");
    fflush(stdin);
    fgets(nome, MAX, stdin);

    printf("Digite o codigo: ");
    scanf("%d", &codigo);

    printf("Digite o preco: ");
    scanf("%f", &preco);

    printf("Digite a quantidade: ");
    scanf("%d", &quantidade);

    //Se há disponilidade de comprar
    float valorTotal = preco*quantidade; //Calculando o valor total
    float saldo = saldoAtual();
    if (valorTotal > saldo) { //Vendo se há saldo suficinete
        printf("O item nao foi cadastrado, pois saldo insuficiente");
    } else {
        //Criando o arquivo e adicionando os valores das variáveis
        FILE* pont_arquivo;
        char nome_arquivo[MAX_ARQ];
        snprintf(nome_arquivo, MAX_ARQ, "estoque-%d%s", codigo, ".txt");
        pont_arquivo = fopen(nome_arquivo, "w");
        fprintf(pont_arquivo, "%s%d\n%.2f\n%d", nome, codigo, preco, quantidade);
        fclose(pont_arquivo);

        printf("O item foi cadastrado com sucesso!");
    }
}

//Função visualizar mantimento
void visualizarMantimento() {
    int codigoVisualizar;
    printf("Informe o codigo do mantimento para visualizar\n");
    scanf("%d", &codigoVisualizar);

    /*Abrindo o arquivo e ver se ele existe, se existir, vai mostrar o conteúdo correspondente que o úsuario digitou.
    Se não existir, vai mandar uma mensagem de arquivo não existente*/
    FILE* pont_arquivo;
    char nome_arquivo[MAX_ARQ];
    snprintf(nome_arquivo, MAX_ARQ, "estoque-%d%s", codigoVisualizar, ".txt");
    if ((pont_arquivo = fopen(nome_arquivo, "r")) != NULL) {

        printf("\nVisulizando");
        char nome[MAX];
        char codigo[MAX];
        char preco[MAX];
        char quantidade[MAX];
 
        fgets(nome, MAX, pont_arquivo);
        printf("\nNome: %s", nome);

        fgets(codigo, MAX, pont_arquivo);
        printf("Codigo: %s", codigo);

        fgets(preco, MAX, pont_arquivo);
        printf("Preco: %s", preco);

        fgets(quantidade, MAX, pont_arquivo);
        printf("Quantidade: %s", quantidade);

        fclose(pont_arquivo);
    } else {
        printf("Mantimento nao existe!\n");
    }
}

//Função editar mantimento
void editarMantimento() {
    char nomeNovo[MAX];
    char codigoAux[MAX];
    char precoNovoAux[MAX];
    char quantidadeNovaAux[MAX];
    int codigoNovo = 0;
    float precoNovo = 0;
    int quantidadeNova = 0;
    
    int codigoEditar = 0;
    int resposta = 0;
    printf("Informe o codigo do mantimento para editar\n");
    scanf("%d", &codigoEditar);

    FILE* pont_arquivo;
    char nome_arquivo[MAX_ARQ];
    snprintf(nome_arquivo, MAX_ARQ, "estoque-%d%s", codigoEditar, ".txt");
    if ((pont_arquivo = fopen(nome_arquivo, "r")) != NULL) {

        //Pegando as variaveis
        fgets(nomeNovo, MAX, pont_arquivo);
        fgets(codigoAux, MAX, pont_arquivo);
        fgets(precoNovoAux, MAX, pont_arquivo);
        fgets(quantidadeNovaAux, MAX, pont_arquivo);

        //Função que passa de string para outro tipo de variavel
        sscanf(precoNovoAux, "%f", &precoNovo);
        sscanf(quantidadeNovaAux, "%d", &quantidadeNova);
        sscanf(codigoAux, "%d", &codigoNovo);

        while(resposta != 4) {
            printf("Escolha o que deseja editar\n1 - Nome\n2 - Preco\n3 - Quantidade\n4 - Sair\n");
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
                    printf("Informe a nova quantidade: ");
                    scanf("%d", &quantidadeNova);
                break;
            }
        }   
        fclose(pont_arquivo);
        remove(nome_arquivo);

        FILE* pont_arquivo_novo;
        pont_arquivo_novo = fopen(nome_arquivo, "w");
        fprintf(pont_arquivo_novo, "%s%d\n%.2f\n%d", nomeNovo, codigoNovo, precoNovo, quantidadeNova);
        fclose(pont_arquivo_novo);
        
        printf("O item foi atualizado com sucesso!\n");
    } else {
        printf("Mantimento nao existe!\n");
    }
}

//Função deletar mantimento
void deletarMantimento() {
    int codigoDeletar = 0;
    printf("Informe o codigo do mantimento para deletar");
    scanf("%d", &codigoDeletar);

    FILE* pont_arquivo;
    char nome_arquivo[MAX_ARQ];
    snprintf(nome_arquivo, MAX_ARQ, "estoque-%d%s", codigoDeletar, ".txt");
    if ((pont_arquivo = fopen(nome_arquivo, "w")) != NULL) {
        fclose(pont_arquivo);
        remove(nome_arquivo);
        printf("O mantimento foi deletado!");
    } else {
        printf("Mantimento nao existe!");
    }
}

/*
int quantIng(int codigo) {
    char quantAux[MAX];
    int quant = 0;
    FILE* pont_arquivo;
    char nome_arquivo[MAX_ARQ];
    snprintf(nome_arquivo, MAX_ARQ, "estoque-%d%s", codigo, ".txt");
    if ((pont_arquivo = fopen(nome_arquivo, "w")) != NULL) {
        fgets(quantAux, MAX, pont_arquivo);
        sscanf(quantAux, "%d", &quant);
        fclose(pont_arquivo);
    }
    return quant;
}*/

//Vai ser a função. menu do estoque
void main_estoque() {  
    int escolha = 0;
    printf("### Estoque ###");
    while(escolha != 5) {
        printf("\n\nEscolha umas das opcoes abaixo");
        printf("\n1 - Cadastrar\n2 - Visualizar\n3 - Editar\n4 - Deletar\n5 - Sair\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                cadastrarMantimento();
            break;

            case 2:
                visualizarMantimento();
            break;

            case 3:
                editarMantimento();
            break;

            case 4:
                deletarMantimento();
            break;
        }
    }
}