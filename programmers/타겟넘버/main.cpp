#include <string>
#include <vector>
#include <map>

using namespace std;

int cnt;

/*
�׽�Ʈ 1 ��	��� (154.31ms, 3.93MB)
�׽�Ʈ 2 ��	��� (154.27ms, 3.8MB)
�׽�Ʈ 3 ��	��� (0.16ms, 3.86MB)
�׽�Ʈ 4 ��	��� (0.61ms, 3.87MB)
�׽�Ʈ 5 ��	��� (5.16ms, 3.8MB)
�׽�Ʈ 6 ��	��� (0.31ms, 3.79MB)
�׽�Ʈ 7 ��	��� (0.17ms, 3.78MB)
�׽�Ʈ 8 ��	��� (1.27ms, 3.84MB)
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