#include "stack.h"

bool isOperation(char ch){
    return ch == 'a' || ch == 'i';
}
int calculate(int firstVal, int secondVal, char operation){
    if (operation == 'i'){
        if (firstVal < secondVal)
            return firstVal;
        else
            return secondVal;
    }
    else{
        if (firstVal > secondVal)
            return firstVal;
    }
    return secondVal;
}
int task6(const std::string& input){
    stack<int> result;
    stack<char> operations;
    std::string str;
    for (int i = 0; i < input.size(); ++i){
        if (input[i] == 'm'){
            if (input[i + 1] == 'a')
                str += 'a';
            else
                str += 'i';
            i += 2;
        }
        else
            str += input[i];
    }
    for (int i = 0; i < str.size(); ++i){
        if (isOperation(str[i])){
            operations.pushBack(str[i]);
        }
        else{
            std::string temp = "";
            while (!isOperation(str[i]) && str[i] != ')' && str[i] != '(' && i != str.size() && str[i] != ','){
                temp += str[i];
                ++i;
            }
            if (temp.size() > 0)
                result.pushBack(std::stoi(temp));
        }
    }
    while (!operations.isEmpty()){
        int second = result.top();
        result.pop();
        int first = result.top();
        result.pop();
        result.pushBack(calculate(first, second, operations.top()));
        operations.pop();
    }
    return result.top();
}