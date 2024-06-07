#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution
{
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n)
    {
        int ind = 0;
        while (ind < n)
        {
            char cache[4];
            int cache_size = read4(cache); // Number of characters actually read into cache
            if (cache_size == 0)
                break; // No more characters to read

            // Copy characters from cache to buf
            for (int i = 0; i < cache_size && ind < n; ++i)
            {
                buf[ind++] = cache[i];
            }
        }
        return ind;
    }
};

/*

// Mock implementation of read4
int read4(char *buf) {
    static const char *input = "HelloWorld";
    static int idx = 0;
    int i;
    for (i = 0; i < 4 && input[idx] != '\0'; ++i) {
        buf[i] = input[idx++];
    }
    return i;
}

class Solution {
public:
    
    //  * @param buf Destination buffer
    //  * @param n   Number of characters to read
    //  * @return    The number of actual characters read
     
int read(char *buf, int n)
{
    int ind = 0;
    while (ind < n)
    {
        char cache[4];
        int cache_size = read4(cache); // Number of characters actually read into cache
        if (cache_size == 0)
            break; // No more characters to read

        // Copy characters from cache to buf
        for (int i = 0; i < cache_size && ind < n; ++i)
        {
            buf[ind++] = cache[i];
        }
    }
    return ind;
}
}
;

int main()
{
    Solution solution;
    char buffer[20];
    int n = solution.read(buffer, 10);
    buffer[n] = '\0'; // Null-terminate the string
    std::cout << "Read " << n << " characters: " << buffer << std::endl;
    return 0;
}

*/