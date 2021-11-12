class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        //partition
        auto it = stable_partition(logs.begin(),logs.end(),[](string& str1){
            return isalpha(str1[str1.find(' ')+1]);
        });
        
        
        sort(logs.begin(),it,[](string s1, string s2){
            string ss1 = s1.substr(s1.find(' ')+1);
            string ss2 = s2.substr(s2.find(' ')+1);
            
            if(ss1 == ss2)return s1<s2;
            else return ss1<ss2;
        });
        return logs;
    }
};