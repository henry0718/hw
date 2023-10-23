#include <stdio.h>

int main(){
    int i,j,current_color;
    int chess[8][8]={0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,
                    0,0,0,2,1,0,0,0,
                    0,0,0,1,2,0,0,0,
                    0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0};
    int temporary_x,temporary_y;
    int count;

    count = 0;
    current_color = 1;
    scanf("%d%d",&i,&j);
    printf("(%d,%d) is %d\n",i,j,chess[i][j]);
    // 0:blank 1:black 2:white
    if (chess[i][j]==0)
    {
        for (int dx = -1; dx < 2; dx++)
        {
            for (int dy = -1; dy < 2; dy++)
            {
                temporary_x = i + dx;
                temporary_y = j + dy;
                if (current_color==1)
                {
                    while (1)
                    {
                        if (chess[i+dx][j+dy]==2)
                        {
                            temporary_x = temporary_x + dx;
                            temporary_y = temporary_y + dy;

                            if (chess[temporary_x][temporary_y]==1)
                            {
                                printf("(%d,%d) can put",i,j);
                                count = 1;
                                break;
                            }
                           
                            else if (chess[temporary_x][temporary_y]==0)
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
                if (current_color==2)
                {
                    while (1)
                    {
                        if (chess[i+dx][j+dy]==1)
                        {
                            temporary_x = temporary_x + dx;
                            temporary_y = temporary_y + dy;

                            if (chess[temporary_x][temporary_y]==2)
                            {
                                printf("(%d,%d) can put",i,j);
                                count = 1;
                                break;
                            }

                            else if (chess[temporary_x][temporary_y]==0)
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
    if (count==0)
    {
        printf("(%d,%d) can't put",i,j);
    }
    
    return 0;
}
