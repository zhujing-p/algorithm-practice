#include<iostream>
#include<vector>
using namespace std;
int n;
int total=0;
vector<int> col,diag1,diag2,pos;

void dfs(int row)
{

 //如果第n-1行已经找完了，则输出
        if(row==n)
        {
            total++;
            if(total<=3)
            {
                for(auto x:pos)
                {
                    cout<<x+1<<' ';
                    //图中列是1开头的
                }
            cout<<'\n';
            }
            //回到上一行，取消上一行的col，换一列看行不行
            return;
        }
        
    //遍历n列
    for(int i=0;i<n;i++)//如果遍历完了所有列还没有找到，则会自动回到上一层dfs
    {
        //看当前列是否满足三个条件
        if(col[i]||diag1[row-i+n-1]||diag2[row+i])//只要有一个是1，即只要有一个在同一列，同一个主或副对角线，就不行，看下一列
            continue;
        else
        {
            col[i]=1;
            diag1[row-i+n-1]=1;//一个差值代表一个对角线,下标只规定了0-2n-2
            diag2[row+i]=1;
            pos[row]=i;
            //找下一行的列
            dfs(row+1);
            //回来后取消当前列
            col[i]=0;
            diag1[row-i+n-1]=0;
            diag2[row+i]=0;
        }
        
    }
    
}
int main()
{
    cin>>n;
    //用resize初始化数组空间
    col.resize(n);
    diag1.resize(2*n-1);
    diag2.resize(2*n-1);
    pos.resize(n);
    //从第一行开始选row=0;
    dfs(0);
    cout<<total<<endl;
    return 0;
    
}
