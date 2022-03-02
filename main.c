#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "Entidade.h"


int menu () {


    char s[30];
    int escolha;


    printf("\t\t\t\t\t\t SEJA BEM-VINDO\n");
    printf("\t\t\t\t\tControle de Estoque de Substâncias\n");
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\tMenu:\n");
    printf("\t\tINSTRUÇÕES: INSIRA APENAS NÚMEROS. OBRIGADO!!!\n\n");
    printf("\t\t[1] Para configurar o número de armários e o número de substâncias\n");
    printf("\t\t[2] Para definir o nível de restrições entre pares de substâncias\n");
    printf("\t\t[3] Para mostrar a matriz de restrições\n");
    printf("\t\t[4] Para resgistrar fracos de uma substância no estoque\n");
    printf("\t\t[5] Para retirar do estoque um frasco de uma substância\n");
    printf("\t\t[6] Para sair\n");
    printf("\n");
    printf("-----------------------------------------------------------------------------------------------------------------------\n");

    do {
        printf("\tEntre com sua escolha: ");
        gets (s);
        escolha = atoi(s);
    } while (escolha < 1 || escolha > 6);


return escolha;
}


int main(){
            setlocale(LC_ALL,"");
    int escolha;
    int i, k, j;
    char flag = '0';
    lab laboratorio;

    laboratorio.numeroSubst = 0; //Inicializando num de armarios com zero para fazer a validação das etapas
    laboratorio.confirm = 0;

    do {

        escolha = menu();

        switch (escolha) {
        case 1:
            printf("\t\t***IFORMAÇÕES***\n");
            printf("\tCada armário possui 5 pratileiras\n");
            printf("\tCada pratileira comporta até 10 frascos\n");
            printf("\t----------------------------------------\n");
            laboratorio = config_num_armarios();
            laboratorio = config_num_frascos(laboratorio);
            system("pause");
            system("cls");
            break;
        case 2:
            if (laboratorio.confirm == 0) {
                printf("\n\tSem substâncias para alterar restrição\n");
                printf("\tPrimeiro cadastre as substâncias.\n");
                system("pause");
                system("cls");
            } else {
                mostrar_matriz_restricao(laboratorio);
                laboratorio = definir_nivel_restricao(laboratorio);
                system("pause");
                system("cls");
            }
            break;
        case 3:
            if (laboratorio.confirm == 0) {
                printf("\n\t\tMatriz Restrição vazia.\n");
                printf("\t--------------------------------------\n");
                system("pause");
                system("cls");
            }else {
            mostrar_matriz_restricao(laboratorio);
            system("pause");
            system("cls");
            }
            break;
        case 4:
            if (laboratorio.numeroSubst == 0) {
                printf("\n\tEscolha a primeira opção do menu para inserir a\n ");
                printf("\tquantidade de frascos que deseja armazenar.\n");
                system("pause");
                system("cls");
            } else {
                laboratorio = registrar_frascos_substancias(laboratorio);
                mostrar_matriz_restricao(laboratorio);
                system("pause");
                system("cls");
            }
            break;
        case 5:
            if (laboratorio.confirm == 0) {
                printf("\n\tNão há frascos no estoque.\n");
                system("pause");
                system("cls");
            } else {
                mostrar_matriz_restricao(laboratorio);
                laboratorio = retirar_frasco(laboratorio);
                system("pause");
                system("cls");
            }
            break;
        case 6:
            printf("\tEncerrando...\n");
            exit(0);
            break;
        }


    } while (flag == '0');


    return 0;
}
