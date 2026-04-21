//耗时一个多星期终于写出来了
#include <iostream>
#include <vector>
using namespace std;
//只需要一个符号数组存储符号，数据是自动生成的,不是用户输入的
//用一个check函数，检查当前和是否为0
int n;
vector<char> op;
void check()
{
    //需要三个变量,sum计算累加和，cur存储当前数，last当前数前面的符号
    int sum=0;//计算每一组数的和之前要初始化为0
    int cur=1;//cur的作用是，确定下一个数是累加到sum中还是与cur合并当前数字的前一个数字
    char last='+';//可是我为什么要初始化为加号呢,因为第一个符号前面的符号默认为加号
    //自动生成数据
    for(int i=2;i<=n;i++)//生成数据，看当前数i前面的符号，从数字2开始，2前面的符号是op[0]
    {
        if(op[i-2]==' ')//如果当前数前面的符号等于空格，则合并到cur上
            cur=cur*10+i;
        //如果不是空格，看是加号还是减号
        else
        {
            if(last=='+')//这里错了，结算的是上一个数字而不是当前数字i,看当前数字前面的符号是什么，如果是空格就合并，如果不是就看当前符号的前面的符号是什么，如果前面的符号是+号，就把前面的符号后面的数字也就是上一个数字结算
            sum+=cur;
           // sum+=cur;//cur存储的是上一个符号
        else
            sum-=cur;
        cur=i;
        last=op[i-2];
            
        }
        //因为一直在计算当前数字的上一个数字上一个符号，所以还剩下最后一个符号和符号后面的数字没计算
        //最后更新cur和last
        //输出，如果等于0就
    }//循环结束之后结算
    if(last=='+')//因为这里是用last不是用op，所以当符号为空格的时候，也会执行后面的加法
            sum+=cur;
    else
        sum-=cur;
        if(sum==0)
        {
            for(int i=0;i<n-1;i++)
            {
                cout<<i+1<<op[i];
            }
            cout<<n<<endl;
        }
}
    


void dfs(int k) {
    if (k == n - 1) {
        check();
        return;
    }
    // ASCII 顺序：空格 < '+' < '-'  递归的时候已经完成了字符串按ask码排列
    op[k] = ' ';
    dfs(k + 1);
    op[k] = '+';
    dfs(k + 1);
    op[k] = '-';
    dfs(k + 1);
}

int main() {
    cin >> n;
    op.resize(n - 1);//设置n-1个元素，且能够自动初始化为0
    dfs(0);
    return 0;
}
