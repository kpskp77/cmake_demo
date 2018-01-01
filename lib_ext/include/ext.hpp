#ifndef EXT_HPP_QB0TAEXU
#define EXT_HPP_QB0TAEXU

#include <memory>

#include "lib_ext_EXPORTS.h"

class LIB_EXT_SHARED_EXPORT Ext {
  public:
    Ext();
    Ext(char const *name);
    ~Ext();
    void version() const;

  private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

#endif /* end of include guard: EXT_HPP_QB0TAEXU */

