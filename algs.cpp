//
// Created by alla on 20.05.22.
//

#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility> //for swap

class Fibonacci final{

public:
    static int get(int n){
        assert(n >= 0);
        if (n == 0 || n == 1){
            return n;
        }
        static std::unordered_map<int, int> cache;
        auto &result = cache[n];
        if (result == 0){
            result = get(n - 2) + get(n - 1);
        }
        return result;
    }

    static int get2(int n){
        assert(n >= 0);
        // if use unordered_map t = 0.36 10% cpu
        static std::unordered_map<int, int> cache;
        cache[0] = 0;
        cache[1] = 1;
        for (int i = 2; i <= n; i++){
            cache[i] = cache[i - 2] + cache[i - 1];
        }

        return cache[n];
    }

    static int get3(int n){
        // if use vector - t = 0.02 1% cpu
        assert(n >= 0);

        static std::vector<int> cache;
        cache.resize(n + 1);
        cache[0] = 0;
        cache[1] = 1;
        for (int i = 2; i <= n; i++){
            cache[i] = cache[i - 2] + cache[i - 1];
        }


        return cache[n];
    }

    static int get4(int n){
        // use 2 vars t = 0.01s 0% cpu
        assert(n >= 0);
        if (n <= 1){
            return n;
        }
        int previous = 0;
        int current = 1;
        int next = 0;
        for (int i = 2; i <= n; i++){
            next = previous + current;
            previous = current;
            current = next;
        }


        return current;
    }
};


template <class Int>
Int gcd_euclid(Int a, Int b){
    assert(a > 0 && b > 0);

    while(b > 0){
        a %= b;
        std::swap(a, b);
    }
    return a;

    //recursive vers assert(a > 0); if (b > 0) return gcd_euclid(b, a % b), instead of while
}

//int main(){
//
//    std::int64_t a, b;
//    std::cout << "Enter 2 integers to find gcd:";
//    std::cin >> a >> b;
//    const int RUNS_COUNT = 100000;
//    for (int i = 0; i < RUNS_COUNT; i++){
//        gcd_euclid(a, b);
//    }
//    std::cout << gcd_euclid(a, b) << std::endl;
//
//    return 1;
//}