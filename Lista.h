#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "Nodo.h"
using namespace std;


template <typename Tipo>
class Lista
{
public:
    Nodo<Tipo>* inicio;

    Lista()
    {
        inicio = NULL;
    }

    void imprimir()
    {
        for(Nodo<Tipo>* temp = inicio;
            temp!=NULL;
            temp = temp->sig)
        {
            cout<<temp->num<<endl;
        }
    }

    void agregarAlInicio(Tipo valor_nuevo)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>(valor_nuevo);

        if(inicio == NULL)
        {
            inicio = nuevo;
        }else
        {
            nuevo->sig = inicio;
            inicio = nuevo;
        }
    }

    void agregarAlFinal(Tipo valor_nuevo)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>(valor_nuevo);

        if(inicio == NULL)
        {
            inicio = nuevo;
        }else
        {
            Nodo<Tipo>*temp = inicio;
            while(temp->sig!=NULL)
            {
                temp=temp->sig;
            }
            temp->sig = nuevo;
        }
    }

    void borrar(Tipo valor_a_borrar)
    {
        if(inicio->num == valor_a_borrar)
        {
            Nodo<Tipo>* borrar = inicio;
            inicio = inicio->sig;
            delete borrar;
        }else
        {
            Nodo<Tipo>* temp = inicio;
            while(temp->sig->num!=valor_a_borrar)
            {
                temp=temp->sig;
                if(temp->sig==NULL)
                    return;
            }
            Nodo<Tipo>* borrar = temp->sig;
            temp->sig = temp->sig->sig;
            delete temp->sig;
        }
    }
    //

    //Devuelve true si la lista esta vacia, de lo contrario devuelve false
    bool estaVacia()
    {
        if(inicio == NULL)
        {
            return true;
        }
        return false;
    }

    //Devuelve el valor almacenado en el primer nodo de la lista
    Tipo obtenerPrimerValor()
    {
    return inicio->valor;
    }

    //Devuelve el valor almacenado en el ultimo nodo de la lista
    Tipo obtenerUltimoValor()
    {
        Nodo<Tipo>* temp = inicio;
        while(temp->sig!=NULL)
        {
            temp = temp->sig;
        }
        return temp->valor;
    }

    //Devuelve el valor mayor almacenado en la lista
    Tipo obtenerMayor()
    {
        Nodo<Tipo>* temp = inicio;
        int mayor=-9999;
        while(temp!=NULL)
        {
            if(mayor<temp->valor)
            {
                mayor = temp->valor;
            }
            temp = temp->sig;
        }
        return mayor;
    }
};
#endif // LISTA_H
