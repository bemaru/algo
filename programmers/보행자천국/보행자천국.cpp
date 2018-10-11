// 보행자천국.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


#include <vector>

using namespace std;

int MOD = 20170805;


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
enum Direction 
{
    RIGHT,
    DOWN
};
int answer = 0;
void visit(int i, int j, int m, int n, vector<vector<int>> city_map, int direction)
{
    if (i == m - 1 && j == n - 1)
    {
        answer++;
        return;
    }

    switch (city_map[i][j]) 
    {
        case 0:
            if (i < m-1)
            {
                visit(i + 1, j, m, n, city_map, DOWN);
            }

            if (j < n-1)
            {
                visit(i, j + 1, m, n, city_map, RIGHT);
            }
            break;
        case 1:
            return;
        case 2:
            if (direction == DOWN && i < m-1)
            {
                visit(i + 1, j, m, n, city_map, DOWN);
            }

            if (direction == RIGHT && j < n-1)
            {
                visit(i, j + 1, m, n, city_map, RIGHT);
            }
            break;
    }
}

int solution(int m, int n, vector<vector<int>> city_map) {

    answer = 0;
    visit(0, 0, m, n, city_map, 0);
    return answer% MOD;
}





void main()
{
    vector<vector<int>> city_map = {
        //{0, 2, 0, 0, 0, 2},
        //{0, 0, 2, 0, 1, 0},
        //{1, 0, 0, 2, 2, 0}
        {0,0,0},
        { 0,0,0 },
        { 0,0,0 }
        
    };

    solution(3, 3, city_map);
}