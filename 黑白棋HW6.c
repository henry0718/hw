#include <stdio.h>
#define Empty 0
#define Black 1
#define White 2

void inspect(int current_color, int chess[8][8], int temp_chess[8][8][2], int temp_x, int temp_y)
{
    int i, j;
    for ( i = 0; i < 8; i++)    //檢查棋盤可下位置和能翻轉的個數
        {
            for ( j = 0; j < 8; j++)
            {
            int count = 0;
            if (chess[i][j]==0)
            {
                for (int dx = -1; dx < 2; dx++)
                {
                    for (int dy = -1; dy < 2; dy++)
                    {
                        temp_x = i + dx;
                        temp_y = j + dy;
                        int temp_count = 0;
                        if (current_color==Black)   //如果是黑子
                        {
                            while (1)
                            {
                                if (chess[i+dx][j+dy]==White)   //判斷是否有一直線的白子
                                {
                                    temp_x = temp_x + dx;
                                    temp_y = temp_y + dy;
                                    temp_count++;
                                    if (chess[temp_x][temp_y]==Black)   //判斷一直線白子的最後是否有黑子
                                    {
                                        temp_chess[i][j][0] = 1;
                                        count = count + temp_count;
                                        break;
                                    }
                                
                                    else if (chess[temp_x][temp_y]==Empty)
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
                        if (current_color==White)   //如果是白子
                        {
                            while (1)
                            {
                                if (chess[i+dx][j+dy]==Black)   //判斷是否有一直線的黑子
                                {
                                    temp_x = temp_x + dx;
                                    temp_y = temp_y + dy;
                                    temp_count++;
                                    if (chess[temp_x][temp_y]==White)   //判斷一直線黑子的最後是否有白子
                                    {
                                        temp_chess[i][j][0] = 1;
                                        count = count + temp_count;
                                        break;
                                    }

                                    else if (chess[temp_x][temp_y]==Empty)
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
            temp_chess[i][j][1] = count;    //紀錄下那格能翻轉多少棋子
        }
    }
}

void flip(int x, int y, int i, int j, int current_color, int chess[8][8], int temp_x, int temp_y)
{
    for (int dx = -1; dx < 2; dx++)
        {
            for (int dy = -1; dy < 2; dy++)
            {
                temp_x = x + dx;
                temp_y = y + dy;
                if (current_color==Black)   //如果是黑子
                {
                    while (1)
                    {
                        if (chess[x+dx][y+dy]==White)   //判斷是否有一直線的白子
                        {
                            temp_x = temp_x + dx;
                            temp_y = temp_y + dy;
                            if (chess[temp_x][temp_y]==Black)   //判斷一直線白子的最後是否有黑子
                            {
                                while (chess[temp_x - dx][temp_y - dy] == White)    //把中間白棋翻轉成黑棋
                                {
                                    chess[temp_x - dx][temp_y - dy] = Black;
                                    temp_x = temp_x - dx;
                                    temp_y = temp_y - dy;
                                }
                                
                                break;
                            }
                           
                            else if (chess[temp_x][temp_y]==Empty)
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
                if (current_color==White)   //如果是白子
                {
                    while (1)
                    {
                        if (chess[x+dx][y+dy]==Black)   //判斷是否有一直線的黑子
                        {
                            temp_x = temp_x + dx;
                            temp_y = temp_y + dy;
                            if (chess[temp_x][temp_y]==White)   //判斷一直線黑子的最後是否有白子
                            {
                                while (chess[temp_x - dx][temp_y - dy] == Black)    //把中間黑棋翻轉成白棋
                                {
                                    chess[temp_x - dx][temp_y - dy] = White;
                                    temp_x = temp_x - dx;
                                    temp_y = temp_y - dy;
                                }

                                break;
                            }

                            else if (chess[temp_x][temp_y]==Empty)
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

void put_chess(int *current_color, int chess[8][8], int temp_chess[8][8][2], int temp_x, int temp_y)
{
    int i, j;
    int x = -1;
    int y = -1;
    if (*current_color==Black)
    {
        printf("黑棋你下\n黑子所有可下的位置:\n");
        for ( i = 0; i < 8; i++)   //印出黑子可下位置
        {
            for ( j = 0; j < 8; j++)
            {
                if (temp_chess[i][j][0]==1)
                {
                    printf("(%d,%d) ",i,j);
                }
            }
        }
        printf("請輸入落子位置 :\n");
        scanf("%d %d",&x,&y);
        chess[x][y] = Black;
        flip(x, y, i, j, *current_color, chess, temp_x, temp_y);
        *current_color = White;
    }
    else if (*current_color==White)
    {
        printf("白棋電腦下\n白子所有可下的位置:\n");
        for ( i = 0; i < 8; i++)   //印出白子可下位置
        {
            for ( j = 0; j < 8; j++)
            {
                if (temp_chess[i][j][0]==1)
                {
                    printf("(%d,%d) ",i,j);
                }
            }
        }
        printf("請輸入落子位置 :\n");
        for ( int k = 19; k > 0; k--)     //下翻轉數最多的位置
        {
            for ( i = 0; i < 8; i++)
            {
                for ( j = 0; j < 8; j++)
                {
                    if (temp_chess[i][j][1]==k)
                    {
                        x = i;
                        y = j;
                        break;
                    }
                }
                if (x!=-1)
                {
                    break;
                }
            }
        }
        printf("電腦下(%d, %d)\n",x,y);
        chess[x][y] = White;
        flip(x, y, i, j, *current_color, chess, temp_x, temp_y);
        *current_color = Black;
    }
}

void print_chessboard(int chess[8][8])
{
    int i, j;
    for ( i = 0; i < 8; i++)
        {
            for ( j = 0; j < 8; j++)
            {
                printf("%d ",chess[i][j]);
            }
            printf("\n");
        }
}

int determine(int current_color, int temp_chess[8][8][2])
{
    int count = 0;
    for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (current_color==Black && temp_chess[i][j][0]==0)
                {
                    count++;
                }
                if (current_color==White && temp_chess[i][j][0]==0)
                {
                    count++;
                }
            }
            
        }
    if (count==64)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

void win_lose(int chess[8][8])
{
    int count_black = 0;
    int count_white = 0;
    for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (chess[i][j]==Black)
                {
                    count_black++;
                }
                if (chess[i][j]==White)
                {
                    count_white++;
                }
            }
            
        }
    if (count_black>count_white)
    {
        printf("黑方勝 %d:%d", count_black, count_white);
    }
    else if (count_white>count_black)
    {
        printf("白方勝 %d:%d", count_white, count_black);
    }
    else
    {
        printf("平手");
    }
    
}

int main()
{
    int chess[8][8] = {0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,
                    0,0,0,2,1,0,0,0,
                    0,0,0,1,2,0,0,0,
                    0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0};
    int temp_x,temp_y;
    int current_color = Black;
    while (1)
    {
        int temp_chess[8][8][2] = {0};
        inspect( current_color, chess, temp_chess, temp_x, temp_y);
        if (current_color==Black && determine(current_color, temp_chess))
        {
            current_color = White;
            printf("黑棋無子可下\n");
            if (current_color==White && determine(current_color, temp_chess))
            {
                print_chessboard(chess);
                printf("棋局結束\n");
                win_lose(chess);                
                return 0;
            }
            continue;
        }
        else if (current_color==White && determine(current_color, temp_chess))
        {
            current_color = Black;
            printf("白棋無子可下\n");
            continue;
        }
        
        print_chessboard(chess);
        put_chess(&current_color, chess, temp_chess, temp_x, temp_y);
    }
    return 0;
}
