class Solution {
public:
    string intToRoman(int num) {
        map<int,string> mp;
        mp.insert({1000,"M"});
        mp.insert({900,"CM"});
        mp.insert({500,"D"});
        mp.insert({400,"CD"});
        mp.insert({100,"C"});
        mp.insert({90,"XC"});
        mp.insert({50,"L"});
        mp.insert({40,"XL"});
        mp.insert({10,"X"});
        mp.insert({9,"IX"});
        mp.insert({5,"V"});
        mp.insert({4,"IV"});
        mp.insert({3,"III"});
        mp.insert({2,"II"});
        mp.insert({1,"I"});
        
        string ans;
        while(num>0)
        {
            if(num<=0)break;
            for(auto it = mp.rbegin();it!=mp.rend();it++)
            {
                if(it->first <= num)
                    {//cout<<num<<" "<<it->first<<"\n";
                    num-=it->first;
                    ans += it->second;break;}

            }
        }            
        return ans;
    }
};