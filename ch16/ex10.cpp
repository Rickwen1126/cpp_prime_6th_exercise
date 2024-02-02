#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

struct Review {
    Review(const Review &r) : title(r.title), rating(r.rating), price(r.price) {
    }
    Review() {
    }
    std::string title;
    int rating;
    double price;
};

bool operator<(const std::shared_ptr<Review> &r1, const std::shared_ptr<Review> &r2);
bool increaseRating(const std::shared_ptr<Review> &r1, const std::shared_ptr<Review> &r2);
bool decreaseRating(const std::shared_ptr<Review> &r1, const std::shared_ptr<Review> &r2);
bool increasePrice(const std::shared_ptr<Review> &r1, const std::shared_ptr<Review> &r2);
bool decreasePrice(const std::shared_ptr<Review> &r1, const std::shared_ptr<Review> &r2);
bool FillReview(Review &rr);
void ShowReview(const std::shared_ptr<Review> &rr);

int main() {
    using namespace std;

    vector<shared_ptr<Review>> books;
    Review temp;
    while (FillReview(temp))
        books.push_back(shared_ptr<Review>(new Review(temp)));

    
    
    if (books.size() > 0) {
        cout << "Thank you. you entered the following "
            << books.size() << " ratings:\n"
            << "Rating\tBook\tPrice\n";
        for_each(books.begin(), books.end(), ShowReview);
        cout << "Please select how to display these books:\n"
         << "a. Orginal\n"
         << "b. By Title\n"
         << "c. By rating (increase)\n"
         << "d. By rating (decrease)\n"
         << "e. By price (increase)\n"
         << "f. By price (decrease)\n"
         << "q. quit\n"
         << "Display way: ";

        vector<shared_ptr<Review>> sortedList(books.begin(), books.end());
        char sortT; 
        bool quit = false;
        while(cin >> sortT && !quit) {
            
            switch (sortT)
            {
            case 'a':
                for_each(books.begin(), books.end(), ShowReview);
                break;
            case 'b':
                sort(sortedList.begin(), sortedList.end());
                for_each(sortedList.begin(), sortedList.end(), ShowReview);
                break;
            case 'c':
                sort(sortedList.begin(), sortedList.end(), increaseRating);
                for_each(sortedList.begin(), sortedList.end(), ShowReview);
                break;
            case 'd':
                sort(sortedList.begin(), sortedList.end(), decreaseRating);
                for_each(sortedList.begin(), sortedList.end(), ShowReview);
                break;
            case 'e':
                sort(sortedList.begin(), sortedList.end(), increasePrice);
                for_each(sortedList.begin(), sortedList.end(), ShowReview);
                break;
            case 'f':
                sort(sortedList.begin(), sortedList.end(), decreasePrice);
                for_each(sortedList.begin(), sortedList.end(), ShowReview);
                break;
            case 'q':
                quit = true;
                break;
            default:
                for_each(books.begin(), books.end(), ShowReview);
                break;
            }
        cout << "Display way: ";
        }
    } else {
        cout << "No entres. ";
    }
    cout << "Bye.\n";

    return 0;   
}


bool operator<(const std::shared_ptr<Review> &r1, const std::shared_ptr<Review> &r2) {
    if (r1->title < r2->title) {
        return true;
    } else if (r1->title == r2->title && r1->rating < r2->rating) {
        return true;
    } else {
        return false;
    }
}

bool increaseRating(const std::shared_ptr<Review> &r1, const std::shared_ptr<Review> &r2) {
    if (r1->rating < r2->rating) {
        return true;
    } else {
        return false; 
    }
}

bool decreaseRating(const std::shared_ptr<Review> &r1, const std::shared_ptr<Review> &r2) {
    if (r1->rating < r2->rating) {
        return false;
    } else {
        return true; 
    }
}

bool increasePrice(const std::shared_ptr<Review> &r1, const std::shared_ptr<Review> &r2) {
    if (r1->price < r2->price) {
        return true;
    } else {
        return false; 
    }
}

bool decreasePrice(const std::shared_ptr<Review> &r1, const std::shared_ptr<Review> &r2) {
    if (r1->price < r2->price) {
        return false;
    } else {
        return true; 
    }
}

bool FillReview(Review &rr) {
    std::cout << "Enter book title (\"quit\" to quit): ";
    std::getline(std::cin, rr.title);
    if (rr.title == "quit") {
        return false;
    }

    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    if (!std::cin)
        return false;
    std::cout << "Enter book price: ";
    std::cin >> rr.price;
    if (!std::cin)
        return false;
    while(std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const std::shared_ptr<Review> &rr) {
    std::cout << rr->rating << "\t" << rr->title << "\t" << rr->price << std::endl;
}