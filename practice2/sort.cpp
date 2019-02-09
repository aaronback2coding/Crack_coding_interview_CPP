
#include <iostream>
#include <exception>

void QuickSort (int* a, int start, int size)
{
    if(size <= 1)
        return;
    //pick pivot (using last)
    int pivot = a[start + size - 1];
    int left_it = start;
    int right_it = start + size - 1;

    //swap all
    bool left_found = false;
    bool right_found = false;
    bool lastmove = false; //true is left, false is right.

    while (left_it < right_it)
    {

        if(a[left_it] <= pivot)
        {
            left_it++;
            lastmove = true;
            continue;
        }
        else
        {
            left_found = true;
        }
      
        if(a[right_it] > pivot)
        {
            right_it--;
            lastmove = false;
            continue;
        }
        else
        {
            right_found = true;
        }

        //swap
        if (left_found && right_found)
        {
            int temp = a[left_it];
            a[left_it] = a[right_it];
            a[right_it] = temp;
            left_found = false;
            right_found = false;
        }
    }

    int left_size = 0;;
    int right_size = 0;

    if(a[left_it] <= pivot)
    {
        left_size = left_it - start + 1;
    }
    else
    {
        left_size = left_it - start;
    }
    if (left_size == size)
        left_size--;
    right_size = size - left_size;
   
    QuickSort(a, start, left_size); 
    QuickSort(a, start + left_size, right_size);
    
};


int main() {


    int b[7] = {1, 2};
    QuickSort(b, 0, 2);


    int a[6] = {1, 11, 6, 88, 3, 4};
    QuickSort(a, 0, 6);

    return 0;
   
   
}
