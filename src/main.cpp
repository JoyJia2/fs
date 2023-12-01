#define FUSE_USE_VERSION 30

#include <fuse.h>
#include <iostream>
#include <cstring>
#include <cstdlib>

static int my_getattr(const char* path, struct stat* stbuf) {
    // 自定义获取文件属性的方法
    // ...
    std::cout<<"request for my_getattr"<<std::endl;
    return 0;
}

static int my_readdir(const char* path, void* buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info* fi) {
    // 自定义读取目录内容的方法
    // ...
    std::cout<<"request for my_readdir"<<std::endl;
    return 0;
}

static int my_read(const char* path, char* buf, size_t size, off_t offset, struct fuse_file_info* fi) {
    // 自定义读取文件内容的方法
    // ...
    std::cout<<"request for my_read"<<std::endl;
    return size;
}

static const struct fuse_operations my_operations = {
    .getattr = my_getattr,
    .read = my_read,
    .readdir = my_readdir,
    // 其他方法...
};

int main(int argc, char* argv[]) {
    // 启动 FUSE 文件系统
    return fuse_main(argc, argv, &my_operations, NULL);
}