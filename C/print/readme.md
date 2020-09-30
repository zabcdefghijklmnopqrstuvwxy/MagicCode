# 描述
这段代码打印出什么东西？（提示：和“have fun无关”）。

# 解析

首先看一段代码: 

```#include<stdio.h>   
int main()   
{   
    int a[5]={1,2,3,4,5};   
    printf("%d\n",3[a]);   
    return 0;   
}```


在C语言中，其实数组的引用可以3[a]这样的形式的，等价于a[3]。再看下面一段代码: 

```#include   
int main()   
{   
    int a[5]={1,2,3,4,5},i=4;   
    printf("%d\n",3[a]);   
    printf("%d\n",i[a]);   
    return 0;   
} ```
 
这样的表示也是可以的。i[a]实际上相当于a[4]了。再看下面一段代码: 
```#include   
int main()   
{   
    printf("%d\n",unix);   
    return 0;   
}```  

为什么我没有定义unix也能打印出来呢？ 原因是unix被编译器内定为一个宏。相当于#define unix 1 这样打印出来1。下面来解释一下这个问题. 
```#include   
int main()   
{   
    printf("%c\n",(unix)["have"]);   
    return 0;   
}```
   
这里的unix相当于1 ，那么unix["have"]相当于 "have"[1] 我们都知道"have"是个字符数组。那么 "have"[1]就相当于引用这个"have"数组下标为1的字符了，实际上就是a;：
```#include   
int main()   
{   
    printf("0x%x",'a');   
    return 0;   
}```

a的asc码的16进制表示为0x61。(unix)["have"]+"fun"-0x60就相当于0x61-0x60+"fun"相当于 0x01+"fun" ，相当于字符指针后移并指向"un"了 。这样后面的部分解释完了。
```#include   
int main()   
{   
    printf(&unix["\021ix\012\0"]);   
    return 0;   
}```   

我们首先把%s去掉。%s实际上是刚刚讲过的"un"的格式。我们知道unix宏的值 是1，那么
`printf(&unix["\021ix\012\0"]);`  

相当于
`printf(&1["\021ix\012\0"]);`  

根据上贴我说的 1["have"]这个形式，同理能得到：
`printf(&"\021ix\012\0"[1]);`  

这个形式了。这个引用和上面的有所区别区别在于&。那么一个字符数组从它的下标为1 的元素取地址就可以得到一个字符串指针。还原回去相当于
`printf(&"\021%six\012\0"[1],"un");`
  
也就是说把第一个元素跳过去了把\021跳了过去。相当于：
`printf("%six\012\0","un")`  

\012 是asc码里的回车。这个串相当于：
`printf("%six\n\0","un");`  

至此 这个问题解决了...