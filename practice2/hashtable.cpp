#include <iostream>
#include <string>
#include <unordered_map>

//a3+b3 = c3+d3 <=20

struct pair
{
    int a = 0;
    int b = 0;
};

void printmatch(int n)
{
    std::unordered_map<int,pair> hm;

    for(int i = 0; i<n; i++)
        for(int j = i; j<n; j++)
        {
            int sum = i*i*i + j*j*j;

            std::unordered_map<int,pair>::const_iterator match_it = hm.find (sum);
            if(match_it != hm.end())
            {
                if (i + j != match_it->second.a + match_it->second.b )
                    std::cout << "Found matching pairs: " << i << " ,  " << j << " and " <<match_it->second.a << " ,  " << match_it->second.b  << "\n"; 
            }
            else
            {
                pair p;
                p.a = i;
                p.b = j;
                hm.emplace(sum, p);
            }
        }

}

int main ()
{
    printmatch (20);
    return 0;
}