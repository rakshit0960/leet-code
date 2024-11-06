class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [] (string a, string b) {
            int index1 = a.find(" ");
            string id1 = a.substr(0, index1);
            string main1 = a.substr(index1 + 1);
            
            int index2 = b.find(" ");
            string id2 = b.substr(0, index2);
            string main2 = b.substr(index2 + 1);    

            bool isDigit1 = isdigit(main1[0]); 
            bool isDigit2 = isdigit(main2[0]);

            if (!isDigit1 && !isDigit2) {
                if (main1 == main2) return id1 < id2; 
                else return (main1 < main2);
            }
            else if (!isDigit1 && isDigit2) {
                return true;
            } else if (isDigit1 && !isDigit2) {
                return false;
            } else 
                return false;

        });

        return logs;
    }
};