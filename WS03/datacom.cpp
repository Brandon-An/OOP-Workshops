#include <cstdio>
#include <iostream>
#include <cstring>

char bits[16] = {"011111101111110"};
char flag[9] = {"01111110"};
int cons_count;
int length = 16;

int main()
{
    std::cout << "Before Stuffing: " << bits << " -- 15 Characters" << std::endl;
    std::cout << "After Stuffing: ";
    int i;
    for (i = 0; i < length; i++)
    {
        if (bits[i] == '1')
        {
            cons_count++;
        }
        if (cons_count == 6)
        {
            std::cout << "0";
            cons_count = 0;
        }
        std::cout << bits[i];
    }

    std::cout << " --17 Characters" << std::endl;

    std::cout << "After Framing: " << flag << bits << flag;
}

// int bits[17] = {0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0 ,0};
// int flag[8] = {0, 1, 1, 1, 1, 1, 1, 0};
// int b_length = 15;
// int f_length = 8;
// int c_flag = 0;

// void stuffing(int *);
// int *insert(int n, int arr[], int x, int pos);
// void display(int*, int);

// void stuffing(int *bits)
// {
//     int i;
//     for (i = 0; i < b_length; i++)
//     {
//         if (bits[i] == 1)
//         {
//             if (bits[i + 1] != 1)
//             {
//                 break;
//             }
//             if (bits[i + 2] != 1)
//             {
//                 break;
//             }
//             if (bits[i + 3] != 1)
//             {
//                 break;
//             }
//             if (bits[i + 4] != 1)
//             {
//                 break;
//             }
//             insert(b_length, bits, c_flag, i);
//         }

//     }
// }

// int *insert(int n, int arr[], int x, int pos)
// {
//     int i;

//     // increase the size by 1
//     //n++;

//     // shift elements forward
//     for (i = n; i > pos+5; i--)
//         arr[i] = arr[i - 1];

//     // insert x at pos
//     arr[pos + 5 ] = x;
//     return arr;
// }

// void display(int* arr, int len)
// {
//     int i;
//     for (i = 0; i < len; i++)
//     {
//         std::cout << arr[i];
//     }
// }

// int main()
// {
//     std::cout << "Before Stuffing: ";
//     display(bits, b_length);
//     std::cout << " -- 15 Characters" << std::endl;

//     stuffing(bits);

//     std::cout << "After Stuffing: ";
//     display(bits, b_length);
//     std::cout << " -- 17 Characters" << std::endl;

//     std::cout << "After Stuffing: ";
//     display(bits, b_length);
//     std::cout << " -- 17 Characters" << std::endl;

//     return 0;
// }