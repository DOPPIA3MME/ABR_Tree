#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include "Progetto2.h"


TreeT initNodeT(int k)
{

    TreeT T = malloc(sizeof(struct TTreeT));
    T->key = k;
    T->top = NULL;   //Per gestire la lista
    T->sx = NULL;
    T->dx = NULL;
    return T;
}




void StampaLista(List top)
{
   if(top!=NULL)
     {
         printf("->[%d]",top->key);
         StampaLista(top->next);
     }

}





void preOrderT(TreeT T)
{

    if(T != NULL)
    {
        printf(" %d",T->key);


        StampaLista(T->top);

        preOrderT(T->sx);
        preOrderT(T->dx);
    }



}



List Inserimento_in_Testa(List top,int key)
{
       List tmp;

       tmp=malloc(sizeof(struct LList));
       tmp->key=key;
       tmp->next=top;

       return tmp;
}






TreeT insertNodeT(TreeT T, int key)
{

    if (T == NULL)
        T = initNodeT(key);
    else
    {
         if (T->key > key)
            T->sx = insertNodeT(T->sx,key);
         else if (T->key < key)
            T->dx = insertNodeT(T->dx,key);
         else
            T->top=Inserimento_in_Testa(T->top,key);
    }

    return T;
}






TreeT RandomTreeT(int n)
{
    int i = 0;
    TreeT T = NULL;


    for (i=0;i<n;i++)
    {
        T = insertNodeT(T,rand()%100);
    }




    return T;
}



int heightT(TreeT T)
{
      //Se l'albero è vuoto non esiste altezza (-1)
     if(T == NULL)
        return -1;

     return 1+max(heightT(T->sx),heightT(T->dx));

}


float height_mediaT(int n_nodi,int n_volte)
{
    TreeT T=NULL;
    int i,altezza=0,somma_h=0;

    for(i=0;i<n_volte;i++)
    {
       T=RandomTreeT(n_nodi);            //Creo n_volte alberi di tipo T
       altezza=heightT(T);
       somma_h=somma_h+altezza;
    }

    return (float)somma_h/n_volte;
}



List freeList(List top)
{
    if(top)
    {
        freeList(top->next);
        free(top);
    }

    return NULL;
}



TreeT freeTreeT(TreeT T)
{
     if(T)
     {
         freeList(T->top);
         freeTreeT(T->sx);
         freeTreeT(T->dx);
         free(T);
     }

     return NULL;
}





List CancellaNodoLista(List top)
{
  if (top == NULL)
    return NULL;


    List tmp;
    tmp = top->next;
    free(top);


    return tmp;
}





TreeT FindNodeDxMin(TreeT T)
{
    if(T->sx!=NULL)
        return FindNodeDxMin(T->sx);

        return T;

}



TreeT DeleteNodefromT(TreeT T, int key)
{

  if (T == NULL)
  {
     printf("\nElemento non trovato\n");
     return NULL;
  }
  if (key<T->key)
  {
      T->sx = DeleteNodefromT(T->sx, key);
  }
  else if (key > T->key)
  {
      T->dx = DeleteNodefromT(T->dx, key);
  }
  else
  {

             // case 1: senza figli
             if (T->sx == NULL && T->dx == NULL)
             {
                  if(T->top!=NULL)
                     T->top=CancellaNodoLista(T->top);
                  else
                  {
                    free(T);
                    T = NULL;
                  }
             }
             // case 2: un figlio (dx)
             else if (T->sx == NULL)
            {
                  if(T->top!=NULL)
                      T->top=CancellaNodoLista(T->top);
                  else
                  {
                    TreeT temp = T;
                    T = T->dx;
                    free(temp);
                  }
             }
             // case 3: un figlio (sx)
             else if (T->dx == NULL)
            {
                  if(T->top!=NULL)
                     T->top=CancellaNodoLista(T->top);
                  else
                  {
                    TreeT temp = T;
                    T = T->sx;
                    free(temp);
                  }
             }
             else         // case 4: due figli
             {
                          if(T->top!=NULL)
                             T->top=CancellaNodoLista(T->top);
                          else
                         {

                             TreeT nodo_destro_min=FindNodeDxMin(T->dx);          //Cerco il minimo nodo destro
                             T->key=nodo_destro_min->key;                        //sostituisco il valore del padre con quello appena trovato
                             T->top=nodo_destro_min->top;                        //e gli collego la lista
                             nodo_destro_min->top=NULL;                          //scollego la lista dal nodo minimo
                             T->dx=DeleteNodefromT(T->dx,nodo_destro_min->key);  //e infine lo cancello
                         }
             }
  }

     return T;
}

















