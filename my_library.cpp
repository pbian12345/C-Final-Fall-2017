#include <iostream>
#include <cstring>

using namespace std;
//typedef int T;



void debug_intermit_print(){
    cout << endl << endl << "=========================" << endl;
    cout << "Code executed." << endl;
    cout << "=========================" << endl << endl;
}
void print_cstring(char* s){
    cout << endl << "======================" << endl;
    for(int i = 0; s[i] != '\0'; i++){
        cout << s[i];
    }
    cout << endl << "======================" << endl;
}
int* init_int_1d_array_dynamic(int rows){
/*
 * I:
 * - number of rows
 * O:
 * - 1d int array
 * The Point:
 * - initialization fcn for any given 1d int dynamic array
 * - main reason I have one of these specifically for ints is for direct use in
 *      my 2d array (needs int)
 *      if I use typedef, what if I use string for typedef? I still need an int array...
 */
    const bool debug = true;
    int* array = new int[rows];
    int* array_walker = array;
    for (int i = 0; i < rows; i++, array_walker++){
        *array_walker = -1;
    }
    if (debug){
        array_walker = array;
        for (int i = 0; i < rows; i++, array_walker++){
            cout << *array_walker << " ";
        }
        cout<<endl;
    }
    return array;
}
void reverse_cstring(char* s){
    const bool debug = false;
    if (debug) cout<<"reverse_cstring: TOP s: " << s << endl;
    int size = strlen(s);
    char* s_walker = s;
    s_walker = s_walker + size - 1;
    for (int i = 0; s <= s_walker; i++, s++, s_walker--){
        swap(*s, *s_walker);
    }
    if (debug) cout << "reverse_cstring: BOTTOM s: "<< s << endl;
}
void copy_n_rev_char(char* dest, char* src){
    int size = strlen(src);
    int i = 0;
    for (int j = size - 1; j >= 0; j--){
        dest[i] = src[j];
        i++;
    }
    dest[i] = '\0';
}
int ascii_to_int(char input){
    int output = -1;
    char conv_search[] = "0123456789ABCDEF";
    for (int i = 0; i <= strlen(conv_search); i++){
        if (output != -1){
            break;//if search gets hit, ends search on next iteration
        }
        else if (conv_search[i] == input){
            output = i;
        }
    }
    return output;
}
char int_to_ascii(int input){
    char output = ' ';//Armen made me uncomfortable with using any variable not first cleared of any junk
    char conv_search[] = "0123456789ABCDEF";
    output = conv_search[input];
    return output;
}
void pad_right(char* s, int size_to_be){
    int size_of_src = strlen(s);
    for (int i = size_of_src + 1; i <= size_to_be; i++){
        //i starts where NULL is and will continue to increase until desired length
        //s[i] = '0';
        strcat(s, "0");
        s[i+1] = '\0';
    }
}
