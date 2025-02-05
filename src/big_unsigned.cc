#include "big_unsigned.h"


BigUnsigned::BigUnsigned(unsigned n) {
  if (n == 0) {
    numero_unsigned_.emplace_back('0');
    return;
  }
  while (n > 0) {
    numero_unsigned_.emplace_back('0' + (n % 10));
    n /= 10;
  } 
}  

BigUnsigned::BigUnsigned(const unsigned char* entrada) {
  if (entrada) {
    size_t len = std::strlen(reinterpret_cast<const char*>(entrada)); // Calcula el tamaño de la cadena
    numero_unsigned_.assign(entrada, entrada + len); // Copia los bytes al vector
    std::reverse(numero_unsigned_.begin(), numero_unsigned_.end()); // Invertir para little-endian
  }
}  

BigUnsigned::BigUnsigned(const BigUnsigned& copia) { // Constructor de copia
  for (int i{0}; i < copia.Size(); i++) {
    numero_unsigned_.emplace_back(copia.at(i));
  }
}

BigUnsigned& BigUnsigned::operator=(const BigUnsigned&) {

}
  
std::ostream& operator<<(std::ostream& out, const BigUnsigned& big_unsigned) {
  
}

std::istream& operator>>(std::istream& in, BigUnsigned& big_unsigned) {
  big_unsigned.numero_unsigned_.clear();
  std::string numero_crudo;
  in >> numero_crudo;
  for (size_t i{0}; i < numero_crudo.size(); i++) {
    big_unsigned.numero_unsigned_.emplace_back(numero_crudo[i]);
  } 
}

bool BigUnsigned::operator==(const BigUnsigned&) const {

}

bool operator<(const BigUnsigned&, const BigUnsigned&) {

}

BigUnsigned& BigUnsigned::operator++() { // Pre-incremento

}

BigUnsigned BigUnsigned::operator++(int) { // Post-incremento

}

BigUnsigned& BigUnsigned::operator--() { // Pre-decremento

}

BigUnsigned BigUnsigned::operator--(int) { // Post-decremento

}
  
BigUnsigned operator+(const BigUnsigned&, const BigUnsigned&) {

}

BigUnsigned BigUnsigned::operator-(const BigUnsigned&) const {

}

BigUnsigned BigUnsigned::operator*(const BigUnsigned&) const {

}

BigUnsigned operator/(const BigUnsigned&, const BigUnsigned&) {

}

BigUnsigned BigUnsigned::operator%(const BigUnsigned&) const {

}
