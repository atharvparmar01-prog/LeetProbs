class Solution {
public:
    string adder(string s, int a){
        for(int i=1;i<s.size();i+=2){
            int num = s[i] - '0';
            num+=a;
            num = num%10;
            s[i]=num+'0';
        }
        return s;
    }
    string rotateString(string s, int b) {
        if (s.empty()) return s;
        b %= s.size();
        rotate(s.begin(), s.end() - b, s.end());
        return s;
    }

    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        q.push({s});
        string mini = s;
        unordered_set<string> st;

        while(!q.empty()){
            string beg = q.front();
            cout<<beg<<endl;
            q.pop();
            string added = adder(beg,a);
            string rotated = rotateString(beg,b);
            if(st.count(added)==0){
                st.insert(added);
                if(mini>added){
                    mini = added;
                }
                q.push(added);
            } 
            if(st.count(rotated)==0){
                st.insert(rotated);
                if(mini>rotated){
                    mini = rotated;
                }
                q.push(rotated);
            }
        }
        return mini;
    }

};