//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
      if (arr.empty()) return 0;

    unordered_set<int> st(arr.begin(), arr.end());
    int longestStreak = 0;

    for (int num : arr) {
        if (st.find(num - 1) == st.end()) {
            int currentNum = num;
            int currentStreak = 1;
            while (st.find(currentNum + 1) != st.end()) {
                currentNum++;
                currentStreak++;
            }

            longestStreak = max(longestStreak, currentStreak);
        }
    }

    return longestStreak;
  }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends