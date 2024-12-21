class parent{
    private : 
    int a;
    friend class f;
};
class f{
    public:
    void fun(parent &p){p.a;}
};
