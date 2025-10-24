/*

    Sistema de agendamento de pedidos para lanchonete

*/
#include <stdio.h>
#include <string.h>

#define maximo_de_pedidos 100
#define tamanho_nome 50

int main(){

    char nome_cliente[maximo_de_pedidos][tamanho_nome];
    char funcionario[3][tamanho_nome];
    char funcionario_nome[maximo_de_pedidos][tamanho_nome];
    char endereco[maximo_de_pedidos][tamanho_nome];
    char nome_lanche[maximo_de_pedidos][tamanho_nome];
    int id_lanche, id_funcionario;
    char continuar;
    int total=0, total_funcionario=0;

    printf("===CADASTRAR FUNCIONARIO===\n");
    while(1){
        printf("\nEntre com o nome do funcionario numero %d: ", total_funcionario + 1);
        scanf(" %[^\n]", funcionario[total_funcionario]);
       
        total_funcionario++;

        if (total_funcionario>=3)
        {
            break;
        }

    }

    continuar='s';

    printf("===CADASTRAR PEDIDO===");
    while (1)
    {
        printf("\nEntre com o nome do cliente: ");
        scanf(" %[^\n]", nome_cliente[total]);

        printf("===LANCHES===\n");
        printf("Digite 1 para Hamburguer\n");
        printf("Digite 2 para Salada\n");
        printf("Digite 3 para Misto\n");
        printf("Digite o lanche do pedido: ");
        scanf(" %d", &id_lanche);

        switch (id_lanche) 
        {
            case 1: strcpy(nome_lanche[total], "Hamburguer"); break;
            case 2: strcpy(nome_lanche[total], "Salada"); break;
            case 3: strcpy(nome_lanche[total], "Misto"); break;
            default: break;
        }

        printf("===ENDERECO DO CLIENTE==\n");
        printf("Digite o endereco do cliente: ");
        scanf(" %[^\n]", endereco[total]);

        printf("===FUNCIONARIO RESPONSAVEL==\n");
        printf("Digite 1 para %s\n", funcionario[0]);
        printf("Digite 2 para %s\n", funcionario[1]);
        printf("Digite 3 para %s\n", funcionario[2]);
        printf("Entre com o id do funcionario: ");
        scanf(" %d", &id_funcionario);

        switch (id_funcionario)
        {
            case 1: strcpy(funcionario_nome[total], funcionario[0]); break;
            case 2: strcpy(funcionario_nome[total], funcionario[1]); break;
            case 3: strcpy(funcionario_nome[total], funcionario[2]); break;
            default: break;
        }

        total++;

        printf("Deseja continuar? ");
        scanf(" %c", &continuar);

        if (continuar=='n' || continuar=='N')
        {
            break;
        }

        if (total>=maximo_de_pedidos)
        {
            break;
        }

    }

    for (int i = 0; i < total; i++) 
    {
        printf("===PEDIDO NUMERO %d===\n", i+1);
        printf("Cliente: %s\n", nome_cliente[i]);
        printf("Endereco: %s\n", endereco[i]);
        printf("Funcionario: %s\n", funcionario_nome[i]);
        printf("========================\n");
    }

    return 0;
}