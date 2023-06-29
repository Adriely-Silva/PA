#include <stdio.h>
#include <stdlib.h>
#include "pedido.c"
//#include "relatorio.c"

int main() {
    int casmenu = 0; 
    
    printf(" SEJA BEM VINDO AO MENU! \n");
    printf(" Selecione o comando que deseja:\n");
    printf("\n1 - Acessar o estoque\n2 - Acessar o cardapio\n3 - Fazer o pedido \n4 - Acessar o saldo\n5 - Acessar relatorio\n6 - Fechar o menu\n");
    scanf("%d", &casmenu);
    
    while(casmenu != 6) {
        switch (casmenu) {
            case 1:
                printf("Acesso ao estoque!\n");
                main_estoque();
            break;

            case 2:
                printf("Acesso ao cardapio!\n");
                main_cardapio();
            break;

            case 3:
                printf("Acesso ao pedido!\n");
                main_pedido();
            break;

            case 4:
                printf("Acesso ao saldo!\n");
                main_saldo();
            break;

            case 5:
                printf("Acesso ao relatorio!");
            break;

            case 6:
                printf("Finalizando o programa...\n");
                printf("\nPrograma finalizado :)");
            break;

            default:
                printf(" opcao invalida.\n\n");
            break;
        }

        printf("\n Selecione o comando que deseja:\n");
        printf("\n1 - Acessar o estoque\n2 - Acessar o cardapio\n3 - Fazer o pedido \n4 - Acessar o saldo\n5 - Acessar relatorio\n6 - Fechar o menu\n");
        scanf("%d", &casmenu);   
    }

    return 0;
}