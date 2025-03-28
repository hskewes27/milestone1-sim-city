#include <iostream>
#include <fstream>
#include "region.hpp"
using namespace std;

int main() {
    FileHandler::read_txt_file(); // calls read config from input
    FileHandler::read_csv_file(); // calls read region layout from input
                                  // prints region and config too
    cout << "All data needed for initialization has been loaded." << endl;
    FileHandler::simrunner();
    return 0;
}
