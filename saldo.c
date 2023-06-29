#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//Mostrar saldo
void visualisarSaldo() {
    char saldo[MAX];
    FILE* pont_arq;
    pont_arq = fopen("saldo.txt", "r");
    if(pont_arq != NULL) {
        fflush(stdin);
        fgets(saldo, MAX, pont_arq);
        printf("O saldo atual e: R$%s",saldo);
    } else {
        printf("Não existe o arquivo");
    }
    fclose(pont_arq);
}

//Sacar dinheiro
void sacarDinheiro() {
    char saldo[MAX];
    float saldoAtual = 0;
    float dinheiroRetirado = 0;
    float saldoFinal = 0;

    FILE* pont_arq;
    pont_arq = fopen("saldo.txt", "r");
    if(pont_arq != NULL) {
        fgets(saldo, MAX, pont_arq);
        sscanf(saldo, "%f", &saldoAtual);

        printf("Digite o valor a ser sacado: ");
        scanf("%f", &dinheiroRetirado);
        fclose(pont_arq);

        if(dinheiroRetirado > saldoAtual){
            printf("Imposivel sacar o dinheiro\n");
        } else {
            saldoFinal = saldoAtual - dinheiroRetirado;
            remove("saldo.txt");

            FILE* pont_arquivo_novo;
            pont_arquivo_novo = fopen("saldo.txt", "w");
            fprintf(pont_arquivo_novo, "%.2f\n", saldoFinal);
            fclose(pont_arquivo_novo);
            
            printf("O dinheiro foi retirado com sucesso\n");
        }
        
        
    } else {
        printf("Não existe o arquivo\n");
    }    
}

//Depositar dinheiro
void depositarDinheiro() {
    char saldo[MAX];
    float saldoAtual = 0;
    float dinheiroDepositado = 0;
    float saldoFinal = 0;

    FILE* pont_arq;
    pont_arq = fopen("saldo.txt", "r");
    if(pont_arq != NULL) {
        fgets(saldo, MAX, pont_arq);
        sscanf(saldo, "%f", &saldoAtual);

        printf("Digite o valor a ser sacado: ");
        scanf("%f", &dinheiroDepositado);

        saldoFinal = saldoAtual + dinheiroDepositado;
        
        fclose(pont_arq);
        remove("saldo.txt");

        FILE* pont_arquivo_novo;
        pont_arquivo_novo = fopen("saldo.txt", "w");
        fprintf(pont_arquivo_novo, "%.2f\n", saldoFinal);
        fclose(pont_arquivo_novo);

        printf("O dinheiro foi depositado com sucesso\n");
    } else {
        printf("Não existe o arquivo\n");
    }    
}

//Mostrar saldo no atual momento -> Utilizamos essa função no estoque para se tinha possibilade de comprar o mantimento
float saldoAtual() {
    char saldo[MAX];
    float saldoAtual = 0;

    FILE* pont_arq;
    pont_arq = fopen("saldo.txt", "r");
    if(pont_arq != NULL) {
        fgets(saldo, MAX, pont_arq);
        sscanf(saldo, "%f", &saldoAtual);
        fclose(pont_arq);

        return saldoAtual;
    }

    return 0;
}

void main_saldo() {
    float saldo = 1000;
    FILE* pont_arq;
    pont_arq = fopen("saldo.txt", "w");
    if(pont_arq != NULL) {
        fprintf(pont_arq, "%.2f", saldo);
    } else {
        printf("Não existe o arquivo");
    }
    fclose(pont_arq);

    int escolha;
    printf("### Saldo ###");
    while(escolha != 4) {
        printf("\n\nEscolha umas das opcoes abaixo");
        printf("\n1 - Extrato\n2 - Sacar\n3 - Depositar\n4 - Sair\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                visualisarSaldo();
            break;

            case 2:
                sacarDinheiro();
            break;

            case 3:
                depositarDinheiro();
            break;
        }
    }
}