int fd; // open file descriptor
int nb; // # bytes read
int ns = 0; // # spaces
char buf[BUFSIZ]; // input buffer

fd = open("xyz",O_RDONLY);
assert(fd >= 0);
while ((nb = read(fd, buf, 1000)) > 0) {
    for (int i = 0; i < nb; i++)
        if (isspace(buf[i])) ns++;
}
close(fd);



fopen(FilePath, "r")

open(FilePath, O_RDONLY);

fopen(FilePath, "a")

open(FilePath, O_APPEND);

fopen(FilePath, "w")

open(FilePath, O_WRONLY | O_CREAT);

fopen(FilePath, "r+")
open(FilePath, O_RDWR);



fopen(FilePath, "w+")
open(FilePath, O_RDWR | O_CREAT);



int addStruct(char *fileName, struct X data) {
    int fd = open(fileName, O_APPEND);
    if (fd < 0) {
        perror("Failed to open file in addStruct");
        return -1;
    }
    if (write(fd, data, sizeof(struct X)) != sizeof(struct X)) {
        close(fd);
        return -1;
    }
    close(fd);
    return 1;
}
