#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <exception>
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
        for (auto apending_element : elements) {
            cout<<apending_element<<" ";
        }
        for (auto apending_element : ans) {
            cout<<apending_element<<" ";
        }
        cout <<endl << "union successfully" << endl;
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
            if (!flag)
                ans.push_back(apending_element);
        }
//        for (auto element : elements) {
//            cout<<element<<" ";
//        }
        for (auto element : ans) {
            cout<<element<<" ";
        }
//        elements = ans;
        cout <<endl<< "intersection successfully" << endl;
    }

//    • разность
    void difference_sets(my_set difference_set) {
        vector<string> ans=elements;
        for (auto difference_element :difference_set.elements) {
            for (int i = 0; i < ans.size(); i++) {
                if (ans[i] == difference_element) {
                    ans.erase(ans.begin() + i);
                    break;
                }
            }
        }
        for (auto element : ans) {
            cout<<element<<" ";
        }
        cout <<endl<< "difference  successfully" << endl;
    }
//    • симметрическая разность
    void xor_sets(my_set xor_set) {
        vector<string> ans=elements;
        vector<string> ans2=xor_set.elements;

        for (int j = 0; j < ans2.size(); j++) {
            for (int i = 0; i < ans.size(); i++) {
                if (ans[i] == ans2[j]) {
                    ans.erase(ans.begin() + i);
                    ans2.erase(ans2.begin() + j);
                    break;
                }

            }
        }
        ans.insert(ans.end(), ans2.begin(), ans2.end());
        for (auto element : ans) {
            cout<<element<<" ";
        }
        cout <<endl<<  "xor successfully" << endl;
    }

//    • проверка включения
    void inclusion_chek_sets(my_set chek_set) {
        vector<string> ans=elements;
        for (auto chek_element :chek_set.elements) {
            bool flag= false;
            for (int i = 0; i < ans.size(); i++) {
                if (ans[i] == chek_element) {
                    flag=true;
                    break;
                }
            }
            if (!flag){
                cout<<"no"<<endl;
                return;
            }

        }
        cout<<"yes"<<endl;
        return;
    }

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
//    просмотр списка существующих множеств
my_set choose_set() {
    for (int i = 0; i < my_sets.set.size(); i++)
        cout << i << " " << my_sets.set[i].name << endl;
    int ans;
    cin >> ans;
    if (ans>=0 && ans<my_sets.set.size()) {
        return (my_sets.set[ans]);
    }
    else{
        cout<< " error try again choose"<<endl;
        return (choose_set());
    }
}
int main() {
    string test;
    vector <string> simple123 ={"1","2","3"};
    vector <string> simple345 ={"3","4","5"};
    my_set ss ("simple123",simple123);
    my_set second ("simple345",simple345);
    my_sets.set.push_back(ss);
    my_sets.set.push_back(second);
//    getline(cin,test);
//    cout<<test<<endl;
    cout << "press 0 append_set " << endl <<
        "press 1 get_power" << endl <<
        "press 2  append " << endl <<
        "press 3 my_delete " << endl <<
        "press 4 check_element_in_set" << endl <<
        "press 5 union_sets " << endl <<
        "press 6 intersection_sets" << endl <<
        "press 7 difference_sets" << endl <<
        "press 8 xor_sets " << endl <<
         "press 9 show_set" << endl <<
         "press 10 choose set" << endl <<
         "press 11 inclusion chek set" << endl <<
         "press 33 exit " << endl;

    string c;
    while (true) {
//        if (c==100){
//
//        }
        getline(cin,c);
        if (c == "0") {
            string s;
            cout << "enter name of new set" << endl;
            getline(cin,s);
            my_sets.set.emplace_back(s);
        }
        if (c == "1") {
            ss.get_power();
        }
        if (c == "2") {
            cout << "enter element to append" << endl;
            string s;
            getline(cin, s);
            ss.append(s);
        }
        if (c == "3") {
            string s;
            cout << "enter element to delete" << endl;
            getline(cin, s);
            ss.my_delete(s);
        }
        if (c == "4") {
            string s;
            cout << "enter element to chek in set" << endl;
            getline(cin, s);
            bool res = ss.check_element_in_set(s);
        }
        if (c == "5") {
            cout << "choose set" << endl;
            second=choose_set();
            ss.union_sets(second);

        }
        if (c == "6") {
            cout << "choose set" << endl;
            second=choose_set();
            ss.intersection_sets(second);
        }
        if (c == "7") {
            cout << "choose set" << endl;
            second=choose_set();
            ss.difference_sets(second);
        }
        if (c == "8") {
            cout << "choose set" << endl;
            second=choose_set();
            ss.xor_sets(second);
        }
        if (c == "9") {
            ss.show_set();
        }
        if (c == "10") {
            ss=choose_set();
        }
        if (c == "11") {
            cout << "choose set" << endl;
            second=choose_set();
            ss.inclusion_chek_sets(second);
        }
        if (c == "33") {
            break;
        }

    }

//    getline(cin,s);

//    cout << s<<endl;
    return 0;
}
