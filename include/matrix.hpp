#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <stdexcept>
#include <string>
#include <vector>

const std::string OUT_OF_BOUNDS_EXC{"Trying to access out of bounds element! "};
const std::string ZERO_DIMENSION_EXC{"Dimensions of the matrix must be non-zero!"};
const std::string INCOMPATIBLE_EXC{"Using operator on incompatible matrices! Operator: "};

class Matrix {

private:
  unsigned int rows{1};
  unsigned int columns{1};
  std::vector<std::vector<float>> data;

public:
  explicit Matrix() : data{std::vector(1, std::vector<float>(1, 0.0f))} {};

  explicit Matrix(unsigned int rows, unsigned int columns) {
    if (rows == 0 || columns == 0) {
      throw std::invalid_argument(ZERO_DIMENSION_EXC);
    }
    this->rows = rows;
    this->columns = columns;
    data = std::vector(rows, std::vector<float>(columns, 0.0f));
  }

  explicit Matrix(std::initializer_list<std::initializer_list<float>>);

  // No boundary checking, dangerous and cool!
  std::vector<float> &operator[](unsigned int row) { return data[row]; }

  const std::vector<float> &operator[](unsigned int row) const { return data[row]; }

  // Boundary checked access to elements
  float &at(unsigned int row, unsigned int column) {
    if (row >= rows || column >= columns) {
      throw std::out_of_range(OUT_OF_BOUNDS_EXC + std::to_string(row) + " | " +
                              std::to_string(column));
    }
    return data[row][column];
  }

  const float &at(unsigned int row, unsigned int column) const {
    if (row >= rows || column >= columns) {
      throw std::out_of_range(OUT_OF_BOUNDS_EXC + std::to_string(row) + " | " +
                              std::to_string(column));
    }
    return data[row][column];
  }

  Matrix operator*(const Matrix &other) const;

  void print() const;
};

#endif // !MATRIX_HPPj
