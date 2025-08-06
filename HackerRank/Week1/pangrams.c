char* pangrams(char* s) {
    static char result[12];
    int letter[26]={0};
    int count=0;
    
    for (int i=0;s[i] != '\0';i++){
        if(isalpha((unsigned char)s[i])){
            int index = tolower((unsigned char)s[i]) - 'a';
            if (letter[index] == 0){
                letter[index]=1;
                count++;
                if (count == 26){
                    strcpy(result,"pangram");
                    return result;
                }
            }
        }
    }
    if (count==26){
        strcpy(result, "pangram");
    }else{
        strcpy(result,"not pangram");
    }
    return result;

}