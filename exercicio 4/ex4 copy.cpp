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
bool isPersonBanned(string, set<string>);
void printProjectSigns(vector<pair<string,int>>);
void countProjectSigns(vector<pair<string, int>>&, map<string,string>);

int main() {
    string input = "", project;
    map<string,string> projectSigns;
    set<string> uniqueIds, bannedIds;
    set<string>::iterator id;
    vector<pair<string, int>> projectsRank;

    getline(cin, input);
    
    while(input != "0") { // input zero ends the program
        while(input != "1") { // input one separate test cases
            if(isProject(input)) {
                project = input;
            }
            
            getline(cin, input);
            
            while(isPersonId(input)) {
                if(!isPersonBanned(input, bannedIds))
                    uniqueIds.insert(input);
                    
                getline(cin, input);
            }

            for (id = uniqueIds.begin(); id != uniqueIds.end(); id++) {
                if(projectSigns.find(*id) == projectSigns.end()) {
                    projectSigns.insert(pair<string,string>(*id, project));
                }
                // if the user is already in another project, remove him
                // and add to the banned list
                else { 
                    bannedIds.insert(*id);
                    projectSigns.erase(*id);
                }
            }
            
            uniqueIds.clear();
        }
        countProjectSigns(projectsRank, projectSigns);
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

bool isPersonBanned(string personId, set<string> bannedIds) {
    return (bannedIds.find(personId) != bannedIds.end());
}

bool sortProject(const pair<string,int> &a, const pair<string,int> &b) {
    return (a.second > b.second);
}

void countProjectSigns(vector<pair<string, int>> &projectsRank, map<string,string> projectSigns) {

}

void printProjectSigns(vector<pair<string,int>> projectsRank) {
    sort(projectsRank.begin(), projectsRank.end(), sortProject);
    int size = projectsRank.size();

    for (int i = 0; i < size; i++) {
        cout << projectsRank[i].first << " " << projectsRank[i].second << endl;
    }
    return;
}
