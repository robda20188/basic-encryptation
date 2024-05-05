#include <stdio.h>
#include <stdlib.h>

char* symbols = "abcdefghijklmnopqrstuvwxyz1234567890";

int length(char* string){
    int l = 0;
    while(string[l] != '\0'){
        l++;
    }
    return l + 1;
}

char* displace(int displacement){
    int displaced_length = length(symbols);
    char* displaced = malloc(displaced_length * sizeof(char));
    displaced[displaced_length - 1] = '\0';
    
    int j = 0;
    for(int i = 0; i < displaced_length - 1; i++){
        if(displacement + i >= displaced_length - 1){
            displaced[i] = symbols[j];
            j++;
            continue;
        }
        displaced[i] = symbols[displacement + i];
    }
    
    return displaced;
}

char* encrypt(char* code, int displacement){
    char* displaced = displace(displacement);
    
    int encrypted_length = length(code);
    char* encrypted = malloc(encrypted_length * sizeof(char));
    
    for(int i = 0; i < encrypted_length - 1; i++){
        int symbols_index = 0;
        while(symbols[symbols_index] != code[i]){
            symbols_index++;
        }         
        encrypted[i] = displaced[symbols_index];
    }
    
    return encrypted;
}

int main() {
    char* code = "daniel8"; 
    char* encrypted = encrypt(code, 10);
    
    printf("%s", encrypted);
    
    return 0;
}
