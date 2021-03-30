# `this`指针

`this`是一个**纯右值表达式**，值为隐式对象参数（调用类的非构造函数的成员函数时，当做它有一个额外的形参，代表调用函数所用的对象，并出现在首个实际形参之前）的地址。

```cpp
class A {
public:
  void test() {};
} a;
a.test()
```

上面的例子中通过`a`调用类`A`的成员函数`test`，其隐式对象参数为对象`a`的地址`&a`。更多例子见[`this.cpp`](../code/this/this.cpp)

## `this`的出现场景

- 非静态成员函数体中，包括成员初始化器列表
- 非静态成员函数的声明中，（可选）`cv`限定符序列之后的任何位置，比如`noexcept`说明和尾随返回类型
- [默认成员初始化器](https://en.cppreference.com/w/cpp/language/data_members#Member_initialization)

```cpp
class T {
  int a[sizeof(*this)];     // 错误：不在T的成员函数中
  int sz = sizeof(*this);   // 正确：在默认成员初始化器中
  void f() {
    int b[sizeof(*this)];   // 正确：在T的成员函数中
    struct Inner {
      int c[sizeof(*this)]; // 错误：不在Inner的成员函数中
    };
  }
};
```

## `this`的类型

- 在类`X`的成员函数中，`this`的类型是`X*`
- 如果成员函数有`cv`限定，则`this`的类型是`cv X*`

从这个角度可以很容易理解常量对象与常量成员函数之间的关系

- 常量对象调用成员函数时，传入的隐式对象参数为`const X*`，因此必须有与之匹配的`const`限定的常量成员函数，即**常量对象不能调用非常量成员函数**，因为不存在`const X*`到`X*`的隐式转换。
- 非常量对象可以调用`const`或非`const`限定的对象的成员函数

**类模板中的this(dependent expression 待补充)**

## 参考链接

[`this`指针](https://zh.cppreference.com/w/cpp/language/this)
