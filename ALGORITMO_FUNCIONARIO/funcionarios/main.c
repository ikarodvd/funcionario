#include <stdio.h>
#include <stdlib.h>

void menu()
{

    printf ("1 -  Gerar Lista de Nomes\n");
    printf ("2 -  Ordenar por Nomes\n");
    printf ("3 -  Ordenar por Horas\n");
    printf ("0 - sair\n");
}

void gerarListadeNome (FILE* fp )
{
    char nome[50];
    if ((fp=fopen ("informacao.txt","w")) != NULL)
    {
        for(int i=0; i<21; i++)
        {
            printf("Escreva um nome: ");
            gets(nome);
            fprintf(fp, "Nome %d: %s\n", i+1, nome);
        }
    }
    fclose(fp);

}

void OrdenarPorNome()
{

}

void OrdenarPorHora()
{


}

struct TFuncionario
{
    int horas;
    int idade;
    char nome[40];
};

int main(int argc,char *argv[])
{
    FILE *fp;
    char nome[50];
    struct TFuncionario* funcionarios[21];
    int op=0;
    do
    {
        menu();
        scanf ("%i", &op);
        switch (op)
        {

        case 1:

            gerarListadeNome (fp);

            break;

        case 2:

            OrdenarPorNome();

            break;

        case 3:

            OrdenarPorHora();

            break;

        }
    }
    while (op !=0 );

    return 0;
}
