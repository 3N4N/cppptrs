#include <iostream>
#include <memory>

// using namespace std;

class Animal {
public:
  Animal()
  {}
  // for dynamic casting derived class from base
  // you need the baseclass to be polymorphic
  // i.e., it needs at least one virtual function
  virtual ~Animal()
  {}
  void speak()
  {
    std::cout << "I am an animal\n";
  }
};

class Dog : public Animal {
public:
  Dog()
  {}
  void bark()
  {
    std::cout << "Gheu --> ";
  }
  void speak()
  {
    bark();
    Animal::speak();
  }
};

typedef std::shared_ptr<Animal> AnimalPtr;
typedef std::shared_ptr<Dog> DogPtr;

int main()
{
  AnimalPtr ap = std::make_shared<Animal>();
  ap->speak();

  DogPtr dp = std::make_shared<Dog>();
  dp->speak();

  AnimalPtr ap1 = std::static_pointer_cast<Animal>(dp);
  DogPtr dp1 = std::dynamic_pointer_cast<Dog>(ap1); // needs polymorphic base
  dp1->speak();

  return 0;
}
