#include <bits/stdc++.h>


using namespace std;
class BigInteger{
private:
    vector<int>digits;
    bool isNegative;
    void normalize() {
        while (digits.size() > 1&& digits.back() ==0) {
       
	   
	        digits.pop_back();
        }
        if (digits.empty()){
            digits.push_back(0);
            isNegative = false;
        }
    }
    BigInteger addAbs(const BigInteger& other)const{
        BigInteger result;
        result.digits.clear();
        int carry = 0;
        int maxSize =max(digits.size(),other.digits.size());
        for (int i = 0; i< maxSize||carry; i++) {
            int sum = carry;
            if (i < digits.size())sum += digits[i];
            if (i < other.digits.size())sum += other.digits[i];
            carry = sum /10;
            sum %= 10;
            result.digits.push_back(sum);
        }
    result.normalize();
        
		
		
		return result;
    }
    BigInteger subtractAbs(const BigInteger& other)const {
        BigInteger result;
        result.digits = digits;
        int borrow = 0;
        for (int i = 0; i < digits.size(); i++) {
            int sub = result.digits[i] - borrow;
            if (i < other.digits.size()) sub -= other.digits[i];
            if (sub < 0) {
                sub += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.digits[i] = sub;
        }
        result.normalize();
        return result;
    }
    int compareAbs(const BigInteger& other) const {
        if (digits.size() != other.digits.size()) {
            return digits.size() < other.digits.size() ?-1 : 1;
            
            
        }
        for (int i = digits.size()- 1; i >= 0; i--) {
            if (digits[i] != other.digits[i]) {
                return digits[i] < other.digits[i] ? -1 : 1;
                
                
                
                
            }
        }
        return 0;
    }

public:
    BigInteger() : isNegative(false) {
        digits.push_back(0);
        
        
        
    }
    BigInteger(const string& str) {
    	
    	
        isNegative = (str[0] == '-');
        int start = isNegative ? 1 : 0;
        while (start < str.length() && str[start] == '0') start++;
        for (int i = str.length() - 1; i >= start; i--) {
            digits.push_back(str[i] - '0');
        }
        
        
        
        if (digits.empty())digits.push_back(0);
        normalize();
        if (digits.size() == 1 &&digits[0] == 0) isNegative = false;
    }
    BigInteger operator+(const BigInteger& other) const {
        if (!isNegative && !other.isNegative) {
            return addAbs(other);
            
            
        } else if (isNegative && other.isNegative) {
            BigInteger result = addAbs(other);
            result.isNegative = true;
            return result;
            
            
            
        } else if (!isNegative && other.isNegative) {
            BigInteger absOther = other;
            absOther.isNegative = false;
            
            
            if (compareAbs(absOther) >= 0) {
                return subtractAbs(absOther);
                
                
            } else {
                BigInteger result = absOther.subtractAbs(*this);
                result.isNegative = true;
                return result;
                
                
            }
        } else {
            BigInteger absThis = *this;
            absThis.isNegative = false;
            if (other.compareAbs(absThis) >= 0) {
                return other.subtractAbs(absThis);
                
                
                
            } else {
                BigInteger result = absThis.subtractAbs(other);
                result.isNegative = true;
                
                return result;
            }
        }
    }
    BigInteger operator-() const {
        BigInteger result = *this;
        if (digits.size() == 1 && digits[0] == 0) return result;
        result.isNegative = !result.isNegative;
        return result;
        
        
    }
    BigInteger operator-(const BigInteger& other) const {
        return *this + (-other);
        
    }
    bool operator==(const BigInteger& other) const {
        return isNegative == other.isNegative && digits == other.digits;
        
        
    }
    bool operator<(const BigInteger& other)const {
        if (isNegative != other.isNegative) return isNegative;
        return isNegative ? other.compareAbs(*this) < 0 : compareAbs(other) < 0;
        
        
    }
    friend ostream& operator<<(ostream& os,const BigInteger& bi) {
        if (bi.digits.size() == 1 && bi.digits[0] == 0) {
            os << "0";
            
        } else {
            if (bi.isNegative) os << "-";
            for (int i = bi.digits.size() - 1; i >= 0; i--) {
                os << bi.digits[i];
                
                
                
            }
        }
        return os;
    }
    friend istream& operator>>(istream& is,BigInteger& bi) {
        string str;
        is >> str;
        bi = BigInteger(str);
        return is;
    }
};

int main() {
    BigInteger a("12345678901234567890");
    BigInteger b("98765432109876543210");
    cout<< "BigInteger Addition:" << (a+ b) << endl;
    cout << "BigInteger Subtraction: " << (a -b)<< endl;
    return 0;
}