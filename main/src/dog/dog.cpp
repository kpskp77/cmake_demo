#include <iostream>
#include <string>

#include "dog/dog.hh"
#include "dog/dog.hpp"

struct Dog::Impl {
    std::string name;
    int         age;
};

Dog::Dog() : impl(std::make_unique<Impl>()) {
    impl->name = "Unknown";
    impl->age  = 0;
}

Dog::Dog(char const *name) : Dog() { impl->name = name; }

Dog::~Dog() {}

void Dog::setAge(int age) { impl->age = age; }

int Dog::getAge() const { return impl->age; }

void Dog::bark() const {
    bark_private();
    std::cout << "Dog " << impl->name << " Here! Age: " << impl->age << '\n';
}

