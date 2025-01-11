#include <stdlib.h>
#include "./includes/pipex.h"
#include "./library/libft/libft.h"
#include "./library/ft_printf_fd/ft_printf.h"

// Giả lập hàm `ft_strncmp`
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    for (size_t i = 0; i < n && (s1[i] || s2[i]); i++)
    {
        if (s1[i] != s2[i])
            return (unsigned char)s1[i] - (unsigned char)s2[i];
    }
    return 0;
}

// Giả lập hàm `ft_split`
char **ft_split(const char *s, char c)
{
    int count = 1, i = 0, j = 0, k = 0;
    while (s[i])
        if (s[i++] == c)
            count++;

    char **result = malloc((count + 1) * sizeof(char *));
    if (!result)
        return NULL;

    for (i = 0; s[i]; k++)
    {
        j = i;
        while (s[i] && s[i] != c)
            i++;
        result[k] = strndup(s + j, i - j);
        if (s[i])
            i++;
    }
    result[k] = NULL;
    return result;
}

// Hàm xử lý lỗi
void handle_command_error(char **command, const char *msg, int exit_code)
{
    ft_printf_fd(2, "Error: %s\n", msg);  // In lỗi ra STDERR
    if (command)
    {
        for (int i = 0; command[i]; i++)
            free(command[i]);
        free(command);
    }
    exit(exit_code);
}

// Hàm `found_envp_path`
static char **found_envp_path(char **envp, char **command)
{
    int i = 0;

    while (envp[i])
    {
        if (ft_strncmp(envp[i], "PATH=", 5) == 0)
            return ft_split(envp[i] + 5, ':');  // Lấy phần đường dẫn sau "PATH="
        i++;
    }
    handle_command_error(command, "No such file or directory", 1);
    return NULL;
}

int main(int argc, char *argv[], char *envp[])
{
    char *command[] = { "ls", NULL };
    char **paths = found_envp_path(envp, command);

    ft_printf_fd(1, "Paths found in PATH:\n");  // In thông báo ra STDOUT
    for (int i = 0; paths[i] != NULL; i++)
    {
        ft_printf_fd(1, "Path %d: %s\n", i + 1, paths[i]);  // In các đường dẫn
        free(paths[i]);
    }
    free(paths);

    return 0;
}
