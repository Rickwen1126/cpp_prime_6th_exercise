#ifndef EXEC1_H
#define EXEC1_H

class Cow{
    private:
        enum {HOBBY_SIZE = 40};
        char name[20];
        char *hobby;
        double weight;
        static int count;
    public:
        Cow();
        Cow(const char *nm, const char *ho, double wt);
        Cow(const Cow &c);
        ~Cow();
        Cow &operator=(const Cow &c);
        void ShowCow() const;
};

#endif 