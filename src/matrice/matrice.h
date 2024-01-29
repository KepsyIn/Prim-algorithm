class Matrice {
    private:
        int **data;
        int lignes;
        int col;
    public:
        Matrice(int l, int c);
        ~Matrice();
        void init(int l, int c, int val);
        void print();
        
};