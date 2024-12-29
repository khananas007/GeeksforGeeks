//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
       unordered_map<int,pair<int,bool>>m;
       for(int i=0;i<a.size();i++){
           m[a[i]].first++;
       }
       for(int i=0;i<b.size();i++){
           if(m.find(b[i])!=m.end()){
               m[b[i]].second=true;
           }
       }
       vector<int>ans;
       for(auto p:m){
           if(p.second.second==true){
               ans.push_back(p.first);
           }
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1, arr2;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        Solution ob;
        vector<int> res = ob.intersectionWithDuplicates(arr1, arr2);
        sort(res.begin(), res.end());

        if (res.size() == 0) {
            cout << "[]" << endl;
        } else {
            for (auto it : res)
                cout << it << " ";
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends