class ThroneInheritance {
public:
    unordered_map<string,vector<string>> mpp;
    vector<string> ini;
    unordered_set<string> names;
    string kingn;
    ThroneInheritance(string kingName) {
        ini = {};
        mpp[kingName] = ini;
        kingn = kingName;
    }
    void birth(string parentName, string childName) {
        mpp[parentName].push_back(childName);
    }
    
    void death(string name) {
        names.insert(name);
    }

    void dfs(vector<string> &inherit,string kingn){
        if(names.count(kingn)==0){inherit.push_back(kingn);}
        for(auto it:mpp[kingn]){
            dfs(inherit,it);
        }
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> inherit;
        dfs(inherit,kingn);
        return inherit;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */