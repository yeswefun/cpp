


```
头文件: #include <string>


构造
string();					//创建一个空的字符串 例如: string str;      

string(const string& str);	 //使用一个string对象初始化另一个string对象

string(const char* s);		//使用字符串s初始化

string(int n, char c);		//使用n个字符c初始化 



赋值
string& operator=(const char* s);	//char*类型字符串 赋值给当前的字符串

string& operator=(const string &s);	//把字符串s赋给当前的字符串

string& operator=(char c);			//字符赋值给当前的字符串



string& assign(const char *s);		//把字符串s赋给当前的字符串

string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串

string& assign(const string &s);	//把字符串s赋给当前字符串

string& assign(int n, char c);		//用n个字符c赋给当前字符串

string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串



获取
char& operator[](int n);	//通过[]方式取字符

char& at(int n);			//通过at方法获取字符

// 注意：[]越界会返回该类型的默认值，()抛出out_of_range异常



查找
//查找str第一次出现位置,从pos开始查找
int find(const string& str, int pos = 0) const;

//查找s第一次出现位置,从pos开始查找
int find(const char* s, int pos = 0) const;

//从pos位置查找s的前n个字符第一次位置
int find(const char* s, int pos, int n) const;

//查找字符c第一次出现位置
int find(const char c, int pos = 0) const;



//查找str最后一次位置,从pos开始查找
int rfind(const string& str, int pos = npos) const;

//查找s最后一次出现位置,从pos开始查找
int rfind(const char* s, int pos = npos) const;

//从pos查找s的前n个字符最后一次位置
int rfind(const char* s, int pos, int n) const;

//查找字符c最后一次出现位置
int rfind(const char c, int pos = 0) const;



替换
//替换从pos开始n个字符为字符串str
string& replace(int pos, int n, const string& str);

//替换从pos开始的n个字符为字符串s
string& replace(int pos, int n, const char* s);


比较
/*
compare函数在>时返回 1，<时返回 -1，==时返回 0。
比较区分大小写，比较时参考字典顺序，排越前面的越小。
大写的A（65）比小写的a（97）小。
*/

int compare(const string &s) const;//与字符串s比较

int compare(const char *s) const;//与字符串s比较



子串
//返回由pos开始的n个字符组成的字符串
string substr(int pos = 0, int n = npos) const;



插入
string& insert(int pos, const char* s); 	//插入字符串

string& insert(int pos, const string& str); //插入字符串

string& insert(int pos, int n, char c);		//在指定位置插入n个字符c



删除
string& erase(int pos, int n = npos);		//删除从Pos开始的n个字符 
```




# 容器 - vector

> #include <vector>
>
> 动态数组，一旦引起空间的重新配置，指向原vector的所有迭代器就都失效了
>
> 连续线性空间

```
构造
vector<T> v; 				//采用模板实现类实现，默认构造函数

vector(v.begin(), v.end());	 //将v[begin(), end())区间中的元素拷贝给本身

vector(n, elem);			//构造函数将n个elem拷贝给本身

vector(const vector &vec);	//拷贝构造函数

// 上面第二个构造函数
int arr[] = {1, 2, 3, 4, 5, 6};
vector<int> v1(arr, arr + sizeof(arr) / sizeof(arr[0]));
vector<int> v2(v1.begin(), v1.end());



赋值
assign(beg, end);	//将[beg, end)区间中的数据拷贝赋值给本身。

assign(n, elem);	//将n个elem拷贝赋值给本身。

swap(vec);			//将vec与本身的元素互换。

vector& operator=(const vector  &vec);//重载等号操作符



大小操作
capacity();	//容器的容量

size();		//返回容器中元素的个数

empty();	//判断容器是否为空

//重新指定容器的长度为num，
//若容器变长，则以默认值填充新位置。
//若容器变短，则末尾超出容器长度的元素被删除。
resize(int num);

//重新指定容器的长度为num，
//若容器变长，则以elem值填充新位置。
//若容器变短，则末尾超出容器长>度的元素被删除。
resize(int num, elem);

//容器预留len个元素长度，预留位置不初始化，元素不可访问
reserve(int len);



数据存取
front();		//返回容器中第一个数据元素

back();			//返回容器中最后一个数据元素

operator[];		//返回索引idx所指的数据，越界时，linux返回默认值

at(int idx);	//返回索引idx所指的数据，如果idx越界，抛出out_of_range异常。



随机访问
// vector support 随机访问 - list not support
vector<int>::iterator it = v.begin();
it += 2;
cout << *it << endl;




插入
//尾部插入元素ele
push_back(ele);

//迭代器指向位置pos插入count个元素ele.
insert(const_iterator pos, int count,ele);



删除
//删除最后一个元素
pop_back();

//删除迭代器指向的元素
erase(const_iterator pos);

//删除迭代器从start到end之间的元素
//erase [begin, end)
//v.erase(v.begin(), v.end());
erase(const_iterator start, const_iterator end);

//删除容器中所有元素
clear();
```










# 容器 - deque

> #include <deque>
>
> 一旦引起空间的重新配置，指向原vector的所有迭代器就都失效了
>
> 连续线性空间
>
> deque容器是一个双向链表


```
Vector容器是单向开口的连续内存空间，deque则是一种双向开口的连续线性空间。
```


```
构造
deque<T> deqT;	//默认构造形式

deque(beg, end);//构造函数将[beg, end)区间中的元素拷贝给本身

deque(n, elem);//构造函数将n个elem拷贝给本身

deque(const deque &deq);//拷贝构造函数



赋值
assign(beg, end);	//将[beg, end)区间中的数据拷贝赋值给本身。

assign(n, elem);	//将n个elem拷贝赋值给本身。

swap(deq);			// 将deq与本身的元素互换

deque& operator=(const deque &deq); //重载等号操作符




大小操作
deque.size();	//返回容器中元素的个数

deque.empty();	//判断容器是否为空

//重新指定容器的长度为num,
//若容器变长，则以默认值填充新位置。
//若容器变短，则末尾超出容器长度的元素被删除。
deque.resize(num);

//重新指定容器的长度为num,
//若容器变长，则以elem值填充新位置,
//若容器变短，则末尾超出容器长度的元素被删除。
deque.resize(num, elem); 




插入/删除
push_front(elem);	//在容器头部插入一个数据
pop_front();//删除容器第一个数据


push_back(elem);	//在容器尾部添加一个数据
pop_back();	//删除容器最后一个数据


insert(pos,elem);	//在pos位置插入一个elem元素的拷贝，返回新数据的位置。
insert(pos,n,elem);	//在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。


clear();		//移除容器的所有数据
erase(pos);		//删除pos位置的数据，返回下一个数据的位置。
erase(beg,end);	//删除[beg,end)区间的数据，返回下一个数据的位置。





数据存取
front();		//返回容器中第一个数据元素

back();			//返回容器中最后一个数据元素

operator[];		//返回索引idx所指的数据，越界时，linux返回默认值

at(int idx);	//返回索引idx所指的数据，如果idx越界，抛出out_of_range异常。





```



