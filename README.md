# Topology-API---OOP-Task
Implementation of Topology API class - OOP Task for Master Micro

# Description
This project includes an implementatin for an API that handles operations on topologies stored in JSON files. The featurs include:
- `readJSON(filename)` --> Reads json file into memory - Returns true
- `writeJSON(id)` --> Writes the json object with id "id" into "out_topology.json" - Returns true, false if the topology is not in memory
- `queryTopologies()` --> Returns a list (vector) with all the devices in the given topology
- `queryDevices(id)` --> Returns a list (vector) of devices for the given topology. Returns empty vector if topology is not in memory
- `queryDevicesWithNetlistNode(id, netListID)` --> Returns a list (vector) of devices for the given topology that have the given netlist node present. Returns empty vector if topology is not in memory

# Implementation
The code is implemented in C++. The choice for this is because it is the fastet programming language (compared to Java/Python) and it is commonly used in servers that provide APIs. It can be forked into different languages if needed.<br><br>
The API is defined in the header file "main.hpp" and it uses the JSON library created by nholmann - https://json.nlohmann.me/ <br>
A simple test was provided in the "main.cpp" file included (compiled into main.exe)<br>
The devices/topologies lists are implmented using C++ STL vectors for convenience of use.
