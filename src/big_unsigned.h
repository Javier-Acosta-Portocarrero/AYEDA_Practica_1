#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

class BigUnsigned {
 public:
  BigUnsigned(unsigned n = 0);
  BigUnsigned(const unsigned char* );
  BigUnsigned(const BigUnsigned& copia); // Constructor de copia

  int Size() const { return numero_unsigned_.size();}
  unsigned char at(int posicion) const { return numero_unsigned_[posicion];}
  unsigned char& at(int posicion) { return numero_unsigned_[posicion];}

  BigUnsigned& operator=(const BigUnsigned&);
  
  friend std::ostream& operator<<(std::ostream&, const BigUnsigned&);
  friend std::istream& operator>>(std::istream&, BigUnsigned&);

  bool operator==(const BigUnsigned&) const;
  friend bool operator<(const BigUnsigned&, const BigUnsigned&);

  BigUnsigned& operator++(); // Pre-incremento
  BigUnsigned operator++(int); // Post-incremento
  BigUnsigned& operator--(); // Pre-decremento
  BigUnsigned operator--(int); // Post-decremento
  
  friend BigUnsigned operator+(const BigUnsigned&, const BigUnsigned&);
  BigUnsigned operator-(const BigUnsigned&) const;
  BigUnsigned operator*(const BigUnsigned&) const;
  friend BigUnsigned operator/(const BigUnsigned&, const BigUnsigned&);
  BigUnsigned operator%(const BigUnsigned&) const;

 private:
  std::vector<unsigned char> numero_unsigned_;
};