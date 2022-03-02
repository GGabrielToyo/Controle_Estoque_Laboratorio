#include "Entidade.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>



lab config_num_armarios () {
            setlocale(LC_ALL,"");
    lab l;

    do {
        printf("\n\tEscolha n�mero de arm�rios entre 1 e 5 : ");
        scanf("%i", &l.numArm );
    }while (l.numArm <= 0 || l.numArm > 5);

    printf("\n");
return l;
}

lab config_num_frascos (lab laboratorio) {
            setlocale(LC_ALL,"");
    int i = 0,j = 0;
    int cont = 1;
    laboratorio.numeroSubst = 0;
    for (i = 0; i < laboratorio.numArm; i++) {
        printf("\tInsira quantidade de frascos por prateleira do arm�rio %d :\n", i + 1);
        for (j = 0; j < 5; j++) {
          do {
                printf("\tPrateleita %d :", cont);
                scanf("%i", &laboratorio.vetArm[i].vetPrat[j].numFrascos);
            }   while (laboratorio.vetArm[i].vetPrat[j].numFrascos < 0 || laboratorio.vetArm[i].vetPrat[j].numFrascos > 10);
        cont++;
        laboratorio.numeroSubst += laboratorio.vetArm[i].vetPrat[j].numFrascos;
        }
    cont = 1;
    }

return laboratorio;
}

lab registrar_frascos_substancias(lab laboratorio){
                setlocale(LC_ALL,"");
    int i, j, k, a, p, f;
    char nome_subs[20];
    int num_restricao;
    int cont1 = laboratorio.numeroSubst; //Contador de quantas subs faltam cadastrar
    int cont3 = 0;
    int contArm = 0;
    int contador_subs = 0;

    laboratorio.confirm = 1; //Confirma��o de que tem subst�ncias cadatradas

       printf("\t\tRegistrando as subst�ncias.\n");
        printf("\t-------------------------------------------------\n");

        for (i = 0; i < laboratorio.numArm; i++) { // Arm�rio
             contArm++;// armario 0 + 1 para printar qual arm�rio est�
             printf("\t\t\tArm�rio %d \n", contArm);
             printf("\t\t\t#########\n");
            for (k = 0; k < 5; k++) { //Prateleira
                    if (laboratorio.vetArm[i].vetPrat[k].numFrascos != 0) {
                     printf("\tPrateleira %d\n", k+1);// Prat 0 + 1 para printar qual prateleira est�
                    }
                    for (j = 0; j < laboratorio.vetArm[i].vetPrat[k].numFrascos; j++) { // Frascos
                        do {
                          printf("\tFaltam %d subst�ncias para cadastrar\n", cont1);
                          printf("\tEntre com o nome subst�ncia: ");
                          scanf("%s", &nome_subs);

                          if(cont3 != 0){
                             cont3 = 0;
                          } //nivel 1

                        // i do for Am�rio
                        // k do for Prateleira
                        for (f = 0; f < laboratorio.vetArm[i].vetPrat[k].numFrascos; f++) { // Percorrendo os frascos de cada prat
                                if ( (strcmp(laboratorio.vetArm[i].vetPrat[k].vetFrascos[f].a.nome, nome_subs) == 0) &&
                                    laboratorio.vetArm[i].vetPrat[k].vetFrascos[f].a.restricao == 1 ){
                                     cont3 = 1;
                                     printf("\n\tSubst�ncia j� existente com mesmo n�mero de restri��o nessa prateleira.\n");
                                }
                        }

                        // i do for Am�rio
                        for (p = 0; p < 5; p++) {
                            for (f = 0; f < laboratorio.vetArm[i].vetPrat[p].numFrascos; f++) {
                                if ( (strcmp( laboratorio.vetArm[i].vetPrat[p].vetFrascos[f].a.nome, nome_subs) == 0) &&
                                    laboratorio.vetArm[i].vetPrat[p].vetFrascos[f].a.restricao == 2 ){
                                     cont3 = 2;
                                     printf("\n\tSubst�ncia de n�vel 2 j� cadastrada nesse arm�rio.\n");
                                }
                            }
                        }

                        }while(cont3 == 1 || cont3 == 2);

                        contador_subs = 0;

                        for (a = 0; a < laboratorio.numArm; a++) {
                            for (p = 0; p < 5; p++) {
                                for (f = 0; f < laboratorio.vetArm[a].vetPrat[p].numFrascos; f++) {
                                    //Validando restri��o de subst�ncias que ja tenham um par cadastrado
                                    if( strcmp( laboratorio.vetArm[a].vetPrat[p].vetFrascos[f].a.nome, nome_subs) == 0 ){
                                        laboratorio.vetArm[i].vetPrat[k].vetFrascos[j].a.restricao = laboratorio.vetArm[a].vetPrat[p].vetFrascos[f].a.restricao;
                                        contador_subs++;
                                    }
                                }
                            }
                        }


                        if(contador_subs == 0) {
                                printf("\tEntre com a restri��o da subst�ncia [0],[1] ou [2] : ");
                                scanf("%d", &num_restricao);
                               laboratorio.vetArm[i].vetPrat[k].vetFrascos[j].a.restricao = num_restricao;
                        }

                        cont1--; //Contador de quantas subs faltam cadastrar

                        strcpy(laboratorio.vetArm[i].vetPrat[k].vetFrascos[j].a.nome, nome_subs);

                        printf("\t------------------------------\n");

                    }
            }
        }

 return laboratorio;

}

 void mostrar_matriz_restricao (lab laboratorio) {
                setlocale(LC_ALL,"");
    int i = 0;
    int k = 0;
    int j = 0;
    int cont1 = 1;


        printf("\n");
        printf("\tInforma��es da Matriz Restri��o.\n");
            for (i = 0; i < laboratorio.numArm; i++) {
                printf("\n\t\t\t\t\t\tARM�RIO %d\n", cont1++);
                printf("\t----------------------------------------------------------------------------------------\n");
                for (k = 0; k < 5; k++) {
                    for (j = 0; j < laboratorio.vetArm[i].vetPrat[k].numFrascos; j++) {
                        printf("\t%s ", laboratorio.vetArm[i].vetPrat[k].vetFrascos[j].a.nome);
                         printf("%i", laboratorio.vetArm[i].vetPrat[k].vetFrascos[j].a.restricao);
                    }
                        printf("\n\t----------------------------------------------------------------------------------------\n");
                }

            }


return 0;
}

lab retirar_frasco (lab laboratorio) {
            setlocale(LC_ALL,"");
    int i, k, j;
    char exclui_subs[20];
   // int res_cmp;
    printf("\t\t***INFORMA��ES***\n");
    printf("\tSer� atribu�do ao nome da subst�ncia exclu�da 'EX'\n");
    printf("\te a restri��o '-1'\n");
    printf("\tEntre com n�mero do arm�rio que deseja editar: ");
    scanf("%d", &i);//Pergunta qual arm�rio
    printf("\tEntre com n�mero da prateleira: ");
    scanf("%d", &k);// Pergunta qual prateleira
    printf("\tEntre com nome da subst�ncia: ");
    scanf("%s", &exclui_subs);//Pergunta qual subst�ncia

    i = i - 1;
    k = k - 1;
                    // Arm�rio = i
                    // Prateleira = k
                    for (j = 0; j < laboratorio.vetArm[i].vetPrat[k].numFrascos; j++) {
                            if (strcmp(laboratorio.vetArm[i].vetPrat[k].vetFrascos[j].a.nome, exclui_subs) == 0) {
                                strcpy(laboratorio.vetArm[i].vetPrat[k].vetFrascos[j].a.nome, "EX");
                                laboratorio.vetArm[i].vetPrat[k].vetFrascos[j].a.restricao = -1;
                            }
                    }



return laboratorio;
}

lab definir_nivel_restricao (lab laboratorio) {
     int i, k, j, a, p, f;
    char modifica_subs[20];
    int modifica_restricao;
    int cont_subs = 0;
    int cont_modifica = 0;

    printf("\tEntre com n�mero do arm�rio que deseja editar: ");
    scanf("%d", &i);//Pergunta qual arm�rio
    printf("\tEntre com NOME da subst�ncia que deseja alterar o n�mero de restri��o: ");
    scanf("%s", &modifica_subs);//Pergunta qual subst�ncia

    do {
        printf("\tEntre com a nova RESTRI��O :");
        scanf("%d", &modifica_restricao);
    }while(modifica_restricao < 0 || modifica_restricao > 2);

    i = i - 1;

            if (modifica_restricao == 2) { //Modifica restri��o para 2
                        cont_subs = 0;

                    // Arm�rio = i
                     for (k = 0; k < 5; k++) {
                        for (j = 0; j < laboratorio.vetArm[i].vetPrat[k].numFrascos; j++) {
                            if (strcmp(laboratorio.vetArm[i].vetPrat[k].vetFrascos[j].a.nome, modifica_subs) == 0) {
                                        cont_subs++;
                            }
                        }
                     }

                     if (cont_subs == 1) {
                                // Arm�rio = i
                                for (k = 0; k < 5; k++) {
                                    for (j = 0; j < laboratorio.vetArm[i].vetPrat[k].numFrascos; j++) {
                                        if (strcmp(laboratorio.vetArm[i].vetPrat[k].vetFrascos[j].a.nome, modifica_subs) == 0) {
                                            laboratorio.vetArm[i].vetPrat[k].vetFrascos[j].a.restricao = modifica_restricao;
                                        }
                                    }
                                }
                     } else {
                            printf("\tModifica��o n�o autorizada pela quantidade de frascos dessa subst�ncia\n");
                     }
            }

            if (modifica_restricao == 1) {
                    // Arm�rio = i
                    for (k = 0; k < 5; k++) {
                        cont_subs = 0;
                        for (j = 0; j < laboratorio.vetArm[i].vetPrat[k].numFrascos; j++) {
                                if (strcmp(laboratorio.vetArm[i].vetPrat[k].vetFrascos[j].a.nome, modifica_subs) == 0) {
                                    cont_subs++;
                                }
                        }
                        if (cont_subs == 1) {
                                for (j = 0; j < laboratorio.vetArm[i].vetPrat[k].numFrascos; j++) {
                                    if (strcmp(laboratorio.vetArm[i].vetPrat[k].vetFrascos[j].a.nome, modifica_subs) == 0) {
                                        laboratorio.vetArm[i].vetPrat[k].vetFrascos[j].a.restricao = modifica_restricao;
                                    }
                                }
                        }
                    }
            }

            if (modifica_restricao == 0) {
                    // Arm�rio = i
                     for (k = 0; k < 5; k++) {
                        for (j = 0; j < laboratorio.vetArm[i].vetPrat[k].numFrascos; j++) {
                            if (strcmp(laboratorio.vetArm[i].vetPrat[k].vetFrascos[j].a.nome, modifica_subs) == 0) {
                                laboratorio.vetArm[i].vetPrat[k].vetFrascos[j].a.restricao = modifica_restricao;
                            }
                        }
                     }
            }

return laboratorio;
}
