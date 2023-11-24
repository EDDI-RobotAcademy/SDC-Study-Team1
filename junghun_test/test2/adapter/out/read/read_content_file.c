#include "read_content_file.h"
#include "../../../api/service/file_create.h"

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUDDY_PAGE_SIZE         (1)

void read_content_from_file_and_print(int file_descriptor, char *read_content)
{
    int read_bytes;

    while ((read_bytes = read(file_descriptor, read_content, BUDDY_PAGE_SIZE)) > 0)
    {
        write(1, read_content, read_bytes);
    }
    printf("\n");
}

void read_content_from_file(int file_descriptor, char *read_content)
{
    read(file_descriptor, read_content, 4096);
}

int read_file_descriptor()
    {
        int file_descriptor = file_open("/home/eddi/proj/SDC-Study-Team1/junghun_test/test2/create_file/board.txt", O_RDONLY, 0644);
        
        return file_descriptor;
    }


void reset_file_pointer(int file_descriptor)
{
    // https://elixir.bootlin.com/linux/latest/source/include/linux/fdtable.h#L49
    // https://elixir.bootlin.com/linux/latest/source/include/linux/fs.h#L1007
    lseek(file_descriptor, 0, SEEK_SET);
}