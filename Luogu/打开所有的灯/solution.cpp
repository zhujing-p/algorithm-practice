#include<iostream>
#include<algorithm>
using namespace std;
//要存储三行三列的元素,定义一个二维数组
    int lamp[3][3];
    //建立一个副本
   int lamp1[3][3];
int minstep=100;//应该初始化一个很大的数
void press(int a,int b)
{
    //改变当前元素上下左右位置上的元素，0变成1,1变成0,2个方位
    //在矩阵里面向上走是-1,0    向下走是1,0   左   0，-1  右 0,1
    int x[5]={0,-1,1,0,0};
    int y[5]={0,0,0,-1,1};
    //遍历四个方位，当前位置是0就变成1，是1就变成0
    for(int i=0;i<5;i++)
        {
        
            int x_new=a+x[i];
            int y_new=b+y[i];
        //新得到的x,y坐标可能越界，先检查一下
        if(x_new<3&&x_new>=0&&y_new<3&&y_new>=0)
            lamp1[x_new][y_new]^=1;
        }
}
int main()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            cin>>lamp[i][j];
        }

    //只遍历第一行的8种可能
    //用三位数的二进制数表示这八种可能
    int count;
    for(int k=0;k<8;k++)
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            {
                lamp1[i][j]=lamp[i][j];
            }
        count=0;
        int temp=k;
        //把当前组合提取出来，用来决定第二行的数
        //与运算，&的左右操作数都是1才是1


        //移动2位，把第一列数移到最右边&1
        if(temp>>2&1)
        {
            press(0,0);//按第几列第几行的元素
            count++;
        }
        if(temp>>1&1)
        {
            press(0,1);//按第几列第几行的元素
            count++;
        }
        if(temp&1)
        {
            press(0,2);//按第几列第几行的元素
            count++;
        }
        
        //遍历2行
        for(int i=0;i<2;i++)
            for(int j=0;j<3;j++)
            {
                if(!lamp1[i][j])//如果当前元素是0，就按键，改变上下左右的元素
                    
                {
                    press(i+1,j);
                count++;//每按一次就累加一次
                }
                
            }
        //检查最后一行
        if((lamp1[2][0]&&lamp1[2][1]&&lamp1[2][2]))//如果都是1，就保存这种第一行按法的步数，最后找到步数中最小的
        {
            minstep=min(minstep,count);
            continue;//开始下一个第一行按法
        }
        
    }
    cout<<minstep<<endl;
    return 0;
    
        
}

//终于成功了，我的心在颤抖
