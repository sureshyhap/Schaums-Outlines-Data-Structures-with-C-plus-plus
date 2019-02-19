#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <list>
#include <iostream>

class Polynomial {
  friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);
  friend Polynomial operator*(double factor, const Polynomial& p);
  friend Polynomial operator+(const Polynomial& p1, const Polynomial& p2);
  friend Polynomial operator-(const Polynomial& p);
  friend Polynomial operator-(const Polynomial& p, const Polynomial& q);
  friend Polynomial operator*(const Polynomial& p, const Polynomial& q);
  friend Polynomial derivative(const Polynomial& p);
  friend Polynomial antiderivative(const Polynomial& p);
 public:
  Polynomial(double c = 0.0, int e = 0);
  Polynomial(const Polynomial& p);
  Polynomial& operator=(const Polynomial& p);
  Polynomial& operator+=(const Polynomial& p);
  Polynomial& operator-=(const Polynomial& p);
  Polynomial& operator*=(double x);
  Polynomial& operator*=(const Polynomial& p);
  bool operator==(const Polynomial& p);
  bool operator!=(const Polynomial& p);
  double operator()(double x) const;
  int get_degree() const;
  int get_terms() const;
  void print() const;
  // A single term in the polynomial like 5x^2 for instance
  struct Term {
    friend class Polynomial;
    friend std::ostream& operator<<(std::ostream& os, const Term& t);
    friend Term operator-(const Term& t);
    friend Term operator*(const Term& t1, const Term& t2);
    friend Term derivative(const Term& t);
    friend Term antiderivative(const Term& t);
    Term(double c = 0.0, int e = 0);
    bool operator==(const Term& t) const;
    bool operator!=(const Term& t) const;
    bool operator<(const Term& t) const;
    double coeff;
    int exp;
    static const Polynomial ONE;
    static const Polynomial X;
  };
  Polynomial& operator+=(const Term& t);
  const std::list<Term>& get_polynomial() const;
protected:
  // Collection of terms
  std::list<Term> polynomial;
  int degree;
  void reduce();
};

#endif // POLYNOMIAL_H
