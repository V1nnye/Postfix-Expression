#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int evalPostfix(queue<char> expression){
    char aux;
    stack<int> number;
    while(!expression.empty()){
        if(isdigit(expression.front())){
            number.push(int(expression.front() - '0'));
            expression.pop();
        } else {
            int aux1, aux2;
            aux1 = number.top();
            number.pop();
            aux2 = number.top();
            number.pop();

            switch (expression.front()){
            case '+':
                number.push(aux2 + aux1);
                expression.pop();
                break;
            case '-':
                number.push(aux2 - aux1);
                expression.pop();
                break;
            case '*':
                number.push(aux2 * aux1);
                expression.pop();
                break;
            case '/':
                number.push(aux2 / aux1);
                expression.pop();
                break;
            }
        }
        
    }

    return number.top();
}

int main(){
    queue<char> queue1, queue2;
    //basic simple addition
	queue1.push('1');
	queue1.push('2');
	queue1.push('+');
	cout<<"Queue1 evaluates to "<<evalPostfix(queue1)<<endl;
	
    queue2.push('5');
	queue2.push('6');
	queue2.push('7');
	queue2.push('+');
	queue2.push('1');
	queue2.push('2');
	queue2.push('+');
	queue2.push('-');
	queue2.push('*');
	queue2.push('4');
	queue2.push('/');
	cout<<"Queue2 evaluates to "<<evalPostfix(queue2)<<std::endl;
	
    return 0;
}