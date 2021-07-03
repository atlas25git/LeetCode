class Solution {
public:
    int romanToInt(string num) {
       
        map<char,int> mp;
        
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        //cout<<mp['M']<<endl;
        int no=0;
        
         for(int i=0;i<num.size()-1;i++)
         {
             if(mp[num[i]] <mp[num[i+1]])
                 no -= mp[num[i]];
             else no+=mp[num[i]];
         }
    return no+mp[num[num.size()-1]];
    }
};