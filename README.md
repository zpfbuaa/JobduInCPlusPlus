# JobduInCPlusPlus

## List
*	[题目1002：Grading(简单判断)](#-题目1002grading)
*	[题目1003：A+B(带逗号的A+B)](#-题目1003ab)
*	[题目1019：简单计算器(栈的使用)](#-题目1019简单计算器)
*	[题目1040：Prime Number(第k个素数)](#-题目1040prime-number)
*	[题目1061：成绩排序（自定义排序)](#-题目1061成绩排序)
* 	[题目1078：二叉树遍历(二叉树操作)](#-题目1078二叉树遍历)
*	[题目1080：进制转换(大整数任意进制转换)](#-题目1080进制转换)
*	[题目1083：特殊乘法(求模运算符使用)](#-题目1083特殊乘法)
*	[题目1104：整除问题(大数相乘，素数问题)](#-题目1104整除问题)
* 	[题目1153：括号匹配问题(栈的使用)](#-题目1153括号匹配问题)
* 	[题目1161：Repeater (规律输出)](#-题目1161repeater)
* 	[题目1438：最小公倍数(利用最大公约数)](#-题目1438最小公倍数)
*	[题目1439：Least Common Multiple(最小公倍数)](#-题目1439least-common-multiple)
*	[题目1440：Goldbach's Conjecture(哥德巴赫猜想)](#-题目1440goldbachs-conjecture)
*	[题目1441：人见人爱 A ^ B(二分求幂)](#-题目1441人见人爱-a--b)
*	[题目1442：A sequence of numbers(数列计算)](#-题目1442a-sequence-of-numbers)


## Detail

#### <font color = Green> <span id="1002">题目1002：Grading</span></font>


#### Jobdu Link:<br>
[http://ac.jobdu.com/problem.php?pid=1002](http://ac.jobdu.com/problem.php?pid=1002)
#### Problem description:<br>
>题目背景为高考试卷批改打分制度。对于每一道题，至少需要两位评审老师进行打分，当两个老师的打分结果相差在可接受范围内，那么该题最终得分为两位老师所给分数的平均分。<br>
>当打分相差较大超过可接受范围时，需要第三位评审老师打分。<br>
>如果第三位评审老师所给分数之和其中一位老师所给分数相差在可接受范围内，则最终分数为这两位老师所给分数的平均分。<br>
>如果第三位老师所给分数和前面两位老师所给分数之差均为可接受范围内，则最终分数取三位老师所给分数的最高分。<br>
>如果第三位老师所给分数和前面两位所给分数之差均超过可接受范围，则需要第四位评审老师给出分数，最终分数为第四位老师所给分数。

#### Source code:<br>
[http://www.cnblogs.com/zpfbuaa/p/6711256.html](http://www.cnblogs.com/zpfbuaa/p/6711256.html)
#### <font color = Blue size = 5> Analysis:</font>
>原题目为英文，看懂题目就很简单了。注意使用类型为double。并要注意输出精确到小数点后一位，使用`printf("%.1lf\n",ans)`

## [Back to list](#list)

#### <font color = Green> <span id="1003">题目1003：A+B</span></font>


#### Jobdu Link:<br>
[http://ac.jobdu.com/problem.php?pid=1003](http://ac.jobdu.com/problem.php?pid=1003)
#### Problem description:<br>
>给定两个整数A和B，其表示形式是：从个位开始，每三位数用逗号","隔开。<br>
>现在请计算A+B的结果，并以正常形式输出。
>输入要求：输入包含多组数据数据，每组数据占一行，由两个整数A和B组成（-10^9 < A,B < 10^9）。<br>
>输出要求：请计算A+B的结果，并以正常形式输出，每组数据加换行。<br>

#### Source code:<br>
[http://www.cnblogs.com/zpfbuaa/p/6711267.html](http://www.cnblogs.com/zpfbuaa/p/6711267.html)
#### <font color = Blue size = 5> Analysis:</font>
>两个整数带逗号，因此数据可使用char数组保存。之后需要将char数组保存的数据转为相对于的int类型的数字。转换方法有很多，下面给出一种：<br>
>求出char数组中保存数据的长度len，然后设置一个保存最终转换结果的int型变量并且初始化为0.除此之外设置一个记录当前数字长度的变量，用于倒序读取char数组，不断更新最终结果。然后还需要一个变量进行对转换的数字标记是正数还是负数，可以使用bool变量.
>核心代码见下：
><pre>
>int lena = (int)strlen(a);
>int size1 = 0;
>int num1 = 0;
>bool flag1 = (a[0]>='0'&&a[0]<='9') ? true : false;//默认0也是正数了！
>for(int i = lena -1 ; i >= 0 ; i--){
>    if(a[i]>='0' && a[i]<='9'){
>        num1+=(a[i]-'0')*pow(10,size1);
>        size1++;
>    }
>}
></pre>
>
>通过上述转换，可以得到最后的结果，然后根据A和B的符号进行相应的加法和减法操作即可。
><pre>
>if(flag1&&flag2) printf("%d\n",num1+num2);
>else if(flag1 && !flag2) printf("%d\n",num1-num2);
>else if(flag2 && !flag1) printf("%d\n",num2-num1);
>else if(!flag1 && !flag2) printf("%d\n",0-num1-num2);
></pre>

## [Back to list](#list)

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

## [Back to list](#list)

#### <font color = Green> <span id="1040">题目1040：Prime Number</span></font>


#### Jobdu Link:<br>
[http://ac.jobdu.com/problem.php?pid=1040](http://ac.jobdu.com/problem.php?pid=1040)
#### Problem description:<br>
>Output the k-th prime number. 输出第k个素数<br>
>输入要求：多组数据，并且输入的k满足: k≤10000<br>
>输出要求：输出第k个素数,每组数据加换行<br>

#### Source code:<br>
[http://www.cnblogs.com/zpfbuaa/p/6701522.html](http://www.cnblogs.com/zpfbuaa/p/6701522.html)
#### <font color = Blue size = 5> Analysis:</font>
>素数判断可以使用求模运算符进行判断，其中核心代码如下所示：
><pre>
>bool isPrime(long long  n){
>    if(n <= 1) return false;
>    long long  x = sqrt(n)+1;
>    for(long long  i = 2 ; i <= x ; i ++){
>        if(0 == n % i) return false;
>    }
>    return true;
>}
></pre><br>
>另外的一种方法就是素数标记法，利用倍数关系将所有满足倍数关系的数字标记为非素数。
><pre>
>void init(){
>    memset(prime,1,sizeof(prime));
>    prime[0] = false;
>    prime[1] = false;  
>    int x = sqrt(max_size) + 1 ;
>    for(int i = 2; i < x ; i++){
>        if(prime[i] == true ){
>            for(int j = i + i ; j < max_size ; j += i)
>                prime[j] = false ;
>        }
>    }
>}
</pre><br>
>进行素数表的初始化之后，进行循环遍历，并利用计数器记录当前是第几个素数，如果满足等于输入的k，那么停止遍历，输出当前的素数并换行。

## [Back to list](#list)

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

## [Back to list](#list)

#### <font color = Green> <span id="1078">题目1078：二叉树遍历</span></font>


#### Jobdu Link:<br>
[http://ac.jobdu.com/problem.php?pid=1078](http://ac.jobdu.com/problem.php?pid=1078)
#### Problem description:<br>
>给定一棵二叉树的前序遍历和中序遍历，求其后序遍历（提示：给定前序遍历与中序遍历能够唯一确定后序遍历）。
>
>输入要求：输入样例可能有多组，每组数据输入两个字符串，其长度n均小于等于26。第一行为前序遍历，第二行为中序遍历。二叉树中的结点名称以大写字母表示：A，B，C....最多26个结点。
>
>输出要求：对于每组测试样例，输出一行，为后序遍历的字符串。


#### Source code:<br>
[http://www.cnblogs.com/zpfbuaa/p/6684057.html](http://www.cnblogs.com/zpfbuaa/p/6684057.html)
#### <font color = Blue size = 5> Analysis:</font>
>二叉树的前序、中序、后序遍历的定义：<br>
>前序遍历：对任一子树，先访问跟，然后遍历其左子树，最后遍历其右子树；<br>
>中序遍历：对任一子树，先遍历其左子树，然后访问根，最后遍历其右子树；<br>
>后序遍历：对任一子树，先遍历其左子树，然后遍历其右子树，最后访问根。<br>
>根据前序遍历可以得到每层子树的根结点。然后再去中序遍历中定位这个根结点的位置。在中序遍历中，位于根结点左边的均为左子树上的结点，位于根节点右边的均为右子树上的结点。这样每次查找都可以将其分为两棵子树，接下来分别对这两颗子树进行上述操作。进行下一次定位根节点时，需要更新查找的起止位置，同样也要注意更新每棵子树的范围（通过点位根节点来实现划分两颗子树）。
>
>举例说明：<br>
>前序遍历为FDXEAG，中序遍历为XDEFAG。首先从前序遍历得到根节点，前序遍历第一个元素为F，因此F是整棵树的根节点，接下来从中序遍历定位根节点F。中序遍历中在在根节点前面的元素为XDE，后面的为AG。因此左子树包含的结点有XDE,右子树包含的结点有AG。
>
>当前状态为下图所示：<br>
>![二叉树遍历](http://files.cnblogs.com/files/zpfbuaa/1078_%E4%BA%8C%E5%8F%89%E6%A0%91%E9%81%8D%E5%8E%86_1.gif)
>确定左子树前序遍历结果为DXE,左子树中序遍历结果为XDE。<br>
>得到D为该子树的根，X为该子树的左结点，E为该子树的右结点
>
>确定右子树前序遍历结果为AG,右子树中序遍历结果为AG。
>得到A为该子树的根，该子树左结点为空，G为该子树的右结点
>构造出该树如下图所示：<br>
>![二叉树遍历](http://files.cnblogs.com/files/zpfbuaa/1078_%E4%BA%8C%E5%8F%89%E6%A0%91%E9%81%8D%E5%8E%86_2.gif)
>
>按照上述思路，解决由前序遍历和中序遍历得到后序遍历。

## [Back to list](#list)

#### <font color = Green> <span id="1080">题目1080：进制转换</span></font>


#### Jobdu Link:<br>
[http://ac.jobdu.com/problem.php?pid=1080](http://ac.jobdu.com/problem.php?pid=1080)
#### Problem description:<br>
>将M进制的数X转换为N进制的数输出。
>
>输入要求：输入的第一行包括两个整数：M和N(2<=M,N<=36)。<br>
>下面的一行输入一个数X，X是M进制的数，现在要求你将M进制的数X转换成N进制的数输出。<br>
>输出要求：输出X的N进制表示的数。<br>
>Tips: 输入时字母部分为大写，输出时为小写，并且有大数据。

#### Source code:<br>

[http://www.cnblogs.com/zpfbuaa/p/6691038.html](http://www.cnblogs.com/zpfbuaa/p/6691038.html)

#### <font color = Blue size = 5> Analysis:</font>
>如果仅仅是简单的进制转换，那么可以采用从起始进制转为10进制然后再转为目标进制。但是题目要求是大数据因此将数据存储在long long中也是不可行的。因此需要使用到数组，那么数组的话就需要实现从起始进制直接转换至目标进制。
>
>参考博客[http://blog.csdn.net/jaster_wisdom/article/details/52107785](http://blog.csdn.net/jaster_wisdom/article/details/52107785)讲的很详细，里面讲解了如何实现任意进制的转换过程。里面每一次进行的计算，都会让前面的位逐渐变为0，并且直到最后的求和为0时结束循环。实现的功能就是直接将每一位直接转为相应的目标进制。
>
>下面摘出重要的分析：<br>
>![](http://files.cnblogs.com/files/zpfbuaa/1080_%E8%BF%9B%E5%88%B6%E8%BD%AC%E6%8D%A2.gif)<br>
>data[]数组里面保存的是 待转化的数，因为这里数比较大，不能直接除以2，求模。要一步一步算。首先是第一位1除以2，余数是0，模是1，然后考虑第二个数，注意第二个数的值应该是前一个数与2取模之后得到的1再乘以10，再加上2，即12。然后循环下去，当到了最后一个数的时候，将余数1保存到output数组里面去。这只是第一次相除，因为余数061728394不等于0，所以还要继续循环，模拟除以2的过程，直到各个位都为0，即sum(保存各个位的和)＝ 0，最终的结果就是output数组的倒序输出。
>

## [Back to list](#list)

#### <font color = Green> <span id="1083">题目1083：特殊乘法</span></font>

#### Jobdu Link:<br>
[http://ac.jobdu.com/problem.php?pid=1083](http://ac.jobdu.com/problem.php?pid=1083)
#### Problem description:<br>
>写个算法，对2个小于1000000000的输入，求结果。<br>
>特殊乘法举例：123 * 45 = 1 * 4 + 1 * 5 + 2 * 4 + 2 * 5 + 3 * 4 + 3 * 5 <br>
>输入要求： 两个小于1000000000的数<br>
>输出要求： 输入可能有多组数据，对于每一组数据，输出Input中的两个数按照题目要求的方法进行运算后得到的结果

#### Source code:<br>
[http://www.cnblogs.com/zpfbuaa/p/6686469.html](http://www.cnblogs.com/zpfbuaa/p/6686469.html)
#### <font color = Blue size = 5> Analysis:</font>
>按照保存输入数据的类型，可以用一下两种不同方法。<br>
>第一种使用int保存输入，然后可以利用求模运算符%得到每一位的值，并将其保存在int数组中。所输入的两个int类型的数据，均进行上述操作。最后使用循环将每一位都经行相乘并将每次结果相加之后得到最后的答案。这里分析了一下由于不超过1,000,000,000 因此考虑极端情况的话，这个最终结果也不会超过int的范围。
>
>第二种使用char数组保存，然后循环相乘每一位即可。相乘时只需要让该位的值减去'0'即可。<br>
>
>这里觉得第二种方法对于负数好像没有办法使用哎，不知道大家注意到了没有。可以尝试一下在OJ上提交第二种方法的代码。

## [Back to list](#list)


#### <font color = Green> <span id="1104">题目1104：整除问题</span></font>


#### Jobdu Link:<br>
[http://ac.jobdu.com/problem.php?pid=1104](http://ac.jobdu.com/problem.php?pid=1104)
#### Problem description:<br>
>给定n，a求最大的k，使n！可以被`a^k`整除但不能被`a^(k+1)`整除。<br>
>输入要求:两个整数n(2<=n<=1000)，a(2<=a<=1000)<br>
>输出要求:一个整数<br>

#### Source code:<br>
[http://www.cnblogs.com/zpfbuaa/p/6706831.html](http://www.cnblogs.com/zpfbuaa/p/6706831.html)
#### <font color = Blue size = 5> Analysis:</font>
>考虑到`n!`和`a^k`运算结果可能会overflow，所以不能用求余数判断是否能够整除。<br>
>如果不能使用求余数判断是否整除，那么需要考虑其他的方法。<br>
>如果a能整除b即`(b%a==0)`，那么可以将a进行质因数分解a = x1^e1 * x2^e2 * x3^e3 ... * xn^en,同时将b进行质因数分解。那么b一定包含a中所有的质因数，并且b中的每一个质因数的指数大于等于a中的相应指数。<br>
>e(i)>=e'(i)k => k <= e(i)/e'(i)。要使所有的i使不等式都成立，只需求出最小的k即可。<br>
![](http://files.cnblogs.com/files/zpfbuaa/1140_%E6%95%B4%E6%95%B0%E9%97%AE%E9%A2%98_1.gif)<br>
![](http://files.cnblogs.com/files/zpfbuaa/1140_%E6%95%B4%E9%99%A4%E9%97%AE%E9%A2%98_2.gif)<br>
![](http://files.cnblogs.com/files/zpfbuaa/1140_%E6%95%B4%E9%99%A4%E9%97%AE%E9%A2%98_3.gif)<br>
>接下来就是对a和n!进行质因数分解工作。<br>
>试着考虑n！中含有素因数p。n!中包含了从1到n内所有整数的乘积。每个p的倍数（包括p本身）都对n！至少贡献了一个p因子。<br>
>1到n中p的倍数的个数是n/p个！！<br>
>所以贡献一个p因子的整数的个数至少为n/p。<br>
>那么贡献2个p因子，就至少为n/p*p，3个p因子为n/p^3。。。。。。<br>
>对于2个p因子，原本应该算幂指数加2的，但是因为前面被一个p因子的已经计算过了一次，所以加1即可。其余多因子的也一样。<br>
>这样就能计算出n！的各素因数的幂。<br>

## [Back to list](#list)

#### <font color = Green> <span id="1153">题目1153：括号匹配问题</span></font>

#### Jobdu Link:<br>
[http://ac.jobdu.com/problem.php?pid=1153](http://ac.jobdu.com/problem.php?pid=1153)
#### Problem description:<br>
>在某个字符串（长度不超过100）中有左括号、右括号和大小写字母；规定（与常见的算数式子一样）任何一个左括号都从内到外与在它右边且距离最近的右括号匹配。写一个程序，找到无法匹配的左括号和右括号，输出原来字符串，并在下一行标出不能匹配的括号。不能匹配的左括号用 "$"标注,不能匹配的右括号用"?"标注.
>
>输入要求：输入包括多组数据，每组数据一行，包含一个字符串，只包含左右括号和大小写字母，字符串长度不超过100。
>
>输出要求：对每组输出数据，输出两行，第一行包含原始输入字符，第二行由"$","?"和空格组成，"$"和"?"表示与之对应的左括号和右括号不能匹配。
>

#### Source code:<br>
[http://www.cnblogs.com/zpfbuaa/p/6683106.html](http://www.cnblogs.com/zpfbuaa/p/6683106.html)
#### <font color = Blue size = 5> Analysis:</font>
>括号匹配问题，使用栈来解决。题目要求不匹配位置的括号输出对应的字符。其中当左括号不匹配时，输出'$'，右括号不匹配时输出'?'。因此不仅仅是之前的判断括号匹配是否合法，而是需要记录下不匹配位置，用于结果的输出。
>
>之前用Java写过一次，当时的做法是用两个栈，一个用于保存左括号不匹配的下标，另一个保存右括号不匹配的下标。并且在输出的时候，不是简单的判断，因为左括号不匹配以及右括号不匹配时输出的字符不相同。判断过程相对较为复杂。借助了两个list，每次输出都要判断是否存在于对应的list中，存在于左括号的list时，则输出字符为'$',存在于右括号时输出字符为'?'
>
>可以看出这样做很复杂，原因是将左括号和右括号区分太明显了，甚至为了保存其不匹配位置各自申请了一个栈。那么可以换一种思路，之前是保存下来了不匹配的位置，现在可以换做保存左括号和右括号匹配的位置，或者在其匹配的位置上做标记。
>
>通过上述分析，我们可以将通过一个栈以及一个数组完成上述问题。栈依旧用来判断括号匹配，并且保存着当前左括号的位置，另外的一个数组足够大，对应着输入字符串的每个位置。初始化这个flag数组为0，在括号匹配过程中，如果一个左括号和右括号匹配，那么我们可以修改对应左括号位置和右括号位置的数值，来标记出已经匹配的括号的位置。这个标记只发生在遇到一个右括号并且保存左括号位置的栈不为空时，才能够通过循环的变量i以及栈顶元素stack.top()，分别得到右括号匹配位置以及左括号匹配位置。因为都是匹配位置，所以只是两者的共同点。
>
>在输出最终结果时，需要判断遇到的字符：<br>
>1.	如果遇到是左括号'('，那么进一步判断该位置是否标记为已经匹配，如果匹配则输出空格' '，如果不匹配则输出'$'.<br>
>2.	如果遇到是右括号')'，那么进一步判断该位置是否标记为已经匹配，如果匹配则输出空格' '，如果不匹配则输出'?'.<br>
>3. 其他字符军输出空格' ' <br>

## [Back to list](#list)

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

## [Back to list](#list)

#### <font color = Green> <span id="1438">题目1438：最小公倍数</span></font>


#### Jobdu Link:<br>
[http://ac.jobdu.com/problem.php?pid=1438](http://ac.jobdu.com/problem.php?pid=1438)
#### Problem description:<br>
>给定两个正整数，计算这两个数的最小公倍数。
>
>输入要求：输入包含多组测试数据，每组只有一行，包括两个不大于1000的正整数。
>
>输出要求：对于每个测试用例，给出这两个数的最小公倍数，每个实例输出一行。


#### Source code:<br>
[http://www.cnblogs.com/zpfbuaa/p/6691681.html](http://www.cnblogs.com/zpfbuaa/p/6691681.html)
#### <font color = Blue size = 5> Analysis:</font>
>求两个数的最小公倍数按照平常笔算的话，应该是利用短除法，短除法就不说怎么做了。最小公倍数就输乘一圈，最大公约数只乘一竖。利用最大公约数得到最小公倍数即`a*b/gcd(a,b)`<br>
>这里说明一点当求解两个数的最大公约数时，可能遇到下面三种情况：<br>
>1.	两个数都是0，没有最大公约数<br>
>2.	其中一个为0，则最大公约数为不为0的那个数<br>
>3.	两个数均不为0，则使用自调用b->a  a%b->b 即求解`gcd(a,b) = gcd(b,a%b)`<br>
>证明见下图：<br>
>![](http://files.cnblogs.com/files/zpfbuaa/1438_最大公约数_1.gif)<br>
>![](http://files.cnblogs.com/files/zpfbuaa/1438_最大公约数_2.gif)<br>

## [Back to list](#list)

#### <font color = Green> <span id="1439">题目1439：Least Common Multiple</span></font>


#### Jobdu Link:<br>
[http://ac.jobdu.com/problem.php?pid=1439](http://ac.jobdu.com/problem.php?pid=1439)
#### Problem description:<br>
>求m个正数的最小公倍数。
>
>输入要求：第一行输入n，表示共有n组数据。接下来的的n行，每一行的第一个数字m表示一共之后输入m个正数，求这m个正数的最小公倍数。所有数字位于32位整数范围内。
>
>输出要求：每组数据输出最小公倍数，带换行。

#### Source code:<br>
[http://www.cnblogs.com/zpfbuaa/p/6691393.html](http://www.cnblogs.com/zpfbuaa/p/6691393.html)
#### <font color = Blue size = 5> Analysis:</font>
>先看两个正数的最小公倍数的求解过程。通过求出两个数的最大公倍数`gcd(a,b)`。然后通过`a*b/gcd(a,b)`即可得到a和b的最小公倍数。<br>
>但是考虑到题目中的数据可能会超过存储范围，因此可以先计算除法然后再计算乘法即`a/gcd(a,b)*b`<br>
>本题目可以采用输入域求解同时进行，也就是每输入一个数字就进行一次最小公倍数的求解。由于题目描述的不明确，没有采用数组存储所有的输入之后进行遍历的求解方法，反倒是激发自己选择占用空间更小的方法来完成本题目。题目只是说明了所有的数字都在32位整数范围内，但是如果申请如此大的空间来保存输入是不切实际的，同样题目所测试的数据量也不会那么大。但是由于不清楚具体测试数据量的大小，还是采用变输入变求解的方法比较稳。

## [Back to list](#list)

#### <font color = Green> <span id="1440">题目1440：Goldbach's Conjecture</span></font>


#### Jobdu Link:<br>
[http://ac.jobdu.com/problem.php?pid=1440]
#### Problem description:<br>
>一个大于等于4的合数可以拆分为两个素数之和。当然这道题不是让我们去证明这个猜想的。只要求找出一个合数，一共有多少中不同的拆分方式，满足合数n=素数a+素数b。其中组合(a,b)和组合(b,a)是同一种组合。<br>
>输入要求：多组数据，输入一个大于等于4并且不超过2^15的数，当输入0时结束。<br>
>输出要求：输出对应的组合总数。每组数据加换行。

#### Source code:<br>
[http://www.cnblogs.com/zpfbuaa/p/6701440.html](http://www.cnblogs.com/zpfbuaa/p/6701440.html)
#### <font color = Blue size = 5> Analysis:</font>
>合数也就是所谓的偶数，但是这里大于等于4，因此2不再这个范围内。哥德巴赫猜想，一个大于等于4的合数总可以拆分为两个素数之和。因此需要额外的函数进行素数的判断。<br>
>要求出所有的组合，只需要从小打到进行遍历即可，并且由于组合(a,b)和组合(b,a)是同一种组合，因此在遍历过程中，不需要从头遍历至尾。只需要遍历所给合数的一半即可。同时遍历初始化的i并不是2,因为2是偶数，所给的合数大于等于4因此最小i应该从3开始。<br>
>除上述之外,循环遍历的步长不是1，而是2。因为是从3开始，3是一个素数，每次加2一定跳过了偶数部分，可以减判断次数，防止超时。<br>

## [Back to list](#list)

#### <font color = Green> <span id="1441">题目1441：人见人爱 A ^ B</span></font>


#### Jobdu Link:<br>
[http://ac.jobdu.com/problem.php?pid=1441](http://ac.jobdu.com/problem.php?pid=1441)
#### Problem description:<br>
>求A^B的最后三位数表示的整数。说明：A^B的含义是“A的B次方”<br>
>输入要求:输入数据包含多个测试实例，每个实例占一行，由两个正整数A和B组成（1<=A,B<=10000），如果A=0, B=0，则表示输入数据的结束，不做处理。<br>
>输出要求:对于每个测试实例，请输出A^B的最后三位表示的整数，每个输出占一行。<br>


#### Source code:<br>
[http://www.cnblogs.com/zpfbuaa/p/6715390.html](http://www.cnblogs.com/zpfbuaa/p/6715390.html)
#### <font color = Blue size = 5> Analysis:</font>
><pre>
>可能使用for循环的求幂方法：
>int ans = 1;
>for (int i = 1;i <= b;i ++) {
>    ans *= a; 
>}
></pre><br>
>但是对于本题目中A，B的取值范围为[1,10000]。首先数据结果甚至已经超过了保存范围，其次循环次数较大.<br>
>在介绍二分求幂之前看一个简单的例子。如何求2^32？按照上面的for循环需要循环32次，但是注意到在循环到16次时，已经得到了ans = 2^16结果，那么此时的ans * ans 就可以得到2^32。相类似的在得到2^16之前，可以得到2^8，2^4,2^2,2。从而将循环次数从32次降低到了6次（2->2^2->2^4->2^8->2^16->2^32). （注意32的2进制为10000)<br>
>也许上面的例子有点特殊，那么换一个再看一次，求3^10? 3^10 = 3^8 * 3^2 (注意10的二进制为1010)<br>
>再换一个呢，3^15? 3^15 = 3^8 * 3^4 * 3^2 * 3^1(注意15的二进制为1111)<br>
>找到规律了，也就是按照b的二进制逐位进行求解，其实就是将b= 2^k1 + 2^k2 + 2^k3 +...+2^kn <br>
>然后a^b = a^(2^k1 + 2^k2 + 2^k3 +...+2^kn)<br>
>其中k1,k2,k3,kn的关系就是对应着b的二进制所代表的权重。<br>
>因此只要计算出最小的k1那么不断更新当前权重即可。<br>
>本题目只要求输出最终结果的最后三位代表的整数，因此计算过程中也只保存最后三位即可。核心代码如下：
><pre>
>while(b!=0){//二进制转换结束条件b==0
>    if(b%2==1){//b的二进制当前位为1
>        ans = ans * a;
>        ans%=1000;
>     }
>     b/=2;
>     a = a * a;
>     a%=1000;
>}
></pre>
## [Back to list](#list)

#### <font color = Green> <span id="1442">题目1442：A sequence of numbers</span></font>


#### Jobdu Link:<br>
[http://ac.jobdu.com/problem.php?pid=1442](http://ac.jobdu.com/problem.php?pid=1442)
#### Problem description:<br>
>第一行输入一个整数n，代表接下来有n组数据。<br>
>接下来的n行，每一行输入4个正数a,b,c,k.每一行为一组数据，其中a,b,c为一个非递减数列的相邻的前三个元素。并且数列要么是等差数列要么是等比数列中.<br>
>k表示要求出该数列的第k个元素。<br>
>对于每组数据输出一行，取出第k个元素的值。每组数据加换行。<brs>
>输入数据：a,b,c取值范围为[0, 2^63)， k取值范围为(0,10^9]<br>
>输出要求： K-th number module (%) 200907.
#### Source code:<br>
[http://www.cnblogs.com/zpfbuaa/p/6715544.html](http://www.cnblogs.com/zpfbuaa/p/6715544.html)
#### <font color = Blue size = 5> Analysis:</font>
>等差数列通项公式:`an = a1 + (n-1)*d`<br>
>等比数列通项公式:`an = a1 * q^(n-1)` <br>
>由于数据较大，因此在数据保存中使用long long，并且最终结果要求对200907进行求模，那么在中间计算过程中可以直接进行求模操作，防止数据溢出。<br>
>对于等差数列，相邻的三个数a,b,c满足关系式 `b-a == c-b`<br>
>对于等比数列，相邻的三个数a,b,c满足关系式 `b/a == c/b`<br>
>对于本题来说，只需要判断是否为等差数列即可,减法计算所耗时间比除法要低。并且有些数列可能既是等差数列又是等比数列，这样可以将等差数列判断放在前面，如果满足就不需要再进入相对复杂的等比数列的计算。<br>
>等比数列计算通过上面的公式`an = a1 * q^(n-1)`看到可以使用二分求幂的方法，也就是`题目1441：人见人爱 A ^ B`所给出的方法。<br>
>需要注意在计算中需要对200907进行求模操作。可以通过宏定义`#define ret 200907`来简化. 

## [Back to list](#list)
