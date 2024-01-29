class matrice {
    private:
        int **data;
        int lignes;
        int col;
    public:
        matrice(int l, int c);
        ~matrice();
        void init(int l, int c, int val);
        void print();
        
};