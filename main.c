#include <stdio.h>
#include <stdlib.h>
#include "Librerie/Progetto2.h"

int main()
{
     srand(time(NULL));

    TreeT T=NULL;                       //T ha una sua struttura specifica, top e' una lista collegata ad ogni nodo


    Tree T1=NULL;
    Tree T2=NULL;


    int scelta,n_volte,input_key;
    int n,n1,n2;
    char direzione,continua;






    do{
             scelta=Menu();
             switch(scelta)
             {
                 case 0:
                     printf("\nArrivederci\n");
                 break;

                 case 1:

                            if(T!=NULL)
                                T=freeTreeT(T);   //Libero la memoria allocata all'albero T iniziale, per crearne uno nuovo


                            printf("\nScrivi la dimensione di T : ");
                            while (scanf("%d",&n)!=1||n<1)
                            {
                                      printf("Devi inserire un numero intero positivo : ");
                                      while (getchar() != '\n');
                            }

                             T=RandomTreeT(n);

                             printf("\n\t\tSTAMPA T\n");
                             preOrderT(T);



                             Pulisci();
                 break;



                  case 2:

                         if(T==NULL)
                                printf("\nT VUOTO\n");
                         else
                         {

                                     printf("\n\t\tStampa T\n");
                                     preOrderT(T);


                                   printf("\n\nScrivi la key che vuoi inserire : ");
                                   while (scanf("%d",&input_key)!=1)
                                   {
                                      printf("Devi inserire un numero intero : ");
                                      while (getchar() != '\n');
                                   }

                                  T = insertNodeT(T,input_key);

                                  printf("\n\t\tSTAMPA T dopo insertNodeT()\n");
                                   preOrderT(T);
                          }



                                   Pulisci();


                 break;

                  case 3:

                         if(T==NULL)
                                printf("\nT vuoto\n");
                         else
                         {

                                   printf("\n\t\tSTAMPA T\n");
                                    preOrderT(T);

                                   printf("\n\nScrivi la key che vuoi cancellare : ");
                                   while (scanf("%d",&input_key)!=1)
                                   {
                                      printf("Devi inserire un numero intero : ");
                                      while (getchar() != '\n');
                                   }


                                    T=DeleteNodefromT(T,input_key);

                                  printf("\n\t\tSTAMPA T dopo DeleteNodefromT()\n");
                                   preOrderT(T);
                         }
                                  Pulisci();

                 break;

                 case 4 :

                     printf("\nScrivi la dimensione dei 1000 alberi di tipo T : ");
                            while (scanf("%d",&n)!=1||n<1)
                            {
                                      printf("Devi inserire un numero intero positivo : ");
                                      while (getchar() != '\n');
                            }


                             //numero nodi, numero di alberi da creare
                      printf("\nALTEZZA MEDIA : %f",height_mediaT(n,1000));
                      Pulisci();
                    break;

                  case 5:

                      if(T1!=NULL)
                                T1=freeTree(T1);   //Libero la memoria allocata all'albero T1 iniziale, per crearne uno nuovo
                      if(T2!=NULL)
                                T2=freeTree(T2);   //Libero la memoria allocata all'albero T2 iniziale, per crearne uno nuovo


                          printf("\nScrivi la dimensione di T1: ");
                            while (scanf("%d",&n1)!=1||n1<1||n1>100)
                            {
                                      printf("Devi inserire un numero intero positivo non > di 100 : ");
                                      while (getchar() != '\n');
                            }


                         T1=RandomTree(n1);



                        printf("\nScrivi la dimensione di T2: ");
                            while (scanf("%d",&n2)!=1||n2<1||n2>100)
                            {
                                      printf("Devi inserire un numero intero positivo non > di 100 : ");
                                      while (getchar() != '\n');
                            }



                        T2=RandomTree(n2);



                        printf("\n\t\tSTAMPA T1\n");
                             preOrder(T1);
                        printf("\n\t\tSTAMPA T2\n");
                             preOrder(T2);


                            T1 = MERGE(T1,T2,n1,n2);


                           printf("\n\n\n\t\tSTAMPA ABR creato dalla MERGE tra T1 e T2\n");
                           preOrder(T1);


                      Pulisci();


                 break;

                  case 6:


                             if(T1!=NULL)
                                 T1=freeTree(T1);

                            printf("\nScrivi la dimensione dell'albero : ");
                            while (scanf("%d",&n)!=1||n<=1||n>100)
                            {
                                      printf("Devi inserire un numero intero positivo > 1 e non > di 100 : ");
                                      while (getchar() != '\n');
                            }



                             T1=RandomTree(n);

                    do
                    {
                             printf("\n\t\tSTAMPA ABR\n");
                             preOrder(T1);

                               printf("\n\nScrivi in che direzione vuoi ruotare l'albero [l/r] : ");

                                do{

                                while((direzione=getchar()!='\n')&& (direzione!=EOF));
                                scanf("%c",&direzione);


                               }while(  (direzione!='r'&&direzione!='l') && printf("lettera non valida, Riscrivi : ")  );

                               printf("\nScrivi quante volte vuoi ruotare l'albero : ");


                                while (scanf("%d",&n_volte)!=1||n_volte<1)
                                {
                                      printf("Devi inserire un numero intero positivo : ");
                                      while (getchar() != '\n');
                                }

                              T1=ROTATION(T1,direzione,n_volte);

                               printf("\n\n\t\tSTAMPA ABR dopo ROTATION()\n");
                               preOrder(T1);

                               printf("\n\nVuoi eseguire altre rotazioni dell'albero ? [y/n] : ");
                                do{

                                while((continua=getchar()!='\n')&& (continua!=EOF));
                                scanf("%c",&continua);


                               }while(  (continua!='y'&&continua!='n') && printf("lettera non valida, Riscrivi : ")  );

                             if(continua!='n')
                             {
                                 system("@cls||clear");
                             }

                    }
                    while(continua!='n');

                       Pulisci();

                 break;

                 case 7:


                   if(T1!=NULL)
                        T1=freeTree(T1);

                            printf("\nScrivi la dimensione dell'albero : ");
                            while (scanf("%d",&n)!=1||n<=2||n>100)
                            {
                                      printf("Devi inserire un numero intero positivo > 2 e non > di 100 : ");
                                      while (getchar() != '\n');
                            }



                             T1=RandomTree(n);

                         printf("\n\t\tSTAMPA ABR PRIMA\n");
                             preOrder(T1);

                        T1=ROTATION(T1,'b',0);


                         printf("\n\n\t\tSTAMPA ABR DOPO\n");
                         preOrder(T1);



                        printf("\n\nALBERO BILANCIATO\n");

                      /*   if(isBalanced(T1)==1)
                            printf("\nVero");
                         else
                            printf("\nFalso");*/

                            Pulisci();



                    break;


                     case 8:

                         if(T1!=NULL)
                             T1=freeTree(T1);

                               printf("\nScrivi la dimensione dell'albero : ");
                               while (scanf("%d",&n)!=1||n<1||n>100)
                               {
                                      printf("Devi inserire un numero intero positivo non > di 100 : ");
                                      while (getchar() != '\n');
                               }



                                T1=RandomTree(n);

                                 printf("\n\n\t\t\t\tSTAMPA CLASSICA ABR\n");
                                 preOrder(T1);

                                printf("\n\n\t\t\t\tSTAMPA GRAFICA ABR\n");
                                StampaGrafica(T1);

                             Pulisci();


                 break;



                  default:

                    printf("\nErrore, numero non valido");
                         Pulisci();


             }
     }
     while(scelta!=0);



    return 0;
}
