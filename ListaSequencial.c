#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"


struct lista{
   int qtd;
   struct aluno dados[MAX];
};

Lista* criar_lista(){
   Lista* li;
   li = (Lista*) malloc (sizeof(struct lista));
   if (li != NULL)
      li->qtd = 0;
   return li;
}

void liberar_lista(Lista* li){
   free(li);
}

int tamanho_lista(Lista *li){
    if (li == NULL)
        return -1;
    else
        return li->qtd;
}

int lista_vazia(Lista *li){
    if(li == NULL)
        return -1;
    else
        return (li->qtd == 0);
}

int lista_cheia(Lista *li){
    if(li == NULL)
        return -1;
    else
        return (li->qtd == MAX);
}

int inserir_lista_inicio(Lista *li, struct aluno al){
    if (li == NULL)
        return 0;
    if(li->qtd == MAX)
        return 0;
    int i;
    for(i=li->qtd-1; i>=0; i--)
        li->dados[i+1] = li->dados[i];
    li->dados[0] = al;
    li->qtd++;
    return 1;
}

int inserir_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    if(li->qtd == MAX)
        return 0;
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

int inserir_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    if(li->qtd == MAX)
        return 0;
    int i,k = 0;
    while(i < li->qtd && li->dados[i].matricula < al.matricula)
        i++;
    for(k=li->qtd-1; k>=i; k--)
        li->dados[k+1] = li->dados[k];
    li->dados[i] = al;
    li->qtd++;
    return 1;
}

void imprimir_lista(Lista *li){
   int i;
   printf("-------------\n");
   for(i=0;i < li->qtd; i++){
      printf("Matricula: %d\n", li->dados[i].matricula);
      printf("Nome: %s\n",li->dados[i].nome);
        for(int k=0; k<3;k++){
              printf("Nota %d: %f\n",k,li->dados[i].nota[k]);
        }

      printf("-------------\n");
   }
}

int remover_lista_inicio(Lista *li){
    if (li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int k = 0;
    for(k=0;k < li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 1;
}

int remover_lista_final(Lista *li){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    li->qtd--;
    return 1;
}

int remover_lista(Lista *li, int mat){
    if (li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int k,i = 0;
    while(i < li->qtd && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd) //não encontrado
        return 0;

    for(k=i; k < li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 1;
}
int inserir_nota_mat(Lista *li,int matricula,float *notas){
    if(lista_cheia(li)||lista_vazia(li))
        return 0;
    else
        for(int i=0;i < li->qtd; i++){
            if (li->dados[i].matricula == matricula)
                for(int k=0;k<3;k++){
                    li->dados[i].nota[k]= notas[k];
                }
            else;
        }
}
float calcular_media(Lista *li, int matricula,float *notas){
    float media;
        if(lista_cheia(li)||lista_vazia(li))
        return 0;
    else
        for(int i=0;i < li->qtd; i++){
            if (li->dados[i].matricula == matricula)
                for(int k=0;k<3;k++){
                     notas[k]=li->dados[i].nota[k];
                     media= notas[k]+ media;
                }
            else;
        }
    return (media/3);
}
