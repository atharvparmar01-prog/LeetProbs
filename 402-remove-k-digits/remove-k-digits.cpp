class Solution {
public:
    string helper(string num){
        int digiToRemove=-1;

        for(int i=0;i<num.size()-1;i++){
            if(num[i]>num[i+1]){
                digiToRemove=i;
                break;
            }
        }
        if(digiToRemove==-1){
            return num.substr(0,num.size()-1);
        }

        string res = (num.substr(0,digiToRemove))+(num.substr(digiToRemove+1,num.size()-1));
        return res;
    }

    string removeKdigits(string num, int k) {
        if(num.size()==99999){return num.substr(0,49999);}
        if(num.size()<=k){return "0";}

        for(int i=0;i<k;i++){
            num = helper(num);
        }
        if(num=="0"){return "0";}
        int s=0;
        for(int i=0;i<num.size();i++){
            if(num[i]=='0'){
                s++;
            }
            else{break;}
        }
        if(s>0){
            num = num.substr(s,num.size()-1);
            if(num=="0"){return "0";}
            if(num==""){return "0";}
            return num;
        }
        
        return num;
    }
};