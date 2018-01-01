# A demo project to demonstrate how to use cmake

```
demo_project
    |
    |-hello_world
    |
    |-lib_cat
    |
    |-main
    |

demo_project/lib_ext
```

`hello_world`, `lib_cat`, and `main` are three subproject of top-level project
`demo_project`. `hello world` is a trivial project. `lib_cat` is a library project,
and both shared and static library will be built. `main` project will use `lib_cat` and
`lib_ext`. Two targets of `main` will be built, one for dynamic link and the other for
static link.

`lib_ext` is a standalone project although which resides under folder *demo_project*.
The difference between `lib_ext` and `lib_cat` is that `lib_cat` is built together with
`main`, but `lib_ext` should been built and installed before building `demo_project`.

Because `lib_cat` is built together with `main`, part of properties of target `lib_cat`
is transitive to `main` (ie. Public headers), and cmake can figure it out automatically.
While, properties of `lib_ext` must been provided by users.

It's worth noting that library linking should match both architecture (x86 or x64) and
build type (Release or Debug). And of course, we should use the same compiler when
linking libraries.

Currently, `lib_ext` is expected to be built with MSVC on x86 in Release mode.
*CMakeLists.txt* of `main` is not smart enough to detect what kind of library `lib_ext` is,
the properties of `lib_ext` is specified as what it is expected to be. If you build `lib_ext`
differently, you should modify the *CMakeLists.txt* under *demo_projcet/main* as well.
