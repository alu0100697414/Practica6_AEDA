#include "dni.hpp"

using namespace std;

DNI::DNI(void):dni_(0){}


DNI::DNI(int dato){
  if(dato>30000000)
    dni_= dato;
  else
    dni_ = 30000000+dato;
}


DNI::~DNI(void){
  dni_ = 30000000;
}

DNI DNI::operator =(const DNI a){
  dni_ = a.dni_;

  return dni_;
}

bool DNI::operator <(const DNI a){
  return dni_ < a.dni_;
}

bool DNI::operator >(const DNI a){
  return dni_ > a.dni_;
}

bool DNI::operator <=(const DNI a){
  return dni_ <= a.dni_;
}

bool DNI::operator ==(const DNI a){
  return dni_ == a.dni_;
}

bool DNI::operator !=(const DNI a){
  return dni_ != a.dni_;
}

ostream& operator <<(ostream &o, DNI &dato){
  o << dato.dni_;
  return o;
}

istream& operator >>(istream &i, DNI &dato){
  i >> dato.dni_;
  i.ignore();
  return i;
}

void DNI::set_dni(int dato){
  dni_ = dato;
}


int DNI::get_dni(void){
  return dni_;
}
