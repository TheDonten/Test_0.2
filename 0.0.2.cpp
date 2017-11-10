#include <iostream>
#include <utility>
#include <sstream>
#include <string>
using namespace std;

bool read(double *array, int size) {
  char x;
  bool k = true;
  string mas;
  getline(cin, mas);
  istringstream stream(mas);
  for (int i = 0; i < size; i++) {
    if (!(stream >> array[i])) {
      k = false;
      return false;
    }
  }
  if (stream >> x) {
    cout << "An error has occured while reading numbers from line" << endl;
    exit(0);
  }
  return true;
}
void reverse(double *array, int size, unsigned int m) {
  for (int i = 0; i < (size - m) / 2; i++) {
    swap(array[i], array[size - m - i - 1]);
  }
  for (int i = size - m, j = 0; i < size - m + (m / 2); i++, j++) {
    swap(array[i], array[size - 1 - j]);
  }
  for (int i = 0; i < (size / 2); i++) {
    swap(array[i], array[size - 1 - i]);
  }
}
void print_array(double *array, int size) {
  for (unsigned int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
}
int main() {
  int size;
  unsigned int m;
  string string;
  getline(cin, string);
  istringstream stream(string);
  if (!(stream >> size) || (size < 0)) {
    cout << "An error has occured while reading numbers from line" << endl;
    return -1;
  }
  double *array = new double[size];
  if (read(array, size)) {
    getline(cin, string);
    istringstream stream(string);
    if (!(stream >> m)) {
      cout << "An error has occurred while reading input data" << endl;
      return -1;
    }

    reverse(array, size, m);
    print_array(array, size);
    cin.get();
  } else {
    cout << "An error has occured while reading numbers from line";
    cin.get();
  }
  delete[] array;
  return 0;
}
