#include "data_store.h"
#include "../format_test/form_test.h"
void save_data(test_form** data_storage,test_form*tmp_form)
{
    data_storage[test_form_unique_id]=tmp_form;
    increment_test_form_unique_id();

}