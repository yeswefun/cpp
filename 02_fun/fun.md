


## extern "C"

```cpp
#pragma once
  
// 在c++中调用c函数
#ifdef __cplusplus
extern "C" {
#endif

// 由于c++函数重载的原因, 函数名会被编译器更改, 调用时可能会出现找不到函数
#include <stdio.h>
void show();


#ifdef __cplusplus
}
#endif
```



```c
#include "test.h"

void show() {
    printf("hello\n");
}
```



```cpp
#include <iostream>
using namespace std;

#include "test.h"

// show函数按照c语言的方式进行链接
//extern "C" void show();

int main() {
    // g++没有以下问题
    // c++中存在函数重载，show可能会被改名为__showv而导致找不到函数
    show();
    return 0;
}
```

