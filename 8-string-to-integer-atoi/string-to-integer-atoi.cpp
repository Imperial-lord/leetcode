class Solution {
public:
    set<char> ch={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', '+'};
    int myAtoi(string s) {
        bool isNum=false;
        bool isSign=false;
        string num="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                if(!isNum && !isSign) continue;
                else break;
            }
            else if(ch.count(s[i])){
                if(s[i]=='+' || s[i]=='-'){
                    if(isNum || isSign) break;
                    else num+=s[i];
                    isSign = true;
                }
                else{
                    num+=s[i];
                    isNum=true;
                }
            }
            else break;
        }

        long long ans = 0;
        bool isNeg = false;
        if(num[0]=='+') num.erase(0,1);
        else if(num[0]=='-'){
            isNeg = true;
            num.erase(0,1);
        }

        // remove any leading 0s
        int zCount=0;
        for(int i=0;i<num.length();i++){
            if(num[i]=='0') zCount++;
            else break;
        }

        num.erase(0, zCount);

        if(num.length()>10){
            if(isNeg) return INT_MIN;
            else return INT_MAX;
        } 

        else{
            long long cnt=1;
            for(int i=num.length()-1;i>=0;i--){
                int val = num[i]-48;
                ans+=val*cnt;
                cnt*=10;
            }
            if(isNeg) ans*=-1;
            if(ans>INT_MAX) return INT_MAX;
            else if(ans<INT_MIN) return INT_MIN;
            else return (int) ans;
        }
    }
};