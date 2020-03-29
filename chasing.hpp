#ifndef CHASING_HPP
#define CHASING_HPP

#include <iostream> 
#include <string>
#include <algorithm> // std::remove

#define SIZE 64

void chasing(int **A[], int a, int *B[], int b, int C[], int c) {
    std::string line;
    char letter1, letter2, remainder[SIZE];
    int n, m;

    while (getline(std::cin, line)) {
        /* str.erase() erases a part of the string content, shortening the length */
        /* std::remove(first, last, value to be removed), returns an interator to the element that follows the last element not removed */
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end()); // erase(begin to erase, end to erase)
        int ret = sscanf(line.c_str(), "%c%d%c%d%s", &letter1, &n, &letter2, &m, remainder);
        bool isCorrect = !(ret != 4 || n < 0 || m < 0);

        if (isCorrect) {
            if (letter1 == 'A' && letter2 == 'B' && n < a && m < b)
                A[n] = &B[m];
            else if (letter1 == 'B' && letter2 == 'C' && n < b && m < c)
                B[n] = &C[m];
            else
                isCorrect = false;
        }
        std::cout << isCorrect << std::endl;
    }
}

#endif