// basic kmp
vi prefixFunc(string s) {
    int n = sz(s);

    vi pi(n);
    repn(i, n-1) {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

vi indexOfStringInPattern(string s, string p) {
    string temp = s + "#" + p;
    vi pi = prefixFunc(temp);

    int n = sz(temp);
    vi ans;
    rep(i, n) {
        if(pi[i] == sz(s)) {
            ans.pb(i-2*sz(s));
        }
    }
    return ans;
}
bool checkIfStringIsInPattern(string s, string p) {
    string temp = s + "#" + p;
    vi pi = prefixFunc(temp);

    int n = sz(temp);
    rep(i, n) {
        if(pi[i] == sz(s)) {
            return true;
        }
    }
    return false;
}



