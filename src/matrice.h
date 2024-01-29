class matrice {
    private:
        int **data;
        int size;
        void init();
    public:
        matrice() : size(0) {};
        matrice(int s);
        ~matrice();
        void createMatrice(int size);
        void setVal(int l, int c, int val);
        void print();
        
};