#include <iostream>

class NoDefault {
    public:
        NoDefault(int in): nd(in) {}
        NoDefault(): nd(0) {}
    private:
        int nd;
};

class C {
    public:
        C(): ndf(0) {}
    private:
        NoDefault ndf;
};
