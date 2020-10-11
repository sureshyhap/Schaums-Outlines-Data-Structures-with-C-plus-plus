#include "Big_Int.h"

Big_Int operator-(const Big_Int& bi) {
  Big_Int temp(bi);
  if (bi.is_neg == false) {
    temp.is_neg == true;
  }
  else {
    temp.is_neg = false;
  }
}

Big_Int operator+(const Big_Int& bi1, const Big_Int& bi2) {
  Big_Int bi;
  int size1 = bi1.number.size();
  int size2 = bi2.number.size();
  int min = (size1 < size2 ? size1 : size2);
  // Same sign
  if (bi1.is_neg == bi2.is_neg) {
    int i = 0;
    std::list<int>::const_iterator it1 = bi1.number.begin(), it2 = bi2.number.begin();
    int carry = 0;
    int result = 0;
    // Start from least significant digits and work up from there
    for (; i < min; ++i, ++it1, ++it2) {
      result = *it1 + *it2 + carry;
      if (result >= Big_Int::VALUES_PER_NODE) {
	// Strip carry from sum
	carry = 1;
	result -= Big_Int::VALUES_PER_NODE;
      }
      else {
	carry = 0;
      }
      bi.number.push_back(result);
    }
    
    if (size1 == size2) {
      if (carry) {
	bi.number.push_back(carry);
      }
    }
    else if (size1 > size2) {
      while (it1 != bi1.number.end()) {
	result = *it1++ + carry;
	if (result >= Big_Int::VALUES_PER_NODE) {
	  carry = 1;
	  result -= Big_Int::VALUES_PER_NODE;
	}
	else {
	  carry = 0;
	}
	bi.number.push_back(result);
      }
      if (carry) {
	bi.number.push_back(carry);
      }
    }
    else if (size1 < size2) {
      while (it2 != bi2.number.end()) {
	result = *it2++ + carry;
	if (result >= Big_Int::VALUES_PER_NODE) {
	  carry = 1;
	  result -= Big_Int::VALUES_PER_NODE;
	}
	else {
	  carry = 0;
	}
	bi.number.push_back(result);
      }
      if (carry) {
	bi.number.push_back(carry);
     
      }
    }
    // Both are negative
    if (bi1.is_neg && bi2.is_neg) {
      bi.is_neg = true;
    } 
    // Both are positive (since their is_neg's are equal and not negative)
    else {
      bi.is_neg = false;
    }
    return bi;
  }
  else if (!bi1.is_neg && bi2.is_neg) {
    Big_Int temp1 = bi1;
    Big_Int temp2 = bi2;
    temp1.is_neg = false;
    temp2.is_neg = false;
    return temp1 - temp2;
  }
  else if (bi1.is_neg && !bi2.is_neg) {
    Big_Int temp1 = bi1;
    Big_Int temp2 = bi2;
    temp1.is_neg = false;
    temp2.is_neg = false;
    return temp2 - temp1;
  }
}

Big_Int operator-(const Big_Int& bi1, const Big_Int& bi2) {
  Big_Int result;
  Big_Int bigger, smaller;
  bool bigger_found = find_bigger(bi1, bi2, bigger, smaller);
  // Equal size
  if (bigger_found == false) {
    for (std::list<int>::const_reverse_iterator rit1 = bi1.number.rbegin(), rit2 = bi2.number.rbegin();
	 rit1 != bi1.number.rend(); ++rit1, ++rit2) {
      if (*rit1 > *rit2) {
	bigger = bi1;
	smaller = bi2;
	bigger_found = true;
	break;
      }
      else if (*rit2 > *rit1) {
	bigger = bi2;
	smaller = bi1;
	bigger_found = true;
	break;
      }
    }
    // The only way this is possible is if the numbers have
    // the same magnitude
    if (bigger_found == false) {
      // Same sign
      if (bi1.is_neg == bi2.is_neg) {
	result.number.push_back(0);
	result.is_neg = false;
	return result;
      }
      else {
	// bi1 is negative and bi2 is not negative
	if (bi1.is_neg == true) {
	  bigger = smaller = bi1;
	  bigger.is_neg = true;
	  smaller.is_neg = true;
	  return bigger + smaller;
	}
	// bi1 is not negative and bi2 is negative
	else {
	  bigger = smaller = bi1;
	  bigger.is_neg = false;
	  smaller.is_neg = false;
	  return bigger + smaller;
	}
      }
    }
  }
  // Now bigger and smaller have been established
  // Addition of negative numbers 
  if (bigger.is_neg != smaller.is_neg) {
    if (bigger.is_neg == false) {
      if (bigger == bi1) {
	// Redundant but here for clarity
	bigger.is_neg = false;
	smaller.is_neg = false;
	return bigger + smaller;
      }
      else {
	bigger.is_neg = true;
	smaller.is_neg = true;
	return bigger + smaller;
      }
    }
    // bigger is negative
    else {
      if (bigger == bi1) {
	// Redundant but here for clarity
	bigger.is_neg = true;
	smaller.is_neg = true;
	return bigger + smaller;
      }
      else {
	bigger.is_neg = false;
	smaller.is_neg = false;
	return bigger + smaller;
      }
    }
  }
  // If reached here the problem is true subtraction.
  // They are both the same sign.
  // This sets up the sign of the result
  else {
    if (bi1.is_neg == false) {
      if (bigger == bi1) {
	result.is_neg = false;
      }
      else {
	result.is_neg = true;
      }
    }
    else {
      if (bigger == bi1) {
	result.is_neg = true;
      }
      else {
	result.is_neg = false;
      }
    }
    // Now the true subtraction algorithm begins
    // Declared outside because it1 may be needed after the loop
    std::list<int>::iterator it1 = bigger.number.begin();
    for (std::list<int>::iterator it2 = smaller.number.begin();
	 (it1 != bigger.number.end()) && (it2 != smaller.number.end()); ++it1, ++it2) {
      int temp_res = *it1 - *it2;
      if (temp_res >= 0) {
	result.number.push_back(temp_res);
	continue;
      }
      else {
	// Borrow 1 from higher term.
	// If this is the case then there will always
	// be a next node to borrow from because
	// bigger > smaller. If they were the same size
	// and this is the last subtraction (of highest
	// terms) then this could not happen because
	// the most significant digits of bigger must
	// be bigger and thus won't need a borrow.
	// The final term must be nonnegative if this
	// is the case.
	// Allowed to change bigger and smaller.
	// It's okay if the next term becomes -1 (if they
	// are all 0s), it will still work out
	*(++it1) -= 1;
	--it1;
	// 1 from higher term == VALUES_PER_NODE
	temp_res += Big_Int::VALUES_PER_NODE;
	result.number.push_back(temp_res);
      }
    }
    // If same size then answer should be already calculated
    if (bigger.number.size() == smaller.number.size()) {
      return result;
    }
    // bigger's number list is bigger in size than smaller
    else {
      // At this point this is only possible if was a
      // string of 0s that was borrowed from
      while (*it1 < 0) {
	*(++it1) -= 1;
	--it1;
	// Will be string of 9s
	(*it1) += Big_Int::VALUES_PER_NODE;
	result.number.push_back(*it1);
	++it1;
      }
      // When above loop stops, then can just
      // bring down the rest of bigger
      result.number.push_back(*it1);
      while (++it1 != bigger.number.end()) {
	result.number.push_back(*it1);
      }
      --it1;
      // If 0 left over from borrowing remove it
      if (*it1 == 0) {
	result.number.pop_back();
      }
      return result;
    }
  }
}

Big_Int operator*(const Big_Int& bi1, const Big_Int& bi2) {
  Big_Int result;
  if (bi1.is_neg == bi2.is_neg) {
    result.is_neg = false;
  }
  else {
    result.is_neg = true;
  }
  Big_Int bigger, smaller;
  find_bigger(bi1, bi2, bigger, smaller);
  int carry = 0;
  std::list<Big_Int> summands;
  int zeros = 0;
  for (std::list<int>::iterator it2 = smaller.number.begin(); it2 != smaller.number.end(); ++it2) {
    Big_Int temp_summand;
    for (int i = 0; i < zeros; ++i) {
      temp_summand.number.push_back(0);
    }
    for (std::list<int>::iterator it1 = bigger.number.begin(); it1 != bigger.number.end(); ++it1) {
      int temp_res = *it1 * *it2;
      temp_res += carry;
      if (temp_res >= Big_Int::VALUES_PER_NODE) {
	carry = temp_res / Big_Int::VALUES_PER_NODE;
	temp_res %= Big_Int::VALUES_PER_NODE;
      }
      else {
	carry = 0;
      }
      temp_summand.number.push_back(temp_res);
    }
    if (carry) {
      temp_summand.number.push_back(carry);
      carry = 0;
    }
    summands.push_back(temp_summand);
    ++zeros;
  }
  for (std::list<Big_Int>::iterator it = summands.begin(); it != summands.end(); ++it) {
    result += *it;
  }
  return result;
}

Big_Int operator*(int n, const Big_Int& b) {
  std::ostringstream oss;
  oss << n;
  Big_Int b2(oss.str());
  return b * b2;
}

Big_Int operator*(const Big_Int& b, int n) {
  std::ostringstream oss;
  oss << n;
  Big_Int b2(oss.str());
  return b * b2;  
}

std::istream& operator>>(std::istream& is, Big_Int& b) {
  std::string num;
  is >> num;
  Big_Int bi(num);
  b = bi;
  return is;
}

std::ostream& operator<<(std::ostream& os, const Big_Int& b) {
  if (b.is_neg) {
    os << '-';
  }
  std::list<int>::const_reverse_iterator first_element = b.number.rend();
  ++first_element;
  for (std::list<int>::const_reverse_iterator rit = b.number.rbegin(); rit != b.number.rend(); ++rit) {
    if (rit != first_element) {
      // Special case where the node value is 0
      if (*rit == 0) {
	for (int i = 0; i < Big_Int::DIGITS_PER_NODE; ++i) {
	  os << "0";
	}
	continue;
      }
      // Number of digits in the node
      int digits = log10(*rit) + 1;
      // Padding the node with zeros if it has less
      // digits than DIGITS_PER_NODE
      for (int padding_zeros = Big_Int::DIGITS_PER_NODE - digits; padding_zeros > 0; --padding_zeros) {
	os << "0";
      }
    }
    // Outputting the number
    os << *rit;
  }
  os << "\n";
  return os;
}

bool find_bigger(const Big_Int& bi1, const Big_Int& bi2, Big_Int& bigger, Big_Int& smaller) {
  if (bi1.number.size() > bi2.number.size()) {
    bigger = bi1;
    smaller = bi2;
    return true;
  }
  else if (bi2.number.size() > bi1.number.size()) {
    bigger = bi2;
    smaller = bi1;
    return true;
  }
  // Equal size
  else {
    bool bigger_found = false;
    for (std::list<int>::const_reverse_iterator rit1 = bi1.number.rbegin(), rit2 = bi2.number.rbegin();
	 rit1 != bi1.number.rend(); ++rit1, ++rit2) {
      if (*rit1 > *rit2) {
	bigger = bi1;
	smaller = bi2;
	bigger_found = true;
	break;
      }
      else if (*rit2 > *rit1) {
	bigger = bi2;
	smaller = bi1;
	bigger_found = true;
	break;
      }
    }
    if (bigger_found == false) {
      // Same magnitude
      bigger = smaller = bi1;
      return false;
    }
    else {
      return true;
    }
  }
}

Big_Int::Big_Int() {
  is_neg = false;
  number;
}

Big_Int::Big_Int(std::string num) {
  if (num[0] == '-') {
    is_neg = true;
    num = num.substr(1);
  }
  else {
    is_neg = false;
  }
  // While num will take up more than one node
  while (num.length() > Big_Int::DIGITS_PER_NODE) {
    // Extract the first set of digits from num
    std::string sub = num.substr(num.length() - Big_Int::DIGITS_PER_NODE, Big_Int::DIGITS_PER_NODE);
    std::istringstream is(sub);
    int piece = 0;
    // Write the digits to an int
    is >> piece;
    // Add the digits to the number list
    number.push_back(piece);
    // Restart process with digits not yet added to list
    num = num.substr(0, num.length() - Big_Int::DIGITS_PER_NODE);
  }
  // Not cleanest code; just copying above
  std::istringstream is(num);
  int last_piece = 0;
  is >> last_piece;
  number.push_back(last_piece);
  /////////////////////////////////////////// Erase leading zeros
}

Big_Int::Big_Int(const Big_Int& bi) {
  number = bi.number;
  is_neg = bi.is_neg;
}

void Big_Int::print() const {
  std::cout << (*this);
}

// Only works properly is Big_Int can fit in an int
int Big_Int::to_int() const {
  std::ostringstream oss;
  oss << (*this);
  std::istringstream is(oss.str());
  int num = 0;
  is >> num;
  return num;
}

double Big_Int::to_double() const {
  int n = to_int();
  return double(n);
}

Big_Int& Big_Int::operator=(const Big_Int& bi) {
  number = bi.number;
  is_neg = bi.is_neg;
}

bool Big_Int::operator==(const Big_Int& bi) {
  return number == bi.number && is_neg == bi.is_neg;
}

bool Big_Int::operator<(const Big_Int& bi) {
  // If only one is negative the result is quick
  if (is_neg && !bi.is_neg) {
    return true;
  }
  else if (!is_neg && bi.is_neg) {
    return false;
  }
  // After here they must be the same sign
  if (number.size() < bi.number.size()) {
    if (!is_neg) {
      return true;
    }
    else {
      return false;
    }
  }
  for (std::list<int>::const_reverse_iterator this_it = number.rbegin(), bi_it = bi.number.rbegin();
       this_it != number.rend(); ++this_it, ++bi_it) {
    if (*this_it != *bi_it) {
      if (*this_it < *bi_it) {
	if (!is_neg && !bi.is_neg) {
	  return true;
	}
	else {
	  return false;
	}
      }
      else {
	if (!is_neg && !bi.is_neg) {
	  return false;
	}
	else {
	  return true;
	}
      }
    }
  }
  // Equal
  return false;
}

bool Big_Int::operator<=(const Big_Int& bi) {
  return (*this) < bi || (*this) == bi;
}

bool Big_Int::operator>(const Big_Int& bi) {
  return !((*this) <= bi);
}

bool Big_Int::operator>=(const Big_Int& bi) {
  return (*this) > bi || (*this) == bi;
}

bool Big_Int::operator!=(const Big_Int& b) {
  return number != b.number || is_neg != b.is_neg;
}

Big_Int& Big_Int::operator+=(const Big_Int& b) {
  (*this) = (*this) + b;
  return *this;
}

Big_Int& Big_Int::operator-=(const Big_Int& b) {
  (*this) = (*this) - b;
  return *this;
}

Big_Int& Big_Int::operator*=(int n) {
  (*this) = (*this) * n;
  return *this;
}

Big_Int& Big_Int::operator*=(const Big_Int& b) {
  (*this) = (*this) * b;
  return *this;
}

const int Big_Int::DIGITS_PER_NODE = 4;

const int Big_Int::VALUES_PER_NODE = pow(10, Big_Int::DIGITS_PER_NODE);
