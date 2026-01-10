# Pointers in C revision

> ### Program 1

int,float etc store specific values. Likewise Pointers are variables that stores addresses.

```
        int num = 10;
        
        int *ptr1 = NULL;
        int **ptr2 = NULL;
        
        ptr1 = &num;
        ptr2 = &ptr1;

        /* or
            int num = 10;
            int b = 7;
            
            int *ptr1 = NULL;
            int **ptr2 = &ptr1;
            
            ptr1 = &num;
            **ptr2 = b; // this is only allowed if ptr2 is already initialised previously.
        */
        
        printf("\n num = %d", num);
        printf("\n add of int var (&num)= %x", &num);
        printf("\n value at ptr1 var (ptr1)= %x", ptr1);;
        printf("\n dereferencing ptr1 var (*ptr1) = %d", *ptr1);
        printf("\n address of ptr1 variable (&ptr1) = %x", &ptr1);
        
        printf("\n value at ptr2 variable (ptr2) = %x", ptr2);
        printf("\n dereferencing ptr2 var (*ptr2) = %x", *ptr2);
        printf("\n double dereferencing ptr2 var (**ptr2) = %d", *(*ptr2));
```

> **Output:**

    num = 10
    add of int var (&num)= 13e21a64
    value at ptr1 var (ptr1)= 13e21a64
    dereferencing ptr1 var (*ptr1) = 10
    address of ptr1 variable (&ptr1) = 13e21a58
    value at ptr2 variable (ptr2) = 13e21a58
    dereferencing ptr2 var (*ptr2) = 13e21a64
    double dereferencing ptr2 var (**ptr2) = 10

---

### Program 2 

in arrays arr is same as &arr. so using a pointer to array is also the same, except that pointer is dynmic & ++ can be used in it.

> **Pointers with array**

```  
    #include <stdio.h>

    int main()
    {

        int arr[] = {12,56,33,68};
        int* ptr1;
        
        ptr1 = arr + 1;
        
        printf("\n arr[1] = %d", arr[1]);
        printf("\n 0[a] = %d", 0[arr]);
        printf("\n *ptr1 = %d", *ptr1);
        printf("\n *ptr1-1 = %d", *(ptr1-1));
        printf("\n *arr+1 = %d", *(arr + 1));

        
        printf("\n\n arr = %x", arr);
        printf("\n arr+1 = %x", arr+1);
        printf("\n ptr1 = %x", ptr1);
        
        printf("\n\n *ptr1 = %d", *(ptr1));
        printf("\n *ptr1++ = %d", *(ptr1++));
        printf("\n *ptr1 = %d", *(ptr1));
        // cannot write arr++ (i.e arr = arr+1), we cannot change base address

        return 0;
    }
```

>**Output:**

    arr[1] = 56
    0[a] = 12
    *ptr1 = 56
    *ptr1-1 = 12
    *arr+1 = 56

    arr = 8d97fa20
    arr+1 = 8d97fa24
    ptr1 = 8d97fa24

    *ptr1 = 56
    *ptr1++ = 56
    *ptr1 = 33

---

>### Pointers with functions

1) Call by value & call by reference.

```
    int swap(int *x, int *y)
    {
        int temp;
        temp = *x;
        *x = *y;
        *y = temp;
    }

    void main(){
        ....
        swap(&a,&b); // or swap(p1,p2); where *p1 = a & *p2 = b;
    }
```

2) Returning a pointer from a function
```
    int* larger(int *x, int *y)
    {
    if(*x > *y)
        return x;
    else
        return y;
    }

    void main(){
        ...
        int *p;
        p = larger(&a, &b);
    }
```

3) Function pointers
```
    int larger(x, y)
    {
    if(x > y)
        return x;
    else
        return y;
    }

    void main(){
        ...
        /* For fp replace func name with a pointer variable.*/

        int *fp(int,int); //int (*fp) (int,int)
        int largestNo = l(a,b);
    }
```

> 4) Combining everything

`void *(*foo) (int*);`

In this case (*foo) is a pointer to the function, whose argument is of int* type and return type is void*.

### void pointers & conversion

```
    #include <stdio.h>

    void pass(void *ptr){
        
        // first cast void ptr into int pointer
        // now pointer will hold address of a; Derefernce it to print value at-address of a
        int *pointer = (int*) ptr;  
        
        printf("\n\n pointer = %x",pointer);   
        printf("\n *pointer = %d",*pointer);
        
        printf("\n\n ptr = %x",ptr);   

        // printf("\n %d", *ptr); // will result in error, as it is a void ptr
    }

    int main()
    {

        int a = 10;
        void *ptr;
        ptr = &a;
        
        printf("\n &a = %x",&a);
        printf("\n (int*)(ptr) = %x ",(int*)(ptr));    // convert address from void* to int*
        printf("\n *((int*)(ptr)) = %x ",*((int*)(ptr)) ); // derefence to get value

        pass(ptr);

        return 0;
    }
```

> Output:

    &a = 71648aa4
    (int*)(ptr) = 71648aa4 
    *((int*)(ptr)) = a 

    pointer = 71648aa4
    *pointer = 10

    ptr = 71648aa4


___

# Structures

### Structure declaration

> **Method 1:**
```
    struct data{
        int id;
        int totalTime;
    };
```
Wherever we need to create a varaible, we can call struct data Frame1; (same as int Frame1)

> **Method 2:**

```
    struct data{
        int id;
        int totalTime;
    }Frame1; // (or) Frame[3]
```
varaibles are already created.

> **Method 3:**

`typedef struct data{int id;int totalTime;} frame;`

- We can use typedef, so that we don't need to write struct data everywhere.
- Think whatever in between as one line. So whatever in between typedef & ; is called with the last identifier.