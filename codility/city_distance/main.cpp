#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(vector<int> &T) {

    queue<int> q;
    int size = T.size();
    vector<bool> visit(size, false);

    vector<int> firstInLevel;
    vector<bool> isFirstInLevel(size, false);

    //find capital
    int capital = -1;
    for (int i = 0; i < size; i++)
    {
        if (i == T[i])
        {
            capital = i;
        }
    }

    //make graph
    vector<vector<int>> graph(size, vector<int>());
    for (int i = 0; i < size; i++)
    {
        if (i != capital)
        {
            graph[T[i]].emplace_back(i);
        }
    }
    
    //make first in level
    int first = 0;
    if (!graph[capital].empty()) 
    {
        first = graph[capital][0];
        firstInLevel.emplace_back(first);
        isFirstInLevel[first] = true;
    }
    
    while (!graph[firstInLevel.back()].empty())
    {
        first = graph[firstInLevel.back()][0];
        firstInLevel.emplace_back(first);
        isFirstInLevel[first] = true;
    }

    // bfs
    vector<int> result(size-1,0);
    int distance = 0;

    q.push(capital);
    visit[capital] = true;

    while (!q.empty()) 
    {
        int current = q.front();
        q.pop();

        if (isFirstInLevel[current])
        {
            ++distance;
        }

        for (int next : graph[current]) 
        {
            q.push(next);
            result[distance]++;
        }
    }

    return result;
}


void main()
{
    vector<int> T = {9,1,4,9,0,4,8,9,0,1};

    for (auto i : solution(T)) 
    {
        printf("%d ", i);
    }
    printf("\n");
    

    printf("end");
}