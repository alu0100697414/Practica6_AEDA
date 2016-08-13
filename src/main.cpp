#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <stdio.h>

#include "ABB.hpp"
#include "dni.hpp"

using namespace std;

int main(void){

  system("clear");

  bool menu = false;

  while(menu == false){

    int opc;

    system("clear");

    cout << endl;
    cout << "--------------------------------------" << endl;
    cout << "PRACTICA 6: ARBOL BINARIO DE BUSQUEDA." << endl;
    cout << "--------------------------------------" << endl;
    cout << endl;
    cout << "Escoja una de las siguientes opciones del menu:" << endl;
    cout << "1: Modo demostracion." << endl;
    cout << "2: Modo estadisticas." << endl;
    cout << "3: Salir del programa." << endl;
    cout << endl;
    cout << "Introduzca la opcion que desee: ";
    cin >> opc;
    cout << "" << endl;

    switch(opc){

      case 1:
      {
        system("clear");

        ArbolBB<DNI> arbol;

        bool menu1 = false;

        while(menu1 == false){

          int opc1;

          cout << endl << "1. Insertar clave." << endl;
          cout << "2. Eliminar clave." << endl;
          cout << "0. Salir." << endl;
          cout << endl << "Valor que desea ingresar: ";

          cin >> opc1;

          switch(opc1){

            case 1:
            {
              system("clear");

              DNI clave;
              int numero;

              cout << endl << "Introduzca la clave: ";
              cin >> numero;

              clave = DNI(numero);

              arbol.Insertar(clave);
              arbol.mostrar_arbol();
            }
            break;

            case 2:
            {
              system("clear");

              DNI clave;
              int numero;

              cout << endl << "Introduzca la clave: ";
              cin >> numero;

              clave = DNI(numero);

              arbol.Eliminar(clave);
              arbol.mostrar_arbol();
            }
            break;

            case 0:
            {
              menu1 = true;
            }
            break;
          }
        }

      }
      break;

      case 2:
      {
        srand (time(NULL));

        int N,P;

        cout << "Introduzca el tamaño del arbol (numero de nodos del arbol): ";
        cin >> N;

        cout << "Introduzca el numero de pruebas: ";
        cin >> P;

        DNI banco[P];

        int NPruebasBuscar[P];
        int NPruebasInsertar[N];

        for(int i=0; i<P; i++)
          banco[i] = DNI(rand()%50000000);

        ArbolBB<DNI> arbol;

        for(int i=0; i<N; i++){
          arbol.Insertar(banco[i]);
          NPruebasInsertar[i]=arbol.get_conti();
        }

        for(int i=0; i<P; i++){
          arbol.Buscar(banco[i]);
          NPruebasBuscar[i]=arbol.get_contb();
        }

        //Pruebas buscar y media
        int minBuscar = NPruebasBuscar[0];
        int maxBuscar = NPruebasBuscar[0];
        double mediaBuscar=0.0;

        for (int i=0; i<P; i++){
          if (minBuscar > NPruebasBuscar[i])
            minBuscar=NPruebasBuscar[i];

          if(maxBuscar<NPruebasBuscar[i])
            maxBuscar=NPruebasBuscar[i];

          mediaBuscar+=NPruebasBuscar[i];
        }

        mediaBuscar=mediaBuscar/P;

        //Pruebas insertar y media
        int minInsertar = NPruebasInsertar[0];
        int maxInsertar = NPruebasInsertar[0];
        double mediaInsertar=0;

        for (int i=0; i<N; i++){
          if (minInsertar > NPruebasInsertar[i])
            minInsertar=NPruebasInsertar[i];

          if(maxInsertar < NPruebasInsertar[i])
            maxInsertar=NPruebasInsertar[i];

          mediaInsertar+=NPruebasInsertar[i];
        }

        mediaInsertar=mediaInsertar/N;

        cout << endl << "Valor de N: " << N << endl;
        cout << "Valor de P: " << P << endl;

        cout << endl << "NUMERO DE COMPARACIONES." << endl << endl;
        cout << "BUSQUEDAS:" << endl;
        cout << "MAXIMO: " << maxBuscar << " MINIMO: " << minBuscar << " MEDIA: " << mediaBuscar << endl << endl;

        cout << "INSERCION:" << endl;
        cout << "MAXIMO: " << maxInsertar << " MINIMO: " << minInsertar << " MEDIA: " << mediaInsertar << endl;

        getchar(); getchar();
      }
      break;

      case 3:
      {
        system("clear");
        menu = true;
      }
      break;

    }
  }

  return 0;
}
