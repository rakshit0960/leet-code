class Solution {
    bool checkIsValidIpv4_character(char ch) {
        // not a number 
        if (ch < '0' || ch > '9') return false;
        return true;
    }

    bool checkIsValidIpv6_character(char ch) {
        // if not a number
        if (ch < '0' || ch > '9') {
            // if not a small case letter a to f
            if (ch < 'a' || ch > 'f') {
                // if not a uppercase letter A to F
                if (ch < 'A' || ch > 'F') {
                    // not a number for a valid character
                    return false;
                }   
            }
        }

        return true;
    }

    bool checkIsValidIpv4(string queryIP) {
        const int n = queryIP.size();
        int sectionCount = 0;
        int s = 0;
        for (int e = 0; e <= n; e++) {
            // keep continueing until reached the end of a period
            if (e != n) {
                if (queryIP[e] != '.') continue;
            }
            
            // if size of section is zero or 
            // size of section if greater than 3
            if (e == s || e - s > 3) return false;

            string curr = "";
            for (int i = s; i < e; i++) {
                if (!checkIsValidIpv4_character(queryIP[i])) return false;
                curr += queryIP[i];
            }
            
            // leading zeros
            if (curr.size() > 1 && curr[0] == '0') return false;

            int num = stoi(curr);

            // num out of range
            if (num < 0 || num > 255) return false;
            sectionCount++;
            s = e + 1;
        }
        if (sectionCount == 4) return true;
        return false;
    }

    bool checkIsValidIpv6(string queryIP) {
        const int n = queryIP.size();
        int sectionCount = 0;
        int s = 0;
        for (int e = 0; e <= n; e++) {
            // keep continueing until reached the end of a period
            if (e != n) {
                if (queryIP[e] != ':') continue;
            }

            // if size of section is zero or 
            // size of section if greater than 4
            if (e == s || e - s > 4) return false;

            for (int i = s; i < e; i++) {
                if (!checkIsValidIpv6_character(queryIP[i])) return false;
            }

            sectionCount++;
            s = e + 1;
        }

        if (sectionCount == 8) return true;
        return false;
    }

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
            if (checkIsValidIpv4(queryIP))
                return "IPv4";
            else 
                return "Neither";
        }
        else {
            if (checkIsValidIpv6(queryIP)) 
                return "IPv6";
            else
                return "Neither"; 
        }

        return "Neither"; 
    }
};