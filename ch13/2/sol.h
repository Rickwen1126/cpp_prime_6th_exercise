#ifndef CH13CD_H_
#define CH13CD_H_
#include <cstring>
#include <iostream>
#include <string>

class Cd {
    private:
        enum {PER_SIZE = 50, LABEL_SIZE = 20};
        char *performers;
        char *label;
        int selections = 0;
        double playtime = 0.0;
        void newString() {
            performers = new char[PER_SIZE]{'\0'};
            label = new char[LABEL_SIZE]{'\0'};
        }

        void copyString(const char *s1, const char *s2) {
            std::strncpy(performers, s1, PER_SIZE);
            performers[PER_SIZE - 1] = '\0';
            std::strncpy(label, s2, LABEL_SIZE);
            label[LABEL_SIZE - 1] = '\0';
        }
    public:
        Cd(const char *s1, const char *s2, int n, double x):selections(n), playtime(x) {
            newString();
            copyString(s1, s2);
        }
        Cd(const Cd &d) : selections(d.selections), playtime(d.playtime) {
            newString();
            copyString(d.performers, d.label);
        }
        Cd(){
            newString();
        }

        virtual ~Cd() {
            delete [] performers;
            delete [] label;
        }

        virtual void Report() const {
            std::cout << "Performers:" << performers << std::endl;
            std::cout << "Label:" << label << std::endl;
            std::cout << "Selecrtions:" << selections << std::endl;
            std::cout << "PlayTime:" << playtime << std::endl;
            std::cout << "\n";
        }

        Cd & operator=(const Cd &d) {
            if (this == &d) {
                return *this;
            }
            delete [] performers;
            delete [] label;
            copyString(d.performers, d.label);
            selections = d.selections;
            playtime = d.playtime;

            return *this;
        }
};

class Classic : public Cd {
    private: 
        char *primaryWork;
        void copyPrimaryWork(const char *work) {
            size_t workLen = strlen(work);
            primaryWork = new char[workLen + 1]{'\0'};
            strncpy(primaryWork, work, workLen);
        }
    public:
        Classic(const char *work, const char* per, const char* lab, int s, double time) : Cd(per, lab, s, time) {
           copyPrimaryWork(work);
        }

        Classic() : Cd() {
            primaryWork = new char[1]{'\0'};
        }

        Classic(const Classic &c) : Cd(c) {
            copyPrimaryWork(c.primaryWork);
        } 

        virtual ~Classic() {
            delete [] primaryWork;
        }

        virtual void Report() const {
           std::cout << "PrimaryWork:" << primaryWork << std::endl;
           Cd::Report();
        }

        Classic &operator=(const Classic &d) {
            if (this == &d) {
                return *this;
            }

            Cd::operator=(d);
            delete [] primaryWork;
            copyPrimaryWork(d.primaryWork);

            return *this;
        }

        
};

#endif