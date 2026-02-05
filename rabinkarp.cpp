                                                                                                                                                                                                                                                                                #include <iostream>
#include <string>
using namespace std;

#define d 256      // number of characters
#define q 101      // a prime number

int main() {

    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    int n = text.length();
    int m = pattern.length();

    int h = 1;
    for(int i = 0; i < m-1; i++)
        h = (h * d) % q;

    int p = 0, t = 0;

    // Calculate initial hash values
    for(int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    cout << "Text: " << text << "\n";
    cout << "Pattern: " << pattern << "\n\n";
    cout << "Pattern found at index: ";

    for(int i = 0; i <= n - m; i++) {

        if(p == t) {
            bool match = true;

            for(int j = 0; j < m; j++) {
                if(text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }

            if(match)
                cout << i << " ";
        }

        if(i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if(t < 0) t = t + q;
        }
    }

    return 0;
}