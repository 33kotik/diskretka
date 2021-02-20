#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
vector<double> x(10);
vector<double> y(10);
vector<vector<double>> a(10);


class my_set {
public:
    vector<string> elements;
    string name;
//    vector
public:
    //конструкторы и деструкторы
    my_set(string nn,vector<string> your_elements) {
        name=nn;
        elements = your_elements;
        cout << "set was made" << endl;
    }

    my_set(string nn) {
        name=nn;
        cout << "set was made" << endl;
    }

//    my_set(my_set your_set) {
//        elements = your_set.elements;
//        cout << "set was made" << endl;
//    }

    ~my_set() {
        cout << "set deleted" << endl;
        //        delete(elements);
    }

    //методы и свойства множества
    void get_power() {
        cout << "power of set = " << elements.size() << endl;
    }

    void append(string new_element) {
        for (auto element : elements)
            if (element == new_element) {
                cerr << "this element is already in the set" << endl;
                return;
            }
        elements.push_back(new_element);
        cout << "element append successfully " << endl;
    }

    void my_delete(string element) {
        for (int i = 0; i < elements.size(); i++)
            if (elements[i] == element) {
                elements.erase(elements.begin() + i);
                cout << "element deleted successfully " << endl;
                return;
            }
        cerr << "element wasn't deleted" << endl;
    }

    bool check_element_in_set(string element) {
        for (int i = 0; i < elements.size(); i++)
            if (elements[i] == element) {
                cout << "yes" << endl;
                return (true);
            }
        cout << "no" << endl;
        return (false);
    }

//операции над множествами
    //    объединение
    void union_sets(my_set apending_set) {
        vector<string> ans;
        for (auto apending_element : apending_set.elements) {
            bool flag = true;
            for (auto my_element :elements) {
                if (my_element == apending_element) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans.push_back(apending_element);
        }
        for (auto apending_element : ans) {
            elements.push_back(apending_element);
        }
        cout << "union successfully" << endl;
    }

    //    • пересечение
    void intersection_sets(my_set apending_set) {
        vector<string> ans;
        for (auto apending_element : apending_set.elements) {
            bool flag = true;
            for (auto my_element :elements) {
                if (my_element == apending_element) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans.push_back(apending_element);
        }
        elements = ans;
        cout << "intersection successfully" << endl;
    }

//    • разность
    void difference_sets(my_set difference_set) {
        vector<string> ans;
        for (auto difference_element :difference_set.elements) {
            for (int i = 0; i < elements.size(); i++) {
                if (elements[i] == difference_element) {
                    elements.erase(elements.begin() + i);
                    break;
                }
            }
        }
        elements = ans;
        cout << "intersection successfully" << endl;
    }

//    • симметрическая разность
    void xor_sets(my_set xor_set) {
        for (int j = 0; j < xor_set.elements.size(); j++) {
            for (int i = 0; i < elements.size(); i++) {
                if (elements[i] == xor_set.elements[j]) {
                    elements.erase(elements.begin() + i);
                    xor_set.elements.erase(xor_set.elements.begin() + j);
                    break;
                }

            }
        }
        vector<string> ans = elements;
        ans.insert(ans.end(), xor_set.elements.begin(), xor_set.elements.end());
        cout << "xor successfully" << endl;
    }

//    • проверка включения
//    просмотр списка существующих множеств
//    • просмотр элементов существующего множества
    void show_set() {
        for (auto element : elements) {
            cout << element << endl;
        }
    }
};

struct sets {
    vector<my_set> set;
};
sets my_sets;

my_set choose_set() {
    for (int i =0;i<my_sets.set.size();i++)
        cout<<i<<" "<<my_sets.set[i].name;
    int ans;
    cin>>ans;
    return (my_sets.set[ans]);
}

int main() {
    string s;
    my_set ss("first");
    my_sets.set.push_back(ss);
    cout << "press 0 void append_set " << endl <<
        "press 1 get_power" << endl <<

        "press 2 void append(string new_element) " << endl <<
        "press 3 void my_delete(string element) " << endl <<
        "press 4 bool check_element_in_set(string element)" << endl <<
        "press 5 void union_sets(my_set apending_set) " << endl <<
        "press 6 void intersection_sets(my_set apending_set) " << endl <<
        "press 7 void difference_sets(my_set difference_set)" << endl <<
        "press 8  void xor_sets(my_set xor_set) " << endl <<
         "press 9 void show_set()" << endl <<
         "press 10 void choose set" << endl <<
         "press 12 void append(string new_element) " << endl <<
         "press 33 exit " << endl;
    int c=100;
    while (true) {
//        if (c==100){
//
//        }
        cin >> c;
        if (c == 1) {
            ss.get_power();
        }
        if (c == 1) {
            ss.get_power();
        }
        if (c == 2) {
            cout << "enter element to append" << endl;
            getline(cin, s);
            ss.append(s);
        }
        if (c == 3) {
            cout << "enter element to delete" << endl;
            getline(cin, s);
            ss.my_delete(s);
        }
        if (c == 4) {
            cout << "enter element to chek in set" << endl;
            getline(cin, s);
            bool res = ss.check_element_in_set(s);
        }
        if (c == 5) {

        }
        if (c == 10) {
            ss=choose_set();
        }

        if (c == 33) {
            break;
        }

    }

//    getline(cin,s);

//    cout << s<<endl;
    return 0;
}
