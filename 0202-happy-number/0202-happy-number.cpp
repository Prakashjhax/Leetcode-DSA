class Solution {
public:
    int f(int n) {
        int s = 0;
        while (n) {
            int d = n % 10;
            s += d * d;
            n /= 10;
        }
        return s;
    }

    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = f(slow);
            fast = f(f(fast));
        } while (slow != fast);
        return slow == 1;
    }
};
