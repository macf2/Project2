#include <string>
#include <iostream>
#include <vector>

#include "queue.hpp"
#include "cat.hpp"
#include "stack.hpp"

char *read_file(char *ppath)
{
        if (!ppath)
                return NULL;
        
        FILE *fptr;
        if ((fptr = fopen(ppath, "r")) == NULL)
                return NULL;
        
        if (fseek(fptr, 0, SEEK_END))
                return NULL;
        
        long sz = ftell(fptr);
        rewind(fptr);

        char *pfile = (char *)malloc(sz + 1);
        pfile[sz] = '\0';

        fread(pfile, 1, sz, fptr);

        fclose(fptr);
        return pfile;
}

void parse_data(char *pfile, std::vector<Cat> &cats)
{
        // skip header
        while (*pfile++ != '\n')
                ;

        while (*pfile != '\0')
        {
                uint32_t i = atoi(pfile);

                while (*pfile++ != ',')
                        ;

                char *pbreed = pfile;

                while (*pfile++ != ',')
                        ;
                pfile[-1] = '\0';

                uint32_t age = atoi(pfile);

                while (*pfile++ != ',')
                        ;
                
                uint32_t weight = atoi(pfile);

                while (*pfile++ != ',')
                        ;

                uint32_t idx_color = pfile - pbreed;

                while (*pfile++ != ',')
                        ;
                pfile[-1] = '\0';

                uint32_t idx_gender = pfile - pbreed;

                while (*pfile++ != '\n')
                        ;
                pfile[-1] = '\0';
        
                cats.emplace_back(Cat(
                        i++,
                        pbreed,
                        age,
                        weight,
                        idx_color,
                        idx_gender
                ));
        }
}

int main()
{
        std::vector<Cat> cats;
        char *pfile = read_file("cats_dataset.csv");
        if (!pfile)
                return -1;

        parse_data(pfile, cats);

        auto int_queue = Queue<int>();
        auto string_queue = Queue<std::string>();
        
        int_queue.enqueue(100);
        int_queue.dequeue();
        int_queue.enqueue(10);
        int_queue.enqueue(90);
        int_queue.enqueue(69);
        int_queue.print();

        string_queue.enqueue("hello");
        string_queue.dequeue();
        string_queue.enqueue("goodbye");
        string_queue.print();

        auto cat_queue = Queue<Cat>();
        auto cat_stack = Stack<Cat>();

        for (uint32_t i = 0; i < 10; i++)
        {
                Cat c = cats[i];
                c.print();
                cat_queue.enqueue(c);

        }

        for (uint32_t i = 0; i < 10; i++)
        {
                cat_stack.push(cat_queue.dequeue());
        }

        for (uint32_t i = 0; i < 10; i++)
        {
                cat_stack.pop().print();
        }



        return 0;        
}