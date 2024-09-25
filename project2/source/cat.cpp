#include <string.h>
#include <stdio.h>

#include "cat.hpp"

char *Cat::get_pbreed()
{
        return pbreed;
}

uint32_t Cat::get_age()
{
        return age;
}

uint32_t Cat::get_weight()
{
        return weight;
}

char *Cat::get_pcolor()
{
        return &pbreed[idx_color];
}

char *Cat::get_pgender()
{
        return &pbreed[idx_gender];
}

uint32_t Cat::get_id()
{
        return i;
}

void Cat::set_breed(char *ptr)
{
        if (!ptr)
                return;

        pbreed = ptr;
}

void Cat::set_age(uint32_t a)
{
        age = a;
}

void Cat::set_weight(uint32_t w)
{
        weight = w;
}

void Cat::set_color(char *ptr)
{
        if (!ptr)
                return;

        strcpy(get_pcolor(), ptr);
}

void Cat::set_gender(char *ptr)
{
        if (!ptr)
                return;

        strcpy(get_pgender(), ptr);
}


void Cat::print()
{
        if (i == -1)
        {
                return;
        }
        printf("\nCat #%d:\n", get_id());
        printf("Breed: %s\n", get_pbreed());
        printf("Age: %d\n", get_age());
        printf("Weight: %d\n", get_weight());
        printf("Color: %s\n", get_pcolor());
        printf("Gender: %s\n", get_pgender());
}