#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
struct funcionario {
    char nome [32];
    int idade;
    int horas;
};
char c_empresa [64];
struct funcionario funcionarios [21];
struct funcionario funcionarios1 [21];
FILE *arq,*arq1_nome,*arq2_horas;
void menu (){   
    printf ("1 - Gerar Lista de Nomes \n");
    printf ("2 - Ordenar por Nome\n");
    printf ("3 - Ordenar por hora\n");
    printf ("4 - Imprimir lista\n");
    printf ("0 - Sair\n");
}
void gerarListaNomes (){ 
        arq = fopen ("funcionarios", "w");
        if ((arq=fopen("funcionarios", "w"))!=NULL){
            for (int i = 0 ; i < 3 ; i++){
                
                getchar ();
                printf ("Informe o nome do funcionario: ");
                gets(funcionarios[i].nome);
                
                printf ("\nInforme a idade do funcionario:");
                scanf ("%d", &funcionarios[i].idade);
                
                printf ("\nInforme as horas trabalhadas:");
                scanf("%d", &funcionarios[i].horas);
                    
                fprintf (arq, "empresa: %s | numero funcionario: %i | nome: %s | idade: %i | horas trabalhadas: %i | \n",c_empresa, i+1, funcionarios[i].nome, funcionarios[i].idade, funcionarios[i].horas);

            }
        }
    fclose (arq);

}

void OrdenarPorNome (){
 struct funcionario temp;
    for (int i = 0 ; i < 2 ; i++){
        for (int j = 0 ; j < 2 ; j ++ ){
        if (strcmp(funcionarios[j].nome,funcionarios[j+1].nome)>0){
            temp = funcionarios[j];
            funcionarios[j]=funcionarios[j+1];
            funcionarios[j+1]=temp;
            }
        }   
    }
     arq1_nome = fopen ("funcionarios_nomes", "w");
        if ((arq1_nome=fopen("funcionarios_nomes", "w"))!=NULL){
            for (int i = 0 ; i < 3 ; i++){                    
                fprintf (arq2_horas, "empresa: %s | numero funcionario: %i | nome: %s | idade: %i | horas trabalhadas: %i | \n",c_empresa, i+1, funcionarios[i].nome, funcionarios[i].idade, funcionarios[i].horas);

            }
        }
    fclose (arq1_nome);
    for (int i = 0 ; i < 3 ; i++){
        printf ("pessoa: %s idade: %i horas: %i\n", funcionarios[i].nome,funcionarios[i].idade, funcionarios[i].horas );
    }
}

void OrdenarPorHora (){
   
   struct funcionario temp;
    for (int i = 0 ; i < 2 ; i++){
        for (int j = 0 ; j < 2 ; j ++ ){
        if (funcionarios[j].horas>funcionarios[j+1].horas){
            temp = funcionarios[j];
            funcionarios[j]=funcionarios[j+1];
            funcionarios[j+1]=temp;
            }
        }   
    }
   arq2_horas = fopen ("funcionarios_horas", "w");
        if ((arq=fopen("funcionarios_horas", "w"))!=NULL){
            for (int i = 0 ; i < 3 ; i++){                    
                fprintf (arq2_horas, "empresa: %s | numero funcionario: %i | nome: %s | idade: %i | horas trabalhadas: %i | \n",c_empresa, i+1, funcionarios[i].nome, funcionarios[i].idade, funcionarios[i].horas);

            }
        }
    fclose (arq2_horas);
    for (int i = 0 ; i < 3 ; i++){
        printf ("pessoa: %s idade: %i horas: %i\n", funcionarios[i].nome,funcionarios[i].idade, funcionarios[i].horas );
    }

}
void ImprimirLista (){
    arq= fopen("funcionarios", "r");
    char cPalavra[64];
    if (arq == NULL){
        printf ("Erro ao abrir o arquivo\n");
        exit (1);
    }
    system ("cls");
    printf ("Buscando dados no arquivo, aguarde...\n");
    printf ("NUMERO DO FUNCIONARIO | IDADE | HORAS TRABALHADAS\n");
    getchar();
    while (fgets (cPalavra,64, arq)!=NULL){
        printf ("\n");
        printf (" %s  ",cPalavra);
    }   
    printf ("\n\n");
}

int main ( ){
    setlocale(LC_ALL, "Portuguese");
    int op;
    do {
    menu();
    scanf ("%d", &op);

    switch (op){
        case 1: 
        printf ("Informe o nome da empresa: ");
        scanf ("%s", c_empresa);
        printf ("Funcionarios da empresa %s\n", c_empresa);
        gerarListaNomes();
        break;
        case 2:
        OrdenarPorNome();
        break;
        case 3:
        OrdenarPorHora();
        break;
        case 4:
        ImprimirLista();
        break;
        case 0:
        break;
        default:
        printf ("Opcao invalida!");
        break;
    }

    }while (op!=0);
    return 0;
}
