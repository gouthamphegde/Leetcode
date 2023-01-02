class Solution {
public:
    string capitalizeTitle(string title) {
        vector<string>words;
        string ans = "";

        int i;
        string word="";
        for(i=0;i<title.length();i++){
            if(title[i]==' '){
                if(word.length() == 1 && word[0] <= 'Z'){
                word[0] = tolower(word[0]);
            }
            if(word.length() == 2){
                word[0] = tolower(word[0]);
                word[1] = tolower(word[1]);
 
            }
            else{
                transform(word.begin(), word.end(), word.begin(), ::tolower);
                
                if(word.length() == 1){
                    
                }
                else{
                                    word[0] = word[0] - 32;

                }
                

            }
            ans = ans + word;
            
            ans = ans+' ';
                
            word="";
            }else{
                word+=title[i];
            }
        }
        
        if(word.length() == 1 || word.length() == 2){
        transform(word.begin(), word.end(), word.begin(), ::tolower);

 
            }
            else{
                transform(word.begin(), word.end(), word.begin(), ::tolower);
                 word[0] = word[0] - 32;

            }
        ans+=word;

        
        /*for(auto word : words){
            if(word.length() == 1){
                word[0] = word[0] - 32;
            }
            if(word.length() == 2){
                word[0] = word[0] - 32;
                word[1] = word[1] - 32;
 
            }
            else{
                transform(word.begin(), word.end(), word.begin(), ::tolower);
                 word[0] = word[0] - 32;

            }
            ans = ans + word;
            
            ans = ans+' ';
        }*/
        
        return ans;
    }
};