请考虑一个由 1 到 N 的数字组成的递增数列：1,2,3,…,N。

现在请在数列中插入 + 表示加，或者 - 表示减， （空格） 表示空白（例如 1-2 3 就等于 1-23），来将每一对数字组合在一起（请不要在第一个数字前插入符号）。

计算该表达式的结果并判断其值是否为 0。 请你写一个程序找出所有产生和为零的长度为N的数列。

输入格式
单独的一行表示整数 N（3≤N≤9）。

输出格式
按照 ASCI I码的顺序，输出所有在每对数字间插入 +，-， （空格） 后能得到结果为零的数列。

输入输出样例
输入 #1复制运行

7
输出 #1复制运行

1+2-3+4-5-6+7
1+2-3-4+5+6-7
1-2 3+4+5+6+7
1-2 3-4 5+6 7
1-2+3+4-5+6-7
1-2-3-4-5+6+7





思路1

要用什么数据结构，用什么算法
要怎么把三个符号插入到n-1个位置中
伪代码：
int n;
vector<char> str_g(n);
vector<char> str_1;
vector<int> nums(n+1,0);
vector<int> nums_1(n,0);
for(int i=1;i<=n;i++)
{
    cin>>nums[i];
}
//计算
bool culculate()//计算是否为0，把符号传进去
{

    nums_1[0]=nums[1];   
    int j=0;
    for(int i=1;i<n;i++)//这样nums就是从2开始的，如果第一个数字不是空格，nums_1[0]就丢失了nums[1]第一个数字，如果是空格，nums_1[0]会被覆盖
    {
        //遍历整数数组,把要计算的数放在一个新的数组里面
        //int j=-1;j每次都被重置了
        nums_1[++j]=nums[i+1];//你现在写 nums_1[j] = i，是不是等于在自己造数字，而不是用题目给的？
        
        if(str_g[i]==' ')//对原始的两个数组进行处理，得到去掉空格之后的新数字数组和符号数组
        {
            nums_1[j]=nums[i]*10+nums[i+1];
        }
        else
            str_1.push_back(str_g[i]);
        
    }
            
            /*nums[i+1]=nums[i]*10+nums[i+1];
            //删除第i个
            erase(nums.begin()+i);
            不要修改原来的数组，把计算结果保存在一个新的数组，在一个新的数组里面计算，最好还是存档*/
            
        
    
    //对nums和str_g求和
    
    //我要怎么求和，我并不知道数字和字符下标之间的联系


    sum=nums_1[0];
    for(int i=0;i<j;i++)//这两个下标的关系是i  i+1,当有一个数组会越界的时候，取范围小的那个
        //这样nums_1从nums_1[1]开始被加进sum，所以应该在进入循环之前把nums_1[0]加进去
    {
        if(str_1[i]=='+')
            sum+=nums_1[i+1];
        if(str_1[i]=='-')
            sum-=nums_1[i+1];
    }
    if(sum==0)
    {
        for(int i=1;i<n;i++)
        {
            cout<<nums[i]<<str_g[i];
        }
        cout<<endl;
        return true;
    }
    else return false;
}
void dfs(int k)//递归的目的：建立了一个存储符号的数组，每递归一次就存储一个符号
{
    if(k==n)
    {
        if(!calculate())
            return; 
    }
    str_g[k]='+';
    dfs(k+1);
    str_g[k]='-';
    dfs(k+1);
    str_g[k]=' ';
    //空格后再加一个递归，才能形成三个符号的闭环
    dfs(k+1);
}











#修改问题
##for(int i=1;i<n;i++)
    {
        //nums_1[++j]=nums[i+1];//不要一进来就新开一个位置马上把原来的数存进去，j在什么时候++呢，只有当不是空格的时候才++,存储原来的数，如果是空格，就把现在的数也就是最后一个数乘10+i+1，放回去，不需要新开一个位置存储这个修改之后的数
        
        if(str_g[i]==' ')
        {
            nums_1[j]=nums[i]*10+nums[i+1];
        }
        else
        {
            j++;
            nums_1[i]=nums[i+1];
            str_1.push_back(str_g[i]);
        }




#修改问题
##if(str_g[i]==' ')
        {
          //  nums_1[j]=nums[i]*10+nums[i+1];
            //忽略掉如果有多个空格，应该按从左到右计算
            //如果两个空格连在一起，应该先算前面的空格，这样就得到第二个空格的左操作数
            //例如，1 2 3   计算过程应该是 （1*10+2） 3                                                    （12*10+3）
            //所以如果多个空格连在一起的话，不用单开一个存储空间，把当前的数取出来修改后再放回去，是当前数，当前数可能是上一个已经被修改过的数，继续修改
        }



#修改问题
##str_1.push_back(str_g[i]);
            //因为每一次进入Calculator str_1都是直接用push back把当前字符添加到最后一个元素的下一个位置所以每一次进入Calculator str_1的元素数量会越来越多所以str_1必须每一次进入啊这一组数据都必须先把符号清空
        }


##if(k==n-1)//第n-2层dfs的时候，继续填符号，把符号填到str_g[n-2]，然后进入下一次递归调用,第n-1次dfs递归调用，str_g[n-1]不存在，所以return上一层，换个符号




#include<iostream>
#include<vector>
//忘写命名空间
using namespace std;
int n;
vector<char> str_g;
vector<char> str_1;
vector<int> nums;//未定义n的值，还不能赋值0
vector<int> nums_1;
//计算
void calculate()//计算是否为0，把符号传进去
{

    //进来就调用clear函数清空str_1内所有元素
    str_1.clear();
    nums_1[0]=nums[1];   
    int j=0;
    for(int i=0;i<n-1;i++)
    {
        if(str_g[i]==' ')//把当前数取出来修改
        {
            nums_1[j]=nums_1[j]*10+nums[i+2];
        }
        else
        {
            j++;
            nums_1[j]=nums[i+2];
             str_1.push_back(str_g[i]);
        }
    }
     int sum=nums_1[0];
    for(int i=0;i<str_1.size();i++)
    {
        if(str_1[i]=='+')
            sum+=nums_1[i+1];
        if(str_1[i]=='-')
            sum-=nums_1[i+1];
    }
    if(sum==0)
    {
        cout<<nums_1[0];
        for(int i=0;i<str_1.size();i++)
        {
            cout<<str_1[i]<<nums_1[i+1];//新数字与新符号数组的关系也是n,n-1
        }
        cout<<endl;
    }
}
void dfs(int k)//递归的目的：建立了一个存储符号的数组，每递归一次就存储一个符号
{
    if(k==n-1)
    {
        //如果已经填满符号了，先计算，不管是否为0都要返回上一层dfs试下一个符号
        calculate();
        return;
    }
        
    str_g[k]='+';//给第k个位置存储+号
    dfs(k+1);//
    str_g[k]='-';
    dfs(k+1);
    str_g[k]=' ';
    //空格后再加一个递归，才能形成三个符号的闭环
    dfs(k+1);
}

int main()
{
    cin>>n;
    //用revize增加元素数量
    nums.resize(n+1);
    nums_1.resize(n);
    str_g.resize(n-1);
for(int i=1;i<=n;i++)
{
    cin>>nums[i];
}
    dfs(0);
    return 0;
}

