


# 容器 - queue

> #include <queue>
>
> First In First Out
>
> **queue没有迭代器**



```
构造
queue<T> queT;			//queue采用模板类实现，queue对象的默认构造形式

queue(const queue &que);//拷贝构造函数




赋值
queue& operator=(const queue &que);	//重载等号操作符



数据存取和删除
push(elem);	//往队尾添加元素

pop();		//从队头移除第一个元素

back();		//返回最后一个元素

front();	//返回第一个元素



大小操作
empty();	//判断队列是否为空

size();		//返回队列的大小

```









# 容器 - stack

> #include <stack>
>
> First In Last Out
>
> **stack没有迭代器**


```
构造
stack<T> stkT;			//stack采用模板类实现，stack对象的默认构造形式

stack(const stack &stk);//拷贝构造函数



赋值
stack& operator=(const stack &stk);	//重载等号操作符



数据存取和删除
push(elem);	//向栈顶添加元素

pop();		//从栈顶移除第一个元素

top();		//返回栈顶元素




大小操作
empty();	//判断堆栈是否为空

size();		//返回堆栈的大小

```








# 容器 - list

> #include \<list\>
>
> 非连续线性空间
>
> List容器是一个双向循环链表
>
> List：插入操作和删除操作除了被删除的那个元素的迭代器失效，其它的迭代器都不会失效
>
> List和vector是两个最常被使用的容器



```
构造
list<T> lstT;	//list采用采用模板类实现,对象的默认构造形式

list(beg,end);	//构造函数将[beg, end)区间中的元素拷贝给本身

list(n,elem);	//构造函数将n个elem拷贝给本身

list(const list &lst);	//拷贝构造函数




赋值
assign(beg, end);	//将[beg, end)区间中的数据拷贝赋值给本身

assign(n, elem);	//将n个elem拷贝赋值给本身

list& operator=(const list &lst);//重载等号操作符

swap(lst);	//将lst与本身的元素互换



数据存取和删除
front();	//返回第一个元素
back();		//返回最后一个元素

push_back(elem);	//在容器尾部加入一个元素
pop_back();			//删除容器中最后一个元素

push_front(elem);	//在容器开头插入一个元素
pop_front();		//从容器开头移除第一个元素

insert(pos,elem);	//在pos位置插elem元素的拷贝，返回新数据的位置。
insert(pos,n,elem);	//在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。

clear();		//移除容器的所有数据

erase(pos);		//删除pos位置的数据，返回下一个数据的位置。
erase(beg,end);	//删除[beg,end)区间的数据，返回下一个数据的位置。

remove(elem);	//删除容器中所有与elem值匹配的元素。





大小操作
size();	//返回容器中元素的个数

empty();//判断容器是否为空

//重新指定容器的长度为num，
//若容器变长，则以默认值填充新位置
//若容器变短，则末尾超出容器长度的元素被删除
resize(num);

//重新指定容器的长度为num，
//若容器变长，则以默认值填充新位置
//若容器变短，则末尾超出容器长度的元素被删除
resize(num, elem);





排序
sort(); 	//list排序
reverse();	//反转链表，比如lst包含1,3,5元素，运行此方法后，lst就包含5,3,1元素





不支持随机访问
// list迭代器不支持随机访问
//list<int>::iterator it = L2.begin();
//it = it + 2;

```









# 容器 - set / multiset

> #include <set>
>
> set / multiset 容器底层是红黑树
>
> set：插入操作和删除操作除了被删除的那个元素的迭代器失效，其它的迭代器都不会失效
>
> set 不允许键值重复，multiset 允许键值重复


```
构造
set<T> st;			//set默认构造函数：

mulitset<T> mst; 	//multiset默认构造函数: 

set(const set &st);	//拷贝构造函数




赋值
set& operator=(const set &st);	  //重载等号操作符

swap(st);						//交换两个集合容器





大小操作
size();	//返回容器中元素的数目

empty();//判断容器是否为空





数据存取和删除
insert(elem);	//在容器中插入元素。

clear();		//清除所有元素

erase(elem);	//删除容器中值为elem的元素
erase(pos);		//删除pos迭代器所指的元素，返回下一个元素的迭代器
erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器


//查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
find(key);

count(key);			//查找键key的元素个数

lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。

```





# 容器 - map / multimap

> #include <map>
>
> map / multimap 容器底层是红黑树
>
> map：插入操作和删除操作除了被删除的那个元素的迭代器失效，其它的迭代器都不会失效
>
> map 不允许键值重复，multimap 允许键值重复


```
构造
map<T1, T2> mapTT;	//map默认构造函数: 

map(const map &mp);	//拷贝构造函数



赋值
map& operator=(const map &mp);	//重载等号操作符

swap(mp);					  //交换两个集合容器



大小操作
size();	//返回容器中元素的数目

empty();//判断容器是否为空



删除
clear();		//删除所有元素

erase(pos);		//删除pos迭代器所指的元素，返回下一个元素的迭代器
erase(beg,end);	//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器
erase(keyElem);	//删除容器中key为keyElem的对组




查找
//查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回map.end();
find(key);

//返回容器中key为keyElem的对组个数。对map来说，要么是0，要么是1。对multimap来说，值可能大于1
count(keyElem);

lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器
upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器
equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器




```









