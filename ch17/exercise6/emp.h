#ifndef EMP_H
#define EMP_H

#include <iostream>
#include <string>
#include <fstream>

#define CLASS_ABS 'a'
#define CLASS_EMP 'e'
#define CLASS_MGR 'm'
#define CLASS_FINK 'f'
#define CLASS_HIGH 'h'
#define CLASS_PREFIX "class="

class abstr_emp {
    private:
        std::string fname;
        std::string lname;
        std::string job;
    protected:
        void data() const;
        void input();
        void write(std::ofstream &fout);
        void writeClassMark(std::ofstream &fout, const char mark);
    public:
        abstr_emp();
        abstr_emp(const abstr_emp &ab);
        abstr_emp(const std::string &fn, const std::string & ln, const std::string &j);
        abstr_emp(const std::string &fileString);
        virtual void ShowAll() const;
        virtual void SetAll();
        virtual void WriteAll(std::ofstream &fout);
        friend std::ostream & operator<<(std::ostream &os, const abstr_emp &e);
        virtual ~abstr_emp() = 0;
};

class employee : public abstr_emp {
    public:
        employee();
        employee(const std::string &fn, const std::string &ln,  const std::string &j);
        employee(const std::string &fileString);
        virtual void ShowAll() const;
        virtual void SetAll();
        virtual void WriteAll(std::ofstream &fout);
};


class manager : virtual public abstr_emp {
    private:
        int  inchargeof; /// num of abstr_emps managed
    protected:
        int InChargeOf() const {return inchargeof;}
        int &InChargeOf() {return inchargeof;}
        void data() const;
        void input();
        void write(std::ofstream &fout);
    public:
        manager();
        manager(const std::string &fn, const std::string &ln, const std::string &j, int ico = 0);
        manager(const abstr_emp & e, int ico);
        manager(const manager &m);
        manager(const std::string &fileString);
        virtual void ShowAll() const;
        virtual void SetAll();
        virtual void WriteAll(std::ofstream &fout);
};

class fink: virtual public abstr_emp {
    private:
        std::string reportsto;
    protected:
        void data() const;
        void input(); 
        void write(std::ofstream &fout);
        const std::string ReportsTo() const {return reportsto;}
        std::string & ReportsTo() {return reportsto;}
    public:
        fink();
        fink(const std::string &fn, const std::string &ln, const std::string &j, const std::string &rpo);
        fink(const abstr_emp &e, const std::string &rpo);
        fink(const fink &e);
        fink(const std::string &fileString);
        virtual void ShowAll() const;
        virtual void SetAll();
        virtual void WriteAll(std::ofstream &fout);
};

class highfink : public manager, public fink {
    public:
        highfink();
        highfink(const std::string &fn, const std::string &ln, const std::string &j, const std::string &rpo, int ico);
        highfink(const abstr_emp &e, const std::string &rpo, int ico);
        highfink(const manager &m, const std::string &rpo);
        highfink(const highfink &h);
        highfink(const std::string &fileString);
        virtual void ShowAll() const;
        virtual void SetAll();
        virtual void WriteAll(std::ofstream &fout);
};

#endif