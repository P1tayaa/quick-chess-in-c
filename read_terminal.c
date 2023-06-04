
#include "chess.h"

int const buffer_size = 20;

char    *str_join(char *str1, char *str2)
{
    char *new_str;
    int i;
    int len_str1;
    int len_str2;

    if (!str1 && !str2)
        return (NULL);
    if (str1)
        len_str1 = strlen(str1);
    else
        len_str1 = 0;
    if (str2)
        len_str2 = strlen(str2);
    else
        len_str2 = 0;
    new_str = malloc(sizeof(char) * (len_str1 + len_str2 + 1));
    if (!new_str)
        return (NULL);
    i = 0;
    while (i < len_str1)
    {
        new_str[i] = str1[i];
        i++;
    }
    i = 0;
    while (i < len_str2)
    {
        new_str[len_str1 + i] = str2[i];
        i++;
    }
    new_str[len_str1 + i] = '\0';
    return (new_str);
}

char    *start_read_terminal()
{
    char    buffer[buffer_size];
    char    *current_line;
    char    *temp_str;
    int     string_len;

    current_line = NULL;
    buffer[0] = '\0';
    string_len = buffer_size;
    while (string_len == buffer_size)
    {
        temp_str = str_join(current_line, buffer);
        if (current_line)
            free(current_line);
        current_line = temp_str;
        string_len = read(0, buffer, buffer_size);
    }
    temp_str = str_join(current_line, buffer);
    if (current_line)
        free(current_line);
    current_line = temp_str;
    return (current_line);
}
