#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

// Hàm `count_words()` từ chương trình của bạn
static int count_words(char *command)
{
    int words = 0;
    int i = 0;
    char quote;

    while (command[i])
    {
        if (command[i] == 39 || command[i] == 34)  // Nếu là dấu nháy đơn (') hoặc nháy kép (")
        {
            words++;
            quote = command[i];
            i++;
            while (command[i] && command[i] != quote)
                i++;
            if (command[i] != quote)  // Nếu thiếu dấu đóng nháy
            {
                fprintf(stderr, "pipex: Missing %c\n", quote);
                exit(1);
            }
            i++;
        }
        else if (command[i] != 32)  // Nếu không phải khoảng trắng
        {
            words++;
            while (command[i] && command[i] != 32 && command[i] != 34 && command[i] != 39)
            {
                if (command[i] == '\\' && command[i + 1])
                    i += 2;  // Bỏ qua ký tự escape và ký tự sau nó
                else
                    i++;
            }
        }
        else
            i++;
    }
    return words;
}

int main(int argc, char **argv)
{
    if (argc < 2)  // Nếu người dùng không nhập chuỗi lệnh
    {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        exit(1);
    }

    for (int i = 1; i < argc; i++)  // Duyệt qua các chuỗi lệnh người dùng nhập
    {
        printf("Command %d: \"%s\"\n", i, argv[i]);
        int words = count_words(argv[i]);
        printf("Number of words: %d\n\n", words);
    }

    return 0;
}
