class Solution {
public:
    string capitalizeTitle(string title) {
        istringstream iss(title);   //or use stringstream
        string word;
        string str="" ;
        

        while(iss>>word){
            //  cout<<word<<" ";
            if(word.length()<=2){
                transform(word.begin(), word.end(), word.begin(), ::tolower);
                str+=word+" ";
            }
            else{
                
                word[0]=toupper(word[0]);
                transform(word.begin()+1, word.end(), word.begin()+1, ::tolower);
                

                str+= word+" ";
                
            }
        }
        // cout<<str;
        //   rtrim(str);

        return str.substr(0,str.length()-1);
    }
};