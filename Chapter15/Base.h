#pragma once
class Base
{
    void memfcn(Base& b) { b = *this; }
public:
    Base() = default;
    ~Base();
public:
    void pub_mem() {};
protected:
    int prot_mem=0;
private:
    char priv_mem='0';
};

struct Pub_Derv :public Base {
    void memfcn(Base& b) { b = *this; }
    int f() { return prot_mem; }
};

struct Prot_Derv :protected Base {
    void memfcn(Base& b) { b = *this; }
    int f1() const { return prot_mem; }
};

struct Priv_Derv :private Base {
    void memfcn(Base& b) { b = *this; }
    int f2() const { return prot_mem; }
};

struct Derived_from_Public :public Pub_Derv {
    void memfcn(Base& b) { b = *this; }
    int use_base() { return prot_mem; }
};

struct Derived_from_Protected :public Prot_Derv {
    void memfcn(Base& b) { b = *this; }
};

struct Derived_from_Private :public Priv_Derv {
    //void memfcn(Base& b) { b = *this; }
    //  C2247   'Base' not accessible because 'Priv_Derv' uses 'private' to inherit from 'Base'
    //  C2243   'type cast': conversion from 'Derived_from_Private *' to 'const Base &' exists, but is inaccessible
};
