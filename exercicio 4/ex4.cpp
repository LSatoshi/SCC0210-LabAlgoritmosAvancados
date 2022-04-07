//Leandro Satoshi de Siqueira 10893103

#include <iostream>
#include <iterator>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <ctype.h>

using namespace std;

bool isPersonId(string);
bool isProject(string);
void printProjectSigns(vector<pair<string,int>>);
void rankProjectSigns(vector<pair<string, int>>&, map<string,set<string>>);

int main() {
    string input = "", project;
    map<string,set<string>> projectSigns;
    set<string> uniqueIds;
    map<string,string> idStatus;

    set<string>::iterator id;
    map<string,string>::iterator usedId;

    vector<pair<string, int>> projectsRank;

    getline(cin, input);
    
    while(input != "0") { // input zero ends the program
        while(input != "1") { // input one separate test cases
            if(isProject(input)) {
                project = input;
            }
            
            getline(cin, input);
            
            while(isPersonId(input)) {
                uniqueIds.insert(input);
                    
                getline(cin, input);
            }

            projectSigns.insert(pair<string, set<string>>(project, uniqueIds));

            for (id = uniqueIds.begin(); id != uniqueIds.end(); id++) {
                usedId = idStatus.find(*id);
                if(usedId == idStatus.end()) {
                    idStatus.insert(pair<string,string>(*id, "ok"));
                }
                // if the user is already in another project, ban him
                else { 
                    usedId->second = "banned";
                }
            }
            
            uniqueIds.clear();
        }
        projectsRank = rankProjectSigns(projectSigns, idStatus);
        printProjectSigns(projectsRank);
        
        projectSigns.clear();
        bannedIds.clear();
        projectsRank.clear();
        
        getline(cin, input);
    }

    return 0;
}

bool isPersonId(string input) {
    char c = input[0];
    return islower(c);
}

bool isProject(string input) {
    char c = input[0];
    return isupper(c);
}

bool isPersonBanned(string personId, map<string,string> idStatus) {
    map<string,string>::iterator usedId;
    usedId = idStatus.find(personId);

    if(usedId->second == "banned")
        return true;
    else
        return false;
}

bool sortProject(const pair<string,int> &a, const pair<string,int> &b) {
    return (a.second > b.second);
}

vector<pair<string, int>> rankProjectSigns(map<string,set<string>> projectSigns, map<string,string> idStatus) {
    vector<pair<string, int>> projectsRank;
    int count = 0;

    sort(projectsRank.begin(), projectsRank.end(), sortProject);

    return projectsRank;
}

void printProjectSigns(vector<pair<string,int>> projectsRank) {
    int size = projectsRank.size();

    for (int i = 0; i < size; i++) {
        cout << projectsRank[i].first << " " << projectsRank[i].second << endl;
    }
    return;
}
