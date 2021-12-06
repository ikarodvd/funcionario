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
    printf ("2 - Imprimir lista\n");
    printf ("3 - Apagar arquivos\n");
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
    system ("pause");
    system ("cls");
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
                fprintf (arq1_nome, "empresa: %s | numero funcionario: %i | nome: %s | idade: %i | horas trabalhadas: %i | \n",c_empresa, i+1, funcionarios[i].nome, funcionarios[i].idade, funcionarios[i].horas);

            }
        }
        fclose (arq1_nome);
    for (int i = 0 ; i < 3 ; i++){
        printf ("pessoa: %s idade: %i horas: %i\n", funcionarios[i].nome,funcionarios[i].idade, funcionarios[i].horas );
    }
    system ("pause");
    system ("cls");
}



void OrdenarPorHora (){
   
   struct funcionario temp;
    for (int i = 0 ; i < 2 ; i++){
        for (int j = 0 ; j < 2 ; j ++ ){
        if (funcionarios[j].horas<funcionarios[j+1].horas){
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
system ("pause");
}


void ImprimirLista (){
    arq= fopen("funcionarios", "r");
    char cPalavra[64];
    if (arq == NULL){
        printf ("Erro ao abrir o arquivo\n");
        exit (1);
    }
    getchar();
    while (fgets (cPalavra,64, arq)!=NULL){
        printf ("\n");
        printf (" %s  ",cPalavra);
    }   
    printf ("\n\n");
    system ("pause");
    system ("cls");
}

void menu_case2 (){
    printf ("Como voce deseja exibir a lista?\n");
    printf (" 1 - Como foi salva. Obs> sem tratamento dos dados\n");
    printf (" 2 - Ordenada por horas\n");
    printf (" 3 - Ordenada por nomes\n");

}
void apagar (){
    arq = fopen ("funcionarios", "ab");

    printf ("Isso apagará todos os dados dos arquivos! Você tem certeza? y/n\n");
    char op;
    scanf ("%c", &op);
    if (op=='y'){
        remove (arq);
    }

    system ("pause");
    system ("cls");




}
int main ( ){
    setlocale(LC_ALL, "Portuguese");
    int op,op4;
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
        menu_case2 ();
        scanf ("%d", &op4);
            switch (op4)
            {
            case 1:
                ImprimirLista();
                break;
            case 2: 
                OrdenarPorHora();
            break;
            case 3: 
                OrdenarPorNome();
            break;

            default:
                printf ("Opção inválida!\n");
                break;
            }
        break;

        case 3: 
            apagar();
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