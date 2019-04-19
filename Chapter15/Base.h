#pragma once
class Base
{
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
    int f() { return prot_mem; }
};

struct Prot_Derv :protected Base {
    int f1() const { return prot_mem; }
};

struct Priv_Derv :private Base {
    int f2() const { return prot_mem; }
};

struct Derived_from_Public :public Pub_Derv {
    int use_base() { return prot_mem; }
};

struct Derived_from_Protected :public Prot_Derv {

};

struct Derived_from_Private :public Priv_Derv {

};
