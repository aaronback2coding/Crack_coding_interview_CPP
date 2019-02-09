
#include <iostream>
#include <exception>
#include <cassert>


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

void Merge (int* a, int first_start, int first_end, int second_start, int second_end)
{
    assert(first_end >= first_start);
    assert(second_end >= second_start);
    assert(second_start - first_end == 1);

    
    int first_array [first_end - first_start];
    int second_array [second_end - second_start];
    for (int i = first_start; i <=first_end; i++)
        first_array[i - first_start] = a[i];
    for (int i = second_start; i <= second_end; i++)
        second_array[i - second_start] = a[i]; 


    int first_it = 0;
    int first_size = first_end - first_start + 1;
    int second_it = 0;
    int second_size = second_end - second_start + 1;

    int i = 0;
    bool first_notfinished = (first_size > first_it) ;
    bool second_notfinsihed = (second_size > second_it);

    while(first_notfinished || second_notfinsihed)
    {
        if(first_notfinished && second_notfinsihed)
        {
            if(first_array[first_it] <= second_array[second_it])
            {
                a[i] = first_array[first_it];
                first_it ++;
            }
            else
            {
                a[i] = second_array[second_it];
                second_it ++;
            }
        }
        else if(first_notfinished && !second_notfinsihed)
        {
            a[i] = first_array[first_it];
            first_it ++;
        }
        else if(!first_notfinished && second_notfinsihed)
        {
            a[i] = second_array[second_it];
            second_it ++;
        }
        first_notfinished = (first_size > first_it);
        second_notfinsihed = (second_size > second_it);
        i++;
    }
}
void MergeSort (int* a, int start, int end)
{
    int size = end  - start + 1;
    if(size == 1)
        return;
    if(size == 2)
    {
        if(a[start]>a[start+1])
        {
            int temp = a[start];
            a[start] = a[start+1];
            a[start+1] = temp;
        }
        return;
    }
    int first_end = size/2 + start - 1;
    int second_start = first_end + 1;
    MergeSort(a, start, first_end);
    MergeSort(a, second_start, end);
    Merge(a, start, first_end, second_start, end);
}




int main() {


    int t1[2] = {1, 2};
    MergeSort(t1, 0, 1);

    int t2[3] = {1, 2, 3};
    MergeSort(t2, 0, 2);

    int t3[4] = {4, 3, 2, 1};
    MergeSort(t3, 0, 3);

    int t4[4] = {1, 3, 2, 4};
    MergeSort(t4, 0, 3);


    return 0;
   
   
}
