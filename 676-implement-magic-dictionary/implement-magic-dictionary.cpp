class MagicDictionary {
public:
    unordered_set<string> st;
    MagicDictionary() {
        unordered_set<string> st;
    }
    
    void buildDict(vector<string> dictionary) {
        unordered_set<string> temp(dictionary.begin(),dictionary.end());
        st = temp;
    }
    
    bool search(string searchWord) {
        int n = searchWord.size();
        string tempword = searchWord;
        vector<char> alpha = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        for(int i=0;i<n;i++){
            searchWord = tempword;
            for(auto it:alpha){
                if(tempword[i]==it){cout<<"!";continue;}
                searchWord[i]=it;
                if(st.count(searchWord)>0){return true;}
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */