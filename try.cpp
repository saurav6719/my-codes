#include <bits/stdc++.h>
using namespace std;

// Function to trim whitespace from both ends of a string
string trim(const string &s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    if(start == string::npos || end == string::npos)
        return "";
    return s.substr(start, end - start + 1);
}

// Function to split a string by a delimiter and trim each part
vector<string> split_and_trim(const string &s, char delimiter) {
    vector<string> parts;
    string part;
    stringstream ss(s);
    while(getline(ss, part, delimiter)) {
        part = trim(part);
        if(!part.empty())
            parts.push_back(part);
    }
    return parts;
}

string key_generation(string key_mode, vector<string> roles){
    // Define all products
    vector<string> products = {"payments", "banking", "identity", "climate", "capital"};
    
    // Define permissions for each product
    map<string, vector<string>> product_permissions;
    
    // Standard permissions for all products
    vector<string> standard_read = {"read_settings", "read_intent"};
    vector<string> standard_write = {"write_settings", "create_intent", "confirm_intent"};
    
    for(auto &product : products){
        // Initialize with standard permissions
        product_permissions[product] = {};
        // Add read permissions
        for(auto &perm : standard_read){
            product_permissions[product].push_back(perm);
        }
        // Add write permissions
        for(auto &perm : standard_write){
            product_permissions[product].push_back(perm);
        }
        // Add payments specific permissions
        if(product == "payments"){
            vector<string> payments_extra_write = {"update_disputes", "create_dispute", "create_refund", "cancel_refund"};
            vector<string> payments_extra_read = {"read_refund"};
            for(auto &perm : payments_extra_write){
                product_permissions[product].push_back(perm);
            }
            for(auto &perm : payments_extra_read){
                product_permissions[product].push_back(perm);
            }
        }
    }
    
    // Define read permissions per product for admin_readonly
    map<string, vector<string>> product_read_permissions;
    for(auto &product : products){
        product_read_permissions[product] = {"read_settings", "read_intent"};
        if(product == "payments"){
            product_read_permissions[product].push_back("read_refund");
        }
    }
    
    set<string> perms;
    
    // If role includes admin, add all permissions
    if(find(roles.begin(), roles.end(), "admin") != roles.end()){
        for(auto &product : products){
            for(auto &perm : product_permissions[product]){
                perms.insert(product + "." + perm);
            }
        }
    }
    else{
        for(auto &role : roles){
            if(role == "admin_readonly"){
                // Add all read permissions
                for(auto &product : products){
                    for(auto &perm : product_read_permissions[product]){
                        perms.insert(product + "." + perm);
                    }
                }
            }
            else{
                // Assume role is a product
                if(product_permissions.find(role) != product_permissions.end()){
                    for(auto &perm : product_permissions[role]){
                        perms.insert(role + "." + perm);
                    }
                }
                // If role is not recognized, ignore it
            }
        }
    }
    
    // Collect permissions into a vector and sort them
    vector<string> perm_list(perms.begin(), perms.end());
    sort(perm_list.begin(), perm_list.end());
    
    // Concatenate with newline
    string output = "";
    for(auto &p : perm_list){
        if(!output.empty()) output += "\n";
        output += p;
    }
    
    return output;
}

int main(){
    string line;
    string key_mode = "";
    vector<string> roles;
    
    // Read input lines
    while(getline(cin, line)){
        line = trim(line);
        if(line.empty()) continue;
        // Check for key_mode
        if(line.find("key_mode") != string::npos){
            size_t pos = line.find("=");
            if(pos != string::npos){
                key_mode = trim(line.substr(pos+1));
            }
        }
        // Check for roles
        else if(line.find("roles") != string::npos){
            size_t pos = line.find("=");
            if(pos != string::npos){
                string roles_str = trim(line.substr(pos+1));
                roles = split_and_trim(roles_str, ',');
            }
        }
    }
    
    // Call key_generation
    string result = key_generation(key_mode, roles);
    cout << result << endl;
    
    return 0;
}
