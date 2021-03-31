# cv（const 与 volatile）类型限定符

`const`定义类型为常量，`volatile`定义类型为易变的。

对于除了函数类型或引用类型以外的任何类型 T（包括不完整类型），还有另外三个独立的类型：`const T`, `volatile T`和`const volatile T`

- `const`对象：类型为`const`限定的对象，或者`const`对象的非`mutable`子对象。此类型的对象不能修改，间接修改（比如通过非`const`类型的引用或指针修改`const`对象）会导致未定义行为。
- `volatile`对象：类型为`volatile`限定的对象，或者`volatile`对象的子对象，或者`const volatile`对象的`mutable`子对象。单线程执行过程中对`volatile`访问不能被被优化掉，也不能与另一个`volatile`访问交换次序。
- `const volatile`对象
  - `const volatile`限定的对象
  - `const volatile`对象的非`mutable`子对象
  - `volatile`对象的`const`子对象
  - `const`对象的非`mutable volatile`子对象

`mutable`说明符的作用是容许在即便包含它的对象被声明为`const`时仍可修改。C++ 语言文法把`mutable`当做存储类说明符而非类型限定符，但它**不影响存储类或连接**。

到 cv 限定类型的引用和指针能被隐式转换到更多 cv 限定的类型的引用和指针，欲将到 cv 限定类型的引用或指针转换为到更少 cv 限定类型的引用或指针，必须使用 `const_cast`

## `const`

[示例代码](../code/show_symbols/const.cpp)

```cpp
const          int gc   = 1; // LOCAL  .rodata
extern const   int gec  = 1; // GLOBAL .rodata
const volatile int gecv = 1; // GLOBAL .rodata(clang++) .data(gcc)
inline const   int gic  = 1; // 外部连接，此处符号表中未显示
extern const   int gecn;

int main() {
  const int lc = 1;
  static const int lsc = 1;  // LOCAL  .rodata
}
```

符号表中除了`main`只有五个符号，下面是`nm a.o`的输出结果

```
0000000000000004 R gec
0000000000000000 D gecv
0000000000000000 T main
0000000000000000 r _ZL2gc
0000000000000008 r _ZZ4mainE3lsc
```

- `const`变量的值一般被存放在`.rodata`(只读数据段)中，除了`const volatile`限定的非`static`变量在 gcc 中会被放到`.data`段。
- 在顶层命名空间作用域中声明的非`extern`的`const`变量（`gc`）具有**内部连接**（在C中具有外部连接），使用`extern`限定的才有外部连接。
- `extern const int gecn`是声明而非定义
- 局部`const`变量（`lc`）是无连接的，且存储期为自动存储期，不显示在符号表中
- 静态局部`const`变量具有内部连接和静态存储期

**const限定的成员和成员函数，待补充**
