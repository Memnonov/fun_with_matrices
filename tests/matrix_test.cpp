#include "../include/matrix.hpp"
#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main() {
  Matrix testMatrix;

  std::cout << "Default matrix:\n";
  testMatrix.print();

  std::cout << "4x4\n";
  testMatrix = Matrix(4, 4);
  testMatrix.print();

  std::cout << "6x8\n";
  testMatrix = Matrix(6, 8);
  testMatrix.print();

  std::cout << "[5][3] = 6\n";
  testMatrix[5][3] = 6.0f;
  testMatrix.print();

  std::cout << "at(2, 2)";
  testMatrix.at(2, 2) = 6.0f;
  testMatrix.print();

  std::cout << "Trying to initialize (0, 2) and (2, 0)\n";
  try {
    Matrix invalidMatrix(0, 2);
  } catch (std::invalid_argument) {
    std::cout << "Can't initialize with 0 rows!\n";
  }

  try {
    Matrix invalidMatrix(2, 0);
  } catch (std::invalid_argument exc) {
    std::cout << "Can't initialize with 0 rows!\n\n";
  }

  std::cout << "Testing out of bounds element.\n";
  try {
    testMatrix.at(6, 6) = 666;
  } catch (std::out_of_range exc) {
    std::cout << "Exception caught:\n" << exc.what() << "\n\n";
  }

  std::cout << "Testing constructor with initializer list.\n";
  testMatrix = Matrix({{1, 2, 3}, {4, 5, 6}});
  testMatrix.print();

  std::cout << "Testing invalid initializer lists.\n";
  try {
    Matrix invalidMatrix({{}, {1, 2, 3}});
  } catch (std::invalid_argument exc) {
    std::cout << exc.what() << '\n';
  }
  try {
    Matrix invalidMatrix({{1, 2, 3}, {1, 2}});
  } catch (std::invalid_argument exc) {
    std::cout << exc.what() << "\n\n";
  }

  std::cout << "Testing multiplication: transforming row order\n";
  testMatrix = Matrix({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
  testMatrix.print();
  std::cout << "Transformed matrix:\n";
  testMatrix = Matrix({{0, 0, 1}, {0, 1, 0}, {1, 0, 0}}) * testMatrix;
  testMatrix.print();

  std::cout << "Transforming to R³ vector\n";
  testMatrix = Matrix({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
  testMatrix.print();
  Matrix transformationMatrix({{1, 1, 1}});
  transformationMatrix.print();
  testMatrix = transformationMatrix * testMatrix;
  testMatrix.print();

  std::cout << "Transposing a matrix.\n";
  testMatrix = Matrix({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
  testMatrix.print();
  testMatrix = testMatrix.transpose();
  testMatrix.print();

  std::cout << "Testing Matrix::transform.\n";
  testMatrix = Matrix({{1, 2, 3}, {4, 5, 6}});
  testMatrix.print();
  std::cout << "Flipping rows:\n";
  testMatrix.transform({{0, 1}, {1, 0}}).transform({{1, 0}, {0, 1}}); // chaining!
  testMatrix.print();

  return EXIT_SUCCESS;
}
