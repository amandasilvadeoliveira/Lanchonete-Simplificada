/*

    Com o intuito de facilitar o processo de Digitação de pedidos de uma lanchonete,
    o sistema visa simplificar as principais entradas de dados para gravar um pedido

*/
#include <stdio.h>
#include <string.h> // foi utilizado a biblioteca string para facilitar na atribuição de dados as variaveis do tipo string

#define maximo_de_pedidos 100 // Definindo um numero maximo para pedidos
#define tamanho_nome 50 // Definindo o tamanho maximo de caracteres para as strings

int main(){

    char nome_cliente[maximo_de_pedidos][tamanho_nome];
    char funcionario[3][tamanho_nome];
    char funcionario_nome[maximo_de_pedidos][tamanho_nome];
    char endereco[maximo_de_pedidos][tamanho_nome];
    char nome_lanche[maximo_de_pedidos][tamanho_nome];
    int id_lanche, id_funcionario;
    char continuar;
    int total=0, total_funcionario=0;
    // Acima foram definidas todas as variaveis do sistema
    

    printf("===CADASTRAR FUNCIONARIO===\n");
    while(1){
        printf("\nEntre com o nome do funcionario numero %d: ", total_funcionario + 1);
        scanf(" %[^\n]", funcionario[total_funcionario]); // Entrada de dados o especificador " %[^\n]" indica que a entrada será finalizada ao clicar a tecla enter
       
        total_funcionario++;

        if (total_funcionario>=3)// Estrutura condicional para encerrar o while
        {
            break;
        }

    }
    // Acima foi definido o primeiro laço de repetição while, para definir quais são os funcionarios da lanchonete

    continuar='s'; // A variavel continuar recebe o valor 'S' para que o proximo laço continue

    printf("===CADASTRAR PEDIDO===");
    // Abaixo temos o principal laço de repetição que recebe os dados do pedido
    while (1)
    {
        printf("\nEntre com o nome do cliente: ");
        scanf(" %[^\n]", nome_cliente[total]); // entra com o nome do cliente

        printf("===LANCHES===\n");
        printf("Digite 1 para Hamburguer\n");
        printf("Digite 2 para Salada\n");
        printf("Digite 3 para Misto\n");
        printf("Digite o lanche do pedido: ");
        scanf(" %d", &id_lanche); // Entrada que define qual será o lanche 

        switch (id_lanche) 
        {
            case 1: strcpy(nome_lanche[total], "Hamburguer"); break; // Atribui o ID ao lanche desejado
            case 2: strcpy(nome_lanche[total], "Salada"); break;
            case 3: strcpy(nome_lanche[total], "Misto"); break;
            default: break;
        }

        printf("===ENDERECO DO CLIENTE==\n");
        printf("Digite o endereco do cliente: ");
        scanf(" %[^\n]", endereco[total]); // Armazena qual será o endereço do cliente

        printf("===FUNCIONARIO RESPONSAVEL==\n");
        printf("Digite 1 para %s\n", funcionario[0]);
        printf("Digite 2 para %s\n", funcionario[1]);
        printf("Digite 3 para %s\n", funcionario[2]);
        printf("Entre com o id do funcionario: ");
        scanf(" %d", &id_funcionario); //Entra com o ID do funcionario

        switch (id_funcionario)
        {
            case 1: strcpy(funcionario_nome[total], funcionario[0]); break; //Para amarrar ao pedido funcionario_nome recebe o valor do funcionario cadastrado
            case 2: strcpy(funcionario_nome[total], funcionario[1]); break;
            case 3: strcpy(funcionario_nome[total], funcionario[2]); break;
            default: break;
        }

        total++;

        printf("Deseja continuar? ");
        scanf(" %c", &continuar); // Pergunta se haverá mais pedidos

        if (continuar=='n' || continuar=='N') // Condição que enterrompe a repitição caso o usuario não queira continuar a Digitação
        {
            break;
        }

        if (total>=maximo_de_pedidos) // Condição que interrompe o laço caso o total de pedidos cadastrado alcance o maximo definido no começo
        {
            break;
        }

    }
    // O laço de repetição abaixo Exibe o pedido na tela para o usuario
    int i=0;
    while(i!=total) 
    {
        printf("===PEDIDO NUMERO %d===\n", i+1);
        printf("Cliente: %s\n", nome_cliente[i]);
        printf("Endereco: %s\n", endereco[i]);
        printf("Funcionario: %s\n", funcionario_nome[i]);
        printf("========================\n");
        i++;
    }

    return 0;

}

