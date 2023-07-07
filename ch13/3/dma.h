#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class abcDMA {
    private:
        char *label;
        int rating;
    public:
        virtual void View() const = 0;

        abcDMA(const char * l = "null", int r = 0);
        abcDMA(const abcDMA &rs);
        virtual ~abcDMA();
        abcDMA & operator=(const abcDMA &);
        friend std::ostream &operator<<(std::ostream &os, const abcDMA &);
};  

class baseDMA : public abcDMA{
    public:
        baseDMA(const char * l = "null", int r = 0);
        baseDMA(const baseDMA &rs);
        baseDMA operator=(const baseDMA &ot); 
        virtual void View() const;
        friend std::ostream &operator<<(std::ostream &os, const baseDMA &);
};

class lacksDMA : public abcDMA {
    public:
        enum { COL_LEN = 40};
        lacksDMA(const char *c = "blank", const char *l = "null", int r = 0);
        lacksDMA(const char *c, const abcDMA &rs);
        lacksDMA operator=(const lacksDMA &);
        friend std::ostream & operator<<(std::ostream &os, const lacksDMA &rs);
        virtual void View() const;
    private:
        char color[COL_LEN];
};

class hasDMA : public abcDMA {
    private:
        char *style;
    public:
        hasDMA(const char *s = "none", const char *l = "null", int r = 0);
        hasDMA(const char *s, const abcDMA &rs);
        hasDMA(const hasDMA &hs);
        hasDMA operator=(const hasDMA&);
        ~hasDMA();
        friend std::ostream & operator<<(std::ostream &os, const hasDMA &rs);
        virtual void View() const;
};

#endif