class Solution {
public:
    int mirrorReflection(int p, int q) {
        if(q==0)return 0;

        int vert = q;
        while(vert % p) vert += q;
        int up = vert / p;
        int ri = vert / q;

        int top = up % 2;
        return (ri % 2 ? top : 2);
    }
};
