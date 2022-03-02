typedef struct _substancia {
    int restricao;
    char nome[20];
}subst;

typedef struct _frasco {
    subst a;
    int vol; //ml
}frasco;

typedef struct _prateleira {
    frasco vetFrascos[10];
    int numFrascos;
}prat;

typedef struct _armario {
    prat vetPrat[5];
}arm;

typedef struct _laboratorio {
    arm vetArm[5];
    int numArm;
    int numeroSubst;
    int confirm;

}lab;

    lab config_num_armarios();

    lab config_num_frascos(lab laboratorio);

    lab registrar_frascos_substancias(lab laboratorio);

    lab retirar_frasco(lab laboratorio);

    lab definir_nivel_restricao (lab laboratorio);

    void mostrar_matriz_restricao(lab laboratorio);





