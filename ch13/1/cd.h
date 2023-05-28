#ifndef CH13CD_H_
#define CH13CD_H_
#include <cstring>
#include <iostream>
#include <string>

class Cd {
    private:
        char performers[50];
        char label[20];
        int selections = 0;
        double playtime = 0.0;
        void copyString(const char *s1, const char *s2) {
            std::strncpy(performers, s1, 50);
            performers[50] = '\0';
            std::strncpy(label, s2, 20);
            label[20] = '\0';
        }
    public:
        Cd(char *s1, char *s2, int n, double x):selections(n), playtime(x) {
            copyString(s1, s2);
        }
        Cd(const Cd &d) : selections(d.selections), playtime(d.playtime) {
            copyString(d.performers, d.label);
        }
        Cd(){
            performers[0] = '\0';
            label[0] = '\0';
        }

        virtual ~Cd() {}

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

            copyString(d.performers, d.label);
            selections = d.selections;
            playtime = d.playtime;
        }
};

class Classic : public Cd {
    private: 
        std::string primaryWork;
    public:
        Classic(char *work, char* per, char* lab, int s, double time) : Cd(per, lab, s, time) {
            primaryWork = work;
        }

        Classic() : Cd() {

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
            primaryWork = d.primaryWork;
        }

        
};

#endif