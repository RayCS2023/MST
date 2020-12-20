//
//  main.cpp
//  MST
//
//  Created by Raymond Chen on 2020-03-26.
//  Copyright © 2020 Raymond Chen. All rights reserved.
//

#include <iostream>
#include "MST.cpp"
#include "DisjointSet.cpp"

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::stoi;

int main(int argc, const char * argv[]) {
    
    MST mst;
    string line;

    while (!cin.eof()) {

        getline(cin, line);
        if(line == "")
            break;

        size_t space_index = line.find(" ");
        string command = line.substr(0,space_index);

        if(command == "n"){
            try{
                string info = line.substr(space_index+1);
                mst.init(stoi(info));
                cout << "success" << endl;
            }
            catch(illegal_argument){
                cout << "failure" << endl;
                break;
            }
        }
        else if(command == "i"){
            string info = line.substr(space_index+1);
            size_t semi_colon_1 = info.find(";");
            size_t semi_colon_2 = info.find(";", semi_colon_1 + 1);

            int u = stoi(info.substr(0, semi_colon_1));
            int v = stoi(info.substr(semi_colon_1+1,semi_colon_2-(semi_colon_1+1)));
            double w = stod(info.substr(semi_colon_2+1));

            try{
                mst.insert(u, v, w);
                cout << "success" << endl;
            }
            catch(illegal_argument){
                cout << "failure" << endl;
            }
        }
        else if(command == "d"){
            string info = line.substr(space_index+1);
            size_t semi_colon_1 = info.find(";");

            int u = stoi(info.substr(0, semi_colon_1));
            int v = stoi(info.substr(semi_colon_1+1));

            try{
                if(mst.del(u, v)){
                    cout << "success" << endl;
                }
                else{
                    cout << "failure" << endl;
                }
            }
            catch(illegal_argument){
                cout << "failure" << endl;
            }

        }
        else if(command == "degree"){
            try{
                string info = line.substr(space_index+1);
                int deg = mst.deg_vertex(stoi(info));
                cout << "degree of " << info << " is " << deg << endl;
            }
            catch(illegal_argument){
                cout << "failure" << endl;
            }
        }
        else if(command == "edge_count"){
            cout << "edge count is " << mst.edgeCount() << endl;
        }
        else if(command == "clear"){
            mst.clear();
            std::cout << "success" << endl;
        }
        else if(command == "mst"){
            double min = mst.mst();
            if(min == -1.0){
                cout << "not connected" << endl;
            }
            else{
                cout << "mst " << min << endl;
            }
        }

    }
    
    return 0;
}

