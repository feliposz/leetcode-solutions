class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> n1;
        vector<int> n2;

        if ((num1 == "0") || (num2 == "0")) {
            return "0";
        }
        
        for (char c: num1) {
            n1.push_back(c-'0');
        }
        for (char c: num2) {
            n2.push_back(c-'0');
        }

        int sz1 = n1.size();
        int sz2 = n2.size();
        vector<int> prod(sz1+sz2);
        for (int i = sz1 - 1; i >= 0; i--) {            
            for (int j = sz2 - 1; j >= 0; j--) {
                int p = n1[i] * n2[j] ;
                prod[i+j+1] += p;
            }
        }
        
        int carry = 0;
        for (int i = prod.size() - 1; i >= 0; i--) {
            int sum = prod[i] + carry;
            prod[i] = sum % 10;
            carry = sum / 10;
        }
        
        string s;
        int i = 0;
        while (prod[i] == 0)
            i++;
        for (; i < prod.size(); i++) {
            s += prod[i] + '0';
        }
        return s;
    }
};