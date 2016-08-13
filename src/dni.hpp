// Clase dni.

#include <iostream>

using namespace std;

class DNI {

private:

  int dni_;

public:

  DNI(void);
  DNI(int dato);
  ~DNI(void);

  DNI operator =(const DNI a);

  bool operator !=(const DNI a);
  bool operator ==(const DNI a);

  bool operator <(const DNI a);
  bool operator >(const DNI a);
  bool operator <=(const DNI a);

  friend ostream& operator <<(ostream &o, DNI &dato);
  friend istream& operator >>(istream &i, DNI &dato);

  void set_dni(int dato);
  int get_dni(void);
};
