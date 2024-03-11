class Solution {
    public:
        string sortSentence(string s) {
            string S[10][10];
            string temp;
            for(int i = 0; i < s.size(); i++){
                if(s[i] >= '1' && s[i] <= '9'){
                    S[s[i] - '0'][0] = temp;
                    temp = "";
                    i++;
                }
                else{
                    temp += s[i];
                }
            }
            string result = "";
            for(int i = 1; i < 10; i++){
                if(S[i][0] != ""){
                    result += S[i][0];
                    if(S[i+1][0] != ""){
                        result += " ";
                    }
                }
            }
            return result;   
        }
};  


/*
string temp = "";
string S[10];
int order;
for(i = 0; i < size; i++) {
    temp += s[i];
    if( get_order ) {
        S[order] = temp;
        temp = "";
    }
}
*/