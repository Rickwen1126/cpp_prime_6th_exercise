#ifndef ITER_H_
#define ITER_H_

template<class Iter, class T>
Iter Find(Iter begin, Iter end, const T &target) {
    for (Iter iter = begin ; iter != end; iter++) {
        if (*iter == target) {
            return iter;
        }
    }
    
    return end;
}

#endif
