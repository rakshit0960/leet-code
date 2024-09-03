class Solution {
public:
    string validIPAddress(string queryIP) {
        const int n = queryIP.size();
        bool hasPeriod = false, hasColon = false;
        for (char ch : queryIP) {
            if (ch == '.') hasPeriod = true;
            if (ch == ':') hasColon = true;
        }
        if (hasPeriod && hasColon) return "Neither";
        if (!hasPeriod && !hasColon) return "Neither";

        if (hasPeriod) {
            int sectionCount = 0;
            int s = 0;
            for (int e = 0; e <= n; e++) {
                if (e != n) {
                    if (queryIP[e] != '.') continue;
                }
                // either e == n || e != n And q[e] == '.'
                if (e == s || e - s > 3) return "Neither";

                string curr = "";
                for (int i = s; i < e; i++) {
                    // symbols
                    if (queryIP[i] < '0' || queryIP[i] > '9') return "Neither";
                    curr += queryIP[i];
                }
                // leading zeros
                if (curr.size() > 1 && curr[0] == '0') return "Neither";
                int num = stoi(curr);

                // num out of range
                if (num < 0 || num > 255) return "Neither";
                sectionCount++;
                s = e + 1;
            }
            if (sectionCount == 4) return "IPv4";
        }
        else {
            int sectionCount = 0;
            int s = 0;
            for (int e = 0; e <= n; e++) {
                if (e != n) {
                    if (queryIP[e] != ':') continue;
                }

                if (e == s || e - s > 4) return "Neither";

                // either e == n || e != n And q[e] == ':'
                string curr = "";
                for (int i = s; i < e; i++) {
                    // if not a number
                    if (queryIP[i] < '0' || queryIP[i] > '9') {
                        // if not a small case letter a to f
                        if (queryIP[i] < 'a' || queryIP[i] > 'f') {
                            // if not a uppercase letter A to F
                            if (queryIP[i] < 'A' || queryIP[i] > 'F') {
                                return "Neither";
                            }   
                        }
                    }
                    curr += queryIP[i];
                }
                if (curr.size() > 4) return "Neither";
                sectionCount++;
                s = e + 1;
            }
            if (sectionCount == 8) return "IPv6";
        }

        return "Neither";
    }
};