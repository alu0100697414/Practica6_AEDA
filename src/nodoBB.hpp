// Clase nodo

#include <iostream>

template<class T>
class nodoBB {

  public:

    T clave;
    int nivel;
    bool pivote;

    nodoBB* izdo;
    nodoBB* dcho;

    nodoBB(T cl, int ni, bool piv, nodoBB* iz=NULL, nodoBB* de=NULL): clave(cl),nivel(ni),pivote(piv),izdo(iz),dcho(de){}

    T get_clave(void){ return clave; }
    int get_nivel(void){ return nivel; }
    bool get_pivote(void){ return pivote; }

    void set_clave(T clav){ clave=clav; }
    void set_nivel(int niv){ nivel=niv; }
    void set_pivote(bool a){ pivote = a; }
};
