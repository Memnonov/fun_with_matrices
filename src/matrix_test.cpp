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

  std::cout << "Testing out of bounds element.\n";
  try {
    testMatrix[6][6] = 666;
  } catch (std::out_of_range exc) {
    std::cout << "Exception caught:\n" << exc.what() << '\n';
  }

  return EXIT_SUCCESS;
}
