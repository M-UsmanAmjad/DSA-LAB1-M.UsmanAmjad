#include <iostream>
#include <string>
using namespace std;

int findPattern(string text, string pattern) {
    if (pattern.empty()) {
        return 0;
    }
    
    if (pattern.length() > text.length()) {
        return -1;
    }
    
    for (int i = 0; i <= text.length() - pattern.length(); i++) {
        bool found = true;
        for (int j = 0; j < pattern.length(); j++) {
            if (text[i + j] != pattern[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return i;
        }
    }
    
    return -1;
}

void testPatternMatching(string text, string pattern) {
    cout << "Text: \"" << text << "\"" << endl;
    cout << "Pattern: \"" << pattern << "\"" << endl;
    
    int result = findPattern(text, pattern);
    
    if (result == -1) {
        cout << "Pattern not found" << endl;
    } else {
        cout << "Pattern found at index: " << result << endl;
    }
    cout << "-------------------" << endl;
}

int main() {
    cout << "Task 8: String Pattern Matching (Naive Algorithm)" << endl;
    cout << "=================================================" << endl << endl;
    
    cout << "Test Case 1: Pattern at the beginning" << endl;
    testPatternMatching("hello world", "hello");
    
    cout << "Test Case 2: Pattern at the end" << endl;
    testPatternMatching("programming is fun", "fun");
    
    cout << "Test Case 3: Pattern not present" << endl;
    testPatternMatching("data structures", "python");
    
    cout << "Test Case 4: Empty pattern" << endl;
    testPatternMatching("algorithms", "");
    
    cout << "Test Case 5: Pattern in the middle" << endl;
    testPatternMatching("computer science", "puter");
    
    cout << "Test Case 6: Pattern longer than text" << endl;
    testPatternMatching("hi", "hello");
    
    cout << "Test Case 7: Repeated pattern" << endl;
    testPatternMatching("ababab", "ab");
    
    return 0;
}