
#include <iostream>
#include <exception>
#include <cassert>


int bst(int a[], int start, int end, int target)
{
    assert(start<=end);

    if (start == end)
    {
        if(a[start] == end)
            return start;
        else
            return -1;     
    }

    int size = end - start + 1;
    int first_end = size /2 + start - 1;
    int second_start = first_end + 1; 

    if (target < a[first_end])
        return bst(a, start, first_end, target);
    else if (target == a[first_end])
        return first_end;
    else
        return bst(a, second_start, end, target);

    return -1;
}


int min_rotated_array(int a[], int start, int end)
{   
    int size = end - start + 1;
    int first_end = start + size / 2 -1;
    int second_start = first_end + 1;

    bool first_include_cliff = false;
    bool second_include_cliff = false;

    if(size == 2)
    {
        if(a[start] > a[end])
            return a[end];
        else
            throw std::runtime_error ("error 2nd");
    }

    if(size ==1)
        return a[start];

    if(a[start] <= a[first_end])
        first_include_cliff = false;
    else 
        first_include_cliff = true;

    if(a[second_start] <= a[end])
        second_include_cliff = false;
    else 
        second_include_cliff = true;

    if(!first_include_cliff && !second_include_cliff)
    {
        if(a[start] <= a[second_start])
            return a[start];
        else
        {
            return a[second_start];
        }
    }
    else if(first_include_cliff)
        return min_rotated_array(a, start, first_end);
    else if (second_include_cliff)
        return min_rotated_array(a, second_start, end);
    else
        throw std::runtime_error("error 1st");
}


int findmin(int a[], int start, int end)
{
    if(a[start] <= a[end])
    {
        return a[start];
    }
    int middle = (start + end) / 2;
    if(a[end] > a[middle])
    {
        return findmin(a, start, middle);
    } 
    else
    {
        return findmin(a, middle+1, end);
    }
}

int findmin_iteration(int a[], int start, int end)
{
    int start_it = start;
    int end_it = end;

    while (a[start_it] > a[end_it])
    {
        int middle = (start_it + end_it) / 2;
        if(a[end_it] > a[middle])
        {
            start_it = start_it;
            end_it = middle;
        } 
        else
        {
            start_it = middle+1;
            end_it = end_it;
        }
    }
    return a[start_it];
}


int main() {
    int t1[4] = {1, 2, 3, 4};
    int target = 1;
    int pos = bst(t1, 0, 3, target);

    int t2[] = {6, 8, 9, 11, 15, 20, 3, 4, 5};
    int min = findmin_iteration(t2, 0, 8); 

    int t3[] = {2, 1};
    int min2 = findmin_iteration(t3, 0, 1);
    return 0;

}
