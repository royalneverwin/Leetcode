class Bank {
    vector<long long> depo;
    int people;
public:
    Bank(vector<long long>& balance) {
        people = balance.size();
        depo = balance;
    }

    bool transfer(int account1, int account2, long long money) {
        if(account1 < 1 || account1 > people || account2 < 1 || account2 > people)
            return false;
        if(money > depo[account1-1])
            return false;
        depo[account1-1] -= money;
        depo[account2-1] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if(account < 1 || account > people)
            return false;
        depo[account-1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if(account < 1 || account > people)
            return false;
        if(money > depo[account-1])
            return false;
        depo[account-1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */