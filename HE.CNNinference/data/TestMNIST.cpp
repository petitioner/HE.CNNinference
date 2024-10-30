#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string input = "0,\"64,60,48\",\"69,67,55\",\"67,67,59\"";
    stringstream ss(input);

    cout << ss.str() << endl;
    cout << input << endl;


    char comma, quote;
    int n;
    ss >> n; cout << n << endl;


    ss >> comma; cout << comma << endl;
    ss >> quote; cout << quote << endl;
    ss >> n; cout << n << endl;
    ss >> comma; cout << comma << endl;
    ss >> n; cout << n << endl;
    ss >> comma; cout << comma << endl;
    ss >> n; cout << n << endl;
    ss >> quote; cout << quote << endl;
    // 检查是否到达EOF
    if (ss.eof()) {
        std::cout << "Reached the end of the stringstream." << std::endl;
    } else {
        std::cout << "Did not reach EOF." << std::endl;
    }
    ss >> comma; cout << comma << endl;
    ss >> quote; cout << quote << endl;
    ss >> n; cout << n << endl;
    ss >> comma; cout << comma << endl;
    ss >> n; cout << n << endl;
    ss >> comma; cout << comma << endl;
    ss >> n; cout << n << endl;
    ss >> quote; cout << quote << endl;
    // 检查是否到达EOF
    if (ss.eof()) {
        std::cout << "Reached the end of the stringstream." << std::endl;
    } else {
        std::cout << "Did not reach EOF." << std::endl;
    }

    ss >> comma; cout << comma << endl;
    ss >> quote; cout << quote << endl;
    ss >> n; cout << n << endl;
    ss >> comma; cout << comma << endl;
    ss >> n; cout << n << endl;
    ss >> comma; cout << comma << endl;
    ss >> n; cout << n << endl;
    ss >> quote; cout << quote << endl;

    // 检查是否到达EOF
    if (ss.eof()) {
        std::cout << "Reached the end of the stringstream." << std::endl;
    } else {
        std::cout << "Did not reach EOF." << std::endl;
    }
    ss >> comma; cout << comma << endl;
    ss >> quote; cout << quote << endl;
    ss >> n; cout << n << endl;
    ss >> comma; cout << comma << endl;
    ss >> n; cout << n << endl;
    ss >> comma; cout << comma << endl;
    ss >> n; cout << n << endl;
    ss >> quote; cout << quote << endl;

    // 检查是否到达EOF
    if (ss.eof()) {
        std::cout << "Reached the end of the stringstream." << std::endl;
    } else {
        std::cout << "Did not reach EOF." << std::endl;
    }
    ss >> comma; cout << comma << endl;
    ss >> quote; cout << quote << endl;
    ss >> n; cout << n << endl;
    ss >> comma; cout << comma << endl;
    ss >> n; cout << n << endl;
    ss >> comma; cout << comma << endl;
    ss >> n; cout << n << endl;
    ss >> quote; cout << quote << endl;
    // 检查是否到达EOF
    if (ss.eof()) {
        std::cout << "Reached the end of the stringstream." << std::endl;
    } else {
        std::cout << "Did not reach EOF." << std::endl;
    }
    ss >> comma; cout << comma << endl;
    ss >> quote; cout << quote << endl;
    ss >> n; cout << n << endl;
    ss >> comma; cout << comma << endl;
    ss >> n; cout << n << endl;
    ss >> comma; cout << comma << endl;
    ss >> n; cout << n << endl;
    ss >> quote; cout << quote << endl;
    // 检查是否到达EOF
    if (ss.eof()) {
        std::cout << "Reached the end of the stringstream." << std::endl;
    } else {
        std::cout << "Did not reach EOF." << std::endl;
    }

    ss >> comma; cout << comma << endl;
    ss >> quote; cout << quote << endl;
    ss >> n; cout << n << endl;
    ss >> comma; cout << comma << endl;
    ss >> n; cout << n << endl;
    ss >> comma; cout << comma << endl;
    ss >> n; cout << n << endl;
    ss >> quote; cout << quote << endl;

    /*

        string line, temp;
        getline(openFile, line);
        long i;
        size_t start, end;
        for(i = 0; i < line.length(); ++i) if(line[i] == ',' ) factorDim++;

        while(getline(openFile, line)){
            vector<double> vecline;
            do {
                end = line.find_first_of (',', start);
                temp = line.substr(start,end);
                vecline.push_back(atof(temp.c_str()));
                start = end + 1;
            } while(start);
            zline.push_back(vecline);
            sampleDim++;
    */
    return 0;
}
