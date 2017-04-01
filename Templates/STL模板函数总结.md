
## 第01篇 ACM/ICPC竞赛之STL简介
### 一、关于STL

STL大致可以分为三大类：算法(algorithm)、容器(container)、迭代器(iterator)。

STL容器是一些模板类，提供了多种组织数据的常用方法，例如vector(向量，类似于数组)、list(列表，类似于链表)、deque(双向队列)、set(集合)、map(映象)、stack(栈)、queue(队列)、priority_queue(优先队列)等，通过模板的参数我们可以指定容器中的元素类型。

STL算法是一些模板函数，提供了相当多的有用算法和操作，从简单如for_each（遍历）到复杂如stable_sort（稳定排序）。

STL迭代器是对C中的指针的一般化，用来将算法和容器联系起来。几乎所有的STL算法都是通过迭代器来存取元素序列进行工作的，而STL中的每一个容器也都定义了其本身所专有的迭代器，用以存取容器中的元素。有趣的是，普通的指针也可以像迭代器一样工作。

熟悉了STL后，你会发现，很多功能只需要用短短的几行就可以实现了。通过STL，我们可以构造出优雅而且高效的代码，甚至比你自己手工实现的代码效果还要好。

### 二、使用STL
在C++标准中，STL被组织为以下的一组头文件（注意，是没有.h后缀的！）：

algorithm / deque / functional / iterator / list / map

memory / numeric / queue / set / stack / utility / vector


## 第02篇 ACM/ICPC竞赛之STL--pair
STL的<utility>头文件中描述了一个看上去非常简单的模板类pair，用来表示一个二元组或元素对，并提供了按照字典序对元素对进行大小比较的比较运算符模板函数。

例如，想要定义一个对象表示一个平面坐标点，则可以：

```
pair<double, double> p1;
cin >> p1.first >> p1.second;
```

pair模板类需要两个参数：首元素的数据类型和尾元素的数据类型。pair模板类对象有两个成员：first和second，分别表示首元素和尾元素。

在<utility>中已经定义了pair上的六个比较运算符：<、>、<=、>=、==、!=，其规则是先比较first，first相等时再比较second，这符合大多数应用的逻辑。
当然，也可以通过重载这几个运算符来重新指定自己的比较逻辑。

除了直接定义一个pair对象外，如果需要即时生成一个pair对象，也可以调用在<utility>中定义的一个模板函数：make_pair。make_pair需要两个参数，分别为元素对的首元素和尾元素。

## 第03篇 ACM/ICPC竞赛之STL--vector
在STL的<vector>头文件中定义了vector（向量容器模板类），vector容器以连续数组的方式存储元素序列，可以将vector看作是以顺序结构实现的线性表。
当我们在程序中需要使用动态数组时，vector将会是理想的选择，vector可以在使用过程中动态地增长存储空间。

vector模板类需要两个模板参数，第一个参数是存储元素的数据类型，第二个参数是存储分配器的类型，其中第二个参数是可选的，如果不给出第二个参数，将使用默认的分配器。

#### 下面给出几个常用的定义vector向量对象的方法示例：

vector<int> s;
定义一个空的vector对象，存储的是int类型的元素。

vector<int> s(n);
定义一个含有n个int元素的vector对象。

vector<int> s(first, last);
定义一个vector对象，并从由迭代器first和last定义的序列[first, last)中复制初值。

#### vector的基本操作有：

s[i]
直接以下标方式访问容器中的元素。
s.front()
返回首元素。
s.back()
返回尾元素。
s.push_back(x)
向表尾插入元素x。
s.size()
返回表长。
s.empty()
当表空时，返回真，否则返回假。
s.pop_back()
删除表尾元素。
s.begin()
返回指向首元素的随机存取迭代器。
s.end()
返回指向尾元素的下一个位置的随机存取迭代器。
s.sort(v.begin(),v.end())
使数组排序
```
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool Comp(const int &a,const int &b) {
    return a>b;
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(3);

	Pinrt(v);//自定义输出函数

    sort(v.begin(),v.end());//默认升序
    Pinrt(v);//自定义输出函数

    sort(v.begin(),v.end(),Comp);//用降序 需要自定义一个降序函数
    Pinrt(v);//自定义输出函数
    return 0;
}
```

s.insert(it, x)
向迭代器it指向的元素前插入新元素val。
s.insert(it, n, x)
向迭代器it指向的元素前插入n个x。
s.insert(it, first, last)
将由迭代器first和last所指定的序列[first, last)插入到迭代器it指向的元素前面。
s.erase(it)
删除由迭代器it所指向的元素。
s.erase(first, last)
删除由迭代器first和last所指定的序列[first, last)。
```
vector<int>::iterator itor;  
for(itor=array.begin(); itor != array.end(); itor++) {  
    if(6 == *itor) {  
        itor = array.erase(itor);  
        itor--;  
    }  
}  
```
去除vector中值为6的数据。  
执行erase后itor会自动+1，所以需要itor--

s.reserve(n)
预分配缓冲空间，使存储空间至少可容纳n个元素。
s.resize(n)
改变序列的长度，超出的元素将会被删除，如果序列需要扩展（原空间小于n），元素默认值将填满扩展出的空间。
s.resize(n, val)
改变序列的长度，超出的元素将会被删除，如果序列需要扩展（原空间小于n），将用val填满扩展出的空间。
s.clear()
删除容器中的所有的元素。
s.swap(v)
将s与另一个vector对象v进行交换。
s.assign(first, last)
将序列替换成由迭代器first和last所指定的序列[first, last)。[first, last)不能是原序列中的一部分。
要注意的是，resize操作和clear操作都是对表的有效元素进行的操作，但并不一定会改变缓冲空间的大小。

另外，vector还有其他一些操作如反转、取反等，不再一下列举。
vector上还定义了序列之间的比较操作运算符(>, <, >=, <=, ==, !=)，可以按照字典序比较两个序列。


### 第04篇 ACM/ICPC竞赛之STL--string
字符串是程序中经常要表达和处理的数据，我们通常是采用字符数组或字符指针来表示字符串。STL为我们提供了另一种使用起来更为便捷的字符串的表达方式：string。string类的定义在头文件<string>中。

string类其实可以看作是一个字符的vector，vector上的各种操作都可以适用于string，另外，string类对象还支持字符串的拼合、转换等操作。

在尾部添加字符串或者字符：
（1）尾部添加一个字符，用“+”
```
string s;
s=s+’a’;
```
（2）尾部添加一个字符串（两种方式）
用“+”方式添加：
```
string s;
s=s+”abc”;
```
用append()方法添加：
```
string s;
s=s.append(“abc”);
```

s.erase(it, it)
s.clear（）
```
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    s = "0123456789";
    cout << s << endl;

    string::iterator it = s.begin();

    //删除s[3]
    s.erase(it+3);
    cout << s << endl;

    //删除s[1]~s[3]
    s = "0123456789";
    s.erase(it + 1,it + 4);
    cout << s << endl;

    //全部删除
    s.clear();
    cout << "clear : " << s << endl;

    return 0;
}
```
s.find()  
用find找到string里面第一个要找到元素（char或者串），找到返回数组下标，找不到返回end（）迭代器  
s.length()
求字符串长度   
s.empty()
为空返回1，不为空返回0  
s.replace(位置,长度,替换字符串)
```
string s="1234567";  
s.replace(1,4,"abc");//输出为1abc67
s.replace(1,1,"abc");//如果只执行这一条指令，输出为1abc34567
```


### 第05篇 ACM/ICPC竞赛之STL--map
在STL的头文件<map>中定义了模板类map和multimap，用有序二叉树来存贮类型为pair<const Key, T>的元素对序列。序列中的元素以const Key部分作为标识，map中所有元素的Key值都必须是唯一的，multimap则允许有重复的Key值。

map里的元素按照key的大小排序，multimap先按照key再按照value

可以将map看作是由Key标识元素的元素集合，这类容器也被称为“关联容器”，可以通过一个Key值来快速确定一个元素，因此非常适合于需要按照Key值查找元素的容器。

map模板类需要四个模板参数，第一个是键值类型，第二个是元素类型，第三个是比较算子，第四个是分配器类型。其中键值类型和元素类型是必要的。

#### map的基本操作有：

1、定义map对象，例如：  
map<string, int> m;

2、向map中插入元素对，有多种方法，例如：
```
m[key] = value;
```
[key]操作是map很有特色的操作，如果在map中存在键值为key的元素对，则返回该元素对的值域部分，否则将会创建一个键值为key的元素对，值域为默认值。所以可以用该操作向map中插入元素对或修改已经存在的元素对的值域部分。

m.insert( make_pair(key, value) );  
也可以直接调用insert方法插入元素对，insert操作会返回一个pair，当map中没有与key相匹配的键值时，其first是指向插入元素对的迭代器，其second为true；若map中已经存在与key相等的键值时，其first是指向该元素对的迭代器，second为false。

3、查找元素对，例如：
```
int i = m[key];
```
要注意的是，当与该键值相匹配的元素对不存在时，会创建键值为key的元素对。  
map<string, int>::iterator it = m.find(key);  
如果map中存在与key相匹配的键值时，find操作将返回指向该元素对的迭代器，否则，返回的迭代器等于map的end()（参见vector中提到的begin和end操作）。

4、删除元素对，例如：
m.erase(key);  
删除与指定key键值相匹配的元素对，并返回被删除的元素的个数。
m.erase(it);  
删除由迭代器it所指定的元素对，并返回指向下一个元素对的迭代器。
再看一段简单的示例代码：
```
#include <iostream>
#include <map>
using namespace std;
main() {
	map<string, int> m;
	m["one"] = 1;
	m["two"] = 2;
	// 几种不同的insert调用方法
	m.insert(make_pair("three", 3));
	m.insert(map<string, int>::value_type("four", 4));
	m.insert(pair<string, int>("five", 5));
	string key;
 	while (cin >> key) {
 		map<string, int>::iterator it = m.find(key);
 		if (it == m.end()) {
 		cout << "No such key!" << endl;
 		}
 		else {
 			cout << key << " is " << it->second << endl;
 			cout << "Erased " << m.erase(key) << endl;
 		}
	}
	return 1;
}
```
### 第06篇 ACM/ICPC竞赛之STL--set
set是用红黑树的平衡二叉索引树的数据结构来实现的，插入时，它会自动调节二叉树排列，把元素放到适合的位置，确保每个子树根节点的键值大于左子树所有的值、小于右子树所有的值，插入重复数据时会忽略。  
set迭代器采用中序遍历，检索效率高于vector、deque、list，并且会将元素按照升序的序列遍历。set容器中的数值，一经更改，set会根据新值旋转二叉树，以保证平衡，构建set就是为了快速检索（python中的set一旦建立就是一个常量，不能改的）。  
multiset，与set不同之处就是它允许有重复的键值。以及erase（key）的时候会删除multiset里面所有的key并且返回删除的个数。  

s.begin()
返回指向第一个元素的迭代器  
```
set<int>::iterator it;
```
s.clear()
清除所有元素  
s.count(key)
返回某个值元素的个数  
s.empty()
如果集合为空，返回true  
s.end()
返回指向最后一个元素的迭代器  
s.erase(iterator)
删除定位器iterator指向的值  
s.erase(iter,iter)
删除定位器first和second之间的值  
s.erase(key_value)
删除键值key_value的值  
s.find(key)
返回一个指向被查找到元素的迭代器  
s.insert()
在集合中插入元素,返回值是pair<set<int>::iterator,bool>  
s.rbegin()
返回指向集合中最后一个元素的反向迭代器  
s.rend()
返回指向集合中第一个元素的反向迭代器  
s.size()
集合中元素的数目  
s.lower_bound(key_value)
返回第一个大于等于key_value的定位器  
s.upper_bound(key_value)
返回最后一个大于等于key_value的定位器
#### 比较函数
1.如果元素不是结构体，可以编写比较函数
```
struct Comp {
    //重载()
    bool operator()(const int &a, const int &b) {
        return a > b;
    }
};
set<int, Comp> s;//初始化
```
2.元素本身就是结构体，直接把比较函数写在结构体内部
```
struct Info {
    string name;
    double score;
    //重载 <
    bool operator < (const Info &a) const {
        return a.score < score;
    }
};
set<Info> s;//初始化
```


### 第07篇 ACM/ICPC竞赛之STL--stack
stack(栈)和queue(队列)也是在程序设计中经常会用到的数据容器，STL为我们提供了方便的stack(栈)的queue(队列)的实现。
准确地说，STL 中的stack 和queue 不同于vector、list 等容器，而是对这些容器的重新包装。这里我们不去深入讨论STL 的stack 和queue 的实现细节，而是来了解一些他们的基本使用。 

stack 模板类的定义在<stack>头文件中。 
stack 模板类需要两个模板参数，一个是元素类型，一个容器类型，但只有元 素类型是必要的，在不指定容器类型时，默认的容器类型为deque。 定义stack 对象的示例代码如下：
```
stack<int> s1; 
stack<string> s2; 
```
stack 的基本操作有：  
入栈，如例：s.push(x);   
出栈，如例：s.pop();注意，出栈操作只是删除栈顶元素，并不返回该元素。  
访问栈顶，如例：s.top() 
判断栈空，如例：s.empty()，当栈空时，返回true。   
访问栈中的元素个数，如例：s.size() 

### 第08篇 ACM/ICPC竞赛之STL--queue
queue 模板类的定义在<queue>头文件中。stack 模板类很相似，queue 模板类也需要两个模板参数，一个是元素类型，一个容器类型，元素类型是必要的，容器类型是可选的，默认为deque 类型。  
定义queue对象的示例代码如下：
```
queue<int> q1;
queue<double> q2; 
```
queue 的基本操作有： 
入队，如例：q.push(x); 将x 接到队列的末端。 
出队，如例：q.pop(); 弹出队列的第一个元素，注意，并不会返回被弹出元素的值。  
访问队首元素，如例：q.front()，即最早被压入队列的元素。  
访问队尾元素，如例：q.back()，即最后被压入队列的元素。  
判断队列空，如例：q.empty()，当队列空时，返回true。 访问队列中的元素个数，如例：q.size()

### 第09篇 ACM/ICPC竞赛之STL--priority_queue
在<queue>头文件中，还定义了另一个非常有用的模类priority_queue(优先队列）。  
优先队列与队列的差别在于优先队列不是按照入队的顺序出队，而是按照队列中元素的优先权顺序出队（默认为大者优先，也可以通过指定算子来指定自己的优先顺序）。
##### 实际上默认为一个大根堆
priority_queue 模板类有三个模板参数，第一个是元素类型，第二个容器类型，第三个是比较算子。其中后两个都可以省略，默认容器为vector，默认算子为less，即小的往前排，大的往后排（出队时序列尾的元素出队）。  
STL里面默认用的是 vector. 比较方式默认用 operator< , 所以如果你把后面俩个参数缺省的话  
定义priority_queue 对象的示例代码如下： 
```
priority_queue<int> q1; 
priority_queue<pair<int, int> > q2; // 注意在两个尖括号之间一定要留空格
priority_queue<int, vector<int>, greater<int> > q3; // 定义小的先出队
```
（1）priority_queue::empty
判断队列是否为空（也即是size是否为0），是则返回true，否则返回false。优先队列的此成员函数实际上调用底层容器的同名函数。

（2）priority_queue::size
返回队列中元素的个数。此函数实际上调用底层容器的同名函数。这个函数也可以用于判断队列是否为空。

（3）priority_queue::top
返回队头元素的常引用，队头元素是在所设定的比较关系下最大也即优先级最高的元素。此函数实际上调用底层容器的front函数。

（4）priority_queue::pop
清除队头元素。

（5）priority_queue::push
给队列插入元素，新元素会按其优先级被排列到适当位置。

对pair的使用
```
#include <iostream>
#include <queue>
using namespace std;

int main() {
	 priority_queue<pair<int, int> > q2;
	 q2.push(make_pair(99, 3));
	 q2.push(make_pair(100, 4));
	 while (!q2.empty()) {
		 cout << q2.top().first << " " << q2.top().second << endl;
		 q2.pop();
	 }
	 return 0;
}
```
初学者在使用priority_queue 时，最困难的可能就是如何定义比较算子了。如果是基本数据类型，或已定义了比较运算符的类，可以直接用STL 的less算子和greater 算子——默认为使用less 算子，即小的往前排，大的先出队。
```
#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int x, y;
    Node( int a= 0, int b= 0 ):
        x(a), y(b) {}
};

struct cmp{
    bool operator() ( Node a, Node b ){
        if( a.x== b.x ) return a.y> b.y;

        return a.x> b.x; }
};

int main(){
    priority_queue<Node, vector<Node>, cmp> q;
    for(int i= 0; i< 10; ++i)
    	q.push(Node( rand(), rand() ) );
    while(!q.empty()) {
        cout << q.top().x << ' ' << q.top().y << endl;
        q.pop();
    }
    getchar();
    return 0;
}
```

### 第06篇 ACM/ICPC竞赛之STL--algorithm
<algorithm>无疑是STL中最大的一个头文件，它是由一大堆模板函数组成的。

下面列举出<algorithm>中的模板函数：

adjacent_find / binary_search / copy / copy_backward / count / count_if / equal / equal_range / fill / fill_n / find / find_end / find_first_of / find_if / for_each / generate / generate_n / includes / inplace_merge / iter_swap / lexicographical_compare / lower_bound / make_heap / max / max_element / merge / min / min_element / mismatch / next_permutation / nth_element / partial_sort / partial_sort_copy / partition / pop_heap / prev_permutation / push_heap / random_shuffle / remove / remove_copy / remove_copy_if / remove_if / replace / replace_copy / replace_copy_if / replace_if / reverse / reverse_copy / rotate / rotate_copy / search / search_n / set_difference / set_intersection / set_symmetric_difference / set_union / sort / sort_heap / stable_partition / stable_sort / swap / swap_ranges / transform / unique / unique_copy / upper_bound

如果详细叙述每一个模板函数的使用，足够写一本书的了。还是来看几个简单的示例程序吧。

示例程序之一，for_each遍历容器：
```
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Visit(int v) // 遍历算子函数
{
 cout << v << " ";
 return 1;
}

class MultInt // 定义遍历算子类
{
private:
 int factor;
public:
 MultInt(int f) : factor(f)
 {
 }
 void operator()(int &elem) const
 {
 elem *= factor;
 }
};

main()
{
 vector<int> L;
 for (int i=0; i<10; i++) L.push_back(i);
 for_each(L.begin(), L.end(), Visit);
 cout << endl;
 for_each(L.begin(), L.end(), MultInt(2));
 for_each(L.begin(), L.end(), Visit);
 cout << endl;
 return 1;
}
```

程序的输出结果为：

0 1 2 3 4 5 6 7 8 9
0 2 4 6 8 10 12 14 16 18

示例程序之二，min_element/max_element，找出容器中的最小/最大值：
```
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

main()
{
 vector<int> L;
 for (int i=0; i<10; i++) L.push_back(i);
 vector<int>::iterator min_it = min_element(L.begin(), L.end());
 vector<int>::iterator max_it = max_element(L.begin(), L.end());
 cout << "Min is " << *min_it << endl;
 cout << "Max is " << *max_it << endl;
 return 1;
}
```
程序的输出结果为：

Min is 0
Max is 9

示例程序之三，sort对容器进行排序：
```
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
main()
{
 vector<int> L;
 for (int i=0; i<5; i++) L.push_back(i);
 for (int i=9; i>=5; i--) L.push_back(i);
 Print(L);
 sort(L.begin(), L.end());
 Print(L);
 sort(L.begin(), L.end(), greater<int>()); // 按降序排序
 Print(L);//自定义输出函数
 return 1;
}
```
程序的输出结果为：

0 1 2 3 4 9 8 7 6 5
0 1 2 3 4 5 6 7 8 9
9 8 7 6 5 4 3 2 1 0

示例程序之四，copy在容器间复制元素：
```
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
main( )
{
 // 先初始化两个向量v1和v2
 vector <int> v1, v2;
 for (int i=0; i<=5; i++) v1.push_back(10*i);
 for (int i=0; i<=10; i++) v2.push_back(3*i);

 cout << "v1 = ( " ;
 for (vector <int>::iterator it=v1.begin(); it!=v1.end(); it++)
 cout << *it << " ";
 cout << ")" << endl;

 cout << "v2 = ( " ;
 for (vector <int>::iterator it=v2.begin(); it!=v2.end(); it++)
 cout << *it << " ";
 cout << ")" << endl;

 // 将v1的前三个元素复制到v2的中间
 copy(v1.begin(), v1.begin()+3, v2.begin()+4);

 cout << "v2 with v1 insert = ( " ;
 for (vector <int>::iterator it=v2.begin(); it!=v2.end(); it++)
 cout << *it << " ";
 cout << ")" << endl;

 // 在v2内部进行复制，注意参数2表示结束位置，结束位置不参与复制
 copy(v2.begin()+4, v2.begin()+7, v2.begin()+2);

 cout << "v2 with shifted insert = ( " ;
 for (vector <int>::iterator it=v2.begin(); it!=v2.end(); it++)
 cout << *it << " ";
 cout << ")" << endl;
 return 1;
}
```
程序的输出结果为：

v1 = ( 0 10 20 30 40 50 )
v2 = ( 0 3 6 9 12 15 18 21 24 27 30 )
v2 with v1 insert = ( 0 3 6 9 0 10 20 21 24 27 30 )
v2 with shifted insert = ( 0 3 0 10 20 10 20 21 24 27 30 )
