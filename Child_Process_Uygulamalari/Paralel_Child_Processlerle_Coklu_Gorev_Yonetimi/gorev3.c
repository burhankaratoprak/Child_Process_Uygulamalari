#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>


void create_file(const char *filename) {
    int fd = open(filename, O_CREAT | O_WRONLY, 0644);
    if (fd < 0) {
        perror("Dosya oluşturulamadı");
        exit(1);
    }
    write(fd, "Dosya başlatıldı.\n", 18);
    close(fd);
}


void write_file(const char *filename) {
    int fd = open(filename, O_WRONLY | O_APPEND);
    if (fd < 0) {
        perror("Dosya açılamadı");
        exit(1);
    }
    write(fd, "Yeni veri eklendi.\n", 19);
    close(fd);
}


void read_file(const char *filename) {
    char buffer[256];
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Dosya okunamadı");
        exit(1);
    }
    int bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0) {
        perror("Dosya okunurken hata");
        exit(1);
    }
    buffer[bytes_read] = '\0';
    printf("Dosya içeriği:\n%s", buffer);
    close(fd);
}

int main() {
    const char *filename = "output.txt";

    
    pid_t pid1 = fork();
    if (pid1 == 0) {
        create_file(filename);
        exit(0);
    }

    
    pid_t pid2 = fork();
    if (pid2 == 0) {
        sleep(1); 
        write_file(filename);
        exit(0);
    }

   
    pid_t pid3 = fork();
    if (pid3 == 0) {
        sleep(2); 
        read_file(filename);
        exit(0);
    }

    
    wait(NULL);
    wait(NULL);
    wait(NULL);

    printf("Tüm işlemler tamamlandı.\n");
    return 0;
}
