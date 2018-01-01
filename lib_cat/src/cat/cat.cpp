#include <iostream>
#include <string>

#include "cat/cat.hh"
#include "cat/cat.hpp"
#include "configVersion.hpp"

Cat cat0("cat0");

struct Cat::Impl {
    std::string name;
    int         age;
};

Cat::Cat() : impl(std::make_unique<Impl>()) {
    impl->name = "Unknown";
    impl->age  = 0;
}

Cat::Cat(char const *name) : Cat() { impl->name = name; }

Cat::~Cat() {}

void Cat::setAge(int age) { impl->age = age; }

int Cat::getAge() const { return impl->age; }

void Cat::meow() const {
    meow_private();
    std::cout << "Cat " << impl->name << " Here! Age: " << impl->age << '\n';
}

void Cat::version() const {
    std::cout << "lib_cat version info: " << LIB_CAT_VERSION_MAJOR << '.'
              << LIB_CAT_VERSION_MINOR << '.' << LIB_CAT_VERSION_PATCH << '\n';
}

