class FizzBuzz {
private:
    int n;
    int i;
    mutex m;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (true) {
            const lock_guard<mutex> lock(m);
            if (i > n) break;
            if (i % 3 == 0 && i % 5 != 0) {
                printFizz();
                i++;
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (true) {
            const lock_guard<mutex> lock(m);
            if (i > n) break;
            if (i % 5 == 0 && i % 3 != 0) {
                printBuzz();
                i++;
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            const lock_guard<mutex> lock(m);
            if (i > n) break;
            if (i % 3 == 0 && i % 5 == 0) {
                printFizzBuzz();
                i++;
            }
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (true) {
            const lock_guard<mutex> lock(m);
            if (i > n) break;
            if (i % 3 != 0 && i % 5 != 0) {
                printNumber(i);
                i++;
            }
        }
    }
};