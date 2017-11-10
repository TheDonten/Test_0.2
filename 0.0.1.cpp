#include<iostream>
#include <utility>
#include <sstream>
using namespace std;

bool read(double *array,  int size) {
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
  if(stream>>x){
	cout<<"An error has occured while reading numbers from line"<<endl;
	exit(0);
	}
  return true;

}
void reverse(double *array, int size) 
{
	for(int i=0; i<size/2;i++)
	{
	  swap(array[i],array[size-i-1]);
	}
}
void print_array(double *array,  int size) {
  for (unsigned int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
}
int main() {
   int size;
  string string;
  getline(cin, string);
  istringstream stream(string);
  if (!(stream >> size)|| (size<0) ) {
    cout << "An error has occured while reading numbers from line";
    return -1;
  }
  double *array = new double[size];
  if (read(array, size)) {
     
	reverse(array, size);
    print_array(array, size);
    cin.get();
  } 
  else {
    cout << "An error has occured while reading numbers from line";
    cin.get();
  }
  delete[] array;
  return 0;
}
