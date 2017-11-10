#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
using namespace std;

bool read(float **&matrix, unsigned int &rows, unsigned int &columns) {
  bool result = true;
  char op;
  string string, string1;
  getline(cin, string);
  istringstream stream(string);
  if (stream >> rows && stream >> op && op == ',' && stream >> columns) {
    result = true;
  } else
    return false;
  matrix = new float *[rows];
  for (unsigned int i = 0; i < rows; i++) {
    matrix[i] = new float[columns];
    getline(cin, string1);
    istringstream stream(string1);
    for (unsigned int j = 0; j < columns; j++) {
      if (!(stream >> matrix[i][j])) {
        result = false;
        break;
      }
    }
  }
  return result;
}
void sdvig(float *array, int size, int m) {
  float *array_left = new float[size - m];
  float *array_right = new float[m];
  for (unsigned int i = 0; i < size; ++i) {
    if (i < size - m) {
      array_left[i] = array[i];
    } else {
      array_right[i + m - size] = array[i];
    }
  }
  for (unsigned int i = 0; i < (size - m) / 2; ++i) {
    swap(array_left[i], array_left[size - m - 1 - i]);
  }
  for (unsigned int i = 0; i < m / 2; ++i) {
    swap(array_right[i], array_right[m - 1 - i]);
  }
  for (unsigned int i = 0; i < size; ++i) {
    if (i < size - m) {
      array[i] = array_left[i];
    } else {
      array[i] = array_right[i + m - size];
    }
  }
  for (unsigned int i = 0; i < size / 2; ++i) {
    swap(array[i], array[size - 1 - i]);
  }
}
void reverse(float **&matrix, unsigned int rows, unsigned int columns, int m) {
  unsigned int size = (rows + columns) * 2 - 4;
  float *array = new float[size];
  int element = 0;
  for (unsigned int i = 0; i < columns; i++) {
    array[element] = matrix[0][i];
    element++;
  }
  for (unsigned int i = 1; i < rows - 1; i++) {
    array[element] = matrix[i][columns - 1];
    element++;
  }
  for (int i = columns - 1; i > -1; i--) {
    array[element] = matrix[rows - 1][i];
    element++;
  }
  for (unsigned int i = rows - 2; i > 0; i--) {
    array[element] = matrix[i][0];
    element++;
  }
  sdvig(array, size, m);
  element = 0;
  for (unsigned int i = 0; i < columns; i++) {
    matrix[0][i] = array[element];
    element++;
  }
  for (unsigned int i = 1; i < rows - 1; i++) {
    matrix[i][columns - 1] = array[element];
    element++;
  }
  for (int i = columns - 1; i > -1; i--) {
    matrix[rows - 1][i] = array[element];
    element++;
  }
  for (unsigned int i = rows - 2; i > 0; i--) {
    matrix[i][0] = array[element];
    element++;
  }
}

void delete_memory(float **matrix, unsigned int rows) {
  for (unsigned int i = 0; i < rows; ++i) {
    delete[] matrix[i];
  }
  delete[] matrix;
}

void write(ostream &stream, float **matrix, unsigned int rows,
           unsigned int columns) {
  stream << endl;
  for (unsigned int i = 0; i < rows; i++) {
    for (unsigned int j = 0; j < columns; j++) {
      if (matrix[i][j] == -0) {
        stream << 0 << " ";
      } else {
        stream << matrix[i][j] << " ";
      }
    }
    stream << endl;
  }
}

int main() {
  int m;
  unsigned int rows = 0, columns = 0;
  char op;
  float **matrix = new float *[rows];

  if (read(matrix, rows, columns)) {
    write(cout, matrix, rows, columns);
    string stroka;
    getline(cin, stroka);
    istringstream stream(stroka);
    if (!(stream >> m) || (m < 1)) {
      cout << "Wrong" << endl;
      exit(0);
    }
    reverse(matrix, rows, columns, m);
    write(cout, matrix, rows, columns);
    delete_memory(matrix, rows);
  }
}
