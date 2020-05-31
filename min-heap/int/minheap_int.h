/** @file
Definizione del tipo ElemType e dichiarazione delle funzioni ad esso associate: 
    - ElemCompare()
    - ElemCopy()
    - ElemDelete()
    - ElemSwap()
    - ReadElem()
    - ReadStdinElem()
    - WriteElem()
    - WriteStdoutElem()

Le suddette funzioni dipendono da come ElemType viene definito: al variare
della definizione di ElemType la dichiarazione delle funzioni non cambia, ma 
la loro definizione deve essere modificata opportunamente.

Definizione del tipo Node e delle funzioni primitive (e non) degli alberi:
    - CreateEmptyTree()
    - CreateRootTree()
    - IsEmptyTree()
    - GetRootValueTree()
    - LeftTree()
    - RightTree()
    - IsLeafTree()
    - DeleteTree()

    - WritePreOrderTree()
    - WriteStdoutPreOrderTree()
    - WriteInOrderTree()
    - WriteStdoutInOrderTree()
    - WritePostOrderTree()
    - WriteStdoutPostOrderTree()

La dichiarazioni e la definizione delle suddette funzioni NON deve essere
modificate al variare della definizione di ElemType.
*/

#ifndef MINHEAP_INT_H_
#define MINHEAP_INT_H_

#include <stdbool.h>
#include <stdio.h>

/*****************************************************************************/
/*                                 Element                                   */
/*****************************************************************************/

/** @brief Definizione del tipo ElemType. */
typedef int ElemType;

/** @brief La funzione ElemCompare confronta due elementi.

@param[in] e1 Puntatore al primo elemento di cui eseguire il confronto. Il 
              valore contenuto in e1 non viene modificato.
@param[in] e2 Puntatore al secondo elemento di cui eseguire il confronto. Il
              valore contenuto in e2 non viene modificato.

@return La funzione ritorna un valore intero che indica la relazione tra i due
        elementi, ovvero:
         - -1 se il contenuto del primo e' minore di quello del secondo;
         -  0 se i contenuti dei due elementi sono uguali
         -  1 se il contenuto del primo e' maggiore di quello del secondo;
*/
int ElemCompare(const ElemType *e1, const ElemType *e2);

/** @brief La funzione ElemCopy crea e ritorna una copia dell'elemento dato.

@param[in] e Puntatore all'elemento da copiare. Il valore contenuto in e non 
             viene modificato.

@return Copia dell'elemento e.
*/
ElemType ElemCopy(const ElemType *e);

/** @brief La funzione ElemDelete libera la memoria occupata dall'elemento
           specificato.

@param[in] e Puntatore all'elemento di cui liberare la memoria.

@return Non ci sono valori di ritorno.
*/
void ElemDelete(ElemType *e);

/** @brief La funzione ElemSwap scambia i due elementi specificati.

@param[in] e1 Puntatore al primo elemento da scambiare.
@param[in] e2 Puntatore al secondo elemento da scambiare.

@return Non ci sono valori di ritorno.
*/
void ElemSwap(ElemType *e1, ElemType *e2);

/** @brief La funzione ReadElem legge un elemento da file.

@param[in] f FILE * da cui leggere un elemento.
@param[out] e Elemento letto da file.

@return Numero di elementi effettivamente letti (0 o 1).
*/
int ReadElem(FILE *f, ElemType *e);

/** @brief La funzione ReadStdinElem legge un elemento da standard input.

@param[out] e Elemento letto da standard input.

@return Numero di elementi effettivamente letti (0 o 1).
*/
int ReadStdinElem(ElemType *e);

/** @brief La funzione WriteElem stampa un elemento su file.

@param[in] e Puntatore all'elemento da stampare su file. Il valore contenuto in
             e non viene modificato.
@param[in] f FILE * su cui stampare l'elemento.

@return Non ci sono valori di ritorno.
*/
void WriteElem(const ElemType *e, FILE *f);

/** @brief La funzione PrintStdoutElem stampa un elemento su standard output.

@param[in] e Puntatore all'elemento da stampare su standard output. Il valore
             contenuto in e non viene modificato.

@return Non ci sono valori di ritorno.
*/
void WriteStdoutElem(const ElemType *e);

/*****************************************************************************/
/*                          Node & Primitives                                */
/*****************************************************************************/

struct Heap{
    ElemType *data;
    size_t size;
};
typedef struct Heap Heap;

/** @brief La funzione LeftHeap prende in input l'indice di un nodo dello heap
           e ritorna l'indice del suo figlio sinistro. 

@param[in] i Indice di un nodo nello heap. 

@return Indice del figlio sinistro del nodo i. Non � detto che il nodo avente
        l'indice ritornato sia effettivamente presente nello heap.
*/
int LeftHeap(int i);

/** @brief La funzione RightHeap prende in input l'indice di un nodo dello heap
           e ritorna l'indice del suo figlio destro.

@param[in] i Indice di un nodo nello heap.

@return Indice del figlio destro del nodo i. Non � detto che il nodo avente
        l'indice ritornato sia effettivamente presente nello heap.
*/
int RightHeap(int i);

/** @brief La funzione ParentHeap prende in input l'indice di un nodo dello heap
           e ritorna l'indice del nodo padre.

@param[in] i Indice di un nodo nello heap.

@return Indice del padre del nodo i. Non � detto che il nodo avente l'indice 
        ritornato sia effettivamente presente nello heap.
*/
int ParentHeap(int i);

/** @brief La funzione CreateEmptyHeap crea e ritorna un heap vuoto
           implementato mediante array. 

@return Puntatore allo heap appena creato.
*/
Heap* CreateEmptyHeap();

/** @brief La funzione IsEmptyHeap verifica se un heap e' vuoto o meno. Lo
           heap deve esistere.

@param[in] h Puntatore allo heap da testare.

@return true se lo heap e' vuoto, ovvero contiene zero elementi, false 
        altrimenti.
*/
bool IsEmptyHeap(const Heap *h);

ElemType* GetNodeValueHeap(const Heap *h, int i);

/** @brief Dato un heap e l'indice di un nodo, la funzione MoveUpMinHeap sposta
           il nodo in alto all'interno dell'albero heap, ovvero lo scambia con 
           il nodo padre ricorsivamente fino a quando le condizione (min-)heap
           non sono rispettate.

@param[i] h (min-)heap. Tutti i nodi di h, ad eccezione di quello di indice i,
            devono rispettare le condizioni (min-)heap.
@param[i] i Indice del nodo su cui applicare la procedura.

@return Non ci sono valori di ritorno.
*/
void MoveUpMinHeap(Heap *h, int i);

/** @brief Dato un heap e l'indice di un nodo, la funzione MoveDownMinHeap 
           sposta il nodo in basso all'interno dell'albero heap, ovvero lo 
           scambia con il minore dei figli ricorsivamente fino a quando le 
           condizione (min-)heap non sono rispettate.

@param[i] h (min-)heap. Tutti i nodi di h, ad eccezione di quello di indice i,
            devono rispettare le condizioni (min-)heap.
@param[i] i Indice del nodo su cui applicare la procedura.

@return Non ci sono valori di ritorno.
*/
void MoveDownMinHeap(Heap *h, int i);

/** @brief La funzione DeleteHeap libera la memoria occupata dai nodi di uno
           heap.

@param[in] h Puntatore al primo elemento dell'array che memorizza lo heap.

@return Non ci sono valori di ritorno.
*/
void DeleteHeap(Heap *h);

/*****************************************************************************/
/*                             Non Primitives                                */
/*****************************************************************************/

/** @brief La funzione WriteHeap stampa lo heap specificato su file.

@param[in] h Heap da stampare su file. Lo heap non viene modificato.
@param[in] f FILE * su cui stampare lo heap.

@return Non ci sono valori di ritorno.
*/
void WriteHeap(const Heap *h, FILE *f);

/** @brief La funzione WriteStdoutHeap stampa lo heap specificato su standard
           output.

@param[in] h Heap da stampare su standard output. Lo heap non viene modificato.

@return Non ci sono valori di ritorno.
*/
void WriteStdoutHeap(const Heap *i);

#endif // MINHEAP_INT_H_
