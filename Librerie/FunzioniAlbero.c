#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include "Progetto2.h"
int truedim=0;                //dimensione reale del mergedArray (NON conterra' eventuali doppioni tra A1 e A2)



Tree initNode(int k)
{
    Tree T = malloc(sizeof(struct TTree));
    T->key = k;
    T->sx = NULL;
    T->dx = NULL;
    return T;
}




Tree insertNode_SenzaDoppioni(Tree T,int key)
{

    if (T == NULL)
        T = initNode(key);
    else
    {
         if (T->key > key)
         {
            T->sx = insertNode_SenzaDoppioni(T->sx,key);
         }
         else if (T->key < key)
         {
              T->dx = insertNode_SenzaDoppioni(T->dx,key);
         }
         else   //doppione
         {
             insertNode_SenzaDoppioni(T,rand()%100);
         }

    }

    return T;
}



void preOrder(Tree T)
{
    if(T != NULL)
    {
        printf("%d ", T->key);
        preOrder(T->sx);
        preOrder(T->dx);
    }

}



void StampaGrafica(Tree T)
{
    if (T == NULL)
        return;

    printf("%d ",T->key);

    if(T->sx != NULL)
        printf("(L:%d)",T->sx->key);
    if(T->dx != NULL)
        printf("(R:%d)",T->dx->key);
    printf("\n");

    StampaGrafica(T->sx);
    StampaGrafica(T->dx);
}



Tree RandomTree(int num_nodi)
{
    int i = 0;
    Tree T = NULL;

    for (i=0;i<num_nodi;i++)
    {
        T = insertNode_SenzaDoppioni(T,rand()%100);
    }


    return T;
}



void Pulisci()
{
   printf("\n\nPremi Enter per continuare... ");
     char prev=0;

        while(1)
        {
            char c = getchar();

            if(c == '\n' && prev == c)
            {

                system("@cls||clear");
                break;
            }

            prev = c;
        }

}






Tree freeTree(Tree T)
{
         if(T)
         {
              freeTree(T->sx);
              freeTree(T->dx);
              free(T);
         }

         return NULL;
}









int max(int a, int b)
{
    if(a>=b)
        return a;
    else
        return b;
}



int height(Tree T)
{
      //Se l'albero è vuoto non esiste altezza (-1)
     if(T == NULL)
        return -1;

     return 1+max(height(T->sx),height(T->dx));

}






Tree rightRotate(Tree a)
{
    Tree b = a->sx;
    Tree c = b->dx;


    b->dx = a;
    a->sx = c;


    return b;
}


Tree leftRotate(Tree a)
{
    Tree b = a->dx;
    Tree c = b->sx;


    b->sx = a;
    a->dx = c;


    return b;
}





int Calcola_IndiceBilanciamento(Tree T)
{
    if (T == NULL)
        return 0;

    return height(T->sx)-height(T->dx);
}






Tree insert_in_AVL(Tree AVL, int key)
{

    if (AVL == NULL)
        return initNode(key);

    if(key < AVL->key)
        AVL->sx  = insert_in_AVL(AVL->sx,key);
    else if(key > AVL->key)
        AVL->dx = insert_in_AVL(AVL->dx,key);




    //Calcola l'indice di bilanciamento, per vedere se dopo l'inserimento di un nodo l'albero è bilanciato
    int balance = Calcola_IndiceBilanciamento(AVL);

    // Se l'indice non sarà compreso tra -1 e 1 vuol dire che l'albero è sbilanciato, quindi ci sono 4 casi possibili :


    // Left Left Case
    if (balance>1 && key<AVL->sx->key)
    {
         return rightRotate(AVL);
                                //ruota a destra la radice
    }

    // Right Right Case
    if (balance < -1 && key > AVL->dx->key)
    {
         return leftRotate(AVL);
                                 //ruota a sinistra la radice
    }

    // Left Right Case
    if (balance > 1 && key > AVL->sx->key)
    {
        AVL->sx = leftRotate(AVL->sx);
                                            //ruota a sinistra il figlio sinistro
        return rightRotate(AVL);
                                           //poi ruota a destra la radice
    }

    // Right Left Case
    if (balance < -1 && key < AVL->dx->key)
    {
        AVL->dx = rightRotate(AVL->dx);
                                         //ruota a destra il figlio destro
        return leftRotate(AVL);
                                        //poi ruota a sinistra la radice
    }

    return AVL;
}




Tree CreaAVL(Tree AVL,Tree T)
{
    if(T==NULL)
        return AVL;
     else
     {
        AVL=insert_in_AVL(AVL,T->key);
        AVL=CreaAVL(AVL,T->sx);
        AVL=CreaAVL(AVL,T->dx);
     }

}




Tree ROTATION(Tree T,char direzione,int n)
{

            Tree AVL=NULL;


            if(n==0&&direzione!='b')
            {
                printf("\nNumero di rotazioni richiesto effettuato\n");
                return T;
            }
            if(T->sx==NULL&&direzione=='r')
            {
                 printf("\nNumero massimo di rotazioni a destra raggiunto");
                 return T;
            }
            else if(T->dx==NULL&&direzione=='l')
            {
                 printf("\nNumero massimo di rotazioni a sinistra raggiunto");
                 return T;
            }


            if(direzione=='l')
            {
                printf("\nRotazione a sinistra");
                T=leftRotate(T);
                T=ROTATION(T,direzione,n-1);
            }
            else if(direzione=='r')
            {
                printf("\nRotazione a destra");
                T=rightRotate(T);
                T=ROTATION(T,direzione,n-1);
            }

            //Se la direzione e' b,l'utente avrà scelto di bilanciare l'albero T
            if(direzione=='b')
            {
                AVL=CreaAVL(AVL,T);
                freeTree(T);
                return AVL;
            }

}






//DA CANCELLARE
int isBalanced(Tree T)
{
   int lh;      //Per l'altezza del sottoalbero sinistro
   int rh;      //Per l'altezza del sottoalbero destro

  //Se l'albero è vuoto è bilanciato
   if(T == NULL)
       return 1;


   lh = height(T->sx);
   rh = height(T->dx);



    //il valore assoluto della differenza tra le altezze
      if(abs(lh-rh) <= 1 && isBalanced(T->sx) && isBalanced(T->dx))
         return 1;




      //Se siamo arrivati a questo punto vuol dire che l'albero non è bilanciato
      return 0;
}






int* Crea_Array(int n)
{
	int* A;
	A = (int *)malloc (n*(sizeof(int)));

	return A;
}



void Stampa_Array(int *A, int n)
{
	int i;

	for(i=0; i<n; i++)
          printf("%d ",A[i]);

}



Tree ABRfromSortedArray(Tree T,int* A_ordinato,int start,int end)
{

    if (start>end)
      return NULL;

    //Prendo l'elemento di mezzo che sarà la radice
    int mid = (start+end)/2;
     T = initNode(A_ordinato[mid]);


    //costruzione del sottoalbero sinistro
    T->sx = ABRfromSortedArray(T,A_ordinato,start,mid-1);

    //costruzione del sottoalbero destro
    T->dx = ABRfromSortedArray(T,A_ordinato,mid+1,end);

    return T;
}





int* MergeSortedArrays(int* A1, int* A2, int n1, int n2)
{
  int dim=0;


    int* mergedA=Crea_Array(n1+n2);
    int i=0,j=0,k=0;


    while (i < n1 && j < n2)
    {

        if (A1[i]<A2[j])
        {
            mergedA[k] = A1[i];
            i++;
        }
        else if(A1[i]>A2[j])
        {
            mergedA[k] = A2[j];
            j++;
        }
        else                   //gestione dei doppioni
        {
            mergedA[k] = A1[i];
            dim++;
            i++;
            j++;
        }

        k++;
    }


    while (i < n1)
    {
        mergedA[k] = A1[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        mergedA[k] = A2[j];
        j++;
        k++;
    }

    truedim=(n1+n2)-dim;


    //Se ci sono stati dei doppioni nei due array allora la dimensione di mergedA dovrà essere riallocata
    if(dim>0)
        mergedA=realloc(mergedA,truedim * sizeof(int));


    return mergedA;
}




void CreaSortedArray(Tree T, int* A,int *i)
{

    if (T == NULL)
        return;

    CreaSortedArray(T->sx,A,i);

    A[*i] = T->key;
    (*i)++;


    CreaSortedArray(T->dx,A,i);
}







Tree MERGE(Tree T1, Tree T2, int n1, int n2)
{

    int *A1 = Crea_Array(n1);
    int i = 0;
    CreaSortedArray(T1,A1,&i);




    int *A2 = Crea_Array(n2);
    int j = 0;
    CreaSortedArray(T2, A2, &j);



    int* mergedA = MergeSortedArrays(A1,A2,n1,n2);


    //Dealloco la memoria occupata da T1
    T1=freeTree(T1);

    //Restituisco nel main il nuovo T1
    return ABRfromSortedArray(T1,mergedA,0,truedim-1);
}







int Menu()
{
    int scelta;

     printf("\t\t\t\t\tProgetto2 - Gruppo 13\n\t\t\t  Maurizio Minieri - Alessio Spina - Domenico Maione");

    printf("\n\nx-----------------------------------------------------------------x");
             printf("\n| 0) EXIT\t\t\t\t\t\t\t  |\n| 1) Per creare l'albero ABR T random\t\t\t\t  |\n| 2) Per inserire un elemento in T\t\t\t\t  |\n| 3) Per cancellare un elemento da T\t\t\t\t  |\n| 4) Per eseguire height_mediaT()");
             printf("\t\t\t\t  |\n|\t\t\t--------------------\t\t\t  |\n| 5) Per fare la MERGE tra due ABR T1 e T2\t\t\t  |\n| 6) Per eseguire la funzione ROTATION di un ABR\t\t  |\n| 7) Per bilanciare un ABR attraverso ROTATION\t\t\t  |\n| 8) Per stampare graficamente un ABR a video\t\t\t  |\n");
           printf("x-----------------------------------------------------------------x");
            printf("\n  SCELTA = ");
            while (scanf("%d",&scelta) != 1)
            {
                 printf("Devi inserire un numero : ");
                 while (getchar() != '\n');
            }

    return scelta;
}







