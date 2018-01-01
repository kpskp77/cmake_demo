#include <iostream>

#include <cat/cat.hpp>
#include <ext.hpp>

#include "configVersion.hpp"
#include "dog/dog.hpp"

int main() {
    std::cout << "demo project 'main' version info: " << MAIN_VERSION_MAJOR
              << '.' << MAIN_VERSION_MINOR << '.' << MAIN_VERSION_PATCH << '\n';
    Dog dog1;
    Dog dog2("dog2");
    dog2.setAge(4);

    dog1.bark();
    dog2.bark();

    Cat cat1("cat1");
    cat1.setAge(5);
    cat1.meow();

    cat0.meow();

    Ext ext;
    ext.version();

    return 0;
}

