//Leandro Satoshi de Siqueira 10893103

#include <iostream>
#include <iterator>
#include <map>
#include <string>

using namespace std;

int main() {
    int numIps, numCommands;
    string ip, name, command;
    map<string, string> servers;
    
    cin >> numIps >> numCommands;
    
    for(int i = 0; i < numIps; i++) {
        cin >> name >> ip;
        servers.insert({ip, name});
    }
    
    for(int i = 0; i < numCommands; i++) {
        cin >> command >> ip;
        ip.pop_back();
        cout << command << " " << ip << "; #" << servers.at(ip) << endl;
    }
    
    return 0;
}
