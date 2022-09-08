#include "chain_hash.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

vector<pair<string, string>> loadCSV(const string& file){
    vector<pair<string, string>> data;
    fstream fin;
    fin.open(file, ios::in);
    vector<string> row;
    string line, word, temp;
    int i = 0;
    while (!fin.eof()){
        row.clear();
        getline(fin, line);
        if (i++ == 0)
            continue;
        stringstream str(line);
        while (getline(str, word, ';')){
            row.push_back(word);
        }
        if (row.size() == 2)
            data.emplace_back(row[0], row[1]);
    }
    return data;
}

template<typename KeyType, typename ValueType>
void print_hash(chain_hash<KeyType, ValueType>& hash){
    cout << "Size of Hash Table: " << hash.bucket_count() << endl;
    cout << "Number of elements: " << hash.get_size() << endl;
    for (int i=0; i < hash.bucket_count(); ++i){
        cout << "bucket #" << i << " contains " << hash.bucket_size(i) << " elements:" << endl;
        for (auto it = hash.begin(i); it != hash.end(i); ++it){
            cout << "[" << it->key << ":" << it->value << "]" << endl;
        }
    }
}

void ejemplo1(){
    vector<pair<string, string>> data = loadCSV("smalldata.csv");
    chain_hash<string, string> map;

    for (auto& [EmployeeName, JobTitle] : data){
        map[EmployeeName] = JobTitle;
    }
    cout << std::string(120, '-');
    print_hash(map);
    cout << std::string(120, '-');
    cout << "MICKELSON LORENE P: " << map.get("MICKELSON LORENE P") << endl;
    cout << std::string(120, '-');
    map.remove("MICKELSON LORENE P");
    cout << "map size: " << map.get_size() << endl;
    cout << std::string(120, '-');
    map.insert("SAMANTA", "TEACHING ASSISTANT");
    print_hash(map);
    cout << std::string(120, '-');
}

int main(){
    ejemplo1();
    return 0;
}
