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

BigUnsigned& BigUnsigned::operator=(const BigUnsigned& copia) {
  for (int i{0}; i < copia.Size(); i++) {
    numero_unsigned_.emplace_back(copia.at(i));
  }
}
  
std::ostream& operator<<(std::ostream& out, const BigUnsigned& big_unsigned) {
  for (int i{big_unsigned.Size() - 1}; i >= 0; i--) {
    out << big_unsigned.at(i);
  }
  return out;
}

std::istream& operator>>(std::istream& in, BigUnsigned& big_unsigned) {
  big_unsigned.numero_unsigned_.clear();
  std::string numero_crudo;
  in >> numero_crudo;
  for (size_t i{0}; i < numero_crudo.size(); i++) {
    big_unsigned.numero_unsigned_.emplace_back(numero_crudo[i]);
  } 
  std::reverse(big_unsigned.numero_unsigned_.begin(), big_unsigned.numero_unsigned_.end());
}

bool BigUnsigned::operator==(const BigUnsigned& unsigned_a_comparar) const {
  if (Size() != unsigned_a_comparar.Size()) {
    return false;
  }
  for (int i{0}; i < Size(); i++) {
    if (at(i) != unsigned_a_comparar.at(i)) {
      return false;
    }
  }
  return true;
}

bool operator<(const BigUnsigned& unsigned_a_comparar_primario, const BigUnsigned& unsigned_a_comparar_secundario) {
  size_t tamano_unsigned_primario{unsigned_a_comparar_primario.Size()};
  size_t tamano_unsigned_secundario{unsigned_a_comparar_secundario.Size()};
  if (tamano_unsigned_primario > tamano_unsigned_secundario) {
    return false;
  } else if (tamano_unsigned_primario < tamano_unsigned_secundario) {
    return true;
  } 
  for (int i{tamano_unsigned_primario - 1}; i >= 0; i--) {
    if (unsigned_a_comparar_primario.at(i) > unsigned_a_comparar_secundario.at(i)) {
      return false;
    } else if (unsigned_a_comparar_primario.at(i) < unsigned_a_comparar_secundario.at(i)) {
      return true;
    }
  }
  return false;
}

BigUnsigned& BigUnsigned::operator++() { // Pre-incremento
  if (at(0) == '9') {
    at(0) = '0';
    for (int i{1}; i < Size(); i++) {
      if (at(i) == '9') {
        at(i) = '0';
      } else {
        ++at(i);
        return *this;
      }
    }
    numero_unsigned_.emplace_back('1');
  } else {
    ++at(0);
  }
  return *this;
}

BigUnsigned BigUnsigned::operator++(int) { // Post-incremento
  BigUnsigned copia = *this;
  if (at(0) == '9') {
    at(0) = '0';
    for (int i{1}; i < Size(); i++) {
      if (at(i) == '9') {
        at(i) = '0';
      } else {
        ++at(i);
        return copia;
      }
    }
    numero_unsigned_.emplace_back('1');
  } else {
    ++at(0);
  }
  return copia;
}

BigUnsigned& BigUnsigned::operator--() { // Pre-decremento
  if (at(0) == '0') {
    for (int i{1}; i < Size() - 1; i++) {
      if (at(i) == '0') {
        at(i) = '9';
      } else {
        --at(i);
        return *this;
      }
    }
    numero_unsigned_.pop_back();
  } else {
    --at(0);
  }
  return *this;
}

BigUnsigned BigUnsigned::operator--(int) { // Post-decremento
  BigUnsigned copia = *this;
  if (at(0) == '0') {
    for (int i{1}; i < Size() - 1; i++) {
      if (at(i) == '0') {
        at(i) = '9';
      } else {
        --at(i);
        return copia;
      }
    }
    numero_unsigned_.pop_back();
  } else {
    --at(0);
  }
  return copia;
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
