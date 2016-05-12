#include<iostream>
#include<stdlib.h>
#include<vector>

#include "DNI.h"
#include "nodo.h"
#include "arbol.h"

using namespace std;


template <class TDATO>
void inicializacion_vector(vector<TDATO> &v, Arbol<TDATO> &arbol_, int tamanio)
{
    v.resize(tamanio);
    for(int i=0;i<tamanio;i++)
    {
        srand(clock());
        int aux = 30000000 + rand()%(80000001-30000000);
        DNI d(aux);
        v[i] = d;
        //v[i] = aux;
        arbol_.insertar(d);
    }
}

template <class TDATO>
bool comprobar_aleatorios(vector<TDATO> v_aleatorios, int valor)
{
  int contador = 0;
  bool encontrado = false;
  while(contador < v_aleatorios.size() && encontrado != true)
  {
    if(v_aleatorios[contador] == valor)
    {
      encontrado = true;
    }
    contador++;
  }
  return encontrado;
}

int main()
{
    vector<TDATO> muestra; //Vector de tamanio 2N
    vector<int> pruebas_busqueda;
    vector<int> pruebas_insercion;
    
    Arbol<TDATO> a1;
    int numero_nodos = 0;
    int numero_pruebas = 0;
    
    cout << "-----PRACTICA 6. ARBOLES BINARIOS DE BUSQUEDA.-----" << endl;
    cout << "Modo estadistico." << endl;
    cout << "Introduzca numero de nodos[N]:";
    cin >> numero_nodos;
    cout << "Introduzca numero de pruebas[P]:";
    cin >> numero_pruebas;
    inicializacion_vector(muestra,a1, numero_nodos*2);
    cout << "-----------------------------" << endl;
    cout << "Informacion disponible:" << endl;
    cout << "Vector de DNI aleatorios de dimension " << numero_nodos*2 << ": ";
    for(int i=0;i<numero_nodos;i++)
    {
        cout << muestra[i];
        if(i < (muestra.size()/2)-1)
        {
          cout << ",";
        }
    }
    cout << endl;
    a1.imprimir();
    cout << "-----------------------------" << endl;
    cout << "Genero aleatorios para las pruebas." << endl;
    cout << "Vector de pruebas de dimension " << numero_pruebas << ": ";
    pruebas_busqueda.resize(numero_pruebas);
    
    for(int i=0;i<numero_pruebas;i++)
    {
      srand(clock());
      int aux_p = 0+rand()%(((numero_nodos + 1 ) -1) -0);
      while(comprobar_aleatorios(pruebas_busqueda,aux_p))
      {
        aux_p = 0+rand()%(((numero_nodos + 1 ) -1) -0);
      }
      pruebas_busqueda[i] = aux_p;
      cout << pruebas_busqueda[i];
      if(i < pruebas_busqueda.size()-1)
      {
        cout << ","; 
      }
    }
    cout << endl;
    cout << "-----------------------------" << endl;
    cout << "Fase de Busqueda." << endl;
    
    int maximo_busqueda = 0;
    int minimo_busqueda = 100000000;
    int suma_busqueda = 0;
    int media_busqueda = 0;
    
    DNI::comparaciones = 0;
    for(int i=0;i<numero_pruebas;i++)
    {
      a1.buscar(muestra[pruebas_busqueda[i]]);
      
      //cout << "DNI::comparaciones: " << DNI::comparaciones << endl;
      if(maximo_busqueda<DNI::comparaciones)
        maximo_busqueda = DNI::comparaciones;
      
      if(minimo_busqueda>DNI::comparaciones)
        minimo_busqueda = DNI::comparaciones;
      
      suma_busqueda += DNI::comparaciones;
      DNI::comparaciones = 0;
    }
    cout << "Maximo busqueda: " << maximo_busqueda << endl;
    cout << "Minimo busqueda: " << minimo_busqueda << endl;
    cout << "Suma busqueda: " << suma_busqueda << endl;
    cout << "Media busqueda: " << suma_busqueda / numero_pruebas << endl;

    cout << "-----------------------------" << endl;
    cout << "Fase de insercion." << endl;
    pruebas_insercion.resize(numero_pruebas);
    int maximo_insercion = 0;
    int minimo_insercion = 100000000;
    int suma_insercion = 0;
    int media_insercion = 0;
    
    
    cout << endl;
    return 0;
}