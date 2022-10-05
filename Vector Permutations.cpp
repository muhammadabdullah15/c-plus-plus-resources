#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using std::copy;
using std::cout;
using std::endl;
using std::vector;

void permutations_recursive(const vector<char> &elems, unsigned long req_len,
                            vector<unsigned long> &pos, vector<bool> &used,
                            unsigned long depth)
{
    // Have we selected the number of required elements?
    if (depth >= req_len)
    {
        for (unsigned long ii = 0; ii < pos.size(); ++ii)
            cout << elems[pos[ii]];
        cout << endl;
        return;
    }

    // Try to select previously unused elements.
    for (unsigned long ii = 0; ii < elems.size(); ++ii)
    {
        if (!used[ii])
        {
            used[ii] = true;
            pos[depth] = ii;
            permutations_recursive(elems, req_len, pos, used, depth + 1);
            used[ii] = false;
        }
    }
    return;
}

void permutations(const vector<char> &elems, unsigned long req_len)
{
    assert(req_len > 0 && req_len <= elems.size());
    vector<unsigned long> positions(req_len, 0);
    vector<bool> used(elems.size(), false);
    permutations_recursive(elems, req_len, positions, used, 0);
}

const unsigned long num_elements = 5;
const unsigned long perm_len = 3;

int main()
{
    vector<char> elements(num_elements);
    char elements_str[num_elements + 1] = "abcde";
    copy(elements_str, elements_str + num_elements, elements.begin());

    permutations(elements, perm_len);
    return 0;
}