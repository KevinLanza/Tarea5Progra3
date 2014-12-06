#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "Nodo.h"
using namespace std;

//Trabajo realizado en grupo con Maynor Morales, Iveth Sabillon, Merary Fernandez


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
        if(inicio == NULL)//Se hace un if para evaluar la condicion de si la lista esta vacia
        {
            return true;//Si la condicion se cumple devuelve true
        }
        return false;//Si la condicion no se cumple devuelve false
    }

    //Devuelve el valor almacenado en el primer nodo de la lista
    Tipo obtenerPrimerValor()
    {
    return inicio->valor;//Devuelve el primer valor que exste en la lista
    }

    //Devuelve el valor almacenado en el ultimo nodo de la lista
    Tipo obtenerUltimoValor()
    {
        Nodo<Tipo>* temp = inicio;//Se hace un nuevo nodo para evaluarlo
        while(temp->sig!=NULL)//Con un ciclo while se va recorriendo la lista
        {
            temp = temp->sig;//El nuevo nodo se convierte el en el siguiente de ese nodo 
        }
        return temp->valor;//Devuelve el valor del nodo del final de la lista 
    }

    //Devuelve el valor mayor almacenado en la lista
    Tipo obtenerMayor()
    {
        Nodo<Tipo>* temp = inicio;//Se hace un nuevo nodo para evaluarlo
        int mayor=-9999;//Se hace una variable int para evaluarlo en la condicion de si es mayor
        while(temp!=NULL)//Un ciclo while que lo anidamos a otras condiciones para buscar lo que queremos 
        {
            if(mayor<temp->valor)//Hacemos un if para evaluar el valor del nodo hecho con la variable hecha
            {
                mayor = temp->valor;//Si la condicion se cumple la variable toma el valor del nodo 
            }
            temp = temp->sig;//El nodo hecho toma el valor del siguiente valor del nodo 
        return mayor;//Devuelve el numero mayor del ciclo 
    }
};
#endif // LISTA_H
