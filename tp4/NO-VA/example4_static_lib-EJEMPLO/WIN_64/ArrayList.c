#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void** pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));//pido espacio para el array una sola vez

    if(this != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );//pido espacio para los datos, pElements
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this, void* pElement)
{
  int returnAux = -1;
  int flag=1;

    if(this!=NULL && pElement!=NULL)
    {
        if(this->size==this->reservedSize)
        {
           if(resizeUp(this))//creo el nuevo espacio de memoria
            {
               *(this->pElements+this->size)=pElement;//si funciona lo ubico en el 2do puntero
               this->size++;//aumento el size
               returnAux=0;
            }
          else
            {
            flag=0;
            }
        }

        if(flag==1)
        {
       *(this->pElements+this->size)=pElement;// si no necesita mas espacio lo asigno directo
        this->size++;
        returnAux=0;
        }
        else
        {
        *(this->pElements+this->size)=pElement;
        returnAux=0;
        }

    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this)
{
    int returnAux = -1;

    if (this!=NULL)
    {
        free(this);
        returnAux=0;
    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this)
{
    int returnAux = -1;
    if (this!=NULL)
    {
        returnAux=this->size;
    }

    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index)
{
    void* returnAux = NULL;
    if (this!=NULL)
        {
            if(index<this->size)
            {
            returnAux=*(this->pElements+index);
            }

        }
    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    int flag=0;
    if (this!=NULL && pElement!=NULL)
        {
           for (i=0; i<this->reservedSize; i++)
           {
               if(pElement==*(this->pElements+i))
               {
                   returnAux =1;
                   flag=1;
                   break;
               }
           }
           if (flag==0)
           {
               returnAux=0;
           }

        }
    return returnAux;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement)
{
    int returnAux = -1;
    int i;

    if (this!=NULL && pElement!=NULL)
        {
           if(index<this->size)
            {
            *(this->pElements+index)=pElement;
            returnAux=0;
            }

        }

    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index)
{
    int returnAux = -1;
    int aux;
    int i;
        if (this!=NULL)
        {
        returnAux=contract(this, index);
        resizeDown(this);
        this->size--;
         }

    return returnAux;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this)
{
    int returnAux = -1;
      if (this!=NULL)
        {
        this->size=0;
        resizeDown(this);
        returnAux=0;
        }


    return returnAux;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL;
    returnAux=al_newArrayList();
    int i;

      if (this!=NULL && returnAux!=NULL)
        {
           for(i=0; i<(this->reservedSize);i++)
           {
            if (*(this->pElements+i)!=NULL)
            {
                al_add(returnAux,*(this->pElements+i));
            }


           }
        }

    return returnAux;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement)
{
  int returnAux = -1;
  int flag=0;
  int i;

    if(this!=NULL && pElement!=NULL && index<(this->size)&&index>0)
    {

        if(this->size==this->reservedSize)
        {
           if(resizeUp(this))//creo el nuevo espacio de memoria
            {
              expand(this, index);
            }

        }
           this->pElements[index]=pElement;
           this->size++;
           returnAux=0;//////////////
    }


    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement)
{
    int returnAux = -1;

    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this)
{
    int returnAux = -1;

    return returnAux;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;

    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this,int from,int to)
{
    void* returnAux = NULL;

    return returnAux ;
}





/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;

    return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{
    int returnAux = -1;
    int auxsize;
    void** aux;

    if (this!=NULL)
    {
     auxsize=this->reservedSize+AL_INCREMENT;
     aux=(void**)realloc(this->pElements, sizeof(void*)*auxsize);
         if (aux!=NULL)
         {
            this->pElements=aux;
            this->reservedSize=auxsize;
            returnAux=0;
         }
    }
    return returnAux;
}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int returnAux = -1;
    int aux;
    int i;
    int flag=0;

    if (this!=NULL)
    {

           if(index<this->size )
            {
                aux=this->reservedSize+(this->reservedSize-this->size);

                for(i=index; i<aux; i++)
                {
                    this->pElements[i+1]=this->pElements[i];
                    flag=1;
                }
            if (flag ==1)
            {
                this->reservedSize=aux;

            }
            }

    }

    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int returnAux = -1;
    int aux;
    int i;
    int flag;

    if (this!=NULL)
    {

           if(index < this->size)
            {
                aux=this->reservedSize-(this->reservedSize-this->size);
                for(i=index; i<aux; i++)
                {
                    this->pElements[i]=this->pElements[i+1];
                    returnAux=0;
                    flag=1;
                }
            }
            if (flag ==1)
            {
                this->reservedSize=aux;

            }
    }



    return returnAux;
}

/** \brief contract the number of elements in pList in the difference between the size and the reserve sized
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeDown(ArrayList* this)
{
    int returnAux = -1;
    int auxsize;
    void** aux;

    if (this!=NULL)
    {

     if((this->reservedSize-this->size)>10 && (this->size!=0));
     {
          auxsize=this->reservedSize-(this->reservedSize- AL_INCREMENT-this->size);
          aux=(void**)realloc(this->pElements, sizeof(void*)*auxsize);
             if (aux!=NULL)
             {
                this->pElements=aux;
                this->reservedSize=auxsize;
                returnAux=0;
             }
     }

   if((this->size==0));
     {
         aux=(void**)realloc(this->pElements, sizeof(void*)*AL_INCREMENT);
             if (aux!=NULL)
             {
                this->pElements=aux;
                this->reservedSize=AL_INCREMENT;
                returnAux=0;
             }
     }




    }
    return returnAux;
}


