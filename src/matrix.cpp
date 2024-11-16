#include "../include/matrix.hpp"
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <string>

const std::string INVALID_DIMENSIONS_EXC{"Invalid matrix dimensions: "};

Matrix::Matrix(std::initializer_list<std::initializer_list<float>> init) {
  if (!init.size()) {
    throw std::invalid_argument(INVALID_DIMENSIONS_EXC + "Rows must be non-zero!");
  }
  
  rows = init.size();

  auto it = init.begin();
  std::size_t length = it->size();
  columns = length;
  
  if (length == 0) {
    throw std::invalid_argument(INVALID_DIMENSIONS_EXC + "Columns must be non-zero!");
  }
  for (auto row : init) {
    if (row.size() != length) {
      throw std::invalid_argument(INVALID_DIMENSIONS_EXC + "Columns must match!");
    }
    data.push_back(row);
  }
}

void Matrix::print() const {
  std::cout << "{ " << rows << " x " << columns << " }\n";
  for (const auto &row : data) {
    for (float value : row) {
      std::cout << value << " ";
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}
