#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

// ANSI Colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define BOLD    "\033[1m"

void printTitle() {
    cout << CYAN << BOLD;
    cout << "\n\n\t============================================\n";
    cout << "\t        DUPLICATE COUNTER ANALYZER\n";
    cout << "\t============================================\n\n" << RESET;
}

int main() {

start_program:

    printTitle();

    int n;
    cout << YELLOW << "Enter array size (2 - 20): " << RESET;
    cin >> n;

    while (n < 2 || n > 20) {
        cout << RED << "Invalid! Size must be between 2 and 20: " << RESET;
        cin >> n;
    }

    cin.ignore();

    cout << YELLOW << "Enter " << n << " numbers separated by spaces:\n" << RESET;

    vector<int> arr(n, 0);
    string line;
    getline(cin, line);

    stringstream ss(line);
    int count = 0;
    int temp;

    while (ss >> temp) {
        if (count < n)
            arr[count] = temp;
        count++;
    }

    bool extra = false;

    if (count > n) {
        extra = true;
        cout << RED << "\nWarning: You entered MORE numbers than required. Extra values ignored.\n" 
             << RESET;
    }

    if (count < n) {
        cout << YELLOW << "\nNotice: You entered LESS numbers. Remaining values filled with 0.\n"
             << RESET;
    }

    // -----------------------------------------
    //  DYNAMIC FRAME SIZE BASED ON EXACT WIDTH
    // -----------------------------------------

    // Build content string
    string content = "";
    for (int i = 0; i < n; i++) {
        if (extra && i == n - 1)
            content += string(RED) + "[" + to_string(arr[i]) + "] " + RESET;
        else
            content += string(CYAN) + "[" + to_string(arr[i]) + "] " + RESET;
    }

    // Remove last space for accuracy
    if (!content.empty() && content.back() == ' ')
        content.pop_back();

    // Count visible characters (ignore ANSI color codes)
    int visibleCount = 0;
    bool inColor = false;

    for (char c : content) {
        if (c == '\033') inColor = true;
        else if (inColor && c == 'm') inColor = false;
        else if (!inColor) visibleCount++;
    }

    int frameLength = visibleCount + 4; // padding
    string border = "+" + string(frameLength - 2, '-') + "+";

    cout << BOLD << "\nYour Array:\n" << RESET;
    cout << MAGENTA << border << "\n" << RESET;

    cout << MAGENTA << "|" << RESET << " ";
    cout << content;
    cout << MAGENTA << " |\n" << RESET;

    cout << MAGENTA << border << "\n\n" << RESET;

    // Method used
    cout << BLUE << BOLD << "Method Used:\n" << RESET;
    cout << "We store positions of each number using an unordered_map,\n";
    cout << "then check if repeated numbers appear in adjacent indices.\n\n";

    unordered_map<int, vector<int>> positions;

    for (int i = 0; i < n; i++) {
        positions[arr[i]].push_back(i);
    }

    cout << BLUE << BOLD
         << "---------------------------------------------\n"
         << "     SOLVING THE PROBLEM STEP BY STEP\n"
         << "---------------------------------------------\n\n" << RESET;

    int out = 0;

    cout << BOLD << "Storage Representation:\n\n" << RESET;

    for (auto &p : positions) {
        int num = p.first;
        vector<int> &pos = p.second;

        cout << GREEN << num << RESET << " -> [ ";

        bool all_adjacent = true;

        for (int i = 0; i < pos.size(); i++) {
            cout << CYAN << pos[i] << RESET;

            if (i < pos.size() - 1) {
                if (pos[i+1] == pos[i] + 1) {
                    cout << RED << " (adjacent) " << RESET;
                } else {
                    cout << GREEN << " (not adjacent) " << RESET;
                    all_adjacent = false;
                }
                cout << " , ";
            }
        }

        cout << " ]\n";

        if (pos.size() > 1 && !all_adjacent)
            out++;
    }

    cout << "\n\n" << MAGENTA << BOLD;
    cout << "=============================================\n";
    cout << "            FINAL REPORT\n";
    cout << "=============================================\n" << RESET;

    cout << CYAN << "Non-adjacent repeated numbers count = "
         << GREEN << out << RESET << "\n\n";

    // -----------------------------------------
    //   ASK USER TO RESTART OR EXIT
    // -----------------------------------------
    int choice;
    cout << YELLOW << "Press 1 to try again, or 0 to exit: " << RESET;
    cin >> choice;

    if (choice == 1) {

        cin.ignore();

        // cross-platform screen clear
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        goto start_program;
    }

    cout << GREEN << "\nGoodbye!\n" << RESET;
    system("pause");
    return 0;
}
