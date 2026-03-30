/*
** EPITECH PROJECT, 2023
** B-ASM-400-MPL-4-1-asmminilibc-marlon.pegahi
** File description:
** test_tests_memcpy_asm.c
*/

#include <criterion/criterion.h>

void *memcpy(void *dest, const void *src, size_t n);

Test(memcpy, returns_correct_pointer) {
    char str[13] = {0};
    char str2[13] = {0};

    for (int i = 0; i != 13; i++)
        str2[i] = 'r';

    cr_assert_eq(memcpy(str, str2, 13), &str[0]);
}

Test(memcpy, change_correctly_bytes) {
    char str[13] = {0};
    char str2[13] = {0};

    for (int i = 0; i != 13; i++)
        str2[i] = 'r';

    memcpy(str, str2, 13);
    cr_assert_eq(strncmp(str, str2, 13), 0);
}
