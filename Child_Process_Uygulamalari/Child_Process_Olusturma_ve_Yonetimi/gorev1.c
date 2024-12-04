#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;

    
    pid = fork();

    if (pid < 0) {
        
        perror("fork hatası");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
       
        printf("Child process başlatılıyor (PID: %d)...\n", getpid());

        
        execlp("cat", "cat", "dosya.txt", (char *)NULL);

        
        perror("execlp hatası");
        exit(EXIT_FAILURE);
    } else {
        
        printf("Parent process (PID: %d), child process'i bekliyor...\n", getpid());

        
        wait(&status);

        
        if (WIFEXITED(status)) {
            printf("Child process tamamlandı. Çıkış durumu: %d\n", WEXITSTATUS(status));
        } else {
            printf("Child process beklenmedik bir şekilde sonlandı.\n");
        }

        printf("Parent process sonlanıyor.\n");
    }

    return 0;
}
