#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*bool ransom_note(vector<string> magazine, vector<string> ransom) 
{
	int count = 1;

    map<string,int> magMap;

    for (int i = 0; i < magazine.size(); i++)
    {
        if(magMap.find(magazine[i]) != magMap.end())
            magMap.find(magazine[i])->second++;
        else
            magMap.insert({magazine[i], count});    
    }

    cout << "\n\nmagMap\n"; 
    for(auto& x : magMap)
        cout << x.first << " : " << x.second << endl;

    for (int i = 0; i < ransom.size(); i++)
    {
        if (magMap.find(ransom[i]) != magMap.end())
            magMap.find(ransom[i])->second--;
    }

    cout << "\n\nmagMap\n"; 
    for(auto& x : magMap)
        cout << x.first << " : " << x.second << endl;

    for(auto& x: magMap)
    {
        if (x.second < 0)
            return false;
    }

    return true;
}*/

void printMap(map<string, int> a)
{
    cout << "\n\nMap\n"; 
    for(auto& x : a)
        cout << x.first << " : " << x.second << endl;    
}

bool ransom_note(vector<string> magazine, vector<string> ransom) 
{
    map<string,int> magMap;

    for (int i = 0; i < magazine.size(); i++)
        magMap[magazine[i]]++;

    printMap(magMap);

    for (int i = 0; i < ransom.size(); i++)
        magMap[ransom[i]]--;

    printMap(magMap);

    for(auto& x: magMap)
    {
        if (x.second < 0)
            return false;
    }

    return true;
}

int main()
{
	int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }

    if(ransom_note(magazine, ransom))
        cout << "\nYes\n";
    else
        cout << "\nNo\n";

	return 0;
}