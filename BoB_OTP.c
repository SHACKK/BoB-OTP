#include <stdio.h>
#include <openssl/md5.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

void MD5Hash(char *string)
{
    int i;
    unsigned char digest[MD5_DIGEST_LENGTH];
    char md5Hash[50] = {0, };
    char *message;
    message = strcat(string, "BoB-OTP");

    MD5_CTX context;
    MD5_Init(&context);
    MD5_Update(&context, message, strlen(string));
    MD5_Final(digest, &context);

    for (i = 0 ; i < MD5_DIGEST_LENGTH ; ++ i)
        sprintf((md5Hash + (i * 2)), "%02x", digest[i]);
    
    printf("Result of md5(%s) : %s\n", string, md5Hash);
}

int main()
{
    char str_time_key[50];
    unsigned long unix_time = time(NULL);
    printf("%lu\n", unix_time);
    unsigned long rest = unix_time % 60;
    unsigned long time_key = unix_time - rest;
    printf("%lu\n", time_key);
    sprintf(str_time_key, "%lu", time_key);
    
    MD5Hash(str_time_key);
    int cnt_time = 60 - rest;
    
    do {
        if (cnt_time > 0) {
            sleep(1);
            cnt_time--;
            printf("%d.", cnt_time);
            fflush(stdout);
            continue;
        }
        unix_time = time(NULL);
        rest = unix_time % 60;
        time_key = unix_time - rest;
        sprintf(str_time_key, "%lu", time_key);

        MD5Hash(str_time_key);
        cnt_time = 59;
    }while (1);
}