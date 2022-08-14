#include <check.h>

#line 1 "my_string_test.check"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_string.h"

START_TEST(my_memchr_test)
{
#line 7
char s1[] = "test";
ck_assert_ptr_eq(my_memchr(s1,'e',5), my_memchr(s1,'e',5));
ck_assert_ptr_eq(my_memchr(s1, 'p', 5), my_memchr(s1,'p',5));

}
END_TEST

START_TEST(my_memcmp_test)
{
#line 12
char s1[] = "test";
char s2[] = "test";
char s3[] = "Test";
ck_assert_int_eq(memcmp(s1, s2, 5), my_memcmp(s1, s2, 5));
ck_assert_int_eq(memcmp(s1, s3, 5), my_memcmp(s1, s3, 5));
ck_assert_int_eq(memcmp(s3, s1, 5), my_memcmp(s3, s1, 5));
ck_assert_int_eq(memcmp(s1, s2, 0), my_memcmp(s1, s2, 0));

}
END_TEST

START_TEST(my_memcpy_test)
{
#line 21
char s1[5] = "";
char s2[5] = "";
char s3[] = "test";
ck_assert_str_eq((char*)memcpy(s1, s3, 4), (char*)my_memcpy(s2, s3, 4));
ck_assert_ptr_eq(memcpy(s1, s3, 4), my_memcpy(s1, s3, 4));

}
END_TEST

START_TEST(my_memmove_test)
{
#line 28
char s1[] = "Two Two Three";
char s2[] = "Two Two Three";
char s3[] = "One";
ck_assert_str_eq((char*)memmove(s1, s3, 3), (char*)my_memmove(s2, s3, 3));
ck_assert_ptr_eq(memmove(s1, s3, 3), my_memmove(s1, s3, 3));

}
END_TEST

START_TEST(my_memmove_test_2)
{
#line 35
char s3[] = "One";
char s2[] = "Two Two Three";
char s1[] = "Two Two Three";
ck_assert_str_eq((char*)memmove(s1, s3, 3), (char*)my_memmove(s2, s3, 3));
ck_assert_ptr_eq(memmove(s1, s3, 3), my_memmove(s1, s3, 3));

}
END_TEST

START_TEST(my_memset_test)
{
#line 42
char s1[6] = "";
char s2[6] = "";
ck_assert_str_eq((char*)memset(s1, '1', 5), (char*)my_memset(s2, '1', 5));
ck_assert_ptr_eq(memset(s1, '1', 5), my_memset(s1, '1', 5));

}
END_TEST

START_TEST(my_strcat_test)
{
#line 48
char s1[10] = "str";
char s2[10] = "str";
ck_assert_str_eq(strcat(s1, "cat"), my_strcat(s2, "cat"));
ck_assert_ptr_eq(strcat(s1, ""), my_strcat(s1, ""));

}
END_TEST

START_TEST(my_strncat_test)
{
#line 54
char s1[10] = "str";
char s2[10] = "str";
ck_assert_str_eq(strncat(s1, "cats", 3), my_strncat(s2, "cats", 3));
ck_assert_ptr_eq(strncat(s1, "", 0), my_strncat(s1, "", 0));

}
END_TEST

START_TEST(my_strchr_test)
{
#line 60
char s1[] = "test";
ck_assert_ptr_eq(strchr(s1,'e'), my_strchr(s1,'e'));
ck_assert_ptr_eq(strchr(s1, 'p'), my_strchr(s1,'p'));

}
END_TEST

START_TEST(my_strcmp_test)
{
#line 65
char s1[] = "test";
char s2[] = "test";
char s3[] = "Aest";
ck_assert_int_eq(strcmp(s1, s2), my_strcmp(s1, s2));
ck_assert_int_eq(strcmp(s1, s3), my_strcmp(s1, s3));
ck_assert_int_eq(strcmp(s3, s1), my_strcmp(s3, s1));

}
END_TEST

START_TEST(my_strncmp_test)
{
#line 73
char s1[] = "test\0test";
char s2[] = "test\0";
char s3[] = "Test\0done";
ck_assert_int_eq(strncmp(s1, s2, 8), my_strncmp(s1, s2, 8));
ck_assert_int_eq(strncmp(s1, s3, 8), my_strncmp(s1, s3, 8));
ck_assert_int_eq(strncmp(s3, s1, 8), my_strncmp(s3, s1, 8));

}
END_TEST

START_TEST(my_strcpy_test)
{
#line 81
char s1[5] = "";
char s2[5] = "";
char s3[] = "test\0test";
ck_assert_str_eq(strcpy(s1, s3), my_strcpy(s2, s3));
ck_assert_ptr_eq(strcpy(s1, s3), my_strcpy(s1, s3));

}
END_TEST

START_TEST(my_strcpy_test1)
{
#line 88
    char src[] = "Floppa!!!";
    char res[5 + 15] = "";
    char expected[5 + 15] = "";
ck_assert_str_eq(strcpy(expected, src), my_strcpy(res, src));
ck_assert_str_eq(strcpy(expected, src), my_strcpy(res, src));

}
END_TEST

START_TEST(my_strcpy_test2)
{
#line 95
    char src[] = "";
    char res[5 + 15] = "abobas";
    char expected[5 + 15] = "abobas";
ck_assert_str_eq(strcpy(expected, src), my_strcpy(res, src));
ck_assert_str_eq(strcpy(expected, src), my_strcpy(res, src));


}
END_TEST

START_TEST(my_strcpy_test3)
{
#line 103
    char src[] = "cock";
    char res[5 + 15] = "";
    char expected[5 + 15] = "";  
ck_assert_str_eq(strcpy(expected, src), my_strcpy(res, src));
ck_assert_str_eq(strcpy(expected, src), my_strcpy(res, src));

}
END_TEST

START_TEST(my_strcpy_test4)
{
#line 110
    char src[] = "1";
    char res[5 + 15] = "";
    char expected[5 + 15] = "";  
ck_assert_str_eq(strcpy(expected, src), my_strcpy(res, src));
ck_assert_str_eq(strcpy(expected, src), my_strcpy(res, src));

}
END_TEST

START_TEST(my_strcpy_test5)
{
#line 117
    char src[] = " floppa!!!";
    char res[5 + 15] = "aboba ";
    char expected[5 + 15] = "aboba "; 
ck_assert_str_eq(strcpy(expected, src), my_strcpy(res, src));
ck_assert_str_eq(strcpy(expected, src), my_strcpy(res, src));

}
END_TEST

START_TEST(my_strcpy_test6)
{
#line 124
    char src[] = " my dear friend\"";
    char res[5 + 15] = "Hello";
    char expected[5 + 15] = "Hello";
ck_assert_str_eq(strcpy(expected, src), my_strcpy(res, src));
ck_assert_str_eq(strcpy(expected, src), my_strcpy(res, src));

}
END_TEST

START_TEST(my_strcpy_test7)
{
#line 131
    char src[] = "ab\0ba";
    char res[10 + 9] = "Gre\0t";
    char expected[10 + 9] = "Gre\0t"; 
ck_assert_str_eq(strcpy(expected, src), my_strcpy(res, src));
ck_assert_str_eq(strcpy(expected, src), my_strcpy(res, src));

}
END_TEST

START_TEST(my_strcpy_test8)
{
#line 138
    char src[] = "ad[sofijpoiajsdf pj98981h23 p9h floppa!!!";
    char res[49 + 42] = "as[oidjf paijsdf j9oqh2837o4h hUW auhduash W8awd";
    char expected[49 + 42] = "as[oidjf paijsdf j9oqh2837o4h hUW auhduash W8awd";  
ck_assert_str_eq(strcpy(expected, src), my_strcpy(res, src));
ck_assert_str_eq(strcpy(expected, src), my_strcpy(res, src));

}
END_TEST

START_TEST(my_strncpy_test)
{
#line 145
char s1[10] = "";
char s2[10] = "";
char s3[] = "test\0test";
ck_assert_str_eq(strncpy(s1, s3, 6), my_strncpy(s2, s3, 6));
ck_assert_ptr_eq(strncpy(s1, s3, 0), my_strncpy(s1, s3, 0));

}
END_TEST

START_TEST(my_strcspn_test)
{
#line 152
char s1[] = "0123456789";
char s2[] = "9876";
ck_assert_int_eq(strcspn(s1, s2), my_strcspn(s1, s2));
ck_assert_int_eq(strcspn(s1, "0"), my_strcspn(s1, "0"));
ck_assert_int_eq(strcspn(s1, "9"), my_strcspn(s1, "9"));
ck_assert_int_eq(strcspn(s1, "q"), my_strcspn(s1, "q"));

}
END_TEST

START_TEST(my_strlen_test)
{
#line 160
char s1[] = "test\0test";
char s2[] = "";
ck_assert_int_eq(strlen(s1), my_strlen(s1));
ck_assert_int_eq(strlen(s2), my_strlen(s2));

}
END_TEST

START_TEST(my_strpbrk_test)
{
#line 166
char s1[] = "01234567";
char s2[] = "654";
ck_assert_ptr_eq(strpbrk(s1, s2), my_strpbrk(s1, s2));
ck_assert_ptr_eq(strpbrk(s1, "8"), my_strpbrk(s1, "8"));

}
END_TEST

START_TEST(my_strrchr_test)
{
#line 172
char s1[] = "01234567";
ck_assert_ptr_eq(strrchr(s1, '7'), my_strrchr(s1, '7'));
ck_assert_ptr_eq(strrchr(s1, '8'), my_strrchr(s1, '8'));

}
END_TEST

START_TEST(my_strspn_test)
{
#line 177
char s1[] = "01234567";
char s2[] = "210";
ck_assert_int_eq(strspn(s1, s2), my_strspn(s1, s2));
ck_assert_int_eq(strspn(s1, "89"), my_strspn(s1, "89"));

}
END_TEST

START_TEST(my_strstr_test)
{
#line 183
char s1[] = "01234567";
char s2[] = "456";
ck_assert_ptr_eq(strstr(s1, s2), my_strstr(s1, s2));
ck_assert_ptr_eq(strstr(s1, "89"), my_strstr(s1, "89"));

}
END_TEST

START_TEST(my_strtok_test)
{
#line 189
char s1[] = "123//456/ dfsg sf4";
char s2[] = "123//456/ dfsg sf4";
char s3[] = "/ ";
char* p1 = strtok(s1, s3);
char* p2 = my_strtok(s2, s3);
p1 = strtok(((void*)0), s3);
p2 = my_strtok(((void*)0), s3);
ck_assert_str_eq(strtok(p1, s3), my_strtok(p2, s3));
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, my_memchr_test);
    tcase_add_test(tc1_1, my_memcmp_test);
    tcase_add_test(tc1_1, my_memcpy_test);
    tcase_add_test(tc1_1, my_memmove_test);
    tcase_add_test(tc1_1, my_memmove_test_2);
    tcase_add_test(tc1_1, my_memset_test);
    tcase_add_test(tc1_1, my_strcat_test);
    tcase_add_test(tc1_1, my_strncat_test);
    tcase_add_test(tc1_1, my_strchr_test);
    tcase_add_test(tc1_1, my_strcmp_test);
    tcase_add_test(tc1_1, my_strncmp_test);
    tcase_add_test(tc1_1, my_strcpy_test);
    tcase_add_test(tc1_1, my_strcpy_test1);
    tcase_add_test(tc1_1, my_strcpy_test2);
    tcase_add_test(tc1_1, my_strcpy_test3);
    tcase_add_test(tc1_1, my_strcpy_test4);
    tcase_add_test(tc1_1, my_strcpy_test5);
    tcase_add_test(tc1_1, my_strcpy_test6);
    tcase_add_test(tc1_1, my_strcpy_test7);
    tcase_add_test(tc1_1, my_strcpy_test8);
    tcase_add_test(tc1_1, my_strncpy_test);
    tcase_add_test(tc1_1, my_strcspn_test);
    tcase_add_test(tc1_1, my_strlen_test);
    tcase_add_test(tc1_1, my_strpbrk_test);
    tcase_add_test(tc1_1, my_strrchr_test);
    tcase_add_test(tc1_1, my_strspn_test);
    tcase_add_test(tc1_1, my_strstr_test);
    tcase_add_test(tc1_1, my_strtok_test);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
