
int inc_by_value(int number);
void inc_by_pointer(int* number);
void inc_by_reference(int &number);
void swap_ptr(int* ptr_a, int* ptr_b);
void swap_ref(int &ref_a, int &ref_b);
int min_in_array(const int* arr, const int arr_size);
int min_in_2d_array(const int* arr, const int arr_rows, const int arr_colums);
int my_str_cmp(const char* str1, const char* str2);
int day_of_year(int day, int month, int year, int* table);
void day_of_month(int day_of_the_year, int year, const int* table, int* return_values);
void add_unique(int* arr, int* n, int new_value);
void print_array(const int* arr, int n);
int sumN(int n);
int encoded32_size(int raw_size);
int decoded32_size(int encode_size);
int encode32(const char *raw_data, int raw_size, char *dst);
int decode32(const char *encoded_data, int encoded_size, char *dst);
char* encode_string(const char* string);
char* decode_string(const char* encoded_strig);
void var_args(int nN1, ...);
int* my_min(int* arr, int arr_size);