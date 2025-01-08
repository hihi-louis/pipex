# include "./includes/pipex.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototype các hàm cần thiết
static char *extract_word(char *command, int len);
static char **split_word(char *command, char **array, int words, int order);
int skip_words(char *command, int i);  // Giả sử bạn có hàm này
void ft_free_double_p(char **array);

// Hàm skip_words mẫu nếu bạn chưa viết:
int skip_words(char *command, int i)
{
    while (command[i] && command[i] != ' ' && command[i] != '\'' && command[i] != '\"')
        i++;
    return i;
}

// Hàm free mảng 2 chiều
void ft_free_double_p(char **array)
{
    if (!array) return;
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}

int main(void)
{
    char command[] = "echo \"Hello World\" ls 'file name' pwd";
    int words = 4;  // Số từ dự kiến trong chuỗi
    char **array = malloc((words + 1) * sizeof(char *));
    
    if (!array)
    {
        printf("Memory allocation failed!\n");
        return (1);
    }

    // Tách các từ
    array = split_word(command, array, words, -1);
    if (!array)
    {
        printf("Error while splitting words.\n");
        return (1);
    }

    // In kết quả
    printf("Tách chuỗi thành các từ:\n");
    for (int i = 0; i < words; i++)
        printf("Word %d: %s\n", i + 1, array[i]);

    // Giải phóng bộ nhớ
    ft_free_double_p(array);
    return 0;
}

static char *extract_word(char *command, int len)
{
    char *word;
    int i = 0, j = 0;

    word = (char *)malloc(sizeof(char) * (len + 1));
    if (!word)
        return (NULL);

    while (i < len)
    {
        if ((command[0] == 34 || command[0] == 39) && command[i] == command[0])
            i++;
        else if (command[0] != 34 && command[0] != 39 && command[i] == 32)
            i++;
        else
        {
            if (command[0] != 34 && command[0] != 39 && command[i] == '\\')
                i++;
            word[j++] = command[i++];
        }
    }
    word[j] = '\0';
    return word;
}

static char **split_word(char *command, char **array, int words, int order)
{
    int i;
    char quote;

    while (++order < words)
    {
        while (*command == 32)  // Bỏ qua khoảng trắng
            command++;
        i = 0;
        quote = *command;

        if (*command == 34 || *command == 39)  // Nếu bắt đầu bằng dấu nháy
        {
            while (command[++i] != quote)
                ;
        }
        else
        {
            i = skip_words(command, 0);
        }
        
        array[order] = extract_word(command, i);
        if (!array[order])
        {
            ft_free_double_p(array);
            return (NULL);
        }

        if (*command == 39 || *command == 34)
            i++;
        command += i;  // Dịch con trỏ để xử lý từ tiếp theo
    }
    array[words] = NULL;  // Đảm bảo mảng kết thúc bằng NULL
    return array;
}
