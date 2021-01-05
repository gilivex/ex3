# include <stdio.h>
# include "txtfind.h"
# include <string.h>

# define LINE 256
# define WORD 36
# define SUMLINES 250

int getLine(char s[]){
    char w;
    int num = 0;
    while(scanf("%c", &w) != EOF && w != '\n'){
        s[num]=w;
        num++;
    }
    return num;
}

int getwords(char w[]){
    char word;
    int num = 0;
    while(scanf("%c", &word) != EOF && word != '\n' && word != '\t' && word != ' ' ){
        w[num]=word;
        num++; 
    }
    return num;
}
int substring(char *str1, char *str2){
    if(strstr(str1,str2)!= NULL) return 1;
    return 0;
}

// int mySub(char *str1, char *str2);

// int similar(char *s, char *t, int n){
//     int lengthOfS = strlen(s);
//     int lengthOfT = strlen(t);

//     if(lengthOfT > lengthOfS) return 0;
//     else if (lengthOfS - lengthOfT != n) return 0;
//     else{
//         if (mySub(s,t) == 1)return 1;
//         else return 0;
//     }
// }
int similar(char *s, char *t, int n){
    size_t index=0;
    size_t sizes=0;
    while(s[sizes]!='\0'){sizes++;}
    char *copy;
    copy=s;
    char *adress;
    while(t[index]!='\0' && adress-s< sizes-1){
        adress=strchr(copy,t[index]);
        index++;
        if (adress==NULL ) 
            return 0;
        copy= adress+1;  
    }
    if(sizes-index!=n)
        return 0;
    return 1;
}

void print_lines(char *str){
    char lineFromDoc[SUMLINES][LINE];
    int i=0;
    while(getLine(lineFromDoc[i])){
        if(substring(lineFromDoc[i], str))
            printf("%s\n", lineFromDoc[i]);
        ++i;
    }
}


void print_similar_words(char *str){
    //char lineFromDoc[LINE]="";
    char w[400][WORD];
    int i=0;
    while(getwords(w[i])){
    //   int dif = strlen(w) - strlen(str);
    //   if (dif == 0){
          if(similar(w[i],str,0)) printf("%s\n", w[i]);
      //}
     // else if(dif == 1){
          if(similar(w[i],str,1)) printf("%s\n", w[i]);
      //}
      i++;
    }  
}

/////////////////////
/* private methods */
/////////////////////

// int mySub(char *str1, char *str2){
//     int tmp = 0, i=0;
//     for (i; str2[i] != '\0' ; i++){
//         for(int j = tmp; str1[tmp] != '\0';j++, tmp++){
//             if(str2[i] == str1[j]){ tmp++; break; }
//         }
//     }
//     if(str1[tmp] != '\0') return 1;
//     else if(str1[tmp-1] == str2[1]) return 1;
//     return 0;
// }


int main(){
    char searchString[WORD] = "";
    char space[WORD];
    char option;
    getwords(searchString);
    scanf("%c", &option);
    getLine(space);
    switch(option){
        case 'a':
            print_lines(searchString);
            break;
        case 'b':
            print_similar_words(searchString);
            break;
        default:
            printf("incorrect option\n");
    }

    return 0;
}