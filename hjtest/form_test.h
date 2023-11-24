#ifndef __FORM_TEST_H__
#define __FORM_TEST_H__

extern unsigned int test_form_unique_id;

typedef struct _test_form test_form;

struct _test_form
{
    int unique_id;
    char *title;
    char *user;
    char *content;
};

int increment_test_form_unique_id(void);
test_form *init_test_form_with_id(int id, char *title, char *user, char *content);
test_form **init_test_form_array(int count);

#endif