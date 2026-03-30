/*
** EPITECH PROJECT, 2023
** B-ASM-400-MPL-4-1-asmminilibc-marlon.pegahi
** File description:
** test_tests_memmove_asm.c
*/

#include <criterion/criterion.h>

void *memmove(void *dest, const void *src, size_t n);

Test(memmove, change_correctly_bytes_1) {
    char str[13] = "hello world";

    memmove(str + 2, str, 5);
    cr_assert_str_eq(str, "hehelloorld");
}

Test(memmove, returns_correct_pointer) {
    char str[13] = {0};
    char str2[13] = {0};

    for (int i = 0; i != 13; i++)
        str2[i] = 'r';

    cr_assert_eq(memmove(str, str2, 13), &str[0]);
}

Test(memmove, change_correctly_bytes_2) {
    char str[13] = {0};
    char str2[13] = {0};

    for (int i = 0; i != 13; i++)
        str2[i] = 'r';

    memmove(str, str2, 13);
    cr_assert_eq(strncmp(str, str2, 13), 0);
}
