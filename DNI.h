#include <iostream>

using namespace std;

class DNI
{

  private:
     int valor;
     static int comparaciones;
     
  public:
    DNI();
    DNI(int v);
    ~DNI();
    int get_value(void);

    //Sobrecarga de operadores
    bool operator==(DNI &dni_);
    bool operator<(DNI &dni_);
    bool operator>(DNI &dni_);
    bool operator<=(DNI &dni_);
    bool operator>=(DNI &dni_);

    //Impresión
    friend ostream& operator<<(ostream &salida, const DNI dni_);
};