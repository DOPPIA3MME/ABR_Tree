#ifndef Progetto2_h
#define Progetto2_h




struct LList
{
    int key;
    struct LList* next;
};

typedef struct LList* List;
//struttura per la lista


struct TTreeT
{
    int key;
    List top;                             //Ogni nodo di T avrà una lista ad esso associato, essa ovviamente conterrà gli eventuali doppioni
    struct TTreeT* sx;
    struct TTreeT* dx;
};

typedef struct TTreeT* TreeT;
//struttura per gli alberi di tipo T


struct TTree
{
    int key;
    struct TTree* sx;
    struct TTree* dx;
};

typedef struct TTree* Tree;
//struttura per gli ABR





/*
      FUNZIONI RIGUARDANTI T , ABR che ACCETTA doppioni
*/


//Crea il nodo dell'albero T
TreeT initNodeT(int k);

//Stampa della lista
void StampaLista(List top);

//Stampa preorder dell'albero T, se un nodo ha un doppione stamperà la lista ad esso associato in questo modo x->[x]
void preOrderT(TreeT T);

//Crea un elemento della lista e lo inserisce in testa
List Inserimento_in_Testa(List top,int key);

//Crea T, un abr che contiene doppioni, essi saranno inseriti in una lista associata al nodo in questione
TreeT insertNodeT(TreeT T, int key);

//Crea T di n nodi
TreeT RandomTreeT(int n);

//Calcola l'altezza dell'albero di tipo T
int heightT(TreeT T);

//Crea n_volte alberi binari di ricerca di tipo T e calcola l'altezza di ognuno, per poi sommarle in somma_h
//infine restituisce la media di tutte le altezze
float height_mediaT(int n_nodi,int n_volte);

//Dealloca la memoria associata alla lista
List freeList(List top);

//Dealloca la memoria associata a T
TreeT freeTreeT(TreeT T);

//Cancella il top della lista e restituisce il prossimo elemento
List CancellaNodoLista(List top);

//Trova il nodo minimo del sottoalbero destro di T
TreeT FindNodeDxMin(TreeT T);

//Cancella un nodo da T, se il nodo avrà un doppione cancella il nodo dalla lista ad esso associato
TreeT DeleteNodefromT(TreeT T, int key);






/*
      FUNZIONI RIGUARDANTI ABR generico che NON accetta doppioni
*/

//Crea un nodo dell'albero
Tree initNode(int k);

//Inserisce il nodo creato da initNode nella posizione giusta dell'albero, quando nella RandomTree sorteggia una key gia' presente nell'albero
//incrementa la variabile globale num_nodi per fare una iterazione in più
Tree insertNode_SenzaDoppioni(Tree T,int key);

//Stampa ABR
void preOrder(Tree T);

//Stampa grafica di T, L: rappresenta il figlio sinistro mentre R: il figlio destro
void StampaGrafica(Tree T);

//Crea un ABR di n_nodi, le chiavi random dei nodi sono da 0 a 99, quindi un albero di 101 nodi non potrà esistere
Tree RandomTree(int num_nodi);

//Pulisce il terminale
void Pulisci();

//Dealloca la memoria dell'albero T
Tree freeTree(Tree T);

//Restituisce il massimo tra a e b
int max(int a, int b);

//Calcola l'altezza d'ellalbero T
int height(Tree T);

//Rotazione a destra del nodo a
Tree rightRotate(Tree a);

//Rotazione a sinistra del nodo a
Tree leftRotate(Tree a);

//Dato un nodo T sottrae l'altezza del sottoalbero sinistro con l'altezza del sottoalbero destro.
//Tale risultato rappresenta l'indice di bilanciamento del nodo
int Calcola_IndiceBilanciamento(Tree T);

//Crea un nodo lo inserisce nell'albero e attraverso opportune rotazioni forma un albero AVL
Tree insert_in_AVL(Tree AVL, int key);

//Crea un albero AVL considerando i nodi dell' ABR T
Tree CreaAVL(Tree AVL,Tree T);

//Ruota l'albero T nella direzione scelta, n volte
Tree ROTATION(Tree T,char direzione,int n);

//Crea un array di n elementi
int* Crea_Array(int n);

//Stampa di un array
void Stampa_Array(int *A, int n);

//Crea un ABR dall'array ordinato A_ordinato
Tree ABRfromSortedArray(Tree T,int* A_ordinato,int start,int end);

//Unisce A1 e A2 in un unico array ordinato
int* MergeSortedArrays(int* A1, int* A2, int n1, int n2);

//Inserisce i nodi di T nell'array in modo ordinato
void CreaSortedArray(Tree T, int* A,int *i);

//Unisce due alberi T1 e T2 creando due array ordinati con gli elementi del primo e del secondo, poi li unisce in un unico array, mergedA, ordinato
//infine la funzione ABRfromSortedArray usa mergedA per creare l'ABR richiesto
Tree MERGE(Tree T1, Tree T2, int n1, int n2);

//Semplice menu' per l'utente
int Menu();


#endif
