/*
 * Класс Cls определен точно таким образом:
 *
 * struct Cls {
 * Cls(char c, double d, int i);
 * private:
 *     char c;
 *     double d;
 *     int i;
 * };
 *
 */


struct Cls {
    Cls(char c, double d, int i);
private:
    //struct is allocated in memory according to max size of its fields = (double) 8 bytes
    char c; // size = 1 byte (+ 7padding) = 8 bytes offset for the next field (1 * 8)
    double d; //size = 8 bytes
    int i; // 16 bytes offset, or 2 points offset for double (2 * 8)
};

// Эта функция должна предоставить доступ к полю c объекта cls.
// Обратите внимание, что возвращается ссылка на char, т. е.
// доступ предоставляется на чтение и запись.
char &get_c(Cls &cls) {
    return *((char *)&cls);
}

// Эта функция должна предоставить доступ к полю d объекта cls.
// Обратите внимание, что возвращается ссылка на double, т. е.
// доступ предоставляется на чтение и запись.
double &get_d(Cls &cls) {
    return *((double *)&cls + 1); // return *(double *)((char *)&cls + 8)
}

int &get_i(Cls &cls) {
    return *((int *)((double *) &cls + 2));// return *(int *)((char *)&cls + 16)
}

/*
 * or:
 * struct Cls_clone{
 * Cls_clone(char c, double d, int i);
 * char c;
 * double d;
 * int i;
 * };
 *
 * then
 *
 * 'new (&cls) Cls_clone' will create Cls_clone object at the cls site, and as
 * it the very same structure, one can use it
 * char &get_c(Cls &cls) {
     return (new (&cls) Cls_clone)->c;
    }

 * */