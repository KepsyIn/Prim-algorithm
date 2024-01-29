class matrice {
    private:
        int **data;
        int size;
    public:
        matrice(int s);
        ~matrice();
        void init();
        void setVal(int l, int c, int val);
        void print();
        
};