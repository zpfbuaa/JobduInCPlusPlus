# JobduInCPlusPlus

## List
*	[题目1061：成绩排序（自定义排序)](#1061)
* 	[题目1161：Repeater (规律输出)](#1161)

## Detail

#### <font color = Green> <span id="1061">题目1061：成绩排序</span></font>

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

#### <font color = Green> <span id="1161">题目1161：Repeater</span></font>


#### LeetCode Link:<br>
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

