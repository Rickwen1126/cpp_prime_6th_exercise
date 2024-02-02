#include "emp.h"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

#define MAX_OBJ_SIZE 10
#define OBJ_FILE "obj.dat"


using namespace std;

abstr_emp *GetClassObj(const string &s) {
    size_t pos = s.find(CLASS_PREFIX);

    if (pos == std::string::npos) return nullptr;

    pos += strlen(CLASS_PREFIX);

    char classMark = s[pos];

    switch (classMark)
    {
    case CLASS_EMP:
        return new employee(s);        
        break;
    case CLASS_MGR:
        return new manager(s);        
        break;
    case CLASS_FINK:
        return new fink(s);        
        break;
    case CLASS_HIGH:
        return new highfink(s);        
        break;
    default:
        break;
    }
}

int main(void) {
    ifstream fin(OBJ_FILE);

    if (fin.is_open() == false) {
        cerr << "Open file " << OBJ_FILE << " failed.";
        exit(1); 
    }

    cout << "Read Objects from file:" << endl;
    string lineStr;
    abstr_emp* arr[MAX_OBJ_SIZE];
    int idx = 0;
    while (idx < 10 && getline(fin, lineStr)) {
        arr[idx++] = GetClassObj(lineStr);
    }

    cout << "There are " << idx << " objects in " << OBJ_FILE << endl;
    
    for (int i = 0 ; i < idx ; i++) {
        arr[i]->ShowAll();
    }
    char c;
    cout << "Chose \"e(employee) m(manager) f(fink) h(highfink)\" to create obj (q to exit):";
    while ((c = cin.get()) != 'q' && idx < MAX_OBJ_SIZE) {
        string fname;
        string lname;
        string job;
        if (c == 'e' || c == 'm' || c == 'f' || c == 'h') {
            cout << "Please enter first name:";
            cin >> fname;
            cout << "Please enter last name:";
            cin >> lname;
            cout << "Please enter job:";
            cin >> job;
        }
        int inchargeof;
        string reportsto;
        switch (c) {
            case 'm':
                cout << "Please enter Inchargeof:";
                cin >> inchargeof;
                arr[idx++] = new manager(fname, lname, job, inchargeof);
                arr[idx - 1]->ShowAll();
                break;
            case 'f':
                cout << "Please enter Reportsto:";
                cin >> reportsto;
                arr[idx++] = new fink(fname, lname, job, reportsto);
                arr[idx - 1]->ShowAll();
                break;
            case 'h':
                cout << "Please enter Inchargeof:";
                cin >> inchargeof;
                cout << "Please enter Reportsto:";
                cin >> reportsto;
                arr[idx++] = new highfink(fname, lname, job, reportsto,inchargeof);
                arr[idx - 1]->ShowAll();
                break;
            case 'e':
                arr[idx++] = new employee(fname, lname, job);
                arr[idx - 1]->ShowAll();
                break;
            default:
                break;    
        }
        while ((c = cin.get()) != '\n') {
            continue;
        }
        cout << "Chose \"e(employee) m(manager) f(fink) h(highfink)\" to create obj (q to exit):";
    }

    fin.close();

    cout << "Check All objects after user added:" << endl;
    ofstream fout(OBJ_FILE);

    for (int i = 0 ; i < idx; i++) {
        arr[i]->ShowAll();
        arr[i]->WriteAll(fout);
    }
    
    fout.close();

    // employee em("Trip", "Harris", "Thumper");
    // cout << em << endl;
    // em.ShowAll();
    // manager ma("Amorphia", "Spindragon", "Nuancer");
    // cout << ma << endl;
    // ma.ShowAll();

    // fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    // cout << fi << endl;
    // fi.ShowAll();

    // highfink hf(ma, "Curly Kew");
    // cout << hf << endl;
    // hf.ShowAll();

    // cout << "Press a key for next phase:\n";
    // cin.get();
    // highfink hf2;
    // hf2.SetAll();

    // cout << "Using an abstr_emp *pointer:\n";
    // abstr_emp *tri[4] =  {&em, &fi, &hf, &hf2};
    // for (int i = 0; i < 4; i++) {
    //     tri[i]->ShowAll();
    // }
    // int choice;
    // cin >> choice;
    // while(choice != 5) {
    //     cout << choice;
    //     cin >> choice;
    // }
    return 0;
}