#include <string>
#include <vector>
#include <map>

using namespace std;

int cnt;

/*
테스트 1 〉	통과 (154.31ms, 3.93MB)
테스트 2 〉	통과 (154.27ms, 3.8MB)
테스트 3 〉	통과 (0.16ms, 3.86MB)
테스트 4 〉	통과 (0.61ms, 3.87MB)
테스트 5 〉	통과 (5.16ms, 3.8MB)
테스트 6 〉	통과 (0.31ms, 3.79MB)
테스트 7 〉	통과 (0.17ms, 3.78MB)
테스트 8 〉	통과 (1.27ms, 3.84MB)
*/
std::map<string, int> cache;

void operation(int result, string op, string ops, int i, vector<int> numbers, int target) 
{
    
    if (i >= numbers.size()) 
    {
        return;
    }

    //printf("%d %s %d\n", result, op.c_str(), numbers[i]);
    
    if (op == "+") 
    {
        result += numbers[i];
    }
    if (op == "-")
    {
        result -= numbers[i];
    }
    //ops += op;
    //cache[ops] = result;

    
    printf("%s\n", ops.c_str());
    if (i == numbers.size() - 1 && result == target)
    {
        cnt++;
        
    }

    i++;

    operation(result, "+", ops, i, numbers, target);
    operation(result, "-", ops, i, numbers, target);
}

int solution(vector<int> numbers, int target) {
    
    int result = 0;
    cnt = 0;
    string ops = "";
    operation(result, "+", ops,0, numbers, target);
    operation(result, "-", ops,0, numbers, target);


    int answer = 0;
    answer = cnt;
    return answer;
}

void main()
{
    vector<int> numbers = {1,1,1,1,1};
    int target = 3;
    printf("solution : %d\n", solution(numbers, target));
}