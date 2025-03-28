#ifndef filehandler_H
#define filehandler_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

namespace FileHandler {
    extern string filenamecsv = ""; // declare filename for input file for region layout
    extern string filenametxt = "";// declare function for config
    extern string config;  // declare as external
    extern int timestep;
    extern int timelimit;
    extern bool changed;
    extern vector<vector<string>> region; // declare as external
    extern vector<vector<string>> prevregion;
    void read_txt_file();  // declare the read function for config
    void read_csv_file(); // declare the read function for region layout
    void simrunner();
}

#endif
