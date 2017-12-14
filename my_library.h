#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

/*
 * 1) Print Fucntions
 * 2) Initialize Arrays
 * 3) Search Functions
 * 4) String Manipulation
 * 5) Array Manipulation
 */

//1) Print Fucntions
void debug_intermit_print();
template <class T>
void print_array(T* a, int size);
void print_cstring(char *s);

//2) Initialize Arrays
template <class T>
void print_2d_array(T** array, int* size_of_rows);
template <class T>
T** init_2d_array_dynamic(T fill_with, int* array);

//3) Search Functions
template <class T>
int search_array(T* array, T target);
template <class T>
void search_2d_array(T** array, int* size_of_rows, T target, int &row_loci, int &column_loci);
template <class T>
T& get_2d_array(T** array, int row_loci, int column_loci);//new version

//4) String Manipulation
template <class T>
void my_swap(T& a, T& b);
void reverse_cstring(char s[]);
void copy_n_rev_char(char dest[], char src[]);
template <class T>
void copy_n_rev_not_char(T dest[], T src[]);
int ascii_to_int(char input);
char int_to_ascii(int input);

//5) Array Manipulation
void pad_right(char s[], int size_to_be);
template <class T>
T* allocate(int capacity);
template <class T>
T* copy_list(T* primary_list, int capacity);
template <class T>
T* re_allocate(T* primary_list, int old_capacity, int new_capacity);
template <class T>
void negate_array(T* array, int size); //multiply all elements by (-1) => only for ints or doubles


// Template Implementation
template <class T>
void print_array(T* a, int size){
    cout << endl << "==========================" << endl;
    int i = 0;
    while(i < size){
        cout << a[i] << " ";
        i++;
    }
    cout << endl << "==========================" << endl;
}
template <class T>
void print_2d_array(T** array, int* size_of_rows){
    int rows = sizeof(array);
    for (int i = 0; i < rows; i++, array++, size_of_rows++){
        T* extra_two_d_walker = *array;
        cout << endl;
        for (int j = 0; j < *size_of_rows; j++, extra_two_d_walker++){
            cout << *extra_two_d_walker << "  ";
        }
    }
}
template <class T>
T** init_2d_array_dynamic(T fill_with, int* array){
/*
 * I:
 * - number of rows
 * - value to fill initialized 2d array with
 * - array containing size of respective rows of 2d array
 * O:
 * - double pointer (containing 2d array)
 * The Point:
 * - initialize any dynamic 2d array
 */
    int size = sizeof(array);
    T** two_d_array = new int*[size];
    T** two_d_ptr_walker = two_d_array;
    T* extra_two_d_walker;
    for (int i = 0; i < size; i++, two_d_ptr_walker++, array++){
        *two_d_ptr_walker = new int[*array];
        extra_two_d_walker = *two_d_ptr_walker;
        for (int j = 0; j < *array; j++, extra_two_d_walker++){
            *extra_two_d_walker = fill_with;
        }
    }
    return two_d_array;
}
template <class T>
int search_array(T* array, T target){
/*
 * I:
 * - single pointer (pointing to array)
 * - target value to search for
 * - number of rows
 * O:
 * - int variable
 * The Point:
 * - searches through array until finds target
 * - saves index of target in variable
 */
    int size = sizeof(array);
    for (int i = 0; i < size; i++, array++){
        if (*array == target){
            int location = i;
            return location;
        }
        else{
            int location = -1;
            return location;
        }
    }
}
template <class T>
void search_2d_array(T** array, int* size_of_rows, T target, int &row_loci, int &column_loci){
/*
 * I:
 * - double pointer (containing array of pointers)
 * - single pointer (contains array; size of array mirrors size of double pointer array, contents are respective sizes
 *      of arrays each pointer in double pointer points to)
 * - target value to search for
 * - single pointer (contains 0 until search has a hit)
 * - number of rows
 * O:
 * - none
 * The Point:
 * - contains first for loop of search through double pointer array of pointers to arrays (2d array)
 */
    int rows = sizeof(array);
    for (int i = 0; i < rows; i++, array++, size_of_rows++){
        T* extra_walker = *array;
        for (int j = 0; j < *size_of_rows; j++, extra_walker++){
            if (target == *extra_walker){
                row_loci = i;
                column_loci = j;
                break;
            }
        }
    }
}
template <class T>
T& get_2d_array(T** array, int row_loci, int column_loci){
/*
 * used for both read and write
 */
    return *(*(array + row_loci) + column_loci);
}
template <class T>
void my_swap(T& a, T& b){
    int temp = a;
    a = b;
    b = temp;
}
template <class T>
void copy_n_rev_not_char(T dest[], T src[]){
    int size = sizeof(src);
    int i = 0;
    for (int j = size - 1; j >= 0; j--){
        dest[i] = src[j];
        i++;
    }
}
template <class T>
T* allocate(int capacity){
    const bool debug = false;
    T* array = new T[capacity];
    for (int i = 0; i < capacity; i++){
        array[i] = T();
    }
    if (debug){
        print_array(array, capacity);
    }
    return array;
}
template <class T>
T* copy_list(T* primary_list, int capacity){
    T* new_list = allocate <T>(capacity);
    for (int i = 0; i < capacity; i++){
        new_list[i] = primary_list[i];
    }
    return new_list;
}
template <class T>
T* re_allocate(T* primary_list, int old_capacity, int new_capacity){
    const bool debug = false;
    T* new_list = allocate<T>(new_capacity);
    if (debug){
        print_array(new_list, new_capacity);
    }
    int pick_capacity = min(old_capacity, new_capacity);
    for (int i = 0; i < pick_capacity; i++){
        new_list[i] = primary_list[i];
    }
    return new_list;
}
template <class T>
void negate_array(T* array, int size){
    int neg_val = -1;
    for (int i = 0; i < size; i++){
        array[i] *= neg_val;
    }
}

#endif // MY_LIBRARY_H
