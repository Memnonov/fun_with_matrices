#include "../include/matrix.hpp"
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <iterator>
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

Matrix Matrix::operator*(const Matrix &other) const {
  if (this->columns != other.rows) {
    throw std::invalid_argument(INCOMPATIBLE_EXC + '*');
  }

  Matrix result(this->rows, other.columns);

  // O(n³) : DDD slow boi, should be OK with these small matrices
  for (std::size_t i = 0; i < this->rows; ++i) {
    for (std::size_t j = 0; j < other.columns; ++j) {
      float product = 0.0f;
      for (std::size_t k = 0; k < this->columns; ++k) {
        product += this->data[i][k] * other.data[k][j];
      }
      result.data[i][j] = product;
    }
  }
  return result;
}

Matrix Matrix::transpose() const {
  Matrix result(columns, rows);
  for (std::size_t i = 0; i < rows; ++i) {
    for (std::size_t j = 0; j < columns; ++j) {
      result[j][i] = data[i][j];
    }
  }
  return result;
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
