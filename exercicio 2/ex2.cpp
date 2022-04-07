//Leandro Satoshi de Siqueira 10893103

#include <iostream>
#include <iterator>
#include <stack>

using namespace std;

void ReverseStack(stack<int>&);
void PrintAndClearStack(stack<int>&);

int main() {
    stack<int> stack;
    int numStacks, numElements, element;
    
    cin >> numStacks;
    
    for(int i = 0; i < numStacks; i++) {
        cin >> numElements;
        
        for(int i = 0; i < numElements; i++) {
            cin >> element;
            stack.push(element);
        }
        
        ReverseStack(stack);
        PrintAndClearStack(stack);
        
        if(i != numStacks-1) cout << endl;
    }
    
    return 0;
}


void ReverseStack(stack<int> &oldStack) {
    stack<int> newStack;
    
    while(!oldStack.empty()) {
        newStack.push(oldStack.top());
        oldStack.pop();
    }
    oldStack = newStack;
    return;
}

void PrintAndClearStack(stack<int> &stack) {
    if (stack.empty())
        return;
 
    int curElement = stack.top();
    stack.pop();
    
    PrintAndClearStack(stack);
    
    cout << curElement << endl;
}
