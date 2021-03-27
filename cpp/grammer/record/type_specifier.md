# 类型

## 类型别名

### `typedef`

`typedef`用来创建在任何位置都能替代类型名的别名。此声明中引入的每个标识符都成为`typedef`名。

自C++20起，用`typedef`声明的无名类只用于包含C-兼容的结构。

```cpp
typedef double w;         // w是double的别名
typedef double other, *p; // other是double的别名，p是double*的别名
```

复合类型的别名的cv限定与平常有所不同，即限定的为别名而不是最顶层的类型。

```cpp
typedef char *str;
const str s1 = "a"; // 等同于char *const s1;
const str *p;       // 等同于char *const *p
```

也可使用`using`进行别名声明

```cpp
using New = double*;
```

## `auto`

`auto`一般会忽略顶层`const`，可添加`const`, `&`这样的修饰符一起参与类型推导。

### `auto`用模板实参推导的规则推导类型

```cpp
auto x = expr
```

采用从函数调用进行模板实参推导的规则，从初始化器推导类型。

[待补充](https://zh.cppreference.com/w/cpp/language/auto)

### `decltype(auto)`类型为`decltype(expr)`

若占位符类型说明符为`decltype(auto)`，则推导出的类型为`decltype(expr)`，其中`expr`是初始化器。

## [`decltype`](https://zh.cppreference.com/w/cpp/language/decltype)

- `decltype(entity)`
  - 实参为**无括号**的标识表达式（标识符）或**无括号**的类成员访问表达式，则`decltype`产生以此表达式命名的实体的类型。（带括号的对象名字被当做通常的左值表达式）。
  - 用于[**结构化绑定（待补充）C++17**](https://zh.cppreference.com/w/cpp/language/structured_binding)
  - 用于[**非类型模板形参（待补充）C++20**](https://zh.cppreference.com/w/cpp/language/template_parameters#.E9.9D.9E.E7.B1.BB.E5.9E.8B.E6.A8.A1.E6.9D.BF.E5.BD.A2.E5.8F.82)
- `decltype(expr)`
  - `expr`的值类别为亡值，则`decltype`产生`T&&`
  - `expr`的值类别为左值，则`decltype`产生`T&`
  - `expr`的值类别为纯右值，则`decltype`产生`T`
