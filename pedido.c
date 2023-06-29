#include <stdio.h>
#include <stdlib.h>
#include "cardapio.c"
#include "estoque.c"
/*
• O sistema deve calcular o preço de venda das comidas, que será o lucro.
• O sistema deve registrar o custo total dos mantimentos utilizados em cada porção da
comida pedida.*/

//Defeni tamanhos para os tamanhos do vetores
#define MAX 100 //Para o nome do cliente
#define MAX_ARQ 50 //Para o nome do arquivo

//Função cadastar pedido
void cadastrarPedido() {
    char nomeCliente[MAX];
    int codigoPedido = 0;
    int comidaPedida = 0;
    int quantComida = 0;

    printf("Digite o nome do cliente: ");
    fflush(stdin);
    fgets(nomeCliente, MAX, stdin);

    printf("Digite o codido do pedido: ");
    scanf("%d", &codigoPedido);

    printf("Digite o codigo da comida a ser pedida:");
    scanf("%d", &comidaPedida);

    printf("Digite a quantidade de comida: ");
    scanf("%d", &quantComida);

    //Calculando o lucro
    float preco = precoComida(comidaPedida);
    float lucro = preco*quantComida;
    float saldo = saldoAtual();
    FILE* pont_arquivo_saldo;
    pont_arquivo_saldo = fopen("saldo.txt", "r");
    if (pont_arquivo_saldo != NULL) {
        fclose(pont_arquivo_saldo);
        remove("saldo.txt");

        pont_arquivo_saldo = fopen("saldo.txt", "w");
        float saldoFinal = saldo + lucro;
        fprintf(pont_arquivo_saldo, "%.2f", saldoFinal);
        fclose(pont_arquivo_saldo);

        //Criando e adicionando a comida
        FILE* pont_arquivo;
        char nome_arquivo[MAX_ARQ];
        snprintf(nome_arquivo, MAX_ARQ, "pedido-%d%s", codigoPedido, ".txt");
        pont_arquivo = fopen(nome_arquivo, "w");
        fprintf(pont_arquivo, "%s%d\n%d\n%d", nomeCliente, codigoPedido, comidaPedida, quantComida);
        fclose(pont_arquivo);

        printf("O pedido feito com sucesso!");
    } else {
        printf("Erro em atualizar saldo");
    }
}

//Função vissualizar pedido
void visualizarPedido() {
    int codigoVisualizar = 0;
    printf("Informe o codigo do pedido para visualizar\n");
    scanf("%d", &codigoVisualizar);

    FILE* pont_arquivo;
    char nome_arquivo[MAX_ARQ];
    snprintf(nome_arquivo, MAX_ARQ, "pedido-%d%s", codigoVisualizar, ".txt");
    if ((pont_arquivo = fopen(nome_arquivo, "r")) != NULL) {

        printf("\nVisulizando");
        char nomeCliente[MAX];
        char codigoPedido[MAX];
        char comidaPedida[MAX];
        char quantComida[MAX];
        //struct Pedido lista [MAX];
 
        fgets(nomeCliente, MAX, pont_arquivo);
        printf("\nNome: %s", nomeCliente);

        fgets(codigoPedido, MAX, pont_arquivo);
        printf("Codigo: %s", codigoPedido);

        fgets(comidaPedida, MAX, pont_arquivo);
        printf("Comida: %s", comidaPedida);

        fgets(quantComida, MAX, pont_arquivo);
        printf("Quantidade: %s", quantComida);
        
        fclose(pont_arquivo);
    } else {
        printf("O pedido nao existe!\n");
    }   
}

//Função editar pedido
void editarPedido() {
    char codigoPedidoAux[MAX];
    char comidaPedidaAux[MAX];
    char quantComidaAux[MAX];

    char nomeNovo[MAX];
    int codigoNovo = 0;
    int comidaNova = 0;
    int quantNova = 0;
    
    int codigoEditar = 0;
    int resposta = 0;
    printf("Informe o codigo do pedido para editar\n");
    scanf("%d", &codigoEditar);

    FILE* pont_arquivo;
    char nome_arquivo[MAX_ARQ];
    snprintf(nome_arquivo, MAX_ARQ, "pedido-%d%s", codigoEditar, ".txt");
    if ((pont_arquivo = fopen(nome_arquivo, "r")) != NULL) {

        //Pegando as variaveis
        fgets(nomeNovo, MAX, pont_arquivo);
        fgets(codigoPedidoAux, MAX, pont_arquivo);
        fgets(comidaPedidaAux, MAX, pont_arquivo);
        fgets(quantComidaAux, MAX, pont_arquivo);

        //Função que passa de string para outro tipo de variavel
        sscanf(codigoPedidoAux, "%d", &codigoNovo);
        sscanf(comidaPedidaAux, "%d", &comidaNova);
        sscanf(quantComidaAux, "%d", &quantNova);

        while(resposta != 4) {
            printf("Escolha o que deseja editar\n1 - Nome\n2 - Comida\n3 - Quantidade\n4 - Sair\n");
            scanf("%d", &resposta);

            switch(resposta) {
                case 1:
                    printf("Informe o novo nome: ");
                    fflush(stdin);
                    fgets(nomeNovo, MAX, stdin);
                break;

                case 2:
                    printf("Informe a nova comida pedida: ");
                    scanf("%d", &comidaNova);
                break;

                case 3:
                    printf("Informe a nova quantidade: ");
                    scanf("%d", &quantNova);
                break;
            }
        }   
        fclose(pont_arquivo);
        remove(nome_arquivo);

        FILE* pont_arquivo_novo;
        pont_arquivo_novo = fopen(nome_arquivo, "w");
        fprintf(pont_arquivo_novo, "%s%d\n%d\n%d", nomeNovo, codigoNovo, comidaNova, quantNova);
        fclose(pont_arquivo_novo);
        
        printf("O pedido foi atualizado com sucesso!\n");
    } else {
        printf("Pedido nao existe!\n");
    }
}

//Função deletar pedido
void deletarPedido() {
    int codigoDeletar = 0;
    printf("Informe o codigo do pedido para deletar");
    scanf("%d", &codigoDeletar);

    FILE* pont_arquivo;
    char nome_arquivo[MAX_ARQ];
    snprintf(nome_arquivo, MAX_ARQ, "pedido-%d%s", codigoDeletar, ".txt");
    if ((pont_arquivo = fopen (nome_arquivo, "w")) != NULL) {
        fclose(pont_arquivo);
        remove(nome_arquivo);
        printf("O pedido foi removido!");
    } else {
        printf("O pedido nao existe!");
    }
}

void main_pedido() {  
    int escolha = 0;
    printf("### Pedido ###");
    while(escolha != 5) {
        printf("\n\nEscolha umas das opcoes abaixo");
        printf("\n1 - Cadastrar\n2 - Visualizar\n3 - Editar\n4 - Deletar\n5 - Sair\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                cadastrarPedido();
            break;

            case 2:
                visualizarPedido();
            break;

            case 3:
                editarPedido();
            break;

            case 4:
                deletarPedido();
            break;
        }
    }
}