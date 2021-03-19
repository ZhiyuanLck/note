# C++中的空指针

## NULL

[参考链接](https://en.cppreference.com/w/cpp/types/NULL)

NULL在多个头文件中均有定义。NULL是实现定义(implementation-defined)的空指针常量。

- C++11前：求值为0的整数类型字面常量表达式右值
- C++11后：整数字面量0，或者是`std::nullptr_t`类型纯右值(prvalue)

可能的实现

```cpp
#define NULL 0
#define NULL nullptr // c++11
```

`stddef.h`中的实现（`cstddef`导入了`stddef.h`）

```cpp
#if defined(__need_NULL)
#undef NULL
#ifdef __cplusplus
#  if !defined(__MINGW32__) && !defined(_MSC_VER)
#    define NULL __null
#  else
#    define NULL 0
#  endif
#else
#  define NULL ((void*)0) // C++中不允许NULL类型为void*
#endif
#ifdef __cplusplus
#if defined(_MSC_EXTENSIONS) && defined(_NATIVE_NULLPTR_SUPPORTED)
namespace std { typedef decltype(nullptr) nullptr_t; }
using ::std::nullptr_t;
#endif
#endif
#undef __need_NULL
#endif /* defined(__need_NULL) */
```

注意上面的定义中，在C中`NULL`的类型是`void*`，**在C++中则不行是整数类型**

**类型转换**

- 空指针常量可以隐式转换为任何指针类型，转换结果为该类型的空指针值。
- 如果空指针常量是整数类型，也可以转换成`std::nullptr_t`类型纯右值。

## `nullptr`

[`nullptr`参考](https://zh.cppreference.com/w/cpp/language/nullptr)

`nullptr`代表指针字面量，是`std::nullptr_t`类型的纯右值。`nullptr`可以隐式转换为任何指针类型以及任何成员指针类型，也可以转换为任何空指针常量（类型为`std::nullptr_t`的值和宏`NULL`）

当`nullptr`不再是字面量时(比如由`constexpr`函数转换为字面类型(literal type))，仍然能保持空指针的含义(可以隐式转换为其他类型的空指针)，`NULL`和`0`则不行。

```cpp
#include <cstddef>
#include <iostream>

template<class T>
constexpr T clone(const T& t)
{
    return t;
}

void g(int*)
{
    std::cout << "Function g called\n";
}

int main()
{
    g(nullptr);        // Fine
    g(NULL);           // Fine
    g(0);              // Fine

    g(clone(nullptr)); // Fine
//  g(clone(NULL));    // ERROR: non-literal zero cannot be a null pointer constant
//  g(clone(0));       // ERROR: non-literal zero cannot be a null pointer constant
}
```

## `std::nullptr_t`

[参考链接](https://zh.cppreference.com/w/cpp/types/nullptr_t)

`std::nullptr_t`定义在`<stddef.h>`(如上所示)，它是空指针字面量`nullptr`的类型。它既不是指针类型也不是成员指针类型，而是一个独立类型。

如果两个重载接受不同的指针类型，则需要`std::nullptr_t`的重载来接受空指针常量。
