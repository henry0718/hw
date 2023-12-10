#include <stdio.h>

void inspect(int i, int j, int current_color, int chess[8][8], int temp_chess[8][8], int temp_x, int temp_y)
{
    if (chess[i][j]==0)
    {
        for (int dx = -1; dx < 2; dx++)
        {
            for (int dy = -1; dy < 2; dy++)
            {
                temp_x = i + dx;
                temp_y = j + dy;
                if (current_color==1)   //如果是黑子
                {
                    while (1)
                    {
                        if (chess[i+dx][j+dy]==2)   //判斷是否有一直線的白子
                        {
                            temp_x = temp_x + dx;
                            temp_y = temp_y + dy;

                            if (chess[temp_x][temp_y]==1)   //判斷一直線白子的最後是否有黑子
                            {
                                temp_chess[i][j] = 1;
                                break;
                            }
                           
                            else if (chess[temp_x][temp_y]==0)
                            {
                                break;    
                            }
                            
                        }

                        else
                        {
                            break;
                        }
                        
                    }
                    
                }
                if (current_color==2)   //如果是白子
                {
                    while (1)
                    {
                        if (chess[i+dx][j+dy]==1)   //判斷是否有一直線的黑子
                        {
                            temp_x = temp_x + dx;
                            temp_y = temp_y + dy;

                            if (chess[temp_x][temp_y]==2)   //判斷一直線黑子的最後是否有白子
                            {
                                temp_chess[i][j] = 1;
                                break;
                            }

                            else if (chess[temp_x][temp_y]==0)
                            {
                                break;    
                            }
                            
                        }

                        else
                        {
                            break;
                        }
                    }

                }

            }
            
        }
        
    }
}


int main()
{
    int i,j,current_color;
    int chess[8][8] = {0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,
                    0,0,0,2,1,0,0,0,
                    0,0,0,1,2,0,0,0,
                    0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0};
    int temp_chess[8][8] = {0};
    int temp_x,temp_y;
    current_color = 1;   // 0:empty 1:black 2:white
    
    for ( i = 0; i < 8; i++)
    {
        for ( j = 0; j < 8; j++)
        {
            inspect( i, j, current_color, chess, temp_chess, temp_x, temp_y);
        }
        
    }
    if (current_color==1)   //如果是下黑子
    {
        printf("黑子所有可下的位置:\n");
        for ( i = 0; i < 9; i++)
        {
            for ( j = 0; j < 9; j++)
            {
                if (temp_chess[i][j]==1)
                {
                    printf("(%d,%d) ",i,j);
                }
            }
        }
    }
    if (current_color==2)   //如果是下白子
    {
        printf("白子所有可下的位置:\n");
        for ( i = 0; i < 9; i++)
        {
            for ( j = 0; j < 9; j++)
            {
                if (temp_chess[i][j]==1)
                {
                    printf("(%d,%d) ",i,j);
                }
            }
        }
    }

    return 0;
}
