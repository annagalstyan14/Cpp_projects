#include <iostream>
using namespace std;

template <typename T>
class vector 
{
public:
  vector() : size(0), capacity(1)
  {
    data = new T[capacity];
  }

  ~vector() {  delete[] data; }

  size_t Size() { return size; }

  T& end()
  {
    if (size == 0) {
      throw std::out_of_range("Vector is empty");
    }
    return data[size - 1];
  }

  T& begin()
  {
    if (size == 0) {
      throw std::out_of_range("Vector is empty");
    }
    return data[0];
  }

  void push_back(const T& el)
  {
    if (size == capacity) {
      resize(2 * capacity);
    }
    data[size] = el;
    size++;
  }

  void pop_back()
  {
    if (size == 0) throw std::out_of_range("Vector is empty");
    size--;
  }

  void clear() { size = 0; }

  T& operator[](int index) {
    if (index >= size || index < 0) throw std::out_of_range("Index out of range");
    return data[index];
  }

private:
  size_t size;
  size_t capacity;
  T* data;

  void resize(size_t new_cap)
  {
    T* new_data = new T[new_cap];
    for (int i = 0; i < size; i++) {
      new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = new_cap;
  }
};


int main() 
{
  vector<int> vec;

  for (int i = 0; i < 10; i++) {
    vec.push_back(i);
  }
  cout << "First element: " << vec.begin() << endl;
  cout << "Last element: " << vec.end() << endl;
  vec.pop_back();
  for (int i = 0; i < vec.Size(); i++) {
    cout << vec[i] << endl;
  }

  return 0;
}
