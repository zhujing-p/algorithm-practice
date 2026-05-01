#常用算法

##if(lamp1[x_new][y_new])
                lamp1[x_new][y_new]=0;
            else
                lamp1[x_new][y_new]=1;
   ## 可简化为：  用一个-号或者是异或 ^    相异为1
  如果1-为1就赋值为0，如果和1相异为1就赋值为1
                如果1-为0，就说明值为1，则赋值为0，如果和1相异0，就说明是1，赋值为0
               #lamp1[x_new][y_new]^=1;
               #或者是
               #lamp1[x_new][y_new]=1-lamp1[x_new][y_new];

#int x[5]={0,-1,1,0,0};
    int y[5]={0,0,0,-1,1};
    //遍历四个方位，当前位置是0就变成1，是1就变成0
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
        {
            int x_new=a+x[i];
            int y_new=b+y[i];
            lamp1[x_new][y_new]^=1;
        }
    

##这样的话就变成遍历25个方向了，在同一行不停地进行左右移动
#实际上只需要一个i就可以了，不需要多一个j
 for(int i=0;i<5;i++)
        {
            int x_new=a+x[i];
            int y_new=b+y[i];
            lamp1[x_new][y_new]^=1;
        }
        一个i同时控制行列变化，一个i对应一个移动方向



#移动之前要检查一下边界
 for(int i=0;i<5;i++)
        {
            int x_new=a+x[i];
            int y_new=b+y[i];
            lamp1[x_new][y_new]^=1;
        }
##//新得到的x,y坐标可能越界，先检查一下
        if(x_new<3&&x_new>=0&&y_new<3&&y_new>=0)
            lamp1[x_new][y_new]^=1;
##应该每按一次就+1，每press就++


###        
for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            {
                if(!lamp1[i][j])//如果当前元素是0，就按键，改变上下左右的元素
            {
            press(i+1,j);
            count++;
            }
            }
        //检查最后一行
        if(!(lamp1[2][0]&&lamp1[2][1]&&lamp1[2][2]))//只要有一个0，就下一层循环，否则return
            break;
        else
            return;


#//要存储三行三列的元素,定义一个二维数组
    int lamp[3][3];
    //建立一个副本
    int lamp1[3][3];
      for(int k=0;k<8;k++)
    {
        count=0;
        int temp=k;
        //把当前组合提取出来，用来决定第二行的数
        lamp1[0][2]=temp&1;
        lamp1[0][1]=temp>>1&1;
        lamp1[0][0]=temp>>2&1;//与运算，&的左右操作数都是1才是1
        //遍历3行
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            {
                if(!lamp1[i][j])//如果当前元素是0，就按键，改变上下左右的元素
                    press(i+1,j);
    修改：每次第一行换一个组合的时候，后两行的应该是没有被修改过的输入的矩阵，而不是被上一行修改过的矩阵
    每次循环的时候，应该在开头把后两行复制为原来的序列

##if(!(lamp1[2][0]&&lamp1[2][1]&&lamp1[2][2]))//只要有一个0，就下一层循环，否则return
            break;
        else
            return;
##后面本来也没有代码了，根本不需要break，直接如果找到就不要继续循环了，直接输出结果
然后return
    
       

        
    
        
               


                



