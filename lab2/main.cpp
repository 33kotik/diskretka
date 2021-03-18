#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <exception>

using namespace std;
vector<int> fact;
vector<int> fact_velue;

int factorial(int n) {
    int ans = 1;
    int start = 1;
    if (fact[fact.size() - 1] <= n) {
        start = fact[fact.size() - 1];
        ans = fact_velue[fact.size() - 1];
    } else
        for (int i = 0; i < fact.size(); i++) {
            if (fact[i] > n) {
                start = fact[i - 1];
                ans = fact_velue[i - 1];
                break;
            }
        }

    for (int i = start; i <= n; i++) {
        ans = ans * i;
    }
    if (start != n) {
        if (fact[fact.size() - 1] <= n) {
            fact_velue.push_back(ans);
            fact.push_back(n);
        } else {
            fact_velue.push_back(ans);
            fact.push_back(n);
            sort(fact.begin(), fact.begin() + fact.size());
            sort(fact_velue.begin(), fact_velue.begin() + fact.size());
        }
    }

    return ans;
}

//Число размещений U(m,n)
int U(int n, int k) {
    return (pow(n,k));
}
//Число размещений без повторений A(m,n)

int A(int n, int k) {
    return factorial(n) / factorial(n - k);
}

//Число перестановок P(n)
int P(int n) {
    return factorial(n);
}

//Число сочетаний C(m,n)
int C(int n, int k) {
    return (A(n,k)/factorial(k));
}

//Число Стирлинга второго рода S(m,n)
int S(int n, int k) {
    if (k==0 && n==0)
        return 1;
    if (k==0)
        return 0;
    if (n<k)
        return 0;
    return S(n-1,k-1)+k*S(n-1,k);
}

//Число Белла B(n)
int B(int n) {
    int ans=0;
    for (int i=0;i<n;i++){
        ans+=S(n,i);
    }
    return (ans);
}

void H() {
    cout << "press H to call Help" << endl <<
         "press U Число размещений" << endl <<
         "press A Число размещений без повторений" << endl <<

         "press P Число перестановок" << endl <<
         "press C Число сочетаний" << endl <<
         "press S Число Стирлинга второго рода " << endl <<
         "press B Число Белла " << endl<<
    "press 33 to finish work" << endl;
}


int main() {
    string c;
    fact.push_back(1);
    fact_velue.push_back(1);
    H();
//    for (int i = 2; i < 10; i++) {
//        cout << factorial(i) << endl;
//    }
    while (true) {
        cin>>c;
        int m,n;
        if (c == "H") {
            H();
        }
        if (c == "U") {
            cout<<"введите кофиценты <m> и <n>"<<endl;
            cin>>m>>n;
            cout<<"U("<<m<<","<<n<<") = "<<U(m,n)<<endl;
        }

        if (c == "A") {
            cout<<"введите кофиценты <m> и <n>"<<endl;
            cin>>m>>n;
            cout<<"A("<<m<<","<<n<<") = "<<A(m,n)<<endl;
        }
        if (c == "P") {
            cout<<"введите кофицент <n>"<<endl;
            cin>>n;
            cout<<"P("<<n<<") = "<<P(n)<<endl;
        }
        if (c == "C") {
            cout<<"введите кофиценты <m> и <n>"<<endl;
            cin>>m>>n;
            cout<<"C("<<m<<","<<n<<") = "<<C(m,n)<<endl;
        }
        if (c == "S") {
            cout<<"введите кофиценты <m> и <n>"<<endl;
            cin>>m>>n;
            cout<<"S("<<m<<","<<n<<")= "<<S(m,n)<<endl;
        }
        if (c == "B") {
            cout<<"введите кофицент <n>"<<endl;
            cin>>n;
            cout<<"B("<<n<<") = "<<B(n)<<endl;
        }
        if (c == "33") {
            break;
        }

    }
    return 0;
}
