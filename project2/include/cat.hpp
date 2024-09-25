#pragma once

#include <stdint.h>

class Cat
{
public:
        Cat()
        {
                i = -1;
        }

        Cat(
                uint32_t i,
                char *pbreed, 
                uint32_t age, 
                uint32_t weight, 
                uint32_t idx_color, 
                uint32_t idx_gender) 
        {
                this->i = i;
                this->pbreed = pbreed;
                this->age = age;
                this->weight = weight;
                this->idx_color = idx_color;
                this->idx_gender = idx_gender;
        }

        uint32_t get_id();
        char *get_pbreed();
        uint32_t get_age();
        uint32_t get_weight();
        char *get_pcolor();
        char *get_pgender();

        void print();

        void set_breed(char *ptr);
        void set_age(uint32_t age);
        void set_weight(uint32_t weight);
        void set_color(char *ptr);
        void set_gender(char *ptr);

private:
        uint32_t i;
        char *pbreed;
        uint32_t age, weight; 
        uint32_t idx_color;
        uint32_t idx_gender;
};