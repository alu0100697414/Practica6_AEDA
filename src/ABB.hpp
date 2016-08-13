// Clase Arbol Binario de Busqueda
#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>

#include "nodoBB.hpp"

using namespace std;

template<class T>
class ArbolBB {

  private:

    nodoBB<T>* raiz;

    int conti;
    int contb;

  public:

    ArbolBB(void):raiz(NULL){}

    void sustituye(nodoBB<T>* a, nodoBB<T>* b);

    void Buscar(T clave_dada);
    void BuscarRama(nodoBB<T>* nodo, T clave_dada);

    void Insertar(T clave_dada);
    void InsertarRama(nodoBB<T>* &nodo, T clave_dada, int& nivel);

    void Eliminar(T clave_dada);
    void EliminarRama(nodoBB<T>* &nodo, T clave_dada);

    void mostrar_arbol(void);

    int get_conti(void);
    int get_contb(void);

};


template<class T> void ArbolBB<T>::sustituye(nodoBB<T>* a, nodoBB<T>* b){

  nodoBB<T>* tmp = a;
  a = b;
  b = tmp;
}


template<class T> void ArbolBB<T>::Buscar(T clave_dada){

  contb=0;

  return BuscarRama(raiz, clave_dada);
}


template<class T> void ArbolBB<T>::BuscarRama(nodoBB<T>* nodo, T clave_dada){

  if(nodo == NULL){
    contb++;
    return;
  }

  if(clave_dada == nodo->clave){
    contb++;
    return;
  }

  if(clave_dada < nodo->clave){
    contb++;
    return BuscarRama(nodo->izdo, clave_dada);
  }

  contb++;
  return BuscarRama(nodo->dcho, clave_dada);
}


template<class T> void ArbolBB<T>::Insertar(T clave_dada){

  int nivel=0;

  conti=0;

  InsertarRama(raiz, clave_dada, nivel);
}



template<class T> void ArbolBB<T>::InsertarRama(nodoBB<T>* &nodo, T clave_dada, int& nivel){

  if(nodo == NULL){
    conti++;
    nodo = new nodoBB<T>(clave_dada,nivel,false);
  }

  if(clave_dada < nodo->clave){
    nivel++;
    conti++;
    InsertarRama(nodo->izdo, clave_dada, nivel);
  }

  if(clave_dada > nodo->clave){
    nivel++;
    conti++;
    InsertarRama(nodo->dcho, clave_dada, nivel);
  }

  //cout << "La clave ya se encuentra dentro del arbol." << endl << endl;
}


template<class T> void ArbolBB<T>::Eliminar(T clave_dada){

  EliminarRama(raiz, clave_dada);
}


template<class T> void ArbolBB<T>::EliminarRama(nodoBB<T>* &nodo, T clave_dada){

  if(nodo == NULL)
    return;

  if(clave_dada < nodo->clave)
    EliminarRama(nodo->izdo, clave_dada);

  else if(clave_dada > nodo->clave)
    EliminarRama(nodo->dcho, clave_dada);

  else{

    nodoBB<T>* Eliminado = nodo;

    if(nodo->dcho == NULL){
      nodo = nodo->izdo;
      nodo->set_nivel(nodo->get_nivel()-1);
    }

    else if(nodo->izdo == NULL){
      nodo = nodo->dcho;
      nodo->set_nivel(nodo->get_nivel()-1);
    }

    else if(nodo->dcho != NULL && nodo->izdo != NULL){
      nodoBB<T>* aux = nodo->dcho;

      nodo = nodo->izdo;
      nodo->set_nivel(nodo->get_nivel()-1);
      nodo->dcho = aux;
    }

    else
      sustituye(Eliminado, nodo->izdo);

    delete(Eliminado);
  }
}


template<class T> void ArbolBB<T>::mostrar_arbol(void){

  std::queue<nodoBB<T>*> cola, colaaux, col;

  nodoBB<T>* aux;
  nodoBB<T>* vacio;

  if(raiz != NULL){
    cola.push(raiz);
    colaaux.push(raiz);

    while(!cola.empty()){
      aux=cola.front();
      cola.pop();

      if(aux->izdo != NULL){
        cola.push(aux->izdo);
        colaaux.push(aux->izdo);
      }
      else{
        vacio = new nodoBB<T>(-1, aux->get_nivel()+1, true);
        colaaux.push(vacio);
      }

      if(aux->dcho != NULL){
        cola.push(aux->dcho);
        colaaux.push(aux->dcho);
      }
      else {
        vacio = new nodoBB<T>(-1, aux->get_nivel()+1, true);
        colaaux.push(vacio);
      }
    }

    int i=0;
    cout << "Nivel " << i << ": ";
    while(!colaaux.empty()){
      if(colaaux.front()->get_nivel()==i){
        if((colaaux.front()->get_clave() == -1) && (colaaux.front()->get_pivote()==true))
          cout << "[.] ";
        else {
          T value = colaaux.front()->get_clave();
          cout << "["<< value << "] ";
        }

        colaaux.pop();
      }

      else {
        i++;
        cout << endl << endl << "Nivel " << i << ": ";
      }
    }
    cout << endl;

  }
  else {
    cout << "El arbol esta vacio." << endl;
  }
}


template<class T> int ArbolBB<T>::get_conti(void){

  return conti;
}



template<class T> int ArbolBB<T>::get_contb(void){

  return contb;
}
