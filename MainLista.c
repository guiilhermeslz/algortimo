#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSequencial.h"

Lista* minha_lista;

struct aluno al;

int main()
{
    minha_lista = criar_lista();
    int escolha, matricula_aluno;
    float notas[3],media;

    do {
         printf("Digite algo\n  0 - Sair\n  1 - Preencher dados do Aluno\n  2 -Media do aluno(APROVACAO E REPROVACAO)\n  3 -Remova um Aluno \n");

         scanf(" %d", &escolha);

         switch(escolha) {
               case 0: //sair
                   printf("Escolheu sair do menu\n");
                   break;
               case 1: //preencher lista
                   printf("Digite o nome do Aluno \n");
                    scanf("%s",&al.nome);
                    printf("Digite a matricula do Aluno\n");
                    scanf("%d",&al.matricula);
                    printf("Digite tres notas do aluno\n");
                    for(int i=0; i<3; i++){
                        scanf("%f",&notas[i]);
                    };
                    inserir_lista_ordenada(minha_lista,al);
                    inserir_nota_mat(minha_lista,al.matricula,notas);
                    imprimir_lista(minha_lista);
                   break;
               case 2: //calcular media
                   printf("Digite a matricula do Aluno que deseja saber a media\n");
                   scanf("%d",&matricula_aluno);
                   media = calcular_media(minha_lista,matricula_aluno, notas);
                   printf("Media: %f",media);
                   if(media>=7)
                    printf("Esse aluno foi APROVADO\n");
                   else
                    printf("Esse aluno foi REPROVADO\n");
                   break;
               case 3: //telefone
                   printf("Escreva a matricula do aluno que deseja excluir:\n");
                   scanf("%d",&matricula_aluno);
                   remover_lista(minha_lista,matricula_aluno);
                   printf("Removido com sucesso\n");
                   imprimir_lista(minha_lista);
                   break;
               default:
                   printf("Escolheu uma opção inválida\n");
                   break;
         }
    } while (escolha != 0);



}
