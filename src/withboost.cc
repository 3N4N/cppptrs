#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <memory>

using namespace std;
// using boost::static_pointer_cast;
// using boost::dynamic_pointer_cast;

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


typedef boost::shared_ptr<Animal> AnimalPtr;
typedef boost::shared_ptr<Dog> DogPtr;


int main()
{

  AnimalPtr ap = boost::make_shared<Animal>();
  ap->speak();

  DogPtr dp = boost::make_shared<Dog>();
  dp->speak();

  AnimalPtr ap1 = static_pointer_cast<Animal>(dp);
  DogPtr dp1 = dynamic_pointer_cast<Dog>(ap1);  // needs polymorphic base
  // AnimalPtr ap1 = boost::static_pointer_cast<Animal>(dp);
  // DogPtr dp1 = boost::dynamic_pointer_cast<Dog>(ap1);  // needs polymorphic base

  Dog *p = dynamic_cast<Dog *>(ap1.get());
  DogPtr dp2 = DogPtr(ap1, p);
  dp2->speak();

  return 0;
}
