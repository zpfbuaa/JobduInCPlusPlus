# JobduInCPlusPlus

## List
*	[题目1019：简单计算器(栈的使用)](#1019)
*	[题目1061：成绩排序（自定义排序)](#1061)
* 	[题目1161：Repeater (规律输出)](#1161)

## Detail

#### <font color = Green> <span id="1019">题目1019：简单计算器</span></font><br>

#### Jobdu Link:<br>
[http://ac.jobdu.com/problem.php?pid=1019](http://ac.jobdu.com/problem.php?pid=1019)
#### Problem description:<br>
>读入一个只包含 +, -, *, / 的非负整数计算表达式，计算该表达式的值。
>
>输入要求: 测试输入包含若干测试用例，每个测试用例占一行，每行不超过200个字符，整数和运算符之间用一个空格分隔。没有非法表达式。当一行中只有0时输入结束，相应的结果不要输出。
>
>输出要求：对每个测试用例输出1行，即该表达式的值，精确到小数点后2位。

#### Source code:<br>

[http://www.cnblogs.com/zpfbuaa/p/6680719.html](http://www.cnblogs.com/zpfbuaa/p/6680719.html)

#### <font color = Blue size = 5> Analysis:</font>
>首先题目给出的已知信息有很多，需要认真读题。注意到一下几点：
>
>1. 读入的字符只有`+ - * /`.故考虑运算顺序时，乘法除法在前面进行计算，最后进行加法减法运算。
>2. 读入的数据肯定是非负整数<br>
>3. 整数和符号之间存在一个空格<br>
>4. 一行只有0时输出结束，相应结果不许输出。这句话有待考核，按照提交的AC代码来看，这里应该修改为`表达式的第一个非负整数等于0时结束输出`。并且只有0输入时，这个计算结果是0，但是不能把这个0输出。`其实就是第一个非负整数等于0时，结束程序`<brs>
>5. 输出结果精确到小数点后2位。故在中间运算结果保存时需要用double类型的变量。
>
>看到题目首先可以想到的思路就是可以将计算表达式转化为后缀表达式，比如1 + 2 * 3 + 4  * 5 可以转换为1 2 3 * 4 5 * + + 这样每当遇到一个运算符时可以取出最后面的两个数进行运算然后放回去（这样一看就是使用到了栈）。但是考虑到前缀表达式转为后缀表达式并不是这道题的考点，因此这种方法可行但不适用。（另外推荐参考博客[http://www.cnblogs.com/hust_wsh/archive/2013/01/01/2841657.html](http://www.cnblogs.com/hust_wsh/archive/2013/01/01/2841657.html)得到中缀表达式转为后缀表示式的具体方法）
>
>但是上面的分析并不是毫无作用的，使用栈这一点对解决该问题目是很重要的。那么怎样完成使用栈完成表达式的计算呢？由于不存在小括号或其他优先级更高的运算符，那么在计算表达式时，只要遇到*或者/，那么就可以直接拿符号前后的数字进行运算即可.但是这样我们只能解决乘法和除法问题，剩下的加法和除法在最后无法判断使用加法还是减法。但是减法也是一种加法呀，等于加上一个负数嘛，虽然题目说的都是非负整数，但是我们自己可以将其转为负数来进行计算的。
>
>因此最后我们选择使用栈来保存计算结果，逐个字符进行读入。在此需要注意的地方如下：
>
>1. 数字和字符之间以空格分隔<br>
>2. 在输入第一个非负整数以及空格后，其他的数字输入都是按照这样的组合进行输入的：`操作符+空格+非负整数+空格`。但是当这个表达式输入结束之后，最后一个就不再是空格了，组合变成了`操作符+空格+非负整数+回车`。因此可以通过判断最后一个字符进行判断表达式是否输入结束。<br>
>3. 在Xcode中遇到的问题，printf()不加'\n'时，会导致无法输出结果。具体原因和解决方法可参见博客[http://www.cnblogs.com/zpfbuaa/p/6675938.html](http://www.cnblogs.com/zpfbuaa/p/6675938.html)<br>
>4. 注意输出结果精确到小数点后两位 可采用printf("%2.lf\n",yourAns);
>
>按照上面的方法就可以完成简单的计算器了。


#### <font color = Green> <span id="1061">题目1061：成绩排序</span></font><br>

#### Jobdu Link:<br>
[http://ac.jobdu.com/problem.php?pid=1061](http://ac.jobdu.com/problem.php?pid=1061)
#### Problem description:<br>
>有N个学生的数据，每个学生的数据包括姓名、年龄、成绩。将学生数据按成绩高低排序，如果成绩相同则按姓名字符的字母序排序，如果姓名的字母序也相同则按照学生的年龄排序，并输出N个学生排序后的信息。
>

#### Source Code:<br>
[http://www.cnblogs.com/zpfbuaa/p/6671377.html](http://www.cnblogs.com/zpfbuaa/p/6671377.html)

#### <font color = Blue size = 5> Analysis:</font><br>
>学生数据的排序依次需要考虑成绩，姓名，年龄的因素。可以使用C++中STL提供的的sort函数，通过自定义的cmp函数实现自定义的学生数据排序。
>
>将学生信息按成绩进行递增排序，成绩相同的则按姓名的字母序进行递增排序，姓名相同的则按照年龄进行递增排序。
>
>因此该cmp函数可以写成:
<pre>
bool cmp(Stu a, Stu b){
    if(a.grade!=b.grade) return a.grade < b.grade;
    int result = strcmp(a.name.c_str(),b.name.c_str());
    if(result == 0) return result < 0;
    else return a.age < b.age;
}
</pre>

>由于学生数据类型不符合常用数据类型，可以创建结构体，其中包括string name, int age, int grade.
>
>最关键的就是通过STL提供的sort函数进行排序操作。代码：`sort(stu,stu+n,cmp);`

#### <font color = Green> <span id="1161">题目1161：Repeater</span></font><br>


#### Jobdu Link:<br>
[http://ac.jobdu.com/problem.php?pid=1161](http://ac.jobdu.com/problem.php?pid=1161)
#### Problem description:<br>
>给定一个模板，根据输入的迭代层数，利用模板图形输出第n次迭代后的图形。
>
>举例：
>
>给定模板如下
>
><pre># #
>  #
># #      
></pre>
>
![Level 2](http://files.cnblogs.com/files/zpfbuaa/1161_Level2.gif)
>
>Level 3 picture will be
>
>![Level 3](http://files.cnblogs.com/files/zpfbuaa/1161_Level3.gif)
#### Source code:<br>
[http://www.cnblogs.com/zpfbuaa/p/6680422.html](http://www.cnblogs.com/zpfbuaa/p/6680422.html)
#### <font color = Blue size = 5> Analysis:</font>
>
>观察规律，如何从模板得到第n层的输出。将模板看成一个n*n的矩阵。比较模板和第2次迭代之后的图形，首先第2层可以看做为n^2 * n^2 的矩阵。同样第3次迭代之后的图形可以看做n^3 * n^3 的矩阵。
>
>再次比较模板和第2次迭代的图形。我们把第二次迭代的图形化为多个n * n 的小矩阵，并且划分的最小矩阵等于模板的大小。这些n * n的小矩阵中有的矩阵和模板相同，有的是n * n的空矩阵。这些小矩阵究竟什么时候等于模板呢？什么时候等于空矩阵呢？可以发现，模板的一个位置正好对应了第二次的迭代相应位置的n * n的小矩阵。
>
>发现上述规律之后，那么第三次迭代的图形，就可以看作是模板为第二次迭代的图形。因此为了输出最后的结果，我们可以提前把每个位置的值提前保存到一个足够大的二维数组中。
>
>怎样才能得到上述保存着最后结果的二维数组呢？首先我们去看一下原题目，在原题目中给定了输出结果最长小于等于3000，因此二维数组大小可以设置了。为了不断进行迭代操作，需要记录下上次迭代的结果（作为下次迭代的模板），并且需要记录下上次迭代的模板的矩阵边长。因此需要一个大小不小于3000*3000的额外矩阵保存上次迭代结果，同时需要一个int变量保存每一次迭代后的长度。可以发现迭代k次之后边长为pow(n,k)。
>
>通过上述分析，可以利用给定的模板，以及所指定的迭代层数得到最终的结果。

