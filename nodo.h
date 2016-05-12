#ifndef _NODO_H
#define _NODO_H
#include <iostream>     // std::cin, std::cout
#include <string>       // std::string
#include <cctype>       // std::isdigit
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class DNI;

typedef DNI TDATO;

template<class TDATO>
class nodo
{
private:
  
public:
  nodo();
  ~nodo();
  nodo(TDATO d);
  nodo(TDATO d, nodo<TDATO>* izquierda, nodo<TDATO>* derecha);
  TDATO get_dato(void);
  void set_dato(TDATO d);
  
  void set_izquierda(nodo<TDATO>* izquierda);
  void set_derecha(nodo<TDATO>* derecha);
  
  nodo<TDATO>* get_izquierda(void);
  nodo<TDATO>* get_derecha(void);
  
  nodo<TDATO>* izq;
  nodo<TDATO>* der;
  TDATO dato;
};

template <class TDATO>
nodo<TDATO>::nodo()
{
  izq = NULL;
  der = NULL;
}

template <class TDATO>
nodo<TDATO>::nodo(TDATO d)
{
    dato = d;    
    izq = NULL;
    der = NULL;
}

template <class TDATO>
nodo<TDATO>::nodo(TDATO d, nodo<TDATO>* izquierda, nodo<TDATO>* derecha)
{
    dato = d;
    izq = izquierda;
    der = derecha;
}

template <class TDATO>
nodo<TDATO>::~nodo()
{
    if(izq != NULL)
    {
        delete izq;
        izq = NULL;
    }
    if(der != NULL)
    {
        delete der;
        der = NULL;
    }
}

template <class TDATO>
TDATO nodo<TDATO>::get_dato(void)
{
    return dato;    
}

template <class TDATO>
void nodo<TDATO>::set_dato(TDATO d)
{
    dato = d;
}

template <class TDATO>
void nodo<TDATO>::set_izquierda(nodo<TDATO>* izquierda)
{
    izq = izquierda;
}

template <class TDATO>
void nodo<TDATO>::set_derecha(nodo<TDATO>* derecha)
{
    der = derecha;
}

template <class TDATO>
nodo<TDATO>* nodo<TDATO>::get_izquierda(void)
{
    return izq;
}

template <class TDATO>
nodo<TDATO>* nodo<TDATO>::get_derecha(void)
{
    return der;   
}

#endif