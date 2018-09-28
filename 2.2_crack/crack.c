#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }

    string hashed_pwd = argv[1];

    // define salt - i.e. first two chars of hashed pwd
    char salt[3];
    strncpy(salt, hashed_pwd, 2);
    salt[2] = '\0';

    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // iterate over pwd length
    for (int pwd_len = 1; pwd_len < 6; pwd_len++)
    {
        //create the pwd string with adequate length
        char pwd[pwd_len + 1];
        pwd[pwd_len] = '\0';

        //printf("\nPWD len: %i\n", pwd_len);

        //iterate over alphabet for first letter
        for (int idx1 = 0; alphabet[idx1] != '\0'; idx1++)
        {
            pwd[0] = alphabet[idx1];

            if (pwd_len > 1)
            {
                //iterate over alphabet for second letter
                for (int idx2 = 0; alphabet[idx2] != '\0'; idx2++)
                {
                    pwd[1] = alphabet[idx2];

                    if (pwd_len > 2)
                    {
                        //iterate over alphabet for third letter
                        for (int idx3 = 0; alphabet[idx3] != '\0'; idx3++)
                        {
                            pwd[2] = alphabet[idx3];

                            if (pwd_len > 3)
                            {
                                //iterate over alphabet for fourth letter
                                for (int idx4 = 0; alphabet[idx4] != '\0'; idx4++)
                                {
                                    pwd[3] = alphabet[idx4];

                                    if (pwd_len > 4)
                                    {
                                        //iterate over alphabet for fifth letter
                                        for (int idx5 = 0; alphabet[idx5] != '\0'; idx5++)
                                        {
                                            pwd[4] = alphabet[idx5];

                                            string tested_hash = crypt(pwd, salt);
                                            if (strcmp(tested_hash, hashed_pwd) == 0)
                                            {
                                                printf("%s\n",pwd);
                                                return 0;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        string tested_hash = crypt(pwd, salt);
                                        if (strcmp(tested_hash, hashed_pwd) == 0)
                                        {
                                            printf("%s\n",pwd);
                                            return 0;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                string tested_hash = crypt(pwd, salt);
                                if (strcmp(tested_hash, hashed_pwd) == 0)
                                {
                                    printf("%s\n",pwd);
                                    return 0;
                                }
                            }
                        }
                    }
                    else
                    {
                        string tested_hash = crypt(pwd, salt);
                        if (strcmp(tested_hash, hashed_pwd) == 0)
                        {
                            printf("%s\n",pwd);
                            return 0;
                        }
                    }
                }
            }
            else
            {
                string tested_hash = crypt(pwd, salt);
                if (strcmp(tested_hash, hashed_pwd) == 0)
                {
                    printf("%s\n",pwd);
                    return 0;
                }
            }
        }
    }
    return 1;
}