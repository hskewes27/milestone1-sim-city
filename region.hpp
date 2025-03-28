#ifndef REGION_H
#define REGION_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

namespace FileHandler {
    static string config;
    static string filenametxt;
    static string filenamecsv;
    static int timestep;
    static int timelimit;
    static vector<vector<string>> region;
    static bool changed;
    static int count;
    static bool limit;
    static vector<vector<string>> prevregion;
    inline void read_txt_file() {
        cin >> filenametxt;
        std::ifstream configfile(filenametxt);

        if (configfile.is_open()) {
            string line;
            while (getline(configfile, line)) {
                config += line + "\n";
                
                // Parse Time Limit
                if (line.find("Time Limit:") != string::npos) {
                    string time_str = line.substr(line.find(":") + 1);
                    timelimit = stoi(time_str);
                }
                
                // Parse Region Layout filename
                if (line.find("Region Layout:") != string::npos) {
                    filenamecsv = line.substr(line.find(":") + 1);
                }

                // Parse Refresh Rate
                if (line.find("Refresh Rate:") != string::npos) {
                    string rate_str = line.substr(line.find(":") + 1);
                    timestep = stoi(rate_str);
                }
            }
            configfile.close();
            cout<<"Region layout file: " << filenamecsv << endl; // each line part of config info is ripped from file
            cout<<"Config loaded. Time limit: " << timelimit << endl;
            cout<<"Refresh rate: " << timestep << endl;
        }
        else {
            cout << "file not found" << endl;
        }
    }

    inline void read_csv_file() {
        // No need to ask for filename, we got it from config
        cout << "Opening region file: " << filenamecsv << endl;
        std::ifstream regionfile(filenamecsv);

        if (regionfile.is_open()) {
            region.clear(); // Clear any existing data
            string line;
            while (getline(regionfile, line)) {
                vector<string> row;
                stringstream ss(line);
                string cell;
                while (getline(ss, cell, ',')) {
                    row.push_back(cell);
                }
                region.push_back(row);
            }
            regionfile.close();
            
            cout << "\nRegion layout:\n";
            for (const auto& row : region) {
                for (const auto& cell : row) {
                    cout << cell << " ";
                }
                cout << endl;
            }
        }
        else {
            cout << "Region file not found: " << filenamecsv << endl;
        }
    }
    inline void simrunner(){
        int count = 0;
        bool limit = true;
        changed = true;
        while(changed == true and limit == true){
            count++;
            prevregion = region;
            changed = false;
            if(count == timelimit){
                limit = false;
            }
            //after this is when the other zone functionality would be implemented
            //then I would check for changes properly
            for(int i = 0; i < region.size(); i++){
                for(int j = 0; j < region[i].size(); j++){
                    if(region[i][j] != prevregion[i][j]){
                        changed = true;
                    }
                }
                if(changed == true){
                    break;
                }
            }
            if(changed == false){
                cout << "No changes detected in this iteration. Sim loop is working." << endl;
                break;
            }
            
        
        }
    }
}

#endif

