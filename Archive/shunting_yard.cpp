#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

string shunting_yard(string &s) {
    auto is_ident=[](char x) {
        return x>='0'&&x<='9';
    };

    auto is_operator=[](char x) {
        return x=='+'||x=='-'||x=='*'||x=='/'||x=='^';
    };

    auto left_assoc=[](char x) {
        return x=='+'||x=='-'||x=='*'||x=='/';
    };

    auto priority=[](char x) {
        if(x=='^') return 1;
        if(x=='*'||x=='/') return 2;
        if(x=='+'||x=='-') return 3;
        return 4;
    };

    string res,stk;
    for(auto x:s) {
        if(is_ident(x)) res.push_back(x);
        else if(is_operator(x)) {
            while(stk.size()&&is_operator(stk.back())) {
                char l=stk.back();
                if (
                    left_assoc(x)&&priority(x)>=priority(l)||
                    !left_assoc(x)&&priority(x)>priority(l)
                ) stk.pop_back(),res.push_back(l);
                else break;
            }
            stk.push_back(x);
        }
        else if(x=='(') stk.push_back(x);
        else if(x==')') {
            while(stk.size()&&stk.back()!='(')
                res.push_back(stk.back()),stk.pop_back();
            assert(stk.back()=='(');
            stk.pop_back();
        }
    }

    while(stk.size()) {
        assert(stk.back()!='('&&stk.back()!=')');
        res.push_back(stk.back());
        stk.pop_back();
    }
    return res;
}

void solve() {
    // string s="3+4*2/(1-5)^2^3";
    string s="3/4";
    cout<<shunting_yard(s);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}