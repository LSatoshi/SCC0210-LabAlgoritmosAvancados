//Leandro Satoshi de Siqueira 10893103

#include <iostream>
#include <iterator>
#include <queue>

#define PRIORITY first
#define POSITION second

using namespace std;

int main() {
    int numCases, numJobs, myPosition, jobPriority;
    int waitTime = 1;
    
    cin >> numCases;

    for(int i = 0; i < numCases; i++) {
        waitTime = 1;
        queue<pair<int,int>> queue;
        priority_queue<int> pQueue;

        cin >> numJobs >> myPosition;

        for(int jobPosition = 0; jobPosition < numJobs; jobPosition++) {
            cin >> jobPriority;
            
            queue.push({jobPriority, jobPosition});
            pQueue.push(jobPriority);
        }
		
        while(!pQueue.empty()) {
            if(queue.front().PRIORITY == pQueue.top()) {
                if(queue.front().POSITION == myPosition) {
                    cout << waitTime << endl;
                    break;
                }else {
                    waitTime++; 
                    pQueue.pop();
                    queue.pop();
                }
            }else {
               pair<int,int> p = queue.front();
               queue.pop();
               queue.push(p);
            }
        }
    }

    return 0;
}
