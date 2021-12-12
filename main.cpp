#include <iostream>
#include <vector>

#include "headers/json.hpp" // We use nlohamnn's json library - https://github.com/nlohmann/json
#include "headers/main.hpp"

using namespace std;
using json = nlohmann::json;

int main(){

    TopologyAPI api;

    api.readJSON("topology.json");

    vector<json> TopList = api.queryTopologies();

    cout << TopList << endl;

    vector<json> devicesList = api.queryDevices("top1");

    cout << devicesList << endl;

    vector<json> devicesList2 = api.queryDevicesWithNetlistNode("top1", "drain");

    cout << devicesList2 << endl;

    return 0;
}