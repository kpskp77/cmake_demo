#include <iostream>
#include <string>

#include "configVersion.hpp"
#include "ext.hpp"

struct Ext::Impl {
    std::string name;
    int         age;
};

Ext::Ext() : impl(std::make_unique<Impl>()) {
    impl->name = "Unknown";
    impl->age  = 0;
}

Ext::Ext(char const *name) : Ext() { impl->name = name; }

Ext::~Ext() {}

void Ext::version() const {
    std::cout << "lib_ext version info: " << LIB_EXT_VERSION_MAJOR << '.'
              << LIB_EXT_VERSION_MINOR << '.' << LIB_EXT_VERSION_PATCH << '\n';
}

