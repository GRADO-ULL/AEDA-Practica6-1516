#include<iostream>
#include<stdlib.h>

#include "DNI.h"
#include "nodo.h"
#include "arbol.h"

using namespace std;

void imprimir_estadisticas(vector<Estadistica> est)
{
  cout << "Tabla de estadisticas:" << endl;
  cout << "\t\t"<<"Mayor"<<"\t"<<"Media"<<"\t"<<"Menor"<<endl;
  cout<<est[0].nombre<<"\t\t"<<est[0].mayor<<"\t"<<est[0].media<<"\t"<<est[0].menor<<endl;
  for(int i=1;i<est.size();i++)
  {
      cout<<est[i].nombre<<"\t"<<est[i].mayor<<"\t"<<est[i].media<<"\t"<<est[i].menor<<endl;
  }
}

int main()
{
    
    Arbol<int> a1;

    int opcion_elegida = 0;
    TDATO nuevo_dato;
    TDATO eliminar_dato;
    TDATO buscar_dato;
    
    int contador = 0;
    cout << "-----PRACTICA 6. ARBOLES BINARIOS DE BUSQUEDA.-----" << endl;
    cout << "MENU:" << endl;
    
    
    return 0;
}