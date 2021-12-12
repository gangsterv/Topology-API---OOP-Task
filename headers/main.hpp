#include <iostream>
#include <fstream>
#include <vector>

#include "json.hpp" // We use nlohamnn's json library - https://github.com/nlohmann/json

using namespace std;
using json = nlohmann::json;

class TopologyAPI{
    private:
        vector<json> tops; // This vector contains all topologies in memory
    
    public:
        bool readJSON(char filename[]){
            /**
             * @brief Takes file name as input and adds the topology into memory
             */
            ifstream topology(filename, ifstream::binary);
            json t = json::parse(topology); // Parse the json text into a json object

            tops.push_back(t); // Add the json object to the vector
            cout << "Added topology from: " << filename << " successfully" << endl;

            return true;
        }

        bool writeJSON(char id[]){
            /**
             * @brief Takes toplogy id as input and writes it into the file
             */
            
            // Iterate through the available topologies to find the one required
            for(int i=0; i<tops.size(); i++){
                if(tops[i]["id"] == id){
                    ofstream o("out_topology.json");
                    o << tops[i] << endl;
                    cout << "Write successful" << endl;
                    return true;
                }
            }

            // Reaching this point means the required topology was not found
            return false;
        }

        vector<json> queryTopologies(){
            /**
             * @brief returns the list of current topologies in memory
             */
            return tops;
        }

        bool deleteTopology(char id[]){
            /**
             * @brief Takes toplogy id as input and removes that topology from memory
             */
            
            // Iterate through the available topologies to find the one required
            for(int i=0; i<tops.size(); i++){
                if(tops[i]["id"] == id){
                    tops.erase(tops.begin()+i);
                    return true;
                }
            }

            // Reaching this point means the required topology was not found
            return false;
        }

        vector<json> queryDevices(char id[]){
            /**
             * @brief Takes toplogy id as input and returns the devices given in this topology
             */
            vector<json> devicesList;
            
            // Iterate through the available topologies to find the one required
            for(int i=0; i<tops.size(); i++){
                if(tops[i]["id"] == id){
                    for(auto el : tops[i]["components"]) // Iterate through the compnents list and add them to the devices list
                        devicesList.push_back(el);
                }
            }

            return devicesList;
        }

        vector<json> queryDevicesWithNetlistNode(char id[], char netListID[]){
            /**
             * @brief Takes toplogy id as input and returns the devices given in this topology
             */
            vector<json> devicesList;
            
            // Iterate through the available topologies to find the one required
            for(int i=0; i<tops.size(); i++){
                if(tops[i]["id"] == id){
                    for(auto el : tops[i]["components"]) // Iterate through the compnents list and add them to the devices list
                    {
                        for(auto& node : el["netlist"].items()){
                            if(node.key() == netListID)
                                devicesList.push_back(el);
                        }
                    }
                }
            }

            return devicesList;
        }

};