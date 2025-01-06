#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

typedef struct s_pipex
{
    int fork_counts;      // Số lượng tiến trình con cần chờ
    int wait_status;      // Lưu trạng thái trả về từ `waitpid`
    int exit_status;      // Mã thoát của tiến trình con cuối cùng
    pid_t pid;            // PID của tiến trình con
} t_pipex;

void child_wait(t_pipex *pipex)
{
    while (pipex->fork_counts > 0)  // Chờ tất cả các tiến trình con
    {
        pipex->pid = wait(&pipex->wait_status);  // Lưu PID trả về từ `waitpid()` vào `pipex->pid`
        if (pipex->pid > 0)  // Nếu có tiến trình con kết thúc
        {
            if (WIFEXITED(pipex->wait_status))  // Nếu tiến trình con kết thúc bình thường
                pipex->exit_status = WEXITSTATUS(pipex->wait_status);  // Lấy mã thoát
            else if (WIFSIGNALED(pipex->wait_status))  // Nếu tiến trình con bị dừng bởi tín hiệu
                pipex->exit_status = 128 + WTERMSIG(pipex->wait_status);  // Gán mã tín hiệu cộng 128
            printf("Child process with PID %d finished. Exit status: %d\n", pipex->pid, pipex->exit_status);
            pipex->fork_counts--;  // Giảm số lượng tiến trình cần chờ
        }
        else if (pipex->pid == -1)  // Nếu `waitpid` gặp lỗi
        {
            perror("waitpid error");
            break;
        }
    }
}

int main(void)
{
    t_pipex pipex;
    pipex.fork_counts = 5;  // Giả sử chúng ta sẽ tạo 3 tiến trình con

    for (int i = 0; i < 5; i++)
    {
        pipex.pid = fork();  // Tạo tiến trình con
        // pipex.pid = -5;
        if (pipex.pid == 0)
        {
            printf("Child process %d running...\n", i + 1);
            sleep(i + 5);  // Tiến trình con "ngủ" để mô phỏng thời gian chạy
            exit(i);  // Kết thúc tiến trình con với mã thoát là `i`
        }
        else if (pipex.pid < 0)
        {
            perror("fork error");
            exit(1);
        }
    }

    child_wait(&pipex);  // Gọi hàm `child_wait` để chờ tất cả các tiến trình con hoàn thành
    printf("All child processes finished.\n");
    return 0;
}
