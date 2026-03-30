/*
** EPITECH PROJECT, 2023
** B-ASM-400-MPL-4-1-asmminilibc-marlon.pegahi
** File description:
** tests_ffs_asm.c
*/

#include <criterion/criterion.h>

int ffs(int i);

Test(ffs, returns_index_of_first_set_bit)
{
    int i = 0b00100000;
    int result = ffs(i);

    cr_assert_eq(result, 6);
}

Test(ffs, returns_index_of_first_set_bit_1)
{
    int i = 0b00000000;
    int result = ffs(i);

    cr_assert_eq(result, 0);
}

Test(ffs, returns_index_of_first_set_bit_2)
{
    int i = 0b00000001;
    int result = ffs(i);

    cr_assert_eq(result, 1);
}

Test(ffs, returns_index_of_first_set_bit_3)
{
    int i = 0b00000010;
    int result = ffs(i);

    cr_assert_eq(result, 2);
}
