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
            if(symbols_index > length(symbols) - 1){
                printf("Invalid characters\n");
                exit(1);
            }
        }         
        encrypted[i] = displaced[symbols_index];
    }
    
    return encrypted;
}

char* decrypt(char* code, int displacement){
    char* displaced = displace(displacement);
    
    int decrypted_length = length(code);
    char* decrypted = malloc(decrypted_length * sizeof(char));
    
    for(int i = 0; i < decrypted_length - 1; i++){
        int displaced_index = 0;
        while(displaced[displaced_index] != code[i]){
            displaced_index++;
            if(displaced_index > length(displaced) - 1){
                printf("Invalid characters\n");
                exit(1);
            }
        }
        decrypted[i] = symbols[displaced_index];
    }
    
    return decrypted;
}

int main() {
    int toEncrypt;
    int input;
    printf("Encrypt[1] or Decrypt[2]: ");
    scanf("%d", &input);
    if(input == 1){
        toEncrypt = 1;
    }
    else if(input == 2){
        toEncrypt = 0;
    }else{
        printf("Invalid input\n");
        return 1;
    }

    char code[100];
    printf("Code: ");
    scanf("%s", code);

    int displacement;
    printf("Displacement: ");
    scanf("%d", &displacement);

    if(displacement > length(symbols) - 1){
        displacement = displacement % (length(symbols) - 1);
    }else if(displacement < 0){
        displacement = length(symbols) + displacement;
    }
    
    if(toEncrypt){
        printf("%s\n", encrypt(code, displacement));
    }else{
        printf("%s\n", decrypt(code, displacement));
    }
    
    return 0;
}
