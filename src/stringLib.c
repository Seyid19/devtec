#include "stringLib.h"


int str_len(char* s){
    int i;
    for(i = 0; *s != '\0'; ++i,*s++);
    printf("Length of string: %d\n", i);
    return i;
}


int str_cmp(char* str1, char* str2){
    int ctr=0;
    
    while(str1[ctr]==str2[ctr]){
        if(str1[ctr]=='\0'||str2[ctr]=='\0')
            break;
        ctr++;
    }
    if(str1[ctr]=='\0' && str2[ctr]=='\0')
        return 0;
    else
        return -1;
}

int isPolindrome(char* str){
	char* reverse_text = malloc(sizeof(char));
    int i,n, len = 0;

    for (i = 0; str[i] != '\0'; i++){
       len++; 
    }

    
    for (i = len - 1; i >= 0; i--){
       reverse_text[len - i - 1] = str[i];
    }

   
    for (n = 1, i = 0; i < len; i++){
       if (reverse_text[i] != str[i])
       n = 0;
    }
 
    if (n == 1){
       printf("%s is a palindrome.\n", str);
       return 0;
    }
    else{
       printf("%s is not a palindrome\n", str);
       return -1;
    }

}