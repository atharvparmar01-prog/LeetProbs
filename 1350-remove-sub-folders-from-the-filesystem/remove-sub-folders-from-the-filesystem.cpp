class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        set<string> st(folder.begin(),folder.end());

        for(auto it:folder){
            string s = it;
            string check="/";
            for(int i=1;i+1<s.size();i++){
                check+=s[i];
                if(s[i+1]=='/'){
                    if(st.count(check)>0){
                        st.erase(s);
                    }
                }
            }
        }
        vector<string> res(st.begin(),st.end());

        return res;
    }
};