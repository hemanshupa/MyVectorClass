#include<iostream>
#include<string>

//#include "Array.h"
#include "Vector.h"


struct Vector3
{
   float x = 0.0f, y = 0.0f, z = 0.0f;
   int* m_MemoryBlock;

   Vector3() { m_MemoryBlock = new int[5]; };
   Vector3(float scalar)
      : x(scalar), y(scalar), z(scalar)
   {
      m_MemoryBlock = new int[5];
   }
   Vector3(float x, float y, float z)
      :x(x), y(y), z(z) {
      m_MemoryBlock = new int[5];
   }

   Vector3(const Vector3& other) = delete;
  //    :x(other.x), y(other.y), z(other.z) 
  // {
  //    std::cout << "Copy\n";
  // }

   Vector3(Vector3&& other)
      :x(other.x), y(other.y), z(other.z)
   {
      m_MemoryBlock = other.m_MemoryBlock;
      other.m_MemoryBlock = nullptr;
      std::cout << "Move\n";
   }

   Vector3& operator=(const Vector3& other) = delete;
   //{
   //   std::cout << "Copy\n";
   //   x = other.x;
   //   y = other.y;
   //   z = other.z;
   //   return *this;
   //}

   Vector3& operator=(Vector3&& other)
   {
      m_MemoryBlock = other.m_MemoryBlock;
      other.m_MemoryBlock = nullptr;
      std::cout << "Move\n";
      x = other.x;
      y = other.y;
      z = other.z;
      return *this;
   }

   ~Vector3()
   {
      std::cout << "Destroyed\n";
      delete[] m_MemoryBlock;
   }
};


template<typename  T>
void printVector(const Vector<T>& vector)
{
   for (size_t i = 0; i < vector.Size(); i++)
      std::cout << vector[i] << std::endl;

   std::cout << "---------------------------------------\n";
}

template<>
void printVector(const Vector<Vector3>& vector)
{
   for (size_t i = 0; i < vector.Size(); i++)
      std::cout << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << ", " << std::endl;

   std::cout << "---------------------------------------\n";
}

int main()
{
   //Array<std::string, 2> data;
   //data[0] = "Hemanshu";
   //data[1] = "C++";

   {
      Vector<Vector3> vector;
      //vector.PushBack(Vector3(1.0f));
      //vector.PushBack(Vector3(3,4,5));
      //vector.PushBack(Vector3());
      vector.EmplaceBack(1.0f);
      vector.EmplaceBack(3, 4, 5);
      vector.EmplaceBack(1, 3, 5);
      vector.EmplaceBack();
      printVector(vector);
      vector.PopBack();
      vector.PopBack();
      printVector(vector);
      vector.EmplaceBack(6, 7, 5);
      vector.EmplaceBack(3, 8, 8);
      printVector(vector);
      vector.Clear();
      printVector(vector);
      vector.EmplaceBack(6, 7, 5);
      vector.EmplaceBack(3, 8, 8);


      printVector(vector);
   }

   Vector<int> intVector;
   intVector.PushBack(5);
   intVector.EmplaceBack(7);
   printVector(intVector);
   intVector.PopBack();
   printVector(intVector);
   intVector.Clear();
   printVector(intVector);

   std::cin.get();

}