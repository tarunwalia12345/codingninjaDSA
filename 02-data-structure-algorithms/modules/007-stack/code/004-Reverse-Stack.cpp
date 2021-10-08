#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<list>

using namespace std;

/**
 *  Reverse a Stack
 *  -   You have been given two stacks that can store integers as the data. 
 *      Out of the two given stacks, one is populated and the other one is 
 *      empty. You are required to write a function that reverses the populated 
 *      stack using the one which is empty.
 * 
 *  Input Format :
 *      The first line of input contains an integer N, denoting the total 
 *      number of elements in the stack.
 *      The second line of input contains N integers separated by a single 
 *      space, representing the order in which the elements are pushed into the stack.
 *  Output Format:
 *      The only line of output prints the order in which the stack elements are 
 *      popped, all of them separated by a single space. 
 *  
 *  Constraints:
 *      1 <= N <= 10^3
 *      -2^31 <= data <= 2^31 - 1
 * 
 *  Time Limit: 1sec 
 * 
 *  Sample Input 1:
 *      6
 *      1 2 3 4 5 10
 *  Note: Here, 10 is at the top of the stack.
 *  Sample Output 1:
 *      1 2 3 4 5 10
 *  Note: Here, 1 is at the top of the stack.
 * 
 *  Sample Input 2:
 *      5
 *      2 8 15 1 10
 *  Sample Output 2:
 *      2 8 15 1 10
 */
void reverseStack(stack<int> &input, stack<int> &extra) {
	if(input.empty()){
        return;
    }
    int temp = input.top();
    input.pop();
    reverseStack(input, extra);
    while(!input.empty()){
        int t = input.top();
        input.pop();
        extra.push(t);
    }
    input.push(temp);
    while(!extra.empty()){
        int t = extra.top();
        extra.pop();
        input.push(t);
    }
}

int main(){
    stack<int> input, extra;
    int size;
    cin >> size;
    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }
    reverseStack(input, extra);
    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}