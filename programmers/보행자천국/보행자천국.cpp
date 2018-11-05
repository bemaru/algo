// ������õ��.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#include <stdio.h>
#include <vector>

using namespace std;

int MOD = 20170805;


// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
enum Direction 
{
    RIGHT,
    DOWN
};


vector<vector<int> > cache;
int visit(int i, int j, int m, int n, vector<vector<int>> city_map, int direction)
{
    
    

    //if (cache[i][j] != -1) 
    //{
    //    return cache[i][j];
    //}

    int result = 0;
    if (i == m - 1 && j == n - 1)
    {
        result = 1;
    }

    switch (city_map[i][j]) 
    {
        case 0:
            if (i < m-1)
            {
                result+=visit(i + 1, j, m, n, city_map, DOWN);
            }

            if (j < n-1)
            {
                result+=visit(i, j + 1, m, n, city_map, RIGHT);
            }
            break;
        case 1:
            break;
        case 2:
            if (direction == DOWN && i < m-1)
            {
                result+=visit(i + 1, j, m, n, city_map, DOWN);
            }
            else if (direction == RIGHT && j < n - 1)
            {
                result+=visit(i, j + 1, m, n, city_map, RIGHT);
            }
            break;
    }

    if (cache[i][j] == -1) 
    {
        cache[i][j] = result;
    }
           
    
    return result;
}

int solution(int m, int n, vector<vector<int>> city_map) {

    cache.resize(m, vector<int>(n, -1));

    return visit(0, 0, m, n, city_map, 0);
}



void main()
{
    vector<vector<int>> city_map = {
        {0, 2, 0, 0, 0, 2},
        {0, 0, 2, 0, 1, 0},
        {1, 0, 0, 2, 2, 0}
        /*{0,0,0},
        {0,0,0 },
        {0,0,0 }*/
        
    };

    printf("%d\n", solution(3, 6, city_map));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf("%d ", cache[i][j]);
        }
        printf("\n");
    }

}