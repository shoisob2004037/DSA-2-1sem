#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> queueObj;

    // Push elements into the queue
    queueObj.push(5);
    queueObj.push(10);
    queueObj.push(20);

   int frontElement = queueObj.front();
        cout << frontElement << " "<<endl;

    int rearElement = queueObj.back();
        cout << rearElement << " ";

        int x;
        cout<<endl<<"enter element";
        cin>>x;
        queueObj.push(x);

    // Print the remaining elements in the queue
    cout <<endl<< "elements in the queue: ";
    while (!queueObj.empty()) {
        int frontElement = queueObj.front();
        cout << frontElement << " ";
        queueObj.pop(); // Remove the front element after printing
    }
    cout << endl;
}
