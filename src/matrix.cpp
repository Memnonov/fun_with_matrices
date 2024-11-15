#include "../include/matrix.hpp"
#include <iostream>

void Matrix::print() const {
  std::cout << "{ " << rows << " x " << columns << " }\n";
  for (const auto& row : data) {
    for (float value : row) {
      std::cout << value << " ";
    }
      std::cout << '\n';
  }
  std::cout << '\n';
}
