#include<iostream>
#include<queue>
using namespace std;



int main() {
    queue<int> myQueue;

    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);


    cout << "Queue contents:" << endl;
    while (!myQueue.empty())
    {
        cout << myQueue.front() << endl;
        myQueue.pop();
    }
}
