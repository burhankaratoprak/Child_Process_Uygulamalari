#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int durum;

    pid = fork();

    if (pid < 0) {
        perror("Fork işlemi başarısız oldu");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        FILE *dosya = fopen("test.txt", "r");
        if (dosya == NULL) {
            perror("Dosya bulunamadı");
            abort();
        } else {
            printf("Dosya başarıyla açıldı.\n");
            fclose(dosya);
            exit(0); 
        }
    } else { 
        wait(&durum); 

        if (WIFEXITED(durum)) {
            printf("Çocuk süreci normal bir şekilde çıkış yaptı. Çıkış kodu: %d.\n", WEXITSTATUS(durum));
        } else if (WIFSIGNALED(durum)) {
            printf("Çocuk süreci bir sinyal ile sonlandırıldı. Sinyal kodu: %d.\n", WTERMSIG(durum));
        } else {
            printf("Çocuk süreci anormal bir şekilde sonlandı.\n");
        }
    }

    return 0;
}
