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
    vector<string> products = {"banking", "capital", "climate", "identity", "payments"};
    
    // Define permissions for each product
    map<string, vector<string>> product_permissions;
    
    // Standard permissions for all products
    vector<string> standard_read = {"read_intent", "read_settings"};
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
            vector<string> payments_extra_write = {"cancel_refund", "create_dispute", "create_refund", "update_disputes"};
            vector<string> payments_extra_read = {"read_refund"};
            for(auto &perm : payments_extra_write){
                product_permissions[product].push_back(perm);
            }
            for(auto &perm : payments_extra_read){
                product_permissions[product].push_back(perm);
            }
        }
    }
    
    // Add a global dummy permission to make it 31
    // This can be used for future extensions or global access
    vector<string> global_permission = {"access"};
    product_permissions["global"] = global_permission;
    
    // Define read permissions per product for admin_readonly
    map<string, vector<string>> product_read_permissions;
    for(auto &product : products){
        product_read_permissions[product] = {"read_intent", "read_settings"};
        if(product == "payments"){
            product_read_permissions[product].push_back("read_refund");
        }
    }
    product_read_permissions["global"] = {"access"};
    
    // Define all permissions sorted alphabetically with product prefix
    vector<string> all_permissions = {
        "banking.confirm_intent",
        "banking.create_intent",
        "banking.read_intent",
        "banking.read_settings",
        "banking.write_settings",
        "capital.confirm_intent",
        "capital.create_intent",
        "capital.read_intent",
        "capital.read_settings",
        "capital.write_settings",
        "climate.confirm_intent",
        "climate.create_intent",
        "climate.read_intent",
        "climate.read_settings",
        "climate.write_settings",
        "identity.confirm_intent",
        "identity.create_intent",
        "identity.read_intent",
        "identity.read_settings",
        "identity.write_settings",
        "payments.cancel_refund",
        "payments.confirm_intent",
        "payments.create_dispute",
        "payments.create_intent",
        "payments.create_refund",
        "payments.read_intent",
        "payments.read_refund",
        "payments.read_settings",
        "payments.update_disputes",
        "payments.write_settings",
        "global.access"
    };
    
    // Ensure the permissions are sorted alphabetically
    sort(all_permissions.begin(), all_permissions.end());
    
    // Create a map from permission to its index
    map<string, int> permission_index;
    for(int i = 0; i < all_permissions.size(); ++i){
        permission_index[all_permissions[i]] = i;
    }
    
    // Initialize permission set
    set<string> perms;
    
    // If role includes admin, add all permissions
    if(find(roles.begin(), roles.end(), "admin") != roles.end()){
        for(auto &perm : all_permissions){
            perms.insert(perm);
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
                // Also add global read permissions if any
                for(auto &perm : product_read_permissions["global"]){
                    perms.insert("global." + perm);
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
    
    if(key_mode == "permissions"){
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
    else if(key_mode == "full_token"){
        // Initialize a binary string with '0's
        // Total permissions: 31
        string binary_string = "";
        for(int i = 0; i < all_permissions.size(); ++i){
            binary_string += "0";
        }
        
        // Set bits corresponding to user's permissions
        for(auto &perm : perms){
            if(permission_index.find(perm) != permission_index.end()){
                int idx = permission_index[perm];
                binary_string[idx] = '1';
            }
        }
        
        return binary_string;
    }
    else{
        // Unsupported key_mode
        return "";
    }
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
