#include "write_post.h"
#include "../../adapter/in/create/create_post.h"

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

bool write_post_in_file(int file_descriptor, char *content)
{
    int content_length = strlen(content);
    int written_bytes = write(file_descriptor, content, content_length);
    
    printf("written_byte = %d\n", written_bytes);
    printf("content_length = %d\n", content_length);

    if (written_bytes != content_length)
    {
        printf("write() System Call Error!\n");
        return false;
    }

    return true;
}