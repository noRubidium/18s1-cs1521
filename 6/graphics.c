int main(int argc, char const *argv[]) {
    int pic_fd = open("Picture", O_RDONLY);
    if (pic_fd < 0) {
        perror("Fail to open Piture!");
        return -1;
    }

    int device_fd = open("/dev/display", O_WRONLY);
    if (device_fd < 0) {
        close(pic_fd);
        perror("Failed to open /device/display");
        return -1;
    }

    Graphics g;

    while(read(pic_fd, &g, sizeof(Graphics)) == sizeof(Graphics)) {
        display(device_fd, g);
    }

    close(pic_fd);
    close(device_fd);

    return 0;
}
