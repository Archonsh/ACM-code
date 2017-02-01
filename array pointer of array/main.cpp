/*
 * (*ptr)[2] is a pointer which points to an array of LENGTH 2
 * so each increment is equal to 2*sizeof(int) = 8 bit
 *
 * Warning:
 *   (*ptr)[2]    is NOT EQUAL to    *ptr[2]
 * array pointer                  pointer array
 *
 *
 * -----!!!!!!------------
 * array[0] = &array[0][0]
 * -----!!!!!!------------
 */

#include <cstdio>

int main()
{
    int  array[4][2] = {{1,2},{3,4},{5,6},{7,8}};
    int  (*ptr)[2];
    int  (**dptr)[2];
    ptr = array;

    dptr = &ptr; // pointing to the address ptr points to

//    printf("%p\n",ptr);
//    printf("%p\n",&ptr);
//    printf("%p\n%p\n",,array[0]);
    int i,j;
    for (j = 0; j < 4; ++j)
    {
        for (i = 0; i<2; ++i)
        {
              printf("%p\n%p\n%p\n",ptr,array[0],*ptr);
              printf("%p\n", *dptr + j);                 //*dptr+j = ptr+j = &array[0]+j
              printf("%p\n", *(*dptr+j) + i );           //*(*dptr+j)+i = *(ptr+j)+i = *(&array[j])+i = array[j]+i = &array[j][0]+i
              printf("%d\n", * ( *(*dptr+j) + i ));      //*(&array[j][0]+i)= *&array[j][i] = array[j][i]

        }
    }
    return 0;
}