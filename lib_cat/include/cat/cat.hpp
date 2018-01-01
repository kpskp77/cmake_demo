#ifndef CAT_HPP_PQFGZHPC
#define CAT_HPP_PQFGZHPC

#include <memory>

#include "lib_cat_EXPORTS.h"

class LIB_CAT_SHARED_EXPORT Cat {
  public:
    Cat();
    Cat(char const *name);
    ~Cat();
    void version() const;
    void meow() const;
    void setAge(int age);
    int  getAge() const;

  private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

extern LIB_CAT_SHARED_EXPORT Cat cat0;

#endif /* end of include guard: CAT_HPP_PQFGZHPC */

