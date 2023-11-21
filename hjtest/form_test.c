#include "form_test.h"

#include <stdlib.h>
#include <string.h>

unsigned int test_form_unique_id;

int increment_test_form_unique_id(void)
{
    return test_form_unique_id++;
}

test_form *init_test_form_with_id(int id, char *title, char* user, char *content)
{
    test_form *tmp_form = (test_form *)malloc(sizeof(test_form));
    int title_length = strlen(title) + 1;
    int user_length = strlen(user) + 1;
    int content_length = strlen(content) + 1;

    tmp_form->unique_id = id;

    tmp_form->title = (char *)malloc(sizeof(char) * title_length);
    strncpy(tmp_form->title, title, title_length);

    tmp_form->user = (char *)malloc(sizeof(char) * user_length);
    strncpy(tmp_form->user, user, user_length);

    
    tmp_form->content =
        (char *)malloc(sizeof(char) * content_length);
    strncpy(tmp_form->content, content, content_length);

    return tmp_form;
}



test_form **init_test_form_array(int count)
{
    test_form **tmp_format = (test_form **)malloc(sizeof(test_form *) * count);

    return tmp_format;
}