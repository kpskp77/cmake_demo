#ifndef DOG_HPP_GBNTZMNY
#define DOG_HPP_GBNTZMNY

#include <memory>

class Dog {
  public:
    Dog();
    Dog(char const *name);
    ~Dog();
    void bark() const;
    void setAge(int age);
    int  getAge() const;

  private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

#endif /* end of include guard: DOG_HPP_GBNTZMNY */

