#include "Polynomial.h"
#include <cmath>

std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
  // Used to mark when there will be no more terms to add_or_sub
  std::list<Polynomial::Term>::const_iterator no_more_add_or_sub = p.polynomial.end();
  --no_more_add_or_sub;
  for (std::list<Polynomial::Term>::const_iterator it = p.polynomial.begin(); it != p.polynomial.end(); ++it) {
    // Handles a special case so that the negative sign is printed if the
    // first term is negative
    if (it == p.polynomial.begin() && it->coeff < 0) {
      std::cout << "-";
    }
    os << *it;
    // If not last term include a plus sign
    if (it != no_more_add_or_sub) {
      ++it;
      if (it->coeff >= 0.0) {
	std::cout << " + ";
      }
      else {
	std::cout << " - ";
      }
      --it;
    }
  }
  return os;
}

Polynomial operator*(double factor, const Polynomial& p) {
  Polynomial p2(p);
  for (std::list<Polynomial::Term>::iterator it = p2.polynomial.begin(); it != p2.polynomial.end(); ++it) {
    // Multiply each coefficient by the factor
    it->coeff *= factor;
  }
  return p2;
}

// For use in sorting
bool compare_terms(const Polynomial::Term& t1, const Polynomial::Term& t2) {
  return t1 < t2;
}

Polynomial operator+(const Polynomial& p1, const Polynomial& p2) {
  Polynomial p(p1);
  for (std::list<Polynomial::Term>::const_iterator it = p2.polynomial.begin(); it != p2.polynomial.end(); ++it) {
    // Add the term
    p.polynomial.push_front(*it);
  }
  // Keep them in sorted (descending power) order
  p.polynomial.sort(compare_terms);
  // Combine terms with the same exponent
  p.reduce();
  return p;
}

Polynomial operator-(const Polynomial& p) {
  return (-1 * p);
}

Polynomial operator-(const Polynomial& p, const Polynomial& q) {
  return (p + -q);
}

Polynomial operator*(const Polynomial& p, const Polynomial& q) {
  Polynomial product;
  for (std::list<Polynomial::Term>::const_iterator it = p.polynomial.begin();
       it != p.polynomial.end(); ++it) {
    for (std::list<Polynomial::Term>::const_iterator it2 = q.polynomial.begin();
	 it2 != q.polynomial.end(); ++it2) {
      product += ((*it) * (*it2));
    }
  }
  product.polynomial.sort(compare_terms);
  product.reduce();
  return product;
}

Polynomial::Polynomial(double c, int e) {
  // Be careful checking equality with a double
  if (c == 0.0) {
    // Empty list
    polynomial = std::list<Term>(0);
    degree = -1;
  }
  else {
    // List with 1 term given the c and e
    polynomial = std::list<Term>(1, Term(c, e));
    degree = e;
  }
}

Polynomial::Polynomial(const Polynomial& p) : polynomial(p.polynomial), degree(p.degree) {
  
}

Polynomial& Polynomial::operator=(const Polynomial& p) {
  polynomial = p.polynomial;
  degree = p.degree;
}

bool Polynomial::operator==(const Polynomial& p) {
  return polynomial == p.polynomial;
}

double Polynomial::operator()(double x) const {
  if (polynomial.size() == 0) {
    return 0.0;
  }
  double result = 0.0;
  std::list<Polynomial::Term>::const_iterator it2 = polynomial.end();
  // Tracks last element
  --it2;
  for (std::list<Polynomial::Term>::const_iterator it = polynomial.begin(); it != polynomial.end(); ++it) {
    if (it != it2) {
      // Temporary iterator to next element
      std::list<Polynomial::Term>::const_iterator it3 = ++it;
      --it;
      // Horner's method of evaluating a polynomial
      (result += it->coeff) *= pow(x, it->exp - it3->exp);
    }
    else {
      // The last term just evaluates normally without subtraction of exponents
      (result += it->coeff) *= pow(x, it->exp);
      return result;
    }
  }
}

int Polynomial::get_degree() const {
  return degree;
}

int Polynomial::get_terms() const {
  return polynomial.size();
}

void Polynomial::print() const {
  std::cout << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Polynomial::Term& t) {
  if (t.exp == 0) {
    // fabs because the sign will be printed separately
    return os << fabs(t.coeff);
  }
  if (t.coeff == 0.0) {
    return os;
  }
  else if (t.coeff == 1.0) {
    os << "x";
  }
  // Again sign will be printed separately
  else if (t.coeff == -1.0) {
    os << "x";
  }
  else {
    // Same comment
    os << fabs(t.coeff) << "x";
  }
  if (t.exp == 1) {
    // The coefficient has already been sent to the stream
    return os;
  }
  else {
    return os << "^" << t.exp;
  }
}

Polynomial::Term operator-(const Polynomial::Term& t) {
  return Polynomial::Term(-1 * t.coeff, t.exp);
}

// Multiplying two terms
Polynomial::Term operator*(const Polynomial::Term& t1, const Polynomial::Term& t2) {
  // The coefficients multiply and the exponents add
  return Polynomial::Term(t1.coeff * t2.coeff, t1.exp + t2.exp);
}

Polynomial::Term::Term(double c, int e) : coeff(c), exp(e) {
  
}

bool Polynomial::Term::operator==(const Term& t) const {
  return coeff == t.coeff && exp == t.exp;
}
 
bool Polynomial::Term::operator<(const Term& t) const {
  // Higher order terms come before lower ordered terms
  return exp > t.exp;
}

Polynomial& Polynomial::operator+=(const Polynomial::Term& t) {
  polynomial.push_front(t);
  return *this;
}

void Polynomial::reduce() {
  if (polynomial.size() == 0) {
    return;
  }
  for (std::list<Polynomial::Term>::iterator it = polynomial.begin(); it != polynomial.end(); ) {
    int common_power = it->exp;
    std::list<Polynomial::Term>::const_iterator it2 = it;
    // Keep checking if iterator is pointing to fictitious last element
    // to prevent it from being incremented
    if (it == polynomial.end()) {
      return;
    }
    ++it2;
    if (it2 == polynomial.end()) {
      return;
    }
    // Collecting like powers
    for ( ; it2->exp == common_power && it2 != polynomial.end(); ++it2) {
      it->coeff += it2->coeff;
    }
    std::list<Polynomial::Term>::const_iterator it3 = it;
    if (it == polynomial.end()) {
      return;
    }
    ++it3;
    if (it3 == polynomial.end()) {
      return;
    }
    // Erase extra terms now that they have been consolidated into one term
    polynomial.erase(it3, it2);
    // If the sum of the coefficients happened to be 0, erase it
    if (it->coeff == 0.0) {
      // Sets it to the proper place after erasing so don't need to increment it here
      it = polynomial.erase(it);
    }
    else {
      ++it;
    }
  }
}
